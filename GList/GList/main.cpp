#include "stdafx.h"
#include "GList.h"
#include "myString.h"																//自己写的常见字符串操作

int main()
{
	//GList L;																		//原表
	//GList LCpoy;																	//复制表LCpoy
	//HString StringCh;																
	//const char *string = "((A),((B),C),D)";											//输入的字符串（英文条件下输入的），这里要转化成HString，因为之后设计字符串操作
	//StrAssign(StringCh, string);													//char * 转化成 HString
	//CreatGList(L, StringCh);														//创建广义表

	//printf("广义表L深度：%d\n", GListDepth(L));										//求广义表的深度
	//printf("输出广义表L：\n");
	//PrintGList(L);																	//输出广义表

	//CopyGList(LCpoy, L);
	//printf("\n\n广义表LCpoy深度：%d\n", GListDepth(LCpoy));							//求广义表的深度
	//printf("输出广义表LCpoy：\n");
	//PrintGList(LCpoy);																//输出广义表


	/***************************************************
	**			串（6个基本函数）测试
	****************************************************/
	const char *ceshi = "ZhongGuoMeng";
	const char *ceshi1 = "WoDeMeng";
	HString S;
	HString S1;
	HString newStringConcat;
	HString Sub;
	
	StrAssign(S, ceshi);
	printf("串1：\n");
	PrintString(S);

	//求字串
	printf("串1长度：%d\n", strLength(S));
	SubString(Sub, S, 6, 3);
	printf("字串[SubString(Sub, S, 6, 3)]：\n");
	PrintString(Sub);

	StrAssign(S1, ceshi1);
	printf("串2：\n");
	PrintString(S1);
	Concat(newStringConcat, S, S1);
	printf("连接串：\n");
	PrintString(newStringConcat);

	printf("比较串：\n");
	printf("%d\n", StrCompare(S, S1)); 


	ClearString(S);
	printf("是否为空：%d\n", StrEmpty(S));
	printf("复制串(S1-->S)：\n");
	StrCopy(S, S1);
	PrintString(S);
	return 0;
}

