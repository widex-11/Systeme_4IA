//
// Created by Maxi on 07.10.2026.
//

#ifndef LISTEN_STRUKTUREN_DOUBLELINKEDLIST_H
#define LISTEN_STRUKTUREN_DOUBLELINKEDLIST_H

#include <stdlib.h>
#include <stdint.h>

typedef struct DLLNODE {
    double value;
    struct DLLNODE_t *prev;
    struct DLLNODE_t *next;
}DLLNODE_t;

typedef struct DLLLIST {
    DLLNODE_t *head;
    DLLNODE_t *tail;
    unit32_t size;
}DLLLIST_t;


void dll_init(DLLLIST_t *list);
uint32_t  dll_size(const DLLIST_t *list);


















#endif //LISTEN_STRUKTUREN_DOUBLELINKEDLIST_H

