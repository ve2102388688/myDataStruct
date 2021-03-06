#include "stdafx.h"
#include "GList.h"

/******************************************************************************
**								 创建广义表
**	p	：p是最新的，需要不断的malloc
	q	：q是之前的p,用于创建之前还未建的侧枝
	sub ：‘,’后字符串
	hsub：‘,’前字符串
** 简单的分析下思路（这个不好理解，学完树，图还好点.....）
	1：首先明白，这个是多层递归，变量是放在函数体内 or 外？
	2：这里递归是递归的’头（p->ptr.hp）‘，用啥数据建呢？答：hsub：‘,’前字符串
	3：这里需要的东西
	   建立单个原子及'()'--它分解的最小单位是原子与'()'，那么建立原子后，返回上层递归点，必建立'()'--即不会进while（这是由于截断里的ClearString(str)已经清空了sub）
	   建立侧枝，想想？？我们已经建好了最底层的原子与'()'--相当于葡萄，正如一串葡萄，有好多分支的，这里我称为侧枝，必须要每个侧枝啊，那就是q啊，p新建一大堆东西连上q即可

*******************************************************************************/
int CreatGList(GList &L, HString &StringCh)
{
	GList p;																					//p是最新的，需要不断的malloc
	GList q;																					//q是之前的p,用于创建之前还未建的侧枝
	HString sub;																				//‘,’后字符串
	HString hsub;																				//‘,’前字符串

	const char *emp = "()";																		//提前预设空串
	HString temp;
	StrAssign(temp, emp);

	if (!StrCompare(StringCh, temp))															//若空串，则空表
		L = NULL;
	else{
		if (!(L = (GList)malloc(sizeof(GNode))))
			return OVERFLOW;
		if (strLength(StringCh) == 1) {
			L->tag = ATOM;
			L->data = StringCh.firstAddress[0];													//如果是原子，取StringCh[0]即可
		}else {
			L->tag = LIST;		p = L;															//不是原子，当然是表
			SubString(sub, StringCh, 2, strLength(StringCh) - 2);								//退去外层括弧
			do {
				sever(sub, hsub);																//截取‘，’前面的，也就是α1，α2···
				CreatGList(p->ptr.hp, hsub);													//创建广义表某个元素的表（就好像葡萄树上的一串葡萄），”ptr.hp“
				q = p;																			//p是下一个，q是上一个
				if (!StrEmpty(sub)) {
					if (!(p = (GList)malloc(sizeof(GNode))))
						return OVERFLOW;
					p->tag = LIST;		q->ptr.tp = p;											//相当于一条侧枝，侧枝从哪儿开始呢？从q开始啊，递归调用批永远是最新的，q就是过去的p
				}
			} while (!StrEmpty(sub));
			q->ptr.tp = NULL;																	//不存在侧枝，侧枝为空
		}
	}
}


/***************************************************************************************
**		功能：截取‘,’前面的，也就是α1，α2···
**i：指向现在获取的ch的位置，一但发现完整的‘,’如'((B),C)，'就出while，截取两段
**k：是左右括号匹配问题，左括号加1，右括号减1。
	 比如'((B),C)'k遇左括号自增两次，遇左括号自两次，结果为0，出while
****************************************************************************************/
void sever(HString &str, HString &hstr)
{
	int n = strLength(str);															//获取str的长度
	int i = 0, k = 0;																//k是匹配左右括号数，左括号加1，右括号减1。i可以说是记录这次应该判断哪个字符了（位置）
	HString ch;
	do {
		++i;																		//ch的位置
		SubString(ch, str, i, 1);													//取一个字符分析
		if (ch.firstAddress[0] == '(')												//左括号加1
			++k;
		else if (ch.firstAddress[0] == ')')											//右括号减1
			--k;
	} while (i < n && (ch.firstAddress[0] != ',' || k != 0));						//遇到','或者k为0。退出循环（当然最好的情况只有一个α1，一把到i=n）
	if (i < n)																		//i < n:需要截断
	{
		SubString(hstr, str, 1, i - 1);												//hstr是α1，α2···中的α1
		SubString(str, str, i + 1, n - i);											//把‘,’后字符串给str
	}else{																			//传进来只可能是单字母
		StrCopy(hstr, str);															//单原子（如A）
		ClearString(str);															//清空str,也就是sub，这样递归回去，就不会进入创建子表if里了
	}
}


//求广义表深度
int GListDepth(GList &L)
{
	if (!L)																			//空表深度为1
		return 1;
	if (L->tag == ATOM)																//原子深度为0
		return 0;

	GNode *pp;
	int depth;
	int max = 0;
	for (max = 0, pp = L; pp; pp = pp->ptr.tp)										//横着走
	{
		depth = GListDepth(pp->ptr.hp);												//（竖着走）其中一项的深度
		if (depth > max)	
			max = depth;															//不断更新更深的
	}
	return max + 1;																	//最深的加1
}


//复制广义表
int CopyGList(GList &T, GList L)
{
	if (!L)																			//L为空，T复制为空
		T = NULL;
	else
	{
		if (!(T = (GList)malloc(sizeof(GNode))))
			return OVERFLOW;
		T->tag = L->tag;															//复制标志位
		if (T->tag == ATOM)
			T->data = L->data;														//复制data
		else
		{
			CopyGList(T->ptr.hp, L->ptr.hp);										//复制L的头					
			CopyGList(T->ptr.tp, L->ptr.tp);										//复制L的尾		
		} 
	}
}


/***************************************************************************************
**								输出广义表	
**	输出（成对的）：  原子  +  '()'--NULL
**	这也是一个递归调用
	1：输出原子--不分析了
	2：输出NULL
	   本身是LIST,自己的下一个是ATOM,必是与之原子配对的NULL
****************************************************************************************/
void PrintGList(GList &L) 
{
	GNode *p;
	for (p = L; p; p = p->ptr.tp)													//横着走
	{
		if(p->tag == ATOM)
		{
			printf("%c\t", p->data);												//输出原子
			break;
		}
		if(p->ptr.hp->tag == ATOM && p->tag == LIST)								//输出与原子配对的'()'
			printf("Null\t");

		PrintGList(p->ptr.hp);														//竖着走
	}
}