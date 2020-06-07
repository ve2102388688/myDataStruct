#ifndef _GRAPH_H
#define _GRAPH_H

#include <string>
//using namespace std;
//ʮ��������ṹ
#define MAX_VERTEX_NUM 20						//������Ŀ���20�����������������

//����� 
typedef struct ArcBox
{
	int				tailvex, headvex;			//����β��ͷλ��
	struct ArcBox	*hlink, *tlink;				//��ͷ��ͬ�����򣬻�β��ͬ������
}ArcBox;

//������  
typedef struct 
{
	int nodenum;								//Ϊ������ȱ�����ȡ�����������λ��
	char	data;								//��������
	ArcBox	*firstin, *firstout;				//�ֱ�ָ��ö���ĵ�һ���뻡�ͳ���
}VexNode;

typedef struct {
	VexNode xlist[MAX_VERTEX_NUM];				//��ͷ����
	int		vexnum, arcnum;						//����ͼ�Ķ������뻡��
}OLGraph;

int CreatDG(OLGraph &G, int vexnum, int arcnum);
int LocateVex(OLGraph &G, char v);


void DFSTraverse(OLGraph &G);
void DFS(OLGraph &G, int v);

void BFSTraverse(OLGraph &G);
#endif
