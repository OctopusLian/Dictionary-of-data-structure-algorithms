#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include<iostream.h>
#define MAXSIZE 100
typedef char DataType;
typedef struct Node
{ 
	DataType data;
	struct Node * lchild,*rchild;
}BitNode,*BiTree;
void TreePrint(BiTree T,int level);
BiTree CreateBitTree();
int Degrees1(BitNode *T);
int Degrees0(BitNode *T);
BiTree CreateBitTree()
/*�����������뷽ʽ����������*/
{
	DataType ch;
	BiTree bt;
	scanf("%c",&ch);
	if(ch=='#')
		bt=NULL;
	else
	{
		bt=(BitNode*)malloc(sizeof(BitNode));
		bt->data=ch;
		bt->lchild=CreateBitTree();
		bt->rchild=CreateBitTree();
	}
	return bt;
}
int Degrees1(BitNode *T)
//��������ж�Ϊ1�Ľ�����
{
	if(T==NULL)//�ն�����
		return 0;//��Ϊ1�Ľ��Ϊ0
	if(T->lchild !=NULL && T->rchild==NULL || T->lchild ==NULL && T->rchild!=NULL)//��ֻ����������������
		return 1 + Degrees1(T->lchild) + Degrees1(T->rchild);//��ý���Ϊ1���������������������Ķ�Ϊ1�Ľ�����֮��
	return  Degrees1(T->lchild) + Degrees1(T->rchild);//�����������������������Ϊ1�Ľ�����֮��
}
int Degrees0(BiTree T)
/*��������ж�Ϊ0�Ľ�����*/
{
    if(!T)										/*����ǿն�����������0*/
		return 0;
    else 
		if(!T->lchild&&!T->rchild)					/*�������������������Ϊ�գ�����1*/
			return 1;
		else 
			return Degrees0(T->lchild)+Degrees0(T->rchild); 	/*��������Ҷ�ӽ�������������Ҷ�ӽ��������*/
}
void TreePrint(BiTree T,int level) 
/*����״��ӡ�Ķ�����*/ 
{   
	int i;
	if(T==NULL)									/*���ָ��Ϊ�գ�������һ��*/ 
		return;
	TreePrint(T->rchild,level+1);				/*��ӡ��������������μ�1*/ 
	for(i=0;i<level;i++)						/*���յݹ�Ĳ�δ�ӡ�ո�*/ 
		cout<<"   ";
	cout<<T->data<<endl;						/*��������*/ 
	TreePrint(T->lchild,level+1);				/*��ӡ��������������μ�1*/ 
}
void main()
{  
	BiTree T;
	cout<<"�밴������ʽ����������Ľ��Ԫ�أ�"<<endl;
	T=CreateBitTree();
	cout<<"�����Ķ�������"<<endl;
	TreePrint(T,1);
	cout<<"��Ϊ0�Ľ�����:"<<Degrees0(T)<<endl;
	cout<<"��Ϊ1�Ľ�����:"<<Degrees1(T)<<endl;
}
