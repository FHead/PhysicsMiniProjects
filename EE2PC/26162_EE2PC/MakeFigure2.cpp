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

#include "SetStyle.h"

#define BaseTextSize 0.06
#define AxisSpacing 505
#define TypeMC 0
#define TypeData 1
#define TypeMC2 2

int main(int argc, char *argv[]);
void SetPad(TPad &P);
void SetAxis(TGaxis &A);
void SetWorld(TH2D &H);
TGraphAsymmErrors Transcribe(int type, int nmin, int color);

int main(int argc, char *argv[])
{
   vector<int> PrimaryColors = GetPrimaryColors();
   // int Colors[3] = {PrimaryColors[0], PrimaryColors[1], PrimaryColors[5]};   // 5 = purple
   int Colors[3] = {PrimaryColors[0], PrimaryColors[1], PrimaryColors[2]};

   // Setup canvas
   double PanelW = 500, PanelH = 500;
   double MarginL = 150, MarginR = 25, MarginT = 50, MarginB = 75;
   double PanelSpacing = 75;

   double XMin = 0, XMax = M_PI;
   double YMin1 = 0.65, YMax1 = 1.31;
   double YMin2 = 3.1, YMax2 = 4.25;

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

   TGaxis YAxis1(MarginL, MarginB, MarginL, MarginB + PanelH, YMin1, YMax1, AxisSpacing, "S");
   SetAxis(YAxis1);
   
   TGaxis YAxis2(MarginL + PanelW + PanelSpacing, MarginB,
      MarginL + PanelW + PanelSpacing, MarginB + PanelH, YMin2, YMax2, AxisSpacing, "S");
   SetAxis(YAxis2);

   // Add texts
   TLatex Latex;

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(22);
   Latex.SetTextAngle(0);
   Latex.DrawLatex(MarginL + PanelW * 0.5, MarginB * 0.35, "#Delta#phi");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(22);
   Latex.SetTextAngle(0);
   Latex.DrawLatex(MarginL + PanelW + PanelSpacing + PanelW * 0.5, MarginB * 0.35, "#Delta#phi");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(22);
   Latex.SetTextAngle(90);
   Latex.DrawLatex(MarginL * 0.35, MarginB + PanelH * 0.5, "#frac{1}{N_{trk}^{corr}} #frac{dN^{pair}}{d#Delta#phi}");

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
   TGraphAsymmErrors GN0Data  = Transcribe(TypeData, 0, Colors[0]);
   TGraphAsymmErrors GN0MC    = Transcribe(TypeMC, 0, Colors[1]);
   TGraphAsymmErrors GN0MC2   = Transcribe(TypeMC2, 0, Colors[2]);
   TGraphAsymmErrors GN50Data = Transcribe(TypeData, 50, Colors[0]);
   TGraphAsymmErrors GN50MC   = Transcribe(TypeMC, 50, Colors[1]);
   TGraphAsymmErrors GN50MC2  = Transcribe(TypeMC2, 50, Colors[2]);

   // Draw left pad
   Pad1.cd();
   TH2D HWorld1("HWorld1", "", 100, XMin, XMax, 100, YMin1, YMax1);
   SetWorld(HWorld1);

   GN0MC.Draw("e2");
   GN0MC2.Draw("e2");
   GN0Data.Draw("p");

   // TLegend Legend1(0.675, 0.25, 1.175, 0.05);   // not sure what this is
   // TLegend Legend1(0.075, 0.4, 0.575, 0.6);   // This is original 2 entry sizing
   TLegend Legend1(0.075, 0.4, 0.575, 0.7);   // 3 entries
   Legend1.SetTextFont(42);
   Legend1.SetTextSize(BaseTextSize / PanelH);
   Legend1.SetFillStyle(0);
   Legend1.SetBorderSize(0);
   Legend1.AddEntry(&GN0Data, "Data", "lp");
   Legend1.AddEntry(&GN0MC, "Archived MC", "f");
   Legend1.AddEntry(&GN0MC2, "PYTHIA 8", "f");
   Legend1.Draw();

   HWorld1.Draw("axis same");
   
   // Draw right pad
   Pad2.cd();
   TH2D HWorld2("HWorld2", "", 100, XMin, XMax, 100, YMin2, YMax2);
   SetWorld(HWorld2);

   GN50MC.Draw("e2");
   GN50MC2.Draw("e2");
   GN50Data.Draw("p");

   HWorld2.Draw("axis same");

   // Draw labels on top of pads
   Canvas.cd();

   double OffsetX = 0.025;
   double OffsetY = OffsetX * CanvasW / CanvasH;

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(13);
   Latex.SetTextAngle(0);
   Latex.DrawLatex(MarginL + OffsetX, MarginB + PanelH - OffsetY, "1.6 #leq |#Delta#eta| < 3.2");
   Latex.DrawLatex(MarginL + OffsetX, MarginB + PanelH - OffsetY - BaseTextSize * 1.10, "Inclusive");
   
   Latex.SetTextAlign(31);
   Latex.DrawLatex(MarginL + PanelW - OffsetX, MarginB + OffsetY, "(sys. = 0.8%)");
   Latex.DrawLatex(MarginL + PanelW * 2 + PanelSpacing - OffsetX, MarginB + OffsetY, "(sys. = 1.7%)");

   Latex.SetTextFont(42);
   Latex.SetTextSize(BaseTextSize);
   Latex.SetTextAlign(13);
   Latex.SetTextAngle(0);
   Latex.DrawLatex(MarginL + PanelW + PanelSpacing + OffsetX, MarginB + PanelH - OffsetY, "N_{track} #geq 50");

   Canvas.SaveAs("Figure2.C");
   Canvas.SaveAs("Figure2Raw.pdf");

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

TGraphAsymmErrors Transcribe(int type, int nmin, int color)
{
   TGraphAsymmErrors G;

   TFile File("Fig2.root");
   TTree *Tree = (TTree *)File.Get("Tree");

   // branches x:y:exl:exh:eyl:eyh:nmin:data

   double X, EXL, EXH, Y, EYL, EYH, NMin, Type;
   Tree->SetBranchAddress("x",    &X);
   Tree->SetBranchAddress("exl",  &EXL);
   Tree->SetBranchAddress("exh",  &EXH);
   Tree->SetBranchAddress("y",    &Y);
   Tree->SetBranchAddress("eyl",  &EYL);
   Tree->SetBranchAddress("eyh",  &EYH);
   Tree->SetBranchAddress("nmin", &NMin);
   Tree->SetBranchAddress("data", &Type);

   int EntryCount = Tree->GetEntries();
   for(int iE = 0; iE < EntryCount; iE++)
   {
      Tree->GetEntry(iE);

      // Sloppy!  double-int comparison
      if(Type != type)
         continue;
      if(NMin != nmin)
         continue;

      if(type == TypeMC2 && nmin == 0)
      {
         EYL = max(EYL, 0.0025);
         EYH = max(EYH, 0.0025);
      }
      
      int N = G.GetN();
      G.SetPoint(N, X, Y);
      G.SetPointError(N, EXL, EXH, EYL, EYH);

      // if(type == TypeMC2 && nmin == 0)
      // {
      //    G.SetPoint(N, X, Y * 1.18);
      //    G.SetPointError(N, EXL, EXH, EYL * 1.18, EYH * 1.18);
      // }
   }

   File.Close();

   G.SetLineWidth(2);
   
   if(type != TypeMC)
      G.SetLineColor(color);
   else
      G.SetLineColorAlpha(color, 0.5);
   
   if(type == TypeData)
      G.SetMarkerStyle(20);
   else
      G.SetMarkerStyle(5);
   G.SetMarkerSize(1.75);
   G.SetMarkerColor(color);

   if(type != TypeMC)
      G.SetFillColorAlpha(color, 1.0);
   else
      G.SetFillColorAlpha(color, 0.75);

   return G;
}

