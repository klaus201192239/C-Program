#include<iostream>
#include<windows.h>
using namespace std;
class intstack
{
	int max;
	int top;
	int *st;
public:
	intstack(int size)
	{
		max=size;
		top=-1;
		st=new int[size];
	}
	intstack()
	{
		top=-1;
	}
	~intstack()
	{
		delete [] st;
	}
	void clear()
	{
		top=-1;
	}
	int push(const int number)
	{
		if(top==max-1)
		{
			cout<<"manle"<<endl;
			return 0;
		}
		else
		{
			st[++top]=number;
			return 1;
		}
	}
	int pop(int &item)
	{
		if(top==-1)
		{
			cout<<"kongde"<<endl;
			return 0;
		}
		else
		{
			item=st[top--];
			return 1;
		}
	}
	int Top(int &num)
	{
		if(top==-1)
		{
			cout<<"kongde"<<endl;
			return 0;
		}
		else
		{
			num=st[top];
			return 1;
		}
	}
	void change(int i,int j)
	{
		while(j)
		{
			push(j%i);
			j=j/i;
		}
	}
};
int main()
{
	int h;
	intstack a(20);
	a.change(2,99999);
	while(a.pop(h))
	{
		cout<<h<<"  ";
	}
	cout<<endl;
	system("pause");
	return 0;
}
