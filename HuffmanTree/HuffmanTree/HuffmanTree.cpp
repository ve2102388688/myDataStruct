#include "stdafx.h"
#include "HuffmanTree.h"
#include <stdlib.h>
#include "string.h"
#pragma warning(disable:4996)									//忽略strcpy函数的警告				

/*****************************************************************
**	*HT:哈夫曼树
**	s1 :最小数的位置
**	s2 :次小数的位置
**	n  :权值的个数（叶子结点）一棵n叶子结点的哈夫曼共有2n-1个结点
******************************************************************/
void select(HuffmanTree *HT, int n, int *s1, int *s2)
{
	int i = 0;
	int min;											//记录最小权值

	for (i = 1; i <= n; i++)							//遍历全部结点，找出单节点
	{
		if (0 == (*HT)[i].parent)						//如果此结点的父亲没有，那么把结点号赋值给min，跳出循环
		{
			min = i;
			break;
		}
	}
	for (i = 1; i <= n; i++)							//继续遍历全部结点，找出权值最小的单节点
	{
		if (0 == (*HT)[i].parent)						//如果此结点的父亲为空，则进入 if
		{
			if ((*HT)[i].weight < (*HT)[min].weight)	//如果此结点的权值比 min 结点的权值小，那么更新 min 结点，否则就是最开始的 min
			{
				min = i;
			}
		}
	}
	*s1 = min;											//s1指向最小权值的结点

	
	for (i = 1; i <= n; i++)							//遍历全部结点
	{
		if ((*HT)[i].parent == 0 && i != (*s1))			//找出下一个单节点，且没有被 s1指向，那么i 赋值给 min，跳出循环
		{
			min = i;
			break;
		}
	}
	for (i = 1; i <= n; i++)							//继续遍历全部结点，找到权值最小的那一个
	{
		if (0 == (*HT)[i].parent && i != (*s1))
		{
			if ((*HT)[i].weight < (*HT)[min].weight)	//如果此结点的权值比 min 结点的权值小，那么更新 min 结点，否则就是最开始的min
			{
				min = i;
			}
		}
	}
	*s2 = min;											//s2指向次小权值的叶子结点
}

/*****************************************************************
**	*HT:哈夫曼树
**	*HC:哈夫曼编码二维字符数组
**	*w :存放权值的数组
**	n  :权值的个数（叶子结点）一棵n叶子结点的哈夫曼共有2n-1个结点
******************************************************************/
void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n)
{
	if (n < 1)
		return ;
	int m;														//哈夫曼树的总结点树
	m = 2 * n - 1;												//一棵有n个叶子结点的哈夫曼树共有2n - 1个结点

	*HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));			//0号单元没有用
	int i;
	for (i = 1; i <= n; i++)									//初始化叶子结点--n个
	{
		(*HT)[i].weight = w[i-1];
		(*HT)[i].parent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0;
	}
	for (; i <= m; i++)											//初始化度2结点（双亲节点及根结点）--(n-1)个
	{
		(*HT)[i].weight = 0;
		(*HT)[i].parent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0;
	}
	int s1, s2;
	for (i = n + 1; i <= m; i++)								//开始创建后(n-1)个结点
	{
		select(HT, i-1, &s1, &s2);								//i逐渐增加，比较对象个数增加（对于上一轮被更改的双亲的结点，找最小值就不考虑了，但是它的位置任然固定）
		(*HT)[s1].parent = i;									//在这里两个较小的结点双亲改变，所以接下来的select()就会除掉这两个点
		(*HT)[s2].parent = i;									
		(*HT)[i].lchild = s1;				
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
		printf("%d (%d %d)\n", (*HT)[i].weight, (*HT)[s1].weight, (*HT)[s2].weight);	//双亲权值 左孩子权值  右孩子权值
	}

	printf("index  weight  parent  lChild  rChild\n");			//输出每个节点的所有信息
	for (i = 1; i <= m; ++i) 
	{
		printf("%d\t", i);										//结点所在的序号
		printf("%d\t", (*HT)[i].weight);
		printf("%d\t", (*HT)[i].parent);
		printf("%d\t", (*HT)[i].lchild);
		printf("%d\n", (*HT)[i].rchild);
	}
		
	printf("\nWPL = %d\n\n", (*HT)[m].weight);					//输出WPL值，WPL值必定是最后结点的weight，且它的parent为0

	HC = (HuffmanCode *)malloc((n + 1) * sizeof(char *));		//分配编码空间
	char *temp = (char *)malloc(n * sizeof(char));				//临时储存，以备复制给HC[i]
	temp[n - 1] = '\0';											//倒序输出
	int start, c, f;
	for (i = 1; i <= n; i++)									//叶子结点需要编码
	{
		start = n - 1;
		for (c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent)	//先用c记录当前位置，f记录c的双亲的位置，不断往上同时走
		{
			if (c == (*HT)[f].lchild)							//左边编码为0
				temp[--start] = '0';
			else												//右边编码为1
				temp[--start] = '1';	
		}
		HC[i] = (char *)malloc((n-start)* sizeof(char));		//动态分配HC[i],由于每个结点编码长度不一致，start值每次循环都不一样（编码一个0或1，start减一）
		strcpy(HC[i], &temp[start]);							//单个叶子节点编码拷贝
	}
	free(temp);													//释放临时的temp空间
	
	for (i = 1; i <= n; i++)
	{
		printf("HuffmanCode of\t %3d is %s\n", (*HT)[i].weight, HC[i]);		//输出各结点的编码
	}
}

