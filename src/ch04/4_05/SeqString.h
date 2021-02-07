#define MaxLen 255
typedef struct
{
    char str[MaxLen];
    int length;
}SeqString;
void StrAssign(SeqString *S,char cstr[]) 
/*���ĸ�ֵ����*/
{
	int i=0;
	for(i=0;cstr[i]!='\0';i++)	/*������cstr�е��ַ���ֵ����S*/
		S->str[i]=cstr[i];
	S->length=i;
}
int StrEmpty(SeqString S)   
/*�жϴ��Ƿ�Ϊ�գ���Ϊ�շ���1�����򷵻�0*/
{
    if(S.length==0)			/*������ĳ��ȵ���0*/
        return 1;			/*����1*/
    else                    /*����*/
        return 0;            /*����0*/
}
int StrLength(SeqString S) 
/*�󴮵ĳ���*/
{
	return S.length;
}
void StrCopy(SeqString *T,SeqString S) 
/*���ĸ��Ʋ���.*/
{
	int i;
	for(i=0;i<S.length;i++)		/*����S���ַ���ֵ����T*/
		T->str[i]=S.str[i];
	T->length=S.length; 		/*����S�ĳ��ȸ�ֵ����T*/
}
int StrCompare(SeqString S,SeqString T)
/*���ıȽϲ���*/
{
	int i;
	for(i=0;i<S.length&&i<T.length;i++)	/*�ӵ�һ���ַ���ʼ�Ƚ��������е��ַ�*/
		if(S.str[i]!=T.str[i]) 			/*����в���ȵ��ַ�*/
			return (S.str[i]-T.str[i]);      /*���������ַ��Ĳ�ֵ*/
		return (S.length-T.length); 			/*����Ƚ���ϣ������������ĳ��ȵĲ�ֵ*/
}
int StrInsert(SeqString *S,int pos,SeqString T)
/*���Ĳ��롣��S�е�pos��λ�ò���T��Ϊ�������*/
{
	int i;
	if(pos<0||pos-1>S->length) 		/*����λ�ò���ȷ������0*/
	{
		printf("����λ�ò���ȷ");
		return 0;
	}
	if(S->length+T.length<=MaxLen)/*��1������������Ӵ��󴮳���MaxLen���Ӵ�T�����ز��뵽��S��*/
	{
		/*�ڲ����Ӵ�Tǰ����S��pos����ַ�����ƶ�len��λ��*/
		for(i=S->length+T.length-1;i>=pos+T.length-1;i--)
			S->str[i]=S->str[i-T.length];
		/*�������뵽S��*/
		for(i=0;i<T.length;i++)
			S->str[pos+i-1]=T.str[i];
		S->length=S->length+T.length;
		return 1;
	}
	/*��2��������Ӵ�������ȫ���뵽S�У�����S�е��ַ����ᱻ�ص�*/
	else if(pos+T.length<=MaxLen)
	{
		for(i=MaxLen-1;i>T.length+pos-1;i--)	/*��S��pos�Ժ���ַ������ƶ�����������*/
			S->str[i]=S->str[i-T.length];
		for(i=0;i<T.length;i++)					/*��T���뵽S��*/
			S->str[i+pos-1]=T.str[i];
		S->length=MaxLen;
		return 0;
	}
	/*��3��������Ӵ�T���ܱ���ȫ���뵽S�У�T�н������ַ�������*/
	else
	{
		for(i=0;i<MaxLen-pos;i++)			/*��Tֱ�Ӳ��뵽S�У�����֮ǰ����Ҫ�ƶ�S�е��ַ�*/
			S->str[i+pos-1]=T.str[i];
		S->length=MaxLen;
		return 0;
	}
}
int StrDelete(SeqString *S,int pos,int len)
/*�ڴ�S��ɾ��pos��ʼ��len���ַ�*/
{
	int i;
	if(pos<0||len<0||pos+len-1>S->length)		/*����������Ϸ����򷵻�0*/
	{
		printf("ɾ��λ�ò���ȷ������len���Ϸ�");
		return 0;
	}
	else
	{
		for(i=pos+len;i<=S->length-1;i++)		/*����S�ĵ�pos��λ���Ժ��len���ַ����ǵ�*/
			S->str[i-len]=S->str[i];
		S->length=S->length-len; 				/*�޸Ĵ�S�ĳ���*/
		return 1;
	}
}
int StrConcat(SeqString *T,SeqString S)
/*����S�����ڴ�T��ĩβ*/
{
	int i,flag;
	/*��1����������Ӻ�Ĵ���С�ڵ���MaxLen����Sֱ�������ڴ�Tĩβ*/
	if(T->length+S.length<=MaxLen)
	{
		for(i=T->length;i<T->length+S.length;i++)	/*��Sֱ��������T��ĩβ*/
			T->str[i]=S.str[i-T->length];
		T->length=T->length+S.length; 			/*�޸Ĵ�T�ĳ���*/
		flag=1; 							/*�޸ı�־����ʾS�������ӵ�T��*/
	}
	/*��2����������Ӻ󴮳�����MaxLen��S���ֱ������ڴ�Tĩβ*/
	else if(T->length<MaxLen)
	{
		for(i=T->length;i<MaxLen;i++)			/*����S����������T��ĩβ*/
			T->str[i]=S.str[i-T->length];
		T->length=MaxLen; 				     /*�޸Ĵ�T�ĳ���*/
		flag=0; 							/*�޸ı�־����ʾS���ֱ�������T��*/
	}
	return flag;
}
void StrClear(SeqString *S) 
/*��մ���ֻ��Ҫ�����ĳ�����Ϊ0����*/
{
	S->length=0;
}