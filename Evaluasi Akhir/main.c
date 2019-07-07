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
#include "STACK.h"

#define TreeArrayLength 511
#define INPUTDATA 1
#define INPUTFREQ 2
#define SHOWTREE 3
#define SHOWCODE 4
#define COMPRESS 5
#define DECOMPRESS 6
#define INPUTFILE 7
#define MAKECODE 8
#define EXIT 9

/*** Prototype Modul */
bool ResetList(List *L);
void HuffmanCodingProccess(addressT Tree[TreeArrayLength], List theList);
void MoveCodeToList(addressT *Table, List *theList);
void PrintCode(char Input[LengthOfInput],List theList);
void EncodeNode(BinTree node, FILE *fp);
BinTree ReadTree(FILE *reader);
void CompressTheCode(FILE *OriginalFile, FILE *CompressedFile, List theList);
void ProcessCodeToOrigin(Code OriginalCode,char huruf);

/*** Main Program */
int main(){
	//Variabel dalam program
	int MenuSelect,i,Freq,TotalFreq;
	char Input[LengthOfInput],InputTranslate[LengthOfInput];
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
						binaryToRandomChar(Input,DataHuruf);
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
					FILE *fpo,*fp;
					char FileName[25],huruf;
					printf("Masukan nama file: ");
					scanf("%s",FileName);
					
					fpo = fopen(FileName, "r");
					
					if(fpo == NULL){
						perror("Error");
					}
					else{
						while((huruf = fgetc(fpo)) != EOF){
							InsertHuruf(&DataHuruf,huruf);
							JumlahHurufFile += 1;
						}
						//Huffman Process
						CreateProbabilty(&DataHuruf, JumlahHurufFile);
						HuffmanCodingProccess(T,DataHuruf);
						executeHuffman(T, &theTree);
						MoveCodeToList(T,&DataHuruf);
						FreqMenu = true;
					}
					rewind(fpo);
					//strcat(FileName,"md");
					
					fp = fopen("Compressed.txt", "wb");
					
					if(fp == NULL){
						perror("Error");
					}
					else{
						EncodeNode(theTree, fp);
						putc(00,fp);
						CompressTheCode(fpo, fp, DataHuruf);
						
					}
					fclose(fpo);
					fclose(fp);
				}
				else{
					printf("Kembali ke menu..");
				}
				system("pause");
				break;
			}
			case DECOMPRESS:{
				initiateTable(T, TreeArrayLength);
				initiateTree(&theTree);
				
				Code OriginalCode = "";
				char FileName[25],huruf;
				printf("Masukan nama file: ");
				//scanf("%s",FileName);
					
				FILE *fp;
				fp = fopen("Compressed.txt", "rb"); // filename ganti
				
				if(fp == NULL){
					perror("Error");
				}
				else{
					/*
					while((huruf = fgetc(fp)) != EOF){
						printf("%c",huruf);
					}*/
					//rewind(fp);
					theTree = ReadTree(fp); //BUG: caranya agar ngeread sampe NULL kitu kumaha (FIXED)
					fgetc(fp);
					while((huruf = fgetc(fp)) != EOF && huruf != 00){
						//printf("%c",huruf);
						ProcessCodeToOrigin(OriginalCode,huruf);
					}
					printf("\n");
					while((huruf = fgetc(fp)) != EOF){
						printf("%c",huruf);
					}
				}
				//printTree(theTree,0);
				system("pause");
				fclose(fp);
				break;
			}
			case INPUTFILE:{
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
			case MAKECODE:{
				if(isEmpty(DataHuruf)){
					printf("Data tidak tersedia, silahkan input terlebih dahulu\n");
				}
				else{
					printf("Input beberapa simbol untuk dijadikan code(Batas: %d huruf):\n",LengthOfInput);
					scanf(" %[^\n]s",&InputTranslate);
					printf("Kode (beberapa symbol tidak mempunyai code silahkan input kembali):\n");
					for(i=0;i<strlen(InputTranslate);i++){
						if(!inList(DataHuruf, InputTranslate[i])){
							printf("%c",InputTranslate[i]);
						}
					}
					printf("\n");
				}
				system("pause");
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
	printf("5. Kompresi file\n");
	printf("6. Dekompresi file\n");
	printf("7. Input data berupa file\n");
	printf("8. Buat kode dari kamus yang tersimpan\n");
	printf("9. Exit\n\n");
	printf("Pilihan: ");scanf("%d",&Pilihan);
	if(Pilihan > EXIT || Pilihan < INPUTDATA){ //Program error ketika input berupa huruf
		printf("Pilihan tidak tersedia.\n");
		system("pause");
		Pilihan = 0;
	}
	return Pilihan;
}

void CompressTheCode(FILE *OriginalFile, FILE *CompressedFile, List theList){
	int i,j,k=0;
	char s1[2],s2[2],huruf;
	bool found;
	address PNav;
	Code hasil, kompres="NONE",sisa="NONE";
	int pembagi = 8, batas,asci = 0;
	hasil = "123";
	while((huruf = fgetc(OriginalFile)) != EOF){
		PNav = First(theList);
		while(PNav != NULL){
			if(huruf == Info(PNav)){
				if(hasil=="123"){
					hasil = PNav->code;
				}
				else{
					hasil = concat(hasil,Code(PNav));
				}
				break;
			}
			PNav = Next(PNav);
		}
	}
	//printf("Input setelah diubah menjadi code : %s",hasil);
	batas = strlen(hasil)-(strlen(hasil)%pembagi);
	i=0;
	if(strlen(hasil)>=8){
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
			if(asci==0){
				s1[0] = ' ';
			}
			else{
				s1[0] = (char)asci;
			}
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
		fprintf(CompressedFile,"%s",kompres);
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
		putc(00,CompressedFile);
		fprintf(CompressedFile,"%s",sisa);
		//printf("\n");
		//printf("Output hasil compress             : %s",kompres);
		//printf("\nKode - kode sisa yang tidak terkompres         : %s",sisa);
		//printf("\n");
	}
	else{
		fprintf(CompressedFile,"%s",hasil);
		/*printf("\n");
		printf("Output sama dengan kode huffman karena jumlah digit kode < 8");
		printf("\nOutput hasil compress             : %s",hasil);
		printf("\nKode - kode sisa yang tidak terkompres         : %s",hasil);
		printf("\n");*/
	}
}

//Memeriksa apakah telah ada/tidak
bool ListExist(List L){
	return First(L) != NULL;
}

void EncodeNode(BinTree node, FILE *fp){
    if (Symbol(node) != 0)
    {
        fprintf(fp,"1");
        fprintf(fp,"%c",node->symbol);
    }
    else
    {
        fprintf(fp,"0");
        EncodeNode(node->left, fp);
        EncodeNode(node->right, fp);
    }
}

void ProcessCodeToOrigin(Code OriginalCode,char huruf){
	STACK *BinStack;
	BinStack = InitStack();
	int tempInt;
	char tempChar[2];
	
	int decimal = (int) huruf;
	
	do{
		PushStack(&BinStack, decimal%2 );
		decimal=decimal/2;
	}while(decimal!=0);
	while(!IsEmpty(BinStack)){
		tempInt = PopStack(&BinStack) + '0';
		tempChar[0] = (char) tempInt;
		tempChar[1] = '\0';
		OriginalCode = concat(OriginalCode,tempChar);
	}
}

BinTree ReadTree(FILE *reader){
    if (fgetc(reader) == '1')
    {
    	return AlokasiTree(fgetc(reader), NULL, NULL);
        //return new Node(reader.ReadByte(), null, null);
    }
    else
    {
    	BinTree leftChild = ReadTree(reader);
    	BinTree rightChild = ReadTree(reader);
    	return AlokasiTree(0,leftChild,rightChild);
        //Node leftChild = ReadNode(reader);
        //Node rightChild = ReadNode(reader);
        //return new Node(0, leftChild, rightChild);
    }
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
				Code(PNav) = Table[i]->code;
			}
			i++;
		}
		PNav = Next(PNav);
	}//end while List mencapai akhir
}

//Menampilkan code hasil terjemahan berupa huffman code
void PrintCode(char Input[LengthOfInput],List theList){
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
