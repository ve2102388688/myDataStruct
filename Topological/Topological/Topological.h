#ifndef _TOPOLOGICAL_H
#define _TOPOLOGICAL_H
#include "stack.h"
#pragma warning(disable:4996)

/*******************************************************
**				�洢�ṹ--����ͼ���ڽӱ�
	����
	Ȩֵ---ĳ�������ʱ��
**				ջ���ز�����S�� ���ز�����(T)��
********************************************************/
#define MAX_VERTEX_NUM  20
typedef char VertexType;
typedef int EdgeType;

//һ������ĵ�����
typedef struct ArxNode {
	int			    adjvex;									//����λ��
	struct ArxNode *nextarc;								//�û�����һ��
	EdgeType	weight;										//����Ȩֵ��ĳ�������ʱ�䣩
}ArxNode;

//��������
typedef struct VNode {
	VertexType  data;										//�����ŵ����ݣ�������char--A B C��������
	ArxNode		*firstarc;									//ָ���һ������ָ��
}VNode, AdjList[MAX_VERTEX_NUM];

//DLGraph��������Ϣ
typedef struct {
	AdjList vertices;
	int		vexnum, arcnum;									//�������ͻ���
}DLGraph;


int LocateVex(DLGraph &G, VertexType v);					//�ж��ַ���ͼ��λ��
void CreatDLGraph(DLGraph &G);								//��������ͼ���ڽӱ�
void PrintDLGraph(DLGraph &G);								//�������ͼ���ڽӱ�
void FindInDegree(DLGraph &G, int *indegree);				//�����
void FindOutDegree(DLGraph &G, int *indegree);				//�����
int TopologicalOrder(DLGraph &G, SqStack &S, SqStack &T);	//��������
int CriticalPath(DLGraph &G);								//��ؼ�·��������



#endif // !_TOPOLOGICAL_H

