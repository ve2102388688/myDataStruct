#include "stdafx.h"
#include "queue.h"
#include <stdlib.h>

Status InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		return OVERFLOW;
	Q.front->next = NULL;
	return OK;
}


Status DestroyQueue(LinkQueue &Q)
{
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}


Status EnQueue(LinkQueue &Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return OVERFLOW;
	p->data = e;		p->next = NULL;
	Q.rear->next = p;	Q.rear = p;
	return OK;
}


QElemType DeQueue(LinkQueue &Q, QElemType &e)
{
	if (Q.front == Q.rear)
		return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return e;
}


Status  QueueEmpty(LinkQueue &Q)
{
	if (Q.front == Q.rear)
		return 1;
	return 0;
}


QElemType GetHead(LinkQueue &Q)
{
	if (Q.front->next == NULL)
		return 0;
	return Q.front->next->data;
}



 //打印队列元素
void PrintQueue(LinkQueue Q)
{
	if(Q.front != Q.rear){
		do{
			Q.front = Q.front->next;
			printf("%d ",Q.front->data);
		}while(Q.front->next);
	}
	printf("\n");
}

