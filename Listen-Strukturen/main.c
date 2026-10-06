#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void print_list(const char *text, const LLIST_t *list)
{
    uint32_t count = 0;
    double *array = ll_to_array(list, &count);

    printf("%-16s [", text);

    for (uint32_t i = 0; i < count; i++) {
        printf("%.2f", array[i]);

        if (i + 1 < count)
            printf(", ");
    }

    printf("] size=%u\n", ll_size(list));
    free(array);
}

int main(void)
{
    LLIST_t list;
    double value = 0;
    uint32_t position = 0;

    ll_init(&list);
    print_list("init", &list);

    printf("leer: pop_front=%d pop_back=%d remove_at=%d\n",
           ll_pop_front(&list, &value),
           ll_pop_back(&list, &value),
           ll_remove_at(&list, 0, &value));

    ll_push_front(&list, 2.50);
    ll_push_front(&list, 1.25);
    ll_push_back(&list, 3.75);
    ll_push_back(&list, 5.00);
    print_list("push", &list);

    if (ll_find(&list, 3.75, &position))
        printf("3.75 gefunden an Position %u\n", position);

    printf("9.99 gefunden: %d\n", ll_find(&list, 9.99, NULL));

    ll_remove_at(&list, 1, &value);
    printf("remove_at(1) = %.2f\n", value);
    print_list("remove_at", &list);

    ll_pop_front(&list, &value);
    printf("pop_front = %.2f\n", value);

    ll_pop_back(&list, &value);
    printf("pop_back = %.2f\n", value);
    print_list("pop", &list);

    ll_clear(&list);
    print_list("clear", &list);

    /* TODO: Teil 2 - Benchmark mit clock() */
    /* TODO: dasselbe fuer die DLL */

    return 0;
}
