#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "BTree.h"

int main(){
	addressT T[26];
	T[0] = AlokasiT('a', 0.12);
	T[1] = AlokasiT('b', 0.40);
	T[2] = AlokasiT('c', 0.15);
	T[3] = AlokasiT('d', 0.08);
	T[4] = AlokasiT('e', 0.25);
	
	//printf("%c",T[1]->symbol);
	return 0;
}
