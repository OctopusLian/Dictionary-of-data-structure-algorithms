#include<stdio.h>
#include<stdlib.h>
#define StackSize 100
typedef char DataType;
#define CHAR1 "���ջ��ջ��Ԫ���ǣ�%c���Ҷ�ջ��ջ��Ԫ����:%c\n"
#define CHAR2 "%5c"
#include "SSeqStack.h"		/*��������ջ�Ļ������Ͷ���ͻ�������ʵ��*/
void main()
{
    SSeqStack S;			/*����һ������ջ*/
	int i;
	DataType a[]={'a','b','c','d','e','f'};
	DataType b[]={'p','w','x','y','z'};
	DataType e1,e2;
    InitStack(&S);					/*��ʼ������ջ*/
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++)	/*������a��Ԫ�����ν����ջ*/
    {
        if(PushStack(&S,a[i],1)==0)
        {
            printf("ջ������������ջ!");
            return;
        }
	}
	for(i=0;i<sizeof(b)/sizeof(b[0]);i++)	/*������b��Ԫ�����ν��Ҷ�ջ*/
    {
        if(PushStack(&S,b[i],2)==0)
        {
            printf("ջ������������ջ!");
            return;
        }
	}	
	if(GetTop(S,&e1,1)==0)
	{
		printf("ջ�ѿ�");
		return;
	}
	if(GetTop(S,&e2,2)==0)
	{
		printf("ջ�ѿ�");
		return;
	}
	printf(CHAR1,e1,e2);
	printf("���ջ�ĳ�ջ��Ԫ�ش����ǣ�");
	
	while(!StackEmpty(S,1))	/*�����ջԪ�س�ջ*/
    {
        PopStack(&S,&e1,1);
        printf(CHAR2,e1);	
	}
	printf("\n");
	printf("�Ҷ�ջ�ĳ�ջ��Ԫ�ش����ǣ�");
	while(!StackEmpty(S,2))	/*���Ҷ�ջԪ�س�ջ*/
	{
		PopStack(&S,&e2,2);
		printf(CHAR2,e2);
	}
	printf("\n");	
}