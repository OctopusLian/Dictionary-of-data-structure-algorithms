#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<iostream.h>
//ͼ���ڽӱ����Ͷ���
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
//��������
int LocateVertex(AdjGraph G,VertexType v);
void CreateGraph(AdjGraph *G);
void DisplayGraph(AdjGraph G);
void DestroyGraph(AdjGraph *G);
void DFSTraverse(AdjGraph G);
ArcNode *nextnode=NULL;       //ȫ�ֱ���
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
//�����ڽӱ�洢�ṹ����������ͼG
{ 
	int i,j,k;
	VertexType v1,v2;//������������v1��v2
	ArcNode *p;
	printf("������ͼ�Ķ�����,����(���ŷָ�): ");
	scanf("%d,%d",&(*G).vexnum,&(*G).arcnum);
	printf("������%d�������ֵ:\n",G->vexnum);
	for(i=0;i<G->vexnum;i++)//������洢��ͷ�����
	{
		scanf("%s",G->vertex[i].data);
		G->vertex[i].firstarc=NULL;	//��������Ķ�����Ϊ��
	}
	printf("�����뻡β�ͻ�ͷ(�Կո���Ϊ���):\n");
	for(k=0;k<G->arcnum;k++)		//����������
	{
		scanf("%s%s",v1,v2);
		i=LocateVertex(*G,v1);
		j=LocateVertex(*G,v2);
		//jΪ��ͷiΪ��β�����ڽӱ�
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->info=NULL;
		p->nextarc=G->vertex[i].firstarc;
		G->vertex[i].firstarc=p;
	}
	(*G).kind=DG;
}

void DestroyGraph(AdjGraph *G)
//��������ͼG
{ 
	int i;
	ArcNode *p,*q;
	for(i=0;i<(*G).vexnum;++i)	//�ͷ�ͼ�еı߱���
	{
		p=G->vertex[i].firstarc;	//pָ��߱�ĵ�һ�����
		if(p!=NULL)					//����߱�Ϊ�գ����ͷű߱�Ľ��
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
	printf("%d�����㣺\n",G.vexnum);
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
void visitvex(AdjGraph G,int i)
//���ͼ�е�i������
{
	cout<<G.vertex[i].data<<"  ";
}
void DFS(AdjGraph G,int i,int visited[],int *n)
//�Ӷ���v�����ݹ����������������ͼG
{
	ArcNode *p;
	visited[i]=1;
	(*n)++;
	visitvex(G,i);
	p=G.vertex[i].firstarc;//�õ�i�Ŷ���ĵ�һ���ڽӶ���
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
			DFS(G,p->adjvex,visited,n);
		p=p->nextarc;//�õ�i�Ŷ������һ���ڽӶ���
	}
}
void DFSTraverse(AdjGraph G)
//��v=0�����������������������ͼ
{
	int v,u,n,visited[MAXSIZE];
	for(v=0;v<G.vexnum;v++)
	{
		cout<<"��"<<G.vertex[v].data<<"��ʼ������";
		for(u=0;u<G.vexnum;u++)  
			visited[u]=0;
		n=0;
		DFS(G,v,visited,&n);
		if(n==G.vexnum)
			cout<<". "<<G.vertex[v].data<<"�Ǹ�����"<<endl;
		else
			cout<<". "<<G.vertex[v].data<<"���Ǹ�����"<<endl;
	}
}
void main()
{
	AdjGraph G;
	cout<<"�����ڽӱ�������ͼG��"<<endl;
	CreateGraph(&G);
	cout<<"�������ͼG��";
	DisplayGraph(G);
	DFSTraverse(G);
	DestroyGraph(&G);
}
