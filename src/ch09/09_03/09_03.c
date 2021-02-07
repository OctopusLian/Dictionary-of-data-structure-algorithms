#include<stdio.h>
void ShellSort(int a[],int length,int delta[],int m);
void ShellInsert(int a[],int length,int c);
void DispArray(int a[],int length);
void main()
{
	int a[]={55,72,31,24,86,16,37,8};
	int delta[]={4,2,1},m=3,n;
	n=sizeof(a)/sizeof(a[0]);
	printf("ϣ������ǰ:\n");
	DispArray(a,n);
	ShellSort(a,n,delta,m);
	printf("ϣ��������:");
	DispArray(a,n);
}
void ShellInsert(int a[],int length,int c)
/*�������е�Ԫ�ؽ���һ��ϣ������c������*/
{
	int i,j,t;
	for(i=c;i<length;i++)				/*������Ϊc��Ԫ����Ϊһ�������н�������*/
	{
		if(a[i]<a[i-c])				/*�������С��ǰ�ߣ�����Ҫ�ƶ�Ԫ��*/
		{
			t=a[i];
			for(j=i-c;j>=0&&t<a[j];j=j-c)
				a[j+c]=a[j];
			a[j+c]=t;				/*���ν�Ԫ�ز��뵽��ȷ��λ��*/
		}
	}
}
void ShellSort(int a[],int length,int delta[],int m)
/*ϣ������ÿ�ε����㷨ShellInsert,delta�Ǵ������������*/
{
	int i;
	for(i=0;i<m;i++)			/*����m��ϣ����������*/
	{
		ShellInsert(a,length,delta[i]);
		printf("��%d��������:",i+1);
		DispArray(a,length);
	}
}
void DispArray(int a[],int length)
/*�������a�е�Ԫ��*/
{
	int i;
	for(i=0;i<length;i++)
		printf("%4d",a[i]);
	printf("\n");
}
