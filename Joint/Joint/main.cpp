#include "stdafx.h"
#include "Joint.h"


int main()
{
	ALGraph G;
	printf("Please enter vexnum and arcnum: ");
	scanf("%d %d", &G.vexnum, &G.arcnum);												//��������������

	CreatALGraph(G);																	//��������ͼ���ڽӱ�
	printf("\n����ͼ���ڽӱ����:\n");
	PrintALGraph(G);																	//�������ͼ���ڽӱ�
	printf("\n�ؽڵ����:\n");
	FindArticul(G);																		//�ؽڵ����
	return 0;
}
