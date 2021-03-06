#include "stdafx.h"
#include "Topological.h"
#include <stdlib.h>


//判断字符在图的位置
int LocateVex(DLGraph &G, VertexType v)
{
	for (int m = 0; m < G.vexnum; m++) {
		if (G.vertices[m].data == v)
			return m;
	}
	return -1;
}


//创建有向图的邻接表
void CreatDLGraph(DLGraph &G)
{
	for (int i = 0; i < G.vexnum; i++) {
		printf("Please enter %d data:", i + 1);
		scanf(" %c", &G.vertices[i].data);										//输入顶点值
		G.vertices[i].firstarc = NULL;											//弧表头指针置为空  
	}

	VertexType v1, v2;															//输入的两条弧(A B C···)
	EdgeType w;
	int i, j;																	//获取(v1,v2)各自在图中位置		
	printf("Please input the two data of arc,for example: A C\n");
	for (int k = 0; k < G.arcnum; k++) {
		printf("The %d arc: ", k + 1);
		scanf(" %c", &v1);														//输入第一个顶点
		getchar();																//把输入的空格读走
		v2 = getchar();															//输入弧的第二个顶点
		scanf("%d", &w);														//输入权值
		i = LocateVex(G, v1);													//获取弧的第一个节点位置
		j = LocateVex(G, v2);													//获取弧的第二个节点位置
		

		
		/*******************************************************
		**	1：无向图
		**	2：这里要清楚怎么接上去的
		新结点的next后面接的是之前的一串上（可以这么想，新的节点接在原来的左弧）
		不断把上次firtarc赋值给新节点的next，新的p又接在firtarc
		********************************************************/
		ArxNode *p = (ArxNode *)malloc(sizeof(ArxNode));						//分配弧结点空间
		p->adjvex = j;
		p->nextarc = G.vertices[i].firstarc;									//i是弧尾，且出发的弧是一链表，说明这里的p是
		G.vertices[i].firstarc = p;

		//注意:这里必须在邻接表创建后才能赋值w,不然G.vertices[i].firstarc是个空指针-error
		G.vertices[i].firstarc->weight = w;										//某活动持续的时间

		//p = (ArxNode *)malloc(sizeof(ArxNode));									//重新分配弧结点空间（上面的消逝了）
		//p->adjvex = i;
		//p->nextarc = G.vertices[j].firstarc;									//将结点i链接到j的单链表中
		//G.vertices[j].firstarc = p;
	}
}


//输出有向图的邻接表
void PrintDLGraph(DLGraph &G)
{
	ArxNode *p;																	//切记：这里创建一个临时p，我们不可以把之前邻接表结构改变了，就像给你U盘拷贝东西，你只能复制而不是剪切！你不可以改变之前的结构，不然之后邻接表是个空的
	for (int i = 0; i < G.vexnum; i++)
	{
		printf("%c", G.vertices[i].data);
		p = G.vertices[i].firstarc;												//先指向一个结点
		while (p != NULL) {
			printf(" -%d-->%c",p->weight, G.vertices[p->adjvex]);				//输出弧的权值及结点
			p = p->nextarc;														//指向下一条弧
		}
		printf("\n");
	}
}

//求出度
void FindOutDegree(DLGraph &G, int *indegree)
{
	ArxNode *p;																	//切记：这里创建一个临时p，我们不可以把之前邻接表结构改变了，就像给你U盘拷贝东西，你只能复制而不是剪切！你不可以改变之前的结构，不然之后邻接表是个空的
	int num;
	for (int i = 0; i < G.vexnum; i++)											
	{
		num = 0;
		p = G.vertices[i].firstarc;												//先指向一个结点
		while (p != NULL) {
			p = p->nextarc;														//指向下一条弧
			num++;																//出度加一
		}
		indegree[i] = num;
	}
}


//求入度
void FindInDegree(DLGraph &G, int *indegree)
{
	ArxNode *p;																	//切记：这里创建一个临时p，我们不可以把之前邻接表结构改变了，就像给你U盘拷贝东西，你只能复制而不是剪切！你不可以改变之前的结构，不然之后邻接表是个空的
	int num;
	for (int i = 0; i < G.vexnum; i++)											//求所有节点的入度
	{
		num = 0;
		for(int j = 0; j < G.vexnum; j++)										//一个结点的入度需要遍历所有结点才可以知道
		{ 
			p = G.vertices[j].firstarc;											//先指向一个结点
			while (p != NULL) {
				if (p->adjvex == i)												//从另外一个结点出发的链域，发现与该次所求结点一致，入读加一，break
				{
					num++;
					break;
				}
				p = p->nextarc;													//指向下一条弧
			}
		}
		indegree[i] = num;
		//printf("%d\t", indegree[i]);
	}
}

int *ve;
//拓扑排序
int TopologicalOrder(DLGraph &G, SqStack &S, SqStack &T)
{
	int *indegree = (int *)malloc(G.vexnum * sizeof(int));
	ve = (int *)malloc(G.vexnum * sizeof(int));
	FindInDegree(G, indegree);													//求出每个节点的入度

	int count = 0;																//累计访问的结点个数
	InitStack(S);																//拓扑有序栈
	for (int i = 0; i < G.vexnum; i++) {
		if (!indegree[i])
			Push(S, G.vertices[i].data);										//入度为0，全部入栈S
		ve[i] = 0;																//最早发生时间
	}

	InitStack(T);																//逆拓扑有序栈
	while(!StackEmpty(S)){
		char popData = Pop(S);													//出栈元素
		int popDataIndex = LocateVex(G, popData);								//出栈元素的位置
		Push(T, popData);														//出栈元素马上入栈T
		count++;																//访问节点数+1

		ArxNode *p = G.vertices[popDataIndex].firstarc;
		for (; p; p = p->nextarc) {
			int k = p->adjvex;
			if (--indegree[k] == 0)												//减1，入度为0，入栈S
				Push(S, G.vertices[k].data);
			if (ve[popDataIndex] + p->weight > ve[k])							//更新k最早发生时间
				ve[k] = ve[popDataIndex] + p->weight;
		}
	}

	printf("\n\nve[]：\n");
	for(int i = 0; i < G.vexnum; i++)
		printf("%d\t", ve[i]);

	if (count < G.vexnum)														//该有向网有环
		return ERROR;
	return OK;
}


//求关键路径及长度
int CriticalPath(DLGraph &G)
{
	SqStack S;
	SqStack T;
	int *vl = (int *)malloc(G.vexnum * sizeof(int));

	if (!TopologicalOrder(G, S, T)){											//有环结束，不需要继续了
		printf("The direction graph contains rings, Can't output critical path, Test end!!!\n");
		return ERROR;
	}
	else
	{
		ArxNode *p;
		int k;
		for (int i = 0; i < G.vexnum; i++)
			vl[i] = ve[LocateVex(G, GetTop(T))];								//获取栈T的栈顶元素，找到其位置，把ve[]赋值给vl[]的所有元素（就是把最大值赋给所有的vl[]）
		while (!StackEmpty(T)) {
			char popData = Pop(T);												//出栈元素
			int popDataIndex = LocateVex(G, popData);							//出栈元素的位置
			p = G.vertices[popDataIndex].firstarc;
			for (; p; p = p->nextarc) {
				 k = p->adjvex;
				if (vl[k] - p->weight < vl[popDataIndex]) {						//倒序求，已知k（弧头）求popDataIndex（弧尾），弧尾-弧头<弧头,替换
					vl[popDataIndex] = vl[k] - p->weight;
				}
			}
		}

		printf("\n\nvl[]：\n");													//输出vl[]
		for(int i = 0; i < G.vexnum; i++)
			printf("%d\t", vl[i]);

		/*******************************************************************
		**	这里我举个例子，比如A->B
		**	在第一次循环中，i是A  k是B
						   el是'vl[B]'- 权值 ---如果等于--ee = ve[i]，关键路径
		********************************************************************/
		int ee, el;
		printf("\n\ncritical path  weight\tee    el    是否为关键路径");
		for (int i = 0; i < G.vexnum; i++)										//求所有的关键路径
			for (p = G.vertices[i].firstarc; p; p = p->nextarc) {				//不防从第一个点开始，比如A
				k = p->adjvex;
				ee = ve[i];		el = vl[k] - p->weight;
				if (ee == el) {
					printf("\n%c --> %c weight: %d\tee: %d el:%d   关键路径", G.vertices[i].data, G.vertices[k].data, p->weight, ee, el);
				}
			}
		printf("\n\nThe length of critical path is: %d", vl[G.vexnum-1]);			//关键路径长度
	}
	return OK;
}