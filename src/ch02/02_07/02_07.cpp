#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
typedef char DataType;
#include"LinkList.h"
#define MAXSIZE 100
void CreateList(LinkList *L,DataType str[MAXSIZE]);
int SymmetryString(LinkList L);
void main()
{
	DataType a[MAXSIZE],b[MAXSIZE];
	LinkList L;
	int flag;
	cout<<"������һ���ַ�����"<<endl;
	cin>>a;
	CreateList(&L,a);
	flag=SymmetryString(L);
	if(flag==1)
		cout<<"���ĶԳ�!"<<endl;
	else
		cout<<"���Ĳ��Գ�!"<<endl;
	cout<<"������һ���ַ�����"<<endl;
	cin>>b;
	CreateList(&L,b);
	flag=SymmetryString(L);
	if(flag==1)
		cout<<"���ĶԳ�!"<<endl;
	else
		cout<<"���Ĳ��Գ�!"<<endl;
}   
int SymmetryString(LinkList L)
/*�ж��ַ����Ƿ����ĶԳ�*/
{
	char str[MAXSIZE];
	int i=1,n;
	ListNode *p;
	n=ListLength(L);//nΪ�����н��Ԫ�ظ���
	p=L->next;//pָ���һ�����
	for(i=0;i<n/2;i++)//��������ǰһ��Ԫ����ջ
	{
		str[i]=p->data;
		p=p->next;
	}
	i--;//�ָ�����iֵ
	if(n%2)//��nΪ����������ƹ����Ľ��
		p=p->next;
	while(p!=NULL && str[i]==p->data)//��ǰ�벿�ֺͺ�벿��Ԫ�ؽ��бȽ�
	{
		i--;
		p=p->next;
	}
	if(i==-1)//��Ϊ��ջ��������������ĶԳ�
		return 1;
	else//�����������Ĳ��Գ�
		return 0;
}
void CreateList(LinkList *L,DataType str[MAXSIZE])
//�����ַ�����str����������L
{
	int i;
	InitList(L);
	for(i=0;str[i]!='\0';i++)
		InsertList(*L,i+1,str[i]);
}