#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include"SeqString.h"
void InputString(char str[]);
void MaxEqSubStr(SeqString S,SeqString *T);
void SubString(SeqString S,SeqString *T,int s,int length);
void StrPrint(SeqString S);
void main()
{
	char str[MaxLen];
	SeqString S,T;
	cout<<"������һ���ַ�����"<<endl;
	InputString(str);
	StrAssign(&S,str);
	MaxEqSubStr(S,&T);
	cout<<"������һ���ַ���"<<endl;
	InputString(str);
	StrAssign(&S,str);
	MaxEqSubStr(S,&T);
}
void InputString(char str[])
//����������ַ�
{
	char ch;
	int i=0;
	while((ch=getchar())!='\n')
	{
		str[i++]=ch;
	}
	str[i]='\0';
}
void MaxEqSubStr(SeqString S,SeqString *T)
//������ֵ�Ӵ�
{
	int i=0,start1=0,start2=0,length1=1,length2=1;//start1,start2�������ֵ�Ӵ�����ʼλ��
	while(i<S.length)
	{
		i++;
		if(S.str[i]==S.str[start2])//����ǰ�ַ�����ʼλ���ַ���ȣ��򳤶ȼ�1
			length2++;
		else
		{
			if(length2>length1)//����ǰ����Ӵ����Ƚϴ��򱣴�֮
			{
				start1=start2;
				length1=length2;
			}
			start2=i;//�ӵ�ǰλ�����±Ƚ�
			length2=1;//�ָ����ȵ�ԭʼ״̬
		}
	}
	if(length1<2)
		cout<<"�޵�ֵ�Ӵ���"<<endl;
	else
	{
		SubString(S,T,start1,length1);
		StrPrint(*T);
	}
}
void SubString(SeqString S,SeqString *T,int s,int length)
//ȡ��S�еȳ��Ӵ���T��
{
	int j=0,i;
	for(i=s;i<s+length;i++)
		T->str[j++]=S.str[i];
	T->length=length;
}
void StrPrint(SeqString S)
{
	int i;
	for(i=0;i<S.length;i++)
		cout<<S.str[i];
	cout<<endl;
}