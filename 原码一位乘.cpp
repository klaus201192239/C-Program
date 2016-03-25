#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int *a1,*a2,*td;
	char *ch1,*ch2,ch;
	int size,count=0,sign=0;
	cout<<"请输入位数（不包含符号位）"<<endl;
	cin>>size;
	td=new int[2*size+1];
	a1=new int[size+1];
	ch1=new char[size+2];
	ch2=new char[size+2];
	for(int j=0;j<2*size+1;j++)
		td[j]=0;
	cout<<"输入表达式，要连同正负号"<<endl;
	cin>>ch;
	if(ch=='+')
		sign++;
	if(ch=='-')
		sign--;
	for(int j=0;j<size+1;j++)
	{
		cin>>ch1[j];
		if(ch1[j]=='.')
			cin>>ch1[j];
		a1[j]=ch1[j]-'0';
	}
	cin>>ch;
	if(ch=='*')
		cin>>ch;
	if(ch=='+')
		sign++;
	if(ch=='-')
		sign--;
	for(int j=0;j<size+1;j++)
	{
		cin>>ch2[j];
		if(j!=0)
		{
			if(ch2[j]=='.')
				cin>>ch2[j];
			td[j+size]=ch2[j]-'0';
		}
	}
	while(count<size)
	{
		if(td[2*size]==0)
		{
			for(int j=2*size-1;j>=0;j--)
			{
				td[j+1]=td[j];
			}
			td[0]=0;
			cout<<"第"<<count+1<<"次移位    ";
			for(int j=0;j<size*2+1;j++)
			{
				if(j==0)
				{
					cout<<td[0]<<".";
				}
				else
					cout<<td[j];
			}
			cout<<endl;
			count++;
		}
		if(td[size*2]==1)
		{
			for(int j=size;j>=0;j--)
			{
				td[j]=td[j]+a1[j];
				if(td[j]>=2)
				{
					td[j]=td[j]-2;
					if(j!=0)
					{
						td[j-1]++;
					}
				}
			}
			for(int j=2*size-1;j>=0;j--)
			{
				td[j+1]=td[j];
			}
			td[0]=0;
			cout<<"第"<<count+1<<"次移位    ";
			for(int j=0;j<size*2+1;j++)
			{
				if(j==0)
				{
					cout<<td[0]<<".";
				}
				else
					cout<<td[j];
			}
			cout<<endl;
			count++;
		}
	}
	cout<<"最终结果为  ";
	if(sign==0)
	{
		cout<<"-";
	}
	else
		cout<<" ";
	for(int j=0;j<size*2+1;j++)
	{
		if(j==0)
		{
			cout<<td[0]<<".";
		}
		else
			cout<<td[j];
	}
	cout<<endl;
	system("pause");
	return 0;
}
