typedef struct				/*�����������Ͷ���*/
{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree; 
typedef char **HuffmanCode;	/*��Ź���������*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<iostream.h>
#define infinity 10000			/*����һ�����޴��ֵ*/

typedef char **HuffmanCode; /*��Ź���������*/
int Min(HuffmanTree t,int n);
void Select(HuffmanTree *t,int n,int *s1,int *s2);
void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n);
void main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w,n,i;
	cout<<"������Ҷ�ӽ��ĸ���: ";
	cin>>n;
	w=(int*)malloc(n*sizeof(int));		/*Ϊn������Ȩֵ�����ڴ�ռ�*/
	for(i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"������Ȩֵ:";
		cin>>w[i];
	}
	HuffmanCoding(&HT,&HC,w,n);
	for(i=1;i<=n;i++)
	{
		cout<<"ȨֵΪ"<<w[i-1]<<"�Ĺ���������:";
		cout<<HC[i]<<endl;
	}
	/*�ͷ��ڴ�ռ�*/
	for(i=1;i<=n;i++)
		free(HC[i]);
	free(HC);
	free(HT);
}
void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n)
/*�����������HT�����������ı�������HC�У�wΪn���ַ���Ȩֵ*/
{ 
	int m,i,s1,s2,start;
	unsigned int c,f;
	HuffmanTree p;
	char *cd;
	if(n<=1)
		return;
	m=2*n-1;
	*HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode)); /*�������Ԫδ��*/
	for(p=*HT+1,i=1;i<=n;i++,p++,w++)				/*��ʼ��n��Ҷ�ӽ��*/
	{
		(*p).weight=*w;
		(*p).parent=0;
		(*p).lchild=0;
		(*p).rchild=0;
	}
	for(;i<=m;i++,p++)			/*��n-1����Ҷ�ӽ���˫�׽���ʼ����Ϊ0*/
		(*p).parent=0;
	for(i=n+1;i<=m;++i)			/*�����������*/
	{ 
		Select(HT,i-1,&s1,&s2);	/*��������Ȩֵ��С���������*/
		(*HT)[s1].parent=(*HT)[s2].parent=i;
		(*HT)[i].lchild=s1;
		(*HT)[i].rchild=s2;
		(*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
	}
	/*��Ҷ�ӽ�㵽�������ÿ���ַ��Ĺ���������*/
	*HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
	cd=(char*)malloc(n*sizeof(char));		/*Ϊ���������붯̬����ռ�*/
	cd[n-1]='\0'; 
	/*��n��Ҷ�ӽ��Ĺ���������*/
	for(i=1;i<=n;i++)
	{ 
		start=n-1;												/*���������λ��*/
		for(c=i,f=(*HT)[i].parent;f!=0;c=f,f=(*HT)[f].parent)	/*��Ҷ�ӽ�㵽����������*/
			if((*HT)[f].lchild==c)
				cd[--start]='0';
			else
				cd[--start]='1';
			(*HC)[i]=(char*)malloc((n-start)*sizeof(char));	/*Ϊ��i���ַ��������ռ�*/
			strcpy((*HC)[i],&cd[start]);						/*����ǰ������Ĺ��������븴�Ƶ�HC*/
	}
	free(cd);
}
int Min(HuffmanTree t,int n)
/*��������n�������Ȩֵ��С�Ľ�����*/
{ 
	int i,flag;
	int f=infinity;					/*fΪһ�����޴��ֵ*/
	for(i=1;i<=n;i++)
		if(t[i].weight<f&&t[i].parent==0) 
			f=t[i].weight,flag=i;
		t[flag].parent=1;			/*��ѡ�еĽ���˫�׽�㸳ֵ1�������ٴβ��Ҹý��*/
		return flag;
}
void Select(HuffmanTree *t,int n,int *s1,int *s2)
/*��n�������ѡ������Ȩֵ��С�Ľ����ţ�����s1��С��s2��С*/
{ 
	int x;
	*s1=Min(*t,n);
	*s2=Min(*t,n);
	if((*t)[*s1].weight>(*t)[*s2].weight)		/*������s1��Ȩֵ�������s2��Ȩֵ�������߽�����ʹs1��С��s2��С*/
	{
		x=*s1;
		*s1=*s2;
		*s2=x;
	}
}