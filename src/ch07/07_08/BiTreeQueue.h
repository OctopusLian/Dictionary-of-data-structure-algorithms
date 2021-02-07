/*������Ͷ���*/
typedef struct QNode
{
	BitNode *data;
	struct QNode* next;
}LQNode,*QueuePtr;
/*�������Ͷ���*/
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}Queue;
void InitQueue(Queue *LQ)   
/*��ʼ����ʽ����*/
{
	LQ->front=LQ->rear=(LQNode*)malloc(sizeof(LQNode));
	if(LQ->front==NULL) exit(-1);
	LQ ->front->next=NULL;	/*��ͷ����ָ������ΪΪ0*/
}
int QueueEmpty(Queue LQ)    
/*�ж���ʽ�����Ƿ�Ϊ�գ�����Ϊ�շ���1�����򷵻�0*/
{
	if(LQ.front->next==NULL)		/*����ʽ����Ϊ��ʱ*/
        return 1; 				/*����1*/
    else						/*����*/
        return 0; 				/*����0*/
}
int EnQueue(Queue *LQ,BitNode* x)
/*��Ԫ��e���뵽��ʽ����LQ�У�����ɹ�����1*/
{
    LQNode *s;
	s=(LQNode*)malloc(sizeof(LQNode));	/*Ϊ��Ҫ��ӵ�Ԫ������һ�����Ŀռ�*/
	if(!s) exit(-1);		/*�������ռ�ʧ�ܣ����˳������ز���-1*/
	s->data=x;					/*��ָ��ֵ��������������*/
	s->next=NULL;				/*������ָ������Ϊ��*/
	LQ->rear->next=s;			/*��ԭ�����еĶ�βָ��ָ��s*/
	LQ->rear=s;				/*����βָ��ָ��s*/
    return 1;
}
int DeQueue(Queue *LQ,BitNode **e)
/*ɾ����ʽ�����еĶ�ͷԪ�أ�������ָ�븳��e��ɾ���ɹ�����1�����򷵻�0*/
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


void ClearQueue(Queue *LQ) 
/*��ն���*/
{
	while(LQ->front!=NULL)
	{
        LQ->rear=LQ->front->next;		/*��βָ��ָ���ͷָ��ָ�����һ�����*/
		free(LQ->front);				/*�ͷŶ�ͷָ��ָ��Ľ��*/
		LQ->front=LQ->rear;			/*��ͷָ��ָ���βָ��*/
	}
}






















