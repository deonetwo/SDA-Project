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
#include <ctype.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "Huffman.h"
#include "BTree.h"

#define TreeArrayLength 256
#define INPUTDATA 1
#define INPUTFREQ 2
#define SHOWTREE 3
#define SHOWCODE 4
#define COMPRESS 5
#define DECOMPRESS 6
#define EXIT 7

/*** Prototype Modul */
bool ResetList(List *L);
void HuffmanCodingProccess(addressT Tree[TreeArrayLength], List theList);
void MoveCodeToList(addressT *Table, List *theList);
void PrintCode(char Input[100],List theList);

/*** Main Program */
int main(){
	//Variabel dalam program
	int MenuSelect,i,Freq,TotalFreq;
	char Input[100];
	char InputFreq;
	bool FreqMenu;
	//Variabel lain
	List DataHuruf;
	BinTree theTree;
	addressT T[TreeArrayLength];
	
	CreateList(&DataHuruf);
	MenuSelect = 0;
	while(MenuSelect != EXIT){
		MenuSelect = MainMenu();
		
		switch(MenuSelect){
			case INPUTDATA:{
				if(ResetList(&DataHuruf)){
					initiateTable(T, TreeArrayLength);
					initiateTree(&theTree);
					
					// Input data dari keyboard
					printf("Input kata/kalimat:\n"); 
					scanf(" %[^\n]s",Input);
					for(i=0;i<strlen(Input);i++){
						InsertHuruf(&DataHuruf,Input[i]);
					}
					
					//Huffman Process
					CreateProbabilty(&DataHuruf, strlen(Input));
					HuffmanCodingProccess(T,DataHuruf);
					executeHuffman(T, &theTree);
					MoveCodeToList(T,&DataHuruf);
					printf("Data berhasil disimpan..\n");
					FreqMenu = false;
				}
				else{
					printf("Kembali ke menu..");
				}
				system("pause");
				break;
			} //end Case 1
			case INPUTFREQ:{
				if(ResetList(&DataHuruf)){
					TotalFreq = 0;
					initiateTable(T, TreeArrayLength);
					initiateTree(&theTree);
					do{
						system("cls");
						printf("==============================================\n");
						printf("Implementasi Huffman Code dengan Array\n");
						printf("oleh\t: Dewanto & Mufqi\n");
						printf("Prodi\t: D4-Informatika POLBAN\n");
						printf("==============================================\n");
						printf("============= [MAIN MENU] ====================\n");
						printf("==============================================\n");
						printf("Input huruf\t: "); scanf(" %c",&InputFreq);
						printf("Input frequensi\t: "); scanf(" %d",&Freq);
						InsertFreq(&DataHuruf,InputFreq,Freq);
						TotalFreq += Freq;
						printf("Tekan Enter untuk melanjutkan dan Esc untuk mengakhiri..\n"); 
					}while(getch() != 27); //Loop berakhir saat menekan ESC(ASCI = 27) saat selesai
					
					//Huffman Process
					CreateProbabilty(&DataHuruf, TotalFreq);
					HuffmanCodingProccess(T,DataHuruf);
					executeHuffman(T, &theTree);
					MoveCodeToList(T,&DataHuruf);
					printf("Data berhasil disimpan..\n");
					FreqMenu = true;
				}
				else{
					printf("Kembali ke menu..");
				}
				system("pause");
				break;
			}//end Case 2
			case SHOWTREE:{
				if(isEmpty(DataHuruf)){
					printf("Data tidak ditemukan.\n");
				}
				else{
					printTree(theTree,0);
					printf("Keterangan: Tree dibaca dari kiri ke kanan sehingga root berada di kiri.\n");
				}
				system("pause");
				break;
			} //end Case 3
			case SHOWCODE:{
				if(isEmpty(DataHuruf)){
					printf("Data tidak ditemukan.\n");
				}
				else{
					PrintInfoList(DataHuruf);
					if(!FreqMenu){ //Input berupa kalimat
						PrintCode(Input, DataHuruf);
					}
				}
				system("pause");
				break;
			} //end Case 4
			case COMPRESS:{
				if(ResetList(&DataHuruf)){
					initiateTable(T, TreeArrayLength);
					initiateTree(&theTree);
					int JumlahHurufFile=0;
					FILE *fp;
					char FileName[25],huruf;
					printf("Masukan nama file: ");
					scanf("%s",FileName);
					
					fp = fopen(FileName, "r");
					
					if(fp == NULL){
						perror("Error");
					}
					else{
						while((huruf = fgetc(fp)) != EOF){
							//printf("%c",huruf);
							InsertHuruf(&DataHuruf,huruf);
							JumlahHurufFile += 1;
						}
						//Huffman Process
						CreateProbabilty(&DataHuruf, JumlahHurufFile);
						HuffmanCodingProccess(T,DataHuruf);
						executeHuffman(T, &theTree);
						MoveCodeToList(T,&DataHuruf);
						printf("Data berhasil disimpan..\n");
						FreqMenu = true;
					}
					fclose(fp);
				}
				else{
					printf("Kembali ke menu..");
				}
				system("pause");
				break;
			}
			case DECOMPRESS:{
				
				break;
			}
			case EXIT:{
				printf("Terima Kasih telah menggunakan program ini.\n");
				break;
			} //end Case 4
			default:{
				printf("Pilihan tidak tersedia\n");
				break;
			}
		} //end Switch
	} //end While tidak EXIT
	return 0;
} //end Main

//Menampilkan menu aplikasi
int MainMenu(){
	int Pilihan;
	
	system("cls");
	printf("==============================================\n");
	printf("Implementasi Huffman Code dengan Array\n");
	printf("oleh\t: Dewanto & Mufqi\n");
	printf("Prodi\t: D4-Informatika POLBAN\n");
	printf("==============================================\n");
	printf("============= [MAIN MENU] ====================\n");
	printf("==============================================\n");
	printf("1. Input data berupa sekumpulan simbol/kalimat\n");
	printf("2. Input data berupa simbol beserta frequensi\n");
	printf("3. Tampilkan Tree\n");
	printf("4. Tampilkan kode huruf\n");
	printf("5. Exit\n\n");
	printf("Pilihan: ");scanf("%d",&Pilihan);
	if(Pilihan > EXIT || Pilihan < INPUTDATA){ //Program error ketika input berupa huruf
		printf("Pilihan tidak tersedia.\n");
		system("pause");
		Pilihan = 0;
	}
	return Pilihan;
}

//Memeriksa apakah telah ada/tidak
bool ListExist(List L){
	return First(L) != NULL;
}

//Menghapus list
bool ResetList(List *L){
	char InputAnswer;
	if(ListExist(*L)){ //List masih ada
		printf("Data sebelumnya masih ada, apakah anda ingin menghapus data? (Y/N)\n");
		scanf(" %c",&InputAnswer);
		if(tolower(InputAnswer) == 'y'){
			DeleteAllNode(L);
			return true;
		}
		else{
			return false;
		}
	}
	else{ //List Belum ada
		return true;
	}
}

//Menginput huruf-huruf yang berada dalam list menuju tree
void HuffmanCodingProccess(addressT Tree[TreeArrayLength], List theList){
	int IndexArrayTree = 0;
	address PNav;
	PNav = First(theList);
	while(PNav != NULL){
		Tree[IndexArrayTree] = AlokasiT(Info(PNav), TotalInfo(PNav));
		IndexArrayTree++;
		PNav = Next(PNav);
	}
}

//Memasukan data dari tree menuju list
void MoveCodeToList(addressT *Table, List *theList){
	int filledArray, i = 0;
	filledArray = countFilledArray(&(*Table));
	address PNav;
	PNav = First(*theList);
	while(PNav != NULL){
		i = 0;
		while(i<filledArray){
			if(Info(PNav) == Table[i]->symbol){
				//strcpy(Code(PNav),Table[i]->code);
				Code(PNav) = Table[i]->code;
			}
			i++;
		}
		PNav = Next(PNav);
	}//end while List mencapai akhir
}

//Menampilkan code hasil terjemahan berupa huffman code
void PrintCode(char Input[100],List theList){
	int i;
	bool found;
	address PNav;
	printf("================================================================\n");
	printf("Input sebelum diubah menjadi code : %s\n",Input);
	printf("Input setelah diubah menjadi code : ");
	for(i=0;i<strlen(Input);i++){
		found = false;
		PNav = First(theList);
		while(PNav != NULL || !found){
			if(Input[i] == Info(PNav)){
				printf("%s", Code(PNav));
				found = true;
			}
			PNav = Next(PNav);
		}
	}
	printf("\n");
}
