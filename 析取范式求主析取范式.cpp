#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
int main()
{
	system("color 0d");//��������Ϊǳ��ɫ��������Ϊ����ɫ
	int arr[100]={0},temp;//�洢�����ƴ��������
	char Arr[100],ah[20];//Arr�����洢���ʽ��ah�����洢��Ԫ
	int i,sum,sign=0,count,length=0,size=0;//sizeΪ��Ԫ����,countΪ��¼ÿ���������еı�Ԫ����
	char ch;
	cout<<"���������ñ�Ԫ��ĸ,����#��������"<<endl;
	cin>>ch;
	while(ch!='#')
	{
		ah[size]=ch;
		size++;
		cin>>ch;
	}
	cout<<"������һ����ȡ��ʽ��������#����"<<endl;
	cout<<"ע����ÿ��������������������,��&��Ϊ��ȡ�����㣬��|��Ϊ��ȡ���㣬��-��Ϊ������"<<endl;
	cin>>ch;
	while(ch!='#')
	{
		Arr[length]=ch;
		length++;
		cin>>ch;
	}
	cout<<"������ȡ��ʽΪ"<<endl;
	for(i=0;i<int(pow(2.0,size*1.0));i++)//��������ֵ�仯,ѭ��2��size���Ρ���00...000��11...111
	{
		for(int j=0;j<length&&sign==0;j++)//signΪ�Ƿ��Ѿ�����ֵΪ1�Ļ������ı�־
		{
			if(Arr[j]=='(')//����ÿ���µĻ�����ʱ����sum��count���㡣
			{
				sum=count=0;
			}
			if((Arr[j]>='a'&&Arr[j]<='z')||(Arr[j]>='A'&&Arr[j]<='Z'))
			{
				count++;
				int m=0;
				while(m<size&&Arr[j]!=ah[m])//Ѱ�������Ԫ��Ӧ�Ķ������룬ah[j](��Ԫ����)��Ӧarr[j]�������������飩
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
				if(sum==count)//�ж��Ƿ�����������Ƿ�ֵΪ1����ֵΪ1������˴ζ�������ֵ��Ӧ�ļ�С�
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
					sign=1;//��־��Ϊ1���Ǳ���ѭ����ֹ��
				}
			}
		}
		sign=0;
		arr[size-1]++;//�����ƽ�λ
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
