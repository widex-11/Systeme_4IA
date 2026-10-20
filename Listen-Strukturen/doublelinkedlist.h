#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdint.h>

typedef struct DLLNODE {
    double value;
    struct DLLNODE *prev;
    struct DLLNODE *next;
} DLLNODE_t;

typedef struct DLLIST {
    DLLNODE_t *head;
    DLLNODE_t *tail;
    int64_t size;
} DLLIST_t;

void dll_init(DLLIST_t *list);
int64_t dll_size(const DLLIST_t *list);

int64_t dll_push_front(DLLIST_t *list, double value);
int64_t dll_push_back(DLLIST_t *list, double value);

int64_t dll_pop_front(DLLIST_t *list, double *value);
int64_t dll_pop_back(DLLIST_t *list, double *value);

int64_t dll_find(const DLLIST_t *list, double value, int64_t *position);
int64_t dll_remove_at(DLLIST_t *list, int64_t index, double *value);

double *dll_to_array(const DLLIST_t *list, int64_t *count);
void dll_clear(DLLIST_t *list);

#endif