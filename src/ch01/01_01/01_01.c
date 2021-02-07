#include<stdio.h>				/*�����������ͷ�ļ�*/
#define ListSize 200
typedef int DataType;			/*Ԫ�����Ͷ���Ϊ����*/
#include"SeqList.h"				/*����˳���Ļ�������*/
void MergeList(SeqList A,SeqList B,SeqList *C);	/*�ϲ�˳���A��B��Ԫ�صĺ�������*/
void main()
{
	int i,flag;
	DataType a[]={8,17,17,25,29};
	DataType b[]={3,9,21,21,26,57};
	DataType e;
	SeqList A,B,C;					/*����˳���A��B��C*/
	InitList(&A);					/*��ʼ��˳���A*/
	InitList(&B);					/*��ʼ��˳���B*/
	InitList(&C);					/*��ʼ��˳���C*/
	for(i=1;i<=sizeof(a)/sizeof(a[0]);i++)				/*������a�е�Ԫ�ز��뵽˳���A��*/
	{
		if(InsertList(&A,i,a[i-1])==0)
		{
			printf("λ�ò��Ϸ�");
			return;
		}
	}
	for(i=1;i<=sizeof(b)/sizeof(b[0]);i++)				/*������b��Ԫ�ز��뵽˳���B��*/
	{
		if(InsertList(&B,i,b[i-1])==0)
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
	printf("��A��B�е�Ԫ�غϲ���õ�C��\n");
	MergeList(A,B,&C);					/*����˳���A��B�е�Ԫ�غϲ�*/
	for(i=1;i<=C.length;i++)			/*��ʾ����ϲ���C������Ԫ��*/
	{
		flag=GetElem(C,i,&e);
		if(flag==1)
			printf("%4d",e);	
	}
	printf("\n");
	
}
void MergeList(SeqList A,SeqList B,SeqList *C)
/*�ϲ�˳���A��B��Ԫ�ص�C�У�������Ԫ�طǵݼ�����*/
{
	int i,j,k;
	DataType e1,e2;
	i=1;j=1;k=1;
	while(i<=A.length&&j<=B.length)
	{
		GetElem(A,i,&e1);				/*ȡ��˳���A�е�Ԫ��*/
		GetElem(B,j,&e2);				/*ȡ��˳���B�е�Ԫ��*/
		if(e1<=e2)						/*�Ƚ�˳���A��˳���B�е�Ԫ��*/
		{
			InsertList(C,k,e1);			/*����С��һ�����뵽C��*/
			i++;						/*�����ƶ�һ��λ�ã�׼���Ƚ���һ��Ԫ��*/
			k++;
		}
		else
		{
			InsertList(C,k,e2);			/*����С��һ�����뵽C��*/
			j++;						/*�����ƶ�һ��λ�ã�׼���Ƚ���һ��Ԫ��*/
			k++;
		}
		
	}
	while(i<=A.length)					/*���A��Ԫ�ػ���ʣ�࣬��ʱB���Ѿ�û��Ԫ��*/
	{
		GetElem(A,i,&e1);
		InsertList(C,k,e1);				/*��A��ʣ��Ԫ�ز��뵽C��*/
		i++;
		k++;
	}
	while(j<=B.length)					/*���B��Ԫ�ػ���ʣ�࣬��ʱA���Ѿ�û��Ԫ��*/
	{
		GetElem(B,j,&e2);
		InsertList(C,k,e2);				/*��B��ʣ��Ԫ�ز��뵽C��*/
		j++;
		k++;
	}
	C->length=A.length+B.length;		/*C�ı�����A��B�ı��ĺ�*/
}