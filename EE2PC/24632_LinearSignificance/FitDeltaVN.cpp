#include <iostream>
using namespace std;

#include "TFile.h"
#include "TGraphAsymmErrors.h"
#include "TF1.h"

#include "SetStyle.h"
#include "PlotHelper4.h"
#include "CommandLine.h"

int main(int argc, char *argv[])
{
   SetThesisStyle();

   CommandLine CL(argc, argv);

   string InputFileName = CL.Get("Input");
   string DataCurveBase = CL.Get("Data");
   string MCCurveBase = CL.Get("MC");

   TFile File(InputFileName.c_str());

   TGraphAsymmErrors *GDataStat = (TGraphAsymmErrors *)File.Get((DataCurveBase + "_Stat").c_str());
   TGraphAsymmErrors *GDataSys = (TGraphAsymmErrors *)File.Get((DataCurveBase + "_Sys").c_str());
   TGraphAsymmErrors *GMC = (TGraphAsymmErrors *)File.Get((MCCurveBase + "_Stat").c_str());

   TGraphAsymmErrors G;

   for(int i = 0; i < GDataStat->GetN(); i++)
   {
      double X = GDataStat->GetPointX(i);
      double XErrLow = GDataStat->GetErrorXlow(i);
      double XErrHigh = GDataStat->GetErrorXhigh(i);
      double Y = GDataStat->GetPointY(i);
      double YErrLow = GDataStat->GetErrorYlow(i);
      double YErrHigh = GDataStat->GetErrorYhigh(i);

      double YSysLow = -1;
      double YSysHigh = -1;
      for(int j = 0; j < GDataSys->GetN(); j++)
      {
         double XTest = GDataSys->GetPointX(j);
         if(XTest < X - XErrLow)    continue;
         if(XTest > X + XErrHigh)   continue;

         YSysLow = GDataSys->GetErrorYlow(j);
         YSysHigh = GDataSys->GetErrorYhigh(j);
      }
      if(YSysLow < 0 || YSysHigh < 0)
         continue;

      bool FoundMC = false;
      double YShift = 0;
      for(int j = 0; j < GMC->GetN(); j++)
      {
         double XTest = GMC->GetPointX(j);
         if(XTest < X - XErrLow)    continue;
         if(XTest > X + XErrHigh)   continue;

         FoundMC = true;
         YShift = GMC->GetPointY(j);
      }
      if(FoundMC == false)
         continue;

      if(YErrLow > 0.4 || YErrHigh > 0.4)
         continue;
      if(YSysLow > 0.4 || YSysHigh > 0.4)
         continue;

      int N = G.GetN();
      G.SetPoint(N, X, Y - YShift);
      G.SetPointError(N, XErrLow, XErrHigh,
         sqrt(YErrLow * YErrLow + YSysLow * YSysLow),
         sqrt(YErrHigh * YErrHigh + YSysHigh * YSysHigh));
   }

   PdfFileHelper PdfFile("Output.pdf");
   PdfFile.AddTextPage("Meow");

   PdfFile.AddPlot(G, "ap");
   G.Fit("pol1");
   PdfFile.AddPlot(G, "ap");

   PdfFile.AddTimeStampPage();
   PdfFile.Close();

   File.Close();

   return 0;
}




