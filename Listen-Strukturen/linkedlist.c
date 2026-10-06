#include <stdlib.h>
#include "linkedlist.h"

void ll_init(LLIST_t *list)
{
    list->head = NULL;
    list->size = 0;
}

uint32_t ll_size(const LLIST_t *list)
{
    return list->size;
}

int ll_push_front(LLIST_t *list, double value)
{
    LLNODE_t *node = malloc(sizeof(LLNODE_t));

    if (node == NULL)
        return 0;

    node->value = value;
    node->next = list->head;
    list->head = node;
    list->size++;

    return 1;
}

int ll_push_back(LLIST_t *list, double value)
{
    LLNODE_t *node = malloc(sizeof(LLNODE_t));

    if (node == NULL)
        return 0;

    node->value = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        LLNODE_t *current = list->head;

        while (current->next != NULL)
            current = current->next;

        current->next = node;
    }

    list->size++;
    return 1;
}

int ll_pop_front(LLIST_t *list, double *value)
{
    LLNODE_t *node = list->head;

    if (node == NULL)
        return 0;

    if (value != NULL)
        *value = node->value;

    list->head = node->next;
    free(node);
    list->size--;

    return 1;
}

int ll_pop_back(LLIST_t *list, double *value)
{
    LLNODE_t *current = list->head;

    if (current == NULL)
        return 0;

    if (current->next == NULL) {
        if (value != NULL)
            *value = current->value;

        free(current);
        list->head = NULL;
    } else {
        while (current->next->next != NULL)
            current = current->next;

        if (value != NULL)
            *value = current->next->value;

        free(current->next);
        current->next = NULL;
    }

    list->size--;
    return 1;
}

int ll_find(const LLIST_t *list, double value, uint32_t *position)
{
    const LLNODE_t *current = list->head;
    uint32_t index = 0;

    while (current != NULL) {
        if (current->value == value) {
            if (position != NULL)
                *position = index;
            return 1;
        }

        current = current->next;
        index++;
    }

    return 0;
}

int ll_remove_at(LLIST_t *list, uint32_t index, double *value)
{
    LLNODE_t *current;
    LLNODE_t *node;

    if (index >= list->size)
        return 0;

    if (index == 0)
        return ll_pop_front(list, value);

    current = list->head;

    for (uint32_t i = 0; i < index - 1; i++)
        current = current->next;

    node = current->next;

    if (value != NULL)
        *value = node->value;

    current->next = node->next;
    free(node);
    list->size--;

    return 1;
}

double *ll_to_array(const LLIST_t *list, uint32_t *count)
{
    double *array = NULL;
    const LLNODE_t *current = list->head;

    *count = 0;

    if (list->size == 0)
        return NULL;

    array = malloc(list->size * sizeof(double));

    if (array == NULL)
        return NULL;

    for (uint32_t i = 0; i < list->size; i++) {
        array[i] = current->value;
        current = current->next;
    }

    *count = list->size;
    return array;
}

void ll_clear(LLIST_t *list)
{
    while (list->head != NULL)
        ll_pop_front(list, NULL);
}
