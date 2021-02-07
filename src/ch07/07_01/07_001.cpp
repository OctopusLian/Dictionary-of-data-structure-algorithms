#include<iostream.h>
#include<malloc.h>
#include<stdio.h>
typedef char DataType;
#define  MAXSIZE 200
typedef struct BiTnode
{
	DataType data;
	struct  BiTnode *lchild,*rchild;
}*BiTree,BitNode;
int CreateBiTree(BiTree *T, DataType *str);
void DispBTNode(BiTree T);
int CreateBiTree(BiTree *T, DataType *str)
{    
	BiTree S[MAXSIZE],  p=NULL;   //˳��ջ
	int top=0,k=0,j=0;
	char ch;              //topջ��ָ��
	*T=NULL;	         //��������ʼʱΪ��
	ch=str[j];
	while (ch!='@')//ɨ�������е��ַ�
	{ 	                          
		switch(ch)
		{
		case '(':  //���뵽��һ�㣬����Ϊ���ӽ��
			S[top++]=p; 
			k=1;
			break;
		case ')'://�ص���һ��
			top--;
			break;
		case ',':  //Ϊ�Һ��ӽ��  
			k=2;
			break;                 
		default:
			p=(BiTree)malloc(sizeof(BitNode));
			p->data=ch; 
			p->lchild=p->rchild=NULL;
			if (*T==NULL) //����� 
				*T=p;       //���������                                                    
			else//�ѽ��������������
			{                              
				switch(k)//����kֵ������ջ�����Ĺ�ϵ
				{                               
				case 1:  
					S[top-1]->lchild=p; 
					break;
				case 2:   
					S[top-1]->rchild=p; 
					break;
				}
			}
			break;
		}
		ch=str[++j];   //����һ���ַ�
	}
	return 1;
} 
void main()
{
	int n,len=0;
	char ch,str[MAXSIZE];
	BiTree T;
	cout<<"��������,��'@'������"<<endl;
	while((ch=getchar())!='\n')
	{
		str[len++]=ch;
	}
    n= CreateBiTree(&T,str);
    if(n==1) 
		cout<<"�����ɹ�."<<endl;
	else 
		cout<<"����ʧ��."<<endl;
	DispBTNode(T);
}
void DispBTNode(BiTree T)
{
	BitNode *qu[MAXSIZE];
	BitNode *p;
	int front,rear,n;
	n = 0;	//��ʼ�����
	front=rear=0;
	qu[rear++]=NULL;
	p = T;
	if (p != NULL)
	{
		qu[rear ++] = p;
	}
	do
	{
		p = qu[front ++];
		if (p == NULL)
		{
			qu[rear++] = NULL;			//�����н����ָ����Ϊ�ֲ��־
			n++;	//��ż�1
			printf("\n");
		}
		else
		{
			cout<<"��"<<n<<"��:"<<p->data<<endl;
			if (p->lchild != NULL)
			{
				qu[rear++] = p->lchild;
			}
			if (p->rchild != NULL)
			{
				qu[rear++] = p->rchild;
			}
		}
	} while (front!=rear-1);
}

void level_order(BiTree T)
{
    BiTree  ptr ,tree[MAXSIZE];
	int i,front=-1,rear=0;
	for(i=0;i<MAXSIZE;i++)
		tree[i]=NULL;
    ptr=T;
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		if(ptr->lchild!=NULL)tree[rear++]=ptr->lchild;
		if(ptr->lchild!=NULL)tree[rear++]=ptr->rchild;
		if(front!=rear)ptr=tree[++front];
	}
}