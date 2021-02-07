#define MaxSize 200
typedef struct			/*��Ԫ�����Ͷ���*/
{
	int i; 				/*����Ԫ�ص��к�*/
	int j; 				/*����Ԫ�ص��к�*/
    DataType e;
}Triple;
typedef struct				/*�������Ͷ���*/
{
    Triple data[MaxSize];
	int m; 			/*���������*/
	int n; 			/*���������*/
	int len; 			/*�����з���Ԫ�صĸ���*/
}TriSeqMatrix;
int CreateMatrix(TriSeqMatrix *M)
/*����ϡ����󣨰���������˳���������Ԫ��ֵ��*/
{ 
	int i,m,n;
	DataType e;
	int flag;
	printf("������ϡ����������������������Ԫ�ظ�����");
	scanf("%d,%d,%d",&M->m,&M->n,&M->len);
	if(M->len>MaxSize)
		return 0;
	for(i=0;i<M->len;i++)
	{
		do
		{
			printf("�밴����˳�������%d������Ԫ�����ڵ���(0��%d),��(0��%d),Ԫ��ֵ:",i+1,M->m-1,M->n-1);
			scanf("%d,%d,%d",&m,&n,&e);
			flag=0;							/*��ʼ����־λ*/
			if(m<0||m>M->m||n<0||n>M->n)			/*����кŻ��к���ȷ����־λΪ1*/
				flag=1;                        
			/*�������˳����ȷ�����־λΪ1*/
			if(i>0&&m<M->data[i-1].i||m==M->data[i-1].i&&n<=M->data[i-1].j)	
				flag=1;
		}while(flag);
		M->data[i].i=m;
		M->data[i].j=n;
		M->data[i].e=e;
	}
	return 1;
}
void CopyMatrix(TriSeqMatrix M,TriSeqMatrix *N)
/*��ϡ�����M���Ƶõ���һ������N*/
{ 
	
	int i;
	N->len=M.len;				/*�޸�ϡ�����N�ķ���Ԫ�صĸ���*/
	N->m=M.m;				/*�޸�ϡ�����N������*/
	N->n=M.n;				/*�޸�ϡ�����N������*/
	for(i=0;i<M.len;i++)	/*��M�з���Ԫ�ص��кš��кż�Ԫ��ֵ���θ�ֵ��N���кš��кż�Ԫ��ֵ*/
	{
		N->data[i].i=M.data[i].i;
		N->data[i].j=M.data[i].j;
		N->data[i].e=M.data[i].e;
	}
}
void TransposeMatrix(TriSeqMatrix M,TriSeqMatrix *N)
/*ϡ������ת��*/
{ 
	int i,k,col;
	N->m=M.n;
	N->n=M.m;
	N->len=M.len;
	if(N->len)
	{
		k=0;
		for(col=0;col<M.n;col++)			/*�����к�ɨ����Ԫ��˳���*/
			for(i=0;i<M.len;i++)
				if(M.data[i].j==col)		/*���Ԫ�ص��к��ǵ�ǰ�У������ת��*/
				{
					N->data[k].i=M.data[i].j;
					N->data[k].j=M.data[i].i;
					N->data[k].e=M.data[i].e;
					k++;
				}
	}
}

void DestroyMatrix(TriSeqMatrix *M)
/*����ϡ�����*/
{ 
	M->m=M->n=M->len=0;
}