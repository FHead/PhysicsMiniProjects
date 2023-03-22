#include <iostream>
using namespace std;

#include "TH2D.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLatex.h"

#include "CommandLine.h"

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   string DataFileName = CL.Get("Data");
   string MCFileName = CL.Get("MC");

   string DataHistogram = CL.Get("DataHistogram");
   string MCHistogram = CL.Get("MCHistogram");
   
   string OutputFileName = CL.Get("Output");
   
   string TrackSelection = CL.Get("Track", "");
   string AxisType = CL.Get("Axis", "");

   TFile FData(DataFileName.c_str());
   TFile FMC(MCFileName.c_str());

   TCanvas Canvas("Canvas", "Canvas", 800, 800);

   Canvas.SetLeftMargin(0.2);
	Canvas.SetTheta(60.839);
	Canvas.SetPhi(38.0172);

   TH2D *HData = (TH2D *)FData.Get(DataHistogram.c_str());
   TH2D *HMC = (TH2D *)FMC.Get(MCHistogram.c_str());

   HData->Add(HMC, -1);

   HData->SetTitleOffset(1.5,"X");
   HData->SetTitleOffset(1.5,"Y");
   HData->SetTitleOffset(2.0,"Z");
   HData->GetXaxis()->CenterTitle();
   HData->GetYaxis()->CenterTitle();
   HData->GetZaxis()->CenterTitle();
   HData->SetNdivisions(505,"X");
   HData->SetNdivisions(505,"Y");
   HData->SetNdivisions(505,"Z");
   HData->GetXaxis()->SetTitle("#Delta#eta");
   HData->GetYaxis()->SetTitle("#Delta#phi");
   HData->GetZaxis()->SetTitle("#frac{1}{N_{trk}^{corr}} #frac{d^{2}N^{pair}}{d#Delta#etad#Delta#phi} (Data - MC)");
   HData->SetStats(0);

   HData->Draw("surf1 fb");

   TLatex Latex;
   Latex.SetTextFont(42);
   Latex.SetNDC();
   Latex.SetTextSize(0.045);
   Latex.DrawLatex(0.1, 0.92, "ALEPH e^{+}e^{-}, #sqrt{s} = 183-209 GeV");
   Latex.DrawLatex(0.1, 0.85, TrackSelection.c_str());
   Latex.DrawLatex(0.1, 0.78, AxisType.c_str());

   Canvas.SaveAs(OutputFileName.c_str());

   FMC.Close();
   FData.Close();

   return 0;
}



