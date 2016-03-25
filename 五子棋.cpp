#include<iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>
#define N 4
using namespace std;
class qipan
{
public:
	char qizi[15][15];
	char color[2];
	qipan();
	void show();
	int over(int i,int j);
};
qipan::qipan()
{
	color[0]='B';
	color[1]='R';
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++)
		{
				qizi[i][j]=' ';
		}
	}
}
void qipan::show()
{
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++)
		{
			if(i==0)
			{
				cout<<j<<"   ";
			}
			else if(j==0&&i!=0)
			{
				cout<<i<<"  ";
			}
			else
				cout<<qizi[i][j]<<"   ";
		}
		cout<<endl;
		cout<<endl;
	}
}
int qipan::over(int i, int j)
{
	int k=i,l=j;
	while(j<15&&j-4>0){
	if(qizi[i][j]==qizi[i][j-1]&&qizi[i][j-1]==qizi[i][j-2]&&qizi[i][j]!=' '&&qizi[i][j-2]==qizi[i][j-3]&&qizi[i][j-3]==qizi[i][j-4])
		return 1;
	j++;
	}
	j=l;
	while(i-4>0&&i<15){
	if(qizi[i][j]==qizi[i-1][j]&&qizi[i-1][j]==qizi[i-2][j]&&qizi[i][j]!=' '&&qizi[i-2][j]==qizi[i-3][j]&&qizi[i-4][j]==qizi[i-3][j])
		return 1;
	i++;
	}
	i=k;j=l;
	while(i>0&&j>0&&i+4<15&&j+4<15){
	if(qizi[i][j]==qizi[i+1][j+1]&&qizi[i+1][j+1]==qizi[i+2][j+2]&&qizi[i][j]!=' '&&qizi[i+2][i+2]==qizi[i+3][i+3]&&qizi[i+3][i+3]==qizi[i+4][i+4])
		return 1;
	i--;j--;
	}
	i=k;j=l;
	while(i>0&&j-4>0&&i+4<15&&j<15){
		if(qizi[i][j]==qizi[i-1][j+1]&&qizi[i-1][j+1]==qizi[i-2][j+2]&&qizi[i][j]!=' '&&qizi[i-2][j+2]==qizi[i-3][j+3]&&qizi[i-3][j+3]==qizi[i-4][j-4])
		return 1;
	i++;j--;
	}
	return 0;
}
int main()
{
	qipan qipa;
	int i,j,k=0,counter=2,m=1;
	qipa.show();
	while(1){
    m=1;
	k++;
	while(m==1){
	cout<<"输入"<<qipa.color[k%2]<<"方坐标（x,y）"<<endl;
	while(counter==2){
	try{
	cin>>i>>j;
	if(i<0||i>15||j<0||j>15){
		cout<<"输入数据不对，重新输入"<<endl;
		throw i;
	}
	if(qipa.qizi[i][j]!=' '){
		cout<<"此处有棋子，重新输入"<<endl;
		throw j;
	}
	counter=-1;
	}catch(int ){}
	}
	counter=2;
	qipa.qizi[i][j]=qipa.color[k%2];
	system("cls");
	qipa.show();
	if(qipa.over(i,j))
	{
		cout<<qipa.color[k%2]<<"  方获胜!"<<endl;
		system("pause");
        return 1;
	}
    cout<<"想缓棋吗"<<endl;
    cout<<"如果想请按    ‘1’"<<endl;
    cout<<"如果不想请按  ‘2’"<<endl;
	cin>>m;
	system("cls");
	qipa.show();
	if(m==1)
	{
        	qipa.qizi[i][j]=' ';
       		system("cls");
	        qipa.show();
    }
    }
	}
	system("pause");
	return 0;
}
