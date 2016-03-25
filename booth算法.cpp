#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int *a1,*a2,*a3,*b1,*b2,*td;
	char *ch1,*ch2,ch;
	int size,count=0,sign=0;
	cout<<"请输入位数（不包含符号位）"<<endl;
	cin>>size;
	td=new int[2*size+4];
	a1=new int[size+2];
	a2=new int[size+2];
	a3=new int[size+2];
	b1=new int[size+1];
	b2=new int[size+1];
	ch1=new char[size+2];
	ch2=new char[size+2];
	for(int j=0;j<2*size+4;j++)
		td[j]=0;
	cout<<"输入表达式，要连同正负号"<<endl;
	cin>>ch;
	if(ch=='+')
	{
		sign++;
		a1[0]=a1[1]=0;
	}
	if(ch=='-')
	{
		sign--;
		a1[0]=a1[1]=1;
	}
	for(int j=0;j<size;j++)
	{
		cin>>ch1[j];
		if(j==0)
			cin>>ch1[j];
		if(ch1[j]=='.')
			cin>>ch1[j];
		a1[j+2]=ch1[j]-'0';
	}
	//cout<<"here"<<endl;
	if(ch=='+')
	{
		for(int j=0;j<size+2;j++)
			a2[j]=a1[j];
		a3[0]=a3[1]=1;
		for(int j=2;j<size+2;j++)
		{
			if(a1[j]==1)
				a3[j]=0;
			if(a1[j]==0)
				a3[j]=1;
		}
		a3[size+1]++;
		for(int j=size+1;j>=2;j--)
		{
			if(a3[j]==2)
			{
				a3[j]=0;
				if(j!=2)
					a3[j-1]++;
			}
		}
	}
	if(ch=='-')
	{
		a2[0]=a2[1]=1;
		for(int j=2;j<size+2;j++)
		{
			if(a1[j]==1)
				a2[j]=0;
			if(a1[j]==0)
				a2[j]=1;
		}
		a2[size+1]++;
		for(int j=size+1;j>=2;j--)
		{
			if(a2[j]==2)
			{
				a2[j]=0;
				if(j!=2)
					a2[j-1]++;
			}
		}
		a3[0]=a3[1]=0;
		for(int j=2;j<size+2;j++)
			a3[j]=a1[j];
	}
	cin>>ch;
	if(ch=='*')
		cin>>ch;
	if(ch=='+')
	{
		sign++;
		b1[0]=0;
	}
	if(ch=='-')
	{
		sign--;
		b1[0]=1;
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
	if(ch=='+')
	{
		for(int j=0;j<size+1;j++)
			b2[j]=b1[j];
	}
	if(ch=='-')
	{
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
	}
	for(int j=0;j<size+1;j++)
	{
		td[size+2+j]=b2[j];
	}
	cout<<"X的原码  ";
	for(int j=0;j<size+2;j++)
	{
		if(j==1)
			cout<<a1[1]<<".";
		else
			cout<<a1[j];
	}
	cout<<endl;
	cout<<"X的补码  ";
	for(int j=0;j<size+2;j++)
	{
		if(j==1)
			cout<<a2[1]<<".";
		else
			cout<<a2[j];
	}
	cout<<endl;
	cout<<"-X的补码 ";
	for(int j=0;j<size+2;j++)
	{
		if(j==1)
			cout<<a3[1]<<".";
		else
			cout<<a3[j];
	}
	cout<<endl;
	cout<<"Y的原码  ";
	for(int j=0;j<size+1;j++)
	{
		if(j==0)
			cout<<b1[0]<<".";
		else
			cout<<b1[j];
	}
	cout<<endl;
	cout<<"Y的补码  ";
	for(int j=0;j<size+1;j++)
	{
		if(j==0)
			cout<<b2[0]<<".";
		else
			cout<<b2[j];
	}
	cout<<endl;
	while(count<=size)
	{
		if(td[2*size+2]==1&&td[2*size+3]==0)
		{
			for(int j=size+1;j>=0;j--)
			{
				td[j]=td[j]+a3[j];
				if(td[j]>=2)
				{
					td[j]=td[j]-2;
					if(j!=0)
					{
						td[j-1]++;
					}
				}
			}
			if(count==size)
				break;
			for(int j=size*2+2;j>=0;j--)
			{
				td[j+1]=td[j];
			}
			cout<<"第"<<count+1<<"次移位    ";
			for(int j=0;j<size*2+4;j++)
			{
				if(j==1)
				{
					cout<<td[0]<<".";
				}
				else
					cout<<td[j];
			}
			cout<<endl;
			count++;
		}
		if(td[2*size+2]==td[2*size+3])
		{
			if(count==size)
				break;
			for(int j=size*2+2;j>=0;j--)
			{
				td[j+1]=td[j];
			}
			cout<<"第"<<count+1<<"次移位    ";
			for(int j=0;j<size*2+4;j++)
			{
				if(j==1)
				{
					cout<<td[0]<<".";
				}
				else
					cout<<td[j];
			}
			cout<<endl;
			count++;
		}
		if(td[2*size+2]==0&&td[2*size+3]==1)
		{
			for(int j=size+1;j>=0;j--)
			{
				td[j]=td[j]+a2[j];
				if(td[j]>=2)
				{
					td[j]=td[j]-2;
					if(j!=0)
					{
						td[j-1]++;
					}
				}
			}
			if(count==size)
				break;
			for(int j=size*2+2;j>=0;j--)
			{
				td[j+1]=td[j];
			}
			cout<<"第"<<count+1<<"次移位    ";
			for(int j=0;j<size*2+4;j++)
			{
				if(j==1)
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
	cout<<"最终结果为(补码)   ";
	for(int j=1;j<size*2+2;j++)
	{
		if(j==1)
		{
			cout<<td[1]<<".";
		}
		else
			cout<<td[j];
	}
	if(td[1]==1)
	{
		for(int j=2;j<=size*2+1;j++)
		{
			if(td[j]==1)
				td[j]=0;
			else
				td[j]=1;
		}
		td[2*size+1]++;
		for(int j=2*size+1;j>=2;j--)
		{
			if(td[j]==2)
			{
				td[j]=0;
				if(j!=2)
					td[j-1]++;
			}
		}
	}
	cout<<endl;
	cout<<"最终结果为(真值)  ";
	if(td[1]==1)
	{
		td[1]=0;
		cout<<"-";
	}
	for(int j=1;j<size*2+2;j++)
	{
		if(j==1)
		{
			cout<<td[1]<<".";
		}
		else
			cout<<td[j];
	}
	cout<<endl;
	system("pause");
	return 0;
}
