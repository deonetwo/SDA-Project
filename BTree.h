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

typedef char *Code;
typedef struct tElmtNode *addressT;
typedef struct tElmtNode {
	float prob;
	char symbol;
	addressT parent;
	addressT left;
	addressT right;
	int status;
	Code code;
} ElmtNode;
typedef addressT BinTree;

addressT AlokasiT(char X, float prob);

void initiateTree(BinTree *tree);

void printTree(BinTree T,int space);


#endif
