#include <iostream>
#include <vector>
using namespace std;

#include "CATree.h"

int main()
{
   // Declare the node object vectors
   vector<Node *> NodesEScheme, NodesWTAScheme;

   // Loop over jet constituents.  Here we use a toy with 25 particles
   for(int i = 0; i < 25; i++)
   {
      // Set particle kinematics
      FourVector P;
      P.SetPtEtaPhiMass(10 + i * 0.0001, (i / 5) * 0.01, (i % 5) * 0.01, 0);

      // Add into the node object vector
      NodesEScheme.push_back(new Node(P));
      NodesWTAScheme.push_back(new Node(P));
   }

   // Do the reclustering!
   BuildCATree(NodesEScheme, -1, EScheme);
   BuildCATree(NodesWTAScheme, -1, WTAScheme);

   // Some output
   cout << "EScheme: " << NodesEScheme[0]->P.GetEta() << " " << NodesEScheme[0]->P.GetPhi() << endl;
   cout << "WTAScheme: " << NodesWTAScheme[0]->P.GetEta() << " " << NodesWTAScheme[0]->P.GetPhi() << endl;

   // Clean up is important.  We only need to delete the root node and everything will be cleaned
   delete NodesEScheme[0], NodesWTAScheme[0];

   return 0;
}





