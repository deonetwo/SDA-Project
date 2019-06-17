/* ------------------------------------------------
 * Program		: Huffman_Coding.c
 * Deskripsi	: 
 * Nama			: - Dewanto Joyo Pramono		(181524005)
 				  - Mufqi Uwais Nastiar Salim	(181524017)
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Huffman.h"
#include "BTree.h"

#define TreeArrayLength 30
#define INPUTDATA 1
#define SHOWTREE 2
#define SHOWCODE 3
#define EXIT 4

bool ResetList(List *L);
void HuffmanCodingProccess(addressT Tree[TreeArrayLength], List theList);
void MoveCodeToList(addressT *Table, List *theList);

int main(){
	int MenuSelect,i;
	char Input[100];
	
	List DataHuruf;
	
	BinTree theTree;
	
	addressT T[TreeArrayLength];
	
	CreateList(&DataHuruf);
	
	MenuSelect = 0;
	while(MenuSelect != 4){
		MenuSelect = MainMenu();
		
		switch(MenuSelect){
			case INPUTDATA:{
				if(ResetList(&DataHuruf)){
					initiateTable(T, TreeArrayLength);
					initiateTree(&theTree);
					
					printf("Input kata/kalimat:\n"); 
					scanf(" %[^\n]s",Input); // Input data dari keyboard
					for(i=0;i<strlen(Input);i++){
						InsertHuruf(&DataHuruf,Input[i]);
					}
					CreateProbabilty(&DataHuruf, strlen(Input));
					//PrintInfoList(DataHuruf); // test
					//Input to Tree
					HuffmanCodingProccess(T,DataHuruf);
					executeHuffman(T, &theTree);
					//printArray(T);
					MoveCodeToList(T,&DataHuruf);
					PrintInfoList(DataHuruf);
				}
				else{
					printf("Kembali ke menu..");
				}
				system("pause");
				break;
			} //end Case 1
			case SHOWTREE:{
				printf("Test select 2");
				break;
			} //end Case 2
			case SHOWCODE:{
				printf("Test select 3");
				break;
			} //end Case 3
			case EXIT:{
				break;
			} //end Case 4
		} //end Switch
	} //end While
} //end Main

int MainMenu(){
	int Pilihan;
	
	system("cls");
	printf("1. Input data berupa kalimat.\n");
	printf("2. Tampilkan Tree.\n");
	printf("3. Tampilkan kode huruf.\n");
	printf("4. Exit.\n");
	printf("Pilihan: ");scanf("%d",&Pilihan);
	if(Pilihan > 4 || Pilihan < 1){ //Program error ketika input berupa huruf
		printf("Pilihan tidak tersedia.\n");
		system("pause");
		Pilihan = 0;
	}
	return Pilihan;
}

bool ListExist(List L){
	return First(L) != NULL;
}

bool ResetList(List *L){
	char InputAnswer;
	if(ListExist(*L)){ //List masih ada
		printf("Data sebelumnya masih ada, apakah anda ingin menghapus data? (Y/N)\n");
		scanf(" %c",&InputAnswer);
		if(tolower(InputAnswer) == 'y'){
			DeleteAllNode(L);
			return true;
		}
		else{
			return false;
		}
	}
	else{ //List Belum ada
		return true;
	}
}

void HuffmanCodingProccess(addressT Tree[TreeArrayLength], List theList){
	int IndexArrayTree = 0;
	address PNav;
	PNav = First(theList);
	while(PNav != NULL){
		Tree[IndexArrayTree] = AlokasiT(Info(PNav), TotalInfo(PNav));
		IndexArrayTree++;
		PNav = Next(PNav);
	}
}

void MoveCodeToList(addressT *Table, List *theList){
	int filledArray, i = 0;
	filledArray = countFilledArray(&(*Table));
	address PNav;
	PNav = First(*theList);
	while(PNav != NULL){
		i = 0;
		while(i<filledArray){
			if(Info(PNav) == Table[i]->symbol){
				//strcpy(Code(PNav),Table[i]->code);
				Code(PNav) = Table[i]->code;
			}
			i++;
		}
		PNav = Next(PNav);
	}
	//while(i<filledArray){
		//printf("%x		%c		%g		%x		%x		%d		%s\n", Table[i]->left, Table[i]->symbol, Table[i]->prob, Table[i]->right, Table[i]->parent, Table[i]->status, Table[i]->code);
	//	i++;
	//}
}
