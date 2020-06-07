#ifndef _GLIST_H
#define _GLIST_H
#include <stdlib.h>
#include "myString.h"

/***************************************************
**					存储结构
** 1：广义表的头尾链表表示-----以此为存储解构
** 2：广义表的扩展线性链表表示
***************************************************/
typedef char AtomType;

typedef enum{														//标志位，原子（0）与表（1）
	ATOM, LIST
}ElemTag;


//广义表的头尾链存储
typedef struct GNode {
	ElemTag tag;
	union {
		AtomType data;												//数据（char）
		struct { struct GNode *hp, *tp; }ptr;						//ptr表结点指针域，hp：表头，tp:表尾
	};
}*GList;

int CreatGList(GList &L, HString &ch);									//创建广义表
void sever(HString &str, HString &hstr);								//将str分割成两部分，hstr是','之前的，str是','之后的

int GListDepth(GList &L);												//求广义表深度
int CopyGList(GList &T, GList L);										//复制广义表
void PrintGList(GList &L);												//输出广义表



#endif // !_GLIST_H

