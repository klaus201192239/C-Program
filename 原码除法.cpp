#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int *b1,*b2,*td;
	char *ch1,*ch2,ch;
	int size,count=0,sign=0,temp;
	cout<<"请输入位数（不包含符号位）"<<endl;
	cin>>size;
	td=new int[2*size+2];
	b1=new int[size+1];
	b2=new int[size+1];
	ch1=new char[size+2];
	ch2=new char[size+2];
	for(int j=0;j<2*size+2;j++)
		td[j]=0;
	cout<<"输入表达式，要连同正负号"<<endl;
	cin>>ch;
	if(ch=='+')
	{
		sign++;
	}
	if(ch=='-')
	{
		sign--;
	}
	for(int j=0;j<size;j++)
	{
		cin>>ch1[j];
		if(j==0)
			cin>>ch1[j];
		if(ch1[j]=='.')
			cin>>ch1[j];
		td[j+1]=ch1[j]-'0';
	}
	b1[0]=0;
	cin>>ch;
	if(ch=='/')
		cin>>ch;
	if(ch=='+')
	{
		sign++;
	}
	if(ch=='-')
	{
		sign--;
	}
	for(int j=0;j<size;j++)
	{
		cin>>ch2[j];
		if(j==0)
			cin>>ch2[j];
		if(ch2[j]=='.')
			cin>>ch2[j];
		b1[j+1]=ch2[j]-'0';
	}
	b2[0]=1;
	for(int j=1;j<size+1;j++)
	{
		if(b1[j]==1)
			b2[j]=0;
		if(b1[j]==0)
			b2[j]=1;
	}
	b2[size]++;
	for(int j=size;j>=1;j--)
	{
		if(b2[j]==2)
		{
			b2[j]=0;
			if(j!=1)
				b2[j-1]++;
		}
	}
	cout<<"Y*的补码   ";
	for(int j=0;j<size+1;j++)
	{
		if(j==0)
			cout<<b1[0]<<".";
		else
			cout<<b1[j];
	}
	cout<<endl;
	cout<<"-Y*的补码  ";
	for(int j=0;j<size+1;j++)
	{
		if(j==0)
			cout<<b2[0]<<".";
		else
			cout<<b2[j];
	}
	cout<<endl;
	temp=td[0];
	while(count<=size)
	{
		if(temp==0)
		{
			for(int j=size;j>=0;j--)
			{
				td[j]=td[j]+b2[j];
				if(td[j]>=2)
				{
					td[j]=td[j]-2;
					if(j!=0)
					{
						td[j-1]++;
					}
				}
			}
			temp=td[0];
			if(count!=size)
			{
				if(td[0]==1)
					td[2*size+1]=0;
				else
					td[2*size+1]=1;
			}
			else
			{
				td[2*size+1]=1;
				break;
			}
			for(int j=1;j<=2*size+1;j++)
			{
				td[j-1]=td[j];
			}
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
		if(temp==1)
		{
			for(int j=size;j>=0;j--)
			{
				td[j]=td[j]+b1[j];
				if(td[j]>=2)
				{
					td[j]=td[j]-2;
					if(j!=0)
					{
						td[j-1]++;
					}
				}
			}
			temp=td[0];
			if(count!=size)
			{
				if(td[0]==1)
					td[2*size+1]=0;
				else
					td[2*size+1]=1;
			}
			else
			{
				td[2*size+1]=1;
				break;
			}
			for(int j=1;j<=2*size+1;j++)
			{
				td[j-1]=td[j];
			}
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
	if(sign==0)
		td[size+1]=1;
	cout<<"最终结果为   ";
	for(int j=size+1;j<size*2+2;j++)
	{
		if(j==size+1)
		{
			cout<<td[j]<<".";
		}
		else
			cout<<td[j];
	}
	cout<<endl;
	system("pause");
	return 0;
}
