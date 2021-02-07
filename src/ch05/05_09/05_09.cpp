#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<iostream.h>
#include<iomanip.h>
typedef int DataType;
#include"TriSeqMatrix.h"
int AddMatrix(TriSeqMatrix A,TriSeqMatrix B,TriSeqMatrix *C);
void PrintMatrix(TriSeqMatrix M);
void PrintMatrix2(TriSeqMatrix M);
int CreateMatrix(TriSeqMatrix *M); 
int CompareElement(int a,int b);
void main()
{
	TriSeqMatrix M,N,Q;
	CreateMatrix(&M);
	PrintMatrix2(M);
	CreateMatrix(&N);
	PrintMatrix2(N);
	AddMatrix(M,N,&Q);
	PrintMatrix(Q);
	PrintMatrix2(Q);	
}
void PrintMatrix(TriSeqMatrix M)
/*���ϡ�����*/
{ 
	int i;
	cout<<"ϡ�������"<<M.m<<"�С�"<<M.n<<"�У���"<<M.len<<"������Ԫ��"<<endl;
	cout<<"��    ��    Ԫ��ֵ"<<endl;
	for(i=0;i<M.len;i++)
		cout<<setw(2)<<M.data[i].i<<setw(6)<<M.data[i].j<<setw(8)<<M.data[i].e<<endl;
}
void PrintMatrix2(TriSeqMatrix M)
/*��������ʽ���ϡ�����*/
{ 
	int k,i,j;
	DataType a[MaxSize][MaxSize];
	for(i=0;i<M.m;i++)//��ʼ������a��ȫ��Ԫ����Ϊ0
		for(j=0;j<M.n;j++)
			a[i][j]=0;
	for(k=0;k<M.len;k++)//����0Ԫ�ش�������a
	{
		if(M.data[k].e!=0)
		{
			i=M.data[k].i;
			j=M.data[k].j;
			a[i][j]=M.data[k].e;
		}
	}
	cout<<"ϡ�����(��������ʽ���):"<<endl;
	for(i=0;i<M.m;i++)//��������ʽ�������a�е�Ԫ��
	{
		for(j=0;j<M.n;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
}
int AddMatrix(TriSeqMatrix A,TriSeqMatrix B,TriSeqMatrix *C)
/*����������A��B��Ӧ��Ԫ��ֵ��ӣ��õ���һ��ϡ�����C*/
{
	int m=0,n=0,k=-1;
	if(A.m!=B.m||A.n!=B.n) /*��������������������������ȣ����ܹ������������*/
		return 0;
	C->m=A.m;
	C->n=A.n;
	while(m<A.len&&n<B.len) 
	{
		switch(CompareElement(A.data[m].i,B.data[n].i))/*�Ƚ����������ӦԪ�ص��к�*/
		{
		case -1: 
			C->data[++k]=A.data[m++];	/*������A�����к�С��Ԫ�ظ�ֵ��C*/
			break;
		case  0:
			/*�������A��B���к���ȣ���Ƚ��к�*/
			switch(CompareElement(A.data[m].j,B.data[n].j)) 
			{
			case -1:					/*���A���к�С��B���кţ��򽫾���A��Ԫ�ظ�ֵ��C*/
				C->data[++k]=A.data[m++];
				break;
			case  0:					/*���A��B���кš��кž���ȣ�����Ԫ����ӣ�����C*/
				C->data[++k]=A.data[m++]; 
				C->data[k].e+=B.data[n++].e; 
				if(C->data[k].e==0)		/*�������Ԫ�صĺ�Ϊ0���򲻱���*/
					k--;
				break;
			case  1:					/*���A���кŴ���B���кţ��򽫾���B��Ԫ�ظ�ֵ��C*/
				C->data[++k]=B.data[n++];
			}
			break;
			case  1:						/*���A���кŴ���B���кţ��򽫾���B��Ԫ�ظ�ֵ��C*/
				C->data[++k]=B.data[n++]; 
		}
	}
	while(m<A.len)						/*�������A��Ԫ�ػ�û������ϣ���A�е�Ԫ�ظ�ֵ��C*/
		C->data[++k]=A.data[m++];
	while(n<B.len)						/*�������B��Ԫ�ػ�û������ϣ���B�е�Ԫ�ظ�ֵ��C*/
		C->data[++k]=B.data[n++];
	C->len=k+1;							/*�޸ķ���Ԫ�صĸ���*/
	if(k>MaxSize)						
		return 0;
	return 1;
}
int CompareElement(int a,int b)
/*�Ƚ����������Ԫ��ֵ��С��ǰ��С�ں��ߣ�����-1����ȣ�����0�����ڣ�����1*/
{ 
	if(a<b)
		return -1;
	if(a==b)
		return 0;
	return 1;
}