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
void DFS(AdjGraph *G,int v,int *vNum,int *eNum,int visited[]);
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
int IsTree(AdjGraph *G)
{
	int vNum=0,eNum=0,i,visited[MAXSIZE];
	for(i=0;i<G->vexnum;i++)
		visited[i]=0;
	DFS(G,0,&vNum,&eNum,visited);
	if(vNum==G->vexnum && eNum==2*(G->vexnum-1))
		return 1;
	else
		return 0;
}
void DFS(AdjGraph *G,int v,int *vNum,int *eNum,int visited[])
{
	ArcNode *p;
	visited[v]=1;
	(*vNum)++;
	p=G->vertex[v].firstarc;
	while(p!=NULL)
	{
		(*eNum)++;
		if(visited[p->adjvex]==0)
			DFS(G,p->adjvex,vNum,eNum,visited);
		p=p->nextarc;
	}
}
void main()
{
	AdjGraph G;
	cout<<"�����ڽӱ�������ͼG��"<<endl;
	CreateGraph(&G);
	cout<<"�������ͼG���ڽӱ�"<<endl;
	DisplayGraph(G);
	if(IsTree(&G))
		cout<<"����ͼG��һ����!"<<endl;
	else
		cout<<"����ͼG����һ����!"<<endl;
	DestroyGraph(&G);
}
