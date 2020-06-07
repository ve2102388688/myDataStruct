#ifndef _STACK_H
#define _STACK_H
#include <stdlib.h>

#define STACK_INIT_SIZE 8											//储存空间初始量
#define STACKINCREMENT  5											//储存空间分配增量

#define ERROR		0
#define OK			 1
#define TRUE		 2
#define OVERFLOW	-2

typedef int Status;
typedef char SElemType;

typedef struct 
{
	SElemType *base;												//栈底
	SElemType *top;													//栈顶
	int		   stacksize;											//每次的新元素个数
}SqStack;

Status InitStack(SqStack &s);										//构造一个空栈操作				
Status Push(SqStack &s, SElemType e);								//栈的插入操作 Push
SElemType Pop(SqStack &s);											//取栈顶元素 Pop
SElemType GetTop(SqStack &s);										//获取栈顶元素
SElemType StackLength(SqStack &s);									//获取栈当前元素个数
Status StackEmpty(SqStack &s);
#endif // !_STACK_H

