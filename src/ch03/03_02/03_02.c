#include<stdio.h>
typedef struct{
	char name[20];
	char sex;  /*�Ա�'F'��'f'��ʾŮ�ԣ�'M'��'m'��ʾ����*/
}Person;
typedef Person DataType;  /* ��������Ԫ�ص��������͸�ΪPerson */
#include"SeqQueue.h"
void DancePartner(DataType dancer[],int num)
/*�ṹ����dancer�д���������Ů��num�����������*/
{
	int i;
	DataType p;
	SeqQueue Mdancers,Fdancers;
	InitQueue(&Mdancers);/*��ʿ���г�ʼ��*/
	InitQueue(&Fdancers);/*Ůʿ���г�ʼ��*/
	for(i=0;i<num;i++){/*���ν������������Ա����*/
		p=dancer[i];       
		if(p.sex=='F'||p.sex=='f')
			EnQueue(&Fdancers,p);   /*����Ů��*/
		else
			EnQueue(&Mdancers,p);   /*�����ж�*/
	}
	printf("��Գɹ������ֱ���: \n");
	while(!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers)){
		/*����������Ů�����*/
		DeQueue(&Fdancers,&p);     /*Ůʿ����*/
		printf("%s   ",p.name);/*��ӡ����Ůʿ��*/
		DeQueue(&Mdancers,&p);     /*��ʿ����*/
		printf("%s\n",p.name);    /*��ӡ������ʿ��*/
	}
	if(!QueueEmpty(Fdancers)){ /*���Ůʿʣ����������ͷŮʿ������*/
		printf("����%d��Ůʿ�ȴ���һ������.\n",DancerCount(Fdancers));
		GetHead(Fdancers,&p);  /*ȡ��ͷ*/
		printf("%s ������һ�������ȵõ����. \n",p.name);
	}
	else if(!QueueEmpty(Mdancers)){/*����ж�ʣ����������ͷ������*/
		printf("����%d����ʿ�ȴ���һ������.\n",DancerCount(Mdancers));
		GetHead(Mdancers,&p);
		printf("%s ������һ�������ȵõ����.\n",p.name);
	}
}  
int DancerCount(SeqQueue Q)
/*�����еȴ���Ե�����*/
{
	return (Q.rear-Q.front+QueueSize)%QueueSize;
}
void main()
{
	int i,n;
	DataType dancer[30];
	printf("������������Ŷӵ�����:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("����:");
		scanf("%s",dancer[i].name);
		getchar();
		printf("�Ա�:");
		scanf("%c",&dancer[i].sex);
	}
	DancePartner(dancer,n);
}