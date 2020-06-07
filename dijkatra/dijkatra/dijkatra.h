#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H
#pragma warning(disable:4996)

//�ڽӾ���
#define INT__MAX	   65000										//���ֵ65535����ʾ������û����ϵ
#define MAX_VERTEX_NUM 20											//��ඥ����

typedef char VertexType;
typedef int  EdgeType;


//������Ϣ
typedef struct ArcCell {
	EdgeType wight;
	
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];				//��ά����  

																	//������Ϣ
typedef struct MGraph {
	VertexType vexs[MAX_VERTEX_NUM];								//��������  
	AdjMatrix  arcs;												//�ڽӾ���  
	int vexnum, arcnum;												//ͼ�ĵ�ǰ�������ͻ���  
}MGraph;

typedef char **shortestCode;										//���·������

int LocateVex(MGraph &G, char v);
void CreatMGraph(MGraph &G);										//��������ͼ���ڽӾ���  
void printMatrixGraph(MGraph &G);									//����ڽӾ���
void ShortestPath_DIJ(MGraph &G, char v0, shortestCode &code);		//�Ͻ�˹������Dijkstra���㷨--������·�����������·��
void ShortestPath_FLOYD(MGraph &G, shortestCode &code);				//�������£�Floyd���㷨--������·�����������·��

#endif // !_DIJKSTRA_H

