#include "stdafx.h"
#include "Prim.h"


int main()
{
	MGraph G;
	printf("Please enter vexnum and arcnum: ");
	scanf("%d %d", &G.vexnum, &G.arcnum);												//输入结点数，弧数

	CreatMGraph(G);																		//建立无向图的邻接矩阵 
	printf("\nTne output of Adjacency Matrix:\n\n");
	printMatrixGraph(G);																//输出邻接矩阵
	printf("\nTne shortest path of Graph:\n\n");
	printf("\nThe sum of the shortest paths is %d.\n", MiniSpanTree_Prim(G, G.vexs[0]));//输出路径与权值

	return 0;
}
