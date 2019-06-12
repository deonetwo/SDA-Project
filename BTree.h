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
#define InfoT(P) (P)->info
#define Left(P)  (P)->left
#define Parent(P) (P)->parent
#define Right(P) (P)->right
#define Count(P) (P)->count

typedef int infotypeT;
typedef struct tElmtNode *addressT;
typedef struct tElmtNode {
	infotypeT info;
	addressT left;
	addressT right;
	int count;
} ElmtNode;
typedef addressT BinTree;

addressT AlokasiT(infotypeT X);

int IsEmpty(BinTree P);

#endif
