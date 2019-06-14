#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "BTree.h"

void initiateTable(addressT *Table, int ArrayLength);

int searchMinProb(addressT *Table);

int countSymbol(addressT *Table);

int countFilledArray(addressT *Table);

int insertNode(addressT *Table, float newProb);

void connectToTree(addressT *Table, BinTree *newTree);

char* concat(const char *s1, const char *s2);

void produceCode(addressT *Table);

void executeHuffman(addressT *Table, BinTree *newTree);

#endif
