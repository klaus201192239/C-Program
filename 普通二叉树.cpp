#include<iostream>
#include<queue>
#include<stack>
#include<math.h>
#include<Windows.h>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};
class bintree
{
	node *root;
public:
	bintree();
	~bintree();
	static int count0;
	static int count1;
	static int count2;
	static int tall;
	int creat(node *&root);
	void dele(node *root);
	void show(node *&root);
	int tell_du(node *&root);
	bool tell_whole(node *root);
	int heigh(node *root);
	void dele_du0(node *&root);
	void Pre(node *root);
	void PreWithout(node *root);
	void InOrder(node *root);
	void InOrderWithoutRecursion(node *root);
	void behindorder(node *root);
	//void printf(node *root);
	void exchange(node *&root);
	int levelnumber(node *root,int a[],int h);
	int width(node *root);
	int Max(node *root);
	node *copy(node *no1,node *no2);
};
int bintree::count0=0;
int bintree::count1=0;
int bintree::count2=0;
bintree::bintree()
{
	//root=NULL;
}
bintree::~bintree()
{
	//dele(root);
}
int bintree::creat(node *&root)
{
	int number;
	cin>>number;
	if(number==-1)
		root=NULL;
	else
	{
		root=new node;
		root->data=number;
		creat(root->left);
		creat(root->right);
	}
	return 1;
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
void bintree::show(node *&root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		show(root->left);
		show(root->right);
	}
}
bool bintree::tell_whole(node *root)
{
	if(root==NULL)
		return true;
	queue<node*> Q;
	if(root)
		Q.push(root);
	int flag=0;
	while(!Q.empty())
	{
		cout<<flag<<endl;
		if(flag==0)
		{
			if(Q.front()->left!=NULL)
				Q.push(Q.front()->left);
			else
				flag++;
			if(Q.front()->right!=NULL)
				Q.push(Q.front()->right);
			else
				flag++;
			Q.pop();
		}
		else
		{
			if(Q.front()->left!=NULL)
				return false;
			if(Q.front()->right!=NULL)
				return false;
			Q.pop();
		}
	}
	return true;
}
int bintree::tell_du(node *&root)
{
	if(root!=NULL)
	{
		if(root->left&&root->right)
			count2++;
		if((root->left&&root->right==NULL)||(root->left==NULL&&root->right))
			count1++;
		if(root->left==NULL&&root->right==NULL)
			count0++;
		tell_du(root->left);
		tell_du(root->right);
	}
	return 1;
}
int bintree::heigh(node *root)
{
	int h1,h2;
	if(root==NULL)
		return 0;
	else
	{
		h1=heigh(root->left);
		h2=heigh(root->right);
		return (h1<h2?(h2+1):(h1+1));
	}
}
void bintree::dele_du0(node *&root)
{
	if(root==NULL)
		return ;
	if(root->left==NULL&&root->right==NULL)
	{
		delete root;
		root=NULL;
	}
	else
	{
		dele_du0(root->left);
		dele_du0(root->right);
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
void bintree::PreWithout(node *root)
{
	using std::stack;
	stack<node *>S;
	S.push(NULL);
	while(root)
	{
		cout<<root->data<<" ";
		if(root->right!=NULL)
			S.push(root->right);
		if(root->left!=NULL)
			root=root->left;
		else
		{
			root=S.top();
			S.pop();
		}
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
void bintree::InOrderWithoutRecursion(node *root)
{
	using std::stack;
	stack<node *> S;
	node *temp=root;
	while((!S.empty())||temp)
	{
		if(temp)
		{
			S.push(temp);
			temp=temp->left;
		}
		else
		{
			temp=S.top();
			S.pop();
			cout<<temp->data<<" ";
			temp=temp->right;
		}
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
/*void bintree::printf(node *root)
{
	if(root!=NULL)
	{
		if(root->left==NULL&&root->right==NULL)
			cout<<root->data;
		else
		{
			cout<<"(";
			cout<<root->data;
		
	if(root->left->left==NULL&&root->left->right==NULL)
	{
		cout<<"(";
		
	}	
	printf(root->left);
	if(root->right!=NULL)
	{
		cout<<",";
		
	}
	printf(root->right);
	if(root->left->left==NULL&&root->left->right==NULL)
	{
			cout<<")";
	}
	//cout<<")";
	}
	}
}*/
void bintree::exchange(node *&root)
{
	node *temp;
	if(root==NULL)
		return ;
	if(root->left!=NULL||root->right!=NULL)
	{
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		exchange(root->left);
		exchange(root->right);
	}
		
}
int bintree::levelnumber(node *root,int a[],int h)
{
	if(root!=NULL)
	{
		a[h]+=1;
		levelnumber(root->left,a,h+1);
		levelnumber(root->right,a,h+1);
	}
	return 1;
}
int bintree::width(node *root)
{
	int a[100];
	int h=0,i,wid;
	for(i=0;i<100;i++)
	{
		a[i]=0;
	}
	levelnumber(root,a,h);
	wid=a[0];
	for(i=1;i<100;i++)
	{
		if(a[i]>wid)
			wid=a[i];
	}
	return wid;
}
int bintree::Max(node *root)
{
	using std::stack;
	stack<node *>S;
	int max=0;
	S.push(NULL);
	while(root)
	{
		if(root->data>=max)
			max=root->data;
		if(root->right!=NULL)
			S.push(root->right);
		if(root->left!=NULL)
			root=root->left;
		else
		{
			root=S.top();
			S.pop();
		}
	}
	return max;
}
node *bintree::copy(node *no1,node *no2)
{
     if(no2==NULL)
     {no1=NULL;}
	else
	{
		no1=new node;
		no1->data=no2->data;
		copy(no1->left,no2->left);
		copy(no1->right,no2->right);
	}
	return no1;
}
int main()
{
	bintree tree;
	node *no,*te,*r;
	tree.creat(no);
	tree.show(no);
	tree.InOrder(no);
	cout<<endl;
//	r=tree.copy(te,no);
//	tree.show(r);
	system("pause");
	return 0;
}
