#include <stdio.h>
#define MAXSIZE 100
int Comb(int n,int m);
void main()
{
	int n,m;
	printf("������n��m�����ڵ���1С�ڵ���20��n>m����");
	scanf("%d,%d",&n,&m);
	printf("ջ��ָ��  [top][1] [top][2] [top][3]\n");
	printf("C(%d,%d)=%8d\n",n,m,Comb(n,m));
}
int Comb(int n,int m)
//����c(n,m)��ֵ
{
	int s1,s2,tag=0;//tag��־Ϊ�˱����ظ����
	int stack[MAXSIZE][3],top=1;//����ջstack����ʼ��ջ
	if (n<m || n<0 || m<0)
	{
		printf("n��mֵ����ȷ!" );
		return -1;
	}
	stack[top][1]=0; //ջ�����1�ĳ�ʼ������ֵ0��ջ
	stack[top][2]=n; //ջ�����2�ĳ�ʼ������ֵn��ջ
	stack[top][3]=m; //ջ�����3�ĳ�ʼ������ֵm��ջ
	do
	{
		printf("top=%d:%8d,%8d,%8d\n",top,stack[top][1],stack[top][2],stack[top][3]);
		if (stack[top][1]==0)
		//��ջ��Ϊ(0,n,m)����ʾҪ����ֽ⣬��(0,n-1,m)��ջ������C(n,m-1)��ֵ
		{
			top++;
			stack[top][1]=0;
			stack[top][2]=stack[top-1][2]-1;
			stack[top][3]=stack[top-1][3];
			if (stack[top][3]==0 || stack[top][2]==stack[top][3])
			//��ջ�����3��ֵΪ0����2��ֵ���ڱ��3��ֵ��������1����ֵ1
			{
				stack[top][1]=1;	
			}
			tag=1;
		}
		if (top>=2 && stack[top][1]>0 && stack[top-1][1]==0)
		//��ջ�����1��ֵ����0�Ҵ�ջ�����1��ֵΪ0����ʾC(n,m-1)�����Ѽ��㣬����C(n-1,m-1)���֣���(0,n-1,m-1)��ջ
		{
			printf("top=%d:%8d,%8d,%8d\n",top,stack[top][1],stack[top][2],stack[top][3]);
			top++;
			stack[top][1]=0;
			stack[top][2]=stack[top-2][2]-1;
			stack[top][3]=stack[top-2][3]-1;
			if (stack[top][3]==0 || stack[top][2]==stack[top][3])
			//��ջ�����2��ֵΪ0����2��ֵ���ڱ��3��ֵ����õ����1��ֵ1
				stack[top][1]=1;
			tag=1;
		}
		if (top>2 && stack[top][1]>0 && stack[top-1][1]>0)
		//��ջ���ʹ�ջ�����1��ֵ������0������ջ���Σ�������ջ�����1ֵ֮
		{
			if(tag)
			{
				printf("top=%d:%8d,%8d,%8d\n",top,stack[top][1],stack[top][2],stack[top][3]);
				tag=0;
			}	
			s1=stack[top][1];
			s2=stack[top-1][1];
			top=top-2;
			stack[top][1]=s1+s2;
		}
	} while (top>1);//��ջ��ֻ��һ��Ԫ��ʱ���������ɣ��˳�ѭ��
	return(stack[1][1]);
}
