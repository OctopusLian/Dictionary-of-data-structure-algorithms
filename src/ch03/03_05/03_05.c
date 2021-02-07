#include<stdio.h>		
#include<stdlib.h>		
#include<string.h>		
#include<malloc.h>		
typedef char DataType;	/*��������Ϊ�ַ�����*/
#include"LinkStack.h"
#include"LinkQueue.h"
void PrintStackQueue(LStackNode *LStack,LinkQueue LQueue);
void main()
{
	DataType str1[]="ABCDEFEDCBA";	/*�����ַ�����1*/
	DataType str2[]="xabcdcaax";	/*�����ַ�����2*/
	int i;
	LinkQueue LQueue1,LQueue2;		/*������ʽѭ������*/
	LStackNode *LStack1,*LStack2;	/*������ջ*/
	InitQueue(&LQueue1);		/*��ʼ����ʽѭ������1*/
	InitQueue(&LQueue2);		/*��ʼ����ʽѭ������2*/
	InitStack(&LStack1);		/*��ʼ����ջ1*/
	InitStack(&LStack2);		/*��ʼ����ջ2*/
	for(i=0;i<strlen(str1);i++)
	{
		EnQueue(&LQueue1,str1[i]);	/*�ַ�����1���*/
	    PushStack(LStack1,str1[i]);	/*�ַ�����1��ջ*/
	}
	for(i=0;i<strlen(str2);i++)
	{
		EnQueue(&LQueue2,str2[i]);	/*�ַ�����2���*/
		PushStack(LStack2,str2[i]);	/*�ַ�����2��ջ*/
	}
	printf("�ַ�����1��%s\n",str1);
	PrintStackQueue(LStack1,LQueue1);
	printf("�ַ�����2��%s\n",str2);
	PrintStackQueue(LStack2,LQueue2);
}
void PrintStackQueue(LStackNode *LStack,LinkQueue LQueue)
{
	DataType st,qu;
	printf("��������  ��ջ����\n");
	while(!StackEmpty(LStack))		/*�ж�ջ1�Ƿ�Ϊ��*/
	{
		DeQueue(&LQueue,&qu);		/*�ַ����γ��ӣ�����Ԫ�ظ���q*/
		PopStack(LStack,&st);		/*�ַ���ջ������Ԫ�ظ���s*/	
		printf("%5c",qu);			/*����ַ�����1*/
		printf("%10c\n",st);
		if(qu!=st)				/*�ж��ַ�����1�Ƿ�Ϊ����*/
		{
			printf("���ַ����в��ǻ��ģ�\n");
			return;
		}
	}
	printf("���ַ������ǻ��ģ�\n");	
}