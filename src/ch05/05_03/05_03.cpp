#include<iostream.h>
#include<iomanip.h>
#define MAX 20
void main()
{
	int a[MAX][MAX],i,j,t,p=1,n;
	cout<<"���������Ľ�:"<<endl;
	cin>>n;
	cout<<"*******��תǰ�ľ���*******"<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=p++;
			cout<<setw(4)<<a[i][j];
		}
		cout<<endl;
	}
	cout<<"*******˳ʱ����ת��ľ���*******"<<endl;
	for(i=1;i<=n/2;i++)
	{
		for(j=i;j<n-i+1;j++)
		{
			t=a[i][j];
			a[i][j]=a[n-j+1][i];
			a[n-j+1][i]=a[n-i+1][n-j+1];
			a[n-i+1][n-j+1]=a[j][n-i+1];
			a[j][n-i+1]=t;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				cout<<setw(4)<<a[i][j];
			cout<<endl;
		}
	}
}