#include "stdafx.h"
#include "myString.h"

//将常量赋值给变量串T
Status StrAssign(HString &T, const char *chars)
{
	//if (T.firstAddress)
	//	free(T.firstAddress);
	int len;
	const char *c;
	for (len = 0, c = chars; *c; len++, ++c);										//计算chars的长度
	if (!len)																		//长度为0，不需要创建串
		T.firstAddress = NULL;
	else
	{
		if (!(T.firstAddress = (char *)malloc(len * sizeof(char))))
			return OVERFLOW;
		for (int i = 0; i < len; i++)
		{
			T.firstAddress[i] = chars[i];											//一个一个赋值
		}
		T.length = len;																//记录长度
	}
	return OK;
}


//求串的长度
int strLength(HString S)
{
	return S.length;																//返回串长度
}


/**************************************************
**				比较大小（按字典顺序）
**	S > T 返回 >0
	S = T 返回 =0
	S < T 返回 <0
**************************************************/
int StrCompare(HString S, HString T) 
{
	for (int i = 0; i < S.length && i < T.length; i++)
		if (S.firstAddress[i] != T.firstAddress[i])									//比字母大小
			return S.firstAddress[i] - T.firstAddress[i];
	return S.length - T.length;														//字母大小相同，比长度
}


//连接字符串（新串T = S1 + S2）
Status Concat(HString &T, HString &S1, HString &S2)
{
	//if (T.firstAddress)
	//	free(T.firstAddress);
	if (!(T.firstAddress = (char *)malloc((S1.length + S2.length) * sizeof(char))))
		return OVERFLOW;
	for (int i = 0; i < S1.length; i++)												//先复制S1
		T.firstAddress[i] = S1.firstAddress[i];
	for (int i = 0; i < S2.length; i++)
		T.firstAddress[S1.length + i] = S2.firstAddress[i];							//之后复制S2，记得起始地址增加了！
	T.length = S1.length + S2.length;												//记录新的串长度
	return OK;
}


//求字串
Status SubString(HString &Sub, HString S, int pos, int len)
{
	if (pos < 1 || len > S.length || len < 0 || len > S.length - pos + 1)			//剔除不正确的输入值
		return ERROR;
	//if (Sub.firstAddress)
	//	free(Sub.firstAddress);
	if (!len)																		//长度为0，返回NULL
	{ 
		Sub.firstAddress = NULL;
		Sub.length = 0;
	}else
	{
		if (!(Sub.firstAddress = (char *)malloc(len * sizeof(char))))
			return OVERFLOW;
		for (int i = 0; i < len; i++)												//提取子串，从pos起到pos - 1 + i（记得减1）
			Sub.firstAddress[i] = S.firstAddress[pos - 1 + i];
;		Sub.length = len;															//记录子串长度
	}
	return OK;
}


//判串空
Status StrEmpty(HString S)
{
	if (S.firstAddress)
		return 0;
	return 1;
}


//串的复制
void StrCopy(HString &S, HString &T)
{
	S.firstAddress = T.firstAddress;												//复制首地址
	S.length = T.length;															//复制长度
}

//清空串，并释放内存(看实际情况是否释放空间)
Status ClearString(HString &S)									
{
	if (S.firstAddress)
	{
		//free(S.firstAddress);														//并释放内存
		S.firstAddress = NULL;														//清空串
	}
	S.length = 0;																	//长度请0
	return OK;
}


//输出串
void PrintString(HString &S)
{
	for (int i = 0; i < S.length; i++)
		printf("%c",S.firstAddress[i]);	
	printf("\n");
}
