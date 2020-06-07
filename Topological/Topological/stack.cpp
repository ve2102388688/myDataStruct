#include "stdafx.h"
#include "stack.h"

//����һ����ջ����
Status InitStack(SqStack &s)
{
	s.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s.base)
		return OVERFLOW;
	memset(s.base, 0, STACK_INIT_SIZE * sizeof(SElemType));					//��ʼ��ÿ����ŪΪ0
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return OK;
}


//ջ�Ĳ������ Push
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


//ȡջ��Ԫ�� Pop
SElemType Pop(SqStack &s)
{
	if (s.base == s.top)
		return ERROR;
	return *--s.top;
}


//��ȡջ��Ԫ��
SElemType GetTop(SqStack &s)
{
	if (s.base == s.top)
		return ERROR;
	return *(s.top - 1);
}


//��ȡջ��ǰԪ�ظ���
SElemType StackLength(SqStack &s)
{
	return (s.top - s.base) / sizeof(SElemType);
}


//��ջ��
Status StackEmpty(SqStack &s)
{
	if (s.base == s.top)
		return 1;
	return 0;
}