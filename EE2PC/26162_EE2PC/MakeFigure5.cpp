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

#define BaseTextSize 0.05
#define AxisSpacing 505
#define TypeStat 0
#define TypeSys 1
#define TypeMC 2

int main(int argc, char *argv[]);
void SetPad(TPad &P);
void SetAxis(TGaxis &A);
void SetWorld(TH2D &H);
TGraphAsymmErrors Transcribe(int type, double e, int color);
TArrow MakeArrow(TGraphAsymmErrors &G, double XMax);

int main(int argc, char *argv[])
{
   vector<int> PrimaryColors = GetPrimaryColors();
   int Colors[4] = {TColor::GetColorDark(PrimaryColors[0]),  PrimaryColors[1], PrimaryColors[3], PrimaryColors[2]};

   // Setup canvas
   double PanelW = 500, PanelH = 500;
   double MarginL = 75, MarginR = 25, MarginT = 50, MarginB = 75;

   double XMin = 0, XMax = 6;
   double YMin = -0.8, YMax = 0.8;

   double CanvasW = MarginL + PanelW + MarginR;
   double CanvasH = MarginT + PanelH + MarginB;

   PanelW = PanelW / CanvasW;
   PanelH = PanelH / CanvasH;
   MarginL = MarginL / CanvasW;
   MarginR = MarginR / CanvasW;
   MarginT = MarginT / CanvasH;
   MarginB = MarginB / CanvasH;

   TCanvas Canvas("Canvas", "", CanvasW, CanvasH);

   // Setup pad
   TPad Pad("Pad", "", MarginL, MarginB, MarginL + PanelW, MarginB + PanelH);
   SetPad(Pad);
   
   // Setup axes
   TGaxis XAxis(MarginL, MarginB, MarginL + PanelW, MarginB, XMin, XMax, AxisSpacing, "S");
   SetAxis(XAxis);
   
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
   Latex.SetTextAngle(90);
   Latex.DrawLatex(MarginL * 0.35, MarginB + PanelH * 0.5, "sign(#DeltaV_{2}) #sqrt{|#DeltaV_{2}|}");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(11);
   Latex.SetTextAngle(0);
   // Latex.DrawLatex(MarginL, MarginB + PanelH + 0.01, "Archived ALEPH data, Thrust Axis");
   Latex.DrawLatex(MarginL, MarginB + PanelH + 0.01, "#bf{#it{ALEPH e^{+}e^{-}, #sqrt{s} = 183-209 GeV}}");

   // Setup lines and curves
   TGraph GLine;
   GLine.SetPoint(0, XMin, 0);
   GLine.SetPoint(1, XMax, 0);

   TGraphAsymmErrors GALEPHStat  = Transcribe(TypeStat, 0.2, Colors[0]);
   TGraphAsymmErrors GALEPHSys   = Transcribe(TypeSys,  0.2, Colors[0]);
   TGraphAsymmErrors GCMS13Stat  = Transcribe(TypeStat, 13,  Colors[1]);
   TGraphAsymmErrors GCMS13Sys   = Transcribe(TypeSys,  13,  Colors[1]);
   TGraphAsymmErrors GCMS7Stat   = Transcribe(TypeStat, 7,   Colors[2]);
   TGraphAsymmErrors GCMS7Sys    = Transcribe(TypeSys,  7,   Colors[2]);
   TGraphAsymmErrors GCMS5Stat   = Transcribe(TypeStat, 5,   Colors[3]);
   TGraphAsymmErrors GCMS5Sys    = Transcribe(TypeSys,  5,   Colors[3]);

   // Setup arrows
   TArrow ArrowALEPH = MakeArrow(GALEPHStat,  XMax);

   // Draw things!
   Pad.cd();
   TH2D HWorld("HWorld", "", 100, XMin, XMax, 100, YMin, YMax);
   SetWorld(HWorld);

   GCMS13Sys.Draw("2");
   GCMS7Sys.Draw("2");
   GCMS5Sys.Draw("2");
   GALEPHSys.Draw("2");

   GCMS13Stat.Draw("p");
   GCMS7Stat.Draw("p");
   GCMS5Stat.Draw("p");
   GALEPHStat.Draw("p");

   ArrowALEPH.Draw("|>");
   
   GLine.Draw("l");

   TLegend Legend1(0.3, 0.275, 0.6, 0.02);
   Legend1.SetTextFont(42);
   Legend1.SetTextSize(BaseTextSize / PanelH);
   Legend1.SetFillStyle(0);
   Legend1.SetBorderSize(0);
   Legend1.AddEntry(&GCMS13Sys, "CMS pp 13 TeV, v_{2}^{sub}{2}", "lp");
   Legend1.AddEntry(&GCMS7Sys, "CMS pp 7 TeV, v_{2}^{sub}{2}", "lp");
   Legend1.AddEntry(&GCMS5Sys, "CMS pp 5 TeV, v_{2}^{sub}{2}", "lp");
   Legend1.Draw();

   TLegend Legend2(0.6, 0.36, 0.9, 0.275);
   Legend2.SetTextFont(42);
   Legend2.SetTextSize(BaseTextSize / PanelH);
   Legend2.SetFillStyle(0);
   Legend2.SetBorderSize(0);
   Legend2.AddEntry(&GALEPHSys, "Data - MC", "lpf");
   Legend2.Draw();

   HWorld.Draw("axis same");
   
   // Draw labels on top of pads
   Canvas.cd();

   double OffsetX = 0.03;
   double OffsetY = OffsetX * CanvasW / CanvasH;

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(13);
   Latex.SetTextAngle(0);
   Latex.DrawLatex(MarginL + OffsetX, MarginB + PanelH - OffsetY, "N_{trk} #geq 50");
   Latex.DrawLatex(MarginL + OffsetX, MarginB + PanelH - OffsetY - BaseTextSize * 1.1, "Thrust Axis");

   Canvas.SaveAs("Figure5.C");
   Canvas.SaveAs("Figure5Raw.pdf");

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

TGraphAsymmErrors Transcribe(int type, double e, int color)
{
   TGraphAsymmErrors G;

   TFile File("Fig5.root");
   TTree *Tree = (TTree *)File.Get("Tree");

	// branches x:exl:exh:y:eyl:eyh:syl:syh:energy

   double X, EXL, EXH, Y, EYL, EYH, SYL, SYH, E;
   Tree->SetBranchAddress("x",      &X);
   Tree->SetBranchAddress("exl",    &EXL);
   Tree->SetBranchAddress("exh",    &EXH);
   Tree->SetBranchAddress("y",      &Y);
   Tree->SetBranchAddress("eyl",    &EYL);
   Tree->SetBranchAddress("eyh",    &EYH);
   Tree->SetBranchAddress("syl",    &SYL);
   Tree->SetBranchAddress("syh",    &SYH);
   Tree->SetBranchAddress("energy", &E);

   int EntryCount = Tree->GetEntries();
   for(int iE = 0; iE < EntryCount; iE++)
   {
      Tree->GetEntry(iE);

      // Sloppy!  double-double comparison
      if(E != e)
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
   }

   File.Close();

   G.SetLineWidth(3);
   G.SetLineColor(color);
   G.SetMarkerStyle(20);
   G.SetMarkerSize(1.75);
   G.SetMarkerColor(color);
   G.SetFillColorAlpha(color, 0.25);

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
