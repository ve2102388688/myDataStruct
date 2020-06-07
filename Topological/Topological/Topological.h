#ifndef _TOPOLOGICAL_H
#define _TOPOLOGICAL_H
#include "stack.h"
#pragma warning(disable:4996)

/*******************************************************
**				存储结构--有向图的邻接表
	有向
	权值---某活动持续的时间
**				栈（拓补排序（S） 逆拓补排序(T)）
********************************************************/
#define MAX_VERTEX_NUM  20
typedef char VertexType;
typedef int EdgeType;

//一个顶点的单链表
typedef struct ArxNode {
	int			    adjvex;									//弧的位置
	struct ArxNode *nextarc;								//该弧的下一弧
	EdgeType	weight;										//弧的权值（某活动持续的时间）
}ArxNode;

//顶点数组
typedef struct VNode {
	VertexType  data;										//顶点存放的数据（这里用char--A B C···）
	ArxNode		*firstarc;									//指向第一条弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];

//DLGraph的整体信息
typedef struct {
	AdjList vertices;
	int		vexnum, arcnum;									//顶点数和弧数
}DLGraph;


int LocateVex(DLGraph &G, VertexType v);					//判断字符在图的位置
void CreatDLGraph(DLGraph &G);								//创建有向图的邻接表
void PrintDLGraph(DLGraph &G);								//输出有向图的邻接表
void FindInDegree(DLGraph &G, int *indegree);				//求入度
void FindOutDegree(DLGraph &G, int *indegree);				//求出度
int TopologicalOrder(DLGraph &G, SqStack &S, SqStack &T);	//拓扑排序
int CriticalPath(DLGraph &G);								//求关键路径及长度



#endif // !_TOPOLOGICAL_H

