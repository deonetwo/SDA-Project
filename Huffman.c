#ifndef HUFFMAN_C
#define HUFFMAN_C

#include "Huffman.h"

void initiateTable(addressT *Table, int ArrayLength){
	int i = 0;
	while(i<ArrayLength){
		Table[i] = AlokasiT(0, 0);
		i++;
	}
}

int searchMinProb(addressT *Table){
	int filledArray, i=0;
	int IndexMinProb, found = 0;
	float MinProb;
	filledArray = countFilledArray(&(*Table));
	while(found==0&&i<filledArray){
		if(Table[i]->status==0){
			found = 1;
			IndexMinProb = i;
		}
		i++;
	}
	if(found==0){
		return -1;
	}
	else{
		MinProb = Table[IndexMinProb]->prob;
		i = 0;
		while(i<filledArray){
			if(Table[i]->status==1||i==IndexMinProb){
				i++;
			}
			else{
				if(Table[i]->prob<=MinProb){
					MinProb = Table[i]->prob;
					IndexMinProb = i;
				}
				i++;
			}
		}
		Table[IndexMinProb]->status = 1;
		return IndexMinProb;
	}
	return 0;
	//printf("%d\n",filledArray);
}

int countSymbol(addressT *Table){
	int count = 0, i = 0;
	while(Table[i]->symbol!=0){
		count++;
		i++;
	}
	return count;
}

int countFilledArray(addressT *Table){
	int count = 0, i = 0;
	while(Table[i]->symbol!=0||Table[i]->prob!=0){
		count++;
		i++;
	}
	return count;
}

int insertNode(addressT *Table, float newProb){
	int filledArray;
	filledArray = countFilledArray(&(*Table));
	Table[filledArray] = AlokasiT(0, newProb);
	return filledArray;
}

void connectToTree(addressT *Table, BinTree *newTree){
	int indexMinProb1, indexMinProb2, indexParentProb;
	float parentProb;
	indexMinProb1 = searchMinProb(&(*Table));
	indexMinProb2 = searchMinProb(&(*Table));
	parentProb = Table[indexMinProb1]->prob + Table[indexMinProb2]->prob;
	indexParentProb = insertNode(&(*Table), parentProb);
	Table[indexParentProb]->left = Table[indexMinProb1];
	Table[indexParentProb]->right = Table[indexMinProb2];
	Table[indexMinProb1]->parent = Table[indexParentProb];
	Table[indexMinProb2]->parent = Table[indexParentProb];
	(*newTree) = Table[indexParentProb];
}

void executeHuffman(addressT *Table, BinTree *newTree){
	int i = 1;
	while(i < (( countSymbol(&(*Table)) * 2 ) - countSymbol(&(*Table)))){
		connectToTree(&(*Table), &(*newTree));
		i++;		
	}
}

void printArray(addressT *Table){
	int filledArray, i = 0;
	filledArray = countFilledArray(&(*Table));
	printf("left		symbol		prob		right		parent		status\n");
	while(i<filledArray){
		printf("%x		%c		%g		%x		%x		%d\n", Table[i]->left, Table[i]->symbol, Table[i]->prob, Table[i]->right, Table[i]->parent, Table[i]->status);
		i++;
	}
}





#endif
