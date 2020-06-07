#ifndef _GRAPH_H
#define _GRAPH_H

#include <string>
//using namespace std;
//十字链表储存结构
#define MAX_VERTEX_NUM 20						//顶点数目最多20个，顶点放在数组中

//弧结点 
typedef struct ArcBox
{
	int				tailvex, headvex;			//弧的尾与头位置
	struct ArcBox	*hlink, *tlink;				//弧头相同的链域，弧尾相同的链域
}ArcBox;

//顶点结点  
typedef struct 
{
	int nodenum;								//为广度优先遍历获取顶点在数组的位置
	char	data;								//顶点数据
	ArcBox	*firstin, *firstout;				//分别指向该顶点的第一条入弧和出弧
}VexNode;

typedef struct {
	VexNode xlist[MAX_VERTEX_NUM];				//表头向量
	int		vexnum, arcnum;						//有向图的顶点数与弧数
}OLGraph;

int CreatDG(OLGraph &G, int vexnum, int arcnum);
int LocateVex(OLGraph &G, char v);


void DFSTraverse(OLGraph &G);
void DFS(OLGraph &G, int v);

void BFSTraverse(OLGraph &G);
#endif
