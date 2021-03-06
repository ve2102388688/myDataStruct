#include "stdafx.h"
#include "thread.h"

/********************************************************************
**	TParent		：双亲节点（后序线索化）
**	BiThrRoot	：头结点（先，中序线索化）
**	T			：根节点
********************************************************************/

int main()
{
	//先序数组
	char Vexch[26] = { 'A','B','D','H','$','$','I','$','$','E','J','$','$','$','C','F','$','$','G','$','$' };
	
	BiThrTree T, TParent, BiThrRoot;								
	printf("先序创建二叉树\n");
	CreatPreBiThreadTree(T, Vexch);
	printf("\n");

	printf("中序创建二叉树\n");
	CreatInBiThreadTree(T, Vexch);
	printf("\n");

	printf("后序创建二叉树\n");
	CreatPostBiThreadTree(T, Vexch, TParent);
	printf("\n");

//注意：以下三段只能一次只能使用其中一组，不同线索化会覆盖之前的线索化，从而出现死循环
	//printf("\n先序遍历线索二叉树\n");
	//PreOrderThreading(BiThrRoot, T);
	//PreOrderTraverse(BiThrRoot, visit);
	//printf("\n");

	//printf("\n中序遍历线索二叉树\n");
	//InOrderThreading(BiThrRoot, T);
	//InOrderTraverse(BiThrRoot, visit);
	//printf("\n");

	printf("\n后序遍历线索二叉树\n");
	PostThreading(T);
	PostOrderTraverse(T, visit);
	printf("\n");
	
	
	printf("\n");
    return 0;
}

