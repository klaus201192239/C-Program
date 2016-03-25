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
	//返回1代表移动合法；返回0代表移动不合法。
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
	//定义棋盘
	Qizi *q[11][10];
	//定义棋子
    Che che_red;Ma ma_red;Pao pao_red;Xiang xiang_red;Shi shi_red; Shuai shuai_red;Bing bing_red;
    Che che_black; Ma ma_black;Pao pao_black;Xiang xiang_black;Shi shi_black; Jiang jiang_black;Zu zu_black;
	Space space;
	Qipan();
	int exist(int x,int y,string color);//坐标x、y上color颜色棋子
	void show();
};
int operator ==(Qizi &Q1,Qizi &Q2){ 
    if(Q1.name==Q2.name&&Q1.color==Q2.color)       
        return 1;
    else
        return 0;
}
Qizi::Qizi(string name,string color):name(name),color(color){}
//车的实现
Che::Che(string color):Qizi("che",color){}
int Che::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int i;
	//起点、终点不在同一条直线上
	if((start_x!=end_x) && (start_y!=end_y))
	{
	    cout<<"车必须走直线"<<endl;
		return 0;
	}
	//横向移动时，中间是否有棋子。
	if(start_x==end_x)
	{
	    if(start_y<end_y)
		{
			for(i=start_y+1;i<end_y;i++)
				if(qp.q[start_x][i]->name!="   ")
				{
					cout<<"水平线路上有棋子"<<endl;
					return 0;
				}
		}
		else
		{
			for(i=end_y+1;i<start_y;i++)
				if(qp.q[start_x][i]->name!="   ")
				{
					cout<<"水平线路上有棋子"<<endl;
					return 0;
				}
		}
	}
	//纵向移动时，中间是否有棋子。
    if(start_y==end_y)
	{
	    if(start_x<end_x)
		{
			for(i=start_x+1;i<end_x;i++)
				if(qp.q[i][start_y]->name!="   ")
				{
					cout<<"垂直线路上有棋子"<<endl;
					return 0;
				}
		}
		else
		{
			for(i=end_x+1;i<start_x;i++)
				if(qp.q[i][start_y]->name!="   ")
				{
					cout<<"垂直线路上有棋子"<<endl;
					return 0;
				}
		}
	}
	return 1;
}
//马的实现
Ma::Ma(string color):Qizi("ma",color){}
int Ma::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int a=end_x-start_x;
    int b=end_y-start_y;
    if(!(a*b==2||a*b==-2))
    {
        cout<<"马必须走日"<<endl;
        return 0;
    }
    if((a==1||a==-1)&&b==2&&qp.q[start_x][start_y+1]->name!="   ")
    {
        cout<<"蹩腿!"<<endl;
        return 0;
    }
     if((a==1||a==-1)&&b==-2&&qp.q[start_x][start_y-1]->name!="   ")
    {
        cout<<"蹩腿!"<<endl;
        return 0;
    }
     if((b==1||b==-1)&&a==2&&qp.q[start_x+1][start_y]->name!="   ")
    {
        cout<<"蹩腿!"<<endl;
        return 0;
    }
     if((b==1||b==-1)&&a==-2&&qp.q[start_x-1][start_y]->name!="   ")
    {
        cout<<"蹩腿!"<<endl;
        return 0;
    }
    return 1;
}
//炮的实现
Pao::Pao(string color):Qizi("pao",color){C=color;}
int Pao::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int i;
	//起点、终点不在同一条直线上
	if((start_x!=end_x) && (start_y!=end_y))
	{
	    cout<<"炮必须走直线"<<endl;
		return 0;
	}
	//横向移动时，中间是否有棋子。
	if(start_x==end_x)
	{
	    if(start_y<end_y)
		{
			for(i=start_y+1;i<end_y;i++){
				if(qp.q[start_x][i]->name!="   "&&qp.exist(end_x,end_y,C))
				{
					cout<<"水平线路上有棋子"<<endl;
					return 0;
				}
					if(qp.q[start_x][i]->name!="   "&&qp.q[start_x][end_y]->name=="   ")
				{
					cout<<"水平线路上有棋子"<<endl;
					return 0;
				}
                }
		}
		else
		{
			for(i=end_y+1;i<start_y;i++)
				if(qp.q[start_x][i]->name!="   "&&((qp.exist(end_x,end_y,C)||qp.q[start_x][end_y]->name=="   ")))
				{
					cout<<"水平线路上有棋子"<<endl;
					return 0;
				}
		}
	}
	//纵向移动时，中间是否有棋子。
    if(start_y==end_y)
	{
	    if(start_x<end_x)
		{
			for(i=start_x+1;i<end_x;i++)
				if(qp.q[i][start_y]->name!="   "&&((qp.exist(end_x,end_y,C)||qp.q[end_x][end_y]->name=="   ")))
				{
					cout<<"垂直线路上有棋子"<<endl;
					return 0;
				}
		}
		else
		{
			for(i=end_x+1;i<start_x;i++)
				if(qp.q[i][start_y]->name!="   "&&((qp.exist(end_x,end_y,C)||qp.q[end_x][end_y]->name=="   ")))
				{
					cout<<"垂直线路上有棋子"<<endl;
					return 0;
				}
		}
	}
	return 1;
}
//像的实现
Xiang::Xiang(string color):Qizi("xiang",color){C=color;}
int Xiang::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int a=end_x-start_x;
    int b=end_y-start_y;
    if(!(fabs(a)==2&&fabs(b)==2))
    {
        cout<<"象必须走田"<<endl;
        return 0;
    }
    if(b==2&&a==-2&&qp.q[start_x-1][start_y+1]->name!="   ")
    {
        cout<<"象眼有子"<<endl;
        return 0;
    }
    if(b==2&&a==2&&qp.q[start_x+1][start_y+1]->name!="   ")
    {
        cout<<"象眼有子"<<endl;
        return 0;
    }                                                                        
    if(b==-2&&a==2&&qp.q[start_x+1][start_y-1]->name!="   ")
    {
        cout<<"象眼有子"<<endl;
        return 0;
    }  
    if(b==-2&&a==-2&&qp.q[start_x-1][start_y-1]->name!="   ")
    {
        cout<<"象眼有子"<<endl;
        return 0;
    }  
    if(C=="R"&&end_x>5) 
    {
         cout<<"象不能过河"<<endl;
         return 0;
    }
    if(C=="B"&&end_x<6) 
    {
         cout<<"象不能过河"<<endl;
         return 0;
    }
    return 1;
}	
//士的实现
Shi::Shi(string color):Qizi("shi",color){C=color;}
int Shi::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int a=end_x-start_x;
    int b=end_y-start_y;
    if(C=="R"){
    if(!(end_x<4&&end_x>0&&end_y<7&&end_y>3))
    {
        cout<<"越界了"<<endl;
        return 0;
    }
    }
    if(C=="B"){
    if(!(end_x<11&&end_x>7&&end_y<7&&end_y>3))
    {
        cout<<"越界了"<<endl;
        return 0;
    }
    }
    if(!(fabs(a)*fabs(b)==1))
    {
    cout<<"必须斜着走"<<endl;
    return 0;
    }
    return 1;
}	
//帅的实现
Shuai::Shuai(string color):Qizi("shuai",color){}
int Shuai::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
     int a=end_x-start_x;
     int b=end_y-start_y;
     if(!(end_x<4&&end_x>0&&end_y<7&&end_y>3))
     {
           cout<<"越界了"<<endl;
           return 0;
     }
      if(!(fabs(a)+fabs(b)==1))
      {
           cout<<"走一步且不走斜线"<<endl;
           return 0;
      }
      return 1;
}	
//将的实现
Jiang::Jiang(string color):Qizi("jiang",color){}
int Jiang::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
     int a=end_x-start_x;
     int b=end_y-start_y;
     if(!(end_x<11&&end_x>7&&end_y<7&&end_y>3))
     {
           cout<<"越界了"<<endl;
           return 0;
      }
      if(!(fabs(a)+fabs(b)==1))
      {
            cout<<"走一步且不走斜线"<<endl;
            return 0;
      }
      return 1;
}	
//兵的实现
Bing::Bing(string color):Qizi("bing",color){}
int Bing::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
     int a=end_x-start_x;
     int b=end_y-start_y;
     if(!((fabs(a)+fabs(b)==1)&&a>=0))
     {
           cout<<"兵不能回头"<<endl;
           return 0;
     }
     if(start_x<6&&a==0)
     {
            cout<<"现在还不能走水平线"<<endl;
            return 0;
     }
     return 1;
}	
//卒的实现
Zu::Zu(string color):Qizi("zu",color){}
int Zu::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
     int a=end_x-start_x;
     int b=end_y-start_y;
     if(!((fabs(a)+fabs(b)==1)&&a<=0))
     {
         cout<<"卒不能回头"<<endl;
         return 0;
      }
     if(start_x>5&&a==0)
     {
         cout<<"现在还不能走水平线"<<endl;
         return 0;
     }
     return 1;
}
//空棋子的实现
Space::Space(string color):Qizi("   ",color){}
int Space::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
  return 1;
}
//棋盘实现
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
		//赋值红方
	    q[1][1]=q[1][9]=&che_red;
	    q[1][2]=q[1][8]=&ma_red;
	    q[1][3]=q[1][7]=&xiang_red;
	    q[1][4]=q[1][6]=&shi_red;
	    q[1][5]=&shuai_red;
        q[3][2]=q[3][8]=&pao_red;
	    for(i=1;i<=10;i=i+2) q[4][i]=&bing_red;
	    //赋值黑方
	    q[10][1]=q[10][9]=&che_black;
	    q[10][2]=q[10][8]=&ma_black;
	    q[10][3]=q[10][7]=&xiang_black;
	    q[10][4]=q[10][6]=&shi_black;
	    q[10][5]=&jiang_black;
        q[8][2]=q[8][8]=&pao_black;
	    for(i=1;i<=10;i=i+2) q[7][i]=&zu_black;
}
int Qipan::exist(int x,int y,string color)//坐标x、y上color颜色棋子
{
	    if(q[x][y]->color==color)
			return 1;
		else
			return 0;
}
void Qipan::show()
{
	    int i,j;
        for(i=0;i<=9;i++)//输出头行坐标 
		{
			cout.width(7);
		    cout<<i;
		}
		cout<<endl;
		for(i=1;i<=10;i++)
		{
		    cout.width(7);
			cout<<i;  //输出头列坐标
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
			cout<<"请输入第"<<step<<"步需要移动"<<color<<"色棋子的原始位置坐标（x和y）："<<endl;
			cin>>start_x>>start_y;
			if(start_x>10||start_x<1||start_y>9||start_y<1)
                  throw start_x;
             count=-1;
            }catch(int){
                   cout<<"输入数据不对!"<<endl;            
            }
            }
			if(!qipan.exist(start_x,start_y,color))
			{
				cout<<"坐标（"<<start_x<<"，"<<start_y<<"）没有"<<color<<"色棋子,本步重走"<<endl;
			    continue;
			}
			count=2;
			while(count==2){
            try{
			cout<<"请输入第"<<step<<"步需要移动"<<color<<"色棋子的目的位置坐标（x和y）："<<endl;
			cin>>end_x>>end_y;
				if(end_x>10||end_x<1||end_y>9||end_y<1)
                  throw end_x;
             count=-1;
            }catch(int){
                   cout<<"输入数据不对!"<<endl;            
            }
            }
			if(qipan.exist(end_x,end_y,color))
			{
				cout<<"坐标（"<<end_x<<"，"<<end_y<<"） 有"<<color<<"色棋子,本步重走"<<endl;
                continue;		
			}
			if(!qipan.q[start_x][start_y]->move(qipan,start_x,start_y,end_x,end_y))
			{
				cout<<"移动规则不符，本步重走"<<endl;
				continue;
			}
			//移动
			if(*qipan.q[end_x][end_y]==shuai)
			{
                qipan.q[end_x][end_y]=qipan.q[start_x][start_y];
			    qipan.q[start_x][start_y]=&qipan.space;
				system("cls");
			    qipan.show();
			    cout<<"黑方（B）胜!"<<endl;
		    	system("pause");
                return 1;                                                    
	         } 
             if(*qipan.q[end_x][end_y]==jiang)
			 {
                qipan.q[end_x][end_y]=qipan.q[start_x][start_y];
			    qipan.q[start_x][start_y]=&qipan.space;
				system("cls");
		    	qipan.show();
			    cout<<"红方（R）胜"<<endl;
		    	system("pause");
                return 1;                                                
	         }   
             temp_qipan.q[end_x][end_y]=qipan.q[end_x][end_y];   	
			 qipan.q[end_x][end_y]=qipan.q[start_x][start_y];
			 qipan.q[start_x][start_y]=&qipan.space;
			//刷新棋盘
			 system("cls");
			 qipan.show();
			 cout<<"想缓棋吗"<<endl;
			 cout<<"如果想请按    ‘1’"<<endl;
			 cout<<"如果不想请按  ‘2’"<<endl;
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
