
typedef struct
{
DataType list[ListSize];
int length;
}SeqList;
void InitList(SeqList *L)    
/*��ʼ�����Ա�*/
{
	L->length=0;	/*�����Ա�ĳ�����Ϊ0*/
}
int ListEmpty(SeqList L)   
/*�ж����Ա��Ƿ�Ϊ�գ����Ա�Ϊ�շ���1�����򷵻�0*/
{
	if(L.length==0)		/*���Ա�ĳ�����Ϊ0*/
		return 1;			/*����1*/
	else				/*����*/
		return 0; 		/*����0*/
}
int GetElem(SeqList L,int i,DataType *e)   
/*�������Ա��е�i��Ԫ�ء����ҳɹ�����ֵ���ظ�e��������1��ʾ�ɹ������򷵻�-1��ʾʧ�ܡ�*/
{
	if(i<1||i>L.length)  /*�ڲ��ҵ�i��Ԫ��֮ǰ���жϸ�����Ƿ�Ϸ�*/
		return -1;
	*e=L.list[i-1];		/*����i��Ԫ�ص�ֵ��ֵ��e*/
	return 1;
}
int LocateElem(SeqList L,DataType e)   
/*�������Ա���Ԫ��ֵΪe��Ԫ��*/
{
	int i;
	for(i=0;i<L.length;i++)	 	/*�ӵ�һ��Ԫ�ؿ�ʼ��e���бȽ�*/
		if(L.list[i]==e) 		/*��������eֵ��ȵ�Ԫ��*/
			return i+1;		     /*���ظ�Ԫ�������Ա��е����*/
		return 0;				/*���򣬷���0*/
}
int InsertList(SeqList *L,int i,DataType e)   
/*��˳���ĵ�i��λ�ò���Ԫ��e������ɹ�����1���������λ�ò��Ϸ�����-1��˳���������0*/
{
	int j;
if(i<1||i>L->length+1)	/*�ڲ���Ԫ��ǰ���жϲ���λ���Ƿ�Ϸ�*/
{
	printf("����λ��i���Ϸ���\n");
return -1;
}
else if(L->length>=ListSize)	/*�ڲ���Ԫ��ǰ���ж�˳����Ƿ��Ѿ��������ܲ���Ԫ��*/
{
	printf("˳������������ܲ���Ԫ�ء�\n");
	return 0;
}
else
{
	for(j=L->length;j>=i;j--)	/*����i��λ���Ժ��Ԫ�����κ���*/
			L->list[j]=L->list[j-1];
		L->list[i-1]=e;			/*����Ԫ�ص���i��λ��*/
		L->length=L->length+1;	/*��˳�����1*/
		return 1;
	}
}
int DeleteList(SeqList *L,int i,DataType *e)
{
	int j;
	if(L->length<=0)
	{
		printf("˳����ѿղ��ܽ���ɾ��!\n");
		return 0;
	}
	else if(i<1||i>L->length)
	{
printf("ɾ��λ�ò�����!\n");
return -1;
	}
	else
	{
		*e=L->list[i-1];
		for(j=i;j<=L->length-1;j++)
			L->list[j-1]=L->list[j];
		L->length=L->length-1;
		return 1;
	}
}
int ListLength(SeqList L)
{
	return L.length;
}
void ClearList(SeqList *L)
{
	L->length=0;
}