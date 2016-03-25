#include<iostream>
#include<windows.h>
using namespace std;
#define N 6
int k,j;
void build(int *a,int i,int n)
{
    int tmp;
    k=i;
    j=2*k+1;
    while(j<=n)
	{
        if(j<n && a[j]<a[j+1])
            j++;
        if(a[k]>=a[j])
			break;
        tmp=a[k];
        a[k]=a[j];
        a[j]=tmp;        
        k=j;
        j=2*j+1;
    }
}
int main()
{
    int a[50],i,tmp,sum,num,len;
	cout<<"输入待排序数组个数"<<endl;
	cin>>len;
	cout<<"输入待排序数组"<<endl;
    for(i=0;i<len;i++)
		cin>>a[i];    
    tmp=1;sum=0;
    while(sum+tmp<=len)
	{
        sum+=tmp;    
        tmp*=2;
    }
	cout<<"初始数组"<<endl;
	for(i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;  
    for(i=sum-1;i>=0;i--)
        build(a,i,len-1);       
    for(i=0;i<len-1;i++){
        tmp=a[0];
        a[0]=a[len-1-i];
        a[len-1-i]=tmp;
        build(a,0,len-2-i);
	}
	cout<<"排序结果"<<endl;
	for(i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}
