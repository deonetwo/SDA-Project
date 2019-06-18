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

void printTree(BinTree T, int space) 
{ 
	int i, count = 1;
    // Base case 
    if (T == NULL) 
        return; 
  
    // Increase distance between levels 
    space += count; 
  
    // Process right child first 
    printTree(T->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (i = count; i < space; i++) {
    	printf("	"); 
	}
        
    if(T->symbol!=0){
    	printf("[%c]\n", T->symbol); 
	}
	else{
		printf("[%.2f]\n", T->prob); 
	}
   
  	
    // Process left child 
    printTree(T->left, space); 
}



#endif
