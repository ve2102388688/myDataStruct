#include "stdafx.h"
#include "Joint.h"


int main()
{
	ALGraph G;
	printf("Please enter vexnum and arcnum: ");
	scanf("%d %d", &G.vexnum, &G.arcnum);												//输入结点数，弧数

	CreatALGraph(G);																	//创建无向图的邻接表
	printf("\n无向图的邻接表输出:\n");
	PrintALGraph(G);																	//输出无向图的邻接表
	printf("\n关节点输出:\n");
	FindArticul(G);																		//关节点输出
	return 0;
}
