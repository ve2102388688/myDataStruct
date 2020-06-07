#ifndef _PRIM_H
#define _PRIM_H
#pragma warning(disable:4996)

#define INT_MAX		   65535										//���ֵ65535����ʾ������û����ϵ
#define MAX_VERTEX_NUM 20											//��ඥ����

typedef char VertexType;
typedef int  EdgeType;

//����ͼ, ������, ����ͼ, ������
enum GraphKind {
	DG, DN, UDG, UDN
};

//������Ϣ
typedef struct ArcCell {
	EdgeType wight;

}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];				//��ά����  

//������Ϣ
typedef struct MGraph {
	VertexType vexs[MAX_VERTEX_NUM];								//��������  
	AdjMatrix  arcs;												//�ڽӾ���  
	int vexnum, arcnum;												//ͼ�ĵ�ǰ�������ͻ���  
	GraphKind   kind;												//ͼ�������־  
}MGraph;


//Prim�㷨�еĸ�����Ϣ
struct prim{
	VertexType adjvex;												//������·���ĳ����ڵ���
	EdgeType   lowcost;												//���·��
};


int LocateVex(MGraph &G, VertexType v);								//�ж��ַ���ͼ��λ��
void CreatMGraph(MGraph &G);										//��������ͼ���ڽӾ���  
void printMatrixGraph(MGraph &G);									//����ڽӾ���
int MiniSpanTree_Prim(MGraph &G, VertexType u);						//����ķ�㷨
int minArc(MGraph &G, struct prim *closedge);						//Ѱ����С��


#endif // !_PRIM_H
