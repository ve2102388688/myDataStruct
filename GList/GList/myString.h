#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <stdlib.h>


#define ERROR		 0
#define OK			 1
#define TRUE		 2
#define OVERFLOW	-2

typedef int Status;

/******************************************************
**		���Ĵ洢����
**1��ѭ��洢
		����˳���ʾ--------�漰���ضϡ�,�ܴ�ı׶�
		�ѷ��䣨��̬���䣩--�����ص�
 **2����ʽ�洢
******************************************************/
typedef struct {
	char *firstAddress;
	int length;
}HString;


Status StrAssign(HString &T, const char *chars);					//��������ֵ��������T
int strLength(HString S);											//�󴮵ĳ���
int StrCompare(HString S, HString T);								//�Ƚϴ�С�����ֵ�˳��
Status Concat(HString &T, HString &S1, HString &S2);				//�����ַ������´�T = S1 + S2��
Status SubString(HString &Sub, HString S, int pos, int len);		//���ִ�
Status StrEmpty(HString S);											//�д���
void StrCopy(HString &S, HString &T);								//���ĸ���

Status ClearString(HString &S);										//��մ������ͷ��ڴ�
void PrintString(HString &S);										//�����

#endif // !_MYSTRING_H

