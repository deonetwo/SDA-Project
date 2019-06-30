/* ------------------------------------------------
 * Program		: BTree.h
 * Deskripsi	: ADT Binary Tree
 * Nama			: - Dewanto Joyo Pramono		(181524005)
 				  - Mufqi Uwais Nastiar Salim	(181524017)
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/

#ifndef BTREE_H
#define BTREE_H
 
#include <stdlib.h>
#define Nil NULL
#define Prob(P) (P)->prob
#define Symbol(P) (P)->symbol
#define Left(P)  (P)->left
#define Parent(P) (P)->parent
#define Right(P) (P)->right
#define Status(P) (P)->status
#define Code(P) (P)->code

/* Struktur data Node Tree */
typedef char *Code;			//ADT Code biner huffman
typedef struct tElmtNode *addressT;
typedef struct tElmtNode {
	float prob;
	char symbol;
	addressT parent;
	addressT left;
	addressT right;
	int status;				//Sebagai tanda apakah Node sudah terpasang ke tree
	Code code;
} ElmtNode;
typedef addressT BinTree;


/* Prototype */

addressT AlokasiT(char X, float prob);
/* 	menghasilkan address hasil alokasi sebuah ElmtNode */
    /* 	Jika alokasi berhasil, maka address tidak Nil  */
    /* 	Prob(P)=prob, Parent(P)=Nil, Symbol(P)=X, Left(P)=Nil, 
		Right(P)=Nil; Status(P)=0 */	
    /* 	Jika alokasi gagal ; mengembalikan  Nil 	     */

void initiateTree(BinTree *tree);
/* 	Untuk menginisiasi tree agar tree dapat dipakai*/

void printTree(BinTree T, int space);
/*	Untuk mencetak tree secara 'Reverse In-Order' atau In-Order 
		yang dimulai dari kanan terlebih dahulu*/
/*	Tree memanjang ke kanan dengan root di paling kiri*/


#endif
