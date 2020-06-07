#ifndef _GLIST_H
#define _GLIST_H
#include <stdlib.h>
#include "myString.h"

/***************************************************
**					�洢�ṹ
** 1��������ͷβ�����ʾ-----�Դ�Ϊ�洢�⹹
** 2����������չ���������ʾ
***************************************************/
typedef char AtomType;

typedef enum{														//��־λ��ԭ�ӣ�0�����1��
	ATOM, LIST
}ElemTag;


//������ͷβ���洢
typedef struct GNode {
	ElemTag tag;
	union {
		AtomType data;												//���ݣ�char��
		struct { struct GNode *hp, *tp; }ptr;						//ptr����ָ����hp����ͷ��tp:��β
	};
}*GList;

int CreatGList(GList &L, HString &ch);									//���������
void sever(HString &str, HString &hstr);								//��str�ָ�������֣�hstr��','֮ǰ�ģ�str��','֮���

int GListDepth(GList &L);												//���������
int CopyGList(GList &T, GList L);										//���ƹ����
void PrintGList(GList &L);												//��������



#endif // !_GLIST_H

