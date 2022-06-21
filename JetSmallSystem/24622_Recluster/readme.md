
# Recalculate WTA axis from constituent

## Reclustering

You need to include `CATree.h` (which then includes `TauHelperFunctions3.h`) and make a vector of `Node *` object.

Then call `BuildCATree(vector<Node *> &Nodes, double p, int Scheme)` to do the reclustering.
- `p = 0` => Cambridge-Aachen, `p = -1` => anti-KT clustering
- `Scheme` = `EScheme` or `WTAScheme`

After it's done, the head node (`Nodes[0]`) is the full reclustered jet.  We can then access the axis by

```
Nodes[0]->P.GetEta()
Nodes[0]->P.GetPhi()
```

## Behind the scene

The `BuildCATree(...)` function rearranges all the nodes in the vector into a binary tree based on clustering algorithm and recombination scheme.  After the function is done, there should only be one single entry in the vector containing the root node of the tree (all others should be linked as children).

Once we have this binary tree structure, one can easily run many different algorithms (for example soft drop grooming, subjet reclustering, etc)


## Soft drop

Once we have the `BuildCATree` step done, all we need is to call `FindSDNode(Node *Head, double Z, double beta, double R)` to get the node corresponding to the soft drop result

```
Node *SDNode = FindSDNode(Nodes[0], 0.1, 0.0, 0.4);
```

Then we can get the four vector as follows
- `SDNode->P`: groomed jet 4-vector
- `SDNode->Child1->P`: leading subjet 4-vector
- `SDNode->Child2->P`: subleading subjet 4-vector

There are some completely groomed-away cases.  If `SDNode->N == 1` it means nothing is left after grooming.  In this case `Child1` and `Child2` will be `nullptr`.  Be careful!



## Example

See example usage in the `TestCATree.cpp` source file.  To test run the file, simply compile with g++

```
g++ TestCATree.cpp -o Execute
./Execute
```






