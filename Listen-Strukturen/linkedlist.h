#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdint.h>

typedef struct LLNODE {
    double value;
    struct LLNODE *next;
} LLNODE_t;

typedef struct LLIST {
    LLNODE_t *head;
    int64_t size;
} LLIST_t;

void ll_init(LLIST_t *list);
int64_t ll_size(const LLIST_t *list);

int64_t ll_push_front(LLIST_t *list, double value);
int64_t ll_push_back(LLIST_t *list, double value);

int64_t ll_pop_front(LLIST_t *list, double *value);
int64_t ll_pop_back(LLIST_t *list, double *value);

int64_t ll_find(const LLIST_t *list, double value, int64_t *position);
int64_t ll_remove_at(LLIST_t *list, int64_t index, double *value);

double *ll_to_array(const LLIST_t *list, int64_t *count);
void ll_clear(LLIST_t *list);

#endif
