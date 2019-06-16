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

int countProb(addressT *Table){
	int i = 0;
	int TotalProb = 0;
	while(Table[i]->symbol!=0){
		TotalProb += Table[i]->prob;
		i++;
	}
	return TotalProb;
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
	if(indexMinProb2==-1){
		(*newTree) = Table[indexMinProb1];
	}
	else{
		parentProb = Table[indexMinProb1]->prob + Table[indexMinProb2]->prob;
		indexParentProb = insertNode(&(*Table), parentProb);
		Table[indexParentProb]->left = Table[indexMinProb1];
		Table[indexParentProb]->right = Table[indexMinProb2];
		Table[indexMinProb1]->parent = Table[indexParentProb];
		Table[indexMinProb2]->parent = Table[indexParentProb];
		(*newTree) = Table[indexParentProb];
	}
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}


void produceCode(addressT *Table){
	int totalSymbol, i = 0;
	float currentProb;
	char currentSymbol;
	addressT pcur;
	totalSymbol = countSymbol(&(*Table));
	if(totalSymbol==1){
		Table[i]->code = "0";
	}
	else{
		while(i<totalSymbol){
			pcur = Table[i];
			currentProb = Table[i]->prob;
			currentSymbol = Table[i]->symbol;
			while(pcur!=Nil){
				if(pcur->prob<=countProb(&(*Table))){
					currentProb = pcur->prob;
					pcur->symbol = currentSymbol;
					if(currentProb == pcur->parent->left->prob && currentSymbol == pcur->parent->left->symbol){
						if(strcmp(Table[i]->code, "NONE")==0){
							Table[i]->code = "0";
						}
						else{
							Table[i]->code = concat("0", Table[i]->code);
						}
					}
					else{
						if(strcmp(Table[i]->code, "NONE")==0){
							Table[i]->code = "1";
						}
						else{
							
							Table[i]->code = concat("1", Table[i]->code);
						}
					}
				}
				if(pcur!=Table[i]){
					pcur->symbol = 0;
				}
				pcur = pcur->parent;
			}
			i++;
		}
	}
	
}

void executeHuffman(addressT *Table, BinTree *newTree){
	int i = 1;
	if(countSymbol(&(*Table))==1){
		connectToTree(&(*Table), &(*newTree));
	}
	else{
		while(i < (( countSymbol(&(*Table)) * 2 ) - countSymbol(&(*Table)))){
			connectToTree(&(*Table), &(*newTree));
			i++;		
		}
	}
	produceCode(&(*Table));
}

void printArray(addressT *Table){
	int filledArray, i = 0;
	filledArray = countFilledArray(&(*Table));
	printf("left		symbol		prob		right		parent		status		code\n");
	while(i<filledArray){
		printf("%x		%c		%g		%x		%x		%d		%s\n", Table[i]->left, Table[i]->symbol, Table[i]->prob, Table[i]->right, Table[i]->parent, Table[i]->status, Table[i]->code);
		i++;
	}
}





#endif
