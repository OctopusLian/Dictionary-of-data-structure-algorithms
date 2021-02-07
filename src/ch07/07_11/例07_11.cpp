#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include<iostream.h>
#include<iomanip.h>
typedef char DataType;
#define MAXSIZE 100
typedef struct Node
{ 
    DataType data;
    struct Node * lchild,*rchild;
}BitNode,*BiTree;
void  CreateBitTree(BiTree *T,char str[]);
void PrintLevel(BiTree T);
void  CreateBitTree(BiTree *T,char str[])
/*��������Ƕ�׷�������������*/
{
    char ch;
    BiTree stack[MAXSIZE]; /*ջ���ڴ��ָ��������н���ָ��*/
    int top=-1;    		  /*��ʼ��ջ��ָ��*/
    int flag,k;
    BitNode *p;
    *T=NULL,k=0;
    ch=str[k];
    while(ch!='\0')		  /*����ַ���û�н���*/
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
void TreePrint(BiTree T,int level) 
/*����״��ӡ�Ķ�����*/ 
{   
    int i;
    if(T==NULL)/*���ָ��Ϊ�գ�������һ��*/ 
        return;
    TreePrint(T->rchild,level+1);/*��ӡ��������������μ�1*/ 
    for(i=0;i<level;i++)		/*���յݹ�Ĳ�δ�ӡ�ո�*/ 
        printf("   ");
    printf("%c\n",T->data);	/*��������*/ 
    TreePrint(T->lchild,level+1);/*��ӡ��������������μ�1*/ 
}
void Path(BiTree root, BitNode *r)
//�����root��r֮��·���ϵĽ��
{
    BitNode *p,*q;
    int i,top=0;
    BitNode *s[MAXSIZE];
    q=NULL;
    p=root;
    while(p!=NULL||top!=0)
    {
        while(p!=NULL)
            /*����������*/
        {
            top++;
            if(top>=MAXSIZE)
                exit(-1);
            s[top]=p;
            p=p->lchild;
        }
        if(top>0)/*��ջ��Ϊ��*/
        {
            p=s[top]; 
            if(p->rchild == NULL || p->rchild==q) /*�����*/
            {
                if(p==r) /*�ҵ�r��ָ��㣬������Ӹ���㵽r��ָ���֮��Ľ��*/
                {
                    for(i=1;i<=top;i++)
                        cout<<setw(4)<<s[i]->data;
                    top=0;p=NULL;/*��ջ��Ϊ����p=NULL��Ŀ����Ϊ���˳�����ѭ��*/
                }
                else
                {
                    q=p; 		/*��q����ոձ������Ľ��*/
                    top--; 		/*��ջ��ָ����ջ���ص���һ��*/
                    p=NULL;
                }
            }
            else
                p=p->rchild;	/*����������*/
        }
    }
}
BiTree FindPointer(BiTree T,DataType e)
/*����Ԫ��ֵΪe�Ľ���ָ��*/
{
    BiTree Q[MAXSIZE]; 		/*�������ڴ�Ŷ������н���ָ��*/
    int front=0,rear=0; 		/*��ʼ������*/
    BitNode *p;
    if(T) 					/*����������ǿ�*/
    {
        Q[rear]=T;
        rear++;
        while(front!=rear) 	/*������зǿ�*/
        {
            p=Q[front]; 		/*ȡ����ͷָ��*/
            front++;			/*����ͷָ�����*/
            if(p->data==e)
                return p;
            if(p->lchild)		/*���������ӣ�������ָ�����*/
            {
                Q[rear]=p->lchild;	/*���ӽ���ָ�����*/
                rear++;
            }
            if(p->rchild)		/*�������Һ��ӣ����Һ���ָ�����*/
            {
                Q[rear]=p->rchild; /*�Һ��ӽ���ָ�����*/
                rear++;
            }
        }
    }
    return NULL;
}
void main()
{  
    BiTree T;
    BitNode *s;
    DataType e;
    char str[MAXSIZE];
    cout<<"������������Ĺ������ʽ��"<<endl;
    cin>>str;
    cout<<"�ɹ������ʽ���ַ��������������"<<endl;
    CreateBitTree(&T,str);
    TreePrint(T,1);
    cout<<"������һ����㣺"<<endl;
    cin>>e;
    s=FindPointer(T,e);
    cout<<"�Ӹ���㵽���Ԫ��"<<e<<"֮��·���ϵĽ��Ϊ:"<<endl;
    Path(T,s);    
    cout<<endl;
}