#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream.h>
#include<iomanip.h>
/*�궨��͵��������Ͷ���*/
typedef char DataType;
#include"LinkList.h"
/*��������*/
LinkList CreateList(DataType a[],int n);/*���ݸ��������鴴��������*/
void Decompose(LinkList L,LinkList *ha,LinkList *hb,LinkList *hc);	/*�ֽⵥ����Ϊ����ѭ��������*/
void DispList(LinkList L);
void DispCycList(LinkList head);
int CycListLength(LinkList head);
void main()
{
	LinkList h,ha,hb,hc;
	int n;
	DataType a[]={'a','X','0','$','@','%','p','m','3','9','y','*','i','&'};
	n=sizeof(a)/sizeof(a[0]);
	h=CreateList(a,n);
	Decompose(h,&ha,&hb,&hc);
	cout<<"��СдӢ����ĸ���ַ���"<<CycListLength(ha)<<"�����ֱ���:"<<endl;
	DispCycList(ha);
	cout<<"�����ַ�����:"<<CycListLength(hb)<<"�����ֱ���:"<<endl;
	DispCycList(hb);
	cout<<"�����ַ���:"<<CycListLength(hc)<<"�����ֱ���:"<<endl;
	DispCycList(hc);
}
LinkList CreateList(DataType a[],int n)
//���������е�Ԫ�ش���������
{
	LinkList L;			
	int i;
	InitList(&L);		//��ʼ��������L
	for(i=1;i<=n;i++)	//������a��Ԫ�ز��뵽������L��
	{
		if(InsertList(L,i,a[i-1])==0)
		{
			printf("����λ�ò��Ϸ�!");
			return NULL;
		}
	}
	DispList(L);
	return L;
}
void Decompose(LinkList L,LinkList *ha,LinkList *hb,LinkList *hc)
/*����ͷ���ĵ�����L�ֽ�Ϊ������ͷ����ѭ��������ha��hb��hc������ha
����Ӣ����ĸ�ַ���hb���������ַ���hc���������ַ�*/
{
	ListNode *p,*q;
	p=L->next;
	*ha=(LinkList)malloc(sizeof(ListNode));
	*hb=(LinkList)malloc(sizeof(ListNode));
	*hc=(LinkList)malloc(sizeof(ListNode));
	(*ha)->next=(*ha);
	(*hb)->next=(*hb);
	(*hc)->next=(*hc);
	while(p)
	{
		if((p->data>='A' && p->data<='Z')||(p->data>='a' && p->data<'z'))
		{
			q=p;
			p=p->next;
			q->next=(*ha)->next;
			(*ha)->next=q;
		}
		else if(p->data>='0' && p->data<='9')
		{
			q=p;
			p=p->next;
			q->next=(*hb)->next;
			(*hb)->next=q;
		}
		else
		{
			q=p;
			p=p->next;
			q->next=(*hc)->next;
			(*hc)->next=q;
		}
	}
}
void DispList(LinkList L)
//����������е�Ԫ��
{
	int i;
	LinkList p;
	cout<<"������L�е�Ԫ����"<<ListLength(L)<<"��"<<endl;
	for(i=1;i<=ListLength(L);i++)	/*���������L�е�ÿ��Ԫ��*/
	{
		p=Get(L,i);					/*���ص�����L�е�ÿ������ָ��*/
		if(p)
			cout<<setw(4)<<p->data;	/*���������L�е�ÿ��Ԫ��*/
	}
	cout<<endl;
}
void DispCycList(LinkList h)
//���ѭ���������е�Ԫ��
{
	ListNode *p=h->next;
	if(p==NULL)
	{
		cout<<"����Ϊ��!"<<endl;
		return;
	}
	while(p->next!=h)
	{
		cout<<setw(4)<<p->data;
		p=p->next;
	}
	cout<<setw(4)<<p->data;
	cout<<endl;
}
int CycListLength(LinkList head)
//��ѭ��������ı�
{
    ListNode *p;
    int count=0;
    p=head;
    while(p->next!=head)
    {
        p=p->next;
        count++;
    }
    return count;
}