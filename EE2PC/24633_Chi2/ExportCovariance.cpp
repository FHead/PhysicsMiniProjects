#include <iostream>
#include <fstream>
using namespace std;

#include "TFile.h"
#include "TGraphAsymmErrors.h"
#include "TF1.h"

#include "SetStyle.h"
#include "PlotHelper4.h"
#include "CommandLine.h"

int main(int argc, char *argv[]);
void ExportDelta(string FileName, TGraphAsymmErrors &G);
void ExportMatrix(string FileName, TGraphAsymmErrors &G, bool Correlated);

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

   TGraphAsymmErrors GStat, GSys;

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

      int N = GStat.GetN();
      GStat.SetPoint(N, X, Y - YShift);
      GStat.SetPointError(N, XErrLow, XErrHigh, YErrLow, YErrHigh);
      GSys.SetPoint(N, X, Y - YShift);
      GSys.SetPointError(N, XErrLow, XErrHigh, YSysLow, YSysHigh);
   }

   ExportDelta("Diff.dat", GStat);
   ExportMatrix("StatMatrix.dat", GStat, false);
   ExportMatrix("SysMatrixUncorrelated.dat", GSys, false);
   ExportMatrix("SysMatrixCorrelated.dat", GSys, true);

   return 0;
}

void ExportDelta(string FileName, TGraphAsymmErrors &G)
{
   ofstream out(FileName);

   int N = G.GetN();
   for(int i = 0; i < N; i++)
      out << G.GetPointY(i) << endl;

   out.close();
}

void ExportMatrix(string FileName, TGraphAsymmErrors &G, bool Correlated)
{
   ofstream out(FileName);

   int N = G.GetN();
   for(int i = 0; i < N; i++)
   {
      for(int j = 0; j < N; j++)
      {
         double Error1 = G.GetErrorYhigh(i);
         double Error2 = G.GetErrorYhigh(j);
         double Correlation = 1;

         if(Correlated == true)
            Correlation = 1;
         else
         {
            if(i == j)
               Correlation = 1;
            else
               Correlation = 0;
         }

         out << " " << Error1 * Error2 * Correlation;
      }
      out << endl;
   }

   out.close();
}



