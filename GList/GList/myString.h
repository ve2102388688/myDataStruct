#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <stdlib.h>


#define ERROR		 0
#define OK			 1
#define TRUE		 2
#define OVERFLOW	-2

typedef int Status;

/******************************************************
**		串的存储机构
**1：循序存储
		定长顺序表示--------涉及“截断”,很大的弊端
		堆分配（动态分配）--本次重点
 **2：链式存储
******************************************************/
typedef struct {
	char *firstAddress;
	int length;
}HString;


Status StrAssign(HString &T, const char *chars);					//将常量赋值给变量串T
int strLength(HString S);											//求串的长度
int StrCompare(HString S, HString T);								//比较大小（按字典顺序）
Status Concat(HString &T, HString &S1, HString &S2);				//连接字符串（新串T = S1 + S2）
Status SubString(HString &Sub, HString S, int pos, int len);		//求字串
Status StrEmpty(HString S);											//判串空
void StrCopy(HString &S, HString &T);								//串的复制

Status ClearString(HString &S);										//清空串，并释放内存
void PrintString(HString &S);										//输出串

#endif // !_MYSTRING_H

