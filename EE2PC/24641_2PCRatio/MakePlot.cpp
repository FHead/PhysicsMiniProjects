#include <vector>
#include <iostream>
using namespace std;

#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"

#include "CommandLine.h"
#include "SetStyle.h"
#include "PlotHelper4.h"
#include "CustomAssert.h"

int main(int argc, char *argv[])
{
   SetThesisStyle();
   vector<int> Colors = GetPrimaryColors();

   CommandLine CL(argc, argv);

   string DataFileName      = CL.Get("Data");
   string MCFileName        = CL.Get("MC");
   string DataHistogramName = CL.Get("DataHistogram");
   string MCHistogramName   = CL.Get("MCHistogram");
   string OutputFileName    = CL.Get("Output");
   vector<string> Selection = CL.GetStringVector("Selection");

   TFile DataFile(DataFileName.c_str());
   TFile MCFile(MCFileName.c_str());

   TH1D *HData = (TH1D *)DataFile.Get(DataHistogramName.c_str());
   TH1D *HMC   = (TH1D *)MCFile.Get(MCHistogramName.c_str());

   Assert(HData != nullptr, "Data histogram not found");
   Assert(HMC   != nullptr, "MC histogram not found");

   TH1D *HDiff = (TH1D *)HData->Clone("HDiff");
   HDiff->Add(HMC, -1);

   PdfFileHelper PdfFile(OutputFileName);
   PdfFile.SetPageNumber(false);
   PdfFile.AddTextPage(Selection);

   double YMin = min(HData->GetMinimum(), HMC->GetMinimum());
   double YMax = max(HData->GetMaximum(), HMC->GetMaximum());

   double Delta = YMax - YMin;
   YMin = YMin - Delta * 0.3;
   YMax = YMax + Delta * 0.3;

   TLatex Latex;
   Latex.SetTextFont(42);
   Latex.SetTextSize(0.035);
   Latex.SetNDC();

   TH2D HWorld("HWorld", ";#Delta#phi;Y(#Delta#phi)", 100, 0, M_PI, 100, YMin, YMax);
   HWorld.SetStats(0);

   TLegend Legend(0.55, 0.15, 0.85, 0.3);
   Legend.SetFillStyle(0);
   Legend.SetBorderSize(0);
   Legend.SetTextFont(42);
   Legend.SetTextSize(0.035);
   Legend.AddEntry(HData, "Data", "pl");
   Legend.AddEntry(HMC, "Simulation", "pl");

   TCanvas Canvas;

   HWorld.Draw("axis");
   HMC->Draw("same hist");
   HData->Draw("same");

   HData->SetMarkerStyle(20);
   HMC->SetMarkerStyle(21);
   HDiff->SetMarkerStyle(22);
   HData->SetMarkerColor(Colors[0]);
   HMC->SetMarkerColor(Colors[1]);
   HDiff->SetMarkerColor(Colors[5]);
   HData->SetMarkerSize(2.00);
   HMC->SetMarkerSize(1.75);
   HDiff->SetMarkerSize(1.75);

   HData->SetLineColor(Colors[0]);
   HMC->SetLineColor(Colors[1]);
   HDiff->SetLineColor(Colors[5]);
   HData->SetLineWidth(4);
   HMC->SetLineWidth(4);
   HDiff->SetLineWidth(4);

   Legend.Draw();

   Latex.DrawLatex(0.10, 0.92, "ALEPH Archived Data e^{+}e^{-}, #sqrt{s} = 183-209 GeV");
   for(int i = 0; i < (int)Selection.size(); i++)
      Latex.DrawLatex(0.15, 0.82 - 0.05 * i, Selection[i].c_str());
   
   PdfFile.AddCanvas(Canvas);

   YMax = HDiff->GetMaximum();
   YMin = HDiff->GetMinimum();

   Delta = YMax - YMin;
   YMax = YMax + Delta * 0.6;
   YMin = YMin - Delta * 0.6;

   TH2D HWorldDiff("HWorldDiff", ";#Delta#phi;#DeltaY(#Delta#phi)", 100, 0, M_PI, 100, YMin, YMax);
   HWorldDiff.SetStats(0);

   HWorldDiff.Draw("axis");
   HDiff->Draw("same");

   Latex.DrawLatex(0.10, 0.92, "ALEPH Archived Data e^{+}e^{-}, #sqrt{s} = 183-209 GeV");
   for(int i = 0; i < (int)Selection.size(); i++)
      Latex.DrawLatex(0.15, 0.82 - 0.05 * i, Selection[i].c_str());
   
   PdfFile.AddCanvas(Canvas);

   PdfFile.AddTimeStampPage();
   PdfFile.Close();

   MCFile.Close();
   DataFile.Close();

   return 0;
}




