#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
/*���������Ͷ���*/
typedef int DataType;
#include"LinkList.h"					/*�������������ʵ���ļ�*/
void Sort(LinkList S);
void DispList( LinkList S);
void Interction(LinkList A,LinkList B,LinkList *C);	/*��A��B�Ľ����ĺ�������*/
void main()
{
	int i;
	DataType a[]={21,35,8,23,87,101,57,99};
	DataType b[]={44,57,12,63,35,23,56,99,88,72};
	LinkList A,B,C;					/*����������A��B��C*/
	ListNode *p;
	InitList(&A);					/*��ʼ��������A*/
	InitList(&B);					/*��ʼ��������B*/
	for(i=1;i<=sizeof(a)/sizeof(a[0]);i++)	/*������a��Ԫ�ز��뵽������A��*/
	{
		if(InsertList(A,i,a[i-1])==0)
		{
			printf("λ�ò��Ϸ�");
			return;
		}
	}
	for(i=1;i<=sizeof(b)/sizeof(b[0]);i++)	/*������b��Ԫ�ز��뵥����B��*/
	{
		if(InsertList(B,i,b[i-1])==0)
		{
			printf("λ�ò��Ϸ�");
			return;
		}
	}
	printf("������A�е�Ԫ����%d����\n",ListLength(A));
	for(i=1;i<=ListLength(A);i++)	/*���������A�е�ÿ��Ԫ��*/
	{
		p=Get(A,i);					/*���ص�����A�е�ÿ������ָ��*/
		if(p)
			printf("%4d",p->data);	/*���������A�е�ÿ��Ԫ��*/
	}
	printf("\n");
	printf("������B�е�Ԫ����%d����\n",ListLength(B));
	for(i=1;i<=ListLength(B);i++)	
	{
		p=Get(B,i);					/*���ص�����B�е�ÿ��ÿ������ָ��*/
		if(p)
			printf("%4d",p->data);	/*���������B�е�ÿ��Ԫ��*/
	}
	printf("\n");
	Interction(A,B,&C);					/*��A��B�Ľ���*/
	printf("A��B�Ľ�����%d��Ԫ�أ�\n",ListLength(C));
	for(i=1;i<=ListLength(C);i++)		
	{
		p=Get(C,i);					/*���ص�����C��ÿ������ָ��*/
		if(p)
			printf("%4d",p->data);	/*��ʾ���C������Ԫ��*/
	}
	printf("\n");
}
void Interction(LinkList A,LinkList B,LinkList *C)
/*��A��B�Ľ���*/
{
	ListNode *pa,*pb,*pc;
	Sort(A);
	printf("�����A�е�Ԫ��:\n");
	DispList(A);
	Sort(B);
	printf("�����B�е�Ԫ��:\n");
	DispList(B);
	pa=A->next;
	pb=B->next;
	*C=(LinkList)malloc(sizeof(ListNode));
	(*C)->next=NULL;
	while(pa&&pb)
	{
		if(pa->data<pb->data)
			pa=pa->next;
		else if(pa->data>pb->data)
			pb=pb->next;
		else
		{
			pc=(ListNode*)malloc(sizeof(ListNode));
			pc->data=pa->data;
			pc->next=(*C)->next;
			(*C)->next=pc;
			pa=pa->next;
			pb=pb->next;
		}
	}
}
void Sort(LinkList S)
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
void DispList(LinkList S)
/*�������*/
{
	ListNode *p,*q;
	p=S->next;
	while(p)
	{
		q=p;
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");
}