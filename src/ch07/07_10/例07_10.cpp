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
void  CreateBitTree(BiTree *T,char str[]);
void PrintLevel(BiTree T);
void  CreateBitTree(BiTree *T,char str[])
/*��������Ƕ�׷�������������*/
{
    char ch;
    BiTree stack[MAXSIZE];	/*����ջ�����ڴ��ָ��������н���ָ��*/
    int top=-1;				/*��ʼ��ջ��ָ��*/
    int flag,k;
    BitNode *p;
    *T=NULL,k=0;
    ch=str[k];
    while(ch!='\0')			/*����ַ���û�н���*/
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
    if(T==NULL)					/*���ָ��Ϊ�գ�������һ��*/ 
        return;
    TreePrint(T->rchild,level+1);/*��ӡ��������������μ�1*/ 
    for(i=0;i<level;i++)			/*���յݹ�Ĳ�δ�ӡ�ո�*/ 
        printf("   ");
    printf("%c\n",T->data);		/*��������*/ 
    TreePrint(T->lchild,level+1);/*��ӡ��������������μ�1*/ 
}
int BiTreeDepth(BiTree T)
/*��������������*/
{
    if(T == NULL) 
        return 0;
    return     BiTreeDepth(T->lchild)>BiTreeDepth(T->rchild)?1+BiTreeDepth(T->lchild):1+BiTreeDepth(T->rchild);
}
int BiTreeWidth(BiTree T)
//�������T�������
{
    int front,rear,last,maxw,temp;
    BiTree Q[MAXSIZE]; 	//Q�Ƕ��У�Ԫ��Ϊ���������ָ��
    BitNode *p;
    if (T==NULL)			//�ն��������Ϊ0
        return 0; 
    else 
    {
        front=1;rear=1;last=1;//front��ͷָ��,rear��βָ��, lastͬ�����ҽ���ڶ����е�λ��
        temp=0;			//tempΪ��ǰ���,
        maxw=0; 			//maxwΪ�����
        Q[rear]=T; 		//����������
        while(front<=last) 
        {
            p=Q[front++]; 
            temp++; 		//ͬ��Ԫ������1
            if (p->lchild!=NULL) 
                Q[++rear]=p->lchild; 	//����Ů���
            if (p->rchild!=NULL) 
                Q[++rear]=p->rchild; 	//����Ů���
            if (front>last) 			//һ�������
            {
                last=rear; 
                if(temp>maxw) 
                    maxw=temp; 		//lastָ���²�����Ԫ��, ���µ�ǰ�����
                temp=0; 
            }
        }
        return maxw; 
    }
}
void main()
{  
    BiTree T;
    char str[MAXSIZE];
    cout<<"������������Ĺ������ʽ��"<<endl;
    cin>>str;
    cout<<"�ɹ������ʽ���ַ��������������"<<endl;
    CreateBitTree(&T,str);
    TreePrint(T,1);
    cout<<"��ö������ĸ߶�Ϊ:"<<BiTreeDepth(T)<<endl;
    cout<<"��ö������������Ϊ:"<<BiTreeWidth(T)<<endl;
}