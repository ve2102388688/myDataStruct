#ifndef _STACK_H
#define _STACK_H
#include <stdlib.h>

#define STACK_INIT_SIZE 8											//����ռ��ʼ��
#define STACKINCREMENT  5											//����ռ��������

#define ERROR		0
#define OK			 1
#define TRUE		 2
#define OVERFLOW	-2

typedef int Status;
typedef char SElemType;

typedef struct 
{
	SElemType *base;												//ջ��
	SElemType *top;													//ջ��
	int		   stacksize;											//ÿ�ε���Ԫ�ظ���
}SqStack;

Status InitStack(SqStack &s);										//����һ����ջ����				
Status Push(SqStack &s, SElemType e);								//ջ�Ĳ������ Push
SElemType Pop(SqStack &s);											//ȡջ��Ԫ�� Pop
SElemType GetTop(SqStack &s);										//��ȡջ��Ԫ��
SElemType StackLength(SqStack &s);									//��ȡջ��ǰԪ�ظ���
Status StackEmpty(SqStack &s);
#endif // !_STACK_H

