#include<stdio.h>
#include<string.h>
#define MIN 50;
typedef struct Hnode{
	char val;
	int left;
	int right;
	int parent;
	int weight;
	int side;
	int visted;
}Hnode;
Hnode H[60];
int index[2];
void seletemintwoval(int n)			//ѡ������Сֵ
{
	int i,j,min;
	for(j=0;j<2;j++)
	{
        min=MIN;
		for(i=0;i<n;i++)
		{
			if(H[i].visted==0&&H[i].weight<=min)
			{
				min=H[i].weight;
				index[j]=i;
			}
		}
		H[index[j]].visted=1;
	}
}
int GenbinoryTree(int n)			//��ѡ����������㹹�ɶ�����
{
	H[n].left=index[0];
    H[n].right=index[1];
	H[n].weight=H[index[0]].weight+H[index[1]].weight;
    H[index[0]].parent=n;
    H[index[0]].side=0;
	H[index[1]].parent=n;
	H[index[1]].side=1;
	n++;
	return (n);
}
int HuffmanTree(int s)					//���ɹ�������
{
	int n=s;
	int count=s;
	while(count>1)
	{
        seletemintwoval(n);
		n=GenbinoryTree(n);
		count--;
	}
	return n;
}
void OutputHcoding(char doc[],int w,int k,int n)		//�������
{
	int i,j[20],p,q,t=0;
	int c[20][20];
	for(i=0;i<n;i++)
	{
		p=i;
		if(H[p].left==-1&&H[p].right==-1)
		{
			printf("%c��Ӧ�ĵı����� :",H[p].val);
			j[t]=0;
			while(H[p].parent!=-1)         //��Ҷ�ӽڵ㿪ʼ��飬���������ջ
			{
				c[t][j[t]]=H[p].side;
				j[t]++;
				p=H[p].parent;
			}
			for(q=j[t]-1;q>=0;q--)         //������Ӻ���ǰ�����ʵ��ջ�Ĺ���
				printf("%d",c[t][q]);
			printf("\n");
			t++;
		}
	}
	printf("��������ĸ���еı���Ϊ��\n");
	for(i=0;i<w;i++)
	{
		for(p=0;p<k;p++)
		{
			if(doc[i]==H[p].val)
			{
				for(q=j[p]-1;q>=0;q--)
				  printf("%d",c[p][q]);
			}
		}
	}
	printf("\n");
}
void Translate(int n)								//����
{
	int i,x,y,N=0;
	char a[30];
	int b[30];
	printf("������'0'��'1'����������������:\n");
	gets(a);
	while(a[N]!='\0')
	{
		b[N]=(int)a[N]%2;
	    N++;
	}
	for(i=0;i<n;i++)
	{
		if(H[i].parent==-1)
		{
			x=i;
			y=x;
		}
	}
	printf("����ĸ���е�����Ϊ��\n");
    for(i=0;i<N;i++)
	{
		if(b[i]==0) x=H[x].left;
		if(b[i]==1) x=H[x].right;
        if(H[x].left==-1&&H[x].right==-1)
		{
			printf("%c",H[x].val);
			x=y;    
		}
	}
	printf("\n");
}
void main()
{
	char doc[30];
	int t=0,k=0,count=0;
	int i,j,n;
	int d[30][26];
	int sum[26]={0};
	char b[26];
	for(i=0;i<26;i++)
	{
		b[i]='a'+i;
	}
	for(i=0;i<20;i++)
	{
		H[i].left=H[i].right=H[i].parent=H[i].side=-1;//��ʼ�����ڵ�
	    H[i].visted=0;
	}
	printf("���������ڱ������ĸ����:\n");
    gets(doc);
	while(doc[t]!='\0')
	{
		t++;
	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<26;j++)
		{
			if(doc[i]==b[j]) 
			{
				d[i][j]=1;
				count++;
			}
			else d[i][j]=0;
		}
	}
	for(j=0;j<26;j++)
	{
		for(i=0;i<t;i++)               //ͳ��Ȩֵ
			sum[j]=sum[j]+d[i][j];
		if(sum[j]!=0)
		{
			H[k].weight=sum[j];
            H[k].val=b[j];
			k++;
		}
	}
	n=HuffmanTree(k);
	for(i=0;i<k;i++)
		printf("%c���ֵĴ���Ϊ��%d\n",H[i].val,H[i].weight);
    OutputHcoding(doc,t,k,n);
	Translate(n);
}
