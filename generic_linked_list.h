#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#ifndef _GENERIC_LINKED_LIST_
#define _GENERIC_LINKED_LIST_

/* GHELESEL David-Mihai 311CB*/

typedef struct node {
    void* data;            /* the data stored at that location */
    struct node *next;     /* pointer to the next node in the linked list */
} Node, *LinkedList, **ListOfLists;

#endif