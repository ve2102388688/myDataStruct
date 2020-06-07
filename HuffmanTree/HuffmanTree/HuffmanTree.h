#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

typedef struct 
{
	int weight;										 //权值
	unsigned int parent, lchild, rchild;			 //双亲及左右孩子的下标 
}HTNode, *HuffmanTree;

typedef char *HuffmanCode;							 //哈夫曼编码

void select(HuffmanTree *HT, int n, int *s1, int *s2);
void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n);
#endif
