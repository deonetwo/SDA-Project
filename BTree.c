/* ------------------------------------------------
 * Program		: BTree.c
 * Deskripsi	: ADT Binary Tree
 * Nama			: - Dewanto Joyo Pramono		(181524005)
 				  - Mufqi Uwais Nastiar Salim	(181524017)
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/

#ifndef BTREE_C
#define BTREE_C

#include <stdio.h>
#include <string.h>
#include "BTree.h"

addressT AlokasiT(char X, float prob)
{   /* menghasilkan address hasil alokasi sebuah Node */
    /* Jika alokasi berhasil, maka address tidak Nil  */
    /* Info(P)=X, Left(P)=Nil,Right(P)=Nil; Count(P)=0 */	
    /* Jika alokasi gagal ; mengembalikan  Nil 	     */
   
  
    addressT P;
    //char *str = "4", *str2 = "5";
    P=(addressT) malloc(sizeof(ElmtNode));   
    if(P!=Nil)
	{
		Prob(P)=prob;
    	Symbol(P)=X;
    	Parent(P)=Nil;
    	Left(P)=Nil;
		Right(P)=Nil;
		Status(P)=0;
		Code(P)="NONE";
    }
    return P;
}

void initiateTree(BinTree *tree){
	(*tree) = AlokasiT(0, 0);
}

void printTree(BinTree P)
{   /* I.S  : P terdefinisi                          	*/
    /* F.S  : semua simpul P sudah ditulis / preorder	*/
	if(P==Nil)
	{
	  printf("[ ]");	
	} else  {
		    printf("%g	",Prob(P));
		    if(Left(P)!=Nil){
		    	printTree(Left(P));
			}
		    if(Right(P)!=Nil){
		    	printTree(Right(P));
			}
		}
}



#endif
