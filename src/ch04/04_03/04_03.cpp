#include<iostream.h>
#include<stdio.h>
#include"SeqString.h"
#define MAX 255
void MaxComStr(SeqString S,SeqString T,int *index,int *length);
void main()
{
	char str1[MAX],str2[MAX];
	int index,length,i;
	SeqString S,T;
	cout<<"�������1���ַ���:"<<endl;
	cin>>str1;
	StrAssign(&S,str1);
	cout<<"������ڶ����ַ���:"<<endl;
	cin>>str2;
	StrAssign(&T,str2);
	MaxComStr(S,T,&index,&length);
	cout<<"������Ӵ�Ϊ:"<<endl;
	for(i=index;i<index+length;i++)
		cout<<S.str[i];
	cout<<endl;
}
void MaxComStr(SeqString S,SeqString T,int *index,int *length)
//��S��T��������Ӵ�
{
	int i,j,k,length1,con;
	*index=0;
	*length=0;
	i=0;
	while(i<S.length)
	{
		j=0;
		while(j<T.length)
		{
			if(S.str[i]==T.str[j])//�����S��T��ǰ��Ӧ�ַ����
			{
				k=1;
				length1=1;
				con=1;
				while(con)
				{
					if(i+k<S.length&&j+k<T.length&&S.str[i+k]==T.str[j+k])//�����S��T�ĳ����ڣ���Ӧ�ַ���ȣ���ָ��k���ƱȽ���һ���ַ�
					{
						length1=length1+1;//��ǰ�����Ӵ����ȼ�1
						k++;
					}
					else
						con=0;//S��T��Ӧ���ַ����ȣ��򽫱����Ϊ0
				}
				if(length1>*length)//���һ�αȽϽ�������ǰ�õ��Ĺ����Ӵ����ȴ���length���򱣳ֵ�length��
				{
					*index=i;
					*length=length1;
				}
				j+=k;//��T�ĵ�j+k���ַ��������S�ĵ�i���ַ��Ƚ�
			}
			else
				j++;//�Ӵ�T����һ���ַ�����S�ĵ�i���ַ��Ƚ�
		}
		i++;//����S����һ���ַ���ʼ��T���бȽ�
	}
}