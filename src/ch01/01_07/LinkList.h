typedef struct Node
{
    DataType data;
    struct Node *next;
}ListNode,*LinkList;
void InitList(LinkList *head)
/*��ʼ��������*/
{
	if((*head=(LinkList)malloc(sizeof(ListNode)))==NULL)		/*Ϊͷ������һ���洢�ռ�*/
		exit(-1);
	(*head)->next=NULL;		/*���������ͷ���ָ������Ϊ��*/
}
int ListEmpty(LinkList head)   
/*�жϵ������Ƿ�Ϊ��*/
{
    if(head->next==NULL)			/*���������ͷ����ָ����Ϊ��*/
        return 1;					/*����1*/
    else							/*����*/
        return 0; 					/*����0*/
}
ListNode *Get(LinkList head,int i)   
/*����Ų��ҵ������е�i����㡣���ҳɹ����ظý���ָ���ʾ�ɹ������򷵻�NULL��ʾʧ�ܡ�*/
{
	ListNode *p;
	int j;
	if(ListEmpty(head))	/*�������Ϊ��*/
		return NULL; 	/*����NULL*/
	if(i<1)				/*�����Ų��Ϸ�*/
		return NULL; 	/*�򷵻�NULL*/
	j=0;
	p=head;
	while(p->next!=NULL&&j<i) 
	{
		p=p->next;
		j++;
	}
	if(j==i) 			/*�ҵ���i�����*/
		return p;		/*����ָ��p*/
	else				/*����*/
		return NULL;	/*����NULL*/
}
ListNode *LocateElem(LinkList head,DataType e)   
/*�����ݲ��ҵ�������Ԫ��ֵΪe��Ԫ�أ������ҳɹ��򷵻ض�ӦԪ�صĽ��ָ�룬���򷵻�NULL��ʾʧ�ܡ�*/
{
	ListNode *p;
	p=head->next;		/*ָ��pָ���һ�����*/
	while(p)
	{
		if(p->data!=e)	/*û���ҵ���e��ȵ�Ԫ��*/
			p=p->next; 	/*��������һ��Ԫ��*/
		else			/*�ҵ���e��ȵ�Ԫ��*/
			break; 		/*�˳�ѭ��*/
	}
	return p;
}
int LocatePos(LinkList head,DataType e)   
/*�������Ա���Ԫ��ֵΪe��Ԫ�أ����ҳɹ�����ӦԪ�ص���ŷ��أ����򷵻�0��ʾʧ�ܡ�*/
{
	ListNode *p;
	int i;
	if(ListEmpty(head))	/*�ڲ��ҵ�i��Ԫ��֮ǰ���ж������Ƿ�Ϊ��*/
		return 0;
	p=head->next;		/*ָ��pָ���һ�����*/
	i=1;
	while(p)
	{
		if(p->data==e)	/*�ҵ���e��ȵ�Ԫ��*/
			return i; 	/*���ظ����*/
		else
		{
			p=p->next;
			i++;
		}
	}
	if(!p)				/*���û���ҵ���e��ȵ�Ԫ��*/
		return 0; 		/*����0 */
}
int InsertList(LinkList head,int i,DataType e)
/*�ڵ������е�i��λ�ò���һ����㣬����Ԫ��ֵΪe������ɹ�����1��ʧ�ܷ���0*/
{
	ListNode *pre,*p;	/*�����i��Ԫ�ص�ǰ�����ָ��pre��ָ��pָ�������ɵĽ��*/
	int j;
	pre=head;			/*ָ��pָ��ͷ���*/
	j=0;
	while(pre->next!=NULL&&j<i-1)/*�ҵ���i��1����㣬����i������ǰ�����*/
	{
		pre=pre->next;
		j++;
	}
	if(j!=i-1)					/*���û�ҵ���˵������λ�ô���*/
	{
		printf("����λ�ô���");
		return 0;
	}
	/*������һ����㣬����e��ֵ���ý���������*/
	if((p=(ListNode*)malloc(sizeof(ListNode)))==NULL)
		exit(-1);
	p->data=e;
	/*���������*/
	p->next=pre->next;
	pre->next=p;
	return 1;
}
int DeleteList(LinkList head,int i,DataType *e)
/*ɾ���������еĵ�i��λ�õĽ�㡣ɾ���ɹ�����1��ʧ�ܷ���0*/
{
	ListNode *pre,*p;
	int j;
	pre=head;
	j=0;
    while(pre->next!=NULL&&pre->next->next!=NULL&&j<i-1)/*�ж��Ƿ��ҵ�ǰ�����*/
    {
        pre=pre->next;
        j++;
    }
    if(j!=i-1)				/*���û�ҵ�Ҫɾ���Ľ��λ�ã�˵��ɾ��λ������*/
    {
        printf("ɾ��λ������");
        return 0;
	}
	/*ָ��pָ�������еĵ�i����㣬�����ý���������ֵ��ֵ��e*/
	p=pre->next;
	*e=p->data;
	/*��ǰ������ָ����ָ��Ҫɾ��������һ����㣬Ҳ���ǽ�pָ��Ľ���뵥����Ͽ�*/
	pre->next=p->next;
	free(p);				/*�ͷ�pָ��Ľ��*/
    return 1;
}
int ListLength(LinkList head)
/*�������*/
{
    ListNode *p;
    int count=0;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;
}
void DestroyList(LinkList head)
/*��������*/
{
    ListNode *p,*q;
    p=head;
    while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}
