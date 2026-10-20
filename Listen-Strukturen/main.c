#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <time.h>
#include "doublelinkedlist.h"

void print_list(const char *text, const LLIST_t *list)
{
    int64_t count = 0;
    double *array = ll_to_array(list, &count);

    printf("%-16s [", text);

    for (int64_t i = 0; i < count; i++) {
        printf("%.2f", array[i]);

        if (i + 1 < count)
            printf(", ");
    }

    printf("] size=%lld\n", (long long) ll_size(list));
    free(array);
}



int main(void)
{
    int64_t durchlaeufe = 6767;
    int64_t wiederholungen = 6767;
    int64_t anzahl_mitte = 300;
    int64_t anzahl_hinten = 500;
    clock_t start, end;

    LLIST_t list;
    double value = 0;
    int64_t position = 0;

    ll_init(&list);
    print_list("init", &list);

    printf("leer: pop_front=%lld pop_back=%lld remove_at=%lld\n",
       (long long) ll_pop_front(&list, &value),
       (long long) ll_pop_back(&list, &value),
       (long long) ll_remove_at(&list, 0, &value));

    ll_push_front(&list, 2.50);
    ll_push_front(&list, 1.25);
    ll_push_back(&list, 3.75);
    ll_push_back(&list, 5.00);
    print_list("push", &list);

    if (ll_find(&list, 3.75, &position))
        printf("3.75 gefunden an Position %lld\n", (long long) position);

    printf("9.99 gefunden: %lld\n", (long long) ll_find(&list, 9.99, NULL));

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

    //zeiterfassung
    start = clock();
    for (int64_t a=0; a<wiederholungen; a++) {
        for (int64_t i=0; i<durchlaeufe; i++) {
            ll_push_front(&list, (double) i);
        }
        ll_clear(&list);
        
    }
    end = clock();

    double push_front = (double)(end - start) / CLOCKS_PER_SEC / wiederholungen;
    printf("push_front: %.6f s pro Wiederholung\n", push_front);

    double push_alle = (double)(end - start) / CLOCKS_PER_SEC;
    printf("push_alle: %.6f s\n", push_alle);

    start = clock();
    for (int64_t a=0;a<wiederholungen; a++) {
        for (int64_t i=0; i<durchlaeufe; i++) {
            ll_push_back(&list, (double) i);
        }
        ll_clear(&list);
    }
    end = clock();
    double zeit_back = (double)(end - start) / CLOCKS_PER_SEC;

    printf("push_back %.6f s pro Wiederholung\n", zeit_back);


    for (int64_t i = 0; i < anzahl_mitte; i = i + 1) {
        ll_push_front(&list, (double) i);
    }

    start = clock();
    for (int64_t i = 0; i < anzahl_mitte; i = i + 1) {
        ll_find(&list, (double) (anzahl_mitte / 2), NULL);
    }
    end = clock();

    double zeit_find = (double)(end - start) / CLOCKS_PER_SEC;

    ll_clear(&list);

    for (int64_t i = 0; i < durchlaeufe; i = i + 1) {
        ll_push_front(&list, (double) i);
    }

    start = clock();
    for (int64_t i = 0; i < durchlaeufe; i = i + 1) {
        ll_pop_front(&list, NULL);
    }
    end = clock();

    double zeit_pop_front = (double)(end - start) / CLOCKS_PER_SEC;

    for (int64_t i = 0; i < anzahl_hinten; i = i + 1) {
        ll_push_front(&list, (double) i);

    }

    start = clock();
    for (int64_t i = 0; i < anzahl_hinten; i = i + 1) {
        ll_pop_back(&list, NULL);


    }
    end = clock();

    double zeit_pop_back = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n%-34s %10s\n", "Szenario", "LL (s)");
    printf("\n");
    printf("%-34s %10.6f\n", "vorne einfuegen (pro Wdh.)  O(1)", push_front);
    printf("%-34s %10.6f\n", "hinten einfuegen            O(n)", zeit_back);
    printf("%-34s %10.6f\n", "in der Mitte suchen         O(n)", zeit_find);
    printf("%-34s %10.6f\n", "vorne entfernen             O(1)", zeit_pop_front);
    printf("%-34s %10.6f\n", "hinten entfernen            O(n)", zeit_pop_back);
    printf("\n");

    printf("Double Linked List: \n");
    





    return 0;
}