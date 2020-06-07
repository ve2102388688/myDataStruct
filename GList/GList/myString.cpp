#include "stdafx.h"
#include "myString.h"

//��������ֵ��������T
Status StrAssign(HString &T, const char *chars)
{
	//if (T.firstAddress)
	//	free(T.firstAddress);
	int len;
	const char *c;
	for (len = 0, c = chars; *c; len++, ++c);										//����chars�ĳ���
	if (!len)																		//����Ϊ0������Ҫ������
		T.firstAddress = NULL;
	else
	{
		if (!(T.firstAddress = (char *)malloc(len * sizeof(char))))
			return OVERFLOW;
		for (int i = 0; i < len; i++)
		{
			T.firstAddress[i] = chars[i];											//һ��һ����ֵ
		}
		T.length = len;																//��¼����
	}
	return OK;
}


//�󴮵ĳ���
int strLength(HString S)
{
	return S.length;																//���ش�����
}


/**************************************************
**				�Ƚϴ�С�����ֵ�˳��
**	S > T ���� >0
	S = T ���� =0
	S < T ���� <0
**************************************************/
int StrCompare(HString S, HString T) 
{
	for (int i = 0; i < S.length && i < T.length; i++)
		if (S.firstAddress[i] != T.firstAddress[i])									//����ĸ��С
			return S.firstAddress[i] - T.firstAddress[i];
	return S.length - T.length;														//��ĸ��С��ͬ���ȳ���
}


//�����ַ������´�T = S1 + S2��
Status Concat(HString &T, HString &S1, HString &S2)
{
	//if (T.firstAddress)
	//	free(T.firstAddress);
	if (!(T.firstAddress = (char *)malloc((S1.length + S2.length) * sizeof(char))))
		return OVERFLOW;
	for (int i = 0; i < S1.length; i++)												//�ȸ���S1
		T.firstAddress[i] = S1.firstAddress[i];
	for (int i = 0; i < S2.length; i++)
		T.firstAddress[S1.length + i] = S2.firstAddress[i];							//֮����S2���ǵ���ʼ��ַ�����ˣ�
	T.length = S1.length + S2.length;												//��¼�µĴ�����
	return OK;
}


//���ִ�
Status SubString(HString &Sub, HString S, int pos, int len)
{
	if (pos < 1 || len > S.length || len < 0 || len > S.length - pos + 1)			//�޳�����ȷ������ֵ
		return ERROR;
	//if (Sub.firstAddress)
	//	free(Sub.firstAddress);
	if (!len)																		//����Ϊ0������NULL
	{ 
		Sub.firstAddress = NULL;
		Sub.length = 0;
	}else
	{
		if (!(Sub.firstAddress = (char *)malloc(len * sizeof(char))))
			return OVERFLOW;
		for (int i = 0; i < len; i++)												//��ȡ�Ӵ�����pos��pos - 1 + i���ǵü�1��
			Sub.firstAddress[i] = S.firstAddress[pos - 1 + i];
;		Sub.length = len;															//��¼�Ӵ�����
	}
	return OK;
}


//�д���
Status StrEmpty(HString S)
{
	if (S.firstAddress)
		return 0;
	return 1;
}


//���ĸ���
void StrCopy(HString &S, HString &T)
{
	S.firstAddress = T.firstAddress;												//�����׵�ַ
	S.length = T.length;															//���Ƴ���
}

//��մ������ͷ��ڴ�(��ʵ������Ƿ��ͷſռ�)
Status ClearString(HString &S)									
{
	if (S.firstAddress)
	{
		//free(S.firstAddress);														//���ͷ��ڴ�
		S.firstAddress = NULL;														//��մ�
	}
	S.length = 0;																	//������0
	return OK;
}


//�����
void PrintString(HString &S)
{
	for (int i = 0; i < S.length; i++)
		printf("%c",S.firstAddress[i]);	
	printf("\n");
}
