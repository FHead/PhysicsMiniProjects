#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#include "TFile.h"
#include "TGraphAsymmErrors.h"

#include "CommandLine.h"
#include "DataHelper.h"

int main(int argc, char *argv[]);
double ToNumber(string Number);
void AddPoint(TGraphAsymmErrors &G, double x, double xmin, double xmax, double y, double yerr);

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   string DHFileName = CL.Get("DHFile");
   string OutputFileName = CL.Get("Output");

   DataHelper DHFile(DHFileName);

   TFile OutputFile(OutputFileName.c_str(), "RECREATE");

   vector<string> Keys = DHFile.GetListOfKeys();

   vector<string> Types;
   for(string Key : Keys)
      Types.push_back(DHFile[Key]["Type"].GetString());
   sort(Types.begin(), Types.end());
   Types.erase(unique(Types.begin(), Types.end()), Types.end());

   for(string Type : Types)
   {
      vector<string> Axes;
      for(string Key : Keys)
      {
         if(DHFile[Key]["Type"].GetString() == Type)
            Axes.push_back(DHFile[Key]["Axis"].GetString());
      }
      sort(Axes.begin(), Axes.end());
      Axes.erase(unique(Axes.begin(), Axes.end()), Axes.end());
   
      for(string Axis : Axes)
      {
         vector<pair<string, string>> PTRanges;
         vector<pair<string, string>> MultiplicityRanges;
         for(string Key : Keys)
         {
            if(DHFile[Key]["Type"].GetString() == Type
               && DHFile[Key]["Axis"].GetString() == Axis)
            {
               PTRanges.push_back(pair<string, string>(DHFile[Key]["PTMin"].GetString(),
                                                       DHFile[Key]["PTMax"].GetString()));
               MultiplicityRanges.push_back(pair<string, string>(DHFile[Key]["MultiplicityMin"].GetString(),
                                                                 DHFile[Key]["MultiplicityMax"].GetString()));
            }
         }
         sort(PTRanges.begin(), PTRanges.end());
         PTRanges.erase(unique(PTRanges.begin(), PTRanges.end()), PTRanges.end());
         sort(MultiplicityRanges.begin(), MultiplicityRanges.end());
         MultiplicityRanges.erase(unique(MultiplicityRanges.begin(), MultiplicityRanges.end()),
            MultiplicityRanges.end());

         // now do multiplicity plots
         for(pair<string, string> Range : MultiplicityRanges)
         {
            string NameBase = Type + "_" + Axis + "_Multiplicity_" + Range.first + "_" + Range.second;

            TGraphAsymmErrors Gv1Stat, Gv2Stat, Gv3Stat;
            TGraphAsymmErrors Gv1Sys, Gv2Sys, Gv3Sys;

            Gv1Stat.SetName((NameBase + "_v1_Stat").c_str());
            Gv2Stat.SetName((NameBase + "_v2_Stat").c_str());
            Gv3Stat.SetName((NameBase + "_v3_Stat").c_str());
            Gv1Sys.SetName((NameBase + "_v1_Sys").c_str());
            Gv2Sys.SetName((NameBase + "_v2_Sys").c_str());
            Gv3Sys.SetName((NameBase + "_v3_Sys").c_str());

            for(string Key : Keys)
            {
               if(Type != DHFile[Key]["Type"].GetString())
                  continue;
               if(Axis != DHFile[Key]["Axis"].GetString())
                  continue;
               if(Range.first != DHFile[Key]["MultiplicityMin"].GetString())
                  continue;
               if(Range.second != DHFile[Key]["MultiplicityMax"].GetString())
                  continue;

               double PTMin = ToNumber(DHFile[Key]["PTMin"].GetString());
               double PTMax = ToNumber(DHFile[Key]["PTMax"].GetString());

               double PT = (PTMin + PTMax) / 2;
               if(PTMax > 90)
                  PT = PTMin + 0.5;

               AddPoint(Gv1Stat, PT, PTMin, PTMax,
                  DHFile[Key]["v1"].GetDouble(), DHFile[Key]["v1Stat"].GetDouble());
               AddPoint(Gv2Stat, PT, PTMin, PTMax,
                  DHFile[Key]["v2"].GetDouble(), DHFile[Key]["v2Stat"].GetDouble());
               AddPoint(Gv3Stat, PT, PTMin, PTMax,
                  DHFile[Key]["v3"].GetDouble(), DHFile[Key]["v3Stat"].GetDouble());
               AddPoint(Gv1Sys, PT, PTMin, PTMax,
                  DHFile[Key]["v1"].GetDouble(), DHFile[Key]["v1Sys"].GetDouble());
               AddPoint(Gv2Sys, PT, PTMin, PTMax,
                  DHFile[Key]["v2"].GetDouble(), DHFile[Key]["v2Sys"].GetDouble());
               AddPoint(Gv3Sys, PT, PTMin, PTMax,
                  DHFile[Key]["v3"].GetDouble(), DHFile[Key]["v3Sys"].GetDouble());
            }

            Gv1Stat.Write();
            Gv2Stat.Write();
            Gv3Stat.Write();
            Gv1Sys.Write();
            Gv2Sys.Write();
            Gv3Sys.Write();
         }

         // ...and PT plots
         for(pair<string, string> Range : PTRanges)
         {
            string NameBase = Type + "_" + Axis + "_PT_" + Range.first + "_" + Range.second;

            TGraphAsymmErrors Gv1Stat, Gv2Stat, Gv3Stat;
            TGraphAsymmErrors Gv1Sys, Gv2Sys, Gv3Sys;

            Gv1Stat.SetName((NameBase + "_v1_Stat").c_str());
            Gv2Stat.SetName((NameBase + "_v2_Stat").c_str());
            Gv3Stat.SetName((NameBase + "_v3_Stat").c_str());
            Gv1Sys.SetName((NameBase + "_v1_Sys").c_str());
            Gv2Sys.SetName((NameBase + "_v2_Sys").c_str());
            Gv3Sys.SetName((NameBase + "_v3_Sys").c_str());

            for(string Key : Keys)
            {
               if(Type != DHFile[Key]["Type"].GetString())
                  continue;
               if(Axis != DHFile[Key]["Axis"].GetString())
                  continue;
               if(Range.first != DHFile[Key]["PTMin"].GetString())
                  continue;
               if(Range.second != DHFile[Key]["PTMax"].GetString())
                  continue;

               double MultiplicityMin = ToNumber(DHFile[Key]["MultiplicityMin"].GetString());
               double MultiplicityMax = ToNumber(DHFile[Key]["MultiplicityMax"].GetString());

               double Multiplicity = (MultiplicityMin + MultiplicityMax) / 2;
               if(MultiplicityMax > 90)
                  Multiplicity = MultiplicityMin + 5;

               AddPoint(Gv1Stat, Multiplicity, MultiplicityMin, MultiplicityMax,
                     DHFile[Key]["v1"].GetDouble(), DHFile[Key]["v1Stat"].GetDouble());
               AddPoint(Gv2Stat, Multiplicity, MultiplicityMin, MultiplicityMax,
                     DHFile[Key]["v2"].GetDouble(), DHFile[Key]["v2Stat"].GetDouble());
               AddPoint(Gv3Stat, Multiplicity, MultiplicityMin, MultiplicityMax,
                     DHFile[Key]["v3"].GetDouble(), DHFile[Key]["v3Stat"].GetDouble());
               AddPoint(Gv1Sys, Multiplicity, MultiplicityMin, MultiplicityMax,
                     DHFile[Key]["v1"].GetDouble(), DHFile[Key]["v1Sys"].GetDouble());
               AddPoint(Gv2Sys, Multiplicity, MultiplicityMin, MultiplicityMax,
                     DHFile[Key]["v2"].GetDouble(), DHFile[Key]["v2Sys"].GetDouble());
               AddPoint(Gv3Sys, Multiplicity, MultiplicityMin, MultiplicityMax,
                     DHFile[Key]["v3"].GetDouble(), DHFile[Key]["v3Sys"].GetDouble());
            }

            Gv1Stat.Write();
            Gv2Stat.Write();
            Gv3Stat.Write();
            Gv1Sys.Write();
            Gv2Sys.Write();
            Gv3Sys.Write();
         }
      }
   }

   OutputFile.Close();

   return 0;
}

double ToNumber(string Number)
{
   if(Number == "None")
      return 99;
   return stof(Number);
}

void AddPoint(TGraphAsymmErrors &G, double x, double xmin, double xmax, double y, double yerr)
{
   int N = G.GetN();

   G.SetPoint(N, x, y);
   G.SetPointError(N, x - xmin, xmax - x, yerr, yerr);
}


