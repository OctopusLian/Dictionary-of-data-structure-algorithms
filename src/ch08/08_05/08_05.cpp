#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<iostream.h>
/*ͼ���ڽӱ����Ͷ���*/
typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
#define MAXSIZE 100				/*��󶥵����*/
typedef enum{DG,DN,UG,UN}GraphKind; 	/*ͼ�����ͣ�����ͼ��������������ͼ��������*/
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
int LocateVertex(AdjGraph G,VertexType v);
void CreateGraph(AdjGraph *G);
void DisplayGraph(AdjGraph G);
void DestroyGraph(AdjGraph *G);
void DFSTraverse(AdjGraph G);
int LocateVertex(AdjGraph G,VertexType v)
//����ͼ�ж����Ӧ��λ��
{ 
	int i;
	for(i=0;i<G.vexnum;i++)
		if(strcmp(G.vertex[i].data,v)==0)
			return i;
		return -1;
}
void CreateGraph(AdjGraph *G)
//�����ڽӱ�洢�ṹ��������ͼG
{ 
	int i,j,k;
	VertexType v1,v2;		//������������v1��v2
	ArcNode *p;
	cout<<"������ͼ�Ķ������ͱ���: ";
	cin>>(*G).vexnum>>(*G).arcnum;
	cout<<"������"<<G->vexnum<<"�������ֵ:"<<endl;
	for(i=0;i<G->vexnum;i++)	//������洢��ͷ�����
	{
		cin>>G->vertex[i].data;
		G->vertex[i].firstarc=NULL;	//��������Ķ�����Ϊ��
	}
	cout<<"�����뻡β ��ͷ:"<<endl;
	for(k=0;k<G->arcnum;k++)	//����������
	{
		cin>>v1>>v2;
		i=LocateVertex(*G,v1);/*ȷ��v1��Ӧ�ı��*/
		j=LocateVertex(*G,v2);/*ȷ��v2��Ӧ�ı��*/
		//jΪ��ͷiΪ��β�����ڽӱ�
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->info=NULL;
		p->nextarc=G->vertex[i].firstarc;
		G->vertex[i].firstarc=p;
		//iΪ��ͷjΪ��β�����ڽӱ�
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=i;
		p->info=NULL;
		p->nextarc=G->vertex[j].firstarc;
		G->vertex[j].firstarc=p;
	}
	(*G).kind=UG;
}

void DestroyGraph(AdjGraph *G)
//��������ͼG
{ 
	int i;
	ArcNode *p,*q;
	for(i=0;i<(*G).vexnum;i++)	//�ͷ�ͼ�еı߱���
	{
		p=G->vertex[i].firstarc;//pָ��߱�ĵ�һ�����
		if(p!=NULL)			//����߱�Ϊ�գ����ͷű߱�Ľ��
		{
			q=p->nextarc;
			free(p);
			p=q;
		}
	}
	(*G).vexnum=0;		//����������Ϊ0
	(*G).arcnum=0;		//���ߵ���Ŀ��Ϊ0
}
void DFS(AdjGraph G,int i,int visited[])
//�Ӷ���v�����ݹ����������������ͼG
{
	ArcNode *p;
	if(!visited[i])
		cout<<G.vertex[i].data<<" ";
	visited[i]=1;
	p=G.vertex[i].firstarc;//�õ�i�Ŷ���ĵ�һ���ڽӶ���
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
			DFS(G,p->adjvex,visited);
		p=p->nextarc;//�õ�i�Ŷ������һ���ڽӶ���
	}
}
void DFSTraverse(AdjGraph G)
//��v=0�����������������������ͼ
{
	int v,u,visited[MAXSIZE];
	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	for(u=0;u<G.vexnum;u++) 
		if(!visited[u])
			DFS(G,u,visited);
}
void DisplayGraph(AdjGraph G)
//���ͼ���ڽӾ���G
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
void main()
{
	AdjGraph G;
	cout<<"�����ڽӾ��󴴽�����ͼG��"<<endl;
	CreateGraph(&G);
	cout<<"�������ͼG���ڽӱ�"<<endl;
	DisplayGraph(G);
	cout<<"������ȱ�������ͼG��"<<endl;
	DFSTraverse(G);
	cout<<endl;
	DestroyGraph(&G);
}
