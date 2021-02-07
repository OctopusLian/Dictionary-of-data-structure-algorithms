#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int DataType;
#include"LinkList.h"					/*����������ʵ���ļ�*/
void DelElem(LinkList A,LinkList B);	/*ɾ��A�г���B��Ԫ�صĺ�������*/
void SortList(LinkList S);
ListNode *Append(ListNode *last,DataType e);
ListNode *Difference(ListNode *A,ListNode *B);
void main()
{
	int i;
	DataType a[]={22,7,15,56,89,38,44,65,109,83};
	DataType b[]={15,9,22,89,33,65,90,83};
	LinkList A,B,C;					/*����������A��B��C*/
	ListNode *p;
	InitList(&A);					/*��ʼ��������A*/
	InitList(&B);					/*��ʼ��������B*/
	/*������a��Ԫ�ز��뵽������A��*/
	for(i=1;i<=sizeof(a)/sizeof(a[0]);i++)
	{
		if(InsertList(A,i,a[i-1])==0)
		{
			printf("λ�ò��Ϸ�");
			return;
		}
	}
	/*������b��Ԫ�ز��뵥����B��*/
	for(i=1;i<=sizeof(b)/sizeof(b[0]);i++)
	{
		if(InsertList(B,i,b[i-1])==0)
		{
			printf("λ�ò��Ϸ�");
			return;
		}
	}
	printf("������A�е�Ԫ����%d����\n",ListLength(A));
	p=A->next;
	while(p!=NULL)
	{
		printf("%4d",p->data);	/*�������A�е�ÿ��Ԫ��*/
		p=p->next;
	}
	printf("\n");
	printf("������B�е�Ԫ����%d����\n",ListLength(B));
	p=B->next;
	while(p!=NULL)
	{
		printf("%4d",p->data);	/*�������B�е�ÿ��Ԫ��*/
		p=p->next;
	}
	printf("\n");
	SortList(A);
	SortList(B);
	//	DelElem(A,B);					/*���ڵ�����A�г��ֵ�B��Ԫ��ɾ������A-B*/
	C=Difference(A,B);
	printf("C�е�Ԫ�أ�\n");
	p=C;
	while(p!=NULL)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");
}
void SortList(LinkList S)
/*����ѡ�����򷨶�����S���д�С��������*/
{
	ListNode *p,*q,*r;
	DataType t;
	p=S->next;
	while(p->next)
	{
		r=p;
		q=p->next;
		while(q)
		{
			if(r->data>q->data)
				r=q;
			q=q->next;
		}
		if(p!=r)
		{
			t=p->data;
			p->data=r->data;
			r->data=t;
		}
		p=p->next;
	}	
}
ListNode *Append(ListNode *last,DataType e)
//�ͷ�ͷ���
{
	last->next=(ListNode*)malloc(sizeof(ListNode));
	last->next->data=e;
	return last->next;
}
ListNode *Difference(ListNode *A,ListNode *B)
//��A-B������������C��
{
	ListNode *C,*last;
	C=last=(ListNode*)malloc(sizeof(ListNode));
	while(A!=NULL&&B!=NULL)
		if(A->data<B->data)
		{
			last=Append(last,A->data);
			A=A->next;
		}
		else if(A->data==B->data)
		{
			A=A->next;
			B=B->next;
		}
		else 
			B=B->next;
		while(A!=NULL)//���A�л���ʣ��Ԫ�أ���ʣ�µ�Ԫ��׷�ӵ�C��
		{
			last=Append(last,A->data);
			A=A->next;
		}
		last->next=NULL;//���һ������ָ������Ϊ��
		last=C;
		C=C->next;//ָ���һ�����
		free(last);//�ͷ�ͷ���
		return C;
}
