#include<iostream>
#include<queue>
#include<stack>
#include<math.h>
#include<string>
#include<Windows.h>
using namespace std;
struct node
{
	char data;
	node *left;
	node *right;
};
class bintree
{
	node *root;
public:
	bintree();
	~bintree();
	void dele(node *root);
	void Pre(node *root);
	void InOrder(node *root);
	void behindorder(node *root);
	void pre_mid_creat(node *&t,string mid,string pre,int lm,int rm,int lp,int rp);
	void mid_behind_creat(node *&t,string mid,string post,int lm,int rm,int lp,int rp);
};
bintree::bintree()
{
	root=NULL;
}
bintree::~bintree()
{
	dele(root);
}
void bintree::dele(node *root)
{
	if(root!=NULL)
	{
		dele(root->left);
		dele(root->right);
		delete root;
		root=NULL;
	}
}
void bintree::Pre(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		Pre(root->left);
		Pre(root->right);
	}
}
void bintree::behindorder(node *root)
{
	if(root!=NULL)
	{
		behindorder(root->left);
		behindorder(root->right);
		cout<<root->data<<" ";
	}
}
void bintree::InOrder(node *root)
{
	if(root!=NULL)
	{
		if(root->left!=NULL)
			InOrder(root->left);
		cout<<root->data<<" ";
		if(root->right!=NULL)
			InOrder(root->right);
	}
}
void bintree::pre_mid_creat(node *&t,string mid, string pre, int lm, int rm, int lp, int rp)
{
	t=new node;
	t->data = pre[lp];
	t->left=t->right=NULL;
	int pos=lm;
	while (mid[pos]!=pre[lp])
		pos++;
	int lenL=pos-lm;
	if (pos>lm)
		pre_mid_creat(t->left,mid,pre,lm,pos-1,lp+1,lp+lenL);
	if (pos<rm)
		pre_mid_creat(t->right,mid,pre,pos+1,rm,lp+lenL+1,rp);
}
void bintree::mid_behind_creat(node *&t,string mid,string post,int lm,int rm,int lp,int rp)
{
	t=new node;
	t->data=post[rp];
    t->left=t->right=NULL;
	int pos=lm;
	while(mid[pos]!=post[rp])
		pos++;
	int lenL=pos-lm;
	if(pos>lm)
		mid_behind_creat(t->left,mid,post,lm,pos-1,lp,lp+lenL-1);
	if(pos<rm)
		mid_behind_creat(t->right,mid,post,pos+1,rm,lp+lenL,rp-1);
}
int main()
{
	bintree tree;
	node *no1,*no2;
	string pre,mid,behind;
	cout<<"输入前序序列"<<endl;
    cin>>pre;
	cout<<"输入中序序列"<<endl;
    cin>>mid;
  //  cout<<"输入后序序列"<<endl;
   // cin >>behind;
	tree.pre_mid_creat(no1,mid,pre,0,mid.size()-1,0,pre.size()-1);
	tree.behindorder(no1);
	cout<<endl;
//	tree.mid_behind_creat(no2,mid,behind,0,mid.size()-1,0,behind.size()-1);
//	tree.Pre(no2);
	cout<<endl;
	system("pause");
	return 0;
}
