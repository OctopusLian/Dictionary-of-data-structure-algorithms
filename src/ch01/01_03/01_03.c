#include<stdio.h>				
#define ListSize 200
typedef int DataType;
#include"SeqList.h"					/*����˳���Ļ�������*/
void DelElem(SeqList *A,SeqList B);		/*ɾ��A�г���B��Ԫ�صĺ�������*/
void main()
{
	int i,j,flag;
	DataType e;
	SeqList A,B;					/*����˳���A��B*/
	InitList(&A);					/*��ʼ��˳���A*/
	InitList(&B);					/*��ʼ��˳���B*/
	for(i=1;i<=10;i++)				/*���뵽˳���A��10����*/
	{
		if(InsertList(&A,i,i*2+10)==0)
		{
			printf("λ�ò��Ϸ�");
			return;
		}
	}
	for(i=1,j=10;i<=8;j=j+2,i++)		/*����˳���B��8����*/
	{
		if(InsertList(&B,i,j+i*2)==0)
		{
			printf("λ�ò��Ϸ�");
			return;
		}
	}
	printf("˳���A�е�Ԫ�أ�\n");
	for(i=1;i<=A.length;i++)		/*���˳���A�е�ÿ��Ԫ��*/
	{
		flag=GetElem(A,i,&e);		/*����˳���A�е�ÿ��Ԫ�ص�e��*/
		if(flag==1)
			printf("%4d",e);
	}
	printf("\n");
	printf("˳���B�е�Ԫ�أ�\n");
	for(i=1;i<=B.length;i++)		/*���˳���B�е�ÿ��Ԫ��*/
	{
		flag=GetElem(B,i,&e);		/*����˳���B�е�ÿ��Ԫ�ص�e��*/
		if(flag==1)
			printf("%4d",e);	
	}
	printf("\n");
	printf("����A�г���B��Ԫ��ɾ����,A�е�Ԫ��(��A-B)��\n");
	DelElem(&A,B);					/*����˳���A�г��ֵ�B��Ԫ��ɾ��*/
	for(i=1;i<=A.length;i++)		/*��ʾ���ɾ����A������Ԫ��*/
	{
		flag=GetElem(A,i,&e);
		if(flag==1)
			printf("%4d",e);	
	}
	printf("\n");
}
void DelElem(SeqList *A,SeqList B)
/*��A-B����ɾ��A��B��Ԫ��*/
{
	int i,flag,pos;
	DataType e;
	for(i=1;i<=B.length;i++)		
	{
		flag=GetElem(B,i,&e);		/*���ΰ�B��ÿ��Ԫ��ȡ����e*/
		if(flag==1)
		{
			pos=LocateElem(*A,e);	/*��A�в���Ԫ��e*/
			if(pos>0)				/*�����Ԫ�ش���*/
				DeleteList(A,pos,&e);/*�����A��ɾ��*/
		}
	}
}