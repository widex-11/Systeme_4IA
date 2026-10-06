#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdint.h>

typedef struct LLNODE {
    double value;
    struct LLNODE *next;
} LLNODE_t;

typedef struct LLIST {
    LLNODE_t *head;
    uint32_t size;
} LLIST_t;

void ll_init(LLIST_t *list);
uint32_t ll_size(const LLIST_t *list);

int ll_push_front(LLIST_t *list, double value);
int ll_push_back(LLIST_t *list, double value);

int ll_pop_front(LLIST_t *list, double *value);
int ll_pop_back(LLIST_t *list, double *value);

int ll_find(const LLIST_t *list, double value, uint32_t *position);
int ll_remove_at(LLIST_t *list, uint32_t index, double *value);

double *ll_to_array(const LLIST_t *list, uint32_t *count);
void ll_clear(LLIST_t *list);

#endif
