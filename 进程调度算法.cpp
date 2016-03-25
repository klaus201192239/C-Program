#include<iostream>
#include<windows.h>
using namespace std;
struct node
{
	char name[5];
	int data;
	int ti;
	node *next;
};
class single_list
{
	node *first;
public:
	single_list();
	~single_list(){};
	void creat();
	int show();
	int clean();
	int FCFS();
	int Round();
	int getlen();
};
single_list::single_list()
{
	first=0;
}
void single_list::creat()
{
	int number;
	char na[5];
	node *tail,*temp;
	cout<<"�����������"<<endl;
	cin>>na;
	cout<<"�������ʱ�䳤��"<<endl;
	cin>>number;
	while(number!=-1)
	{
		temp=new node;
		temp->data=number;
		temp->ti=number;
		strcpy(temp->name,na);
		temp->next=0;
		if(!first)
		{
			first=tail=temp;
		}
		else
		{
		tail->next=temp;
		tail=temp;
		}
		cout<<"�����������"<<endl;
		cin>>na;
		cout<<"�������ʱ�䳤��"<<endl;
		cin>>number;
	}
}
int single_list::clean()
{
	node *tail,*de;
	tail=first;
	if(!first)
	{
		cout<<"it's hollow"<<endl;
		return 0;
	}
	else
	{
		while(tail)
		{
			de=tail;
			tail=tail->next;
			delete de;
		}
		first=0;
	}
	return 1;
}
int single_list::show()
{
	node *tail;
	tail=first;
	if(!tail)
	{
		cout<<"it's hollow"<<endl;
		return 0;
	}
	while(tail)
	{
		cout<<tail->name<<"  ";
		cout<<tail->data<<"  ";
		tail=tail->next;
	}
	cout<<endl;
	return 1;
}
int single_list::getlen()
{
	node *tail;
	int leng=0;
	tail=first;
	if(!tail)
	{
		cout<<"it's hollow"<<endl;
		return 0;
	}
	while(tail)
	{
		leng++;
		tail=tail->next;
	}
	return leng;
}
int single_list::FCFS()
{
	node *tail;
	int sum=0,time0=0,time1=0;
	tail=first;
	cout<<"FCFS�㷨"<<endl;
	while(tail)
	{
		cout<<"|(";
		cout<<sum<<")  ";
		time0=time0+sum;
		cout<<tail->name<<"  ";
		sum=sum+tail->data;
		time1=time1+sum;
		tail=tail->next;
	}
	cout<<"|(";
	cout<<sum<<")";
	cout<<endl;
	cout<<"ƽ���ȴ�ʱ��"<<"    "<<(time0*1.0)/getlen()<<endl;;
	cout<<"ƽ����תʱ��"<<"    "<<(time1*1.0)/getlen()<<endl;;
	return 1;
}
int single_list::Round()
{
	node *tail;
	int sum=0,length,count=0,time0=0,time1=0;
	tail=first;
	cout<<"��ת�㷨"<<endl;
	cout<<"����ʱ��Ƭ����"<<endl;
	cin>>length;
	while(tail)
	{
		
		if(tail->data>=length)
		{
			if(tail->data==length)
			{
				cout<<"|(";
				cout<<sum<<")  ";
				cout<<tail->name<<"  ";
				tail->data=0;
				sum=sum+length;
				time0=time0+sum-tail->ti;
				time1=time1+sum;

			}
			else
			{
				cout<<"|(";
				cout<<sum<<")  ";
				cout<<tail->name<<"  ";
				tail->data=tail->data-length;
				sum=sum+length;
			}
		}
		else
		{
			if(tail->data!=0)
			{
				cout<<"|(";
				cout<<sum<<")  ";
				cout<<tail->name<<"  ";
				sum=sum+tail->data;
				tail->data=0;
				time0=time0+sum-tail->ti;
				time1=time1+sum;
			}
			else
			{
				count++;
			}
		}
		tail=tail->next;
		if(!tail)
		{
			if(count==getlen()){}
			else
			{
				tail=first;
				count=0;
			}
		}
	}
	cout<<"|(";
	cout<<sum<<")";
	cout<<endl;
	cout<<"ƽ���ȴ�ʱ��"<<"    "<<(time0*1.0)/getlen()<<endl;;
	cout<<"ƽ����תʱ��"<<"    "<<(time1*1.0)/getlen()<<endl;;
	return 1;
}
int main()
{
	single_list L;
	L.creat();
	L.FCFS();
	L.Round();
	system("pause");
	return 0;
}
