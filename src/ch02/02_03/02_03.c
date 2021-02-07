#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct node
{
    DataType data;
    struct node *next;
}LStackNode,*LinkStack;
void Coversion(int N)
/*��������ģ��ջ��ʮ������ת��Ϊ�˽�����*/
{
	LStackNode *p,*top=NULL; 		/*����ָ�����ָ���ջ��ָ��top������ʼ��ջΪ��*/
    do
    {
        p=(LStackNode*)malloc(sizeof(LStackNode));	/*��̬�����½��*/
        p->data=N%8;							/*�����������½���������*/
        p->next=top; 							/*���½����뵽ԭջ�����֮ǰ��ʹ���Ϊ�µ�ջ��*/
		top=p;									/*ջ��ָ��ָ��ղ�������Ľ�㣬��Ϊջ��*/
        N=N/8;
    }while(N!=0);
	while(top!=NULL)							/*���ջ���գ���ջ����ʼ���ջ��Ԫ��*/
	{
		p=top;									/*pָ��ջ��*/
        printf("%d",p->data); 						/*���ջ��Ԫ��*/
        top=top->next; 							/*ջ�����Ԫ�س�ջ*/
        free(p); 								/*�ͷ�ջ�����*/
	}
}
void main()
{
	int n;
    printf("������һ��ʮ������:\n");
	scanf("%d",&n);
	printf("ת����İ˽�����Ϊ:\n");
	Coversion(n);
	printf("\n");
}