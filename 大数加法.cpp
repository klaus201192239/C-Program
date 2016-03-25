#include<stdio.h>
int main()
{
    char a[101],aa[101];
    int b[100]={0},bb[100]={0},c[101]={0};
    int i=0,j=0,k=0,m=100;
    printf("please input number:\n");
    while(1)
    {
        a[i]=getchar();
        if(a[i]=='\n')
        {
           break;
        }
        i++;
    }
    while((i-1)>=0)
    {
         b[j]=a[i-1]-'0';
         j++;
         i--;
    }
    i=0;j=0;
     while(1)
    {
        aa[i]=getchar();
        if(aa[i]=='\n')
        {
           break;
        }
        i++;
    }
     while((i-1)>=0)
    {
         bb[j]=aa[i-1]-'0';
         j++;
         i--;
    }
    while(k<=99)
    {
        c[k]=c[k]+b[k]+bb[k];
        if(c[k]>=10)
        {
           c[k]=c[k]-10;
           c[k+1]++;
        }
        k++;
    }
    while(c[m]==0)
    {
        m--;
    }
    while(m>=0)
    {
        printf("%d",c[m]);
        m--;
    }
    printf("\n");
    return 0;
}
