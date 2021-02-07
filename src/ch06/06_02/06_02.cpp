#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef char AtomType;
#include"GList.h"
#include"SeqString.h"
/*��������*/
void CreateList(GList *L,SeqString S);
void DistributeString(SeqString *Str,SeqString *HeadStr);
void PrintGList(GList L);
int GListAtomNum(GList L);
void StrPrint(SeqString S);
int SubString(SeqString *Sub,SeqString S,int pos,int len);
void main()
{
	GList L,T;
	SeqString S;
	int depth,length;
	/*���ַ�����ֵ����S*/
	StrAssign(&S,"((a,b),(),(a,(b,c,d)),(a,e))");
	CreateList(&L,S);					/*�ɴ����������L*/
	printf("�����");
	StrPrint(S);
	printf("�е�Ԫ��:\n");
	PrintGList(L);						/*���������е�Ԫ��*/
	length=GListLength(L);				/*������ĳ���*/
	printf("\n�����L�ĳ���length=%2d\n",length);
	depth=GListDepth(L);				/*����������*/
	printf("�����L�����depth=%2d\n",depth);
	printf("������е�ԭ�Ӹ�����%d\n",GListAtomNum(L));
	CopyList(&T,L);
	printf("�ɹ����L���Ƶõ������T.\n�����T��Ԫ��Ϊ:\n");
	PrintGList(T);
	length=GListLength(T);				/*������ĳ���*/
	printf("\n�����T�ĳ���length=%2d\n",length);
	depth=GListDepth(T);				/*����������*/
	printf("�����T�����depth=%2d\n",depth);
	StrAssign(&S,"((3,4),5,((6,3)))");
	CreateList(&L,S);
	printf("�����");
	StrPrint(S);
	GListAtomNum(L);
	printf("�е�ԭ�Ӹ�����%d\n",GListAtomNum(L));
}
int GListAtomNum(GList L)
{
	if(L==NULL)
		return 0;
	if(L->tag==0)
		return 1;
	if(L->tag==1)
		return GListAtomNum(L->ptr.hp)+GListAtomNum(L->ptr.tp);
}

void DistributeString(SeqString *Str,SeqString *HeadStr)
/*����Str������������֣�HeadStrΪ��һ������֮ǰ���Ӵ���StrΪ���ź���Ӵ�*/
{ 
	int len,i,k; 
	SeqString Ch,Ch1,Ch2,Ch3;
	len=StrLength(*Str);				/*lenΪStr�ĳ���*/
	StrAssign(&Ch1,",");				/*���ַ�','��'('��')'�ֱ𸳸�Ch1,Ch2��Ch3*/
	StrAssign(&Ch2,"("); 
	StrAssign(&Ch3,")"); 
	SubString(&Ch,*Str,1,1);			/*Ch����Str�ĵ�һ���ַ�*/
	for(i=1,k=0;i<=len&&StrCompare(Ch,Ch1)||k!=0;i++) /*����Str�����ĵ�һ������*/
	{ 
		SubString(&Ch,*Str,i,1);		/*ȡ��Str�ĵ�һ���ַ�*/
		if(!StrCompare(Ch,Ch2))		/*�����һ���ַ���'('������k��1*/
			k++;
		else if(!StrCompare(Ch,Ch3))	/*�����ǰ�ַ���')'������k��ȥ1*/
			k--; 
	}
	if(i<=len)						/*��Str�д���','�����ǵ�i-1���ַ�*/
	{
		SubString(HeadStr,*Str,1,i-2);	/*HeadStr���洮Str','ǰ���ַ�*/
		SubString(Str,*Str,i,len-i+1);	/*Str���洮Str','����ַ�*/
	}
	else							/*��Str�в�����','*/
	{
		StrCopy(HeadStr,*Str);		/*����Str�����ݸ��Ƶ���HeadStr*/
		StrClear(Str);				/*��մ�Str*/
	}
}
void CreateList(GList *L,SeqString S)
/*����ͷβ�����������*/
{
	SeqString Sub,HeadSub,Empty;
	GList p,q;
	StrAssign(&Empty,"()"); 
	if(!StrCompare(S,Empty))			/*�������Ĵ��ǿմ��򴴽�һ���յĹ����*/
		*L=NULL; 
	else 
	{
		if(!(*L=(GList)malloc(sizeof(GLNode))))		/*Ϊ���������һ�����*/
			exit(-1);
		if(StrLength(S)==1)						/*�������ԭ�ӣ���ԭ�ӵ�ֵ��ֵ���������*/
		{
			(*L)->tag=ATOM;
			(*L)->atom=S.str[0];
		}
		else									/*������ӱ�*/
		{
			(*L)->tag=LIST;
			p=*L;
			SubString(&Sub,S,2,StrLength(S)-2);	/*��Sȥ�����������ţ�Ȼ��ֵ��Sub*/
			do
			{ 
				DistributeString(&Sub,&HeadSub);	/*��Sub�������ͷ�ͱ�β�ֱ�ֵ��HeadSub��Sub*/
				CreateList(&(p->ptr.hp),HeadSub);	/*�ݹ�������ɹ����*/
				q=p;
				if(!StrEmpty(Sub))				/*�����β���գ������ɽ��p������βָ����ָ��p*/
				{
					if(!(p=(GLNode *)malloc(sizeof(GLNode))))
						exit(-1);
					p->tag=LIST;
					q->ptr.tp=p;
				}
			}while(!StrEmpty(Sub));
			q->ptr.tp=NULL;
		}
	}
}
void PrintGList(GList L)
/*���������Ԫ��*/
{
	if(L)								/*����������*/
	{
		if(L->tag==ATOM)				/*�����ԭ�ӣ������*/
			printf("%c ",L->atom);
		else 
		{
			PrintGList(L->ptr.hp);		/*�ݹ����L�ı�ͷ*/
			PrintGList(L->ptr.tp);			/*�ݹ����L�ı�β*/
		}
	}
}
void StrPrint(SeqString S)
{
	int i;
	for(i=0;i<S.length;i++)
	{
		printf("%c",S.str[i]);
	}
	printf("\n");
}

int SubString(SeqString *Sub,SeqString S,int pos,int len)
{
	int i;
	if(pos<0||len<0||pos+len-1>S.length)
	{
		printf("����pos��len���Ϸ�");
		return 0;
	}
	else
	{
		for(i=0;i<len;i++)
			Sub->str[i]=S.str[i+pos-1];
		Sub->length=len;
		return 1;
	}
}