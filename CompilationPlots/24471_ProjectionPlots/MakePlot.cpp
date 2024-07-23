#include <iostream>
#include <vector>
using namespace std;

#include "TCanvas.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TLegend.h"
#include "TLatex.h"

#include "DataHelper.h"
#include "SetStyle.h"
#include "CommandLine.h"

#define ERROR_STAT 0
#define ERROR_SYS 1
#define ERROR_BOTH 2

int main(int argc, char *argv[]);
TGraphAsymmErrors GetGraph(DataHelper &DHFile, string State,
   double Scale = 1, int Error = ERROR_BOTH, double DXOverride = 0.0, double ErrorScale = 1.0,
   double XShift = 0);
vector<double> ParseDoubleList(string input);
void SetGraph(TGraphAsymmErrors &G, int Color, int Marker, int Error);
string DetectBase(string Name);

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   string DHFileName = CL.Get("DHFile", "Data.dh");
   vector<string> States = CL.GetStringVector("States");
   vector<string> Labels = CL.GetStringVector("Labels");
   vector<double> Scales = CL.GetDoubleVector("Scales", vector<double>());
   vector<double> SysScale = CL.GetDoubleVector("SysScale", vector<double>());
   vector<double> StatScale = CL.GetDoubleVector("StatScale", vector<double>());
   vector<double> XShift = CL.GetDoubleVector("XShift", vector<double>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

   string OutputFileName = CL.Get("Output");

   double XMin = CL.GetDouble("XMin", 0);
   double XMax = CL.GetDouble("XMax", 1);
   double YMin = CL.GetDouble("YMin", 0);
   double YMax = CL.GetDouble("YMax", 1);
   bool LogX = CL.GetBool("LogX", false);
   bool LogY = CL.GetBool("LogY", false);
   string XLabel = CL.Get("XLabel", "");
   string YLabel = CL.Get("YLabel", "");
   bool Wide = CL.GetBool("Wide", false);

   double DXOverride = CL.GetDouble("DXOverride", 0.0);

   double LegendX = CL.GetDouble("LegendX", 0.5);
   double LegendY = CL.GetDouble("LegendY", 0.5);
   double LegendW = CL.GetDouble("LegendW", 0.3);
   double LegendH = CL.GetDouble("LegendH", 0.2);

   vector<string> Texts = CL.GetStringVector("Texts");

   // vector<int> Colors = GetPrimaryColors();
   // vector<int> Markers{20, 22, 23, 21};
   vector<int> Markers{20, 22, 47, 22, 23, 21};
   vector<int> Colors{kGreen + 3, kMagenta - 3, kAzure - 1};
   
   if(Wide == true)
      SetThumbStyleWide();
   else
      SetThumbStyle();

   int N = States.size();

   if(Scales.size() < N)
      Scales.insert(Scales.end(), N - Scales.size(), 1);
   if(SysScale.size() < States.size())
      SysScale.insert(SysScale.end(), N - SysScale.size(), 1.0);
   if(StatScale.size() < States.size())
      StatScale.insert(StatScale.end(), N - StatScale.size(), 1.0);

   DataHelper DHFile(DHFileName);

   vector<TGraphAsymmErrors> GSys(N);
   vector<TGraphAsymmErrors> GStat(N);
   for(int i = 0; i < N; i++)
   {
      GSys[i] = GetGraph(DHFile, States[i], Scales[i], ERROR_SYS, DXOverride, SysScale[i], XShift[i]);
      GStat[i] = GetGraph(DHFile, States[i], Scales[i], ERROR_STAT, DXOverride, StatScale[i], XShift[i]);
      SetGraph(GSys[i], Colors[i], Markers[i], ERROR_SYS);
      SetGraph(GStat[i], Colors[i], Markers[i], ERROR_STAT);
   }

   TH2D HWorld("HWorld", "", 100, XMin, XMax, 100, YMin, YMax);
   HWorld.SetStats(0);

   HWorld.GetXaxis()->SetNdivisions(505);
   HWorld.GetYaxis()->SetNdivisions(505);
   
   HWorld.GetXaxis()->CenterTitle();
   HWorld.GetYaxis()->CenterTitle();

   HWorld.GetXaxis()->SetTitle(XLabel.c_str());
   HWorld.GetYaxis()->SetTitle(YLabel.c_str());

   TCanvas Canvas;

   HWorld.Draw("axis");

   // TGraph G;
   // G.SetPoint(0, 0, 1);
   // G.SetPoint(1, 10000, 1);
   // G.Draw("l");

   for(int i = 0; i < N; i++)
   {
      GSys[i].Draw("2");
      GStat[i].Draw("p");
   }

   TLegend Legend(LegendX, LegendY, LegendX + LegendW, LegendY + LegendH);
   Legend.SetTextFont(42);
   Legend.SetTextSize(0.05);
   Legend.SetBorderSize(0);
   Legend.SetFillStyle(0);
   for(int i = 0; i < N; i++)
      Legend.AddEntry(&GSys[i], Labels[i].c_str(), "pf");
   Legend.Draw();

   TLatex Latex;
   Latex.SetTextFont(42);
   Latex.SetTextSize(0.035);
   Latex.SetTextAlign(12);
   Latex.SetTextColor(14);
   Latex.SetNDC();

   cout << "!" << endl;
   for(int i = 0; i + 3 <= (int)Texts.size(); i = i + 3)
      Latex.DrawLatex(stof(Texts[i+0]), stof(Texts[i+1]), Texts[i+2].c_str());

   Latex.SetTextSize(0.04);
   Latex.SetTextColor(kBlack);
   Latex.DrawLatex(0.19, 0.83, "#font[62]{#scale[1.4]{CMS}}  Run3");
   Latex.DrawLatex(0.19, 0.77, "#font[52]{Projection}");
   
   Latex.SetTextSize(0.04);
   Latex.SetTextColor(kBlack);
   Latex.SetTextAlign(12);
   Latex.DrawLatex(0.15, 0.925, "#sqrt{s_{NN}} = 5.02 TeV");
   Latex.SetTextAlign(32);
   Latex.DrawLatex(0.90, 0.925, "PbPb 0-30%");

   if(LogX == true)
   {
      HWorld.GetXaxis()->SetMoreLogLabels();
      HWorld.GetXaxis()->SetNoExponent();
      Canvas.SetLogx();
   }
   if(LogY == true)
      Canvas.SetLogy();

   string OutputBase = DetectBase(OutputFileName);

   Canvas.SaveAs((OutputBase + ".pdf").c_str());
   Canvas.SaveAs((OutputBase + ".png").c_str());

   return 0;
}

TGraphAsymmErrors GetGraph(DataHelper &DHFile, string State, double Scale, int Error, double DXOverride, double ErrorScale, double XShift)
{
   cout << XShift << endl;

   vector<double> X = ParseDoubleList(DHFile[State]["X"].GetString());
   vector<double> Y = ParseDoubleList(DHFile[State]["Y"].GetString());
   vector<double> EXL = ParseDoubleList(DHFile[State]["EXLow"].GetString());
   vector<double> EXH = ParseDoubleList(DHFile[State]["EXHigh"].GetString());
   vector<double> EYLStat = ParseDoubleList(DHFile[State]["EYStatLow"].GetString());
   vector<double> EYHStat = ParseDoubleList(DHFile[State]["EYStatHigh"].GetString());
   vector<double> EYLSys = ParseDoubleList(DHFile[State]["EYSysLow"].GetString());
   vector<double> EYHSys = ParseDoubleList(DHFile[State]["EYSysHigh"].GetString());
   double Global = stof(DHFile[State]["GlobalUncertainty"].GetString()) * Scale;

   for(double &V : Y)         V = V * Scale;
   for(double &V : EYLStat)   V = V * Scale * ErrorScale;
   for(double &V : EYHStat)   V = V * Scale * ErrorScale;
   for(double &V : EYLSys)    V = V * Scale * ErrorScale;
   for(double &V : EYHSys)    V = V * Scale * ErrorScale;

   int N = X.size();

   TGraphAsymmErrors G;

   for(int i = 0; i < N; i++)
   {
      double EYL = 0, EYH = 0;

      if(Error == ERROR_STAT || Error == ERROR_BOTH)
      {
         EYL = EYL + EYLStat[i] * EYLStat[i];
         EYH = EYH + EYHStat[i] * EYHStat[i];
      }
      if(Error == ERROR_SYS || Error == ERROR_BOTH)
      {
         EYL = EYL + EYLSys[i] * EYLSys[i] + Global * Global * Y[i] * Y[i];
         EYH = EYH + EYHSys[i] * EYHSys[i] + Global * Global * Y[i] * Y[i];
      }

      if(EXL[i] == 0 && EXH[i] == 0)
      {
         EXL[i] = DXOverride;
         EXH[i] = DXOverride;
      }

      if(XShift != 0)
      {
         double NewX = X[i];
         if(XShift > 0)
            NewX = X[i] + XShift * EXH[i];
         else
            NewX = X[i] + XShift * EXL[i];

         EXL[i] = NewX - (X[i] - EXL[i]);
         EXH[i] = (X[i] + EXH[i]) - NewX;
         X[i] = NewX;
      }

      EYL = sqrt(EYL);
      EYH = sqrt(EYH);
      
      cout << X[i] << " " << Y[i] << " " << EYLSys[i] << " " << EYHSys[i] << " " << EYL << " " << EYH << endl;

      G.SetPoint(i, X[i], Y[i]);
      G.SetPointError(i, EXL[i], EXH[i], EYL, EYH);
   }

   return G;
}

vector<double> ParseDoubleList(string input)
{
   for(int i = 0; i < input.size(); i++)
   {
      if(input[i] == '[' || input[i] == ']' || input[i] == ',')
         input[i] = ' ';
   }

   vector<double> Result;
   
   stringstream str(input);
   while(str)
   {
      double Temp = -10000;
      str >> Temp;
      if(Temp > -9999)
         Result.push_back(Temp);
   }

   return Result;
}

void SetGraph(TGraphAsymmErrors &G, int Color, int Marker, int Error)
{
   G.SetMarkerSize(2);
   G.SetMarkerStyle(Marker);
   G.SetLineWidth(3);
   G.SetMarkerColor(Color);
   G.SetLineColor(Color);
   G.SetFillColorAlpha(Color, 0.25);

   if(Error == ERROR_SYS)
      G.SetLineWidth(0);
}

string DetectBase(string Name)
{
   int index = Name.find_last_of('.');
   if(index == string::npos)
      return Name;

   return Name.substr(0, index);
}

