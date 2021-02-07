#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
typedef char AtomType;//Ԫ������Ϊ�ַ���
typedef enum{ATOM,LIST}ElemTag; /*ATOM=0����ʾԭ�ӣ�LIST=1����ʾ�ӱ�*/
//�����Ĵ洢�ṹ
struct GNode
{
	ElemTag tag;	//��־��
	union
	{	
		AtomType atom;	//ֵ��
		struct GNode *hp;//�ӱ�ı�ͷָ��
	};
	struct GNode *tp;	//��̽���ָ��
};
int LengthGList(struct GNode *GL);	//������ĳ���
int DepthGList(struct GNode *GL);	//����������
void CreateGList(struct GNode **GL);//���������Ĵ洢�ṹ
void PrintGList(struct GNode *GL);	//��ӡ��������
int SearchGList(struct GNode *GL, AtomType e);//���ҵ��ڸ����ַ��ĵ�Ԫ�ؽ�㣬���ҳɹ��򷵻�1�����򷵻�0

void main()
{
	int flag;
	AtomType e;
	struct GNode *GL;
	cout<<"����һ�������(�Իس�����)."<<endl;
	CreateGList(&GL);
	cout<<"��������"<<endl;
	PrintGList(GL);
	cout<<endl;
	cout<<"�����ĳ��ȣ�";
	cout<<LengthGList(GL->hp)<<endl;
	cout<<"��������ȣ�";
	cout<<DepthGList(GL->hp)<<endl;
	cout<<"������Ҫ���ҵ�ԭ��Ԫ��:"<<endl;
	cin>>e;
	flag=SearchGList(GL,e);
	if(flag)
		cout<<"������д��ڲ��ҵ�Ԫ�ء�"<<endl;
	else
		cout<<"Ҫ���ҵ�Ԫ�ز����ڡ�"<<endl;
}
int LengthGList(struct GNode *GL)
//������ĳ���
{
	if(GL!=NULL)
		return(1 + LengthGList(GL->tp));
	else
		return(0);
}
int DepthGList(struct GNode *GL)
//����������
{
	int max=0;//��max����ֵ
	int dep;
	//��������ÿһ����㣬��������ӱ��������
	while(GL!=NULL)
	{
		if(GL->tag==LIST)
		{
			dep = DepthGList(GL->hp);//�ݹ�������һ���ӱ�����
			if(dep > max)
				max = dep;//��maxʼ��Ϊͬһ����������ӱ�����ȵ����ֵ
		}
		GL = GL->tp;//ʹGLָ��ͬһ�����һ�����
	}
	return max + 1;//���ر�����
}
void CreateGList(struct GNode **GL)
//���������Ĵ洢�ṹ
{
	char ch;
	scanf("%c", &ch);//����һ���ַ����˴�ֻ���ܶ���ո�#�������Ż�Ӣ����ĸ
	if(ch=='#')//������Ϊ�ո����ñ�ͷָ��Ϊ��
		*GL = NULL;
	else if(ch=='(')//������Ϊ������������*GL��ָ����ӱ��㲢�ݹ鹹���ӱ�
	{
		*GL = (struct GNode*)malloc(sizeof(struct GNode));
		(*GL)->tag = LIST;
		CreateGList(&((*GL)->hp));
	}
	else{	//������Ϊ�ַ�������*GL��ָ��ĵ�Ԫ�ؽ��
		*GL = (struct GNode*)malloc(sizeof(struct GNode));
		(*GL)->tag = ATOM;
		(*GL)->atom = ch;
	}
	scanf("%c", &ch);//�˴�������ַ���Ϊ���š������Ż�ֺ�
	if(*GL==NULL)//��*GLΪ�գ���ʲô������
		;	
	else if(ch==',')//�����붺����ݹ鹹���̱�
		CreateGList(&((*GL)->tp));
	else if((ch==')') || (ch=='\n'))//������Ϊ�����Ż�ֺ�����*GL�ĺ��ָ����Ϊ��
		(*GL)->tp = NULL;
}
void PrintGList(struct GNode *GL)
//��ӡ��������
{
	if(GL->tag==LIST)	//�����ӱ�
	{
		printf("(");//����������ţ���Ϊ��ʼ����
		if(GL->hp==NULL)//���ӱ�Ϊ���������#���ַ�
			printf("#");
		else//���ӱ�ǿգ���ݹ�����ӱ�
			PrintGList(GL->hp);
		printf(")");//��һ���ӱ����������Ӧ���һ����������ֹ��
	}
	else//����ԭ��Ԫ�ؽ�㣬������ý���ֵ
		printf("%c", GL->atom);
	if(GL->tp!=NULL)//������ĺ���ӱ�
	{
		printf(",");//��������ŷָ���
		PrintGList(GL->tp);//�ٵݹ��������ӱ�
	}
}
int SearchGList(struct GNode *GL, AtomType e)
//���ҵ���ԭ��Ԫ�ؽ�㣬���ҳɹ��򷵻�1�����򷵻�0
{
	while(GL!=NULL)
	{
		if(GL->tag == LIST)//�����ӱ���ݹ�����������ӱ�
		{
			if(SearchGList(GL->hp, e))
				return 1;
		}
		else//����ԭ��Ԫ�ؽ�㣬���ѯ�Ƿ����ֵe ���������򷵻�1
		{
			if(GL->atom == e)
				return 1;
		}
		GL = GL->tp;//ʹGLָ��ͬһ�����һ�����
	}
	return 0;//��������ֵe ���򷵻�0
}
