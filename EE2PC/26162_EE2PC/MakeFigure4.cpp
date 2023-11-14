#include <iostream>
using namespace std;

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TH2D.h"
#include "TGaxis.h"
#include "TGraph.h"
#include "TLatex.h"
#include "TGraphAsymmErrors.h"
#include "TLegend.h"
#include "TArrow.h"

#include "SetStyle.h"

#define BaseTextSize 0.06
#define AxisSpacing 505
#define TypeStat 0
#define TypeSys 1
#define TypeMC 2

int main(int argc, char *argv[]);
void SetPad(TPad &P);
void SetAxis(TGaxis &A);
void SetWorld(TH2D &H);
TGraphAsymmErrors Transcribe(int type, int vn, int nmin, int color);
TArrow MakeArrow(TGraphAsymmErrors &G, double XMax);

int main(int argc, char *argv[])
{
   vector<int> PrimaryColors = GetPrimaryColors();
   int Colors[4] = {kBlack, PrimaryColors[4], PrimaryColors[0], PrimaryColors[5]};

   // Setup canvas
   double PanelW = 500, PanelH = 500;
   double MarginL = 100, MarginR = 25, MarginT = 50, MarginB = 100;
   double PanelSpacing = 50;

   double XMin = 0, XMax = 4.5;
   double YMin = -0.8, YMax = 0.8;

   double CanvasW = MarginL + PanelW + PanelSpacing + PanelW + MarginR;
   double CanvasH = MarginT + PanelH + MarginB;

   PanelW = PanelW / CanvasW;
   PanelH = PanelH / CanvasH;
   MarginL = MarginL / CanvasW;
   MarginR = MarginR / CanvasW;
   MarginT = MarginT / CanvasH;
   MarginB = MarginB / CanvasH;
   PanelSpacing = PanelSpacing / CanvasW;

   TCanvas Canvas("Canvas", "", CanvasW, CanvasH);

   // Setup pads
   TPad Pad1("Pad1", "", MarginL, MarginB,
      MarginL + PanelW, MarginB + PanelH);
   SetPad(Pad1);
   
   TPad Pad2("Pad2", "", MarginL + PanelW + PanelSpacing, MarginB,
      MarginL + PanelW * 2 + PanelSpacing, MarginB + PanelH);
   SetPad(Pad2);

   // Setup axes
   TGaxis XAxis1(MarginL, MarginB, MarginL + PanelW, MarginB,
      XMin, XMax, AxisSpacing, "S");
   SetAxis(XAxis1);
   
   TGaxis XAxis2(MarginL + PanelW + PanelSpacing, MarginB, MarginL + PanelW * 2 + PanelSpacing, MarginB,
      XMin, XMax, AxisSpacing, "S");
   SetAxis(XAxis2);

   TGaxis YAxis(MarginL, MarginB, MarginL, MarginB + PanelH, YMin, YMax, AxisSpacing, "S");
   SetAxis(YAxis);

   // Add texts
   TLatex Latex;

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(22);
   Latex.SetTextAngle(0);
   Latex.DrawLatex(MarginL + PanelW * 0.5, MarginB * 0.35, "p_{T} (GeV)");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(22);
   Latex.SetTextAngle(0);
   Latex.DrawLatex(MarginL + PanelW + PanelSpacing + PanelW * 0.5, MarginB * 0.35, "p_{T} (GeV)");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(22);
   Latex.SetTextAngle(90);
   Latex.DrawLatex(MarginL * 0.35, MarginB + PanelH * 0.5, "v_{n}");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(11);
   Latex.SetTextAngle(0);
   // Latex.DrawLatex(MarginL, MarginB + PanelH + 0.01, "Archived ALEPH data, Thrust Axis");
   Latex.DrawLatex(MarginL, MarginB + PanelH + 0.01, "#bf{#it{ALEPH e^{+}e^{-}, #sqrt{s} = 183-209 GeV}}");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(31);
   Latex.SetTextAngle(0);
   // Latex.DrawLatex(MarginL + PanelW * 2 + PanelSpacing, MarginB + PanelH + 0.01, "LEP2 #sqrt{s} = 183-209 GeV");
   Latex.DrawLatex(MarginL + PanelW * 2 + PanelSpacing, MarginB + PanelH + 0.01, "Thrust Axis");

   // Setup lines and curves
   TGraph GLine;
   GLine.SetPoint(0, XMin, 0);
   GLine.SetPoint(1, XMax, 0);

   TGraphAsymmErrors GN0V1Stat  = Transcribe(TypeStat, 1, 0, Colors[1]);
   TGraphAsymmErrors GN0V1Sys   = Transcribe(TypeSys,  1, 0, Colors[1]);
   TGraphAsymmErrors GN0V1MC    = Transcribe(TypeMC,   1, 0, Colors[1]);
   TGraphAsymmErrors GN0V2Stat  = Transcribe(TypeStat, 2, 0, Colors[2]);
   TGraphAsymmErrors GN0V2Sys   = Transcribe(TypeSys,  2, 0, Colors[2]);
   TGraphAsymmErrors GN0V2MC    = Transcribe(TypeMC,   2, 0, Colors[2]);
   TGraphAsymmErrors GN0V3Stat  = Transcribe(TypeStat, 3, 0, Colors[3]);
   TGraphAsymmErrors GN0V3Sys   = Transcribe(TypeSys,  3, 0, Colors[3]);
   TGraphAsymmErrors GN0V3MC    = Transcribe(TypeMC,   3, 0, Colors[3]);
   TGraphAsymmErrors GN50V1Stat = Transcribe(TypeStat, 1, 50, Colors[1]);
   TGraphAsymmErrors GN50V1Sys  = Transcribe(TypeSys,  1, 50, Colors[1]);
   TGraphAsymmErrors GN50V1MC   = Transcribe(TypeMC,   1, 50, Colors[1]);
   TGraphAsymmErrors GN50V2Stat = Transcribe(TypeStat, 2, 50, Colors[2]);
   TGraphAsymmErrors GN50V2Sys  = Transcribe(TypeSys,  2, 50, Colors[2]);
   TGraphAsymmErrors GN50V2MC   = Transcribe(TypeMC,   2, 50, Colors[2]);
   TGraphAsymmErrors GN50V3Stat = Transcribe(TypeStat, 3, 50, Colors[3]);
   TGraphAsymmErrors GN50V3Sys  = Transcribe(TypeSys,  3, 50, Colors[3]);
   TGraphAsymmErrors GN50V3MC   = Transcribe(TypeMC,   3, 50, Colors[3]);

   TGraphAsymmErrors GN0V0Sys   = Transcribe(TypeSys, 0, 0, Colors[0]);
   TGraphAsymmErrors GN0V0MC    = Transcribe(TypeMC, 0, 0, Colors[0]);

   // Setup arrows
   TArrow ArrowN0V1  = MakeArrow(GN0V1Stat,  XMax);
   TArrow ArrowN0V2  = MakeArrow(GN0V2Stat,  XMax);
   TArrow ArrowN0V3  = MakeArrow(GN0V3Stat,  XMax);
   TArrow ArrowN50V1 = MakeArrow(GN50V1Stat, XMax);
   TArrow ArrowN50V2 = MakeArrow(GN50V2Stat, XMax);
   TArrow ArrowN50V3 = MakeArrow(GN50V3Stat, XMax);

   // Draw left pad
   Pad1.cd();
   TH2D HWorld1("HWorld1", "", 100, XMin, XMax, 100, YMin, YMax);
   SetWorld(HWorld1);

   GN0V1Sys.Draw("2");
   GN0V2Sys.Draw("2");
   GN0V3Sys.Draw("2");
   
   GN0V1Stat.Draw("p");
   GN0V2Stat.Draw("p");
   GN0V3Stat.Draw("p");

   ArrowN0V1.Draw("|>");
   ArrowN0V2.Draw("|>");
   ArrowN0V3.Draw("|>");
   
   GN0V1MC.Draw("l");
   GN0V2MC.Draw("l");
   GN0V3MC.Draw("l");

   GLine.Draw("l");

   TLegend Legend1(0.675, 0.25, 1.175, 0.05);
   Legend1.SetTextFont(42);
   Legend1.SetTextSize(BaseTextSize / PanelH);
   Legend1.SetFillStyle(0);
   Legend1.SetBorderSize(0);
   Legend1.AddEntry(&GN0V0Sys, "Data", "lpf");
   Legend1.AddEntry(&GN0V0MC, "MC", "l");
   Legend1.Draw();

   HWorld1.Draw("axis same");
   
   // Draw right pad
   Pad2.cd();
   TH2D HWorld2("HWorld2", "", 100, XMin, XMax, 100, YMin, YMax);
   SetWorld(HWorld2);

   GN50V1Sys.Draw("2");
   GN50V2Sys.Draw("2");
   GN50V3Sys.Draw("2");
   
   GN50V1Stat.Draw("p");
   GN50V2Stat.Draw("p");
   GN50V3Stat.Draw("p");
   
   ArrowN50V1.Draw("|>");
   ArrowN50V2.Draw("|>");
   ArrowN50V3.Draw("|>");
   
   GN50V1MC.Draw("l");
   GN50V2MC.Draw("l");
   GN50V3MC.Draw("l");

   GLine.Draw("l");

   TLegend Legend2(0.75, 0.35, 1.25, 0.05);
   Legend2.SetTextFont(42);
   Legend2.SetTextSize(BaseTextSize / PanelH);
   Legend2.SetFillStyle(0);
   Legend2.SetBorderSize(0);
   Legend2.AddEntry(&GN50V1Sys, "v_{1}", "lpf");
   Legend2.AddEntry(&GN50V2Sys, "v_{2}", "lpf");
   Legend2.AddEntry(&GN50V3Sys, "v_{3}", "lpf");
   Legend2.Draw();
   
   HWorld2.Draw("axis same");

   // Draw labels on top of pads
   Canvas.cd();

   double OffsetX = 0.025;
   double OffsetY = OffsetX * CanvasW / CanvasH;

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(13);
   Latex.SetTextAngle(0);
   Latex.DrawLatex(MarginL + OffsetX, MarginB + PanelH - OffsetY, "N_{trk} #geq 0");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(13);
   Latex.SetTextAngle(0);
   Latex.DrawLatex(MarginL + PanelW + PanelSpacing + OffsetX, MarginB + PanelH - OffsetY, "N_{trk} #geq 50");

   Canvas.SaveAs("Figure4.C");
   Canvas.SaveAs("Figure4Raw.pdf");

   return 0;
}

void SetPad(TPad &P)
{
   P.SetLeftMargin(0);
   P.SetTopMargin(0);
   P.SetRightMargin(0);
   P.SetBottomMargin(0);
   P.SetTickx();
   P.SetTicky();
   P.Draw();
}

void SetAxis(TGaxis &A)
{
   A.SetLabelFont(42);
   A.SetLabelSize(BaseTextSize);
   A.SetMaxDigits(6);
   A.SetMoreLogLabels();
   // A.SetNoExponent();
   A.SetTickSize(0);
   A.SetTickLength(0);
   A.Draw();
}

void SetWorld(TH2D &H)
{
   H.SetStats(0);
   H.GetXaxis()->SetNdivisions(AxisSpacing);
   H.GetYaxis()->SetNdivisions(AxisSpacing);
   H.Draw("axis");
}

TGraphAsymmErrors Transcribe(int type, int vn, int nmin, int color)
{
   TGraphAsymmErrors G;

   TFile File("Fig4.root");
   TTree *Tree = (TTree *)File.Get("Tree");

   // branches x:exl:exh:y:eyl:eyh:syl:syh:MC:vn:Nmin:Nmax

   double X, EXL, EXH, Y, EYL, EYH, SYL, SYH, MC, VN, NMin, NMax;
   Tree->SetBranchAddress("x",    &X);
   Tree->SetBranchAddress("exl",  &EXL);
   Tree->SetBranchAddress("exh",  &EXH);
   Tree->SetBranchAddress("y",    &Y);
   Tree->SetBranchAddress("eyl",  &EYL);
   Tree->SetBranchAddress("eyh",  &EYH);
   Tree->SetBranchAddress("syl",  &SYL);
   Tree->SetBranchAddress("syh",  &SYH);
   Tree->SetBranchAddress("MC",   &MC);
   Tree->SetBranchAddress("vn",   &VN);
   Tree->SetBranchAddress("Nmin", &NMin);
   Tree->SetBranchAddress("Nmax", &NMax);

   int EntryCount = Tree->GetEntries();
   for(int iE = 0; iE < EntryCount; iE++)
   {
      Tree->GetEntry(iE);

      // Sloppy!  double-int comparison
      if(VN != vn)
         continue;
      if(NMin != nmin)
         continue;

      int N = G.GetN();

      if(type == TypeStat)
      {
         G.SetPoint(N, X, Y);
         G.SetPointError(N, EXL, EXH, EYL, EYH);
      }
      if(type == TypeSys)
      {
         G.SetPoint(N, X, Y);
         G.SetPointError(N, EXL, EXH, SYL, SYH);
      }
      if(type == TypeMC)
         G.SetPoint(N, X, MC);
   }

   File.Close();

   G.SetLineWidth(2);
   G.SetLineColor(color);
   G.SetMarkerStyle(20);
   G.SetMarkerSize(1.75);
   G.SetMarkerColor(color);
   G.SetFillColorAlpha(color, 0.25);
   G.SetLineStyle((type == TypeMC) ? kDashed : kSolid);

   return G;
}

TArrow MakeArrow(TGraphAsymmErrors &G, double XMax)
{
   double Y = 0;

   for(int i = 0; i < G.GetN(); i++)
   {
      double X = G.GetPointX(i);
      double XErrHigh = G.GetErrorXhigh(i);

      if(X < XMax && X + XErrHigh > XMax)
      {
         Y = G.GetPointY(i);
         break;
      }
   }

   TArrow Arrow(XMax - 0.1, Y, XMax, Y, 0.015);

   Arrow.SetLineWidth(G.GetLineWidth());
   Arrow.SetLineColor(G.GetLineColor());
   Arrow.SetFillColor(G.GetLineColor());

   return Arrow;
}
