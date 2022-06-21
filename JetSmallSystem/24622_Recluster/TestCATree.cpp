#include <iostream>
#include <vector>
using namespace std;

#include "CATree.h"

int main()
{
   vector<Node *> NodesEScheme, NodesWTAScheme;

   for(int i = 0; i < 25; i++)
   {
      FourVector P;

      P.SetPtEtaPhiMass(10 + i * 0.0001, (i / 5) * 0.01, (i % 5) * 0.01, 0);

      NodesEScheme.push_back(new Node(P));
      NodesWTAScheme.push_back(new Node(P));
   }

   BuildCATree(NodesEScheme, -1, EScheme);
   BuildCATree(NodesWTAScheme, -1, WTAScheme);

   cout << "EScheme: " << NodesEScheme[0]->P.GetEta() << " " << NodesEScheme[0]->P.GetPhi() << endl;
   cout << "WTAScheme: " << NodesWTAScheme[0]->P.GetEta() << " " << NodesWTAScheme[0]->P.GetPhi() << endl;

   delete NodesEScheme[0], NodesWTAScheme[0];

   return 0;
}





