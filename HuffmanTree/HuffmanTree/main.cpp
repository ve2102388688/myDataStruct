#include "stdafx.h"
#include "HuffmanTree.h"

int main()
{
	HuffmanTree HT;											//��������
	HuffmanCode HC;											//������������
	int w[] = { 1, 19, 47, 5};			//Ȩֵ���飬������ӽ�㣨Ԫ�أ�

	HuffmanCoding(&HT, &HC, w, sizeof(w)/sizeof(w[0]));
	return 0;
}
