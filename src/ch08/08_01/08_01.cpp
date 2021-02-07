#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream.h>
#include<iomanip.h>
typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
#define INFINITY 65535			/*����һ�����޴��ֵ*/
#define MAXSIZE 100				/*��󶥵����*/
typedef enum{DG,DN,UG,UN}GraphKind; 	/*ͼ�����ͣ�����ͼ��������������ͼ��������*/
typedef struct
{
	VRType adj;				/*������Ȩͼ����1��ʾ���ڣ�0��ʾ�����ڣ����ڴ�Ȩͼ���洢Ȩֵ*/
	InfoPtr *info; 				/*�뻡��ߵ������Ϣ*/
}ArcNode,AdjMatrix[MAXSIZE][MAXSIZE];
typedef struct					/*ͼ�����Ͷ���*/
{
	VertexType vex[MAXSIZE]; 	/*���ڴ洢����*/
	AdjMatrix arc; 				/*�ڽӾ��󣬴洢�߻򻡵���Ϣ*/
	int vexnum,arcnum; 			/*�������ͱߣ���������Ŀ*/
	GraphKind kind; 			/*ͼ������*/
}MGraph;
void CreateGraph(MGraph *N);
int LocateVertex(MGraph N,VertexType v);
void DestroyGraph(MGraph *N);
void DisplayGraph(MGraph N);
void main()
{
	MGraph N;
	cout<<"����һ������"<<endl;
	CreateGraph(&N);
	cout<<"������Ķ���ͻ���"<<endl;
	DisplayGraph(N);
	DestroyGraph(&N);
}
void CreateGraph(MGraph *N)
/*�����ڽӾ����ʾ������������N*/
{ 
	int i,j,k,w;
	VertexType v1,v2;
	cout<<"������������N�Ķ������ͻ���: ";
	cin>>(*N).vexnum>>(*N).arcnum;
	cout<<"������"<<N->vexnum<<"�������ֵ:"<<endl;
	for(i=0;i<N->vexnum;i++)		/*����һ�����飬���ڱ������ĸ�������*/
		cin>>N->vex[i];
	for(i=0;i<N->vexnum;i++)		/*��ʼ���ڽӾ���*/
		for(j=0;j<N->vexnum;j++)
		{
			N->arc[i][j].adj=INFINITY; 
			N->arc[i][j].info=NULL;	/*������Ϣ��ʼ��Ϊ��*/
		}
		cout<<"��ֱ�����"<<N->arcnum<<"�����Ļ�β ��ͷ Ȩֵ(�Կո�ָ�):"<<endl;
		for(k=0;k<N->arcnum;k++)
		{
			cin>>v1>>v2>>w;	/*������������ͻ���Ȩֵ*/
			i=LocateVertex(*N,v1);
			j=LocateVertex(*N,v2);
			N->arc[i][j].adj=w;
		}
		N->kind=DN;						/*ͼ������Ϊ������*/
}
int LocateVertex(MGraph N,VertexType v)
/*�ڶ��������в��Ҷ���v���ҵ���������������ţ����򷵻�-1*/
{ 
	int i;
	for(i=0;i<N.vexnum;++i)
		if(strcmp(N.vex[i],v)==0)
			return i;
		return -1;
}
void DestroyGraph(MGraph *N)
/*������N*/
{ 
	int i,j;
	for(i=0;i<N->vexnum;i++)				/*�ͷŻ��������Ϣ*/
		for(j=0;j<N->vexnum;j++)
			if(N->arc[i][j].adj!=INFINITY)	/*������ڻ�*/
				if(N->arc[i][j].info!=NULL) /*������������Ϣ���ͷŸ���Ϣ��ռ�ÿռ�*/
				{
					free(N->arc[i][j].info);
					N->arc[i][j].info=NULL;
				}
	N->vexnum=0;	 			/*�����Ķ�������Ϊ0*/
	N->arcnum=0; 				/*�����Ļ�����Ŀ��Ϊ0*/
}
void DisplayGraph(MGraph N)
/*����ڽӾ���洢��ʾ��ͼN*/
{ 
	int i,j;
	cout<<"����������"<<N.vexnum<<"������"<<N.arcnum<<"����������������: ";
	for(i=0;i<N.vexnum;++i)				/*������Ķ���*/
		cout<<N.vex[i]<<" ";
	cout<<endl<<"������N��:"<<endl;			/*�����N�Ļ�*/
	cout<<"���㣺";
	for(i=0;i<N.vexnum;i++)
		cout<<setw(7)<<N.vex[i];
	cout<<endl;
	for(i=0;i<N.vexnum;i++)
	{
		cout<<setw(6)<<N.vex[i];
		for(j=0;j<N.vexnum;j++)
			cout<<setw(7)<<N.arc[i][j].adj;
		cout<<endl; 
	}
}
