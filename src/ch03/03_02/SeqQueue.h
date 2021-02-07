#define  QueueSize  60		/*���е�����*/
typedef struct Squeue{
	DataType queue[QueueSize];
	int front,rear; 		/*��ͷָ��Ͷ�βָ��*/
}SeqQueue;
void InitQueue(SeqQueue *SCQ)   
/*˳��ѭ�����еĳ�ʼ��*/
{
    SCQ ->front=SCQ ->rear=0;	/*�Ѷ�ͷָ��Ͷ�βָ��ͬʱ��Ϊ0*/
}
int QueueEmpty(SeqQueue SCQ)    
/*�ж�˳��ѭ�������Ƿ�Ϊ�գ�����Ϊ�շ���1�����򷵻�0*/
{
	if(SCQ.front== SCQ.rear)		/*��˳��ѭ������Ϊ��ʱ*/
		return 1; 				/*����1*/
	else						/*����*/
		return 0; 				/*����0*/
}
int EnQueue(SeqQueue *SCQ,DataType e)
/*��Ԫ��e���뵽˳��ѭ������SQ�У�����ɹ�����1�����򷵻�0*/
{
	if(SCQ->front== (SCQ->rear+1)%QueueSize)
	/*�ڲ����µ�Ԫ��֮ǰ���ж϶�βָ���Ƿ񵽴���������ֵ�����Ƿ�����*/
		return 0;
	SCQ->queue[SCQ->rear]=e;		/*�ڶ�β����Ԫ��e */
	SCQ->rear=(SCQ->rear+1)%QueueSize;		/*��βָ������ƶ�һ��λ��*/
	return 1;
}
int DeQueue(SeqQueue *SCQ,DataType *e)
/*����ͷԪ�س��ӣ�������Ԫ�ظ�ֵ��e��ɾ���ɹ�����1�����򷵻�0*/
{
	if(SCQ->front==SCQ->rear)		/*��ɾ��Ԫ��֮ǰ���ж�˳��ѭ�������Ƿ�Ϊ��*/
		return 0;
	else
	{
		*e=SCQ->queue[SCQ->front];		/*��Ҫɾ����Ԫ�ظ�ֵ��e*/
		SCQ->front=(SCQ->front+1)%QueueSize;		/*����ͷָ������ƶ�һ��λ�ã�ָ���µĶ�ͷ*/
		return 1;
	}
}
int GetHead (SeqQueue SCQ,DataType *e)
/*ȡ��ͷԪ�أ�������Ԫ�ظ�ֵ��e��ȡԪ�سɹ�����1�����򷵻�0*/
{
	if(SCQ.front==SCQ.rear)		/*��ȡ��ͷԪ��֮ǰ���ж�˳��ѭ�������Ƿ�Ϊ��*/
		return 0;
	else
	{
		*e=SCQ.queue[SCQ.front];	/*����ͷԪ�ظ�ֵ��e��ȡ����ͷԪ��*/
		return 1;
	}
}
void ClearQueue(SeqQueue *SCQ) 
/*��ն���*/
{
	SCQ->front=SCQ->rear=0;		/*����ͷָ��Ͷ�βָ�붼��Ϊ0*/
}