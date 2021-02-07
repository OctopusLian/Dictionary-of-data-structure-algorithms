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
void BsfLevel(AdjGraph G,int v0,int k)
/*��ͼG�У�����붥��v0���·��Ϊk�����ж���*/
{
	int visited[MAXSIZE];		/*һ��������ʱ�־���飬0��ʾδ���ʣ�1��ʾ�Ѿ�����*/
	int queue[MAXSIZE][2];	/*����queue[][0]�洢�������ţ�queue[][1]�洢��ǰ�������v0��·������*/
	int front=0,rear=-1,v,i,level,yes=0;
	ArcNode *p;
	for(i=0;i<G.vexnum;i++)		/*��ʼ����־����*/
		visited[i]=0;
	rear=(rear+1)% MAXSIZE;		/*����v0�����*/
	queue[rear][0]=v0;
	queue[rear][1]=1;
	visited[v0]=1;				/*���������־��Ϊ1*/
	level=1;					/*���õ�ǰ���*/
	do{
		v=queue[front][0];		/*ȡ�������ж���*/
		level=queue[front][1];
		front=(front+1)% MAXSIZE;
		p=G.vertex[v].firstarc;	/*pָ��v�ĵ�һ���ڽӵ�*/
		while(p!=NULL)
		{
			if(visited[p->adjvex]==0)		/*������ڽӵ�δ������*/
			{
				if(level==k)			/*������ڽӵ����v0�����·��Ϊk���������*/
				{
					if(yes==0)
						cout<<"����"<<G.vertex[v0].data<<"�����·��Ϊ"<<k<<"�Ķ����У�"<<G.vertex[p->adjvex].data;
					else
						cout<<","<<G.vertex[p->adjvex].data;
					yes=1;
				}
				visited[p->adjvex]=1;	/*���ʱ�־��Ϊ1*/
				rear=(rear+1)% MAXSIZE;	/*�����ö������*/
				queue[rear][0]=p->adjvex;
				queue[rear][1]=level+1;	
			}
			p=p->nextarc;				/*�����ǰ�����Ѿ������ʣ���p������һ���ڽӵ�*/
		}
	}while(front!=rear&&level<k+1);
	cout<<endl;
}
void DisplayGraph(AdjGraph G)
/*ͼG���ڽӱ�����*/
{ 
	int i;
	ArcNode *p;
	cout<<"��ͼ����"<<G.vexnum<<"�����㣺";
	for(i=0;i<G.vexnum;i++)
		cout<<G.vertex[i].data<<" ";
	cout<<endl<<"ͼ�й���"<<2*G.arcnum<<"����:"<<endl;
	for(i=0;i<G.vexnum;i++)
	{
		p=G.vertex[i].firstarc;
		while(p)
		{
			cout<<"("<<G.vertex[i].data<<","<<G.vertex[p->adjvex].data<<")";
			p=p->nextarc;
		}
		cout<<endl;
	}
}
int LocateVertex(AdjGraph G,VertexType v)
/*����ͼ�ж����Ӧ��λ��*/
{ 
	int i;
	for(i=0;i<G.vexnum;i++)
		if(strcmp(G.vertex[i].data,v)==0)
			return i;
		return -1;
}
void CreateGraph(AdjGraph *G)
/*�����ڽӱ�洢�ṹ����������ͼG*/
{ 
	int i,j,k;
	VertexType v1,v2;				/*������������v1��v2*/
	ArcNode *p;
	cout<<"������ͼ�Ķ������ͱ���: ";
	cin>>(*G).vexnum>>(*G).arcnum;
	cout<<"������"<<G->vexnum<<"�������ֵ:"<<endl;
	for(i=0;i<G->vexnum;i++)			/*������洢��ͷ�����*/
	{
		cin>>G->vertex[i].data;
		G->vertex[i].firstarc=NULL;	/*��������Ķ�����Ϊ��*/
	}
	cout<<"�����뻡β�ͻ�ͷ(�ÿո�ָ�):"<<endl;
	for(k=0;k<G->arcnum;k++)			/*����������*/
	{
		cin>>v1>>v2;
		i=LocateVertex(*G,v1);
		j=LocateVertex(*G,v2);
		/*jΪ��ͷiΪ��β�����ڽӱ�*/
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->info=NULL;
		p->nextarc=G->vertex[i].firstarc;
		G->vertex[i].firstarc=p;
		/*iΪ��ͷjΪ��β�����ڽӱ�*/
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=i;
		p->info=NULL;
		p->nextarc=G->vertex[j].firstarc;
		G->vertex[j].firstarc=p;
	}
	(*G).kind=UG;
}
void DestroyGraph(AdjGraph *G)
/*��������ͼG*/
{ 
	int i;
	ArcNode *p,*q;
	for(i=0;i<(*G).vexnum;++i)		/*�ͷ�ͼ�еı߱���*/
	{
		p=G->vertex[i].firstarc;		/*pָ��߱�ĵ�һ�����*/
		if(p!=NULL)					/*����߱�Ϊ�գ����ͷű߱�Ľ��*/
		{
			q=p->nextarc;
			free(p);
			p=q;
		}
	}
	(*G).vexnum=0;					/*����������Ϊ0*/
	(*G).arcnum=0;					/*���ߵ���Ŀ��Ϊ0*/
}
void main()
{
	int k;
	AdjGraph G;
	CreateGraph(&G);		/*�����ڽӱ�洢�ṹ����ͼG*/
	DisplayGraph(G);		/*�������ͼG*/
	cout<<"��������Ҫ���Ҿ��붥��v0·��Ϊ�೤�Ķ���:"<<endl;
	cin>>k;
	BsfLevel(G,0,k);		/*����ͼG�о��붥��v0���·��Ϊk�Ķ���*/
	DestroyGraph(&G);		/*����ͼG*/
}