#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
#define HASH_TABLE_SIZE 8707
entry **entryArray = NULL;
entry **entryHeadArray = NULL;

entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    pHead = *(entryHeadArray + hashIndex(lastName));
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* TODO: implement */
    if(entryArray == NULL) {
        entryArray = (entry **) malloc(HASH_TABLE_SIZE*sizeof( entry * ));
        entryHeadArray = (entry **) malloc(HASH_TABLE_SIZE*sizeof( entry * ));
    }
    unsigned int index = hashIndex(lastName);
    e = *(entryArray + index);
    if (*(entryHeadArray + index) == NULL) {
        e = (entry *) malloc(sizeof(entry));
        *(entryHeadArray + index) = e;
    }
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    *(entryArray + index) = e;
    return e;
}

unsigned int hashIndex(char lastName[])
{
    //using BKDR hash function
    unsigned int seed = 31; //get the odd 2^n-1 (n = 6)
    unsigned int index = 0;
    while(*lastName) {
        index = index * seed + (*lastName++);
    }
    return index % HASH_TABLE_SIZE;
}
