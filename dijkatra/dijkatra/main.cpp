#include "stdafx.h"
#include "dijkatra.h"

int main()
{
	MGraph G;																			//有向图的邻接矩阵
	shortestCode code;																	//编码--输出路径

	printf("Please enter vexnum and arcnum: ");
	scanf("%d %d", &G.vexnum, &G.arcnum);												//输入结点数，弧数

	CreatMGraph(G);																		//建立无向图的邻接矩阵 
	printf("\nTne output of Adjacency Matrix:\n\n");
	printMatrixGraph(G);																//输出邻接矩阵

	ShortestPath_DIJ(G, G.vexs[0], code);												//迪杰斯特拉（Dijkstra）算法--求得最短路径长度与最短路径
	ShortestPath_FLOYD(G, code);														//弗洛伊德（Floyd）算法--求得最短路径长度与最短路径
	return 0;
}

