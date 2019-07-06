#ifndef STACKLINK_H
#define STACKLINK_H
#include <stdbool.h>

typedef int dataType;
typedef struct node { 
	dataType data;
	struct node* next;
}STACK;

/*Konstruktor=================================================*/
STACK *InitStack();

/*Membuat 1 node stack kosong atau NULL*/
STACK* MakeStack(dataType X);

/*Validator===================================================*/
bool IsEmpty(STACK *top);

/*Selektor====================================================*/

dataType PopStack(STACK **top);
/*Mengambil data yang paling atas sekaligus menghapus*/

void PushStack(STACK **top, dataType data);
/*Menambah stack dengan menambahkan di paling atas*/

/*Read and write stack========================================================*/

void PrintStack(STACK *top);
/*Mencetak stack yang telah ada ke layar*/

/*Destruktor================================================*/

void ResetStack(STACK **top);
/*Reset stack/ hapus semua node yang ada*/
#endif
