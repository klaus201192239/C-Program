#include<iostream>
#include<vector>
#include<string>
#include<windows.h>
using namespace std;
class Date;
class publication;
class Libarary
{
     
      vector <publication>v;
      static int top;
       public:
             void add(publication *p);
             void show();
};
class Date
{
      int year;
      int month;
      int day;
      public:
             Date(int y,int m,int d):year(y),month(m),day(d){}
             friend ostream &operator<<(ostream &out,Date &da);
};
class publication
{
      char *name;
      Date date;
      public:
             publication();
             publication(char *p,int y,int m,int d):date(y,m,d)
             {
                 name=new char[strlen(p)+1];
                 strcpy(name,p);
             }
             virtual ~publication(){delete name;}
             virtual void show();
              friend ostream &operator<<(ostream &out,publication &p);
};
class book:public publication
{
      char *author;
      public:
             book(char *p,char *q,int y,int m,int d):publication(p,y,m,d)
             {
                 author=new char[strlen(q)+1];
                 strcpy(author,q);
             }
             ~book(){delete author;}
             void show();
};
class magazine:public publication
{
      char *kind;
      public:
             magazine(char *p,char *q,int y,int m,int d):publication(p,y,m,d)
             {
                 kind=new char[strlen(q)+1];
                 strcpy(kind,q);
             }
             ~magazine(){delete kind;}
             void show();
};
class newspaper:public publication
{
      char *kind;
      public:
            newspaper(char *p,char *q,int y,int m,int d):publication(p,y,m,d)
             {
                 kind=new char[strlen(q)+1];
                 strcpy(kind,q);
             }
             ~newspaper(){delete kind;}
             void show();
};
int Libarary::top=0;
ostream &operator<<(ostream &out,Date &da)
{
      out<<da.year<<" "<<da.month<<" "<<da.day<<" ";
      return out;
}
ostream &operator<<(ostream &out,publication &p)
{
        cout<<p.name<<" "<<p.date<<endl;
        return out;
}
void publication::show()
{
     cout<<name<<" "<<date<<" ";
}
void book::show()
{
     publication::show();
     cout<<author<<endl;
}
void magazine::show()
{
     publication::show();
     cout<<kind<<endl;
}
void newspaper::show()
{
     publication::show();
     cout<<kind<<endl;
}
void Libarary::add(publication *p)
{
     v.push_back(*p);
     top++;
}
void Libarary::show()
{
     cout<<"ÊýÁ¿"<<top<<endl;
     for(int i=0;i<top;i++)
        cout<<v.at(i);
}
int main()
{
    Libarary l;
    book b("C++","jiangguangyuan",2012,1,1);
    magazine m("huankan","yuele",2012,6,18);
    newspaper n("xinhuaribao","quanguoxing",2012,6,20);
    l.add(&b);
    l.add(&m);
    l.add(&n);
    l.show();
	system("pause");
	return 0;
}
