// CATree.h, Jun 21 2022
// Original author: Yi Chen
// This code does jet reclustering!  It's a watered-down version of the full CATree.h Yi is using for her analysis
// Can easily add soft drop in here if needed.

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>

#include "TauHelperFunctions3.h"

#define EScheme 0
#define WTAScheme 1

class Node;
void BuildCATree(std::vector<Node *> &Nodes, double p = 0, int Scheme = EScheme);

class Node
{
public:
   FourVector P;
   Node *Child1;
   Node *Child2;
   Node *Parent;
   int N;   // multiplicity: how many nodes (including self) under this node
public:
   Node();
   Node(FourVector &p);
   Node(Node *n1, Node *n2);
   ~Node();
};

Node::Node()
   : P(0, 0, 0, 0), Child1(NULL), Child2(NULL), Parent(NULL), N(1)
{
}
   
Node::Node(FourVector &p)
   : P(p), Child1(NULL), Child2(NULL), Parent(NULL), N(1)
{
}

Node::Node(Node *n1, Node *n2)
   : P(0, 0, 0, 0), Child1(NULL), Child2(NULL), Parent(NULL), N(1)
{
   if(n1 == NULL || n2 == NULL)
      return;

   P = n1->P + n2->P;
   Child1 = n1;
   Child2 = n2;
   Child1->Parent = this;
   Child2->Parent = this;
   N = n1->N + n2->N + 1;

   if(Child1->P.GetP() < Child2->P.GetP())
      std::swap(Child1, Child2);
}

Node::~Node()
{
   if(Child1 != NULL)   delete Child1;
   if(Child2 != NULL)   delete Child2;

   Child1 = NULL;
   Child2 = NULL;
}

void BuildCATree(std::vector<Node *> &Nodes, double p, int Scheme)
{
   while(Nodes.size() > 1)
   {
      int IndexL = 0, IndexR = 1;
      double BestDistance = -1;

      for(int i = 0; i < (int)Nodes.size() - 1; i++)
      {
         for(int j = i + 1; j < (int)Nodes.size(); j++)
         {
            double Distance = GetDR(Nodes[i]->P, Nodes[j]->P);
            Distance = Distance * Distance;
            if(p != 0)
               Distance = Distance * std::min(std::pow(Nodes[i]->P.GetPT(), 2 * p),
                                              std::pow(Nodes[j]->P.GetPT(), 2 * p));

            if(Distance < BestDistance || BestDistance < 0)
            {
               IndexL = i;
               IndexR = j;
               BestDistance = Distance;
            }
         }
      }

      if(IndexR < IndexL)   // just in case
         std::swap(IndexL, IndexR);

      // Now make a new node
      Node *NewNode = new Node(Nodes[IndexL], Nodes[IndexR]);
      
      if(Scheme == WTAScheme)
      {
         double PTL = NewNode->Child1->P.GetPT();
         double PTR = NewNode->Child2->P.GetPT();
         double NewPT  = PTL + PTR;
         double NewEta, NewPhi;
         if(PTL == PTR)
         {
            NewEta = NewNode->Child1->P.GetEta() + NewNode->Child2->P.GetEta();
            NewPhi = NewNode->Child1->P.GetPhi() + NewNode->Child2->P.GetPhi();
         }
         else if(PTL > PTR)
         {
            NewEta = NewNode->Child1->P.GetEta();
            NewPhi = NewNode->Child1->P.GetPhi();
         }
         else if(PTL < PTR)
         {
            NewEta = NewNode->Child2->P.GetEta();
            NewPhi = NewNode->Child2->P.GetPhi();
         }

         NewNode->P.SetPtEtaPhiMass(NewPT, NewEta, NewPhi, NewNode->P.GetMass());
      }
      else
         NewNode->P = NewNode->Child1->P + NewNode->Child2->P;

      Nodes[IndexL] = NewNode;
      Nodes.erase(Nodes.begin() + IndexR);
   }
}





