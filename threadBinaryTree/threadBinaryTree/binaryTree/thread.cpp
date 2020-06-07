#include "stdafx.h"
#include "thread.h"
#include <stdlib.h>  //֧��malloc

int N = 0;			//���������±�
int N2 = 0;			//���������±�
int N3 = 0;			//���������±�

Status visit(TElemType e) {
	printf("%5c", e);
	return OK;
}



/********************************************************************
**	���������������򣬺���
********************************************************************/
//���򴴽���
Status CreatPreBiThreadTree(BiThrTree &T, char TreeArray[])
{
	char ch = TreeArray[N];
		N++;
	if ('$' == ch) {
		T = NULL;
		return 0;
	}
	else{
		if (!(T = (BiThrNode *)malloc(sizeof(BiThrNode))))
			return OVERFLOW;
		T->data = ch;
		printf("%5c", T->data);
		T->LTag = Link;
		CreatPreBiThreadTree(T->lchild, TreeArray);
		T->RTag = Link;
		CreatPreBiThreadTree(T->rchild, TreeArray);
	}
	return OK;
}

//���򴴽���
Status CreatInBiThreadTree(BiThrTree &T, char TreeArray[])
{
	
	char ch = TreeArray[N2];
		N2++;
	if ('$' == ch) {
		T = NULL;
		return 0;
	}
	else {
		if (!(T = (BiThrTree)malloc(sizeof(BiThrNode))))
			return OVERFLOW;
		T->LTag = Link;
		CreatInBiThreadTree(T->lchild, TreeArray);
		T->data = ch;
		printf("%5c", T->data);
		T->RTag = Link;
		CreatInBiThreadTree(T->rchild, TreeArray);
	}
	return OK;
}

//���򴴽���
Status CreatPostBiThreadTree(BiThrTree &T, char TreeArray[], BiThrTree &parent)
{
	char ch = TreeArray[N3];
		N3++;
	if ('$' == ch) {
		T = NULL;
		return 0;
	}
	else {
		if (!(T = (BiThrNode *)malloc(sizeof(BiThrNode))))
			return OVERFLOW;
		T->Parent = parent;
		T->LTag = Link;
		CreatPostBiThreadTree(T->lchild, TreeArray, T);
		T->RTag = Link;
		CreatPostBiThreadTree(T->rchild, TreeArray, T);
		T->data = ch;
		printf("%5c", T->data);
	}
	return OK;
}



BiThrTree pre;  //ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ�㡣

/********************************************************************
**	(ǰ���У���)��������
********************************************************************/
//����������
void PreThreading(BiThrTree p)
{
	if (p)
	{
		if (!p->lchild)										//ǰ������
		{
			p->lchild = pre;
			p->LTag = Thread;
		}
		if (pre != NULL && !pre->rchild)					//�������
		{
			pre->rchild = p;
			pre->RTag = Thread;
		}
		pre = p;
		if(p->LTag == Link)
			PreThreading(p->lchild);						//������������
		if (p->RTag == Link)
			PreThreading(p->rchild);						//������������
	}
}

//����������
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);				//������������
		if (!p->lchild)						//ǰ������
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild)					//�������
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);				//������������
	}
}

//����������
void PostThreading(BiThrTree p)
{
	if (p)
	{
		PostThreading(p->lchild);			//������������
		PostThreading(p->rchild);			//������������
		if (!p->lchild)						//ǰ������
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (pre && !pre->rchild)			//�������
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
	}
}



/********************************************************************
**	�����������һ��ͷ��㣬ͬʱҲ������������Ȼ����Ҳ�ǿ��Եģ�
**	����ͷ��㣬��Ҫ���ÿ�ָ�룬���ﲻ����ʾ
********************************************************************/
//���������������������ͷ��㣩
Status PreOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
		return OVERFLOW;
	Thrt->LTag = Link;	Thrt->RTag = Thread;				//��ָ��ָ��ͷ���
	Thrt->rchild = Thrt;								    //��ָ���ָ   
	if (!T)
		Thrt->lchild = Thrt;								//������Ϊ�գ���ָ���ָ
	else
	{
		Thrt->lchild = T;	pre = Thrt;						//����ͷ�ڵ�ָ��ͷ�ڵ�
		PreThreading(T);
		pre->rchild = Thrt;  pre->RTag = Thread;			//�������һ���ڵ�ָ������ͷ���
		Thrt->rchild = pre;
	}
	return OK;
}

//���������������������ͷ��㣩--˫������
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	if(!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))		//������ڵ�
		return OVERFLOW;
	Thrt->LTag = Link;	Thrt->RTag = Thread;				//��ָ��ָ��ͷ���
	Thrt->rchild = Thrt;								    //��ָ���ָ   
	if(!T)
		Thrt->lchild = Thrt;								//������Ϊ�գ���ָ���ָ
	else
	{
		Thrt->lchild = T;	pre = Thrt;						//������ڵ�ָ��ͷ�ڵ�
		InThreading(T);
		pre->rchild = Thrt;  pre->RTag = Thread;			//�������һ���ڵ�ָ������ͷ���
		Thrt->rchild = pre;
	}
	return OK;
}



/********************************************************************
**	(ǰ���У���)�����
********************************************************************/
//�������--����Ҫ����������
Status PreOrderTraverse(BiThrTree HeadNode, Status(*visit)(TElemType e))
{
	BiThrTree p = HeadNode->lchild;									//����ͷ���ָ����ڵ�
	while (p != HeadNode)											//תһȦ��������
	{
		while (p->lchild != NULL && p->LTag == Link)				//����һֱ������
		{
			visit(p->data);											//1:���ʸ��ڵ�
			p = p->lchild;											//������
		}
		visit(p->data);												//2:��������߽ڵ�
		if(p->LTag == Thread)										//3:����������(������������򷵻�215�У�������)
			p = p->rchild;								
	}
	return OK;
}

//�������--����Ҫ����������
Status InOrderTraverse(BiThrTree HeadNode, Status(*visit)(TElemType e))
{
	BiThrTree p = HeadNode->lchild;									// ����ͷ���ָ����ڵ�
	while (p != HeadNode) {											//תһȦ��������
		while (p->LTag == Link) {									//һֱ������
			p = p->lchild;
		}
		visit(p->data);												//1:��������߽ڵ�
		while (p->RTag == Thread && p->rchild != HeadNode) {		//������Ϊ�������Ҳ�Ϊͷ���
			p = p->rchild;											//2:���ʷ�֧�ڵ�
			visit(p->data);											
		}
		p = p->rchild;												//�ص���֧�ڵ㣬�ֿ�ʼ232�У�һ��������
	}
	return OK;
}


/********************************************************************
**	�������--����Ҫ����������
**	�������Ҫʹ�ô�˫�׵���������
********************************************************************/
Status PostOrderTraverse(BiThrTree T, Status(*visit)(TElemType e))
{
	if (T)
	{
		BiThrTree p = T;
		pre = NULL;							//����ʹ����ͬһ��preȫ�ֱ������ں���������preֵ�������ɸ��ڵ㣬����Ҫ����
		while (pre != T){ 
			while (p->LTag == Link)			//��һ������������ߵĽڵ� 
			{
				p = p->lchild;
			}
			while (p && p->RTag == Thread)	//�ڶ��������ʺ��  
			{
				visit(p->data);
				pre = p;					//������һ��pre����¼,���ƺ����������ظ���ʵ���ϲ����ǣ��ڱ�����ʱ����Ҫ��ȡ˫�׽ڵ㣬Ҫ��pre
				p = p->rchild;
			}
			while (pre != T && p->rchild == pre)//preʼ����p�ĺ���,���pre��ָ����ڵ�,��ô�Ͳ���Ҫ��˫��,ͬʱҲ�Ǳ��������ı�־
			{
				visit(p->data);
				pre = p;
				if(pre != T)
					p = p->Parent;				//��˫��
			}
			if (p->RTag == Link)				//�ظ�261�У��൱���ִ��½ڵ�������							
			{
				p = p->rchild;
			}
		}
	}
	return OK;
}





