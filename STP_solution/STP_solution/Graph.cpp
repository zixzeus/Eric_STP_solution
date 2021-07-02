#include"Graph.h"

GraphLink::GraphLink()
{
	MaxVertex = SIZE;
	NumVertex = NumEdge = 0;
	VertexTable = new Node[MaxVertex];
}

void GraphLink::InsertVertex(char v, int time_weight)
{
	if (NumVertex >= MaxVertex)
		return;
	VertexTable[NumVertex].data = v;
	VertexTable[NumVertex].time_weight = time_weight;
	NumVertex++;
}

int GraphLink::GetVertexI(char v)
{
	for (int i = 0; i < NumVertex; i++)
	{
		if (VertexTable[i].data == v)
			return i;
	}
	return -1;
}

int GraphLink::GetVertexTimeWeight(char v)
{
	int key = GetVertexI(v);
	int t = VertexTable[key].time_weight;
	return t;
}


void GraphLink::InsertEdge(char v1, char v2)
{
	int p1 = GetVertexI(v1);
	int p2 = GetVertexI(v2);
	if (p1 == -1 || p2 == -1)
		return;
	//p1->p2
	Edge* ed = new Edge(p2);
	ed->link = VertexTable[p1].list;
	VertexTable[p1].list = ed;

	//p2->p1
	ed = new Edge(p1);
	ed->link = VertexTable[p2].list;
	VertexTable[p2].list = ed;
	NumEdge++;
}

void GraphLink::Show()
{
	int i;
	for (i = 0; i < NumVertex; i++)
	{
		cout << VertexTable[i].data << "->";
		Edge* p = VertexTable[i].list;
		while (p)
		{
			cout << p->destvalue << "->";
			p = p->link;
		}
		cout << "null" << endl;
	}
}


void GraphLink::DeleteEdge(char v1, char v2)
{
	int p1 = GetVertexI(v1);
	int p2 = GetVertexI(v2);
	if (p1 == -1 || p2 == -1)
		return;
	//p1->p2
	Edge* p = VertexTable[p1].list;
	Edge* s = NULL;
	while (p && p->destvalue != p2)
	{
		s = p;
		p = p->link;
	}
	if (p == NULL)
		return;
	if (s == NULL)
		VertexTable[p1].list = p->link;
	else
		s->link = p->link;
	delete p;
	//p2->p1
	p = VertexTable[p2].list;
	s = NULL;
	while (p && p->destvalue != p1)
	{
		s = p;
		p = p->link;
	}
	if (s == NULL)
		VertexTable[p2].list = p->link;
	else
		s->link = p->link;
	delete p;
	p = NULL;
	NumEdge--;
}


void GraphLink::DeleteVertex(char v)
{
	int p = GetVertexI(v);
	if (p == -1)
		return;

	Edge* s = NULL;
	Edge* edp = VertexTable[p].list;
	while (edp)
	{
		int destvalue = edp->destvalue;
		Edge* q = VertexTable[destvalue].list;
		s = NULL;
		while (q && q->destvalue != p)
		{
			s = q;
			q = q->link;
		}
		if (s == NULL)
			VertexTable[destvalue].list = q->link;
		else
			s->link = q->link;
		delete q;
		q = NULL;
		VertexTable[p].list = edp->link;
		delete edp;
		edp = VertexTable[p].list;
		NumEdge--;
	}

	NumVertex--;

	VertexTable[p].data = VertexTable[NumVertex].data;
	VertexTable[p].list = VertexTable[NumVertex].list;

	edp = VertexTable[p].list;
	while (edp)
	{
		int destvalue = edp->destvalue;
		s = VertexTable[destvalue].list;
		while (s && s->destvalue != NumVertex)
		{
			s = s->link;
		}
		s->destvalue = p;
		edp = edp->link;
	}
}

GraphLink::~GraphLink()
{
	Edge* p = NULL;
	for (int i = 0; i < NumVertex; ++i)
	{
		p = VertexTable[i].list;
		while (p)
		{
			VertexTable[i].list = p->link;
			delete p;
			p = VertexTable[i].list;
		}
	}
	delete[]VertexTable;
	VertexTable = NULL;
}