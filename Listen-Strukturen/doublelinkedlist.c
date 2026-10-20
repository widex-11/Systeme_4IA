#include <stdlib.h>
#include "doublelinkedlist.h"

void dll_init(DLLIST_t *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int64_t dll_size(const DLLIST_t *list)
{
    return list->size;
}

int64_t dll_push_front(DLLIST_t *list, double value)
{
    DLLNODE_t *node = malloc(sizeof(DLLNODE_t));
    if (node == NULL)
        return 0;

    node->value = value;
    node->prev = NULL;
    node->next = list->head;

    if (list->head != NULL)
        list->head->prev = node;
    else
        list->tail = node;

    list->head = node;
    list->size++;
    return 1;
}

int64_t dll_push_back(DLLIST_t *list, double value)
{
    DLLNODE_t *node = malloc(sizeof(DLLNODE_t));
    if (node == NULL)
        return 0;

    node->value = value;
    node->next = NULL;
    node->prev = list->tail;

    if (list->tail != NULL)
        list->tail->next = node;
    else
        list->head = node;

    list->tail = node;
    list->size++;
    return 1;
}

int64_t dll_pop_front(DLLIST_t *list, double *value)
{
    DLLNODE_t *node = list->head;
    if (node == NULL)
        return 0;

    if (value != NULL)
        *value = node->value;

    list->head = node->next;
    if (list->head != NULL)
        list->head->prev = NULL;
    else
        list->tail = NULL;

    free(node);
    list->size--;
    return 1;
}

int64_t dll_pop_back(DLLIST_t *list, double *value)
{
    DLLNODE_t *node = list->tail;
    if (node == NULL)
        return 0;

    if (value != NULL)
        *value = node->value;

    list->tail = node->prev;
    if (list->tail != NULL)
        list->tail->next = NULL;
    else
        list->head = NULL;

    free(node);
    list->size--;
    return 1;
}

int64_t dll_find(const DLLIST_t *list, double value, int64_t *position)
{
    const DLLNODE_t *current = list->head;
    int64_t index = 0;

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

int64_t dll_remove_at(DLLIST_t *list, int64_t index, double *value)
{
    DLLNODE_t *node;

    if (index < 0 || index >= list->size)
        return 0;

    if (index == 0)
        return dll_pop_front(list, value);
    if (index == list->size - 1)
        return dll_pop_back(list, value);

    node = list->head;
    for (int64_t i = 0; i < index; i++)
        node = node->next;

    if (value != NULL)
        *value = node->value;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(node);
    list->size--;
    return 1;
}

double *dll_to_array(const DLLIST_t *list, int64_t *count)
{
    double *array = NULL;
    const DLLNODE_t *current = list->head;

    *count = 0;
    if (list->size == 0)
        return NULL;

    array = malloc(list->size * sizeof(double));
    if (array == NULL)
        return NULL;

    for (int64_t i = 0; i < list->size; i++) {
        array[i] = current->value;
        current = current->next;
    }

    *count = list->size;
    return array;
}

void dll_clear(DLLIST_t *list)
{
    while (list->head != NULL)
        dll_pop_front(list, NULL);
}