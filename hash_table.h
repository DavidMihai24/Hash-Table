#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "generic_linked_list.h"

#ifndef _HASH_TABLE_
#define _HASH_TABLE_

/* GHELESEL David-Mihai 311CB*/

typedef void (*TF)(void*);     /* functie afisare/eliberare un element */
typedef int (*TFHash)(char*);

typedef struct
{
    size_t M;
    TFHash fh;
    LinkedList* v;
} HashTable;

/* functii tabela hash */
HashTable* initializeHashTable(size_t M, TFHash fh);

void insertWord(HashTable *hash_table, char* word);

void print(HashTable* hash_table);

void printWordsBasedOnStartingLetter(HashTable* hash_table, char starting_letter, int length_of_word);

void printWordsWithMaxOccurrences(HashTable* tabel, int max_nr_aparitii);

void concatenate(char message[], char append[]);

void appendChar(char message[], int number);

#endif