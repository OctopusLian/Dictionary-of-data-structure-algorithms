#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream.h>
#include<iomanip.h>
typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
#define MAXSIZE 50				/*��󶥵����*/
typedef enum{DG,DN,UG,UN}GraphKind; 	/*ͼ�����ͣ�����ͼ��������������ͼ��������*/
//�������ڽӾ�������Ͷ���
typedef struct
{
	VRType adj;				/*������Ȩͼ����1��ʾ���ڣ�0��ʾ�����ڣ����ڴ�Ȩͼ���洢Ȩֵ*/
	InfoPtr *info; 				/*�뻡��ߵ������Ϣ*/
}AdjMatrix[MAXSIZE][MAXSIZE];
typedef struct					/*ͼ�����Ͷ���*/
{
	VertexType vex[MAXSIZE]; 	/*���ڴ洢����*/
	AdjMatrix arc; 				/*�ڽӾ��󣬴洢�߻򻡵���Ϣ*/
	int vexnum,arcnum; 			/*�������ͱߣ���������Ŀ*/
	GraphKind kind; 			/*ͼ������*/
}MGraph;
//�������ڽӱ�����Ͷ���
typedef struct ArcNode			/*�߽������Ͷ���*/
{
    int adjvex; 				/*��ָ��Ķ����λ��*/
	InfoPtr *info;				/*�뻡��ص���Ϣ*/
	struct ArcNode *nextarc; 	/*ָʾ��һ����ö������ڽӵĶ���*/
}ArcNode;
typedef struct VNode			/*ͷ�������Ͷ���*/
{
	VertexType data; 			/*���ڴ洢����*/
	ArcNode *firstarc; 			/*ָʾ��һ����ö����ڽӵĶ���*/
}VNode,AdjList[MAXSIZE];
typedef struct					/*ͼ�����Ͷ���*/
{
	AdjList vertex;
	int vexnum,arcnum;			/*ͼ�Ķ�����Ŀ�뻡����Ŀ*/
	GraphKind kind; 			/*ͼ������*/
}AdjGraph;
void CreateGraph(MGraph *G);
int LocateVertex(MGraph G,VertexType v);
void DestroyGraph(MGraph *G);
void DisplayGraph(MGraph G);
void DisplayAdjGraph(AdjGraph G);
void ConvertGraph(AdjGraph *A,MGraph M);
void main()
{
	MGraph M;
	AdjGraph A;
	cout<<"����һ������ͼ��"<<endl;
	CreateGraph(&M);
	cout<<"������Ķ���ͻ���"<<endl;
	DisplayGraph(M);
	ConvertGraph(&A,M);
	DisplayAdjGraph(A);
	DestroyGraph(&M);
}
void CreateGraph(MGraph *G)
/*�����ڽӾ����ʾ����������ͼG*/
{ 
	int i,j,k;
	VertexType v1,v2;
	cout<<"����������ͼG�Ķ������ͻ���: ";
	cin>>(*G).vexnum>>(*G).arcnum;
	cout<<"������"<<G->vexnum<<"�������ֵ:"<<endl;
	for(i=0;i<G->vexnum;i++)		/*����һ�����飬���ڱ���ͼ�ĸ�������*/
		cin>>G->vex[i];
	for(i=0;i<G->vexnum;i++)		/*��ʼ���ڽӾ���*/
		for(j=0;j<G->vexnum;j++)
		{
			G->arc[i][j].adj=0; 
			G->arc[i][j].info=NULL;	/*������Ϣ��ʼ��Ϊ��*/
		}
		cout<<"������"<<G->arcnum<<"�����Ļ�β ��ͷ(�Կո�ָ�): "<<endl;
		for(k=0;k<G->arcnum;k++)
		{
			cin>>v1>>v2;	/*������������Ԫ��*/
			i=LocateVertex(*G,v1);
			j=LocateVertex(*G,v2);
			G->arc[i][j].adj=1;
		}
		G->kind=DG;						/*ͼ������Ϊ����ͼ*/
}
int LocateVertex(MGraph G,VertexType v)
/*�ڶ��������в��Ҷ���v���ҵ���������������ţ����򷵻�-1*/
{ 
	int i;
	for(i=0;i<G.vexnum;++i)
		if(strcmp(G.vex[i],v)==0)
			return i;
		return -1;
}
void DestroyGraph(MGraph *G)
/*��������ͼG*/
{ 
	int i,j;
	for(i=0;i<G->vexnum;i++)				/*�ͷŻ��������Ϣ*/
		for(j=0;j<G->vexnum;j++)
			if(G->arc[i][j].adj!=0)	/*������ڻ�*/
				if(G->arc[i][j].info!=NULL) /*������������Ϣ���ͷŸ���Ϣ��ռ�ÿռ�*/
				{
					free(G->arc[i][j].info);
					G->arc[i][j].info=NULL;
				}
				G->vexnum=0;	 			/*������ͼ�Ķ�������Ϊ0*/
				G->arcnum=0; 				/*��ͼ�Ļ�����Ŀ��Ϊ0*/
}
void DisplayGraph(MGraph G)
/*����ڽӾ���洢��ʾ��ͼG*/
{ 
	int i,j;
	cout<<"����ͼ����"<<G.vexnum<<"������"<<G.arcnum<<"����������������: ";
	for(i=0;i<G.vexnum;++i)				/*���ͼ�Ķ���*/
		cout<<"  "<<G.vex[i];
	cout<<endl<<"����ͼG:"<<endl;			
	/*���ͼG���ڽӾ���*/
	cout<<"���㣺";
	for(i=0;i<G.vexnum;i++)
		cout<<setw(4)<<G.vex[i];
	cout<<endl;
	for(i=0;i<G.vexnum;i++)
	{
		cout<<setw(6)<<G.vex[i];
		for(j=0;j<G.vexnum;j++)
			cout<<setw(4)<<G.arc[i][j].adj;
		cout<<endl; 
	}
}
void ConvertGraph(AdjGraph *A,MGraph M)
//�������ڽӾ����ʾ������ͼMת�����ڽӱ�A
{ 
	int i,j;
	ArcNode *p;
	A->vexnum=M.vexnum;
	A->arcnum=M.arcnum;
	A->kind=M.kind;
	for(i=0;i<A->vexnum;i++)			/*������洢��ͷ�����*/
	{
		strcpy(A->vertex[i].data,M.vex[i]);
		A->vertex[i].firstarc=NULL;	/*��������Ķ�����Ϊ��*/
	}
	printf("�����뻡β�ͻ�ͷ(�Կո���Ϊ���):\n");
	for(i=0;i<M.arcnum;i++)			/*����������*/
		for(j=0;j<M.arcnum;j++)
			if(M.arc[i][j].adj==1)
			{	
				/*jΪ��ͷiΪ��β�����ڽӱ�*/
				p=(ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->info=NULL;
				p->nextarc=A->vertex[i].firstarc;
				A->vertex[i].firstarc=p;
			}
			
			(*A).kind=DG;
}
void DisplayAdjGraph(AdjGraph G)
/*���ͼ���ڽӾ���G*/
{ 
	int i;
	ArcNode *p;
	cout<<G.vexnum<<"�����㣺"<<endl;
	for(i=0;i<G.vexnum;i++)
		cout<<G.vertex[i].data<<" ";
	cout<<endl<<G.arcnum<<"����:"<<endl;
	for(i=0;i<G.vexnum;i++)
	{
		p=G.vertex[i].firstarc;
		while(p)
		{
			cout<<G.vertex[i].data<<"��"<<G.vertex[p->adjvex].data<<" ";
			p=p->nextarc;
		}
		cout<<endl;
	}
}