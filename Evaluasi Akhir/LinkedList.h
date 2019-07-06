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

#define LengthOfInput 100
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

/* Constructor */
address Alokasi(infotype Huruf);
address AlokasiFreq(infotype Huruf, int Freq);
void CreateProbabilty(List *L, float Jumlah);

/* Destructor */
void DeleteAllNode(List *L);

/* Inisiasi List */
void CreateList(List *L);

/* Operasi-operasi pada list */
void InsertNode(List *L, address NewNode);
void InsertHuruf(List *L, infotype Huruf);
void InsertFreq(List *L, infotype Huruf, int freq);
void PrintInfoList(List L);

/* Validasi List */
bool isEmpty(List L);

#endif
