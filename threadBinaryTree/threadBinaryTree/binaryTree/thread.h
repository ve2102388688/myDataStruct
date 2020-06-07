#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include <stdio.h>

//Ϊ�˷��㣬����û�д����ڴ����ʧ���쳣��OVERFLOW��
#define OK			 1
#define ERROR		 0	
#define OVERFLOW	-1

#define TElemType char
#define Status	  int
 

/********************************************************
Funtion:
	�����������ṹ�壨Threaded Binary Tree��
LTag:
	0 : lchild ��ָʾ�������� 
	1 : lchild ��ָʾ����ǰ�� 
RTag:
	0 : rchild ��ָʾ�����Һ��� 
	1 : rchild ��ָʾ���ĺ��
ע��:
	���ں����������������������ԣ�Ҫʹ�ô�˫�׵���������
	ԭ����ο����ݽṹC����P133�ĵ�һҳ������
*********************************************************/
typedef enum {
	Link, Thread
}PointerTag;//Link == 0 :ָ��, Thread == 1: ����  

typedef struct BiThrNode {
	TElemType		  data;
	struct BiThrNode *rchild, *lchild, *Parent;	//���Һ���ָ�룬(**Parent�������������õġ��������򲻿���*Parent)
	PointerTag		  LTag, RTag;				//���ұ�ʶ
}BiThrNode, *BiThrTree;

//���ʽ��data
Status visit(TElemType e);

//���������������򣬺���
Status CreatPreBiThreadTree(BiThrTree &T, char TreeArray[]);
Status CreatInBiThreadTree(BiThrTree &T, char TreeArray[]);
Status CreatPostBiThreadTree(BiThrTree &T, char TreeArray[], BiThrTree &parent);

//(ǰ���У���)��������
void PreThreading(BiThrTree p);
void InThreading(BiThrTree p);
void PostThreading(BiThrTree p);

//���µ��������������Ǹ����������һ��ͷ��㣬ͬʱҲ������������Ȼ����Ҳ�ǿ��Եģ�
Status PreOrderThreading(BiThrTree &Thrt, BiThrTree T);
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T);

/********************************************************************
**	����������������ͷ��㣬�����Ǳ����ܼ򵥣�ֻ��Ҫת�����ͽ�����
********************************************************************/
Status PreOrderTraverse(BiThrTree HeadNode, Status (*visit)(TElemType e));
Status InOrderTraverse(BiThrTree HeadNode, Status(*visit)(TElemType e));
Status PostOrderTraverse(BiThrTree HeadNode, Status(*visit)(TElemType e));


#endif