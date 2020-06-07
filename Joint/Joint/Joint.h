#ifndef _JOINT_H
#define _JOINT_H
#pragma warning(disable:4996)


#define MAX_VERTEX_NUM  20
typedef char VertexType;

//һ������ĵ�����
typedef struct ArxNode {
	int			    adjvex;					//����λ��
	struct ArxNode *nextarc;				//�û�����һ��
}ArxNode;

//��������
typedef struct VNode {
	VertexType  data;						//�����ŵ����ݣ�������char--A B C��������
	ArxNode		*firstarc;					//ָ���һ������ָ��
	int			 locationOfData;			//��data����λ�ü�����������֪��λ����data
}VNode, AdjList[MAX_VERTEX_NUM];

//ALGraph��������Ϣ
typedef struct {
	AdjList vertices;
	int		vexnum, arcnum;					//���Ķ������ͻ���
}ALGraph;


int LocateVex(ALGraph &G, VertexType v);								//�ж��ַ���ͼ��λ��
char LocateData(ALGraph &G, int i);										//֪��λ�û�ȡ����Data

void CreatALGraph(ALGraph &G);											//��������ͼ���ڽӱ�
void PrintALGraph(ALGraph &G);											//�������ͼ���ڽӱ�

void FindArticul(ALGraph &G);											//�������Ѱ�ҹؽڵ�
void DFSArticul(ALGraph &G, int v);										

#endif // !_JOINT_H

