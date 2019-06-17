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
#include<stdbool.h>

#define Info(P) (P)->huruf
#define TotalInfo(P) (P)->jumlah
#define Next(P) (P)->next
#define Code(P) (P)->code
#define First(L) (L).first

/* Struktur data Node */
typedef char infotype;
typedef struct Node *address;
typedef char *Code;
typedef struct Node{
	infotype huruf;
	Code code;
	float jumlah;
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
void InsertHuruf(List *L, infotype Huruf);

/* Validasi List */
bool isEmpty(List L);

/* (print info) */
void PrintInfoList(List L);

/* (create prob) */
void CreateProbabilty(List *L, float Jumlah);

/* Destructor */
void DeleteAllNode(List *L);

#endif
