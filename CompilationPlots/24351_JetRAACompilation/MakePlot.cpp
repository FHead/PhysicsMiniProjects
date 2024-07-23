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

#define ERROR_STAT 0
#define ERROR_SYS 1
#define ERROR_BOTH 2

int main(int argc, char *argv[]);
TGraphAsymmErrors GetGraph(DataHelper &DHFile, string State, int Error);
vector<double> ParseDoubleList(string input);
void SetGraph(TGraphAsymmErrors &G, int Color);

int main(int argc, char *argv[])
{
   vector<int> Colors = GetPrimaryColors();
   SetThesisStyleWide();

   DataHelper DHFile("Data.dh");

   TGraphAsymmErrors GCMS2020 = GetGraph(DHFile, "CMSJetRAA2020-2-0", ERROR_BOTH);
   TGraphAsymmErrors GCMS2016 = GetGraph(DHFile, "CMSJetRAA2016-8a-3", ERROR_BOTH);
   TGraphAsymmErrors GALICE2020 = GetGraph(DHFile, "ALICEJetRAA2020-33-1", ERROR_BOTH);
   TGraphAsymmErrors GATLAS2018 = GetGraph(DHFile, "ATLASJetRAA2018-19-1", ERROR_BOTH);

   SetGraph(GCMS2020, Colors[0]);
   SetGraph(GCMS2016, Colors[1]);
   SetGraph(GALICE2020, Colors[3]);
   SetGraph(GATLAS2018, Colors[4]);

   TH2D HWorld("HWorld", ";Jet p_{T} (GeV);R_{AA}", 100, 50, 1200, 100, 0, 1.05);
   HWorld.SetStats(0);
   HWorld.GetXaxis()->SetMoreLogLabels();
   HWorld.GetXaxis()->SetNoExponent();

   TCanvas Canvas;

   HWorld.Draw("axis");

   TGraph G;
   G.SetPoint(0, 0, 1);
   G.SetPoint(1, 10000, 1);
   G.Draw("l");

   GCMS2020.Draw("p");
   GCMS2016.Draw("p");
   GALICE2020.Draw("p");
   GATLAS2018.Draw("p");

   TLegend Legend(0.55, 0.15, 0.75, 0.40);
   Legend.SetTextFont(42);
   Legend.SetTextSize(0.035);
   Legend.SetBorderSize(0);
   Legend.SetFillStyle(0);
   Legend.AddEntry(&GCMS2020, "CMS 5.02 TeV 0-10%", "lp");
   Legend.AddEntry(&GCMS2016, "CMS 2.76 TeV 0-5%", "lp");
   Legend.AddEntry(&GATLAS2018, "ATLAS 5.02 TeV 0-10%", "lp");
   Legend.AddEntry(&GALICE2020, "ALICE 5.02 TeV 0-10%", "lp");
   Legend.Draw();

   TLatex Latex;
   Latex.SetTextFont(42);
   Latex.SetTextSize(0.035);
   Latex.SetTextAlign(12);
   Latex.SetNDC();
   Latex.DrawLatex(0.1, 0.8, "Inclusive anti-k_{T} jet R = 0.4");
   Latex.DrawLatex(0.1, 0.75, "PbPb collisions");

   Canvas.SetLogx();
   Canvas.SaveAs("MeowJetRAA.pdf");

   return 0;
}

TGraphAsymmErrors GetGraph(DataHelper &DHFile, string State, int Error)
{
   vector<double> X = ParseDoubleList(DHFile[State]["X"].GetString());
   vector<double> Y = ParseDoubleList(DHFile[State]["Y"].GetString());
   vector<double> EXL = ParseDoubleList(DHFile[State]["EXLow"].GetString());
   vector<double> EXH = ParseDoubleList(DHFile[State]["EXHigh"].GetString());
   vector<double> EYLStat = ParseDoubleList(DHFile[State]["EYStatLow"].GetString());
   vector<double> EYHStat = ParseDoubleList(DHFile[State]["EYStatHigh"].GetString());
   vector<double> EYLSys = ParseDoubleList(DHFile[State]["EYSysLow"].GetString());
   vector<double> EYHSys = ParseDoubleList(DHFile[State]["EYSysHigh"].GetString());
   double Global = stof(DHFile[State]["GlobalUncertainty"].GetString());

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

      EYL = sqrt(EYL);
      EYH = sqrt(EYH);

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

void SetGraph(TGraphAsymmErrors &G, int Color)
{
   G.SetMarkerSize(2);
   G.SetMarkerStyle(20);
   G.SetLineWidth(2);
   G.SetMarkerColor(Color);
   G.SetLineColor(Color);
}


