
void  CreateBitTree(BiTree *T,char str[])
/*��������Ƕ�׵��ַ���������������*/
{
	char ch;
	BiTree stack[MAXSIZE];			/*����ջ�����ڴ��ָ��������н���ָ��*/
	int top=-1;						/*��ʼ��ջ��ָ��*/
	int flag,k;
	BitNode *p;
	*T=NULL,k=0;
	ch=str[k];
	while(ch!='\0')					/*����ַ���û�н���*/
	{
		switch(ch)
		{
		case '(':
			stack[++top]=p;
			flag=1;
			break;
		case ')':
			top--;
			break;
		case ',':
			flag=2;
			break;
		default:
			p=(BiTree)malloc(sizeof(BitNode));
			p->data=ch;
			p->lchild=NULL;
			p->rchild=NULL;
			if(*T==NULL)		/*����ǵ�һ����㣬��ʾ�Ǹ����*/
				*T=p;
			else
			{
				switch(flag)
				{
				case 1:
					stack[top]->lchild=p;
					break;
				case 2:
					stack[top]->rchild=p;
					break;
				}
			}
		}
		ch=str[++k];
	}
}
void DestroyBitTree(BiTree *T)
/*���ٶ���������*/
{
	if(*T) 							/*����Ƿǿն�����*/
	{
		if((*T)->lchild)
			DestroyBitTree(&((*T)->lchild));
		if((*T)->rchild)
			DestroyBitTree(&((*T)->rchild));
		free(*T);
		*T=NULL;
	}
}
void TreePrint(BiTree T,int level) 
/*����״��ӡ�Ķ�����*/ 
{   
	int i;
	if(T==NULL)									/*���ָ��Ϊ�գ�������һ��*/ 
		return;
	TreePrint(T->rchild,level+1);				/*��ӡ��������������μ�1*/ 
	for(i=0;i<level;i++)						/*���յݹ�Ĳ�δ�ӡ�ո�*/ 
		printf("   ");
	printf("%c\n",T->data);						/*��������*/ 
	TreePrint(T->lchild,level+1);				/*��ӡ��������������μ�1*/ 
}