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
	while(found==0){
		if(Table[i]->status==0){
			found = 1;
			IndexMinProb = i;
		}
		i++;
	}
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

void addNewNode(addressT *Table, float newProb, int newIndex){
	Table[newIndex] = AlokasiT(0, newProb);
}

void connectToTree(addressT *Table, BinTree *newTree){
	
}

void executeHuffman(addressT *Table, BinTree *newTree){
	float minProb1, minProb2, parentProb;
	minProb1 = searchMinProb(&(*Table));
	minProb2 = searchMinProb(&(*Table));
	parentProb = minProb1 + minProb2;
	
}





#endif
