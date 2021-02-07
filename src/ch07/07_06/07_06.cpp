#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include<conio.h>
#define MAXSIZE 100
typedef struct Node
{ 
	char data;
	struct Node * lchild,*rchild;
}BitNode,*BiTree;
void CreateBiTree(BiTree *T,char *in,char *post,int len);
void PrintLevel(BiTree T);
void PrintTLR(BiTree T);
void PrintLRT(BiTree T);
void PrintLevel(BiTree T)
/*�������������Ľ��*/
{ 
	BiTree Queue[MAXSIZE];
	int front,rear;
	if(T==NULL) 
		return;
	front=-1;							/*��ʼ��������*/
	rear=0;
	Queue[rear]=T;
	while(front!=rear)					/*������в���*/
	{ 
		front++;						/*����ͷԪ�س���*/
		printf("%4c",Queue[front]->data);/*�����ͷԪ��*/
		if(Queue[front]->lchild!=NULL)	/*�����ͷԪ�ص����ӽ�㲻Ϊ�գ����������*/
		{
			rear++;
			Queue[rear]=Queue[front]->lchild;
		}
		if(Queue[front]->rchild!=NULL)	/*�����ͷԪ�ص��Һ��ӽ�㲻Ϊ�գ����Һ������*/
		{
			rear++;
			Queue[rear]=Queue[front]->rchild;
		}
	}
}
void PreTraverse(BiTree T)
/*��������������Ľ��*/
{ 
	if(T!=NULL)
	{ 
		printf("%4c ",T->data);	/*��������*/
		PreTraverse(T->lchild);	/*�������������*/
		PreTraverse(T->rchild);	/*�������������*/
	}
}
void CreateBiTree(BiTree *T,char *in,char *post,int len) 
/*���������кͺ������й��������*/
{
	
	int k;
	char *temp;
	if(len<=0)
	{
		*T=NULL;
		return;
	}
	for(temp=in;temp<in+len;temp++) /*����������in���ҵ���������ڵ�λ��*/
		if(*(post+len-1)==*temp)
		{
			k=temp-in;				/*�������ĳ���*/
			(*T)=(BitNode*)malloc(sizeof(BitNode));
			(*T)->data =*temp;
			break;
		}
	CreateBiTree(&((*T)->lchild),in,post,k);				/*����������*/
	CreateBiTree(&((*T)->rchild),in+k+1,post+k,len-k-1); /*����������*/		
}
void TreePrint(BiTree T,int level) 
/*����״��ӡ�Ķ�����*/ 
{   
	int i;
	if(T==NULL)									/*���ָ��Ϊ�գ�������һ��*/ 
		return;
	TreePrint(T->rchild,level+1);				/*��ӡ��������������μ�1*/ 
	for(i=0;i<level;i++)						/*���յݹ�Ĳ�δ�ӡ�ո�*/ 
		printf("   ");
	printf("%c\n",T->data);						/*��������*/ 
	TreePrint(T->lchild,level+1);				/*��ӡ��������������μ�1*/ 
}
void main()
{  
	BiTree T,ptr=NULL;
	int len;
	char in[MAXSIZE],post[MAXSIZE];
	printf("���������кͺ������й����������\n");
	printf("��������������ַ������У�");
	gets(in);
	printf("�������������ַ������У�");
	gets(post);
	len=strlen(post);
	CreateBiTree(&T,in,post,len);
	TreePrint(T,1);
	printf("\n�㽨���Ķ����������������ǣ�\n");
	PreTraverse(T);
	printf("\n�㽨���Ķ�������α�������ǣ�\n");
	PrintLevel(T);
	printf("\n");
}
