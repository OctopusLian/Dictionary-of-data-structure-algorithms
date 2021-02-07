#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include<iostream.h>
#define MAXSIZE 100
typedef struct Node
{ 
	char data;
	struct Node * lchild,*rchild;
}BitNode,*BiTree;
#include"BiTreeQueue.h"
void  CreateBitTree(BiTree *T,char str[]);
void PrintLevel(BiTree T);
int JudgeComplete(BiTree T)
//�ж��Ƿ�Ϊ��ȫ������
{
	int tag=0;//��־
	BiTree p=T;
	Queue Q;//����Q�д�Ž���ָ��
	if(p==NULL)//��Ϊ�ն���������ֱ�ӷ���1
		return 1;
	InitQueue(&Q);//��ʼ������
	EnQueue(&Q,p);//�����ָ�����
	while(!QueueEmpty(Q))//���в�Ϊ��
	{
		DeQueue(&Q,&p);//����ͷָ�����
		if(p->lchild && !tag)//�����Ӵ���
			EnQueue(&Q,p->lchild);//���������
		else if(p->lchild)//��ǰ���н��Ϊ�գ����ý�㲻Ϊ��
			return 0;//��˵��������ȫ������
		else//�����ֽ��Ϊ��
			tag=1;//��־��Ϊ1
		if(p->rchild && !tag)//���Һ��Ӵ���
			EnQueue(&Q,p->rchild);//���Һ���ָ�����
		else if(p->rchild)//�Һ��Ӵ��ڣ���ǰ���н��Ϊ��
			return 0;//��˵��������ȫ������
		else//�����ֽ��Ϊ��
			tag=1;//��־��Ϊ1
	}
	ClearQueue(&Q);//��ն���
	return 1;//����1��ʾΪ��ȫ������
}
void  CreateBitTree(BiTree *T,char str[])
/*��������Ƕ�׵��ַ���������������*/
{
	char ch;
	BiTree stack[MAXSIZE];	/*����ջ�����ڴ��ָ��������н���ָ��*/
	int top=-1;				/*��ʼ��ջ��ָ��*/
	int flag,k;
	BitNode *p;
	*T=NULL,k=0;
	ch=str[k];
	while(ch!='\0')		/*����ַ���û�н���*/
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
			if(*T==NULL)/*����ǵ�һ����㣬��ʾ�Ǹ����*/
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
	BiTree T;
	int flag;
	char str[MAXSIZE];
	cout<<"������������Ĺ������ʽ��"<<endl;
	cin>>str;
	cout<<"�ɹ������ʽ���ַ��������������"<<endl;
	CreateBitTree(&T,str);
	TreePrint(T,1);
	flag=JudgeComplete(T);
	if(flag)
		cout<<"����ȫ������!"<<endl;
	else
		cout<<"������ȫ������!"<<endl;
	cout<<"������������Ĺ������ʽ��"<<endl;
	cin>>str;
	cout<<"�ɹ������ʽ���ַ��������������"<<endl;
	CreateBitTree(&T,str);
	TreePrint(T,1);
	flag=JudgeComplete(T);
	if(flag)
		cout<<"����ȫ������!"<<endl;
	else
		cout<<"������ȫ������!"<<endl;
}
