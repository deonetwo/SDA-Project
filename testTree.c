#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "BTree.h"
#include "Huffman.h"

int main(){
	int ArrayLength = 26;
	int jumlah = 0, i = 0;
	float Min;
	addressT T[ArrayLength];
	BinTree Tree;
	
	initiateTable(T, ArrayLength);
	initiateTree(&Tree);
	T[0] = AlokasiT('a', 33);
	T[1] = AlokasiT('b', 33);
	T[2] = AlokasiT('c', 33);
	printf("Tabel awal sebelum operasi huffman dijalankan\n");
	printArray(T);
	printf("\n\n");
	executeHuffman(T, &Tree);
	printf("Tabel akhir setelah operasi huffman dijalankan\n");
	printArray(T);
	printf("\n\n");
	printf("Print tree preorder\n");
	printTree(Tree);
	//T[5] = AlokasiT(0, 0.20);
	//T[6] = AlokasiT(0, 0.27);
	//jumlah = countSymbol(T);
	//printf("%d\n", jumlah);
	//jumlah = countFilledArray(T);
	//printf("%d\n", jumlah);
	//Min = T[searchMinProb(T)]->prob;
	//printf("%g\n", Min);
	//while(T[i]->symbol!=0){
	//	printf("%c\n",T[i]->symbol);
	//	i++;
	//}
	/*T[0]->parent = T[5];
	if(T[5]->symbol==0){
		printf("%g",T[0]->parent->prob);
	}*/
	return 0;
}
