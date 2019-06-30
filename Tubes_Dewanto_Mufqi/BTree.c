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
{   /* 	menghasilkan address hasil alokasi sebuah ElmtNode */
    /* 	Jika alokasi berhasil, maka address tidak Nil  */
    /* 	Prob(P)=prob, Parent(P)=Nil, Symbol(P)=X, Left(P)=Nil, 
		Right(P)=Nil; Status(P)=0 */	
    /* 	Jika alokasi gagal ; mengembalikan  Nil 	     */
   
  
    addressT P;
    //char *str = "4", *str2 = "5";
    P=(addressT) malloc(sizeof(ElmtNode));   
    if(P!=Nil)				//Jika proses malloc berhasil, maka P!=Nil
	{
		Prob(P)=prob;		//Probabilitas diisi sesuai parameter
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
	/* 	Untuk menginisiasi tree agar tree dapat dipakai*/
	
	(*tree) = AlokasiT(0, 0);
}

void printTree(BinTree T, int space) 
{ 
	/*	Untuk mencetak tree secara 'Reverse In-Order' atau In-Order 
		yang dimulai dari kanan terlebih dahulu*/
	/*	Tree memanjang ke kanan dengan root di paling kiri*/
	
	int i, count = 1;	//var.count adalah multiplier jarak antar level di tree
    // Jika T nya Nil maka akan langsung return
    if (T == Nil) 
        return; 
  
    // Pertambahan jarak yang terakumulasi di var.space
    space += count; 
  
    // Mendahulukan right child
    printTree(T->right, space); 
  
    // Proses pemberian jarak antar level
    printf("\n"); 
    for (i = count; i < space; i++) {
    	printf("	"); 
	}
	
	//Proses print
    if(T->symbol!=0){
    	printf("['%c']\n", T->symbol); 
	}
	else{
		printf("[%g]\n", T->prob); 
	}
   
  	
    // Proses left child 
    printTree(T->left, space); 
}



#endif
