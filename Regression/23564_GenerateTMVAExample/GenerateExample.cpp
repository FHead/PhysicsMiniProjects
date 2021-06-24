#include <iostream>
#include <vector>
using namespace std;

#include "TTree.h"
#include "TFile.h"

#include "CommandLine.h"
#include "Code/DrawRandom.h"

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   string OutputFileName = CL.Get("Output");
   vector<double> Mean = CL.GetDoubleVector("Mean", vector<double>{1, 2, 3});
   vector<double> RMS = CL.GetDoubleVector("RMS", vector<double>{1, 1, 1});
   int Statistics = CL.GetInt("N", 10000);

   int N = Mean.size();
   if(N > RMS.size())
      N = RMS.size();

   TFile OutputFile(OutputFileName.c_str(), "RECREATE");

   TTree OutputTree("Tree", "");

   double VTotal = 0;
   OutputTree.Branch("VTotal", &VTotal, "VTotal/D");

   vector<double> Branches(N);
   for(int i = 0; i < N; i++)
      OutputTree.Branch(Form("V%d", i + 1), &Branches[i], Form("V%d/D", i + 1));

   for(int i = 0; i < Statistics; i++)
   {
      VTotal = 0;
      for(int j = 0; j < N; j++)
      {
         Branches[j] = DrawGaussian(Mean[j], RMS[j]);
         VTotal = VTotal + Branches[j];
      }
      OutputTree.Fill();
   }

   OutputTree.Write();

   OutputFile.Close();

   return 0;
}


