#include "stdafx.h"
#include "graph.h"
#include "queue.h"
#pragma warning(disable:4996)

int main()
{
	OLGraph G;
	printf("Please enter vexnum and arcnum: ");

	scanf("%d %d", &G.vexnum, &G.arcnum);							//输入结点数，弧数
	CreatDG(G, G.vexnum, G.arcnum);									//创建有向图

	printf("\nDFSTraverse:\n");
	DFSTraverse(G);													//深度优先遍历
	printf("\nBFSTraverse:\n");
	BFSTraverse(G);													//广度优先遍历
	printf("\n");

	
	return 0;
}