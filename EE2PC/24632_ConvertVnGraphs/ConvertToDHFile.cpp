#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

#include "CommandLine.h"
#include "DataHelper.h"

int Sign(double Number);
int main(int argc, char *argv[]);

int Sign(double Number)
{
   return (0 < Number) - (0 > Number);
}

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   string InputFileName = CL.Get("Input");
   string DHFileName = CL.Get("DHFile");
   vector<string> MultiplicityMin = CL.GetStringVector("MultiplicityMin");
   vector<string> MultiplicityMax = CL.GetStringVector("MultiplicityMax");
   string PTMin = CL.Get("PTMin");
   string PTMax = CL.Get("PTMax");
   string Type = CL.Get("Type");
   string Axis = CL.Get("Axis");

   if(MultiplicityMax.size() < MultiplicityMin.size())
      MultiplicityMax.insert(MultiplicityMax.end(), MultiplicityMin.size() - MultiplicityMax.size(), "None");
   int N = MultiplicityMin.size();

   DataHelper DHFile(DHFileName);

   ifstream in(InputFileName);

   for(int i = 0; i < N; i++)
   {
      string State = InputFileName + "__" + to_string(i);

      DHFile[State]["FileName"] = InputFileName;
      DHFile[State]["Type"] = Type;
      DHFile[State]["Axis"] = Axis;
      DHFile[State]["MultiplicityMin"] = MultiplicityMin[i];
      DHFile[State]["MultiplicityMax"] = MultiplicityMax[i];
      DHFile[State]["PTMin"] = PTMin;
      DHFile[State]["PTMax"] = PTMax;

      double Temp[15] = {0};
      for(int j = 0; j < 15; j++)
      {
         in >> Temp[j];
         Temp[j] = Temp[j] / 100;
      }

      DHFile[State]["V1"]     = Temp[0];
      DHFile[State]["V1Stat"] = Temp[1];
      DHFile[State]["V1Sys1"] = Temp[2];
      DHFile[State]["V1Sys2"] = Temp[3];
      DHFile[State]["V1Sys3"] = Temp[4];
      DHFile[State]["V2"]     = Temp[5];
      DHFile[State]["V2Stat"] = Temp[6];
      DHFile[State]["V2Sys1"] = Temp[7];
      DHFile[State]["V2Sys2"] = Temp[8];
      DHFile[State]["V2Sys3"] = Temp[9];
      DHFile[State]["V3"]     = Temp[10];
      DHFile[State]["V3Stat"] = Temp[11];
      DHFile[State]["V3Sys1"] = Temp[12];
      DHFile[State]["V3Sys2"] = Temp[13];
      DHFile[State]["V3Sys3"] = Temp[14];
      
      DHFile[State]["v1"]     = Sign(Temp[0]) * sqrt(abs(Temp[0]));
      DHFile[State]["v1Stat"] = 0.5 * abs(Temp[1]) / sqrt(abs(Temp[0]));
      DHFile[State]["v1Sys1"] = Sign(Temp[2]) * sqrt(abs(Temp[2])) - DHFile[State]["v1"].GetDouble();
      DHFile[State]["v1Sys2"] = Sign(Temp[3]) * sqrt(abs(Temp[3])) - DHFile[State]["v1"].GetDouble();
      DHFile[State]["v1Sys3"] = Sign(Temp[4]) * sqrt(abs(Temp[4])) - DHFile[State]["v1"].GetDouble();
      DHFile[State]["v2"]     = Sign(Temp[5]) * sqrt(abs(Temp[5]));
      DHFile[State]["v2Stat"] = 0.5 * abs(Temp[6]) / sqrt(abs(Temp[5]));
      DHFile[State]["v2Sys1"] = Sign(Temp[7]) * sqrt(abs(Temp[7])) - DHFile[State]["v2"].GetDouble();
      DHFile[State]["v2Sys2"] = Sign(Temp[8]) * sqrt(abs(Temp[8])) - DHFile[State]["v2"].GetDouble();
      DHFile[State]["v2Sys3"] = Sign(Temp[9]) * sqrt(abs(Temp[9])) - DHFile[State]["v2"].GetDouble();
      DHFile[State]["v3"]     = Sign(Temp[10]) * sqrt(abs(Temp[10]));
      DHFile[State]["v3Stat"] = 0.5 * abs(Temp[11]) / sqrt(abs(Temp[10]));
      DHFile[State]["v3Sys1"] = Sign(Temp[12]) * sqrt(abs(Temp[12])) - DHFile[State]["v3"].GetDouble();
      DHFile[State]["v3Sys2"] = Sign(Temp[13]) * sqrt(abs(Temp[13])) - DHFile[State]["v3"].GetDouble();
      DHFile[State]["v3Sys3"] = Sign(Temp[14]) * sqrt(abs(Temp[14])) - DHFile[State]["v3"].GetDouble();
   
      double v1Sys = DHFile[State]["v1Sys1"].GetDouble() * DHFile[State]["v1Sys1"].GetDouble();
      v1Sys = v1Sys + DHFile[State]["v1Sys2"].GetDouble() * DHFile[State]["v1Sys2"].GetDouble();
      v1Sys = v1Sys + DHFile[State]["v1Sys3"].GetDouble() * DHFile[State]["v1Sys3"].GetDouble();
      DHFile[State]["v1Sys"] = sqrt(v1Sys);
      
      double v2Sys = DHFile[State]["v2Sys1"].GetDouble() * DHFile[State]["v2Sys1"].GetDouble();
      v2Sys = v2Sys + DHFile[State]["v2Sys2"].GetDouble() * DHFile[State]["v2Sys2"].GetDouble();
      v2Sys = v2Sys + DHFile[State]["v2Sys3"].GetDouble() * DHFile[State]["v2Sys3"].GetDouble();
      DHFile[State]["v2Sys"] = sqrt(v2Sys);
      
      double v3Sys = DHFile[State]["v3Sys1"].GetDouble() * DHFile[State]["v3Sys1"].GetDouble();
      v3Sys = v3Sys + DHFile[State]["v3Sys2"].GetDouble() * DHFile[State]["v3Sys2"].GetDouble();
      v3Sys = v3Sys + DHFile[State]["v3Sys3"].GetDouble() * DHFile[State]["v3Sys3"].GetDouble();
      DHFile[State]["v3Sys"] = sqrt(v3Sys);
   }
   
   in.close();

   DHFile.SaveToFile();

   return 0;
}



