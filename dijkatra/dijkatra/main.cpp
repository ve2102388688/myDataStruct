#include "stdafx.h"
#include "dijkatra.h"

int main()
{
	MGraph G;																			//����ͼ���ڽӾ���
	shortestCode code;																	//����--���·��

	printf("Please enter vexnum and arcnum: ");
	scanf("%d %d", &G.vexnum, &G.arcnum);												//��������������

	CreatMGraph(G);																		//��������ͼ���ڽӾ��� 
	printf("\nTne output of Adjacency Matrix:\n\n");
	printMatrixGraph(G);																//����ڽӾ���

	ShortestPath_DIJ(G, G.vexs[0], code);												//�Ͻ�˹������Dijkstra���㷨--������·�����������·��
	ShortestPath_FLOYD(G, code);														//�������£�Floyd���㷨--������·�����������·��
	return 0;
}

