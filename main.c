/* ------------------------------------------------
 * Program		: Huffman_Coding.c
 * Deskripsi	: 
 * Nama			: - Dewanto Joyo Pramono		(181524005)
 				  - Mufqi Uwais Nastiar Salim	(181524017)
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "BTree.h"

#define INPUTDATA 1
#define SHOWTREE 2
#define SHOWCODE 3
#define EXIT 4
/*
int main(){
	int MenuSelect,i;
	char Input[100];
	
	List DataHuruf;
	
	CreateList(&DataHuruf);
	
	MenuSelect = 0;
	while(MenuSelect != 4){
		MenuSelect = MainMenu();
		
		switch(MenuSelect){
			case INPUTDATA:{
				printf("Input kata/kalimat:\n"); 
				scanf(" %[^\n]s",Input); // Input data dari keyboard
				//Test
				/*
				int i;
				for(i=0;i<strlen(Input);i++){
					printf("%c\n",Input[i]);
				}
				printf("finish\n");
				
				//End Test
				for(i=0;i<strlen(Input);i++){
					InsertHuruf(&DataHuruf,Input[i]);
				}
				CreateProbabilty(&DataHuruf, strlen(Input));
				PrintInfoList(DataHuruf); // test
				system("pause");
				break;
			} //end Case 1
			case SHOWTREE:{
				printf("Test select 2");
				break;
			} //end Case 2
			case SHOWCODE:{
				printf("Test select 3");
				break;
			} //end Case 3
			case EXIT:{
				break;
			} //end Case 4
		} //end Switch
	} //end While
} //end Main
*/
int MainMenu(){
	int Pilihan;
	
	system("cls");
	printf("1. Input data berupa kalimat.\n");
	printf("2. Tampilkan Tree.\n");
	printf("3. Tampilkan kode huruf.\n");
	printf("4. Exit.\n");
	printf("Pilihan: ");scanf("%d",&Pilihan);
	if(Pilihan > 4 || Pilihan < 1){ //Program error ketika input berupa huruf
		printf("Pilihan tidak tersedia.\n");
		system("pause");
		Pilihan = 0;
	}
	return Pilihan;
}
