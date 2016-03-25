#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	char *ch1,*ch2,ch;
	int *a1,*a2,*a3,*td,C=0;
	int size,count=0,sign=0;
	cout<<"请输入位数（不包含符号位）"<<endl;
	cin>>size;
	td=new int[2*size+5];
	a1=new int[size+3];
	ch1=new char[size+2];
	ch2=new char[size+2];
	a2=new int[size+3];
	a3=new int[size+3];
	for(int j=0;j<2*size+5;j++)
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
		if(j==0)
			a1[0]=a1[1]=a1[2]=0;
		else
		{
			if(ch1[j]=='.')
				cin>>ch1[j];
			a1[j+2]=ch1[j]-'0';
		}
	}
	a2[0]=a2[1]=a2[2]=1;
	for(int j=3;j<size+3;j++)
	{
		if(a1[j]==1)
			a2[j]=0;
		if(a1[j]==0)
			a2[j]=1;
	}
	a2[size+2]++;
	for(int j=size+2;j>=3;j--)
	{
		if(a2[j]==2)
		{
			a2[j]=0;
			if(j!=3)
				a2[j-1]++;
		}
	}
	for(int j=0;j<size+3;j++)
		a3[j]=a1[j];
	for(int j=3;j<=size+2;j++)
	{
		a3[j-1]=a3[j];
	}
	a3[size+2]=0;
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
		if(j==0)
			td[3+size]=td[4+size]=0;
		else
		{
			if(ch2[j]=='.')
				cin>>ch2[j];
			td[4+size+j]=ch2[j]-'0';
		}
	}
	while(count<=(size/2))
	{
		if(td[2*size+3]==0&&td[2*size+4]==1&&C==0)
		{
			for(int j=size+2;j>=0;j--)
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
			C=0;
			count++;
			if(count<=(size/2))
			{
				if(td[0]==0)
				{
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
				}
				if(td[0]==1)
				{
					for(int j=size*2+3;j>=0;j--)
					{
					td[j+1]=td[j];
					}
					td[0]=1;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=1;
				}
				cout<<"第"<<count<<"次移位    ";
				for(int j=0;j<size*2+5;j++)
				{
					if(j==2)
					{
						cout<<td[2]<<".";
					}
					else
						cout<<td[j];
				}
				cout<<endl;
			}
			else
				break;
		}
		if(td[2*size+3]==1&&td[2*size+4]==0&&C==0)
		{
			for(int j=size+2;j>=0;j--)
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
			C=0;
			count++;
			if(count<=(size/2))
			{
				if(td[0]==0)
				{
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
				}
				if(td[0]==1)
				{
					for(int j=size*2+3;j>=0;j--)
					{
					td[j+1]=td[j];
					}
					td[0]=1;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=1;
				}
				cout<<"第"<<count<<"次移位    ";
				for(int j=0;j<size*2+5;j++)
				{
					if(j==2)
					{
						cout<<td[2]<<".";
					}
					else
						cout<<td[j];
				}
				cout<<endl;
			}
			else
				break;
		}
		if(td[2*size+3]==1&&td[2*size+4]==1&&C==0)
		{
			for(int j=size+2;j>=0;j--)
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
			C=1;
			count++;
			if(count<=(size/2))
			{
				if(td[0]==0)
				{
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
				}
				if(td[0]==1)
				{
					for(int j=size*2+3;j>=0;j--)
					{
					td[j+1]=td[j];
					}
					td[0]=1;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=1;
				}
				cout<<"第"<<count<<"次移位    ";
				for(int j=0;j<size*2+5;j++)
				{
					if(j==2)
					{
						cout<<td[2]<<".";
					}
					else
						cout<<td[j];
				}
				cout<<endl;
			}
			else
				break;
		}
		if(td[2*size+3]==0&&td[2*size+4]==0&&C==1)
		{
			for(int j=size+2;j>=0;j--)
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
			C=0;
			count++;
			if(count<=(size/2))
			{
				if(td[0]==0)
				{
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
				}
				if(td[0]==1)
				{
					for(int j=size*2+3;j>=0;j--)
					{
					td[j+1]=td[j];
					}
					td[0]=1;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=1;
				}
				cout<<"第"<<count<<"次移位    ";
				for(int j=0;j<size*2+5;j++)
				{
					if(j==2)
					{
						cout<<td[2]<<".";
					}
					else
						cout<<td[j];
				}
				cout<<endl;
			}
			else
				break;
		}
		if(td[2*size+3]==0&&td[2*size+4]==0&&C==0)
		{
			C=0;
			count++;
			if(count<=(size/2))
			{
				if(td[0]==0)
				{
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
				}
				if(td[0]==1)
				{
					for(int j=size*2+3;j>=0;j--)
					{
					td[j+1]=td[j];
					}
					td[0]=1;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=1;
				}
				cout<<"第"<<count<<"次移位    ";
				for(int j=0;j<size*2+5;j++)
				{
					if(j==2)
					{
						cout<<td[2]<<".";
					}
					else
						cout<<td[j];
				}
				cout<<endl;
			}
			else
				break;
		}
		if(td[2*size+3]==0&&td[2*size+4]==1&&C==1)
		{
			for(int j=size+2;j>=0;j--)
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
			C=0;
			count++;
			if(count<=(size/2))
			{
				if(td[0]==0)
				{
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
				}
				if(td[0]==1)
				{
					for(int j=size*2+3;j>=0;j--)
					{
					td[j+1]=td[j];
					}
					td[0]=1;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=1;
				}
				cout<<"第"<<count<<"次移位    ";
				for(int j=0;j<size*2+5;j++)
				{
					if(j==2)
					{
						cout<<td[2]<<".";
					}
					else
						cout<<td[j];
				}
				cout<<endl;
			}
			else
				break;
		}
		if(td[2*size+3]==1&&td[2*size+4]==0&&C==1)
		{
			for(int j=size+2;j>=0;j--)
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
			C=1;
			count++;
			if(count<=(size/2))
			{
				if(td[0]==0)
				{
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
				}
				if(td[0]==1)
				{
					for(int j=size*2+3;j>=0;j--)
					{
					td[j+1]=td[j];
					}
					td[0]=1;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=1;
				}
				cout<<"第"<<count<<"次移位    ";
				for(int j=0;j<size*2+5;j++)
				{
					if(j==2)
					{
						cout<<td[2]<<".";
					}
					else
						cout<<td[j];
				}
				cout<<endl;
			}
			else
				break;
		}
		if(td[2*size+3]==1&&td[2*size+4]==1&&C==1)
		{
			C=1;
			count++;
			if(count<=(size/2))
			{
				if(td[0]==0)
				{
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=0;
				}
				if(td[0]==1)
				{
					for(int j=size*2+3;j>=0;j--)
					{
					td[j+1]=td[j];
					}
					td[0]=1;
					for(int j=size*2+3;j>=0;j--)
					{
						td[j+1]=td[j];
					}
					td[0]=1;
				}
				cout<<"第"<<count<<"次移位    ";
				for(int j=0;j<size*2+5;j++)
				{
					if(j==2)
					{
						cout<<td[2]<<".";
					}
					else
						cout<<td[j];
				}
			cout<<endl;
			}
			else
				break;
		}
	}
	cout<<"最终结果为  ";
	if(sign==0)
	{
		cout<<"-";
	}
	else
		cout<<" ";
	for(int j=2;j<size*2+3;j++)
	{
		if(j==2)
		{
			td[2]=0;
			cout<<td[2]<<".";
		}
		else
			cout<<td[j];
	}
	cout<<endl;
	system("pause");
	return 0;
}
