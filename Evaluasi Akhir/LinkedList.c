/* ------------------------------------------------
 * Program		: LinkedList.c
 * Deskripsi	: 
 * Nama			: - Dewanto Joyo Pramono		(181524005)
 				  - Mufqi Uwais Nastiar Salim	(181524017)
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/
 
#ifndef List_C
#define List_C

#include<stdio.h>
#include<stdbool.h>
#include"LinkedList.h"
#include"Huffman.h"

/*** Prototype */

/** Constructor */
address Alokasi(infotype Huruf){
	address newNode;
	newNode = (address) malloc (sizeof(Node));
	if(newNode != NULL){ //Node Berhasil Dibuat
		Info(newNode) = Huruf;
		TotalInfo(newNode) = 1;
		Next(newNode) = NULL;
	}
	return newNode;
}

address AlokasiFreq(infotype Huruf, int Freq){
	address newNode;
	newNode = (address) malloc (sizeof(Node));
	if(newNode != NULL){ //Node Berhasil Dibuat
		Info(newNode) = Huruf;
		TotalInfo(newNode) = Freq;
		Next(newNode) = NULL;
	}
	return newNode;
}

void CreateList(List *L){
	First(*L) = NULL;
}

void CreateProbabilty(List *L, float Jumlah){
	address PNav;
	PNav = First(*L);
	while(PNav != NULL){
		TotalInfo(PNav) = TotalInfo(PNav)/Jumlah*100;
		PNav = Next(PNav);
	}
}

/** Destructor */
void DeleteAllNode(List *L){
	address PNav, DeleteNode;
	PNav = First(*L);
	First(*L) = NULL;
	while(PNav != NULL){
		DeleteNode = PNav;
		PNav = Next(PNav);
		free(DeleteNode);
	}
}

/** Operasi-operasi pada list */
void InsertNode(List *L, address NewNode){
	if(isEmpty(*L)){ //List Kosong
		First(*L) = NewNode;
	}
	else{ //List tidak kosong
		address PNav;
		PNav = First(*L);
		while(Next(PNav) != NULL){ 
			PNav = Next(PNav);
		} //Pointer berada di ujung list
		Next(PNav) = NewNode;
	}
}

void InsertHuruf(List *L, infotype Huruf){
	bool isDone = false; //Proses belum selesai
	if(isEmpty(*L)){ //List Kosong
		First(*L) = Alokasi(Huruf);
	}
	else{ //List tidak kosong
		address PNav;
		PNav = First(*L);
		while(PNav != NULL){ //Mencari huruf yang sama
			if(Info(PNav) == Huruf){
				TotalInfo(PNav) += 1;
				PNav = NULL;
				isDone = true; //Proses selesai
			}
			else{
				PNav = Next(PNav);
			}
		}
		if(!isDone){ //Bila huruf tidak ditemukan
			InsertNode(L, Alokasi(Huruf)); //Membuat node baru dalam list
		}
	}
}

void InsertFreq(List *L, infotype Huruf, int freq){
	bool isDone = false; //Proses belum selesai
	if(isEmpty(*L)){ //List Kosong
		First(*L) = AlokasiFreq(Huruf,freq);
	}
	else{ //List tidak kosong
		address PNav;
		PNav = First(*L);
		while(PNav != NULL){ //Mencari huruf yang sama
			if(Info(PNav) == Huruf){
				TotalInfo(PNav) += freq;
				PNav = NULL;
				isDone = true; //Proses selesai
			}
			else{
				PNav = Next(PNav);
			}
		}
		if(!isDone){ //Bila huruf tidak ditemukan
			InsertNode(L, AlokasiFreq(Huruf,freq)); //Membuat node baru dalam list
		}
	}
}

void binaryToRandomChar(char Input[LengthOfInput], List theList){
	int i,j,k=0;
	char s1[2],s2[2];
	bool found;
	address PNav;
	Code hasil, kompres="NONE",sisa="NONE";
	int pembagi = 8, batas,asci = 0;
	hasil = "123";
	printf("================================================================\n");
	printf("Input sebelum diubah menjadi code : %s\n",Input);
	for(i=0;i<strlen(Input);i++){
		found = false;
		PNav = First(theList);
		while(PNav != NULL || !found){
			if(Input[i] == Info(PNav)){
				if(hasil=="123"){
					hasil = Code(PNav);
				}
				else{
					hasil = concat(hasil,Code(PNav));
				}
				found = true;
			}
			PNav = Next(PNav);
		}
	}
	printf("Input setelah diubah menjadi code : %s",hasil);
	batas = strlen(hasil)-(strlen(hasil)%pembagi);
	i=0;
	while(i<batas){
		for(j=i;j<=i+7;j++){
			if(j==i){
				asci += (hasil[j]-'0')*128;
			}
			if(j==i+1){
				asci += (hasil[j]-'0')*64;
			}
			if(j==i+2){
				asci += (hasil[j]-'0')*32;
			}
			if(j==i+3){
				asci += (hasil[j]-'0')*16;
			}
			if(j==i+4){
				asci += (hasil[j]-'0')*8;
			}
			if(j==i+5){
				asci += (hasil[j]-'0')*4;
			}
			if(j==i+6){
				asci += (hasil[j]-'0')*2;
			}
			if(j==i+7){
				asci += (hasil[j]-'0')*1;
			}
		}
		s1[0] = (char)asci;
		s1[1] = '\0';
		s2[0] = '\0';
		s2[1] = '\0';
		if(i==0){
			kompres = concat(s1,s2);
		}
		else{
			kompres = concat(kompres,s1);
		}
		asci = 0;
		i = i + 8;
	}
	while(i<strlen(hasil)){
		s1[0] = hasil[i];
		kompres = concat (kompres,s1);
		if(strcmp(sisa,"NONE")==0){
			sisa = concat(s1,s2);
		}
		else{
			sisa = concat(sisa,s1);
		}
		i++;
	}
	printf("\n");
	printf("Output hasil compress             : %s",kompres);
	printf("\nKode - kode sisa yang tidak terkompres         : %s",sisa);
	printf("\n");
}

void PrintInfoList(List L){
	address PNav;
	PNav = First(L);
	printf("================================================================\n");
	printf("%10s%15s%15s\n","Simbol","Probabilitas","Kode Huruf");
	while(PNav != NULL){
		//printf("Huruf: %c \nProb: %.2f\nCode: %s\n",Info(PNav),TotalInfo(PNav),Code(PNav));
		if(Info(PNav) == 10 || Info(PNav) == 9){
			switch(Info(PNav)){
				case 10:{
					printf("%6s'%s'%15.2f%15s\n"," ","\\n",TotalInfo(PNav),Code(PNav));
					break;
				}
				case 9:{
					printf("%6s'%s'%15.2f%15s\n"," ","\\t",TotalInfo(PNav),Code(PNav));
					break;
				}
			}
		}
		else{
			printf("%7s'%c'%15.2f%15s\n"," ",Info(PNav),TotalInfo(PNav),Code(PNav));
		}
		PNav = Next(PNav);
	}
}

/** Validasi List */
bool isEmpty(List L){
	return L.first == NULL;
}

#endif
