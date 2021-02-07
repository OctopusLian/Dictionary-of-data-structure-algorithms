#include<stdio.h>
#include<malloc.h>
typedef int DataType;			
#define MaxSize 100
#include "LinkQueue.h"
void PrintArray(int a[],int n,int N);
void YangHuiTriangle(int N);
void main()
{
	int n;
	printf("������Ҫ��ӡ��������n=:");
	scanf("%d",&n);	
	YangHuiTriangle(n);	
}
void YangHuiTriangle(int N)
/*��ʽ����ʵ�ִ�ӡ�������*/
{ 
	int i,k,n;
	DataType e,t;
	int temp[MaxSize];				/*����һ����ʱ���飬���ڴ��ÿһ�е�Ԫ��*/
	LinkQueue Q;
	k=0;
	InitQueue(&Q);					/*��ʼ��������*/
	EnQueue(&Q,1);				/*��һ��Ԫ�����*/
	for(n=2;n<=N;n++)				/*������n��Ԫ�ز���ӣ�ͬʱ����n-1�е�Ԫ�ر�������ʱ������*/
	{
		k=0;
		EnQueue(&Q,1);			/*��n�еĵ�һ��Ԫ�����*/
		for(i=1;i<=n-2;i++)			/*���ö����е�n-1��Ԫ�ز�����i�е��м�n-2��Ԫ�ز������*/
		{
			DeQueue(&Q,&t);
			temp[k++]=t;			/*����n-1�е�Ԫ�ش�����ʱ����*/
			GetHead(Q,&e);		/*ȡ��ͷԪ��*/
			t=t+e;				/*���ö��е�n-1��Ԫ�ز�����i��Ԫ��*/
			EnQueue(&Q,t);  
		}
		DeQueue (&Q,&t);
		temp[k++]=t;				/*����n-1�е����һ��Ԫ�ش�����ʱ����*/
		PrintArray(temp,k,N);	
		EnQueue(&Q,1);			/*��n�е����һ��Ԫ�����*/
	}
	k=0;							/*�����һ��Ԫ�ش�������֮ǰ��Ҫ���±�k��Ϊ0*/
	while(!QueueEmpty(Q))			/*�����һ��Ԫ�ش�����ʱ����*/
	{
		DeQueue(&Q,&t);
		temp[k++]=t;
		if(QueueEmpty(Q))
			PrintArray(temp,k,N);
	}	
}
void PrintArray(int a[],int n,int N)
/*��ӡ�����е�Ԫ�أ�ʹ�ܹ�����ȷ����ʽ���*/
{
	int i;
	static count=0;					/*��¼�������*/
	for(i=0;i<N-count;i++)			/*��ӡ�ո�*/
		printf("   ");
	count++;
	for(i=0;i<n;i++)					/*��ӡ�����е�Ԫ��*/
		printf("%6d",a[i]);
	printf("\n");
}