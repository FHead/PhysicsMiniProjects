#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#include "TH1D.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TFile.h"
#include "TPad.h"
#include "TImage.h"
#include "TArrow.h"

#include "CustomAssert.h"
#include "CommandLine.h"
#include "SetStyle.h"
#include "DrawRandom.h"
#include "DataHelper.h"

int main(int argc, char *argv[]);
int Sign(double Number);
string FindBase(string FileName);
void CopyGraph(TGraphAsymmErrors &G, TGraphAsymmErrors *S, bool IsData);
void MakeDelta(TGraphAsymmErrors &G1, TGraphAsymmErrors &G2);
void MakeSquareDelta(TGraphAsymmErrors &G1, TGraphAsymmErrors &G2);
void PrunePoints(TGraphAsymmErrors &G1, TGraphAsymmErrors &G2, double Threshold);
TGraphAsymmErrors Transcribe(DataHelper &DHFile, string State, bool Stat);
vector<double> ParseList(string List);

int main(int argc, char *argv[])
{
   int DefaultColors[7] = {-1, -1, -1, -1, -1, -1, -1};
   DefaultColors[0] = TColor::GetColor("#3F3F3F");   // Gray
   DefaultColors[1] = TColor::GetColor("#E74C3C");   // Tomato
   DefaultColors[2] = TColor::GetColor("#8E44AD");   // Purple
   DefaultColors[3] = TColor::GetColor("#3498DB");   // Blue
   DefaultColors[4] = TColor::GetColor("#2ECC71");
   DefaultColors[5] = TColor::GetColor("#F1C40F");
   DefaultColors[6] = kMagenta;

   int DefaultMarkers[6] = {20, 20, 20, 20, 20, 20};

   CommandLine CL(argc, argv);

   vector<string> Labels       = CL.GetStringVector("Label");
   vector<string> FileNames    = CL.GetStringVector("File");
   vector<string> CurveBases   = CL.GetStringVector("Curve");
   vector<bool> Types          = CL.GetBoolVector("Type");
   
   bool DoShift                = CL.GetBool("DoShift", false);
   bool DoSquareShift          = CL.GetBool("DoSquareShift", false);
   string ShiftFile            = (DoShift || DoSquareShift) ? CL.Get("ShiftFile") : "";
   string ShiftCurve           = (DoShift || DoSquareShift) ? CL.Get("ShiftCurve") : "";

   bool AddPPVN                = CL.GetBool("AddPPVN", false);

   double ErrorThreshold       = CL.GetDouble("ErrorThreshold", 0.4);
   
   string OutputFileName       = CL.Get("Output");
   string Title                = CL.Get("Title", ";;Efficiency");
   double XMin                 = CL.GetDouble("XMin");
   double XMax                 = CL.GetDouble("XMax");
   bool AutoY                  = CL.GetBool("AutoY", false);
   bool WideAutoY              = CL.GetBool("WideAutoY", false);
   double YMin                 = CL.GetDouble("YMin", -1);
   double YMax                 = CL.GetDouble("YMax", 1);
   vector<int> Colors          = CL.GetIntVector("Color", vector<int>(DefaultColors, DefaultColors + 6));
   vector<int> Markers         = CL.GetIntVector("Marker", vector<int>(DefaultMarkers, DefaultMarkers + 6));
   vector<string> Texts        = CL.GetStringVector("Text", vector<string>());
   bool Grid                   = CL.GetBool("Grid", false);
   bool LogY                   = CL.GetBool("LogY", false);
   double LegendX              = CL.GetDouble("LegendX", 0.35);
   double LegendY              = CL.GetDouble("LegendY", 0.20);

   bool DoMOD                  = CL.GetBool("DoMOD", false);
   double LogoX                = CL.GetDouble("LogoX", 0.82);
   double LogoY                = CL.GetDouble("LogoY", 0.16);
   double LogoW                = CL.GetDouble("LogoW", 0.08);

   // string OutputBase = FindBase(OutputFileName);
   string OutputBase = OutputFileName;

   for(int i = 0; i < (int)Colors.size(); i++)
   {
      if(Colors[i] == -1)   Colors[i] = DefaultColors[0];
      if(Colors[i] == -2)   Colors[i] = DefaultColors[1];
      if(Colors[i] == -3)   Colors[i] = DefaultColors[2];
      if(Colors[i] == -4)   Colors[i] = DefaultColors[3];
      if(Colors[i] == -5)   Colors[i] = DefaultColors[4];
      if(Colors[i] == -6)   Colors[i] = DefaultColors[5];
      if(Colors[i] == -7)   Colors[i] = DefaultColors[6];
   }

   int N = FileNames.size();

   Assert(N == Labels.size(),       "Number of files != number of labels");
   Assert(N == CurveBases.size(),   "Number of files != number of curves");
   Assert(N <= Colors.size(),       "Please specify line colors");

   if(N > Markers.size())
      Markers.insert(Markers.end(), N - Markers.size(), 20);

   TGraphAsymmErrors GShift;
   if(DoShift == true || DoSquareShift == true)
   {
      TFile File(ShiftFile.c_str());
      CopyGraph(GShift, (TGraphAsymmErrors *)File.Get((ShiftCurve + "_Stat").c_str()), false);
      File.Close();
   }

   vector<TGraphAsymmErrors> GraphPPStat;
   vector<TGraphAsymmErrors> GraphPPSys;

   if(AddPPVN == true)
   {
      DataHelper DHFile("Data.dh");

      GraphPPStat.push_back(Transcribe(DHFile, "CMSPPVN2018-14-1", true));
      GraphPPSys.push_back(Transcribe(DHFile, "CMSPPVN2018-14-1", false));
      GraphPPStat.push_back(Transcribe(DHFile, "CMSPPVN2018-15-1", true));
      GraphPPSys.push_back(Transcribe(DHFile, "CMSPPVN2018-15-1", false));
      GraphPPStat.push_back(Transcribe(DHFile, "CMSPPVN2018-16-1", true));
      GraphPPSys.push_back(Transcribe(DHFile, "CMSPPVN2018-16-1", false));

      for(int i = 0; i < 3; i++)
      {
         GraphPPStat[i].SetMarkerColor(DefaultColors[i+3]);
         GraphPPStat[i].SetMarkerStyle(21);
         GraphPPStat[i].SetMarkerSize(1);
         GraphPPStat[i].SetLineColor(DefaultColors[i+3]);
         GraphPPStat[i].SetFillColorAlpha(DefaultColors[i+3], 0.25);
         GraphPPSys[i].SetMarkerColor(DefaultColors[i+3]);
         GraphPPSys[i].SetMarkerStyle(21);
         GraphPPSys[i].SetMarkerSize(1);
         GraphPPSys[i].SetLineColor(DefaultColors[i+3]);
         GraphPPSys[i].SetFillColorAlpha(DefaultColors[i+3], 0.25);
      }
   }

   vector<TGraphAsymmErrors> GraphStat;
   vector<TGraphAsymmErrors> GraphSys;
   for(int i = 0; i < N; i++)
   {
      TGraphAsymmErrors GStat, GSys;

      TFile File(FileNames[i].c_str());

      CopyGraph(GStat, (TGraphAsymmErrors *)File.Get((CurveBases[i] + "_Stat").c_str()), Types[i]);
      CopyGraph(GSys, (TGraphAsymmErrors *)File.Get((CurveBases[i] + "_Sys").c_str()), Types[i]);

      File.Close();

      if(Types[i] == true)
         PrunePoints(GStat, GSys, ErrorThreshold);
      
      if(DoShift == true)
      {
         MakeDelta(GStat, GShift);
         MakeDelta(GSys, GShift);
      }
      if(DoSquareShift == true)
      {
         MakeSquareDelta(GStat, GShift);
         MakeSquareDelta(GSys, GShift);
      }

      GraphStat.push_back(GStat);
      GraphSys.push_back(GSys);
   }

   if(AutoY == true)
   {
      YMax = -999;
      YMin = +999;

      for(int i = 0; i < N; i++)
      {
         for(int j = 0; j < GraphStat[i].GetN(); j++)
         {
            double Y, EYLow, EYHigh;

            Y = GraphStat[i].GetPointY(j);
            EYLow = GraphStat[i].GetErrorYlow(j);
            EYHigh = GraphStat[i].GetErrorYhigh(j);

            if(Y > 100)
               continue;
            
            if(YMax < Y + EYHigh)   YMax = Y + EYHigh;
            if(YMin > Y - EYLow)    YMin = Y - EYLow;
         }

         for(int j = 0; j < GraphSys[i].GetN(); j++)
         {
            double Y, EYLow, EYHigh;

            Y = GraphSys[i].GetPointY(j);
            EYLow = GraphSys[i].GetErrorYlow(j);
            EYHigh = GraphSys[i].GetErrorYhigh(j);

            if(Y > 100)
               continue;
            
            if(YMax < Y + EYHigh)   YMax = Y + EYHigh;
            if(YMin > Y - EYLow)    YMin = Y - EYLow;
         }
      }

      if(YMax <= YMin)   // point not found!
      {
         YMax = 1;
         YMin = -1;
      }
      else  // good!
      {
         double Delta = YMax - YMin;

         if(WideAutoY == false)
         {
            YMax = YMax + Delta * 0.20;
            YMin = YMin - Delta * 0.25;
         }
         else
         {
            YMax = YMax + Delta * 0.40;
            YMin = YMin - Delta * 0.60;
         }
      }
   }

   double CanvasWidth = 800;
   double CanvasHeight = 600;

   TCanvas Canvas;
   Canvas.SetCanvasSize(CanvasWidth, CanvasHeight);
   Canvas.SetTopMargin(0.07);
   Canvas.SetLeftMargin(0.10);
   Canvas.SetRightMargin(0.05);

   TH2D HWorld("HWorld", Title.c_str(), 100, XMin, XMax, 100, YMin, YMax);
   HWorld.SetStats(0);
   HWorld.GetXaxis()->SetTitleOffset(1.2);
   HWorld.GetYaxis()->SetTitleOffset(1.2);

   HWorld.Draw();
   
   TGraph GLine;
   GLine.SetPoint(0, XMin, 0);
   GLine.SetPoint(1, XMax, 0);
   GLine.Draw("l");
   
   if(AddPPVN == true)
   {
      GraphPPSys[0].Draw("2");
      GraphPPStat[0].Draw("p");
      GraphPPSys[1].Draw("2");
      GraphPPStat[1].Draw("p");
      GraphPPSys[2].Draw("2");
      GraphPPStat[2].Draw("p");
   }

   for(int i = 0; i < N; i++)
   {
      GraphStat[i].SetMarkerColor(Colors[i]);
      GraphStat[i].SetMarkerStyle(Markers[i]);
      GraphStat[i].SetMarkerSize(1.25);
      GraphStat[i].SetLineColor(Colors[i]);
      GraphStat[i].SetLineWidth(2);
      
      GraphSys[i].SetMarkerColor(Colors[i]);
      GraphSys[i].SetMarkerStyle(Markers[i]);
      GraphSys[i].SetMarkerSize(1.25);
      GraphSys[i].SetLineColor(Colors[i]);
      GraphSys[i].SetLineWidth(2);
      GraphSys[i].SetFillColorAlpha(Colors[i], 0.25);
      
      if(Types[i] == true)   // data
      {
         GraphSys[i].Draw("2");
         GraphStat[i].Draw("p");

         TArrow Arrow;
         Arrow.SetLineWidth(2);
         Arrow.SetLineColor(Colors[i]);
         Arrow.SetFillColor(Colors[i]);

         for(int j = 0; j < GraphStat[i].GetN(); j++)
         {
            double X = GraphStat[i].GetPointX(j);
            double Y = GraphStat[i].GetPointY(j);
            double XErrHigh = GraphStat[i].GetErrorXhigh(j);

            if(X < XMax && X + XErrHigh > XMax)   // add arrow!
               Arrow.DrawArrow(XMax - 0.1, Y, XMax, Y, 0.015, "|>");
         }
      }
      else   // MC
      {
         GraphStat[i].SetLineStyle(kDashed);
         GraphSys[i].SetLineStyle(kDashed);

         GraphStat[i].Draw("l");
      }
   }

   int LegendCount = 0;
   for(int i = 0; i < N; i++)
      if(Labels[i] != "NONE" && Labels[i] != "None")
         LegendCount = LegendCount + 1;
   TLegend Legend(LegendX, LegendY, LegendX + 0.3, LegendY + 0.06 * LegendCount);
   Legend.SetTextFont(42);
   Legend.SetTextSize(0.035);
   Legend.SetBorderSize(0);
   Legend.SetFillStyle(0);
   for(int i = 0; i < N; i++)
   {
      if(Labels[i] == "NONE" || Labels[i] == "None")
         continue;

      if(Types[i] == true)  // data
         Legend.AddEntry(&GraphSys[i], Labels[i].c_str(), "plf");
      else
         Legend.AddEntry(&GraphSys[i], Labels[i].c_str(), "l");
   }
   Legend.Draw();

   TLegend PPLegend(0.60, 0.88, 0.90, 0.70);
   PPLegend.SetTextFont(42);
   PPLegend.SetTextSize(0.035);
   PPLegend.SetBorderSize(0);
   PPLegend.SetFillStyle(0);
   if(AddPPVN == true)
   {
      PPLegend.AddEntry(&GraphPPSys[0], "CMS pp 13 TeV, v_{2}^{sub}{2}", "plf");
      PPLegend.AddEntry(&GraphPPSys[1], "CMS pp 7 TeV, v_{2}^{sub}{2}", "plf");
      PPLegend.AddEntry(&GraphPPSys[2], "CMS pp 5 TeV, v_{2}^{sub}{2}", "plf");

      PPLegend.Draw();
   }

   if(Texts.size() > 0)
   {
      TLatex Latex;
      Latex.SetNDC();
      Latex.SetTextFont(42);
      Latex.SetTextSize(0.035);
      Latex.SetTextAlign(11);

      for(int i = 0; i + 3 <= (int)Texts.size(); i = i + 3)
      {
         double x = atof(Texts[i+0].c_str());
         double y = atof(Texts[i+1].c_str());
         Latex.DrawLatex(x, y, Texts[i+2].c_str());
      }
   }

   TLatex Latex;
   Latex.SetNDC();
   Latex.SetTextFont(42);
   Latex.SetTextSize(0.035);
   Latex.SetTextAlign(12);
   Latex.DrawLatex(0.11, 0.955, "Archived ALEPH data");
   Latex.SetTextAlign(32);
   Latex.DrawLatex(0.95, 0.955, "LEP2, #sqrt{s} = 183-209 GeV");

   Canvas.SetGridx(Grid);
   Canvas.SetGridy(Grid);
   Canvas.SetLogy(LogY);

   double LogoH = LogoW * CanvasWidth / CanvasHeight * 0.4;

   TPad PadLogo("PadLogo", "", LogoX - LogoW / 2, LogoY - LogoH / 2, LogoX + LogoW / 2, LogoY + LogoH / 2);
   PadLogo.SetLeftMargin(0);
   PadLogo.SetTopMargin(0);
   PadLogo.SetRightMargin(0);
   PadLogo.SetBottomMargin(0);
   TImage *Logo = nullptr;
   if(DoMOD == true)
   {
      PadLogo.Draw();
      PadLogo.cd();
      TImage *Logo = (TImage *)TImage::Open("MOD.eps");
      // Logo->SetJpegDpi("MOD.jpg", 300);
      Logo->Draw("xxxz");
   }

   Canvas.SaveAs((OutputBase + ".pdf").c_str());
   // Canvas.SaveAs((OutputBase + ".png").c_str());

   return 0;
}

int Sign(double Number)
{
   return (0 < Number) - (0 > Number);
}

string FindBase(string FileName)
{
   if(FileName.find('.') == string::npos)
      return FileName;

   FileName.erase(FileName.begin() + FileName.rfind('.'), FileName.end());
   return FileName;
}

void CopyGraph(TGraphAsymmErrors &G, TGraphAsymmErrors *S, bool IsData)
{
   if(S == nullptr)
      return;

   G.Set(0);
   
   int N = S->GetN();
   for(int i = 0; i < N; i++)
   {
      double X, Y, XLow, XHigh, YLow, YHigh;
      X = S->GetPointX(i);
      Y = S->GetPointY(i);
      XLow = S->GetErrorXlow(i);
      XHigh = S->GetErrorXhigh(i);
      YLow = S->GetErrorYlow(i);
      YHigh = S->GetErrorYhigh(i);

      G.SetPoint(i, X, Y);
      if(IsData == true)
         G.SetPointError(i, XLow, XHigh, YLow, YHigh);
      else
         G.SetPointError(i, 0, 0, 0, 0);
   }
}

void MakeDelta(TGraphAsymmErrors &G1, TGraphAsymmErrors &G2)
{
   for(int i = 0; i < G1.GetN(); i++)
   {
      double X = G1.GetPointX(i);
      double EXLow = G1.GetErrorXlow(i);
      double EXHigh = G1.GetErrorXhigh(i);
      double Y = G1.GetPointY(i);
      double EYLow = G1.GetErrorYlow(i);
      double EYHigh = G1.GetErrorYhigh(i);

      if(Y > 1000)
         continue;

      double YShift = 0;
      bool Found = false;
      for(int j = 0; j < G2.GetN(); j++)
      {
         double XShift = G2.GetPointX(j);
         if(XShift < X - EXLow)
            continue;
         if(XShift > X + EXHigh)
            continue;

         Found = true;
         YShift = G2.GetPointY(j);
      }
      if(Found == false)
         continue;

      G1.SetPoint(i, X, Y - YShift);
      G1.SetPointError(i, EXLow, EXHigh, EYLow, EYHigh);
   }
}

void MakeSquareDelta(TGraphAsymmErrors &G1, TGraphAsymmErrors &G2)
{
   for(int i = 0; i < G1.GetN(); i++)
   {
      double X = G1.GetPointX(i);
      double EXLow = G1.GetErrorXlow(i);
      double EXHigh = G1.GetErrorXhigh(i);
      double Y = G1.GetPointY(i);
      double EYLow = G1.GetErrorYlow(i);
      double EYHigh = G1.GetErrorYhigh(i);

      if(Y > 1000)
         continue;

      double YShift = 0;
      bool Found = false;
      for(int j = 0; j < G2.GetN(); j++)
      {
         double XShift = G2.GetPointX(j);
         if(XShift < X - EXLow)
            continue;
         if(XShift > X + EXHigh)
            continue;

         Found = true;
         YShift = G2.GetPointY(j);
      }
      if(Found == false)
         continue;

      double OriginalVn = Sign(Y) * Y * Y;
      double ShiftVn = Sign(YShift) * YShift * YShift;

      double OriginalEY = EYHigh * 2 * sqrt(abs(OriginalVn));

      vector<double> vnCollection;
      for(int k = 0; k < 10000; k++)
      {
         double NewVn = DrawGaussian(OriginalVn, OriginalEY) - ShiftVn;
         double Newvn = Sign(NewVn) * sqrt(fabs(NewVn));
         vnCollection.push_back(Newvn);
      }

      int N = 0;
      double Sum = 0;
      double Sum2 = 0;
      for(double vn : vnCollection)
      {
         N = N + 1;
         Sum = Sum + vn;
         Sum2 = Sum2 + vn * vn;
      }

      double Mean = Sum / N;
      double RMS = sqrt((Sum2 - N * Mean * Mean) / N);

      double ShiftedVn = OriginalVn - ShiftVn;
      double Shiftedvn = Sign(ShiftedVn) * sqrt(fabs(ShiftedVn));

      G1.SetPoint(i, X, Shiftedvn);
      G1.SetPointError(i, EXLow, EXHigh, RMS, RMS);
   }
}

void PrunePoints(TGraphAsymmErrors &G1, TGraphAsymmErrors &G2, double Threshold)
{
   for(int i = 0; i < G1.GetN(); i++)
   {
      double G1X = G1.GetPointX(i);
      double G1EXLow = G1.GetErrorXlow(i);
      double G1EXHigh = G1.GetErrorXhigh(i);
      double G1Y = G1.GetPointY(i);
      double G1EYLow = G1.GetErrorYlow(i);
      double G1EYHigh = G1.GetErrorYhigh(i);

      for(int j = 0; j < G2.GetN(); j++)
      {
         double G2X = G2.GetPointX(j);
         double G2EXLow = G2.GetErrorXlow(j);
         double G2EXHigh = G2.GetErrorXhigh(j);
         double G2Y = G2.GetPointY(j);
         double G2EYLow = G2.GetErrorYlow(j);
         double G2EYHigh = G2.GetErrorYhigh(j);

         if(G2X < G1X - G1EXLow)    continue;
         if(G2X > G1X + G1EXHigh)   continue;

         if(G1EYLow > Threshold || G1EYHigh > Threshold || G2EYLow > Threshold || G2EYHigh > Threshold)
         {
            G1.SetPoint(i, G1X, 99999);
            G2.SetPoint(j, G2X, 99999);
         }

         break;
      }
   }
}

TGraphAsymmErrors Transcribe(DataHelper &DHFile, string State, bool Stat)
{
   TGraphAsymmErrors G;

   vector<double> X = ParseList(DHFile[State]["X"].GetString());
   vector<double> Y = ParseList(DHFile[State]["Y"].GetString());

   vector<double> YHigh = ParseList(DHFile[State][Stat?"EYStatHigh":"EYSysHigh"].GetString());
   vector<double> YLow = ParseList(DHFile[State][Stat?"EYStatLow":"EYSysLow"].GetString());

   int N = X.size();

   for(int i = 0; i < N; i++)
   {
      cout << X[i] << " " << Y[i] << endl;
      G.SetPoint(i, X[i], Y[i]);
      G.SetPointError(i, 0.05, 0.05, YLow[i], YHigh[i]);
   }

   return G;
}

vector<double> ParseList(string List)
{
   for(int i = 0; i < List.size(); i++)
   {
      if(List[i] == ',')   List[i] = ' ';
      if(List[i] == '[')   List[i] = ' ';
      if(List[i] == ']')   List[i] = ' ';
   }

   stringstream str(List);

   vector<double> Result;

   while(str)
   {
      double Temp = -1000;
      str >> Temp;

      if(Temp > -999)
         Result.push_back(Temp);
   }

   return Result;
}



