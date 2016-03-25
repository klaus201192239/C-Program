#include<iostream>
#include<windows.h>
#include<string>
#include<stdlib.h>
#include<cmath>
using namespace std;
class Qipan;
class Qizi{
public:
    string  name;
    string color;
	Qizi(string name,string color);
	//����1�����ƶ��Ϸ�������0�����ƶ����Ϸ���
    virtual int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)=0;
    friend int operator ==(Qizi &Q1,Qizi &Q2);
};
class Che:public Qizi{
public:
	Che(string color);
	int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y);
};
class Ma:public Qizi{
public:
	Ma(string color);
	int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y);
};
class Pao:public Qizi{
public:
       string C;
	Pao(string color);
	int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y);
};
class Xiang:public Qizi{
public:
	Xiang(string color);
	string C;
	int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y);
};
class Shi:public Qizi{
public:
	Shi(string color);
	string C;
	int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y);
};
class Shuai:public Qizi{
public:
	Shuai(string color="R");
	int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y);
};
class Jiang:public Qizi{
public:
	Jiang(string color="B");
	int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y);
};
class Bing:public Qizi{
public:
	Bing(string color="R");
	int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y);
};
class Zu:public Qizi{
public:
	Zu(string color="B");
	int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y);
};
class Space:public Qizi{
public:
	Space(string color="  ");
	int move(Qipan &qp, int start_x,int start_y, int end_x,int end_y);
};
class Qipan{
public:
	//��������
	Qizi *q[11][10];
	//��������
    Che che_red;Ma ma_red;Pao pao_red;Xiang xiang_red;Shi shi_red; Shuai shuai_red;Bing bing_red;
    Che che_black; Ma ma_black;Pao pao_black;Xiang xiang_black;Shi shi_black; Jiang jiang_black;Zu zu_black;
	Space space;
	Qipan();
	int exist(int x,int y,string color);//����x��y��color��ɫ����
	void show();
};
int operator ==(Qizi &Q1,Qizi &Q2){ 
    if(Q1.name==Q2.name&&Q1.color==Q2.color)       
        return 1;
    else
        return 0;
}
Qizi::Qizi(string name,string color):name(name),color(color){}
//����ʵ��
Che::Che(string color):Qizi("che",color){}
int Che::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int i;
	//��㡢�յ㲻��ͬһ��ֱ����
	if((start_x!=end_x) && (start_y!=end_y))
	{
	    cout<<"��������ֱ��"<<endl;
		return 0;
	}
	//�����ƶ�ʱ���м��Ƿ������ӡ�
	if(start_x==end_x)
	{
	    if(start_y<end_y)
		{
			for(i=start_y+1;i<end_y;i++)
				if(qp.q[start_x][i]->name!="   ")
				{
					cout<<"ˮƽ��·��������"<<endl;
					return 0;
				}
		}
		else
		{
			for(i=end_y+1;i<start_y;i++)
				if(qp.q[start_x][i]->name!="   ")
				{
					cout<<"ˮƽ��·��������"<<endl;
					return 0;
				}
		}
	}
	//�����ƶ�ʱ���м��Ƿ������ӡ�
    if(start_y==end_y)
	{
	    if(start_x<end_x)
		{
			for(i=start_x+1;i<end_x;i++)
				if(qp.q[i][start_y]->name!="   ")
				{
					cout<<"��ֱ��·��������"<<endl;
					return 0;
				}
		}
		else
		{
			for(i=end_x+1;i<start_x;i++)
				if(qp.q[i][start_y]->name!="   ")
				{
					cout<<"��ֱ��·��������"<<endl;
					return 0;
				}
		}
	}
	return 1;
}
//���ʵ��
Ma::Ma(string color):Qizi("ma",color){}
int Ma::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int a=end_x-start_x;
    int b=end_y-start_y;
    if(!(a*b==2||a*b==-2))
    {
        cout<<"���������"<<endl;
        return 0;
    }
    if((a==1||a==-1)&&b==2&&qp.q[start_x][start_y+1]->name!="   ")
    {
        cout<<"����!"<<endl;
        return 0;
    }
     if((a==1||a==-1)&&b==-2&&qp.q[start_x][start_y-1]->name!="   ")
    {
        cout<<"����!"<<endl;
        return 0;
    }
     if((b==1||b==-1)&&a==2&&qp.q[start_x+1][start_y]->name!="   ")
    {
        cout<<"����!"<<endl;
        return 0;
    }
     if((b==1||b==-1)&&a==-2&&qp.q[start_x-1][start_y]->name!="   ")
    {
        cout<<"����!"<<endl;
        return 0;
    }
    return 1;
}
//�ڵ�ʵ��
Pao::Pao(string color):Qizi("pao",color){C=color;}
int Pao::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int i;
	//��㡢�յ㲻��ͬһ��ֱ����
	if((start_x!=end_x) && (start_y!=end_y))
	{
	    cout<<"�ڱ�����ֱ��"<<endl;
		return 0;
	}
	//�����ƶ�ʱ���м��Ƿ������ӡ�
	if(start_x==end_x)
	{
	    if(start_y<end_y)
		{
			for(i=start_y+1;i<end_y;i++){
				if(qp.q[start_x][i]->name!="   "&&qp.exist(end_x,end_y,C))
				{
					cout<<"ˮƽ��·��������"<<endl;
					return 0;
				}
					if(qp.q[start_x][i]->name!="   "&&qp.q[start_x][end_y]->name=="   ")
				{
					cout<<"ˮƽ��·��������"<<endl;
					return 0;
				}
                }
		}
		else
		{
			for(i=end_y+1;i<start_y;i++)
				if(qp.q[start_x][i]->name!="   "&&((qp.exist(end_x,end_y,C)||qp.q[start_x][end_y]->name=="   ")))
				{
					cout<<"ˮƽ��·��������"<<endl;
					return 0;
				}
		}
	}
	//�����ƶ�ʱ���м��Ƿ������ӡ�
    if(start_y==end_y)
	{
	    if(start_x<end_x)
		{
			for(i=start_x+1;i<end_x;i++)
				if(qp.q[i][start_y]->name!="   "&&((qp.exist(end_x,end_y,C)||qp.q[end_x][end_y]->name=="   ")))
				{
					cout<<"��ֱ��·��������"<<endl;
					return 0;
				}
		}
		else
		{
			for(i=end_x+1;i<start_x;i++)
				if(qp.q[i][start_y]->name!="   "&&((qp.exist(end_x,end_y,C)||qp.q[end_x][end_y]->name=="   ")))
				{
					cout<<"��ֱ��·��������"<<endl;
					return 0;
				}
		}
	}
	return 1;
}
//���ʵ��
Xiang::Xiang(string color):Qizi("xiang",color){C=color;}
int Xiang::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int a=end_x-start_x;
    int b=end_y-start_y;
    if(!(fabs(a)==2&&fabs(b)==2))
    {
        cout<<"���������"<<endl;
        return 0;
    }
    if(b==2&&a==-2&&qp.q[start_x-1][start_y+1]->name!="   ")
    {
        cout<<"��������"<<endl;
        return 0;
    }
    if(b==2&&a==2&&qp.q[start_x+1][start_y+1]->name!="   ")
    {
        cout<<"��������"<<endl;
        return 0;
    }                                                                        
    if(b==-2&&a==2&&qp.q[start_x+1][start_y-1]->name!="   ")
    {
        cout<<"��������"<<endl;
        return 0;
    }  
    if(b==-2&&a==-2&&qp.q[start_x-1][start_y-1]->name!="   ")
    {
        cout<<"��������"<<endl;
        return 0;
    }  
    if(C=="R"&&end_x>5) 
    {
         cout<<"���ܹ���"<<endl;
         return 0;
    }
    if(C=="B"&&end_x<6) 
    {
         cout<<"���ܹ���"<<endl;
         return 0;
    }
    return 1;
}	
//ʿ��ʵ��
Shi::Shi(string color):Qizi("shi",color){C=color;}
int Shi::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int a=end_x-start_x;
    int b=end_y-start_y;
    if(C=="R"){
    if(!(end_x<4&&end_x>0&&end_y<7&&end_y>3))
    {
        cout<<"Խ����"<<endl;
        return 0;
    }
    }
    if(C=="B"){
    if(!(end_x<11&&end_x>7&&end_y<7&&end_y>3))
    {
        cout<<"Խ����"<<endl;
        return 0;
    }
    }
    if(!(fabs(a)*fabs(b)==1))
    {
    cout<<"����б����"<<endl;
    return 0;
    }
    return 1;
}	
//˧��ʵ��
Shuai::Shuai(string color):Qizi("shuai",color){}
int Shuai::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
     int a=end_x-start_x;
     int b=end_y-start_y;
     if(!(end_x<4&&end_x>0&&end_y<7&&end_y>3))
     {
           cout<<"Խ����"<<endl;
           return 0;
     }
      if(!(fabs(a)+fabs(b)==1))
      {
           cout<<"��һ���Ҳ���б��"<<endl;
           return 0;
      }
      return 1;
}	
//����ʵ��
Jiang::Jiang(string color):Qizi("jiang",color){}
int Jiang::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
     int a=end_x-start_x;
     int b=end_y-start_y;
     if(!(end_x<11&&end_x>7&&end_y<7&&end_y>3))
     {
           cout<<"Խ����"<<endl;
           return 0;
      }
      if(!(fabs(a)+fabs(b)==1))
      {
            cout<<"��һ���Ҳ���б��"<<endl;
            return 0;
      }
      return 1;
}	
//����ʵ��
Bing::Bing(string color):Qizi("bing",color){}
int Bing::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
     int a=end_x-start_x;
     int b=end_y-start_y;
     if(!((fabs(a)+fabs(b)==1)&&a>=0))
     {
           cout<<"�����ܻ�ͷ"<<endl;
           return 0;
     }
     if(start_x<6&&a==0)
     {
            cout<<"���ڻ�������ˮƽ��"<<endl;
            return 0;
     }
     return 1;
}	
//���ʵ��
Zu::Zu(string color):Qizi("zu",color){}
int Zu::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
     int a=end_x-start_x;
     int b=end_y-start_y;
     if(!((fabs(a)+fabs(b)==1)&&a<=0))
     {
         cout<<"�䲻�ܻ�ͷ"<<endl;
         return 0;
      }
     if(start_x>5&&a==0)
     {
         cout<<"���ڻ�������ˮƽ��"<<endl;
         return 0;
     }
     return 1;
}
//�����ӵ�ʵ��
Space::Space(string color):Qizi("   ",color){}
int Space::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
  return 1;
}
//����ʵ��
Qipan::Qipan():che_red("R"),ma_red("R"),pao_red("R"),xiang_red("R"),shi_red("R"),shuai_red("R"),
		bing_red("R"),che_black("B"),ma_black("B"),pao_black("B"),xiang_black("B"),
		shi_black("B"),jiang_black("B"),zu_black("B"),space()
{
		int i,j;
	    for(i=1;i<=10;i++)
			for(j=1;j<=9;j++)
			{
			    q[i][j]=&space;
			}
		//��ֵ�췽
	    q[1][1]=q[1][9]=&che_red;
	    q[1][2]=q[1][8]=&ma_red;
	    q[1][3]=q[1][7]=&xiang_red;
	    q[1][4]=q[1][6]=&shi_red;
	    q[1][5]=&shuai_red;
        q[3][2]=q[3][8]=&pao_red;
	    for(i=1;i<=10;i=i+2) q[4][i]=&bing_red;
	    //��ֵ�ڷ�
	    q[10][1]=q[10][9]=&che_black;
	    q[10][2]=q[10][8]=&ma_black;
	    q[10][3]=q[10][7]=&xiang_black;
	    q[10][4]=q[10][6]=&shi_black;
	    q[10][5]=&jiang_black;
        q[8][2]=q[8][8]=&pao_black;
	    for(i=1;i<=10;i=i+2) q[7][i]=&zu_black;
}
int Qipan::exist(int x,int y,string color)//����x��y��color��ɫ����
{
	    if(q[x][y]->color==color)
			return 1;
		else
			return 0;
}
void Qipan::show()
{
	    int i,j;
        for(i=0;i<=9;i++)//���ͷ������ 
		{
			cout.width(7);
		    cout<<i;
		}
		cout<<endl;
		for(i=1;i<=10;i++)
		{
		    cout.width(7);
			cout<<i;  //���ͷ������
			for(j=1;j<=9;j++)
			{
			    cout.width(7);
				cout<<q[i][j]->name+q[i][j]->color;
			}
			cout<<endl;
		}
}
int main()
{
    Qipan qipan;
    Qipan temp_qipan;
    Jiang jiang;
    Shuai shuai;
	int start_x,start_y,end_x,end_y;
	qipan.show();
	string color; 
	int step=1,count,m=1;
	string colors[2]={"B","R"};
		while(1)
		{
            m=1;
            while(m==1){
		    color=colors[step%2];
		    count=1;
		    while(count==1){
		    try{
			cout<<"�������"<<step<<"����Ҫ�ƶ�"<<color<<"ɫ���ӵ�ԭʼλ�����꣨x��y����"<<endl;
			cin>>start_x>>start_y;
			if(start_x>10||start_x<1||start_y>9||start_y<1)
                  throw start_x;
             count=-1;
            }catch(int){
                   cout<<"�������ݲ���!"<<endl;            
            }
            }
			if(!qipan.exist(start_x,start_y,color))
			{
				cout<<"���꣨"<<start_x<<"��"<<start_y<<"��û��"<<color<<"ɫ����,��������"<<endl;
			    continue;
			}
			count=2;
			while(count==2){
            try{
			cout<<"�������"<<step<<"����Ҫ�ƶ�"<<color<<"ɫ���ӵ�Ŀ��λ�����꣨x��y����"<<endl;
			cin>>end_x>>end_y;
				if(end_x>10||end_x<1||end_y>9||end_y<1)
                  throw end_x;
             count=-1;
            }catch(int){
                   cout<<"�������ݲ���!"<<endl;            
            }
            }
			if(qipan.exist(end_x,end_y,color))
			{
				cout<<"���꣨"<<end_x<<"��"<<end_y<<"�� ��"<<color<<"ɫ����,��������"<<endl;
                continue;		
			}
			if(!qipan.q[start_x][start_y]->move(qipan,start_x,start_y,end_x,end_y))
			{
				cout<<"�ƶ����򲻷�����������"<<endl;
				continue;
			}
			//�ƶ�
			if(*qipan.q[end_x][end_y]==shuai)
			{
                qipan.q[end_x][end_y]=qipan.q[start_x][start_y];
			    qipan.q[start_x][start_y]=&qipan.space;
				system("cls");
			    qipan.show();
			    cout<<"�ڷ���B��ʤ!"<<endl;
		    	system("pause");
                return 1;                                                    
	         } 
             if(*qipan.q[end_x][end_y]==jiang)
			 {
                qipan.q[end_x][end_y]=qipan.q[start_x][start_y];
			    qipan.q[start_x][start_y]=&qipan.space;
				system("cls");
		    	qipan.show();
			    cout<<"�췽��R��ʤ"<<endl;
		    	system("pause");
                return 1;                                                
	         }   
             temp_qipan.q[end_x][end_y]=qipan.q[end_x][end_y];   	
			 qipan.q[end_x][end_y]=qipan.q[start_x][start_y];
			 qipan.q[start_x][start_y]=&qipan.space;
			//ˢ������
			 system("cls");
			 qipan.show();
			 cout<<"�뻺����"<<endl;
			 cout<<"������밴    ��1��"<<endl;
			 cout<<"��������밴  ��2��"<<endl;
			 cin>>m;
             system("cls");
	         qipan.show();
			 if(m==1)
			 {
                qipan.q[start_x][start_y]=qipan.q[end_x][end_y];
                qipan.q[end_x][end_y]=temp_qipan.q[end_x][end_y];
                system("cls");
			    qipan.show();
             }
             }
			 step++;
		}
	system("pause");
	return 0;
}
