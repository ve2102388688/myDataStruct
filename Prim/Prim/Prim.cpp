#include "stdafx.h"
#include "Prim.h"


//判断字符在图的位置
int LocateVex(MGraph &G, char v)
{
	for (int m = 0; m < G.vexnum; m++) {
		if (G.vexs[m] == v)
			return m;
	}
	return -1;
}


//输出邻接矩阵
void printMatrixGraph(MGraph &G)
{
	for (int i = 0; i < G.vexnum; i++)
	{ 
		for (int j = 0; j < G.vexnum; j++)
			printf("%d\t", G.arcs[j][i].wight);
		printf("\n");
	}
}


//建立无向图的邻接矩阵  
void CreatMGraph(MGraph &G)
{
	for (int i = 0; i < G.vexnum; i++) {
		printf("Please enter %d data:", i + 1);
		scanf(" %c", &G.vexs[i]);											//输入顶点值
	}
	for (int i = 0; i<G.vexnum; i++)
		for (int j = 0; j<G.vexnum; j++)
			G.arcs[i][j].wight = INT_MAX;           //邻接矩阵初始化  

	VertexType v1, v2;
	EdgeType w;
	int i, j;
	printf("Please input the two data of arc and wight,for example: A C 5\n");
	for (int k = 0; k < G.arcnum; k++) {
		printf("The %d arc: ", k + 1);
		scanf(" %c", &v1);														//输入第一个顶点
		getchar();																//把输入的空格读走
		v2 = getchar();															//输入弧的第二个顶点
		scanf("%d", &w);														//输入结点数，弧数
		i = LocateVex(G, v1);													//获取弧的第一个节点位置
		j = LocateVex(G, v2);													//获取弧的第二个节点位置

		G.arcs[i][j].wight = G.arcs[j][i].wight = w;							//把权值存放在邻接矩阵中
	}
}


struct prim closedge[MAX_VERTEX_NUM];

//寻找最小边
int minArc(MGraph &G, struct prim *closedge)
{
	int min = INT_MAX;
	int index = -1;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (closedge[i].lowcost < min && closedge[i].lowcost != 0)
		{
			min = closedge[i].lowcost;
			index = i;
		}
	}
	return index;
}

/************************************************************************
**						普利姆算法
**	输入参数：MGraph &G			图（邻接矩阵表示）
			：VertexType u		任选一个顶点
**	返回参数：minSum			最短路径之和
*************************************************************************/

int MiniSpanTree_Prim(MGraph &G, VertexType u)
{
	int k = LocateVex(G, u);																			//确定第一个顶点的位置
	closedge[k].lowcost = 0;																			//并入U集
	for (int i = 0; i < G.vexnum; i++)																	//初始化辅助数组
		if(i != k)
		{ 
			closedge[i].adjvex = u;																		//存入起始结点
			closedge[i].lowcost = G.arcs[k][i].wight;													//邻接矩阵该行拷贝到辅助数组中
		}
	
	int minSum = 0;																						//最短路径之和
	for (int i = 0; i < G.vexnum - 1; i++)																//选择其余G.vexnum - 1个顶点
	{
		int mincost = minArc(G, closedge);															    //选择最小代价的边
		printf("%c--%c  %d\n", closedge[mincost].adjvex, G.vexs[mincost], closedge[mincost].lowcost);	//输出路径与权值
		minSum += closedge[mincost].lowcost;															//最短路径之和
		closedge[mincost].lowcost = 0;																	//将mincost并入U集
		for (int j = 0; j < G.vexnum; j++)																
		{
			if (G.arcs[mincost][j].wight < closedge[j].lowcost)											//如果有更小的边，把小的替换原来的
			{
				closedge[j].adjvex = G.vexs[mincost];
				closedge[j].lowcost = G.arcs[mincost][j].wight;
			}
		}
	}
	return minSum;																						//返回最短路径之和
}


