#include "STACK.h"
#include "LinkedList.h"
#include "Huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/*Konstruktor=================================================*/
STACK *InitStack() {
	return NULL;
}
/*Membuat 1 node stack kosong atau NULL*/
STACK* MakeStack(dataType X) {
	STACK* p;
	
	p = (STACK*) malloc(sizeof(STACK));
	p->data = X;
	p->next = NULL;
	return p;
}

/*Validator===================================================*/
bool IsEmpty(STACK *top) {
	return (top == NULL);
}
/*Selektor====================================================*/

/*Mengambil data yang paling atas sekaligus menghapus*/
dataType PopStack(STACK **top) {
	STACK *temp;
	//char *result = "NONE";
	//char s1[2],s2[2];
	dataType popped;
	
	if (IsEmpty(*top)) {
		printf("Stack Kosong\n");
		//exit(1);
	} else {
		temp = *top;
		*top = temp->next;
		popped = temp->data;
		free(temp);
		/*
		s1[0] = (char)popped;
		s1[1] = '\0';
		s2[0] = '\0';
		s2[1] = '\0';
		result = concat(s1,s2);*/
		return popped;	
	}
}

/*Menambah stack dengan menambahkan di paling atas*/
void PushStack(STACK **top, dataType data) {
	STACK* p;
	
	p = MakeStack(data);
	p->next = *top;
	*top = p;
	printf("%d pushed to stack\n", data); 
}

/*Read and write stack========================================================*/

/*Mencetak stack yang telah ada ke layar*/
void PrintStack(STACK *top) {
	STACK* temp;

	if (IsEmpty(top)) {
		printf("Stack Kosong\n");
		//exit(1);
	} else {
		temp = top;
		while (temp != NULL) {
			printf("%d", temp->data);
			temp = temp->next;
		}
		//printf("NULL\n");
	}
}

/*Destruktor================================================*/
/*Reset stack/ hapus semua node yang ada*/
void ResetStack(STACK **top) {
	STACK* temp;
	dataType X;

	while (*top != NULL) {
		temp = *top;
		*top = temp->next;
		free(temp);
	}
	printf("Stack Sudah Kosong\n");
}
