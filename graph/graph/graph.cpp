#include "stdafx.h"
#include "graph.h"
#include "queue.h"
#pragma warning(disable:4996)

//判断字符在图的位置
int LocateVex(OLGraph &G, char v)
{
	for (int m = 0; m < G.vexnum; m++) {
		if (G.xlist[m].data == v)
			return m;
	}
	return -1;
}


//创建有向图的十字链表
int CreatDG(OLGraph &G, int vexnum, int arcnum)
{
	for (int i = 0; i < vexnum; i++) {
		printf("Please enter %d data:", i+1);

		scanf(" %c", &G.xlist[i].data);											//输入顶点值
		
		G.xlist[i].nodenum = i;													//记录顶点的位置
		G.xlist[i].firstin = NULL;												//初始化指针
		G.xlist[i].firstout = NULL;
	}

	char v1, v2;																//一条弧的两个顶点
	int i, j;																	//弧尾位置，弧头位置

	for (int k = 0; k < G.arcnum; k++) {
		printf("Please enter %d arc(tail -> head): ", k + 1);
		scanf(" %c", &v1);													//输入弧的第一个顶点，这里%c前面必须要有一个空格！
		getchar();																//把输入的空格读走
		v2 = getchar();															//输入弧的第二个顶点
		i = LocateVex(G, v1);													//获取弧的第一个节点位置
		j = LocateVex(G, v2);													//获取弧的第二个节点位置

		ArcBox *p = (ArcBox *)malloc(sizeof(ArcBox));							//分配弧结点空间
		p->tailvex = i;		p->tlink = G.xlist[i].firstout;						//i放进tailvex,tlink(尾巴出去firstout)
		p->headvex = j;		p->hlink = G.xlist[j].firstin;						//j放进headvex,hlink(头进来firstin)
		
		G.xlist[j].firstin = G.xlist[i].firstout = p;							//入弧与出弧的插入（数组的firstin firstout有了指向）
	}
	return 0;
}

/******************************************************
**	DFS深度优先遍历
*******************************************************/
bool DFSvisted[20];												//这里定义最多有20个结点
void DFSTraverse(OLGraph &G)
{
	for (int i = 0; i < G.vexnum; i++)							//先把每个结点都标记为假，没有访问过
		DFSvisted[i] = false;
	for (int i = 0; i < G.vexnum; i++) {
		if (!DFSvisted[i])										//对没有访问的结点，按深度优先遍历
			DFS(G, i);
	}
}


void DFS(OLGraph &G, int v)
{
	DFSvisted[v] = true;										//访问结点标识--真
	printf("%c\t", G.xlist[v].data);
	ArcBox *DFStemp = G.xlist[v].firstout;						//用DFStemp来存储该节点的第一个出去的弧

	while (DFStemp)
	{
		if (!DFSvisted[DFStemp->headvex])						//访问此结点第一个出去的弧
			DFS(G, DFStemp->headvex);
		DFStemp = DFStemp->tlink;								//该结点还有指向其他的弧
	}
}

/******************************************************
**	BFS广度优先遍历
*******************************************************/
bool BFSvisted[20];														//这里定义最多有20个结点
void BFSTraverse(OLGraph &G)
{
	for (int i = 0; i < G.vexnum; i++)									//先把每个结点都标记为假，没有访问过
		BFSvisted[i] = false;
	LinkQueue Q;														//初始化队列
	InitQueue(Q);
	ArcBox *BFStemp;													
	char HeadQueue;														//出队元素（队头）第一次会出现一进队就出队
	int headnum = 0;													//队头元素的位置，才好找到十字链表的下一个

	for (int i = 0; i < G.vexnum; i++) {
		if (!BFSvisted[i]) {
			BFSvisted[i] = true;
			printf("%c\t", G.xlist[i].data);							//访问元素
			EnQueue(Q, G.xlist[i].data);								//把访问的元素都入队
			while (!QueueEmpty(Q)) {
				//DeQueue(Q, HeadQueue);									//出队
				printf("出队:%c\t", DeQueue(Q, HeadQueue));

				for (int j = 0; j < G.vexnum; j++) {
					if (G.xlist[j].data == HeadQueue)
						headnum = G.xlist[j].nodenum;					//获取队头位置
				}
				BFStemp = G.xlist[headnum].firstout;					//用BFStemp来存储该节点的第一个出去的弧

				while (BFStemp) {
					if (!BFSvisted[BFStemp->headvex]) {
						BFSvisted[BFStemp->headvex] = true;				//把结点都标记为真
						printf("%c\t", G.xlist[BFStemp->headvex].data);	//访问元素
						EnQueue(Q, G.xlist[BFStemp->headvex].data);		//把访问的元素都入队
					}
					BFStemp = BFStemp->tlink;
				}
			}
		}
	}
}