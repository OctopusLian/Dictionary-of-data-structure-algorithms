
typedef enum{ATOM,LIST}ElemTag; /*ATOM=0����ʾԭ�ӣ�LIST=1����ʾ�ӱ�*/
typedef struct
{
	ElemTag tag;			 	/*��־λtag��������Ԫ����ԭ�ӻ����ӱ�*/
	union
	{
        AtomType atom; 		/*AtomType��ԭ�ӽ���ֵ���û��Լ���������*/
		struct
		{
			struct GLNode *hp,*tp;		/*hpָ���ͷ��tpָ���β*/
        }ptr;
	};
}*GList,GLNode;


GLNode* GetHead(GList L)
/*������ı�ͷ������*/
{
    GLNode *p;
	if(!L) 							/*��������Ϊ�ձ��򷵻�1*/
	{
		printf("�ù�����ǿձ�");
        return NULL;
	}
    p=L->ptr.hp; 					/*�������ı�ͷָ�븳ֵ��p*/
	if(!p)
		printf("�ù����ı�ͷ�ǿձ�.");
	else if(p->tag==LIST)
		printf("�ù����ı�ͷ�Ƿǿյ��ӱ�");
	else
		printf("�ù����ı�ͷ��ԭ�ӡ�");
	return p;
}
GLNode* GeTail(GList L)
/*������ı�β����*/
{
	if(!L) 							/*��������Ϊ�ձ��򷵻�1*/
	{
		printf("�ù�����ǿձ�");
        return;
	}
	return L->ptr.hp; 				/*���������ǿձ��򷵻�ָ���β����ָ��*/
}
int GListLength(GList L)
/*������ĳ��Ȳ���*/
{
    int length=0;
	while(L) 							/*��������ǿգ���pָ���βָ�룬ͳ�Ʊ�ĳ���*/
	{
		L=L->ptr.tp;
        length++;
	}
	return length; 
}
int GListDepth(GList L)
/*���������Ȳ���*/
{
	int max,depth;
	GLNode *p;
	if(!L) 							/*��������ǿգ��򷵻�1*/
		return 1;
	if(L->tag==ATOM) 				/*����������ԭ�ӣ��򷵻�0*/
		return 0;
	for(max=0,p=L;p;p=p->ptr.tp) 		/*��㴦������*/
	{
		depth=GListDepth(p->ptr.hp);
        if(max<depth)
			max=depth;
	}
	return max+1;
}
void CopyList(GList *T,GList L)
/*�����ĸ��Ʋ������ɹ����L���Ƶõ������T*/
{
	if(!L) 							/*��������Ϊ�գ���TΪ�ձ�*/
		*T=NULL;
	else
	{
		*T=(GList)malloc(sizeof(GLNode)); 	/*��L���գ�ΪT����һ������*/
		if(*T==NULL)
			exit(-1);
		(*T)->tag=L->tag;
		if(L->tag==ATOM) 			/*����ԭ��*/
			(*T)->atom=L->atom;
		else						/*�ݹ鸴���ӱ�*/
		{
			CopyList(&((*T)->ptr.hp),L->ptr.hp);
			CopyList(&((*T)->ptr.tp),L->ptr.tp);
		}
	}
}
de *hp,*tp;		/*hpָ���ͷ��tpָ���β*/
        }ptr;
	};
}*GList;
struct GLNode* GetHead(GList L)
/*������ı�ͷ������*/
{
    GLNode *p;
	if(!L) 							/*��������Ϊ�ձ��򷵻�NULL*/
	{
		printf("�ù�����ǿձ�");
        return NULL;
	}
    p=L->ptr.hp; 					/*�������ı�ͷָ�븳ֵ��p*/
	if(!p)
printf("�ù����ı�ͷ�ǿձ�");
	else if(p->tag==LIST)
	printf("�ù����ı�ͷ�Ƿǿյ��ӱ�");
	else
	printf("�ù����ı�ͷ��ԭ�ӡ�");
	return p;
}
GLNode* GeTail(GList L)
/*������ı�β*/
{
	if(!L) 							/*��������Ϊ�ձ��򷵻�NULL*/
	{
		printf("�ù�����ǿձ�");
        return NULL;
	}
	return L->ptr.hp; 				/*���������ǿձ��򷵻�ָ���β����ָ��*/
}
int GListLength(GList L)
/*������ĳ���*/
{
    int length=0;
	while(L) 							/*��������ǿգ���pָ���βָ�룬ͳ�Ʊ�ĳ���*/
	{
		L=L->ptr.tp;
        length++;
	}
	return length; 
}
void CopyList(GList *T,GList L)
/*���ƹ�����ɹ����L���Ƶõ������T*/
{
	if(!L) 							/*��������Ϊ�գ���TΪ�ձ�*/
		*T=NULL;
	else
	{
		*T=(GList)malloc(sizeof(GLNode)); 	/*��L���գ�ΪT����һ������*/
		if(*T==NULL)
			exit(-1);
		(*T)->tag=L->tag;
		if(L->tag==ATOM) 			/*����ԭ��*/
			(*T)->atom=L->atom;
		else						/*�ݹ鸴���ӱ�*/
		{
			CopyList(&((*T)->ptr.hp),L->ptr.hp);
			CopyList(&((*T)->ptr.tp),L->ptr.tp);
		}
	}
}
int GListDepth(GList L)
/*���������Ȳ���*/
{
	int max,depth;
	GLNode *p;
	if(!L) 							/*��������Ϊ�գ��򷵻�1*/
		return 1;
	if(L->tag==ATOM) 				/*����������ԭ�ӣ��򷵻�0*/
		return 0;
	for(max=0,p=L;p;p=p->ptr.tp) 		/*��㴦������*/
	{
		depth=GListDepth(p->ptr.hp);
        if(max<depth)
		max=depth;
	}
	return max+1;
}