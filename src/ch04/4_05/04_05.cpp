#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqString.h"
#include<iostream.h>
#include<iomanip.h>
int B_FIndex(SeqString S,int pos,SeqString T,int *count);
int KMP_Index(SeqString S,int pos,SeqString T,int next[],int *count);
void GetNext(SeqString T,int next[]);
void PrintArray(SeqString T,int next[],int length);
void main()
{
	SeqString S,T;
	int count1=0,count2=0,find;
	int next[40];
    /*��1������*/
	StrAssign(&S,"bcdamnbacabaabaabacababafabacabababab");		/*������S��ֵ*/
	StrAssign(&T,"abaabacababa");				/*��ģʽ��T��ֵ*/
	GetNext(T,next);					/*��next����ֵ*/
	cout<<"ģʽ��T��next�͸Ľ����nextֵ:"<<endl;
	PrintArray(T,next,StrLength(T));	/*���ģʽ��T��nextֵ*/
	find=B_FIndex(S,1,T,&count1);				/*Brute-Forceģʽ��ƥ��*/
	if(find>0)
		cout<<"Brute-Force�㷨�ıȽϴ���Ϊ:"<<count1<<endl;
	find=KMP_Index(S,1,T,next,&count2);
	if(find>0)
		cout<<"����next��KMP�㷨�ıȽϴ���Ϊ:"<<count2<<endl;
    /*��2������*/
	StrAssign(&S,"bcdabcacbdaacabcabaacaabcabcabcbccbcabccbdcabcb");		/*������S��ֵ*/
	StrAssign(&T,"abcabcbc");						/*��ģʽ��T��ֵ*/
	GetNext(T,next);							/*��next����ֵ*/
	PrintArray(T,next,StrLength(T));			/*���ģʽ��T��nextֵ*/
	find=B_FIndex(S,1,T,&count1);					/*Brute-Forceģʽ��ƥ��*/
	if(find>0)
		cout<<"Brute-Force�㷨�ıȽϴ���Ϊ:"<<count1<<endl;
	find=KMP_Index(S,1,T,next,&count2);
	if(find>0)
		cout<<"����next��KMP�㷨�ıȽϴ���Ϊ:"<<count2<<endl;
}
void PrintArray(SeqString T,int next[],int length)
/*ģʽ��T��nextֵ�������*/
{
	int j;
	cout<<"j:\t\t";
	for(j=0;j<length;j++)
		cout<<setw(3)<<j;
	cout<<endl;
	cout<<"ģʽ��:\t\t";
	for(j=0;j<length;j++)
		cout<<setw(3)<<T.str[j];
	cout<<endl;
	cout<<"next[j]:\t";
	for(j=0;j<length;j++)
		cout<<setw(3)<<next[j];
	cout<<endl;
}
int B_FIndex(SeqString S,int pos,SeqString T,int *count) 
/*������S�еĵ�pos��λ�ÿ�ʼ�����Ӵ�T������ҵ������Ӵ���������λ�ã����򣬷���-1*/
{
	int i,j;
	i=pos-1;
	j=0;
	*count=0;						/*count����������ģʽ���ıȽϴ���*/
	while(i<S.length&&j<T.length)
	{
		if(S.str[i]==T.str[j]) 		/*����S�ʹ�T�ж�Ӧλ���ַ���ȣ�������Ƚ���һ���ַ�*/
		{
			i++;
			j++;
		}
		else		/*����ǰ��Ӧλ�õ��ַ�����ȣ���Ӵ�S����һ���ַ���ʼ��T�ĵ�0���ַ���ʼ�Ƚ�*/
		{
			i=i-j+1;
			j=0;
		}
		(*count)++;
	}
	if(j>=T.length) 				/*�����S���ҵ���T���򷵻��Ӵ�T������S��λ��*/
		return i-j+1;
	else
		return -1;
}
int KMP_Index(SeqString S,int pos,SeqString T,int next[],int *count)
/*KMPģʽƥ���㷨������ģʽ��T��next����������S�еĵ�pos��λ�ÿ�ʼ�����Ӵ�T������ҵ������Ӵ���������λ�ã����򣬷���-1*/
{
    int i,j;
    i=pos-1;
    j=0;
	*count=0;								/*count����������ģʽ���ıȽϴ���*/
    while(i<S.length&&j<T.length)
    {
        if(j==-1||S.str[i]==T.str[j])		/*���j=-1��ǰ�ַ���ȣ�������ȽϺ�����ַ�*/
        {
            i++;
            j++;
        }
        else						/*�����ǰ�ַ�����ȣ���ģʽ�������ƶ�*/
            j=next[j];
		(*count)++;
    }
    if(j>=T.length) 					/*ƥ��ɹ��������Ӵ��������е�λ�á����򷵻�-1*/
        return i-T.length+1;
    else
        return -1;
}
void GetNext(SeqString T,int next[])
/*��ģʽ��T��next����ֵ����������next*/
{
    int j,k;
    j=0;
	k=-1;
    next[0]=-1;
    while(j<T.length)
    {
        if(k==-1||T.str[j]==T.str[k])		/*���k=-1��ǰ�ַ���ȣ�������ȽϺ�����ַ���������ֵ���뵽next����*/
        {
            j++;
            k++;
            next[j]=k;
        }
        else						/*�����ǰ�ַ�����ȣ���ģʽ�������ƶ������Ƚ�*/
            k=next[k];
    }
}
