#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
struct data_node
{
	char name[20];
	char phone[12];
	char email[20];
};
struct search_node
{
	char key[20];
};
class Contactbook
{
	data_node dArr[100];
	search_node sArr[100];
	static int length;
public:
	Contactbook();
	~Contactbook(){};
	int add();
	int dele();
	int show();
	int block();
	int creat();
	int change();
	int ordershow();
	int hash(char ch[]);
	int getinformition(int dex);
};
int Contactbook::length=0;
Contactbook::Contactbook()
{
	char pNull[20]={'\0'};
	for(int i=0;i<100;i++)
	{
		strcpy(dArr[i].name,pNull);
		strcpy(dArr[i].phone,pNull);
		strcpy(dArr[i].email,pNull);
		strcpy(sArr[i].key,pNull);
	}
}
int Contactbook::creat()
{
	int sign=1,i,le;
	char pNull[20]={'\0'};
	cout<<"name---phone----email"<<endl;
	while(sign)
	{
		cin>>sArr[length].key;
		le=sArr[length].key[0]+sArr[length].key[1]+sArr[length].key[2];
		i=le/5;
		if(strcmp(dArr[i].name,pNull)!=0)
		{
			while(strcmp(dArr[i].name,pNull)!=0)
			{
				i++;
			}
		}
		strcpy(dArr[i].name,sArr[length].key);
		cin>>dArr[i].phone;
		cin>>dArr[i].email;
		length++;
		cout<<"Continue(1) or not(0)?"<<endl;
		cin>>sign;
	}
	return 1;
}
int Contactbook::hash(char ch[])
{
	int index,le;
	le=ch[0]+ch[1]+ch[2];
	index=le/5;
	if(strcmp(ch,dArr[index].name)!=0)
	{
		while(strcmp(ch,dArr[index].name)!=0)
		{index++;}
	}
	return index;
}
int Contactbook::add()
{
	int Index,le;
	char na[20];
	char ph[12];
	char emai[20];
	char pNull[20]={'\0'};
	cout<<"name---phone----email"<<endl;
	cin>>na;
	cin>>ph;
	cin>>emai;
	le=na[0]+na[1]+na[2];
	Index=le/5;
	if(strcmp(dArr[Index].name,pNull)!=0)
	{
		while(strcmp(dArr[Index].name,pNull)!=0)
		{
			Index++;
		}
	}
	strcpy(sArr[length].key,na);
	strcpy(dArr[Index].name,na);
	strcpy(dArr[Index].phone,ph);
	strcpy(dArr[Index].email,emai);
	length++;
	return 1;
}
int Contactbook::dele()
{
	int i;
	char na[20];
	char pNull[20]={'\0'};
	cout<<"input delete name"<<endl;
	cin>>na;
	for(i=0;i<100&&strcmp(sArr[i].key,na)!=0;i++){}
	if(i==100)
	{
		cout<<"It's not here!"<<endl;
		return 0;
	}
	for(;i<99;i++)
	{
		strcpy(sArr[i].key,sArr[i+1].key);
	}
	i=hash(na);
	strcpy(dArr[i].name,pNull);
	strcpy(dArr[i].phone,pNull);
	strcpy(dArr[i].email,pNull);
	length--;
	return 1;
}
int Contactbook::change()
{
	int choice,Index,i;
	char na[20];
	char ph[12];
	char emai[20];
	cout<<"Whose informition do you want to change"<<endl;
	cin>>na;
	Index=hash(na);
	for(i=0;i<100&&strcmp(sArr[i].key,na)!=0;i++){}
	cout<<"change name(1) or phone(2) or email(3)"<<endl;
	cin>>choice;
	switch(choice)
	{
	case 1:
		strcpy(dArr[Index].name,na);
		strcpy(sArr[i].key,na);
		break;
	case 2:
		cout<<"input phonenumber"<<endl;
		cin>>ph;
		strcpy(dArr[Index].phone,ph);
		break;
	case 3:
		cout<<"input email"<<endl;
		cin>>emai;
		strcpy(dArr[Index].email,emai);
		break;
	default:;
	}
	return 1;
}
int Contactbook::show()
{
	char pNull[20]={'\0'};
	cout<<"name--------------phone--------------email"<<endl;
	for(int i=0;i<100;i++)
	{
		if(strcmp(dArr[i].name,pNull)!=0)
		{
			cout<<dArr[i].name<<"   "<<dArr[i].phone<<"   "<<dArr[i].email<<endl;
		}
	}
	return 1;
}
int Contactbook::ordershow()
{
	int j=0;
	char pNull[20]={'\0'};
	char a1[20],a2[12],a3[20];
	data_node *p=new data_node[length];
	for(int i=0;i<100;i++)
	{
		if(strcmp(dArr[i].name,pNull)!=0)
		{
			strcpy(p[j].name,dArr[i].name);
			strcpy(p[j].phone,dArr[i].phone);
			strcpy(p[j].email,dArr[i].email);
			j++;
		}
	}
	for(int i=0;i<length-1;i++)
	{
		for(j=0;j<length-i-1;j++)
		{
			if(strcmp(p[j].name,p[j+1].name)==1)
			{
				strcpy(a1,p[j].name);
				strcpy(p[j].name,p[j+1].name);
				strcpy(p[j+1].name,a1);
				strcpy(a2,p[j].phone);
				strcpy(p[j].phone,p[j+1].phone);
				strcpy(p[j+1].phone,a2);
				strcpy(a3,p[j].email);
				strcpy(p[j].email,p[j+1].email);
				strcpy(p[j+1].email,a3);
			}
		}
	}
	cout<<"name--------------phone--------------email"<<endl;
	for(int i=0;i<length;i++)
	{
		cout<<p[i].name<<"  "<<p[i].phone<<"  "<<p[i].email<<endl;
	}
	delete []p;
	return 1;
}
int Contactbook::block()
{
	int j=0,k,no;
	search_node *q;
	char pNull[20]={'\0'};
	char a1[20],a2[12],a3[20],na[20];
	data_node *p=new data_node[length];
	for(int i=0;i<100;i++)
	{
		if(strcmp(dArr[i].name,pNull)!=0)
		{
			strcpy(p[j].name,dArr[i].name);
			strcpy(p[j].phone,dArr[i].phone);
			strcpy(p[j].email,dArr[i].email);
			j++;
		}
	}
	for(int i=0;i<length-1;i++)
	{
		for(j=0;j<length-i-1;j++)
		{
			if(strcmp(p[j].name,p[j+1].name)==1)
			{
				strcpy(a1,p[j].name);
				strcpy(p[j].name,p[j+1].name);
				strcpy(p[j+1].name,a1);
				strcpy(a2,p[j].phone);
				strcpy(p[j].phone,p[j+1].phone);
				strcpy(p[j+1].phone,a2);
				strcpy(a3,p[j].email);
				strcpy(p[j].email,p[j+1].email);
				strcpy(p[j+1].email,a3);
			}
		}
	}
	if(length%5!=0)
	{no=length/5+1;}
	else
	{no=length/5;}
	q=new search_node[no];
	for(k=0;k<no;k++)
	{
		strcpy(q[k].key,p[k*5].name);
	}
	cout<<"input found name "<<endl;
	cin>>na;
	for(k=0;k<no&&strcmp(na,q[k].key)==1;k++){}
	if(k!=no)
	{
		for(int t=k*5;t>(k-1)*5;k--)
		{
			if(strcmp(p[k].name,na)==0)
			{
				cout<<"name--------------phone--------------email"<<endl;
				cout<<p[k].name<<"  "<<p[k].phone<<"  "<<p[k].email<<endl;
				delete []p;
				delete []q;
				return 1;
			}
		}
	}
	else
	{
		for(int t=(k-1)*5;t<length-1;k++)
		{
			if(strcmp(p[k].name,na)==0)
			{
				cout<<"name--------------phone--------------email"<<endl;
				cout<<p[k].name<<"  "<<p[k].phone<<"  "<<p[k].email<<endl;
				delete []p;
				delete []q;
				return 1;
			}
		}
	}
	cout<<"It's not here!"<<endl;
	delete []p;
	delete []q;
	return 0;
}
int Contactbook::getinformition(int index)
{
	cout<<"name--------------phone--------------email"<<endl;
	cout<<dArr[index].name<<"   "<<dArr[index].phone<<"   "<<dArr[index].email<<endl;
	return 1;
}
int main()
{
	int choice,index;
	char na[20];
	Contactbook Book;
	system("color 9a");
	cout<<"Please creat a Contactbook"<<endl;
	Book.creat();
	cout<<"打印列表--------------1"<<endl;
	cout<<"散列查找--------------2"<<endl;
	cout<<"分块查找--------------3"<<endl;
	cout<<"增加联系人------------4"<<endl;
	cout<<"删除联系人------------5"<<endl;
	cout<<"修改联系人------------6"<<endl;
	cout<<"退出本程序------------7"<<endl;
	cout<<"please choose"<<endl;
	cin>>choice;
	while(choice!=7)
	{
		switch(choice)
		{
		case 1:
			Book.ordershow();
			break;
		case 2:
			cout<<"input found name"<<endl;
			cin>>na;
			index=Book.hash(na);
			Book.getinformition(index);
			break;
		case 3:
			Book.block();
			break;
		case 4:
			Book.add();
			break;
		case 5:
			Book.dele();
			break;
		case 6:
			Book.change();
			break;
		default:;
		}
		cout<<"please choose"<<endl;
		cin>>choice;
	}
	system("pause");
	return 0;
}
