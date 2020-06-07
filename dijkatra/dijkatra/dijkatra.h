#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H
#pragma warning(disable:4996)

//邻接矩阵
#define INT__MAX	   65000										//最大值65535，表示两顶点没有联系
#define MAX_VERTEX_NUM 20											//最多顶点数

typedef char VertexType;
typedef int  EdgeType;


//顶点信息
typedef struct ArcCell {
	EdgeType wight;
	
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];				//二维数组  

																	//弧的信息
typedef struct MGraph {
	VertexType vexs[MAX_VERTEX_NUM];								//顶点向量  
	AdjMatrix  arcs;												//邻接矩阵  
	int vexnum, arcnum;												//图的当前顶点数和弧数  
}MGraph;

typedef char **shortestCode;										//最短路径编码

int LocateVex(MGraph &G, char v);
void CreatMGraph(MGraph &G);										//建立无向图的邻接矩阵  
void printMatrixGraph(MGraph &G);									//输出邻接矩阵
void ShortestPath_DIJ(MGraph &G, char v0, shortestCode &code);		//迪杰斯特拉（Dijkstra）算法--求得最短路径长度与最短路径
void ShortestPath_FLOYD(MGraph &G, shortestCode &code);				//弗洛伊德（Floyd）算法--求得最短路径长度与最短路径

#endif // !_DIJKSTRA_H

