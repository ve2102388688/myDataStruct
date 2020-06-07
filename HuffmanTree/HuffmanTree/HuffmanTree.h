#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

typedef struct 
{
	int weight;										 //Ȩֵ
	unsigned int parent, lchild, rchild;			 //˫�׼����Һ��ӵ��±� 
}HTNode, *HuffmanTree;

typedef char *HuffmanCode;							 //����������

void select(HuffmanTree *HT, int n, int *s1, int *s2);
void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n);
#endif
