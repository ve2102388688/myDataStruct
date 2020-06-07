#ifndef _PRIM_H
#define _PRIM_H
#pragma warning(disable:4996)

#define INT_MAX		   65535										//最大值65535，表示两顶点没有联系
#define MAX_VERTEX_NUM 20											//最多顶点数

typedef char VertexType;
typedef int  EdgeType;

//有向图, 有向网, 无向图, 无向网
enum GraphKind {
	DG, DN, UDG, UDN
};

//顶点信息
typedef struct ArcCell {
	EdgeType wight;

}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];				//二维数组  

//弧的信息
typedef struct MGraph {
	VertexType vexs[MAX_VERTEX_NUM];								//顶点向量  
	AdjMatrix  arcs;												//邻接矩阵  
	int vexnum, arcnum;												//图的当前顶点数和弧数  
	GraphKind   kind;												//图的种类标志  
}MGraph;


//Prim算法中的辅助信息
struct prim{
	VertexType adjvex;												//存放最短路径的出发节点结点
	EdgeType   lowcost;												//最短路径
};


int LocateVex(MGraph &G, VertexType v);								//判断字符在图的位置
void CreatMGraph(MGraph &G);										//建立无向图的邻接矩阵  
void printMatrixGraph(MGraph &G);									//输出邻接矩阵
int MiniSpanTree_Prim(MGraph &G, VertexType u);						//普利姆算法
int minArc(MGraph &G, struct prim *closedge);						//寻找最小边


#endif // !_PRIM_H
