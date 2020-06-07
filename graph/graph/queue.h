#ifndef _QUEUE_H
#define	_QUEUE_H


#define ERROR		-1
#define OK			 2
#define TRUE		 1
#define OVERFLOW	-2

typedef int Status;
typedef char QElemType;

//队列的数据结构
typedef struct QNode {
	QElemType	   data;
	struct QNode  *next;
}QNode, *QueuePtr;


typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);					//初始化队列
Status DestroyQueue(LinkQueue &Q);				//销毁队列
Status EnQueue(LinkQueue &Q, QElemType e);		//队尾入队
QElemType DeQueue(LinkQueue &Q, QElemType &e);		//对头出队
Status QueueEmpty(LinkQueue &Q);				//判断队空
QElemType GetHead(LinkQueue &Q);
void PrintQueue(LinkQueue Q);					//打印队列



#endif // !_QUEUE_H

