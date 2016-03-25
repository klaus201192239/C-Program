#include<iostream>
#include<windows.h>
using namespace std;
template<class T>
class intstack
{
	int max;
	int top;
	T *st;
public:
	intstack(int size);
	intstack();
	~intstack();
	void clear();
	int Top(T &num);
	int pop(T &item);
	int push(const T number);
	friend int operate();
};
template<class T>
intstack<T>::intstack(int size)
{
	max=size;
	top=-1;
	st=new T[size];
}
template<class T>
intstack<T>::intstack()
{
	top=-1;
}
template<class T>
intstack<T>::~intstack()
{
	delete [] st;
}
template<class T>
void intstack<T>::clear()
{
	top=-1;
}
template<class T>
int intstack<T>::push(const T number)
{
	if(top==max-1)
	{
		cout<<"full"<<endl;
		return 0;
	}
	else
	{
		st[++top]=number;
		return 1;
	}
}
template<class T>
int intstack<T>::pop(T &item)
{
	if(top==-1)
	{
		cout<<"empty!"<<endl;
		return 0;
	}
	else
	{
		item=st[top--];
		return 1;
	}
}
template<class T>
int intstack<T>::Top(T &num)
{
	if(top==-1)
	{
		cout<<"empty"<<endl;
		return 0;
	}
	else
	{
		num=st[top];
		return 1;
	}
}
int contrast(char &ch)
{
	if(ch=='*'||ch=='/')
		return 2;
	if(ch=='-'||ch=='+')
		return 1;
	if(ch=='#')
		return 0;
	return -1;
}
int operate()
{
	int arr[20]={0},a=0,i=0,j=0,aa,bb,cc,co;
	intstack<int> int_stack(10);
	intstack<char> char_stack(10);
	char std[20],ch,temp;
	while(i<20)
	{
		std[i]='n';
		i++;
	}
	char_stack.push('#');
	do
	{
		cin>>ch;
		char_stack.Top(temp);
		if(ch=='(')
		{
			char_stack.push(ch);
			char_stack.Top(temp);
		}
		if(ch==')')
		{
			while(temp!='(')
			{
				char_stack.pop(temp);
				std[j]=temp;
				j++;
				char_stack.Top(temp);
			}
			char_stack.pop(temp);
			char_stack.Top(temp);
		}
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='#')
		{
			if(temp=='('||temp=='#')
				char_stack.push(ch);
			else
			{
				if(contrast(ch)>contrast(temp))
					char_stack.push(ch);
				else
				{
					while(temp!='('&&temp!='#'&&contrast(ch)<=contrast(temp))
					{
						char_stack.pop(temp);
						std[j]=temp;
						j++;
						char_stack.Top(temp);
					}
					char_stack.push(ch);
					char_stack.Top(temp);
				}
			}
		}
		if(ch>='0'&&ch<='9')
		{
			while(ch<='9'&&ch>='0')
			{
				a=a*10+(ch-'0');
				cin>>ch;
			}
			arr[j]=a;
			j++;
			a=0;
			if(ch=='(')
			{
				char_stack.push(ch);
				char_stack.Top(temp);
			}
			if(ch==')')
			{
				while(temp!='(')
			{
				char_stack.pop(temp);
				std[j]=temp;
				j++;
				char_stack.Top(temp);
			}
			char_stack.pop(temp);
			char_stack.Top(temp);
			}
			if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='#')
			{
				if(temp=='('||temp=='#')
					char_stack.push(ch);
				else
				{
					if(contrast(ch)>contrast(temp))
						char_stack.push(ch);
					else
					{
						while(temp!='('&&temp!='#'&&contrast(ch)<=contrast(temp))
						{
							char_stack.pop(temp);
							std[j]=temp;
							j++;
							char_stack.Top(temp);
						}
						char_stack.push(ch);
						char_stack.Top(temp);
					}
				}
			}
		}
	}while(ch!='#');
	j=0;
	while(j<20)
	{
		if(arr[j]!=0)
		{
			int_stack.push(arr[j]);
			j++;
		}
		else if(std[j]!='n')
		{
			int_stack.pop(aa);
			int_stack.pop(bb);
			switch(std[j])
			{
				case '+':cc=aa+bb;break;
				case '-':cc=bb-aa;break;
				case '*':cc=bb*aa;break;
				case '/':cc=bb/aa;break;
				default:;
			}
			int_stack.push(cc);
			j++;
		}
		else
		{
			j++;
		}
	}
	cout<<cc<<endl;
	return 1;
}
int main()
{
	operate();
	system("pause");
	return 0;
}
