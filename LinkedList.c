/* ------------------------------------------------
 * Program		: LinkedList.c
 * Deskripsi	: 
 * Nama			: - Dewanto Joyo Pramono	(181524005)
 				  - 
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/
 
#ifndef List_C
#define List_C

#include<stdio.h>
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



#endif
