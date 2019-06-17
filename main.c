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
void PrintCode(char Input[100],List theList);

int main(){
	//-------------test tree-------------
	BinTree T1, T2, T3, T4, T5;
	T1 = AlokasiT(0,25);
	T2 = AlokasiT(0,15);
	T3 = AlokasiT('c',10);
	T4 = AlokasiT('d',30);
	T5 = AlokasiT('e',20);
	T1->left = T2;
	T1->right = T3;
	T2->parent = T1;
	T3->parent = T1;
	T2->left = T4;
	T2->right = T5;
	T4->parent = T2;
	T5->parent = T2;
	
	//printTree(T1,0);
	printTree(T1,0);
	
	
	return 0;
	//printTree(testTree);
	
	
	//-------------end of test tree---------
	/*
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
					//PrintInfoList(DataHuruf);
					printf("Data berhasil disimpan..\n");
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
				if(isEmpty(DataHuruf)){
					printf("Data tidak ditemukan.\n");
				}
				else{
					PrintInfoList(DataHuruf);
					PrintCode(Input, DataHuruf);
				}
				system("pause");
				break;
			} //end Case 3
			case EXIT:{
				break;
			} //end Case 4
		} //end Switch
	} //end While
	*/
} //end Main

int MainMenu(){
	int Pilihan;
	
	system("cls");
	printf("Implementasi Huffman Code dengan Array\n");
	printf("oleh\t: Dewanto & Mufqi\n");
	printf("Prodi\t: D4-Informatika POLBAN\n");
	printf("========================================\n");
	printf("=============  MAIN MENU  ==============\n");
	printf("========================================\n");
	printf("1. Input data berupa kalimat\n");
	printf("2. Tampilkan Tree\n");
	printf("3. Tampilkan kode huruf\n");
	printf("4. Exit\n\n");
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

void PrintCode(char Input[100],List theList){
	int i;
	bool found;
	address PNav;
	printf("================================================================\n");
	printf("Input sebelum diubah menjadi code : %s\n",Input);
	printf("Input setelah diubah menjadi code : ");
	for(i=0;i<strlen(Input);i++){
		found = false;
		PNav = First(theList);
		while(PNav != NULL || !found){
			if(Input[i] == Info(PNav)){
				printf("%s", Code(PNav));
				found = true;
			}
			PNav = Next(PNav);
		}
	}
	printf("\n");
}
