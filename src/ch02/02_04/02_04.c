#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "string.h"
/*�궨�����ջ���Ͷ���*/
typedef char DataType;
#include"LinkStack.h"					/*������ջʵ���ļ�*/
void LineEdit();
void main()
{
	LineEdit();
}
void LineEdit()
/*�б༭����*/
{
    LinkStack S;
    char ch;
	DataType e;
	DataType a[50];
	int i,j=0;
    InitStack(&S);
    printf("�����ַ�����(#��ʾǰһ���ַ���Ч��@��ʾ��ǰ���ַ���Ч).\n");
    ch=getchar();
    while(ch!='\n')
    {
		switch(ch)
		{
		case '#':					/*�����ǰ�����ַ���'#'����ջ���գ���ջ���ַ���ջ*/
			if(!StackEmpty(S))
				PopStack(S,&ch);
			break;
		case '@': 					/*�����ǰ�����ַ���'@'����ջ���*/
			ClearStack(S);
			break;
		default: 					/*�����ǰ�����ַ�����'#'��'@'�����ַ���ջ*/
			PushStack(S,ch);
		}
		ch=getchar();					/*������һ���ַ�*/
	}
	while(!StackEmpty(S))
	{
		PopStack(S,&e);				/*���ַ���ջ������������a��*/
		a[j++]=e;
	}
	for(i=j-1;i>=0;i--)					/*�����ȷ���ַ�����*/
		printf("%c",a[i]);
	printf("\n");
	DestroyStack(S);
}