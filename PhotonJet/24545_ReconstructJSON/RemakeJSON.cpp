#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

#include "TFile.h"
#include "TTree.h"

#include "CommandLine.h"

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   vector<string> InputFileNames = CL.GetStringVector("Input");
   string OutputFileName = CL.Get("Output");

   map<int, vector<int>> FullList;

   for(string InputFileName : InputFileNames)
   {
      TFile File(InputFileName.c_str());

      TTree *Tree = (TTree *)File.Get("hiEvtAnalyzer/HiTree");

      if(Tree == nullptr)
      {
         File.Close();
         continue;
      }

      cout << "Processing file " << InputFileName << endl;

      unsigned int Run, Lumi;
      Tree->SetBranchAddress("run", &Run);
      Tree->SetBranchAddress("lumi", &Lumi);

      int EntryCount = Tree->GetEntries();
      for(int iE = 0; iE < EntryCount; iE++)
      {
         Tree->GetEntry(iE);

         FullList[Run].push_back(Lumi);
      }

      File.Close();

      for(auto &P : FullList)
      {
         vector<int> &V = P.second;
         if(V.size() > 2000)
            V.erase(unique(V.begin(), V.end()), V.end());
      }
   }

   ofstream out(OutputFileName);

   out << "{";

   bool FirstRun = true;
   for(auto &P : FullList)
   {
      if(FirstRun == true)   FirstRun = false;
      else                   out << ",";
      out << "\"" << P.first << "\": [";

      bool FirstLumi = true;
      for(int L : P.second)
      {
         if(FirstLumi == true)   FirstLumi = false;
         else                    out << ",";
         out << "[" << L << "," << L << "]";
      }
      out << "]";
   }

   out << "}" << endl;

   out.close();

   return 0;
}





