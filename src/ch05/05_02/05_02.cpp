#include<iostream.h>
#include<iomanip.h>	
#define MAX 100							
void SplitArray(int c[],int n);	
void PrintArray(int a[],int n);	
void main()
{
	int n;			
	int c[]={29,54,68,32,49,21,396,207,181};
	n=sizeof(c)/sizeof(c[0]);
	cout<<"����c�е�Ԫ��:"<<endl;
	PrintArray(c,n);
	cout<<"����c������(���Ԫ��Ϊ����,�ұ�Ԫ��Ϊż��):"<<endl;
	SplitArray(c,n);					/*���������е�Ԫ��*/
	PrintArray(c,n);
}
void SplitArray(int c[],int n)
/*������a�ֳ��������֣�������������ұ���ż��*/
{
	int i,j,t;					/*��������ָʾ��i��j*/
	i=0,j=n-1;		/*ָʾ��i��j�ֱ�ָʾ˳������˺��Ҷ�Ԫ��*/
	while(i<j)		
	{
		while(c[i]%2!=0)	/*i��������Ԫ��*/
			i++;				/*�Թ�*/
		while(c[j]%2==0)		/*j����ż��Ԫ��*/
			j--;				/*�Թ�*/
		if(i<j)					/*����i��jָ���Ԫ��*/
		{
			t=c[i];
			c[i]=c[j];
			c[j]=t;
		}	
	}
}
void PrintArray(int a[],int n)
//�������a�е�Ԫ��
{
	int i;
	for(i=0;i<n;i++)
		cout<<setw(4)<<a[i];
	cout<<endl;
}