#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#define MAX 255
#include"SeqString.h"
int DelSubString(SeqString *S,int pos,int n);
void DelAllString(SeqString *S1,SeqString *S2);
void StrPrint(SeqString S) 
/*�������*/
{
	int i=0;
	for(i=0;i<S.length;i++)	
		cout<<S.str[i];
	cout<<endl;
}
void DispPrompt()
{
	printf("\n\t***********************************************");
	printf("\n\t*         ���Ļ�����������Ӧ��              *");
	printf("\n\t*********************************************\n");
	printf("\t *        1.���ĸ�ֵ       2.���Ƚ�           *\n");
	printf("\t *        3.���ĳ���       4.��������         * \n");
	printf("\t *        5.���Ĳ���       6.����ɾ��         * \n");
	printf("\t *        7.��ն���       8.�˳�             * \n");
	printf("\t **********************************************\n");
}
void main()
{
	int i,pos,k;
	char str[MAX];
	SeqString S,T;
	while(1)
	{
		DispPrompt();
		printf("��ѡ��ѡ��<1-8>: ");
		scanf(" %d",&k);
		if(k<0||k>8)
		{
			cout<<"������������������!";
			cout<<"\n";
			continue; 	
		}
		switch(k) 
		{  
		case 1:
			cout<<"�ַ����ĸ�ֵ:\n";
			cout<<"�����������ַ���!\n";
			cout<<"������1���ַ���; ";
			cin>>str;
			StrAssign(&S,str);
			cout<<"��������ַ���Ϊ: "<<endl;
			StrPrint(S);
			printf("\n");
			break;
        case 2:
			cout<<"���ıȽ�:\n";
			cout<<"�����������ַ���!\n";
			cout<<"�������1���ַ���; ";
			cin>>str;
			StrAssign(&S,str);
			cout<<"�������2���ַ���; ";
			cin>>str;
			StrAssign(&T,str);
			i=StrCompare( S,T);
			if(i==0)
				cout<<"�����ַ������!"<<endl;
			else if(i<0)	
				cout<<"��1���ַ����ȵ�2���ַ���С!"<<endl;
			else
				cout<<"��1���ַ����ȵ�2���ַ�����!"<<endl;
			break;
		case 3:
			cout<<"�󴮵ĳ���:\n";
			cout<<"�������ַ�����"<<endl;
			cin>>str;
			StrAssign(&S,str);
			i=StrLength(S);//���ú���
			cout<<"���ĳ���Ϊ"<<i<<endl;
			break;
		case 4:
			printf("�ַ�������\n");
			cout<<"�������1���ַ���; ";
			cin>>str;
			StrAssign(&S,str);
			cout<<"�������2���ַ���; ";
			cin>>str;
			StrAssign(&T,str);
			i= StrConcat(&S,T);
			if(i==0)
				cout<<"����ʧ��!"<<endl;
			else
			{
				cout<<"���Ӻ���´�Ϊ��"<<endl;
				StrPrint(S);
			}
			break;
		case 5:
			cout<<"�ַ�������:\n";
			cout<<"���������ַ���:"<<endl;
			cin>>str;		
			StrAssign(&S,str);
			cout<<"������Ҫ������ַ���:"<<endl;
			cin>>str;
			StrAssign(&T,str);
			cout<<"������Ҫ�����λ��:"<<endl;
			cin>>pos;
			StrInsert(&S,pos,T);
			cout<<"�����������Ϊ:"<<endl;
			StrPrint(S);
			cout<<endl;
			break;
		case 6:
			cout<<"���������ַ���:"<<endl;
			cin>>str;
			StrAssign(&S,str);
			cout<<"���������ַ���:"<<endl;
			cin>>str;
			StrAssign(&T,str);
			DelAllString(&S,&T);
			cout<<"ɾ�������Ӵ�����ַ���:"<<endl;
			StrPrint(S);
			break;
		case 7:
			StrClear(&S);
			break;
		case 8:
			break;
		}
  }
}
int Index(SeqString *S1,SeqString *S2)
{
	int i=0,j,k;
	while(i<S1->length)
	{
		j=0;
		if(S1->str[i]==S2->str[j])
		{
			k=i+1;
			j++;
			while(k<S1->length && j<S2->length && S1->str[k]==S2->str[j])
			{
				k++;
				j++;
			}
			if(j==S2->length)
				break;
			else
				i++;
		}
		else
			i++;
	}
	if(i>=S1->length)
		return -1;
	else
		return i+1;
}
int DelSubString(SeqString *S,int pos,int n)
{
	int i;
	if(pos+n-1>S->length)
		return 0;
	for(i=pos+n-1;i<S->length;i++)
		S->str[i-n]=S->str[i];
	S->length=S->length-n;
	S->str[S->length]='\0';
	return 1;
}
int StrLength(SeqString *S)
{
	return S->length;
}
void DelAllString(SeqString *S1,SeqString *S2)
{
	int n;
	n=Index(S1,S2);
	while(n>=0)
	{
		DelSubString(S1,n,StrLength(S2));
		n=Index(S1,S2);
	}
}