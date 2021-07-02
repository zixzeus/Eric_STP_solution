#include <iostream>
using namespace std;

#define SIZE 10

class Edge
{
public:
	Edge(int i = 0) :destvalue(i), link(NULL) {}
	int destvalue;
	Edge* link;
};

class Node
{
public:
	Node(int i=0) :list(NULL) {}
	Node(int data, int time_weight)
	{
		data = data;
		time_weight = time_weight;
	}
	int data;
	int time_weight;
	Edge* list;
};


class GraphLink
{
public:
	GraphLink();
	void InsertVertex(char v, int time_weight);
	int GetVertexI(char v);
	int GetVertexTimeWeight(char v);
	void InsertEdge(char v1, char v2);
	void Show();
	void DeleteEdge(char v1, char v2);
	void DeleteVertex(char v);
	~GraphLink();

private:
	int MaxVertex;
	int NumVertex;
	int NumEdge;
	Node* VertexTable;
};
