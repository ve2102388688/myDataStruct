#include "stdafx.h"
#include "Joint.h"
#include <stdlib.h>


//判断字符在图的位置
int LocateVex(ALGraph &G, VertexType v)
{
	for (int m = 0; m < G.vexnum; m++) {
		if (G.vertices[m].data == v)
			return m;
	}
	return -1;
}


//知道位置获取数据Data
char LocateData(ALGraph &G, int i)
{
	for (int m = 0; m < G.vexnum; m++) {
		if (G.vertices[m].locationOfData == i)
			return G.vertices[m].data;
	}
	return -1;
}


//创建无向图的邻接表
void CreatALGraph(ALGraph &G)
{
	for (int i = 0; i < G.vexnum; i++) {
		printf("Please enter %d data:", i + 1);
		scanf(" %c", &G.vertices[i].data);										//输入顶点值
		G.vertices[i].locationOfData = i;										//把data在数组位置记下来
		G.vertices[i].firstarc = NULL;											//边表头指针置为空  
	}

	VertexType v1, v2;															//输入的两条弧(A B C···)
	int i, j;																	//获取(v1,v2)各自在图中位置		
	printf("Please input the two data of arc,for example: A C\n");
	for (int k = 0; k < G.arcnum; k++) {
		printf("The %d arc: ", k + 1);
		scanf(" %c", &v1);														//输入第一个顶点
		getchar();																//把输入的空格读走
		v2 = getchar();															//输入弧的第二个顶点
		i = LocateVex(G, v1);													//获取弧的第一个节点位置
		j = LocateVex(G, v2);													//获取弧的第二个节点位置


		/*******************************************************
		**	1：无向图相互的，所以下面的两段代码就i，j互换
		**	2：这里要清楚怎么接上去的
			   新结点的next后面接的是之前的一串上（可以这么想，新的节点接在原来的左边）
			   不断把上次firtarc赋值给新节点的next，新的p又接在firtarc
		********************************************************/
		ArxNode *p = (ArxNode *)malloc(sizeof(ArxNode));						//分配弧结点空间
		p->adjvex = j;
		p->nextarc = G.vertices[i].firstarc;									//i是弧尾，且出发的弧是一链表，说明这里的p是
		G.vertices[i].firstarc = p;

		p = (ArxNode *)malloc(sizeof(ArxNode));									//重新分配弧结点空间（上面的消逝了）
		p->adjvex = i;	
		p->nextarc = G.vertices[j].firstarc;									//将结点i链接到j的单链表中
		G.vertices[j].firstarc = p;
	}
}


//输出无向图的邻接表
void PrintALGraph(ALGraph &G)
{
	ArxNode *p;
	for (int i = 0; i < G.vexnum; i++)
	{
		printf("%c", G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while (p != NULL) {
			printf(" --->%c", LocateData(G, p->adjvex));
			p = p->nextarc;
		}
		printf("\n");
	}
}

/*************************************************************************************
									深度优先寻找关节点
**	low(v) = min{DFSvisted[v], low[w], DFSvisted[k]} 从本身，孩子，双亲，回边选最小的
**	DFSvisted[v]：	深度优先各结点的访问次序
**	low[w]：		孩子
**  DFSvisted[w]：  双亲，回边
**************************************************************************************/
int DFSvisted[20];													//这里定义最多有20个结点
int count = 1;														//全局变量，对访问计数
void FindArticul(ALGraph &G)
{
	DFSvisted[0] = 1;												//设定邻接表的0号是生成树的根
	for (int i = 1; i < G.vexnum; i++)
	{
		DFSvisted[i] = 0;											//其余顶点都没有访问
	}
	
	ArxNode *p0 = G.vertices[0].firstarc;							//选取节点0（A），作为DFS人口
	int v = p0->adjvex;
	DFSArticul(G, v);												//从v顶点出发深度优先查找关节点

	if (count < G.vexnum) {											//生成树上至少有两颗子树
		printf("Joint Point(Vertex): %c\n", G.vertices[0].data);	//输出v顶点是关节点
		while (p0->nextarc) {
			p0 = p0->nextarc;		v = p0->adjvex;
			if(DFSvisted[v] == 0)
				DFSArticul(G, v);									//从新的v顶点出发深度优先查找关节点
		}
	}
}


int low[20];														//DFSArticul()是递归调用，low[20]定义在外
void DFSArticul(ALGraph &G, int v0)
{
	ArxNode *p;
	int w;
	int min = DFSvisted[v0] = ++count;								//v0是第count访问的顶点
	for (p = G.vertices[v0].firstarc; p; p = p->nextarc)			//沿着一个单链表一个一个往下走，并检查
	{
		w = p->adjvex;												//w是v0的孩子
		if (DFSvisted[w] == 0)										//W没有访问，是v0的孩子
		{
			DFSArticul(G, w);										//返回前求得low[w]
			if (low[w] < min)
				min = low[w];										//孩子(w)与min比较
			if(low[w] >= DFSvisted[v0])
				printf("Joint Point: %c\n", G.vertices[v0].data);	//输出v0顶点是关节点
		}
		else if (DFSvisted[w] < min)								//w已访问（回边），那么w以是v0的祖先
		{
			min = DFSvisted[w];										
		}
	}
	low[v0] = min;													//保持low数组最小
}