#include "stdafx.h"
#include "Topological.h"
#include "stack.h"

int main()
{
	DLGraph G;
	printf("Please enter vexnum and arcnum: ");
	scanf("%d %d", &G.vexnum, &G.arcnum);												//��������������

	CreatDLGraph(G);																	//��������ͼ���ڽӱ�
	printf("\n����ͼ���ڽӱ����:\n");
	PrintDLGraph(G);																	//�������ͼ���ڽӱ�

	CriticalPath(G);																	//����ؼ�·���볤��

	return 0;
}
//SqStack s;
//InitStack(s);
//SElemType data[] = {'A', 'B', 'C', 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K'};
//for (int i = 0; i < 11; i++)
//	Push(s, data[i]);
//for (int i = 0; i < 11; i++)
//{ 
//	printf("%c\n", GetTop(s));
//	printf("%c\n", Pop(s));

//}

