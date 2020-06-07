#ifndef _QUEUE_H
#define	_QUEUE_H


#define ERROR		-1
#define OK			 2
#define TRUE		 1
#define OVERFLOW	-2

typedef int Status;
typedef char QElemType;

//���е����ݽṹ
typedef struct QNode {
	QElemType	   data;
	struct QNode  *next;
}QNode, *QueuePtr;


typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);					//��ʼ������
Status DestroyQueue(LinkQueue &Q);				//���ٶ���
Status EnQueue(LinkQueue &Q, QElemType e);		//��β���
QElemType DeQueue(LinkQueue &Q, QElemType &e);		//��ͷ����
Status QueueEmpty(LinkQueue &Q);				//�ж϶ӿ�
QElemType GetHead(LinkQueue &Q);
void PrintQueue(LinkQueue Q);					//��ӡ����



#endif // !_QUEUE_H

