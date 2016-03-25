#include<iostream>
#include<string>
#include<assert.h>
#include<windows.h>
using namespace std;
class String
{
	char *str;
	int size;
public:
	String(char *s);
	~String();
	void show();
	int strlen();
	int strlen(char s[]);
	char *find_last(char *p);
	char *strchr(char *s,char c);//ÕıÏò²éÕÒÄ³×Ö·û
	char *strrchr(char *s,char c);//ÄæÏòÑ°ÕÒÄ³×Ö·û
	int strcmp(char *s1,char *s2);//±È½Ï
	char *strcpy(char *s1,char *s2);
	String Substr(int dex,int count);//³éÈ¡×Ö·û´®
	char operator [](int i);
	String &operator =(String &s);
	String &operator+=(String &s);
	friend int Strcmp(String &a,String &b);
};
String::String(char *s)
{
	size=strlen(s);
	str=new char[size+1];
	assert(str!='\0');
	strcpy(str,s);
}
String::~String()
{
	if(size==1)
		delete str;
	else if(size<=0)
		cout<<"no string"<<endl;
	else
		delete []str;
}
void String::show()
{
	int count=0;
	while(str[count]!='\0')
	{
		cout<<str[count];
		count++;
	}
	cout<<endl;
}
String &String::operator+=(String &s)
{
	char *temp=str;
	size=size+s.size;
	str=new char[size+1];
	assert(str!=0);
	strcpy(str,temp);
	strcat(str,s.str);
	delete temp;
	return *this;
}
char String::operator[](int i)
{
	return str[i];
}
int String::strlen()
{
	return strlen(str);
}

int String::strlen(char s[])
{
	int count=0;
	while(s[count]!='\0')
	{
		count++;
	}
	return count;
}
int String::strcmp(char *s1,char *s2)
{
	int count=0;
	while(s1[count]!='\0'&&s2[count]!='\0')
	{
		if(s1[count]>s2[count])
			return 1;
		else if(s1[count]<s2[count])
			return -1;
		count++;
	}
	if(s1[count]=='\0'&&s2[count]!='\0')
		return -1;
	else if(s1[count]!='\0'&&s2[count]=='\0')
		return 1;
	return 0;
}
char *String::strcpy(char *s1,char *s2)
{
	int count=0;
	while(s2[count]!='\0')
	{
		s1[count]=s2[count];
		count++;
	}
	s1[count]='\0';
	return s1;
}
char *String::strchr(char *s,char c)
{
	int count=0;
	while(s[count]!='\0'&&s[count]!=c)
		count++;
	if(s[count]=='\0')
		return '\0';
	else 
		return &s[count];
}
char *String::strrchr(char *s,char c)
{
	int count=0;
	while(s[count]!='\0')
		count++;
	while(count>=0&&s[count]!=c)
		count--;
	if(count<0)
		return '\0';
	else
		return &s[count];
}
String &String::operator=(String &s)
{
	if(size!=s.size)
	{
		delete []str;
		str=new char[s.size+1];
		assert(str!='\0');
		size=s.size;
	}
	strcpy(str,s.str);
	return *this;
}
String String::Substr(int index,int count)
{
	int left=size-index;
	String temp("hollow");
	char *p,*q;
	if(index>=size)
		return temp;
	if(count>left)
		count=left;
	delete []temp.str;
	temp.str=new char[count+1];
	assert(temp.str!=NULL);
	p=temp.str;
	q=&str[index];
	for(int i=0;i<count;i++)
		*p++=*q++;
	*p='\0';
	temp.size=count;
	return temp;
}
char *String::find_last(char *p)
{
	int count=0,i=0;
	char *q,*r="there's not the string";
	while(str[count]!='\0')
	{
		count++;
	}
	while(count>=0)
	{
     i=0;
	while(count>=0&&str[count]!=p[i])
	{
		count--;
	}
	q=&str[count];
	if(count<0)
	{
		return r;
	}
	while(p[i]!='\0'&&str[count]!='\0'&&p[i]==str[count])
	{
		count++;
		i++;
	}
	if(i==strlen(p))
		return q;
	else
		count=strlen(str)-strlen(q)-1;
	}
}
int Strcmp(String &a,String &b)
{
	int count=0;
	while(a.str[count]!='\0'&&b.str[count]!='\0')
	{
		if(a.str[count]>b.str[count])
			return 1;
		else if(a.str[count]<b.str[count])
			return -1;
		count++;
	}
	if(a.str[count]=='\0'&&b.str[count]!='\0')
		return -1;
	else if(a.str[count]!='\0'&&b.str[count]=='\0')
		return 1;
	return 0;
}
int *Next(String p)
{
	int m=p.strlen();
	assert(m>0);
	int *N=new int[m];
	assert(N!=0);
	N[0]=0;
	for(int i=1;i<m;i++)
	{
		int k=N[i-1];
		while(k>0&&p[i]!=p[k])
			k=N[k-1];
		if(p[i]==p[k])
			N[i]=k+1;
		else
			N[i]=0;
	}
	return N;
}
int main()
{
	String t("abcaabbcabcaabdab"),s("ab"),w("cd");;
	char *p="abd",*temp;
	s+=w;
	s.show();
	t.show();
/*	int *n;
	n=Next(t);
	cout<<*n<<endl;*/ 
	cout<<Strcmp(s,t)<<endl;
	temp=t.find_last(p);
	cout<<temp<<endl;
	system("pause");
	return 0;
}
