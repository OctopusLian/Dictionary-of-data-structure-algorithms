#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream.h>
#include<iomanip.h>
typedef char DataType;
#define MAXSIZE 100				
typedef struct Node				/*��������洢�ṹ���Ͷ���*/
{
	DataType data;			 	/*������*/
	struct Node *lchild; 		/*ָ�����ӽ��*/
	struct Node *rchild; 		/*ָ���Һ��ӽ��*/
}*BiTree,BitNode;
void CreateBitTree(BiTree *T,char str[]);	/*��������Ƕ�׵��ַ��������������ĺ�������*/
void TreePrint(BiTree T,int nLayer);
void PreOrderTraverse(BiTree T);
void DestroyBitTree(BiTree *T);
void main()
{
	BiTree root;
	cout<<"���ݹ����������ʽ(A(B(C,D),E(F(,G),H(I)))����������:"<<endl;
	CreateBitTree(&root,"(A(B(C,D),E(F(,G),H(I)))");
	cout<<"��״��ʾ������:"<<endl;
	TreePrint(root,0);
	cout<<"�������������:"<<endl;
	PreOrderTraverse(root);
	cout<<endl;
	DestroyBitTree(&root);
}
void PreOrderTraverse(BiTree T)
/*��������������ķǵݹ�ʵ��*/
{
	BiTree stack[MAXSIZE]; 				/*����һ��ջ�����ڴ�Ž���ָ��*/
	int top; 							/*����ջ��ָ��*/
	BitNode *p; 						/*����һ������ָ��*/
	top=0;							/*��ʼ��ջ*/
	p=T;
	while(p!=NULL||top>0)
	{
		while(p!=NULL) 					/*���p���գ����ʸ���㣬����������*/
		{
			cout<<setw(3)<<p->data; 	/*���ʸ����*/
			stack[top++]=p; 				/*��p��ջ*/
			p=p->lchild; 				/*����������*/
		}
		if(top>0) 						/*���ջ����*/
		{
			p=stack[--top]; 				/*ջ��Ԫ�س�ջ*/
			p=p->rchild;					/*����������*/
		}
	}
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

void  CreateBitTree(BiTree *T,char str[])
/*��������Ƕ�׵��ַ���������������*/
{
	char ch;
	BiTree stack[MAXSIZE];			/*����ջ�����ڴ��ָ��������н���ָ��*/
	int top=-1;						/*��ʼ��ջ��ָ��*/
	int flag,k;
	BitNode *p;
	*T=NULL,k=0;
	ch=str[k];
	while(ch!='\0')					/*����ַ���û�н���*/
	{
		switch(ch)
		{
		case '(':
			stack[++top]=p;
			flag=1;
			break;
		case ')':
			top--;
			break;
		case ',':
			flag=2;
			break;
		default:
			p=(BiTree)malloc(sizeof(BitNode));
			p->data=ch;
			p->lchild=NULL;
			p->rchild=NULL;
			if(*T==NULL)		/*����ǵ�һ����㣬��ʾ�Ǹ����*/
				*T=p;
			else
			{
				switch(flag)
				{
				case 1:
					stack[top]->lchild=p;
					break;
				case 2:
					stack[top]->rchild=p;
					break;
				}
			}
		}
		ch=str[++k];
	}
}
void DestroyBitTree(BiTree *T)
/*���ٶ���������*/
{
	if(*T) 							/*����Ƿǿն�����*/
	{
		if((*T)->lchild)
			DestroyBitTree(&((*T)->lchild));
		if((*T)->rchild)
			DestroyBitTree(&((*T)->rchild));
		free(*T);
		*T=NULL;
	}
}
void LevelPrint(BiTree T)
/*����δ�ӡ�������еĽ��*/
{ 
    BiTree queue[MAXSIZE];						/*����һ�����У����ڴ�Ž���ָ��*/
	BitNode *p;
    int front,rear;								/*������еĶ�ͷָ��Ͷ�βָ��*/
    front=rear=-1;								/*���г�ʼ��Ϊ��*/
    rear++;										/*��βָ���1*/
    queue[rear]=T;								/*�������ָ�����*/
    while(front!=rear)							/*������в�Ϊ��*/
    {
        front=(front+1)%MAXSIZE;
        p=queue[front];							/*ȡ����ͷԪ��*/
        printf("%c ",p->data);					/*��������*/
        if(p->lchild!=NULL)						/*������Ӳ�Ϊ�գ������ӽ��ָ�����*/
        {
            rear=(rear+1)%MAXSIZE;
            queue[rear]=p->lchild;
        }   
        if(p->rchild!=NULL)						/*����Һ��Ӳ�Ϊ�գ����Һ��ӽ��ָ�����*/
        {
            rear=(rear+1)%MAXSIZE;
            queue[rear]=p->rchild;
        }     
    }    
}