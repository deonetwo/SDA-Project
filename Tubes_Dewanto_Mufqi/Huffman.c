/* ------------------------------------------------
 * Program		: Huffman.c
 * Deskripsi	: Function-function dalam proses Huffman Coding
 * Nama			: - Dewanto Joyo Pramono		(181524005)
 				  - Mufqi Uwais Nastiar Salim	(181524017)
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/
#ifndef HUFFMAN_C
#define HUFFMAN_C

#include "Huffman.h"

void initiateTable(addressT *Table, int ArrayLength){
	/* 	Untuk inisiasi tabel proses huffman coding dalam array*/
	int i = 0;
	while(i<ArrayLength){			//Ukuran array ditentukan oleh 
		Table[i] = AlokasiT(0, 0);	//var.ArrayLength dari parameter
		i++;
	}
}

int searchMinProb(addressT *Table){
	/*	Untuk mencari index dalam tabel array yang probabilitasnya
	 	paling kecil dan juga belum terpasang ke tree, lalu di return serta
		statusnya diubah menjadi 1*/
	
	int filledArray, i=0;
	int IndexMinProb, found = 0;
	float MinProb;
	filledArray = countFilledArray(&(*Table));	//Proses perhitungan current 
												//array yang baru terisi
	
	while(found==0&&i<filledArray){		//Proses mencari symbol yang belum
		if(Table[i]->status==0){		//terpasang ke tree
			found = 1;
			IndexMinProb = i;
		}
		i++;
	}
	if(found==0){	//Jika semua Node sudah terpasang maka akan return -1
		return -1;
	}
	else{
		MinProb = Table[IndexMinProb]->prob;
		i = 0;
		while(i<filledArray){
			if(Table[i]->status==1||i==IndexMinProb){	//Skipping symbol yang
				i++;									//sudah terpasang
			}											//atau diri sendiri
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
}

int countSymbol(addressT *Table){
	/*	Untuk menghitung jumlah Symbol dalam tabel array, lalu di return*/
	int count = 0, i = 0;
	while(Table[i]->symbol!=0){
		count++;
		i++;
	}
	return count;
}

int countProb(addressT *Table){
	/*	Untuk menghitung jumlah probabilitas dari seluruh symbol,
		lalu di return*/
	int i = 0;
	int TotalProb = 0;
	while(Table[i]->symbol!=0){
		TotalProb += Table[i]->prob;
		i++;
	}
	return TotalProb;
}

int countFilledArray(addressT *Table){
	/*	Untuk menghitung total array yang sudah terisi, lalu di return*/
	int count = 0, i = 0;
	while(Table[i]->symbol!=0||Table[i]->prob!=0){
		count++;
		i++;
	}
	return count;
}

int insertNode(addressT *Table, float newProb){
	/*	Untuk insert Node baru ke tabel array*/
	/*	digunakan untuk pembuatan internal node*/
	
	int filledArray;
	filledArray = countFilledArray(&(*Table));
	Table[filledArray] = AlokasiT(0, newProb);
	return filledArray;
}

void connectToTree(addressT *Table, BinTree *newTree){
	/*	Untuk proses pemasangan Node ke tree*/
	/*	Pembuatan internal node dan memasangnya ke tree dan juga tabel array*/
	/*	Menyambungkan pointer-pointer*/
	 
	int indexMinProb1, indexMinProb2, indexParentProb;
	float parentProb;
	indexMinProb1 = searchMinProb(&(*Table));
	indexMinProb2 = searchMinProb(&(*Table));
	if(indexMinProb2==-1){		//Jika tabel array hanya berisi 1 Node maka 
								//akan langsung dipasang ke tree
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
	/*	Untuk menggabungkan 2 string, lalu di return*/
	
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
	// Pemesanan array of berdasarkan panjang dari s1 dan s2
	
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}


void produceCode(addressT *Table){
	/*	Proses pembuatan code untuk setiap symbol dengan
		menggunakan tree atau tabel array sebagai acuan*/
	/*	Menggunakan proses concatenate atau penggabungan 2 array of char*/
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
				if(pcur->prob<countProb(&(*Table))){
					currentProb = pcur->prob;
					pcur->symbol = currentSymbol;
					if(currentProb == pcur->parent->left->prob &&
						currentSymbol == pcur->parent->left->symbol){
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
	/*	Proses keseluruhan Huffman Coding*/
	/*	Mengubah tabel array dan membuat tree sebagai hasilnya*/
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
	/*	Untuk mencetak tabel array*/
	int filledArray, i = 0;
	filledArray = countFilledArray(&(*Table));
	printf("left		symbol		prob		right		parent		status		code\n");
	while(i<filledArray){
		printf("%x		%c		%g		%x		%x		%d		%s\n", Table[i]->left, Table[i]->symbol, Table[i]->prob, Table[i]->right, Table[i]->parent, Table[i]->status, Table[i]->code);
		i++;
	}
}





#endif
