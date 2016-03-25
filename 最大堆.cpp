#include<iostream>
#include<Windows.h>
using namespace std;
class Maxarray
{
	int *st;
	int maxsize;
	int heigh;
public:
	Maxarray(int size,int tall);
	~Maxarray();
	void buildMaxarray();
	void show();
	void delefirst();
	void insertfoirst(int number);
};
Maxarray::Maxarray(int size,int tall)
{
	st=new int[size];
	maxsize=size;
	heigh=tall;
	int i=0,data;
	cout<<"input:"<<endl;
	while(i<size)
	{
		cin>>data;
		st[i]=data;
		i++;
	}
}
Maxarray::~Maxarray()
{
	delete []st;
}
void Maxarray::buildMaxarray()
{
	int i,j=0,temp;
	while(j<heigh)
	{
		i=0;
		while(i<=(maxsize/2-1))
		{
			if((2*i+2)==maxsize)
			{
				if(st[i]<st[2*i+1])
				{
					temp=st[i];
					st[i]=st[2*i+1];
					st[2*i+1]=temp;
				}

			}
			if((2*i+2)<maxsize)
			{
				if(!(st[i]>st[2*i+1]&&st[i]>st[2*i+2]))
				{
					if(st[i]<st[2*i+1]&&st[2*i+1]<st[2*i+2])
					{
						temp=st[i];
						st[i]=st[2*i+2];
						st[2*i+2]=temp;
					}
					if(st[i]<st[2*i+2]&&st[2*i+2]<st[2*i+1])
					{
						temp=st[i];
						st[i]=st[2*i+1];
						st[2*i+1]=temp;
					}
					if(st[2*i+1]<st[i]&&st[i]<st[2*i+2])
					{
						temp=st[i];
						st[i]=st[2*i+2];
						st[2*i+2]=temp;
					}
					if(st[2*i+2]<st[i]&&st[i]<st[2*i+1])
					{
						temp=st[i];
						st[i]=st[2*i+1];
						st[2*i+1]=temp;
					}
				}
			}
			i++;
		}
		j++;
	}
}
void Maxarray::show()
{
	int i=0;
	while(i<maxsize)
	{
		cout<<st[i]<<" ";
		i++;
	}
	cout<<endl;
}
void Maxarray::delefirst()
{
	st[0]=st[maxsize-1];
	int *t=new int[maxsize-1];
	int i=0;
	while(i<(maxsize-1))
	{
		t[i]=st[i];
		i++;
	}
	delete []st;
	maxsize--;
	st=new int[maxsize];
	i=0;
	while(i<maxsize)
	{
		st[i]=t[i];
		i++;
	}
	delete []t;
	buildMaxarray();
}
void Maxarray::insertfoirst(int number)
{
	int *t=new int[maxsize];
	int i=0;
	while(i<maxsize)
	{
		t[i]=st[i];
		i++;
	}
	delete []st;
	maxsize++;
	st=new int[maxsize];
	st[0]=number;
	i=1;
	while(i<maxsize)
	{
		st[i]=t[i-1];
		i++;
	}
	delete []t;
	buildMaxarray();
}
int main()
{
	int a ,b,c;
	cout<<"输入节点数和高度："<<endl;
	cin>>a>>b;
	Maxarray tree(a,b);
	tree.buildMaxarray();
	tree.show();
	tree.delefirst();
	cout<<"删除头节点后："<<endl;
	tree.show();
	cout<<"输入新节点数据："<<endl;
	cin>>c;
	tree.insertfoirst(c);
	tree.show();
	system("pause");
	return 0;
}
