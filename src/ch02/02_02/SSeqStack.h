typedef struct
{
    DataType stack[StackSize];
    int top[2];
}SSeqStack;
void InitStack(SSeqStack *S)
/*����ջ�ĳ�ʼ��*/
{
    S->top[0]=0;
    S->top[1]=StackSize-1;
}
int GetTop(SSeqStack S, DataType *e,int flag)   
/*ȡջ��Ԫ�ء���ջ��Ԫ��ֵ���ظ�e��������1��ʾ�ɹ������򷵻�0��ʾʧ�ܡ�*/
{
	switch(flag)
	{
	case 1:		 /*Ϊ1����ʾҪȡ���ջ��ջ��Ԫ��*/
		if(S.top[0]==0)
			return 0;
		*e=S.stack[S.top[0]-1];
		break;
	case 2: 		/*Ϊ2����ʾҪȡ�Ҷ�ջ��ջ��Ԫ��*/
		if(S.top[1]==StackSize-1)
			return 0;
		*e=S.stack[S.top[1]+1];
		break;
	default:
		return 0;			
	}
	return 1;
}
int PushStack(SSeqStack *S,DataType e,int flag)
/*��Ԫ��e�빲��ջ����ջ�ɹ�����1�����򷵻�0*/
{
	if(S->top[0]==S->top[1])		/*�������ջ����*/
		return 0; 				/*����0����ջʧ��*/
	switch(flag)
	{
	case 1:				/*��flagΪ1����ʾ��Ԫ�ؽ���˵�ջ*/
		S->stack[S->top[0]]=e;	/*Ԫ�ؽ�ջ*/
		S->top[0]++;			/*�޸�ջ��ָ��*/
		break;
	case 2:			/*��flagΪ2����ʾ��Ԫ��Ҫ���Ҷ˵�ջ*/
		S->stack[S->top[1]]=e;	/*Ԫ�ؽ�ջ*/
		S->top[1]--;			/*�޸�ջ��ָ��*/
		break;
	default:
		return 0;
	}
	return 1; 					/*����1����ջ�ɹ�*/
}
int PopStack(SSeqStack *S,DataType *e,int flag)
{
	switch(flag) 			/*�ڳ�ջ����֮ǰ���ж��ĸ�ջҪ���г�ջ����*/
	{
	case 1: 			/*Ϊ1����ʾ��˵�ջ��Ҫ��ջ����*/
		if(S->top[0]==0)	/*��˵�ջΪ��*/
			return 0; 	/*����0����ջ����ʧ��*/
		S->top[0]--;		/*�޸�ջ��ָ�룬Ԫ�س�ջ����*/
		*e=S->stack[S->top[0]];	/*����ջ��Ԫ�ظ���e*/
		break;
	case 2: 			/*Ϊ2����ʾ�Ҷ˵�ջ��Ҫ��ջ����*/
		if(S->top[1]==StackSize-1)	/*�Ҷ˵�ջΪ��*/
			return 0; 			/*����0����ջ����ʧ��*/
		S->top[1]++;				/*�޸�ջ��ָ�룬Ԫ�س�ջ����*/
		*e=S->stack[S->top[1]];	/*����ջ��Ԫ�ظ���e*/
		break;
	default:
		return 0;
	}
	return 1; /*����1����ջ�����ɹ�*/
}
int StackEmpty(SSeqStack S,int flag)
/*�ж�ջ�Ƿ�Ϊ�ա����ջΪ�գ�����1�����򣬷���0��*/
{
	switch(flag)
	{
	case 1: 		/*Ϊ1����ʾ�ж���˵�ջ�Ƿ�Ϊ��*/
		if(S.top[0]==0)
			return 1;
		break;
	case 2: 		/*Ϊ2����ʾ�ж��Ҷ˵�ջ�Ƿ�Ϊ��*/
		if(S.top[1]==StackSize-1)
			return 1;
		break;
	default:
		printf("�����flag��������!");
		return -1;			
	}
	return 0;
}