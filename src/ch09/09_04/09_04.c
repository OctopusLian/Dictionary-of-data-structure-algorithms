#include<stdio.h>
void PrintArray(int a[],int n);
void BubbleSort(int a[],int n);
void BubbleSort2(int a[],int n);
void main()
{
	int a[]={56,22,67,32,59,12,89,26,48,37};
	int n=sizeof(a)/sizeof(a[0]);
	printf("ð������ǰ:\n");
	PrintArray(a,n);
	printf("ð������:\n");
	BubbleSort2(a,n);
	PrintArray(a,n);
}
void BubbleSort(int a[],int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		printf("��%d��������:",i);
		PrintArray(a,n);
	}
}
void PrintArray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
	printf("\n");
}
void BubbleSort2(int a[],int n)
/*˫��ð�����򣬴�ǰ�������������ð������*/
{
	int i,t,flag=1;/*һ�������Ԫ���Ƿ��н���*/
	int low=0,high=n-1;
	while(low<high && flag)/*��flagΪ0˵����û������Ԫ��*/
	{
		flag=0;/*ÿ�˿�ʼ��flag��Ϊ0*/
		for(i=low;i<high;i++)/*��ǰ�������ð������*/
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
				flag=1;/*�н���*/
			}
		}
		high--;/*�����Ͻ�*/
		for(i=high;i>low;i--)/*�Ӻ�ǰ����ð������*/
		{
			if(a[i]<a[i-1])
			{
				t=a[i];
				a[i]=a[i-1];
				a[i-1]=t;
				flag=1;/*�н���*/
			}
		}
		low++;/*�����½�*/
		printf("��%d��������:",i);
		PrintArray(a,n);
	}
}