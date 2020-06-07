#include "stdafx.h"
#include "HuffmanTree.h"

int main()
{
	HuffmanTree HT;											//哈夫曼树
	HuffmanCode HC;											//哈夫曼树编码
	int w[] = { 1, 19, 47, 5};			//权值数组，随意添加结点（元素）

	HuffmanCoding(&HT, &HC, w, sizeof(w)/sizeof(w[0]));
	return 0;
}
