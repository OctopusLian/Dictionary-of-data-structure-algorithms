#include<stdio.h>				
#include<malloc.h>
#include<stdlib.h>
typedef int DataType;

#include"LinkList.h"			/*�����������������ʵ���ļ�*/
void MergeList(LinkList A,LinkList B,LinkList *C);	/*������������������A��B��Ԫ�غϲ���C��*/
void main()
{
	int i;
	DataType a[]={12,16,21,33,35,87,102};
	DataType b[]={3,5,21,23,35,99,123};
	LinkList A,B,C;					/*����������A��B*/
	ListNode *p;
	InitList(&A);					/*��ʼ��������A*/
	InitList(&B);					/*��ʼ��������B*/
	for(i=1;i<=sizeof(a)/sizeof(a[0]);i++)	/*��������Ԫ�ش���������A*/
	{
		if(InsertList(A,i,a[i-1])==0)
		{
			printf("����λ�ò��Ϸ�!");
			return;
		}
	}
	for(i=1;i<=sizeof(b)/sizeof(b[0]);i++)	/*��������Ԫ�ش���������B*/
	{
		if(InsertList(B,i,b[i-1])==0)
		{
			printf("����λ�ò��Ϸ�!");
			return;
		}
	}
	printf("������A�е�Ԫ����%d����\n",ListLength(A));
	for(i=1;i<=ListLength(A);i++)	/*���������A*/
	{
		p=Get(A,i);					/*���ص�����A�е�ÿ������ָ��*/
		if(p)
			printf("%4d",p->data);	/*���������A�е�ÿ��Ԫ��*/
	}
	printf("\n");
	printf("������B�е�Ԫ����%d����\n",ListLength(B));
	for(i=1;i<=ListLength(B);i++)	/*���������B*/
	{
		p=Get(B,i);					/*���ص�����B�е�ÿ������ָ��*/
		if(p)
			printf("%4d",p->data);	/*���������B�е�ÿ��Ԫ��*/
	}
	printf("\n");
	MergeList(A,B,&C);					/*��������A��B�е�Ԫ�غϲ���C��*/
	printf("��A��B��Ԫ�غϲ���һ���ݼ�����ĵ�����C(����%d��Ԫ��)��\n",ListLength(C));
	for(i=1;i<=ListLength(C);i++)		
	{
		p=Get(C,i);					/*���ص�����C��ÿ������ָ��*/
		if(p)
			printf("%4d",p->data);	/*��ʾ���C������Ԫ��*/
	}
	printf("\n");
}
void MergeList(LinkList A,LinkList B,LinkList *C)
/*���ǵݼ����еĵ�����A��B�е�Ԫ�غϲ���C�У�ʹC�е�Ԫ�ذ��ݼ����У���ֵͬ��Ԫ��ֻ����һ��*/
{
	ListNode *pa,*pb,*qa,*qb;/*����ָ������A��B��ָ��*/
	pa=A->next;/*paָ������A*/
	pb=B->next;/*pbָ������B*/
	free(B);/*�ͷŵ�����B��ͷ���*/
	*C=A;				/*��ʼ��������C�����õ�����A��ͷ�����ΪC��ͷ���*/
	(*C)->next=NULL;/*������C��ʼʱΪ��*/
	/*����ͷ�巨��������A��B�еĽ����뵽������C�У��Ȳ���Ԫ��ֵ��С�Ľ�㣩*/
	while(pa&&pb)		/*������A��B������ʱ*/
	{
		if(pa->data<pb->data)/*paָ����Ԫ��ֵ��Сʱ����paָ��Ľ����뵽C��*/
		{
			qa=pa;
			pa=pa->next;
			if((*C)->next==NULL)/*������CΪ��ʱ��ֱ�ӽ������뵽C��*/
			{
				qa->next=(*C)->next;
				(*C)->next=qa;
			}
			else if((*C)->next->data<qa->data)/*paָ��Ľ��Ԫ��ֵ��ͬ�����н��Ԫ��ֵʱ���Ų�����*/
			{
				qa->next=(*C)->next;
				(*C)->next=qa;
			}
			else/*�����ͷ�Ԫ��ֵ��ͬ�Ľ��*/
				free(qa);
		}
		else/*pbָ����Ԫ��ֵ��С����pbָ��Ľ����뵽C��*/
		{
			qb=pb;
			pb=pb->next;
			if((*C)->next==NULL)/*������CΪ��ʱ��ֱ�ӽ������뵽C��*/
			{
				qb->next=(*C)->next;
				(*C)->next=qb;
			}
			else if((*C)->next->data<qb->data)/*pbָ��Ľ��Ԫ��ֵ��ͬ�����н��Ԫ��ʱ���Ž�������*/
			{
				qb->next=(*C)->next;
				(*C)->next=qb;
			}
			else/*�����ͷ�Ԫ��ֵ��ͬ�Ľ��*/
				free(qb);
		}
	}
	while(pa)/*���pbΪ�ա�pa��Ϊ�գ���paָ��ĺ�̽����뵽C��*/
	{
		qa=pa;
		pa=pa->next;
		if((*C)->next&&(*C)->next->data<qa->data)
		{
			qa->next=(*C)->next;
			(*C)->next=qa;
		}
		else
			free(qa);
	}
	while(pb)/*���paΪ�ա�pb��Ϊ�գ���pbָ��ĺ�̽����뵽C��*/
	{
		qb=pb;
		pb=pb->next;
		if((*C)->next&&(*C)->next->data<qb->data)
		{
			qb->next=(*C)->next;
			(*C)->next=qb;
		}
		else
			free(qb);
	}
}