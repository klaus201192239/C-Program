#include<iostream>
#include<windows.h>
using namespace std;
class intstack
{
	int max;
	int top;
	char *st;
public:
	intstack(int size)
	{
		max=size;
		top=-1;
		st=new char[size];
	}
	intstack()
	{
		top=-1;
	}
	~intstack()
	{
		delete [] st;
	}
	void clear()
	{
		top=-1;
	}
	int push(const char number)
	{
		if(top==max-1)
		{
			cout<<"manle"<<endl;
			return 0;
		}
		else
		{
			st[++top]=number;
			return 1;
		}
	}
	int pop(char &item)
	{
		if(top==-1)
		{
			cout<<"kongde"<<endl;
			return 0;
		}
		else
		{
			item=st[top--];
			return 1;
		}
	}
	int Top(char &num)
	{
		if(top==-1)
		{
			cout<<"kongde"<<endl;
			return 0;
		}
		else
		{
			num=st[top];
			return 1;
		}
	}
	int change()
	{
		char ch,ah;
		cin>>ch;
		while(ch!='n')
		{
			switch(ch)
			{
			case '(':push(ch);
				break;
			case '[':push(ch);
				break;
			case '{':push(ch);
				break;
			default:;
			}
			switch(ch)
			{
			case ')':pop(ah);
				if(ah=='(')
				{
					break;
				}
				else
				{
					cout<<"bupipei"<<endl;
					return 0;
				}
				case ']':pop(ah);
				if(ah=='[')
				{
					break;
				}
				else
				{
					cout<<"bupipei"<<endl;
					return 0;
				}
				case '}':pop(ah);
				if(ah=='{')
				{
					break;
				}
				else
				{
					cout<<"bupipei"<<endl;
					return 0;
				}
				default:;
			}
			cin>>ch;
		}
		cout<<"all right!"<<endl;
		return 1;
	}
};
int main()
{
	intstack l(10);
	l.change();
	system("pause");
	return 0;
}
