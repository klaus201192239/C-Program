#include<iostream>
#include<Windows.h>
using namespace std;
#define MAX 1500
typedef struct BiTreeNode
{
	char data;
	BiTreeNode *lChild;   
	BiTreeNode *rChild;   
	int lTag,rTag;  
}BiTreeNode;	  
BiTreeNode *pre =NULL;   
BiTreeNode *point[MAX+1];  
BiTreeNode *CreateBiTree()
{
	BiTreeNode *root=(BiTreeNode *)malloc(sizeof(BiTreeNode));
	int i,j;
	char data;
	cin>>i>>data;
	while(i!=0&&data!='#')
	{
		BiTreeNode *newNode=(BiTreeNode *)malloc(sizeof(BiTreeNode));
		newNode->data=data; 
		newNode->lTag=0;newNode->rTag=0;
		newNode->lChild=NULL;newNode->rChild=NULL;
		point[i]=newNode;
		if(i==1)
		{
			root=point[1];
		}
		else
		{
			j=i/2;
			if(i%2==0)
			{
				point[j]->lChild=newNode;
			}
			else
			{
				point[j]->rChild=newNode;
			}
		}
		cin>>i>>data;
	}
	return root;
}  
void Inthread(BiTreeNode *root)
{
	if(root!=NULL)
	{
		Inthread(root->lChild);
		if(root->lChild==NULL)
		{
			root->lTag=1;root->lChild=pre;
		}
		if(pre!=NULL&&pre->rChild==NULL)
		{
			pre->rTag=1;pre->rChild=root;
		}
		pre=root;
		Inthread(root->rChild);
	}
}   
BiTreeNode *InPre(BiTreeNode *p)
{
	if(p->lTag==1)
		return p->lChild;
	BiTreeNode *q=p->lChild;
	if(q==NULL)
	{
		cout<<"无前驱结点\n";
		return NULL;
	}
	while(q->rTag!=1)
	{
		q=q->rChild;
	}
	return q;
}
BiTreeNode *InSub(BiTreeNode *p)
{
	if(p->rTag==1)
		return p->rChild;
	BiTreeNode *q=p->rChild;
	if(q==NULL)
	{
		cout<<"无后继结点\n";
		return NULL;
	}
	while(q->lTag!=1)
	{
		q=q->lChild;
	}
	return q;
}
int main()
{
	char cmd;
	int index;
	BiTreeNode *root=CreateBiTree();
	Inthread(root);
	cout<<"输入您要查找的结点序号"<<endl;
	cin>>index;
	BiTreeNode *nodePre=InPre(point[index]);
	BiTreeNode *nodeSub=InSub(point[index]); 
	if(nodePre!=NULL)
		cout<<"结点的前驱结点的值为"<<nodePre->data<<endl;
	if(nodeSub!=NULL)
		cout<<"结点的后继结点的值为"<<nodeSub->data<<endl;
	system("pause");
	return 0;
}
