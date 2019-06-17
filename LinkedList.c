/* ------------------------------------------------
 * Program		: LinkedList.c
 * Deskripsi	: 
 * Nama			: - Dewanto Joyo Pramono		(181524005)
 				  - Mufqi Uwais Nastiar Salim	(181524017)
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/
 
#ifndef List_C
#define List_C

#include<stdio.h>
#include<stdbool.h>
#include"LinkedList.h"

/** Prototype */

/* Inisiasi Node */
address Alokasi(infotype Huruf){
	address newNode;
	newNode = (address) malloc (sizeof(Node));
	if(newNode != NULL){ //Node Berhasil Dibuat
		Info(newNode) = Huruf;
		TotalInfo(newNode) = 1;
		Next(newNode) = NULL;
	}
	return newNode;
}

/* Inisiasi List */
void CreateList(List *L){
	First(*L) = NULL;
}

/* Penambahan node pada list */
void InsertNode(List *L, address NewNode){
	if(isEmpty(*L)){ //List Kosong
		First(*L) = NewNode;
	}
	else{ //List tidak kosong
		address PNav;
		PNav = First(*L);
		while(Next(PNav) != NULL){ 
			PNav = Next(PNav);
		} //Pointer berada di ujung list
		Next(PNav) = NewNode;
	}
}

void InsertHuruf(List *L, infotype Huruf){
	bool isDone = false; //Proses belum selesai
	if(isEmpty(*L)){ //List Kosong
		First(*L) = Alokasi(Huruf);
	}
	else{ //List tidak kosong
		address PNav;
		PNav = First(*L);
		while(PNav != NULL){ //Mencari huruf yang sama
			if(Info(PNav) == Huruf){
				TotalInfo(PNav) += 1;
				PNav = NULL;
				isDone = true; //Proses selesai
			}
			else{
				PNav = Next(PNav);
			}
		}
		if(!isDone){ //Bila huruf tidak ditemukan
			InsertNode(L, Alokasi(Huruf)); //Membuat node baru dalam list
		}
	}
}

/* Validasi List */
bool isEmpty(List L){
	return L.first == NULL;
}

/* (print info) */
void PrintInfoList(List L){
	address PNav;
	PNav = First(L);
	printf("================================================================\n");
	printf("%10s%15s%15s\n","Simbol","Probabilitas","Kode Huruf");
	while(PNav != NULL){
		//printf("Huruf: %c \nProb: %.2f\nCode: %s\n",Info(PNav),TotalInfo(PNav),Code(PNav));
		printf("%10c%15.2f%15s\n",Info(PNav),TotalInfo(PNav),Code(PNav));
		PNav = Next(PNav);
	}
}

/* (create prob) */
void CreateProbabilty(List *L, float Jumlah){
	address PNav;
	PNav = First(*L);
	while(PNav != NULL){
		TotalInfo(PNav) = TotalInfo(PNav)/Jumlah*100;
		PNav = Next(PNav);
	}
}

/* Destructor */
void DeleteAllNode(List *L){
	address PNav, DeleteNode;
	PNav = First(*L);
	First(*L) = NULL;
	while(PNav != NULL){
		DeleteNode = PNav;
		PNav = Next(PNav);
		free(DeleteNode);
	}
}

#endif
