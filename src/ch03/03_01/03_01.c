#define QUEUESIZE 20		/*����˳��ѭ�����е��������*/
#include<math.h>
typedef int DataType;		/*����˳��ѭ������Ԫ�ص�����Ϊ��������*/
#define MAXSIZE 100
#include<stdio.h>			/*����ͷ�ļ�����Ҫ���������������*/
typedef struct Squeue{		/*˳��ѭ�����е����Ͷ���*/      
	DataType queue[QUEUESIZE];
	int front,rear;		/*��ͷָ��Ͷ�βָ��*/
	int tag;			/*���пա����ı�־*/
}SCQueue;                       
void PrintData(DataType e);
int CheckType(DataType e);
void InitQueue(SCQueue *SCQ)  
/*��˳��ѭ�����г�ʼ��Ϊ�ն��У���Ҫ�Ѷ�ͷָ��Ͷ�βָ��ͬʱ��Ϊ0���ұ�־λ��Ϊ0*/  
{
    SCQ->front=SCQ->rear=0;		/*��ͷָ��Ͷ�βָ�붼��Ϊ0*/
	SCQ->tag=0;					/*��־λ��Ϊ0*/
}
int QueueEmpty(SCQueue SCQ)   
/*�ж�˳��ѭ�������Ƿ�Ϊ�գ�����Ϊ�շ���1�����򷵻�0*/
{
	if(SCQ.front==SCQ.rear&&SCQ.tag==0)	/*��ͷָ��Ͷ�βָ�붼Ϊ0�ұ�־λΪ0��ʾ�����ѿ�*/
		return 1;
	else
		return 0;
}
int EnQueue(SCQueue *SCQ,DataType e)
/*��Ԫ��e���뵽˳��ѭ������SQ�У�����ɹ�����1�����򷵻�0*/
{
	if(SCQ->front==SCQ->rear&&SCQ->tag==1)  
		/*�ڲ����µ�Ԫ��֮ǰ���ж��Ƿ��βָ�뵽����������ֵ�����Ƿ�����*/
	{
		printf("˳��ѭ������������������ӣ�");
		return 1;
	}
	else
	{
		SCQ->queue[SCQ->rear]=e;		/*�ڶ�β����Ԫ��e */
		SCQ->rear=SCQ->rear+1;			/*��βָ������ƶ�һ��λ�ã�ָ���µĶ�β*/
		SCQ->tag=1;					/*����ɹ�����־λ��Ϊ1 */
		return 1;
	}
}
int DeQueue(SCQueue *SCQ,DataType *e)
/*ɾ��˳��ѭ�������еĶ�ͷԪ�أ�������Ԫ�ظ�ֵ��e��ɾ���ɹ�����1�����򷵻�0*/
{
	if(QueueEmpty(*SCQ))				/*��ɾ��Ԫ��֮ǰ���ж϶����Ƿ�Ϊ��*/
	{
        printf("˳��ѭ�������Ѿ��ǿն��У������ٽ��г����в�����");
		return 0;
	}
	else
	{
		*e=SCQ->queue[SCQ->front];		/*Ҫ�����е�Ԫ��ֵ��ֵ��e */
		SCQ->front=SCQ->front+1;			/*��ͷָ������ƶ�һ��λ�ã�ָ���µĶ�ͷԪ��*/
		SCQ->tag=0;					/*ɾ���ɹ�����־λ��Ϊ0 */
		return 1;
	}
}
void DisplayQueue(SCQueue SCQ)
/*˳��ѭ�����е���ʾ��������������ж϶����Ƿ�Ϊ�գ����ʱ��Ӧ���Ƕ�ͷָ��Ͷ�βָ��ֵ�Ĵ�С����*/
{
	int i;
	if(QueueEmpty(SCQ))				/*�ж�˳��ѭ�������Ƿ�Ϊ��*/
		return;
	if(SCQ.front<SCQ.rear)    
		/*�����ͷָ��ֵС�ڶ�βָ���ֵ����Ѷ�ͷָ�뵽��βָ��ָ���Ԫ���������*/
		for(i=SCQ.front;i<SCQ.rear;i++)
			printf("%4d",SCQ.queue[i]);
		else
			/*�����ͷָ��ֵ���ڶ�βָ���ֵ����Ѷ�βָ�뵽��ͷָ��ָ���Ԫ���������*/
			for(i=SCQ.front;i<SCQ.rear+ QUEUESIZE;i++)
				printf("%4d",SCQ.queue[i% QUEUESIZE]);
			printf("\n");	
}
void main()
{
	SCQueue Q;						/*����һ��˳��ѭ������*/
	int e;							/*����һ���ַ����ͱ��������ڴ�ų����е�Ԫ��*/
	int a[]={1,2,3,4},i;
	InitQueue(&Q);					/*��ʼ��˳��ѭ������*/
	/*�������е�4��Ԫ����������*/
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
		EnQueue(&Q,a[i]);
	/*��˳��ѭ�������е�Ԫ����ʾ���*/
	printf("������Ԫ�أ�");
	DisplayQueue(Q);
	/*��˳��ѭ�������еĶ�ͷԪ�س�����*/
	i=0;
	while(!QueueEmpty(Q))
	{
		printf("��ͷԪ�ص�%d�γ���\n",++i);
		DeQueue(&Q,&e);
		printf("���ӵ�Ԫ�أ�");
		//printf("%d\n",e);
		PrintData(e);
	}
}
void PrintData(DataType e)
/*���ݵ������Ϊ��ʹ���ú�������Ҫ��ʽ���Ʒ���*/
{
	int n;
	n=CheckType(e);
	switch(n)
	{
	case 1://�ַ���
		printf("%4c\n",e);
		break;
	case 2://����
		printf("%4d\n",e);
		break;
	case 3://������
		printf("%8.2f\n",e);
		break;
	}
}
int CheckType(DataType e)
/*�ж�e�Ǹ�����������������ĸ�ַ�*/
{
	char str[MAXSIZE];
	int a;
	float b;
	if(fabs(e-(int)e)>1e-6)//�Ǹ�����
		return 3;
	if(e>='A'&&e<='Z'||e>='a'&&e<='z')//����ĸ�ַ�
		return 1;
	else //������
		return 2;
}


