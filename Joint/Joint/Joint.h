#ifndef _JOINT_H
#define _JOINT_H
#pragma warning(disable:4996)


#define MAX_VERTEX_NUM  20
typedef char VertexType;

//一个顶点的单链表
typedef struct ArxNode {
	int			    adjvex;					//弧的位置
	struct ArxNode *nextarc;				//该弧的下一弧
}ArxNode;

//顶点数组
typedef struct VNode {
	VertexType  data;						//顶点存放的数据（这里用char--A B C···）
	ArxNode		*firstarc;					//指向第一条弧的指针
	int			 locationOfData;			//把data数组位置记下来，方便知道位置找data
}VNode, AdjList[MAX_VERTEX_NUM];

//ALGraph的整体信息
typedef struct {
	AdjList vertices;
	int		vexnum, arcnum;					//弧的顶点数和弧数
}ALGraph;


int LocateVex(ALGraph &G, VertexType v);								//判断字符在图的位置
char LocateData(ALGraph &G, int i);										//知道位置获取数据Data

void CreatALGraph(ALGraph &G);											//创建无向图的邻接表
void PrintALGraph(ALGraph &G);											//输出无向图的邻接表

void FindArticul(ALGraph &G);											//深度优先寻找关节点
void DFSArticul(ALGraph &G, int v);										

#endif // !_JOINT_H

