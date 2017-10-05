#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry **entryArray = NULL;

entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    pHead = *(entryArray + lastName[0] - 97);
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
        entryArray = (entry **) malloc(26*sizeof( entry * ));
    }
    e = *(entryArray + lastName[0] - 97);
    if (e == NULL) {
        e = (entry*) malloc(sizeof(entry));
    }
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    *(entryArray + lastName[0] - 97) = e;
    return e;
}
