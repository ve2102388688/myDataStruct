#include "stdafx.h"
#include "GList.h"
#include "myString.h"																//�Լ�д�ĳ����ַ�������

int main()
{
	//GList L;																		//ԭ��
	//GList LCpoy;																	//���Ʊ�LCpoy
	//HString StringCh;																
	//const char *string = "((A),((B),C),D)";											//������ַ�����Ӣ������������ģ�������Ҫת����HString����Ϊ֮������ַ�������
	//StrAssign(StringCh, string);													//char * ת���� HString
	//CreatGList(L, StringCh);														//���������

	//printf("�����L��ȣ�%d\n", GListDepth(L));										//����������
	//printf("��������L��\n");
	//PrintGList(L);																	//��������

	//CopyGList(LCpoy, L);
	//printf("\n\n�����LCpoy��ȣ�%d\n", GListDepth(LCpoy));							//����������
	//printf("��������LCpoy��\n");
	//PrintGList(LCpoy);																//��������


	/***************************************************
	**			����6����������������
	****************************************************/
	const char *ceshi = "ZhongGuoMeng";
	const char *ceshi1 = "WoDeMeng";
	HString S;
	HString S1;
	HString newStringConcat;
	HString Sub;
	
	StrAssign(S, ceshi);
	printf("��1��\n");
	PrintString(S);

	//���ִ�
	printf("��1���ȣ�%d\n", strLength(S));
	SubString(Sub, S, 6, 3);
	printf("�ִ�[SubString(Sub, S, 6, 3)]��\n");
	PrintString(Sub);

	StrAssign(S1, ceshi1);
	printf("��2��\n");
	PrintString(S1);
	Concat(newStringConcat, S, S1);
	printf("���Ӵ���\n");
	PrintString(newStringConcat);

	printf("�Ƚϴ���\n");
	printf("%d\n", StrCompare(S, S1)); 


	ClearString(S);
	printf("�Ƿ�Ϊ�գ�%d\n", StrEmpty(S));
	printf("���ƴ�(S1-->S)��\n");
	StrCopy(S, S1);
	PrintString(S);
	return 0;
}

