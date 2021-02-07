#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream.h>
typedef char DataType;
typedef struct Node				/*��������洢�ṹ���Ͷ���*/
{
	DataType data;			 	/*������*/
	struct Node *lchild; 			/*ָ�����ӽ��*/
	struct Node *rchild; 			/*ָ���Һ��ӽ��*/
}*BiTree,BitNode;
void CreateBitTree(BiTree *T);
void PreOrderTraverse(BiTree T);	/*����������������ĵݹ麯������*/
void InOrderTraverse(BiTree T);		/*����������������ĵݹ麯������*/
void PostOrderTraverse(BiTree T);	/*�������ĺ�������ĵݹ麯������*/
void InitBitTree(BiTree *T);
void DestroyBitTree(BiTree *T);
void main()
{
	BiTree T;
	InitBitTree(&T);
	cout<<"����������������������д���������('#'��ʾΪ��)��"<<endl;
	CreateBitTree(&T);
	cout<<"���������������У�"<<endl;
	PreOrderTraverse(T);
	printf("\n");
	cout<<"���������������У�"<<endl;
	InOrderTraverse(T);
	printf("\n");
	cout<<"�������ĺ������У�"<<endl;
	PostOrderTraverse(T);
	cout<<endl;
	DestroyBitTree(&T);
}
void CreateBitTree(BiTree *T)
/*�����������ĵݹ�ʵ��*/
{ 
    DataType ch;
    scanf("%c",&ch);
    if(ch=='#') 
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BitNode)); 		/*���ɸ����*/
        if(!(*T))
            exit(-1);
        (*T)->data=ch;
        CreateBitTree(&((*T)->lchild)); 			/*����������*/
        CreateBitTree(&((*T)->rchild)); 			/*����������*/
    }
}
void DestroyBitTree(BiTree *T)
/*���ٶ�����*/
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
void InitBitTree(BiTree *T)
/*�������ĳ�ʼ������*/
{
	*T=NULL;
}
void PreOrderTraverse(BiTree T)
/*��������������ĵݹ�ʵ��*/
{
    if(T)								/*�����������Ϊ��*/
    {
        printf("%2c",T->data); 				/*���ʸ����*/
        PreOrderTraverse(T->lchild);		/*�������������*/
        PreOrderTraverse(T->rchild); 		/*�������������*/
    }
}
void InOrderTraverse(BiTree T)
/*��������������ĵݹ�ʵ��*/
{
    if(T)								/*�����������Ϊ��*/
	{
		InOrderTraverse(T->lchild);			/*�������������*/
        printf("%2c",T->data); 				/*���ʸ����*/
        InOrderTraverse(T->rchild); 		/*�������������*/
    }
}
void PostOrderTraverse(BiTree T)
/*��������������ĵݹ�ʵ��*/
{
    if(T)								/*�����������Ϊ��*/
	{
		PostOrderTraverse(T->lchild);		/*�������������*/
        PostOrderTraverse(T->rchild); 		/*�������������*/
		printf("%2c",T->data); 				/*���ʸ����*/
    }
}