#include<iostream>
#include<Windows.h>
using namespace std;
struct node
{
	int data;
	int sign;
};
class tu
{
	node *td;
	int **Arr;
	int maxsize;
public:
	tu(int size);
	~tu();
	int without_derection_creat();
	int show();
	int poquan();
	int prim();
};
tu::tu(int size)
{
	maxsize=size;
	Arr=new int*[maxsize];
	td=new node[maxsize];
	for(int i=0;i<maxsize;i++)
	{
		Arr[i]=new int[maxsize];
	}
}
tu::~tu()
{
	if(maxsize==1)
		delete td;
	if(maxsize>1)
		delete []td;
	delete Arr;
}
int tu::without_derection_creat()
{
	int i=0,number,j;
	cout<<"please input node data"<<endl;
	while(i<maxsize)
	{
		cout<<"V"<<i<<"  "<<"IS ";
		cin>>number;
		td->data=number;
		td->sign=0;
		i++;
	}
	i=j=0;
	for(i=0;i<maxsize;i++)
	{
		for(j=0;j<maxsize;j++)
		{
			Arr[i][j]=-1;
		}
	}
	while(1)
	{
		cout<<"input a node,\nV";
		cin>>i;
		if(i==-1)
			return 1;
		cout<<"input another node,\nV";
		cin>>j;
		cout<<"input path data"<<endl;
		cin>>number;
		Arr[i][j]=number;
		Arr[j][i]=number;
	}
}
int tu::show()
{
	int i,j;
	for(i=0;i<maxsize;i++)
		for(j=0;j<maxsize;j++)
		{
			cout<<Arr[i][j]<<" ";
			if(j==maxsize-1)
				cout<<endl;
		}
	cout<<endl;
	return 1;
}
int tu::poquan()
{
	int i=0,j=0,k,l,t=1,start,end,max,temp,ss,ee;
	for(i=0;i<maxsize;i++)
	{
		for(j=0;j<maxsize;j++)
		{
			if(Arr[i][j]==-1)
			{}
			else
			{
				start=i;
				end=j;
				max=temp=Arr[start][end];
				ss=i;ee=j;
				Arr[end][start]=-1;
				k=0;l=j;
				td[i].sign=1;
				while(t==1)
				{
					while(k<maxsize&&Arr[l][k]==-1)
					{
						k++;
					}
					if(k==maxsize)
					{
						Arr[end][start]=temp;
						t=0;
					}
					else
					{
						if(td[k].sign==1)
						{
							Arr[end][start]=temp;
							if(Arr[l][k]>max)
							{
								ss=l;
								ee=k;
								max=temp;
							}
							Arr[ss][ee]=Arr[ee][ss]=-1;
							k=0;
							while(k<maxsize)
							{
								td[k].sign=0;
								k++;
							}
							return 1;
						}
						Arr[end][start]=temp;
						td[l].sign=1;
						start=l;
						end=k;
						temp=Arr[l][k];
						if(temp>max)
						{
							ss=start;
							ee=end;
							max=temp;
						}
						Arr[end][start]=-1;
					}
					l=k;
					k=0;
				}
				while(k<maxsize)
				{
					td[k].sign=0;
					k++;
				}
				t=1;
			}
		}
	}
	return 0;
}
int tu::prim()
{
	int **arr,min,end,start,k,te,count=0,l;
	node *std;
	arr=new int*[maxsize];
	std=new node[maxsize];
	for(int i=0;i<maxsize;i++)
	{
		arr[i]=new int[maxsize];
	}
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
			arr[i][j]=-1;
	}
	for(int i=0;i<maxsize;i++)
	{
		std[i].data=-1;
		std[i].sign=0;
	}
	std[1].data=td[1].data;
	count++;
	start=1;
	while(count<maxsize)
	{
		for(k=0;k<maxsize&&(!(Arr[start][k]!=-1&&std[k].data==-1));k++){}
		min=Arr[start][k];
		for(l=0;l<maxsize;l++)
		{
			if(Arr[start][l]!=-1&&Arr[start][l]<min&&std[l].data==-1)
			{
				min=Arr[start][l];
				k=l;
			}
		}
		end=k;
		std[end].data=td[end].data;
		count++;
		arr[start][end]=Arr[start][end];
		arr[end][start]=Arr[start][end];
		start=end;
	}
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			if(arr[i][j]!=-1)
				Arr[i][j]=arr[i][j];
			else
				Arr[i][j]=-1;
		}
	}
	delete []arr;
	delete []std;
	return 1;
}
int main()
{
	tu T(4);
	T.without_derection_creat();
	T.show();
	while(T.poquan()){}
	T.show();
	system("pause");
	return 0;
}
