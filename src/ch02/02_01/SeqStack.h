#define StackSize 100
typedef struct
{
    DataType stack[StackSize];
    int top;
}SeqStack;
void InitStack(SeqStack *S)    
/*��ʼ��ջ*/
{
S->top=0;	/*��ջ��ָ����Ϊ0*/
}
int StackEmpty(SeqStack S)   
/*�ж�ջ�Ƿ�Ϊ�գ�ջΪ�շ���1�����򷵻�0*/
{
    if(S.top==0)			/*���ջ��ָ��topΪ0*/
        return 1;			/*����1*/
    else					/*����*/
        return 0; 			/*����0*/
}
int GetTop(SeqStack S, DataType *e)   
/*ȡջ��Ԫ�ء���ջ��Ԫ��ֵ���ظ�e������1��ʾ�ɹ�������0��ʾʧ�ܡ�*/
{
if(S.top<=0)		/*���ջΪ��*/
{
printf("ջ�Ѿ���!\n");
return 0;
}
else				/*����*/
{
*e=S.stack[S.top-1];	/*��ȡջ��Ԫ��*/
return 1;
}
}
int PushStack(SeqStack *S,DataType e)   
/*��Ԫ��e��ջ��Ԫ�ؽ�ջ�ɹ�����1�����򷵻�0.*/
{
if(S->top>=StackSize)				/*���ջ����*/
{
printf("ջ���������ܽ�Ԫ�ؽ�ջ��\n");
  return 0;
}
else								/*����*/
{
S->stack[S->top]=e;			/*Ԫ��e��ջ*/
S->top++;					/*�޸�ջ��ָ��*/
return 1;
}
}
int PopStack(SeqStack *S,DataType *e)
/*��ջ��������ջ��Ԫ�س�ջ�������丳ֵ��e����ջ�ɹ�����1�����򷵻�0*/
{
    if(S->top==0)		/*���ջΪ��*/
    {
        printf("ջ���Ѿ�û��Ԫ�أ����ܽ��г�ջ����!\n");
        return 0;
    }
	else				/*����*/
{
 S->top--;			/*���޸�ջ��ָ�룬����ջ*/
*e=S->stack[S->top];	/*����ջԪ�ظ���e*/
        return 1;
    }
}
int StackLength(SeqStack S)
/*��ջ�ĳ���*/
{
    return S.top;
}
void ClearStack(SeqStack *S)    
/*���ջ*/
{
S->top=0;			/*��ջ��ָ����Ϊ0*/
}