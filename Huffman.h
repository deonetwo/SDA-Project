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

void addNewNode(addressT *Table, float newProb, int newIndex);

void connectToTree(addressT *Table, BinTree *newTree);

void executeHuffman(addressT *Table, BinTree *newTree);

#endif
