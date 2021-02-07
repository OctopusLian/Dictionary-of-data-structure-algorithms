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
#include"LinkBiTree.h"
void CreateBitTree(BiTree *T,char str[]);	/*��������Ƕ�׵��ַ��������������ĺ�������*/
void LevelTraverse(BiTree T);
void main()
{
	BiTree root;
	cout<<"���ݹ����������ʽ(A(B(C,D),E(F(,G),H(I)))����������:"<<endl;
	CreateBitTree(&root,"(A(B(C,D),E(F(,G),H(I)))");
	cout<<"��״��ʾ������:"<<endl;
	TreePrint(root,0);
	cout<<"��α���������:"<<endl;
	LevelTraverse(root);
	cout<<endl;
	DestroyBitTree(&root);
}
void LevelTraverse(BiTree T)
/*�������������еĽ��*/
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
        cout<<setw(3)<<p->data;					/*��������*/
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