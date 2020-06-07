#include "stdafx.h"
#include "Topological.h"
#include "stack.h"

int main()
{
	DLGraph G;
	printf("Please enter vexnum and arcnum: ");
	scanf("%d %d", &G.vexnum, &G.arcnum);												//输入结点数，弧数

	CreatDLGraph(G);																	//创建有向图的邻接表
	printf("\n无向图的邻接表输出:\n");
	PrintDLGraph(G);																	//输出有向图的邻接表

	CriticalPath(G);																	//输出关键路径与长度

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

