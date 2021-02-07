#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*���Ͷ���*/
typedef char DataType;
typedef struct Node
{
	DataType data;
	struct Node *prior;
    struct Node *next;
}DListNode,*DLinkList;
/*��������*/
DListNode *GetElem(DLinkList head,int i);
void PrintDList(DLinkList head);
int CreateDList(DLinkList head,int n);
int InsertDList(DLinkList head,int i,char e);
/*����ʵ��*/
int InitDList(DLinkList *head)
/*��ʼ��˫��ѭ������*/
{
    *head=(DLinkList)malloc(sizeof(DListNode));
    if(!head)
        return -1;
    (*head)->next=*head;			/*ʹͷ����priorָ���nextָ��ָ���Լ�*/
    (*head)->prior=*head;
    return 1;
}
int CreateDList(DLinkList head,int n)
/*����˫��ѭ������*/
{
    DListNode *s,*q;
    int i;
DataType e;
    q=head;
    for(i=1;i<=n;i++)
    {
printf("�����%d��Ԫ��",i);
        e=getchar();
        s=(DListNode*)malloc(sizeof(DListNode));
s->data=e;
/*�������ɵĽ����뵽˫��ѭ������*/
        s->next=q->next;
        q->next=s;
        s->prior=q;
        head->prior=s;				/*����Ҫע��ͷ����priorָ���²���Ľ��*/
        q=s;						/*qʼ��ָ�����һ�����*/
getchar();
}
return 1;
}
int InsertDList(DLinkList head,int i,DataType e)
/*��˫��ѭ������ĵ�i��λ�ò���Ԫ��e������ɹ�����1�����򷵻�0*/
{
    DListNode *p,*s;
    p=GetElem(head,i);				/*���������е�i�����*/
    if(!p)
        return 0;
    s=(DListNode*)malloc(sizeof(DListNode));
    if(!s)
        return -1;
    s->data=e;
	/*��s�����뵽˫��ѭ������*/
    s->prior=p->prior;
    p->prior->next=s;
    s->next=p;
    p->prior=s;
    return 1;
}
DListNode *GetElem(DLinkList head,int i)
/*���Ҳ����λ�ã��ҵ����ظý���ָ�룬���򷵻�NULL*/
{
    DListNode *p;
    int j;
    p=head->next;
    j=1;
    while(p!=head&&j<i)
    {
        p=p->next;
        j++;
    }
	if(p==head||j>i)				/*���Ҫλ�ò���ȷ������NULL*/
        return NULL;
    return p;
}
void main()
{
    DLinkList h;
    int n;
	int pos;
	char e;
    InitDList(&h);
    printf("����Ԫ�ظ�����");
    scanf("%d",&n);
 	getchar();
    CreateDList(h,n);
    printf("�����е�Ԫ�أ�");
    PrintDList(h);
    printf("����������Ԫ�ؼ�λ�ã�");
    scanf("%c",&e);
	getchar();
    scanf("%d",&pos);
	InsertDList(h,pos,e);
	printf("����Ԫ�غ������е�Ԫ�أ�");
	PrintDList(h);
}
void PrintDList(DLinkList head)
/*���˫��ѭ�������е�ÿһ��Ԫ��*/
{
    DListNode *p;
    p=head->next;
    while(p!=head)
    {
        printf("%c",p->data);
        p=p->next;
    }
	printf("\n");
}