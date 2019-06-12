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
#include "BTree.h"

addressT AlokasiT(infotypeT X)
{   /* menghasilkan address hasil alokasi sebuah Node */
    /* Jika alokasi berhasil, maka address tidak Nil  */
    /* Info(P)=X, Left(P)=Nil,Right(P)=Nil; Count(P)=0 */	
    /* Jika alokasi gagal ; mengembalikan  Nil 	     */
   
  
    addressT P;
    P=(addressT) malloc(sizeof(ElmtNode));   
    if(P!=Nil)
	{
    	InfoT(P)=X;
    	Left(P)=Nil;
		Right(P)=Nil;	 
		Count(P)=0; 
    }
    return P;
}

int IsEmpty(BinTree P)
{  	/*  Mengembalikan true jika pohon kosong  */
	return (P==Nil);
}

infotypeT GetAkar(BinTree P)
{ 	/* Mengirimkan informasi yang tersimpan di Akar pohon biner P */
	/* tidak kosong */
	return InfoT(P);	
}

BinTree GetLeft(BinTree P)
{ 	/* Mengirimkan anak kiri dari pohon biner P yang tidak kosong */
    return Left(P); 	
}

BinTree GetRight(BinTree P)
{ 	/* Mengirimkan anak kanan dari pohon pohon biner P yang tidak kosong */
    return Right(P);
}

#endif
