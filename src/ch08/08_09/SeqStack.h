#define StackSize 100
typedef int DataType;
typedef struct
{
    DataType stack[StackSize];
    int top;
}SeqStack;

void InitStack(SeqStack *S)    
/*��ջ��ʼ��Ϊ��ջֻ��Ҫ��ջ��ָ��top��Ϊ0*/
{
S->top=0;	/*��ջ��ָ����Ϊ0*/
}
int StackEmpty(SeqStack S)   
/*�ж�ջ�Ƿ�Ϊ�գ�ջΪ�շ���1�����򷵻�0*/
{
    if(S.top==0)			/*�ж�ջ��ָ��top�Ƿ�Ϊ0*/
        return 1;			/*��ջΪ��ʱ������1�����򷵻�0*/
    else
        return 0;
}
int GetTop(SeqStack S, DataType *e)   
/*ȡջ��Ԫ�ء���ջ��Ԫ��ֵ���ظ�e��������1��ʾ�ɹ������򷵻�0��ʾʧ�ܡ�*/
{
   if(S.top<=0)		/*��ȡջ��Ԫ��֮ǰ���ж�ջ�Ƿ�Ϊ��*/
{
    printf("ջ�Ѿ���!\n");
    return 0;
}
else
{
    *e=S.stack[S.top-1];	/*��ȡջ��Ԫ��*/
    return 1;
}
}
int PushStack(SeqStack *S,DataType e)   
/*��Ԫ��e��ջ��Ԫ�ؽ�ջ�ɹ�����1�����򷵻�0.*/
{
if(S->top>=StackSize)				/*��Ԫ�ؽ�ջǰ���ж��Ƿ�ջ�Ѿ���*/
{
        printf("ջ���������ܽ�ջ��\n");
        return 0;
}
else
{
        S->stack[S->top]=e;			/*Ԫ��e��ջ*/
        S->top++;					/*�޸�ջ��ָ��*/
        return 1;
}
}
int PopStack(SeqStack *S,DataType *e)
/*��ջ��������ջ��Ԫ�س�ջ�������丳ֵ��e����ջ�ɹ�����1�����򷵻�0*/
{
    if(S->top<=0)		/*Ԫ�س�ջ֮ǰ���ж�ջ�Ƿ�Ϊ��*/
    {
        printf("ջ�Ѿ�û��Ԫ�أ����ܳ�ջ!\n");
        return 0;
    }
    else
{
    S->top--;			/*���޸�ջ��ָ�룬����ջ*/
        *e=S->stack[S->top];	/*����ջԪ�ظ�ֵ��e*/
        return 1;
    }
}
int StackLength(SeqStack S)
/*��ջ�ĳ��ȣ���ջ��Ԫ�ظ�����ջ��ָ���ֵ�͵���ջ��Ԫ�صĸ���*/
{
    return S.top;
}
