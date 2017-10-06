#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry **entryArray = NULL;
entry **entryHeadArray = NULL;

entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    pHead = *(entryHeadArray + lastName[0] - 'a');
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
        entryHeadArray = (entry **) malloc(26*sizeof( entry * ));
    }
    e = *(entryArray + lastName[0] - 'a');
    if (*(entryHeadArray + lastName[0] - 'a') == NULL) {
        e = (entry *) malloc(sizeof(entry));
        *(entryHeadArray + lastName[0] - 'a') = e;
    }
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    *(entryArray + lastName[0] - 'a') = e;
    return e;
}
