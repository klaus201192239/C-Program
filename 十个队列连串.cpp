#include<iostream>
#include<windows.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
class queue
{
	node *front;
	int size;
public:
	queue();
	~queue();
	void clear();
	int enqueue(const int number);
	int dequeue(int &number);
	int getfront(int &number);
	int isempty();
	friend int link(queue &a,queue &b);
};
queue::queue()
{
	size=0;
	front=0;
}
queue::~queue()
{
	clear();
}
void queue::clear()
{
	node *rear;
	while(front!=0)
	{
		rear=front;
		front=front->next;
		delete rear;
	}
	front=0;
	size=0;
}
int queue::enqueue(const int number)
{
	node *rear,*temp;
	temp=new node;
	temp->data=number;
	temp->next=0;
	if(!front)
	{
		front=rear=temp;
	}
	else
	{
		rear=front;
		while(rear->next)
		{
			rear=rear->next;
		}
		rear->next=temp;
		rear=temp;
	}
	size++;
	return 1;
}
int queue::dequeue(int &number)
{
	node *de;
	if(size==0)
	{
		cout<<"it's empty!"<<endl;
		return 0;
	}
	number=front->data;
	de=front;
	front=front->next;
	delete de;
	size--;
	return 1;
}
int queue::getfront(int &number)
{
	number=front->data;
	return 1;
}
int queue::isempty()
{
	if(size==0)
	{
		//cout<<"it's hollow!"<<endl;
		return 1;
	}
	else
	{
		//cout<<"it's not hollow!"<<endl;
		return 0;
	}
}
int link(queue &a,queue &b)
{
	int temp;
	if(a.front==0|b.front==0)
	{
		//cout<<"there's empty one"<<endl;
		return 0;
	}
	while(b.isempty()!=1)
	{
		b.dequeue(temp);
		a.enqueue(temp);
	}
	return 1;
}
int main()
{
	queue a[10];
	int i,j=0,temp;
	cin>>i;
	while(i>=0)
	{
		a[i].enqueue(i);
		cin>>i;
	}
	for(i=1;i<10;i++)
	{
		link(a[j],a[i]);
	}
	while(a[0].isempty()!=1)
	{
		a[0].dequeue(temp);
		cout<<temp<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}
