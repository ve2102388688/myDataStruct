#include "stdafx.h"
#include "graph.h"
#include "queue.h"
#pragma warning(disable:4996)

int main()
{
	OLGraph G;
	printf("Please enter vexnum and arcnum: ");

	scanf("%d %d", &G.vexnum, &G.arcnum);							//��������������
	CreatDG(G, G.vexnum, G.arcnum);									//��������ͼ

	printf("\nDFSTraverse:\n");
	DFSTraverse(G);													//������ȱ���
	printf("\nBFSTraverse:\n");
	BFSTraverse(G);													//������ȱ���
	printf("\n");

	
	return 0;
}