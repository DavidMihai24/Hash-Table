#include "hash_table.h"
#include <stdio.h>
#include <ctype.h>

/* GHELESEL David-Mihai 311CB*/

// primind un cuv, va trimite la locul din v unde trebuie inserat elementul.
// daca element e "Anca" o sa trimita la 0.
int codHash(char* element) {
    if (element[0] >= 97) {
        return (int) element[0] - (int)'a';
    } else {
        return (int) element[0] - (int)'A';
    }
}

void handleInsert(HashTable* hashTable) {
    char* text;
    text = strtok(NULL, "\n");

    char* word;
    word = strtok(text, " ,.");

    while (word) {
        if(strlen(word) < 3){
            word = strtok(NULL, " .,\n");
            continue;
        }

        insertWord(hashTable, word);
        word = strtok(NULL, " .,\n");
    }
}

void handlePrint(HashTable* hashTable) {
    int const ASCII_COD_PENTRU_0 = 48;

    char* parametru1 = strtok(NULL, " ");
    char* parametru2 = strtok(NULL, "\n");

    if(parametru1 != NULL) {
        if(parametru2 != NULL) {
            printWordsBasedOnStartingLetter(hashTable,
                                            *parametru1, *parametru2 - ASCII_COD_PENTRU_0);
            return;
        } else {
            printWordsWithMaxOccurrences(hashTable, *parametru1 - ASCII_COD_PENTRU_0);
            return;
        }
    }

    print(hashTable);
}

int main(int argc, char* argv[]) {
    FILE *in = fopen(argv[1], "rt");
    HashTable *hashTable = initializeHashTable(26, codHash);

    char text[200];

    while (fgets(text, 200, in) != NULL) {
        char* functie = strtok(text, " \n");

        if(strcmp(functie, "insert") == 0) {
            handleInsert(hashTable);
            continue;
        }

        if(strcmp(functie, "print") == 0) {
            handlePrint(hashTable);
            continue;
        }
    }

    fclose(in);

    return 0;
}
