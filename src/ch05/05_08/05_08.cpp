����#include<iostream.h>
����#include<iomanip.h>
����#define MAX 200
����void CreateArray(int a[][MAX],int n);
����void PrintArray(int a[MAX][MAX],int n);
����void Trans(int b[],int c[],int n);
����int PriorRow(int a[][MAX],int n,int b[]);
����void main()
����{
����	int a[MAX][MAX],b[MAX],c[MAX],n,m,i;
����	cout<<"������һ��������<100��:"<<endl;
����	cin>>n;
����	CreateArray(a,n);
����	cout<<"��ά����Ϊ:"<<endl;
����	PrintArray(a,n);	
����	m=PriorRow(a,n,b);
����	cout<<"����b�е�Ԫ��:"<<endl;
����	for(i=0;i<m;i++)
����		cout<<setw(4)<<b[i];
����	cout<<endl;
����	Trans(b,c,n);
����	cout<<"����c�е�Ԫ��:"<<endl;
����	for(i=0;i<m;i++)
����		cout<<setw(4)<<c[i];
����	cout<<endl;
����}
����int PriorRow(int a[MAX][MAX],int n,int b[])
����//�����ȴ洢�����Ǿ���b��
����{
����	int i,j,k=0;
����	for(i=0;i<n;i++)
����		for(j=i;j<n;j++)
����			b[k++]=a[i][j];
����	return k;
����}
����void CreateArray(int a[][MAX],int n)
����//����һ��������1-n�Ķ�ά���飨����
����{
����	int i,j,m;
����	m=1;
����	for(i=0;i<n;i++)
����	{
����		for(j=0;j<i;j++)
����			a[i][j]=0;
����		for(j=i;j<n;j++)
����			a[i][j]=m++;
����	}
����}
����void PrintArray(int a[MAX][MAX],int n)
����//��ӡ����
����{
����	int i,j;
����	for(i=0;i<n;i++)
����	{
����		for(j=0;j<n;j++)
����			cout<<setw(4)<<a[i][j];
����		cout<<endl;
����	}
����}
����void Trans(int b[],int c[],int n)
����/*��b��Ԫ�ذ���Ϊ����������ŵ�����c��*/
����{
����	int step=n,count=0,i=0,j=0,k;
����	for(k=0;k<n*(n+1)/2;k++)
����	{
����		count++;			/*��¼һ���Ƿ����*/
����		c[j*(j+1)/2+i]=b[k];/*������Ϊ���������ŵ���Ӧ����Ϊ�����������*/
����		if(count==step)/*һ�ж����*/
����		{
����			step--;
����			count=0;/*��һ�����¿�ʼ����*/
����			i++;/*��һ�еĿ�ʼ��*/
����			j=n-step;/*һ�ж������һ�ֵĿ�ʼ��*/
����		}
����		else
����			j++;/*һ�л�û�ж��꣬������һ�е���*/
����	}
����}