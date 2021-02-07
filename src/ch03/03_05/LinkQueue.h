/*������Ͷ���*/
typedef struct QNode
{
	DataType data;
	struct QNode* next;
}LQNode,*QueuePtr;
/*�������Ͷ���*/
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
void InitQueue(LinkQueue *LQ)   
/*��ʼ����ʽ����*/
{
	LQ->front=LQ->rear=(LQNode*)malloc(sizeof(LQNode));
	if(LQ->front==NULL) exit(-1);
	LQ ->front->next=NULL;	/*��ͷ����ָ������ΪΪ0*/
}
int QueueEmpty(LinkQueue LQ)    
/*�ж���ʽ�����Ƿ�Ϊ�գ�����Ϊ�շ���1�����򷵻�0*/
{
	if(LQ.rear->next==NULL)		/*����ʽ����Ϊ��ʱ*/
        return 1; 				/*����1*/
    else						/*����*/
        return 0; 				/*����0*/
}
int EnQueue(LinkQueue *LQ,DataType e)
/*��Ԫ��e���뵽��ʽ����LQ�У�����ɹ�����1*/
{
    LQNode *s;
	s=(LQNode*)malloc(sizeof(LQNode));	/*Ϊ��Ҫ��ӵ�Ԫ������һ�����Ŀռ�*/
	if(!s) exit(-1);		/*�������ռ�ʧ�ܣ����˳������ز���-1*/
	s->data=e;					/*��Ԫ��ֵ��ֵ������������*/
	s->next=NULL;				/*������ָ������Ϊ��*/
	LQ->rear->next=s;			/*��ԭ�����еĶ�βָ��ָ��s*/
	LQ->rear=s;				/*����βָ��ָ��s*/
    return 1;
}
int DeQueue(LinkQueue *LQ,DataType *e)
/*ɾ����ʽ�����еĶ�ͷԪ�أ�������Ԫ�ظ���e��ɾ���ɹ�����1�����򷵻�0*/
{
    LQNode *s;
	if(LQ->front==LQ->rear)		/*��ɾ��Ԫ��֮ǰ���ж���ʽ�����Ƿ�Ϊ��*/
        return 0;
    else
	{
		s=LQ->front->next;	/*ʹָ��sָ���ͷԪ�ص�ָ��*/
		*e=s->data;		/*��Ҫɾ���Ķ�ͷԪ�ظ���e*/
		LQ->front->next=s->next;			/*ʹͷ����ָ��ָ��ָ��s����һ�����*/
		if(LQ->rear==s) LQ->rear=LQ->front;	/*���Ҫɾ���Ľ���Ƕ�β����ʹ��βָ��ָ���ͷָ��*/
		free(s);				/*�ͷ�ָ��sָ��Ľ��ռ�*/
        return 1;
	}
}

int GetHead (LinkQueue LQ,DataType *e)
/*ȡ��ʽ�����еĶ�ͷԪ�أ�������Ԫ�ظ���e��ȡԪ�سɹ�����1�����򷵻�0*/
{
    LQNode *s;
	if(LQ.front==LQ.rear)		/*��ȡ��ͷԪ��֮ǰ���ж���ʽ�����Ƿ�Ϊ��*/
		return 0;
	else
	{
		s=LQ.front->next;	/*��ָ��pָ����еĵ�һ��Ԫ�ؼ���ͷԪ��*/
		*e=s->data;			/*����ͷԪ�ظ���e��ȡ����ͷԪ��*/
		return 1;
	}
}
void ClearQueue(LinkQueue *LQ) 
/*��ն���*/
{
	while(LQ->front!=NULL)
	{
        LQ->rear=LQ->front->next;		/*��βָ��ָ���ͷָ��ָ�����һ�����*/
		free(LQ->front);				/*�ͷŶ�ͷָ��ָ��Ľ��*/
		LQ->front=LQ->rear;			/*��ͷָ��ָ���βָ��*/
	}
}






















