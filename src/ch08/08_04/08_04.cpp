#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
const int N=100;
int G[N][N];//0��ʾ�����ڻ���1��ʾ���ڻ�
int path[N], visited[N],n,cycle;
int DFS(int u,int start)
//������ȱ�������ͼ
{
	int i;
    visited[u] =-1;//����u���Ϊ�ѷ���
    path[u] =start;//��¼Դ����
    for(i=0;i<n;i++) 
	{
		if(G[u][i]&&i!=start)//u��i���ڻ���i������start
		{
			if(visited[i]<0) 
			{ 
				cycle =u;
				return 0;
			}
			if(!DFS(i,u))//������·��������������
				return 0;
		}
	}
	visited[u] =1;
	return 1;//u��i�����ڻ��򷵻�1����ζ��ֹͣ�˴��������
}
void DisPath(int u)
//������еĶ���
{
    if(u<0) 
		return;
    DisPath(path[u]);
    cout<<" "<<u;
}
void main()
{
	int i,j;
	cout<<"������ͼ�еĶ������:"<<endl;
	cin>>n;
    memset(G,0,sizeof(G));
	cout<<"������һ��"<<n<<"*"<<n<<"����1��ʾ���ڻ���0��ʾ�����ڻ���:"<<endl;
    for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			cin>>G[i][j];
		}
    }
	cycle =-1;
	for(i=0;i<n;i++) 
	{
		if(!visited[i]&&!DFS(i,-1))//����i��û�б�����
			break;
	}
	if(cycle<0)
		cout<<"�����ڻ�!"<<endl;
	else
	{
		cout<<"���ڻ�!"<<endl;
		DisPath(cycle);
		cout<<endl;
	}
}