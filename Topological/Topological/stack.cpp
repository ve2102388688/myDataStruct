#include "stdafx.h"
#include "stack.h"

//构造一个空栈操作
Status InitStack(SqStack &s)
{
	s.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s.base)
		return OVERFLOW;
	memset(s.base, 0, STACK_INIT_SIZE * sizeof(SElemType));					//初始化每个都弄为0
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return OK;
}


//栈的插入操作 Push
Status Push(SqStack &s, SElemType e)
{
	if ((s.top - s.base) >= s.stacksize)
	{
		s.base = (SElemType *)realloc(s.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType));
		if (!s.base)
			return OVERFLOW;
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*s.top++ = e;
	return OK;
}


//取栈顶元素 Pop
SElemType Pop(SqStack &s)
{
	if (s.base == s.top)
		return ERROR;
	return *--s.top;
}


//获取栈顶元素
SElemType GetTop(SqStack &s)
{
	if (s.base == s.top)
		return ERROR;
	return *(s.top - 1);
}


//获取栈当前元素个数
SElemType StackLength(SqStack &s)
{
	return (s.top - s.base) / sizeof(SElemType);
}


//判栈空
Status StackEmpty(SqStack &s)
{
	if (s.base == s.top)
		return 1;
	return 0;
}