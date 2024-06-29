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
#define XAxisSpacing 510
#define YAxisSpacing 508

int main(int argc, char *argv[]);
void SetPad(TPad &P);
void SetAxis(TGaxis &A);
void SetWorld(TH2D &H);
TGraphAsymmErrors Transcribe(int type, int data, int color, double alpha);
void DrawArrows(TGraphAsymmErrors &G, double ArrowLength, double YMin);

int main(int argc, char *argv[])
{
   vector<int> PrimaryColors = GetPrimaryColors();
   vector<int> CVDColors = GetCVDColors6();
   // The order is BELLE, LEP1, ALICE, LEP2
   // int Colors[4] = {PrimaryColors[1], PrimaryColors[4], PrimaryColors[2], PrimaryColors[0]};
   // int Colors[4] = {CVDColors[5], CVDColors[1], CVDColors[4], PrimaryColors[0]};
   int Colors[4] = {CVDColors[5], CVDColors[1], CVDColors[4], kRed - 4};
   double Alphas[4] = {0.4, 0.5, 0.6, 1.0};

   // Setup canvas
   double PanelW = 500, PanelH = 500;
   double MarginL = 100, MarginR = 25, MarginT = 25, MarginB = 75;

   double XMin = 0, XMax = 70;
   double YMin = 3e-8, YMax = 100;

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
   TGaxis XAxis(MarginL, MarginB, MarginL + PanelW, MarginB, XMin, XMax, XAxisSpacing, "S");
   SetAxis(XAxis);
   
   TGaxis YAxis(MarginL, MarginB, MarginL, MarginB + PanelH, YMin, YMax, YAxisSpacing, "SG");
   SetAxis(YAxis);

   // Add texts
   TLatex Latex;

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(22);
   Latex.SetTextAngle(0);
   Latex.DrawLatex(MarginL + PanelW * 0.5, MarginB * 0.35, "#LT N_{trk}^{corr} #GT");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(22);
   Latex.SetTextAngle(90);
   Latex.DrawLatex(MarginL * 0.25, MarginB + PanelH * 0.5, "Associated yield");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(11);
   Latex.SetTextAngle(0);
   // Latex.DrawLatex(MarginL, MarginB + PanelH + 0.01, "Archived ALEPH data, Thrust Axis");
   // Latex.DrawLatex(MarginL, MarginB + PanelH + 0.01, "#bf{#it{ALEPH e^{+}e^{-}, #sqrt{s} = 183-209 GeV}}");

   // Setup lines and curves
   TGraphAsymmErrors GBELLELimit = Transcribe(0, 0, Colors[0], Alphas[0]);
   TGraphAsymmErrors GLEP1Limit  = Transcribe(0, 1, Colors[1], Alphas[1]);
   TGraphAsymmErrors GALICELimit = Transcribe(0, 4, Colors[2], Alphas[2]);   // #2 is prelim
   TGraphAsymmErrors GLEP2Limit  = Transcribe(0, 3, Colors[3], Alphas[3]);
   TGraphAsymmErrors GBELLEPoint = Transcribe(1, 0, Colors[0], Alphas[0]);
   TGraphAsymmErrors GLEP1Point  = Transcribe(1, 1, Colors[1], Alphas[1]);
   TGraphAsymmErrors GALICEPoint = Transcribe(1, 4, Colors[2], Alphas[2]);
   TGraphAsymmErrors GLEP2Point  = Transcribe(1, 3, Colors[3], Alphas[3]);

   // GLEP2Limit.SetLineWidth(4);
   // GLEP2Point.SetLineWidth(4);

   // Setup arrows
   // TArrow ArrowALEPH = MakeArrow(GALEPHStat,  XMax);

   // Draw things!
   Pad.cd();
   Pad.SetLogy();
   TH2D HWorld("HWorld", "", 100, XMin, XMax, 100, YMin, YMax);
   SetWorld(HWorld);

   // GBELLELimit.Draw("p");
   DrawArrows(GBELLELimit, 0.10, YMin);
   // GLEP1Limit.Draw("p");
   DrawArrows(GLEP1Limit,  0.10, YMin);
   GALICEPoint.Draw("p");
   // GALICELimit.Draw("p");
   DrawArrows(GALICELimit, 0.10, YMin);
   GLEP2Point.Draw("p");
   // GLEP2Limit.Draw("p");
   DrawArrows(GLEP2Limit,  0.10, YMin);
 
   // TLegend Legend(0.3, 0.275, 0.6, 0.02);
   TLegend Legend1(0.03, 0.97, 0.33, 0.63);
   Legend1.SetTextFont(42);
   Legend1.SetTextSize(BaseTextSize / PanelH);
   Legend1.SetFillStyle(0);
   Legend1.SetBorderSize(0);
   Legend1.AddEntry(&GBELLEPoint, "BELLE, e^{+}e^{-} 10.52 GeV", "f");
   Legend1.AddEntry(&GLEP1Point, "ALEPH, e^{+}e^{-} 91.2 GeV", "f");
   Legend1.AddEntry(&GALICEPoint, "ALICE, pp 13 TeV", "f");
   Legend1.AddEntry(&GLEP2Point, "ALEPH, e^{+}e^{-} 183-209 GeV", "f");
   Legend1.Draw();
  
   TGraph G;
   G.SetLineWidth(3);
   G.SetMarkerStyle(20);
   G.SetMarkerSize(2);

   // 0.52 / 0.04 if we want it snug in the corner
   double LegendL = 0.495;
   double LegendR = LegendL + 0.37;
   double LegendB = 0.07;
   double LegendT = LegendB + 0.225;

   TLegend Legend2(LegendL, LegendB, LegendR, LegendT);
   Legend2.SetTextFont(42);
   Legend2.SetTextSize(BaseTextSize / PanelH);
   Legend2.SetFillStyle(0);
   Legend2.SetBorderSize(0);
   Legend2.AddEntry(&G, "Central value", "lp");
   Legend2.AddEntry("", "Limit (95% C.L.", "");
   Legend2.AddEntry("", "unless noted)", "");
   Legend2.Draw();

   double ArrowY = exp(log(YMin) + (log(YMax) - log(YMin)) / 1 * (LegendB * 0.5 + LegendT * 0.5));
   double ArrowXL = (LegendL + (LegendR - LegendL) * 0.06) * XMax + XMin;
   double ArrowXR = (LegendL + (LegendR - LegendL) * 0.20) * XMax + XMin;

   TArrow Arrow;
   Arrow.SetLineWidth(3);
   Arrow.SetLineColor(kBlack);
   Arrow.DrawArrow(ArrowXL, ArrowY, ArrowXR, ArrowY, 0.015, ">");
   Arrow.DrawArrow(ArrowXL, ArrowY, ArrowXL + 0.001, ArrowY, 0.01, "|>");

   double Offset = 1.4;

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize / PanelH * 0.7);
   Latex.SetTextAlign(21);
   Latex.SetTextAngle(0);

   Latex.SetTextColorAlpha(Colors[0], Alphas[0]);
   Latex.DrawLatex(7.0487, 1e-7 * Offset, ">5#sigma");
   Latex.SetTextColorAlpha(Colors[1], Alphas[1]);
   Latex.DrawLatex(12.8, 1e-5 * Offset * 0.2, "96%");
   Latex.SetTextColorAlpha(Colors[3], Alphas[3]);
   Latex.DrawLatex(15.6814, 1e-7 * Offset, ">99%");
   Latex.DrawLatex(23.5278, 1e-7 * Offset, "98.4%");
   Latex.DrawLatex(33.2015, 1e-7 * Offset, ">99%");
   
   HWorld.Draw("axis same");
   
   // Draw labels on top of pads
   Canvas.cd();

   /*
   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(11);
   Latex.SetTextAngle(0);
   Latex.SetTextColor(kBlack);
   Latex.DrawLatex(MarginL + PanelW * 0.65, MarginB + PanelH * 0.2 + BaseTextSize, "Central value");
   Latex.DrawLatex(MarginL + PanelW * 0.65, MarginB + PanelH * 0.2, "C.L. (95%");
   Latex.DrawLatex(MarginL + PanelW * 0.65, MarginB + PanelH * 0.2 - BaseTextSize * 1.05, "unless noted)");
   */

   Canvas.SaveAs("Figure3.C");
   Canvas.SaveAs("Figure3Raw.pdf");

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
   // A.SetMoreLogLabels();
   // A.SetNoExponent();
   A.SetTickSize(0);
   A.SetTickLength(0);
   A.Draw();
}

void SetWorld(TH2D &H)
{
   H.SetStats(0);
   H.GetXaxis()->SetNdivisions(XAxisSpacing);
   H.GetYaxis()->SetNdivisions(YAxisSpacing);
   H.Draw("axis");
}

TGraphAsymmErrors Transcribe(int type, int data, int color, double alpha)
{
   TGraphAsymmErrors G;

   TFile File("Fig3.root");
   TTree *Tree = (TTree *)File.Get("Tree");

   double X, Y, EX, EY, Type, Data;
   Tree->SetBranchAddress("x",      &X);
   Tree->SetBranchAddress("y",      &Y);
   Tree->SetBranchAddress("ex",     &EX);
   Tree->SetBranchAddress("ey",     &EY);
   Tree->SetBranchAddress("type",   &Type);
   Tree->SetBranchAddress("data",   &Data);

   int EntryCount = Tree->GetEntries();
   for(int iE = 0; iE < EntryCount; iE++)
   {
      Tree->GetEntry(iE);

      // Sloppy!  double-int comparison
      if(type != Type)   continue;
      if(data != Data)   continue;

      int N = G.GetN();
      G.SetPoint(N, X, Y);
      if(type == 0)
         G.SetPointError(N, EX, EX, Y * 0.01, Y * 0.01);
      if(type == 1)
         G.SetPointError(N, EX, EX, EY, EY);
   }

   File.Close();

   G.SetLineWidth(3);
   G.SetLineColorAlpha(color, alpha);
   if(type == 0)
   {
      G.SetMarkerStyle(23);
      G.SetMarkerSize(1);
   }
   else
   {
      G.SetMarkerStyle(20);
      G.SetMarkerSize(1.75);
   }

   G.SetMarkerColorAlpha(color, alpha);
   G.SetFillColorAlpha(color, alpha);

   return G;
}

void DrawArrows(TGraphAsymmErrors &G, double ArrowLength, double YMin)
{
   TArrow Arrow;
   Arrow.SetLineWidth(G.GetLineWidth());
   Arrow.SetLineColor(G.GetLineColor());
   Arrow.SetFillColor(G.GetLineColor());

   for(int i = 0; i < G.GetN(); i++)
   {
      double X = G.GetPointX(i);
      double Y = G.GetPointY(i);
      
      double YLow = Y * ArrowLength;
      if(YLow < YMin)
         YLow = YMin;

      Arrow.DrawArrow(X, Y, X, Y * 0.95, 0.01, "|>");
      Arrow.DrawArrow(X, Y, X, YLow, 0.015, ">");
   }
}


