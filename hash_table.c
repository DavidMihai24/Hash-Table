#include "hash_table.h"
#include "word_count.h"
#include "word_list.h"

/* GHELESEL David-Mihai 311CB*/

HashTable* initializeHashTable(size_t M, TFHash fh) {
    HashTable* h = (HashTable *) calloc(sizeof(HashTable), 1);
    if (!h) {
        printf("Encountered error when creating the hash table \n");
        return NULL;
    }

    h->v = (LinkedList*) calloc(M, sizeof(LinkedList));

    if(!h->v) {
        printf("Encountered error when creating the hash table\n");
        free(h);
        return NULL;
    }

    h->M = M;
    h->fh = fh;
    return h;
}

void concatenate(char message[], char append[]) {
    int current_length = 0;

    unsigned int i = 0;
    for (; i < strlen(append); i++) {
        while (message[current_length] != ';') {
            current_length++;
        }

        message[current_length] = append[i];
        current_length++;
    }
}

void appendChar(char message[], int number) {
    int currentIndex = 0;

    while (message[currentIndex] != ';') {
        currentIndex++;
    }

    if (number < 10) {
        if (number == 0) {
            message[currentIndex] = 48;
            return;
        }
        message[currentIndex] = number + 48;
    } else {
        message[currentIndex] = (char) (number / 10 + 48);
        message[currentIndex+1] = (char) (number % 10 + 48);
    }
}

void print(HashTable* hash_table) {
    int index = 0;
    for (; index < hash_table->M; index++) {
        LinkedList list_of_lists = hash_table->v[index];

        if (list_of_lists == NULL) {
            continue;
        }

        char message[100];

        int i = 0;
        for (; i < 100; i++) {
            message[i] = ';';
        }

        concatenate(message, "pos ");
        appendChar(message, index);
        concatenate(message, ": ");

        while (list_of_lists != NULL) {
            concatenate(message, "(");

            int numberOfLetters = ((WordList *)(list_of_lists->data))->word_length;

            appendChar(message, numberOfLetters);
            concatenate(message, ":");

            LinkedList list_of_words = ((WordList *)(list_of_lists->data))->listOfWords;

            while (list_of_words != NULL) {
                WordCount* wc = (WordCount*) list_of_words->data;
                concatenate(message, wc->word);
                concatenate(message, "/");
                appendChar(message, wc->count);

                if (list_of_words->next != NULL) {
                    concatenate(message, ", ");
                }

                list_of_words = list_of_words->next;
            }

            list_of_lists = list_of_lists->next;
            concatenate(message, ")");
        }

        unsigned int x = 0;
        for (; x < 100; x++) {
            if (message[x] != ';') {
                printf("%c", message[x]);
            }
        }

        printf("\n");

    }
}

void printWordsBasedOnStartingLetter(HashTable* hash_table, char starting_letter, int length_of_word) {
    int index;

    if (starting_letter >= 97) {
        index = starting_letter - 'a';
    } else {
        index = starting_letter - 'A';
    }

    char message[100];

    unsigned int i = 0;
    for (; i < 100; i++) {
        message[i] = ';';
    }

    LinkedList list_of_lists = hash_table->v[index];
    int macarUnCuvant = 0;

    while (list_of_lists != NULL) {
        if (((WordList*)(list_of_lists->data))->word_length == length_of_word) {
            LinkedList list_of_words = ((WordList *)(list_of_lists->data))->listOfWords;

            concatenate(message, "(");
            appendChar(message, ((WordList *)(list_of_lists->data))->word_length);
            concatenate(message, ":");
            macarUnCuvant = 1;

            while (list_of_words != NULL) {
                WordCount* wc = (WordCount*)(list_of_words->data);
                concatenate(message, wc->word);
                concatenate(message, "/");
                appendChar(message, wc->count);

                if (list_of_words->next != NULL) {
                    concatenate(message, ", ");
                }

                list_of_words = list_of_words->next;
            }

            concatenate(message, ")");
        }
        list_of_lists = list_of_lists->next;
    }

    if (macarUnCuvant) {
        unsigned int x = 0;
        for (; x < 100; x++) {
            if (message[x] != ';') {
                printf("%c", message[x]);
            }
        }

        printf("\n");
    }
}

void printWordsWithMaxOccurrences(HashTable* tabel, int max_nr_aparitii) {

    int indexul_din_v = 0;
    for (; indexul_din_v < tabel->M; indexul_din_v++) {
        LinkedList lista_de_liste = tabel->v[indexul_din_v];
        int macarUnCuvant = 0;

        if (lista_de_liste == NULL) {
            continue;
        }

        char message[100];

        unsigned int i = 0;
        for (; i < 100; i++) {
            message[i] = ';';
        }

        concatenate(message, "pos");
        appendChar(message, indexul_din_v);
        concatenate(message, ": ");

        while (lista_de_liste != NULL) {
            int aFostUnCuvantDeLungimeaCurenta = 0;

            LinkedList list_of_words = ((WordList *)(lista_de_liste->data))->listOfWords;

            while (list_of_words != NULL) {
                WordCount* wc = (WordCount*) list_of_words->data;

                if (wc->count <= max_nr_aparitii) {
                    if (aFostUnCuvantDeLungimeaCurenta == 0) {
                        concatenate(message, "(");
                        appendChar(message, ((WordList *)(lista_de_liste->data))->word_length);
                        concatenate(message, ": ");
                        aFostUnCuvantDeLungimeaCurenta = 1;
                        macarUnCuvant = 1;
                    }

                    concatenate(message, wc->word);
                    concatenate(message, "/");
                    appendChar(message, wc->count);

                    if (list_of_words->next != NULL) {
                        concatenate(message, ", ");
                    }
                }

                list_of_words = list_of_words->next;
            }

            lista_de_liste = lista_de_liste->next;

            if (aFostUnCuvantDeLungimeaCurenta == 1) {
                concatenate(message, ")");
            }
        }

        if (macarUnCuvant) {
            unsigned int x = 0;

            for (; x < 100; x++) {
                if (message[x] != ';') {
                    printf("%c", message[x]);
                }
            }

            printf("\n");
        }
    }
}

int compareMultipleCriteria(WordCount* wc1, WordCount* wc2) {
    if (wc1->count < wc2->count) {
        return 1;
    } else if(wc1->count == wc2->count) {
        return strcmp(wc1->word, wc2->word);
    } else {
        return 0;
    }
}

int checkIfListOfWordsExistsByDimension(LinkedList linked_list, WordList* wordList) {
    LinkedList current = linked_list;

    while (current != NULL) {
        WordList* wl1 = (WordList*) current->data;

        if (wl1->word_length == wordList->word_length) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

int checkIfListOfWordsExistsByWord(LinkedList linked_list, WordCount* wc) {
    LinkedList current = linked_list;

    while (current != NULL) {
        WordCount* wc1 = (WordCount*) current->data;

        if (strcmp(wc1->word, wc->word) == 0) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

void appendToEndWithDimension(ListOfLists list_of_lists, void* data) {
    // if the list is empty, just create a new head and return it
    LinkedList nodeToAdd = malloc(sizeof(Node));
    nodeToAdd->data = data;
    nodeToAdd->next = NULL;

    // the new node becomes the head of the list
    if (*list_of_lists == NULL) {
        *list_of_lists = nodeToAdd;
        return;
    }

    if (((WordList*)nodeToAdd->data)->word_length -
    ((WordList*)(*list_of_lists)->data)->word_length < 0) {
        // insert at the beginning
        nodeToAdd->next = *list_of_lists;
        *list_of_lists = nodeToAdd;
        return;
    }

    LinkedList current = *list_of_lists;
    LinkedList prev = NULL;

    while (current != NULL) {
        if (((WordList *)nodeToAdd->data)->word_length -
            ((WordList *)current->data)->word_length < 0) {
            nodeToAdd->next = current;
            prev->next = nodeToAdd;
            return;
        }
        prev = current;
        current = current->next;
    }

    prev->next = nodeToAdd;
}

void appendToEndWithWord(ListOfLists list_of_lists, void* data) {
    // if the list is empty, just create a new head and return it
    LinkedList nodeToAdd = malloc(sizeof(Node));
    nodeToAdd->data = data;
    nodeToAdd->next = NULL;

    // the new node becomes the head of the list
    if (*list_of_lists == NULL) {
        *list_of_lists = nodeToAdd;
        return;
    }

    WordCount* nodeToAddWc = (WordCount*) nodeToAdd->data;
    WordCount* listWc = (WordCount*) (*list_of_lists)->data;

    if (compareMultipleCriteria(nodeToAddWc, listWc) < 0) {
        // the node which we want to add is the smallest, so place it
        // at the beginning
        nodeToAdd->next = *list_of_lists;
        *list_of_lists = nodeToAdd;
        return;
    }

    LinkedList current = *list_of_lists;
    LinkedList prev = NULL;

    while (current != NULL) {
        WordCount* wc = (WordCount*) nodeToAdd->data;
        WordCount* currentWc = (WordCount*) current->data;

        if (compareMultipleCriteria(wc, currentWc) < 0) {
            nodeToAdd->next = current;
            prev->next = nodeToAdd;
            return;
        }
        prev = current;
        current = current->next;
    }

    prev->next = nodeToAdd;
}

void sort(ListOfLists listOfLists) {
    LinkedList head = *listOfLists;

    while (head != NULL) {
        LinkedList min = head;
        LinkedList r = head->next;

        while (r != NULL) {
            if (((WordCount*)(min->data))->count < ((WordCount*)(r->data))->count) {
                min = r;
            }

            r = r->next;
        }

        void* temp = head->data;
        head->data = min->data;
        min->data = temp;

        head = head->next;
    }
}

void insertWord(HashTable* hash_table, char* word) {
    if (strlen(word) < 3) {
        return;
    }

    int index = hash_table->fh(word);
    int word_length = (int) strlen(word);

    WordList* word_list = malloc(sizeof(WordList));
    word_list->listOfWords = NULL;
    word_list->word_length = word_length;

    // check if there is a list of words with the current dimension
    if (hash_table->v[index] == NULL || !checkIfListOfWordsExistsByDimension(hash_table->v[index], word_list)) {
        appendToEndWithDimension(&hash_table->v[index], word_list);
    } else {
        free(word_list);
    }

    ListOfLists list_of_pairs = NULL;

    LinkedList vertical_list = hash_table->v[index];

    while (vertical_list != NULL) {
        if(((WordList*)(vertical_list->data))->word_length == word_length){
            list_of_pairs = &((WordList*)(vertical_list->data))->listOfWords;
            break;
        }
        vertical_list = vertical_list->next;
    }


    WordCount* wc = malloc(sizeof(WordCount));
    wc->word = malloc(word_length + 1);
    wc->count = 1;
    strcpy(wc->word, word);

    if(list_of_pairs == NULL || !checkIfListOfWordsExistsByWord(*list_of_pairs, wc)) {
        appendToEndWithWord(list_of_pairs, wc);
    }
    else {
        LinkedList pairs = *list_of_pairs;

        while (pairs != NULL) {
            WordCount* wc1 = (WordCount*) pairs->data;

            if (strcmp(wc1->word, wc->word) == 0) {
                ((WordCount *)(pairs->data))->count += 1;

                // daca avem niste perechi trebuie sortate
//                sorteazaDacaEsteNecesar(list_of_pairs);
                sort(list_of_pairs);
                break;
            }
            pairs = pairs->next;
        }

        free(wc->word);
        free(wc);
    }
}