#include<iostream>
#include<windows.h>
#include<queue>
#include<stack>
using namespace std;
struct edgenode
{
	int nunber;/* 邻接点域,一般是放顶点对应的序号或在表头向量中的下标*/
	int info; /*与边(或弧)相关的信息*/
	edgenode *next;/* 指向下一个邻接点的指针域*/
};
struct datanode
{
	int data;/* 顶点域*/
	int sign;//顶点是否被访问过的标志
	edgenode *first;/* 边表头指针*/
};
class Graph
{
	datanode *Arr;
	int Node_number;
	int Edge_number;
public:
	Graph(int node_number,int edge_number);
	~Graph();
	int creat();
	int show();
	int DFC();
	int BFC();
};
Graph::Graph(int node_number,int edge_number)
{
	Node_number=node_number;
	Edge_number=edge_number;
	Arr=new datanode[Node_number];
}
Graph::~Graph()
{
	delete []Arr;
}
int Graph::creat()
{
	int number,start,end,path;
	edgenode *p;
	for(int i=0;i<Node_number;i++)
	{
		cout<<"input datanode:"<<endl;
		cin>>number;
		Arr[i].data=number;
		Arr[i].sign=0;
		Arr[i].first =NULL;
	}
	for(int i=0;i<Edge_number;i++)
	{
		cout<<"input start and end and the path"<<endl;
		cin>>start>>end>>path;
		p=new edgenode;
		p->nunber=end;
		p->info=path;
		p->next=Arr[start].first;
		Arr[start].first=p;
	}
	return 1;
}
int Graph::show()
{
	edgenode *p;
	for(int i=0;i<Node_number;i++)
	{
		p=Arr[i].first;
		cout<<Arr[i].data<<" ";
		while(p!=NULL)
		{
			cout<<Arr[p->nunber].data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
	cout<<endl;
	return 1;
}
int Graph::DFC()
{
	stack<int> S;
	edgenode *p;
	int v,u;
	for(v=0;v<Node_number;v++)
	{
		if(Arr[v].sign==0)
		{
			Arr[v].sign=1;
			S.push(v);
			while(!S.empty())
			{
				u=S.top();
				cout<<Arr[u].data<<" ";
				S.pop();
				p=Arr[u].first;
				while(p!=NULL)
				{
					if(Arr[p->nunber].sign==0)
					{
						Arr[p->nunber].sign=1;
						S.push(p->nunber);
					}
					p=p->next;
				}
			}
		}
	}
	for(int i=0;i<Node_number;i++)
	{
		Arr[i].sign=0;
	}
	cout<<endl;
	return 1;
}
int Graph::BFC()
{
	queue<int> Q;
	int v,u;
	edgenode *p;
	for(v=0;v<Node_number;v++)
	{
		if(Arr[v].sign==0)
		{
			Arr[v].sign=1;
			//cout<<Arr[v].data<<" ";
			Q.push(v);
			while(!Q.empty())
			{
				u=Q.front();
				p=Arr[u].first;
				cout<<Arr[u].data<<" ";
				Q.pop();
				while(p!=NULL)
				{
					if(Arr[p->nunber].sign==0)
					{
					//	cout<<Arr[v].data<<" ";
						Arr[p->nunber].sign=1;
						Q.push(p->nunber);
					}
					p=p->next;
				}
			}
		}
	}
	for(int i=0;i<Node_number;i++)
	{
		Arr[i].sign=0;
	}
	cout<<endl;
	return 1;
}
int main()
{
	Graph G(8,16);
	G.creat();
	G.show();
	G.BFC();
	G.DFC();
	system("pause");
	return 0;
}
