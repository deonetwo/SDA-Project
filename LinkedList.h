/* ------------------------------------------------
 * Program		: LinkedList.h
 * Deskripsi	: 
 * Nama			: - Dewanto Joyo Pramono		(181524005)
 				  - Mufqi Uwais Nastiar Salim	(181524017)
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/
 
#ifndef List_H
#define List_H 

#include<stdlib.h>

#define Info(P) (P)->huruf
#define TotalInfo(P) (P)->jumlah
#define Next(P) (P)->next
#define First(L) (L).first

/* Struktur data Node */
typedef char infotype;
typedef struct Node *address;
typedef struct Node{
	infotype huruf;
	int jumlah;
	address next;
}Node;

/* Struktur data List */
typedef struct{
	address first;
}List;


/*** Prototype */

/* Inisiasi Node */
address Alokasi(infotype Huruf);

/* Inisiasi List */
void CreateList(List *L);

/* Penambahan node pada list */
void InsertNode(List *L, address NewNode);

#endif
