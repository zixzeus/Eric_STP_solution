#include "Graph.h"
#include "FCFS.h"
#include <iostream>
#include<iostream>
#include<algorithm> 
#include<string>
using namespace std;


int main()
{
    GraphLink G;
    G.InsertVertex(0,15);
    G.InsertVertex(1,20);
    G.InsertVertex(2,5);
    G.InsertVertex(3,10);
    G.InsertVertex(4,5);
    G.InsertEdge(0, 2);
    G.InsertEdge(2, 3);
    G.InsertEdge(1, 2);
    G.InsertEdge(2, 4);
    G.Show();

    int const n = 2;
    string name[n] = { "Humpty","Dumpty" };
    int a[n] = {G.GetVertexTimeWeight(0),G.GetVertexTimeWeight(1)};
    int s[n] = {G.GetVertexTimeWeight(2),G.GetVertexTimeWeight(2)};
    int p[n] = {G.GetVertexTimeWeight(3),G.GetVertexTimeWeight(4)};

    FCFS F(n);
    F.inputP(name, a, s, p);
    F.getresult();
    F.printP();
}


