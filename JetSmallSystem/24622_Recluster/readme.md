
# Recalculate WTA axis from constituent

You need to include CATree.h and make a vector of `Node *` object.

Then call `BuildCATreE(vector<Node *> &Nodes, double p, int Scheme)` to do the reclustering.
- p = 0 => CA, p = -1 => AntiKT
- Scheme = EScheme or WTAScheme

After it's done, the head node (`Nodes[0]`) is the full reclustered jet.  We can then access the axis by

```
Nodes[0]->P.GetEta()
Nodes[0]->P.GetPhi()
```



