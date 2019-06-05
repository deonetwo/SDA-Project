/* ------------------------------------------------
 * Program		: Huffman_Coding.c
 * Deskripsi	: 
 * Nama			: - Dewanto Joyo Pramono	(181524005)
 				  - 
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/

#include<stdio.h>
#include<windows.h>

int main(){
	int MenuSelect;
	
	MenuSelect = 0;
	while(MenuSelect == 0){
		MenuSelect = MainMenu();
	}
}

int MainMenu(){
	int Pilihan;
	
	system("cls");
	printf("1. Input data berupa kalimat.\n");
	printf("2. Tampilkan Tree.\n");
	printf("3. Tampilkan kode huruf.\n");
	printf("Pilihan: ");scanf("%d",&Pilihan);
	if(Pilihan > 3 || Pilihan < 1){
		printf("Pilihan tidak tersedia.\n");
		system("pause");
		Pilihan = 0;
	}
	return Pilihan;
}
