#include "stdafx.h"
#include "Prim.h"


int main()
{
	MGraph G;
	printf("Please enter vexnum and arcnum: ");
	scanf("%d %d", &G.vexnum, &G.arcnum);												//��������������

	CreatMGraph(G);																		//��������ͼ���ڽӾ��� 
	printf("\nTne output of Adjacency Matrix:\n\n");
	printMatrixGraph(G);																//����ڽӾ���
	printf("\nTne shortest path of Graph:\n\n");
	printf("\nThe sum of the shortest paths is %d.\n", MiniSpanTree_Prim(G, G.vexs[0]));//���·����Ȩֵ

	return 0;
}
