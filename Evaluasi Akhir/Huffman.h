/* ------------------------------------------------
 * Program		: Huffman.h
 * Deskripsi	: Function-function dalam proses Huffman Coding
 * Nama			: - Dewanto Joyo Pramono		(181524005)
 				  - Mufqi Uwais Nastiar Salim	(181524017)
 * Tanggal/versi: 00-06-2019/v1.0
 * Compiler		: TDM-GCC 4.9.2 64-bit Release
 --------------------------------------------------*/
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "BTree.h"

void initiateTable(addressT *Table, int ArrayLength);
/* Untuk inisiasi tabel proses huffman coding dalam array*/

int searchMinProb(addressT *Table);
/*	Untuk mencari index dalam tabel array yang probabilitasnya
	paling kecil dan juga belum terpasang ke tree, lalu di return serta
	statusnya diubah menjadi 1*/

int countSymbol(addressT *Table);
/*	Untuk menghitung jumlah Symbol dalam tabel array, lalu di return*/

int countProb(addressT *Table);
/*	Untuk menghitung jumlah probabilitas dari seluruh symbol,
	lalu di return*/

int countFilledArray(addressT *Table);
/*	Untuk menghitung total array yang sudah terisi, lalu di return*/

int insertNode(addressT *Table, float newProb);
/*	Untuk insert Node baru ke tabel array*/
/*	digunakan untuk pembuatan internal node*/

void connectToTree(addressT *Table, BinTree *newTree);
/*	Untuk proses pemasangan Node ke tree*/
/*	Pembuatan internal node dan memasangnya ke tree dan juga tabel array*/
/*	Menyambungkan pointer-pointer*/

char* concat(const char *s1, const char *s2);
/*	Untuk menggabungkan 2 string, lalu di return*/

void produceCode(addressT *Table);
/*	Proses pembuatan code untuk setiap symbol dengan
	menggunakan tree atau tabel array sebagai acuan*/
/*	Menggunakan proses concatenate atau penggabungan 2 array of char*/

void executeHuffman(addressT *Table, BinTree *newTree);
/*	Proses keseluruhan Huffman Coding*/
/*	Mengubah tabel array dan membuat tree sebagai hasilnya*/

void printArray(addressT *Table);
/*	Untuk mencetak tabel array*/

#endif
