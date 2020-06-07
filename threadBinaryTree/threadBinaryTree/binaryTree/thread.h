#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include <stdio.h>

//为了方便，这里没有处理内存分配失败异常（OVERFLOW）
#define OK			 1
#define ERROR		 0	
#define OVERFLOW	-1

#define TElemType char
#define Status	  int
 

/********************************************************
Funtion:
	线索二叉树结构体（Threaded Binary Tree）
LTag:
	0 : lchild 域指示结点的左孩子 
	1 : lchild 域指示结点的前驱 
RTag:
	0 : rchild 域指示结点的右孩子 
	1 : rchild 域指示结点的后继
注意:
	由于后序线索化及遍历的特殊性，要使用带双亲的三叉链表
	原因请参考数据结构C语言P133的第一页！！！
*********************************************************/
typedef enum {
	Link, Thread
}PointerTag;//Link == 0 :指针, Thread == 1: 线索  

typedef struct BiThrNode {
	TElemType		  data;
	struct BiThrNode *rchild, *lchild, *Parent;	//左右孩子指针，(**Parent给后序线索化用的。先序，中序不考虑*Parent)
	PointerTag		  LTag, RTag;				//左右标识
}BiThrNode, *BiThrTree;

//访问结点data
Status visit(TElemType e);

//创建树（先序，中序，后序）
Status CreatPreBiThreadTree(BiThrTree &T, char TreeArray[]);
Status CreatInBiThreadTree(BiThrTree &T, char TreeArray[]);
Status CreatPostBiThreadTree(BiThrTree &T, char TreeArray[], BiThrTree &parent);

//(前，中，后)序线索化
void PreThreading(BiThrTree p);
void InThreading(BiThrTree p);
void PostThreading(BiThrTree p);

//以下的三个函数仅仅是给二叉树添加一个头结点，同时也更加完整。当然不加也是可以的！
Status PreOrderThreading(BiThrTree &Thrt, BiThrTree T);
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T);

/********************************************************************
**	输入参数：是虚设的头结点，这样是遍历很简单（只需要转回来就结束）
********************************************************************/
Status PreOrderTraverse(BiThrTree HeadNode, Status (*visit)(TElemType e));
Status InOrderTraverse(BiThrTree HeadNode, Status(*visit)(TElemType e));
Status PostOrderTraverse(BiThrTree HeadNode, Status(*visit)(TElemType e));


#endif