#include "stdafx.h"
#include "thread.h"
#include <stdlib.h>  //支持malloc

int N = 0;			//先序数组下表
int N2 = 0;			//中序数组下表
int N3 = 0;			//后序数组下表

Status visit(TElemType e) {
	printf("%5c", e);
	return OK;
}



/********************************************************************
**	创建树（先序，中序，后序）
********************************************************************/
//先序创建树
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

//中序创建树
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

//后序创建树
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



BiThrTree pre;  //全局变量，始终指向刚刚访问过的结点。

/********************************************************************
**	(前，中，后)序线索化
********************************************************************/
//先序线索化
void PreThreading(BiThrTree p)
{
	if (p)
	{
		if (!p->lchild)										//前驱线索
		{
			p->lchild = pre;
			p->LTag = Thread;
		}
		if (pre != NULL && !pre->rchild)					//后继线索
		{
			pre->rchild = p;
			pre->RTag = Thread;
		}
		pre = p;
		if(p->LTag == Link)
			PreThreading(p->lchild);						//左子树线索化
		if (p->RTag == Link)
			PreThreading(p->rchild);						//右子树线索化
	}
}

//中序线索化
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);				//左子树线索化
		if (!p->lchild)						//前驱线索
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild)					//后继线索
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);				//右子树线索化
	}
}

//后序线索化
void PostThreading(BiThrTree p)
{
	if (p)
	{
		PostThreading(p->lchild);			//左子树线索化
		PostThreading(p->rchild);			//右子树线索化
		if (!p->lchild)						//前驱线索
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (pre && !pre->rchild)			//后继线索
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
	}
}



/********************************************************************
**	给二叉树添加一个头结点，同时也更加完整。当然不加也是可以的！
**	不加头结点，需要利用空指针，这里不再演示
********************************************************************/
//先序线索化二叉树（添加头结点）
Status PreOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
		return OVERFLOW;
	Thrt->LTag = Link;	Thrt->RTag = Thread;				//左指针指向头结点
	Thrt->rchild = Thrt;								    //右指针回指   
	if (!T)
		Thrt->lchild = Thrt;								//二叉树为空，左指针回指
	else
	{
		Thrt->lchild = T;	pre = Thrt;						//虚设头节点指向头节点
		PreThreading(T);
		pre->rchild = Thrt;  pre->RTag = Thread;			//处理最后一个节点指向虚设头结点
		Thrt->rchild = pre;
	}
	return OK;
}

//中序线索化二叉树（添加头结点）--双向链表
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	if(!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))		//虚设根节点
		return OVERFLOW;
	Thrt->LTag = Link;	Thrt->RTag = Thread;				//左指针指向头结点
	Thrt->rchild = Thrt;								    //右指针回指   
	if(!T)
		Thrt->lchild = Thrt;								//二叉树为空，左指针回指
	else
	{
		Thrt->lchild = T;	pre = Thrt;						//虚设根节点指向头节点
		InThreading(T);
		pre->rchild = Thrt;  pre->RTag = Thread;			//处理最后一个节点指向虚设头结点
		Thrt->rchild = pre;
	}
	return OK;
}



/********************************************************************
**	(前，中，后)序遍历
********************************************************************/
//先序遍历--必须要先序线索化
Status PreOrderTraverse(BiThrTree HeadNode, Status(*visit)(TElemType e))
{
	BiThrTree p = HeadNode->lchild;									//虚设头结点指向根节点
	while (p != HeadNode)											//转一圈回来结束
	{
		while (p->lchild != NULL && p->LTag == Link)				//先序一直向左走
		{
			visit(p->data);											//1:访问根节点
			p = p->lchild;											//向左走
		}
		visit(p->data);												//2:访问最左边节点
		if(p->LTag == Thread)										//3:遍历右子树(如果有子树，则返回215行，往左走)
			p = p->rchild;								
	}
	return OK;
}

//中序遍历--必须要中序线索化
Status InOrderTraverse(BiThrTree HeadNode, Status(*visit)(TElemType e))
{
	BiThrTree p = HeadNode->lchild;									// 虚设头结点指向根节点
	while (p != HeadNode) {											//转一圈回来结束
		while (p->LTag == Link) {									//一直往左走
			p = p->lchild;
		}
		visit(p->data);												//1:访问最左边节点
		while (p->RTag == Thread && p->rchild != HeadNode) {		//右子树为线索，且不为头结点
			p = p->rchild;											//2:访问分支节点
			visit(p->data);											
		}
		p = p->rchild;												//回到分支节点，又开始232行，一个新子树
	}
	return OK;
}


/********************************************************************
**	后序遍历--必须要后序线索化
**	后序遍历要使用带双亲的三叉链表
********************************************************************/
Status PostOrderTraverse(BiThrTree T, Status(*visit)(TElemType e))
{
	if (T)
	{
		BiThrTree p = T;
		pre = NULL;							//由于使用了同一个pre全局变量，在后序线索化pre值会遗留成根节点，这里要清零
		while (pre != T){ 
			while (p->LTag == Link)			//第一步：找树最左边的节点 
			{
				p = p->lchild;
			}
			while (p && p->RTag == Thread)	//第二步：访问后继  
			{
				visit(p->data);
				pre = p;					//这里用一个pre来记录,看似和线索化相重复，实际上并不是，在遍历的时候需要获取双亲节点，要有pre
				p = p->rchild;
			}
			while (pre != T && p->rchild == pre)//pre始终在p的后面,如果pre都指向根节点,那么就不需要找双亲,同时也是遍历结束的标志
			{
				visit(p->data);
				pre = p;
				if(pre != T)
					p = p->Parent;				//找双亲
			}
			if (p->RTag == Link)				//重复261行，相当于又从新节点往左走							
			{
				p = p->rchild;
			}
		}
	}
	return OK;
}





