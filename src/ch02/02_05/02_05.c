#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "string.h"
/*�궨�����ջ���Ͷ���*/
typedef char DataType;
#include"LinkStack.h"					/*������ջʵ���ļ�*/
int Match(DataType e,DataType ch); 		/*���������Ƿ�ƥ�亯��*/
void main()
{
    LinkStack S;
	char *p;
	DataType e;
	DataType ch[60];
	InitStack(&S);						/*��ʼ����ջ*/
	printf("�������������ʽ(���԰�������'{}','[]','()'):\n");
	gets(ch);
	p=ch; 							/*pָ����������ű��ʽ*/
	while(*p) 							/*�ж�pָ����ַ��Ƿ����ַ����������*/
	{
		switch(*p)
		{
		case '(':
		case '[':
		case '{':
			PushStack(S,*p++);			/*����������ţ������Ž�ջ*/
			break;
		case ')':
		case ']':
		case '}':
			if(StackEmpty(S)) 			/*�������������ջ�ѿգ�˵��ȱ��������*/
			{
				printf("ȱ��������.\n");
				return;
			}
			else
			{
				GetTop(S,&e);			/*���ջ���գ�������������ţ���ȡ��ջ��������*/
				if(Match(e,*p)) 			/*��ջ�������������������Ž��бȽ�*/
					PopStack(S,&e); 	/*���ջ������������������ƥ�䣬��ջ�������ų�ջ*/
				else					/*���ջ���������������Ų�ƥ�䣬��˵�����������в�ƥ��*/
				{
					printf("�������Ų�ƥ��.\n");
					return;
				}
			}
		default: 						/*����������ַ����򲻴���ֱ�ӽ�pָ����һ���ַ�*/
			p++;
		}
	}
	if(StackEmpty(S)) 					/*����ַ����ж�����ϣ���ջ�ѿգ�˵����������ƥ��*/
		printf("����ƥ��.\n");
	else                                /*����ַ����ж�����ϣ���ջ���գ�˵��ȱ��������*/
		printf("ȱ��������.\n");			
}
int Match(DataType e,DataType ch)
/*�ж��������������Ƿ�Ϊͬ���͵����ţ�ͬ�����򷵻�1�����򷵻�0*/
{
	if(e=='('&&ch==')')
		return 1;
	else if(e=='['&&ch==']')
		return 1;
	else if(e=='{'&&ch=='}')
		return 1;
	else
		return 0;
}