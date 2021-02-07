
#include<stdio.h>
typedef int DataType;
#include "SeqQueue.h"
void FerryManage()
{
	SeqQueue bus,truck; /*bus��ʾ�ͳ����У�truck��ʾ��������*/
	char ch;
	DataType n;/*nΪ����*/
	int tag; /*tag�Ǳ�־��tag=1��ʾ�ͳ���tag=2��ʾ����*/
	int count=0,countbus=0,counttruck=0;
	InitQueue(&bus);
	InitQueue(&truck);
	while(1)
	{
		fflush(stdin);
		printf("��������(e��E��ʾ��ӣ�o��O��ʾ���ӣ�q��Q��ʾ�˳�)��\n");
		scanf("%c",&ch);
		switch (ch)
		{
		case 'e':
		case 'E':
			printf("�����복��(����)��");
			scanf("%d",&n);
			printf("�ǿͳ�(1)���ǻ���(2)��");
			scanf("%d",&tag);
			if (tag==1)
				EnQueue(&bus,n);
			else
				EnQueue(&truck,n);
			break;
		case 'o':
		case 'O':
			while (count<10)
			{
				if (count<4 && !QueueEmpty(bus)) /*�ͳ�����*/
				{
					DeQueue(&bus,&n);
					printf("�ϴ��ĳ���Ϊ��%d\n",n);
					count++;
					countbus++;
				}
				else if (!QueueEmpty(truck))/*��������*/
				{
					countbus=0;
					DeQueue(&truck,&n);
					printf("�ϴ��ĳ���Ϊ��%d\n",n);
					count++;
					counttruck++;
				}
				else if (!QueueEmpty(bus))
				{
					counttruck=0;
					DeQueue(&bus,&n);
					printf("�ϴ��ĳ���Ϊ��%d\n",n);
					count++;
					countbus++;
				}
				else
				{
					printf("�Ŷ��ֶɵĳ�������10��.\n" );
					return;
				}
			}
			break;
		case 'q':
		case 'Q':
			break;
		}
		if (ch=='q' || ch=='Q')
			break;
	}
}
void main()
{
	FerryManage();
}