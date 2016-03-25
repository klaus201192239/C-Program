#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
int main()
{
	system("color 0d");//将背景置为浅绿色，字体置为淡蓝色
	int arr[100]={0},temp;//存储二进制代码的数组
	char Arr[100],ah[20];//Arr用来存储表达式，ah用来存储变元
	int i,sum,sign=0,count,length=0,size=0;//size为变元个数,count为记录每个基本积中的变元个数
	char ch;
	cout<<"请输入所用变元字母,并以#结束输入"<<endl;
	cin>>ch;
	while(ch!='#')
	{
		ah[size]=ch;
		size++;
		cin>>ch;
	}
	cout<<"请输入一个析取范式，并且以#结束"<<endl;
	cout<<"注明：每个基本积用括号括起来,‘&’为合取合运算，‘|’为析取运算，‘-’为否定运算"<<endl;
	cin>>ch;
	while(ch!='#')
	{
		Arr[length]=ch;
		length++;
		cin>>ch;
	}
	cout<<"其主析取范式为"<<endl;
	for(i=0;i<int(pow(2.0,size*1.0));i++)//二进制数值变化,循环2的size方次。由00...000到11...111
	{
		for(int j=0;j<length&&sign==0;j++)//sign为是否已经碰到值为1的基本积的标志
		{
			if(Arr[j]=='(')//遇到每个新的基本积时，将sum和count置零。
			{
				sum=count=0;
			}
			if((Arr[j]>='a'&&Arr[j]<='z')||(Arr[j]>='A'&&Arr[j]<='Z'))
			{
				count++;
				int m=0;
				while(m<size&&Arr[j]!=ah[m])//寻找这个变元对应的二进制码，ah[j](变元数组)对应arr[j]（二进制码数组）
				{
					m++;
				}
				sum=sum+arr[m];
			}
			if(Arr[j]=='-')
			{
				j++;
				count++;
				int m=0;
				while(m<size&&Arr[j]!=ah[m])
				{
					m++;
				}
				if(arr[m]==0)
					temp=1;
				if(arr[m]==1)
					temp=0;
				sum=sum+temp;
			}
			if(Arr[j]==')')
			{
				if(sum==count)//判断是否这个基本积是否值为1，若值为1，输出此次二进制数值对应的极小项，
				{
					cout<<"(";
					for(int l=0;l<size;l++)
					{
						if(l==0)
						{
							if(arr[l]==1)
								cout<<ah[l];
							if(arr[l]==0)
								cout<<"-"<<ah[l];
						}
						else
						{
							if(arr[l]==1)
								cout<<"&"<<ah[l];
							if(arr[l]==0)
								cout<<"&"<<"-"<<ah[l];
						}
					}
					if(i==int(pow(2.0,size*1.0))-1)
						cout<<")"<<endl;
					else
						cout<<") | ";
					sign=1;//标志置为1，是本次循环终止。
				}
			}
		}
		sign=0;
		arr[size-1]++;//二进制进位
		for(int j=size-1;j>0;j--)
		{
			if(arr[j]==2)
			{
				arr[j]=0;
				arr[j-1]++;
			}
		}
	}
	cout<<endl;
	system("pause");
	return 0;
}
