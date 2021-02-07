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
void BFSTraverse(AdjGraph G)
//��������ȷǵݹ����ͼG
{
	int v,front,rear,visited[MAXSIZE];
	int queue[MAXSIZE];		//�������queue
	ArcNode *p;
	front=rear=-1;			//��ʼ������queue
	for(v=0;v<G.vexnum;v++)	//��ʼ����־λ
		visited[v]=0;	
	v=0;
	visited[v]=1;		//���÷��ʱ�־Ϊ1����ʾ�Ѿ������ʹ�
	cout<<G.vertex[v].data<<" ";
	rear=(rear+1)%MAXSIZE;
	queue[rear]=v;	//v�����*/
	while(front<rear)	//������в���
	{
		front=(front+1)%MAXSIZE;
		v=queue[front];		//��ͷԪ�س��Ӹ���v
		p=G.vertex[v].firstarc;
		while(p!=NULL)		//�������Ϊv�������ڽӵ�	
		{
			if(visited[p->adjvex]==0)//����ö���δ�����ʹ�	
			{
				visited[p->adjvex]=1;
				cout<<G.vertex[p->adjvex].data<<" ";
				rear=(rear+1)%MAXSIZE;
				queue[rear]=p->adjvex;
			}
			p=p->nextarc;	//ָ����һ���ڽӵ�	
		}
	}
}
void DisplayGraph(AdjGraph G)
//���ͼ���ڽӾ���G
{ 
	int i;
	ArcNode *p;
	cout<<G.vexnum<<"�����㣺"<<endl;
	for(i=0;i<G.vexnum;i++)
		cout<<G.vertex[i].data<<" ";
	cout<<endl<<2*G.arcnum<<"����:"<<endl;
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
	BFSTraverse(G);
	cout<<endl;
	DestroyGraph(&G);
}
