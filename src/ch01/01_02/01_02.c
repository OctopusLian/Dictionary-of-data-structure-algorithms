#include<stdio.h>					/*�����������ͷ�ļ�*/
#define ListSize 200
typedef int DataType;/*����Ԫ������Ϊ����*/
#include"SeqList.h"	 
void UnionAB(SeqList *A,SeqList B);		/*��LB�е�����LA�е�Ԫ�ز��뵽LA��*/
void main()
{
	int i,flag;
	DataType e;
	DataType a[]={81,32,61,12,39,25};
	DataType b[]={12,44,39,16,28,6,61,76};
	SeqList LA,LB;					/*����˳���LA��LB*/
	InitList(&LA);					/*��ʼ��˳���LA*/
	InitList(&LB);					/*��ʼ��˳���LB*/
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)	/*������a�е�Ԫ�ز��뵽��LA��*/
	{
		if(InsertList(&LA,i+1,a[i])==0)
		{
			printf("λ�ò��Ϸ�");
			return;
		}
	}
	for(i=0;i<sizeof(b)/sizeof(b[0]);i++)/*������a�е�Ԫ�ز��뵽��LB��*/
	{
		if(InsertList(&LB,i+1,b[i])==0)
		{
			printf("λ�ò��Ϸ�");
			return;
		}
	}
	printf("˳���LA�е�Ԫ�أ�\n");
	for(i=1;i<=LA.length;i++)		/*���˳���LA�е�ÿ��Ԫ��*/
	{
		flag=GetElem(LA,i,&e);	/*����˳���LA�е�ÿ��Ԫ�ص�e��*/
		if(flag==1)
			printf("%4d",e);
	}
	printf("\n");
	printf("˳���LB�е�Ԫ�أ�\n");
	for(i=1;i<=LB.length;i++)		/*���˳���LB�е�ÿ��Ԫ��*/
	{
		flag=GetElem(LB,i,&e);	/*����˳���LB�е�ÿ��Ԫ�ص�e��*/
		if(flag==1)
			printf("%4d",e);	
	}
	printf("\n");
	printf("����LB�е�����LA�е�Ԫ�ز��뵽LA�У�\n");
	UnionAB(&LA,LB);		/*��LB�е�����LA�е�Ԫ�ز��뵽LA��*/
	for(i=1;i<=LA.length;i++)		/*���LA������Ԫ��*/
	{
		flag=GetElem(LA,i,&e);
		if(flag==1)
			printf("%4d",e);	
	}
printf("\n");	
}
void UnionAB(SeqList *LA,SeqList LB)
/*ɾ��A�г���B��Ԫ�صĺ���ʵ��*/
{
	int i,flag,pos;
	DataType e;
	for(i=1;i<=LB.length;i++)		
	{
		flag=GetElem(LB,i,&e);	/*���ΰ�LB��ÿ��Ԫ��ȡ������e*/
		if(flag==1)
		{
			pos=LocateElem(*LA,e);	/*��LA�в��Һ�LB��ȡ����Ԫ��e��ȵ�Ԫ��*/
			if(!pos)
				InsertList(LA,LA->length+1,e);/*����ҵ���Ԫ�أ���Ԫ�ز��뵽LA��*/
		}
	}
}