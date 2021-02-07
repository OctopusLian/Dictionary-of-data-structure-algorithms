#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<iostream.h>
#include"SeqStack.h"
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
void BriefPath(AdjGraph G,int u,int v)
/*��ͼG�дӶ���u������v��һ����·��*/
{
	int k,i;
	SeqStack S,T;
	ArcNode *p;
	int visited[MAXSIZE];
	int parent[MAXSIZE];		/*�洢�Ѿ����ʶ����ǰ������*/
	InitStack(&S);
	InitStack(&T);
	for(k=0;k<G.vexnum;k++)		/*���ʱ�־��ʼ��*/
		visited[k]=0;
	PushStack(&S,u);			/*��ʼ������ջ*/
	visited[u]=1;				/*���ʱ�־��Ϊ1*/
	while(!StackEmpty(S))		/*�����������ͼ������·����parent�洢*/
	{
		PopStack(&S,&k);
		p=G.vertex[k].firstarc;
		while(p!=NULL)
		{
			if(p->adjvex==v)	/*����ҵ�����v*/
			{
				parent[p->adjvex]=k;	/*����v��ǰ�����������k*/
				printf("����%s������%s��·���ǣ�",G.vertex[u].data,G.vertex[v].data);
				i=v;
				do						/*�Ӷ���v��ʼ��·���еĶ���������ջ*/
				{
					PushStack(&T,i);
					i=parent[i];
				}while(i!=u);
				PushStack(&T,u);
				while(!StackEmpty(T))	/*�Ӷ���u��ʼ���u��v��·���Ķ���*/
				{
					PopStack(&T,&i);
					printf("%s ",G.vertex[i].data);
					
				}
				printf("\n");
			}
			else if(visited[p->adjvex]==0)/*��δ�ҵ�����v���ڽӵ�δ���ʹ������������*/
			{
				visited[p->adjvex]=1;
				parent[p->adjvex]=k;
				PushStack(&S,p->adjvex);
			}
			p=p->nextarc;
		}	
	}	
}
void main()
{
	AdjGraph G;
	VertexType u,v;
	int i,j;
	cout<<"�����ڽӱ�������ͼG��"<<endl;
	CreateGraph(&G);
	cout<<"�������ͼG���ڽӱ�"<<endl;
	DisplayGraph(G);
	cout<<"������Ҫ��������������֮��ļ�·����"<<endl;
	cin>>u>>v;
	i=LocateVertex(G,u);
	j=LocateVertex(G,v);
	BriefPath(G,i,j);
	cout<<endl;
	DestroyGraph(&G);
}
