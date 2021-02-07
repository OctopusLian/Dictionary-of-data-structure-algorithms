typedef struct node
{
    DataType data;
    struct node *next;
}LStackNode,*LinkStack;
void InitStack(LinkStack *top)
/*����ջ��ʼ��Ϊ��*/
{
	if((*top=(LinkStack)malloc(sizeof(LStackNode)))==NULL)		/*Ϊͷ������һ���洢�ռ�*/
		exit(-1);
	(*top)->next=NULL;				/*����ջ��ͷ���ָ������Ϊ��*/
}
int StackEmpty(LinkStack top)   
/*�ж���ջ�Ƿ�Ϊ�գ�����ͨ���ж�ͷ����ָ�����Ƿ�Ϊ��*/
{
    if(top->next==NULL)				/*����ջΪ��ʱ*/
        return 1;					/*����1*/
    else							/*����*/
        return 0; 					/*����0*/
}
int PushStack(LinkStack top, DataType e)
/*��ջ��������Ҫ������ĵ�һ�����ǰ����һ���½�㣬��ջ�ɹ�����1*/
{
	LStackNode *p;		/*����ָ���i��Ԫ�ص�ǰ�����ָ��pre��ָ��pָ�������ɵĽ��*/
	if((p=(LStackNode*)malloc(sizeof(LStackNode)))==NULL)
	{
		printf("�ڴ����ʧ��!");
		exit(-1);
	}
	p->data=e;			/*ָ��pָ��ͷ���*/
	p->next=top->next;
	top->next=p;
	return 1;
}
int PopStack(LinkStack top,DataType *e)
/*ɾ���������еĵ�i��λ�õĽ�㡣ɾ���ɹ�����1��ʧ�ܷ���0*/
{
	LStackNode *p;
	p=top->next;
    if(!p)							/*�ж���ջ�Ƿ�Ϊ��*/
    {
        printf("ջ�ѿ�");
        return 0;
    }
    top->next=p->next;				/*��ջ�����������Ͽ�������ջ*/
	*e=p->data;					/*����ջԪ�ظ�ֵ��e*/
    free(p);						/*�ͷ�pָ��Ľ��*/
    return 1;
}
int GetTop(LinkStack top,DataType *e)
/*ȡջ��Ԫ�ء�ȡջ��Ԫ�سɹ�����1�����򷵻�0*/
{
    LStackNode *p;
    p=top->next; 					/*ָ��pָ��ջ�����*/
    if(!p)
	{
        printf("ջ�ѿ�");
        return 0;
	}
	*e=p->data; 					/*��pָ��Ľ��Ԫ�ظ�ֵ��e*/
	return 1;
}
int StackLength(LinkStack top)
/*������������δ�ջ��ָ�뿪ʼ��ͨ������ָ�������ÿһ����㣬�����������ر�ĳ���ֵ*/
{
    LStackNode *p;
    int count=0; 						/*����һ��������������ʼ��Ϊ0*/
    p=top; 							/*pָ��ջ��ָ��*/
    while(p->next!=NULL) 				/*���ջ�л��н��*/
    {
        p=p->next; 						/*���η���ջ�еĽ��*/
        count++;						/*ÿ���ҵ�һ����㣬�������ۼ�1*/
    }
    return count; 						/*����ջ�ĳ���*/
}
void DestroyStack(LinkStack top)
/*������ջ*/
{
    LStackNode *p,*q;
    p=top;
    while(!p) 							/*���ջ���н��*/
	{
		q=p; 							/*q����Ҫ�ͷŵĽ��*/
		p=p->next; 						/*pָ����һ����㣬����һ��Ҫ�ͷŵĽ��*/
		free(q); 						/*�ͷ�qָ��Ľ��ռ�*/
    }
}
void ClearStack(LinkStack top)
/*������ջ*/
{
    LStackNode *p,*q;
    p=top->next;
    while(!p) 							/*���ջ���н��*/
	{
		q=p; 							/*q����Ҫ�ͷŵĽ��*/
		p=p->next; 						/*pָ����һ����㣬����һ��Ҫ�ͷŵĽ��*/
		free(q); 						/*�ͷ�qָ��Ľ��ռ�*/
    }
}