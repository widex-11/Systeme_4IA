#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "linkedlist.h"
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

void print_dll(const char *text, const DLLIST_t *list)
{
    int64_t count = 0;
    double *array = dll_to_array(list, &count);

    printf("%-16s [", text);

    for (int64_t i = 0; i < count; i++) {
        printf("%.2f", array[i]);

        if (i + 1 < count)
            printf(", ");
    }

    printf("] size=%lld\n", (long long) dll_size(list));
    free(array);
}

double sekunden(clock_t start, clock_t end)
{
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(void)
{
    int64_t durchlaeufe = 10000;
    int64_t wiederholungen = 4000;
    int64_t anzahl_vorne = 1000000;
    int64_t anzahl_mitte = 20000;
    int64_t anzahl_hinten = 22000;
    clock_t start, end;

    LLIST_t list;
    DLLIST_t dlist;
    double value = 0;
    int64_t position = 0;

    double ll_zeit_front, ll_zeit_back, ll_zeit_find, ll_zeit_pop_front, ll_zeit_pop_back;
    double dll_zeit_front, dll_zeit_back, dll_zeit_find, dll_zeit_pop_front, dll_zeit_pop_back;

    setvbuf(stdout, NULL, _IONBF, 0);

    printf("===== TEIL 1: Validierung Linked List =====\n\n");

    ll_init(&list);
    print_list("init", &list);

    printf("leer: pop_front=%lld pop_back=%lld remove_at=%lld\n",
       (long long) ll_pop_front(&list, &value),
       (long long) ll_pop_back(&list, &value),
       (long long) ll_remove_at(&list, 0, &value));

    ll_push_front(&list, 2.50);
    print_list("push_front 2.50", &list);
    ll_push_front(&list, 1.25);
    print_list("push_front 1.25", &list);
    ll_push_back(&list, 3.75);
    print_list("push_back 3.75", &list);
    ll_push_back(&list, 5.00);
    print_list("push_back 5.00", &list);

    if (ll_find(&list, 3.75, &position))
        printf("3.75 gefunden an Position %lld\n", (long long) position);

    printf("9.99 gefunden: %lld\n", (long long) ll_find(&list, 9.99, NULL));

    ll_remove_at(&list, 1, &value);
    printf("remove_at(1) = %.2f\n", value);
    print_list("remove_at", &list);

    printf("remove_at(99) = %lld (ungueltiger Index)\n", (long long) ll_remove_at(&list, 99, &value));
    print_list("unveraendert", &list);

    ll_pop_front(&list, &value);
    printf("pop_front = %.2f\n", value);
    print_list("pop_front", &list);

    ll_pop_back(&list, &value);
    printf("pop_back = %.2f\n", value);
    print_list("pop_back", &list);

    ll_pop_back(&list, &value);
    printf("pop_back = %.2f (letztes Element)\n", value);
    print_list("leer", &list);

    ll_push_back(&list, 7.70);
    ll_push_back(&list, 8.80);
    print_list("zwei neue", &list);
    ll_clear(&list);
    print_list("clear", &list);

    printf("\n===== TEIL 1: Validierung Double Linked List =====\n\n");

    dll_init(&dlist);
    print_dll("init", &dlist);

    printf("leer: pop_front=%lld pop_back=%lld remove_at=%lld\n",
       (long long) dll_pop_front(&dlist, &value),
       (long long) dll_pop_back(&dlist, &value),
       (long long) dll_remove_at(&dlist, 0, &value));

    dll_push_front(&dlist, 2.50);
    print_dll("push_front 2.50", &dlist);
    dll_push_front(&dlist, 1.25);
    print_dll("push_front 1.25", &dlist);
    dll_push_back(&dlist, 3.75);
    print_dll("push_back 3.75", &dlist);
    dll_push_back(&dlist, 5.00);
    print_dll("push_back 5.00", &dlist);

    if (dll_find(&dlist, 3.75, &position))
        printf("3.75 gefunden an Position %lld\n", (long long) position);

    printf("9.99 gefunden: %lld\n", (long long) dll_find(&dlist, 9.99, NULL));

    dll_remove_at(&dlist, 1, &value);
    printf("remove_at(1) = %.2f\n", value);
    print_dll("remove_at", &dlist);

    printf("remove_at(99) = %lld (ungueltiger Index)\n", (long long) dll_remove_at(&dlist, 99, &value));
    print_dll("unveraendert", &dlist);

    dll_pop_front(&dlist, &value);
    printf("pop_front = %.2f\n", value);
    print_dll("pop_front", &dlist);

    dll_pop_back(&dlist, &value);
    printf("pop_back = %.2f\n", value);
    print_dll("pop_back", &dlist);

    dll_pop_back(&dlist, &value);
    printf("pop_back = %.2f (letztes Element)\n", value);
    print_dll("leer", &dlist);

    dll_push_back(&dlist, 7.70);
    dll_push_back(&dlist, 8.80);
    print_dll("zwei neue", &dlist);
    dll_clear(&dlist);
    print_dll("clear", &dlist);

    printf("\n===== TEIL 2: Benchmark =====\n\n");
    printf("Messung laeuft, bitte warten ...\n");

    start = clock();
    for (int64_t a = 0; a < wiederholungen; a = a + 1) {
        for (int64_t i = 0; i < durchlaeufe; i = i + 1) {
            ll_push_front(&list, (double) i);
        }
        ll_clear(&list);
    }
    end = clock();
    ll_zeit_front = sekunden(start, end);

    start = clock();
    for (int64_t a = 0; a < wiederholungen; a = a + 1) {
        for (int64_t i = 0; i < durchlaeufe; i = i + 1) {
            dll_push_front(&dlist, (double) i);
        }
        dll_clear(&dlist);
    }
    end = clock();
    dll_zeit_front = sekunden(start, end);

    start = clock();
    for (int64_t i = 0; i < anzahl_hinten; i = i + 1) {
        ll_push_back(&list, (double) i);
    }
    end = clock();
    ll_zeit_back = sekunden(start, end);

    start = clock();
    for (int64_t i = 0; i < anzahl_hinten; i = i + 1) {
        dll_push_back(&dlist, (double) i);
    }
    end = clock();
    dll_zeit_back = sekunden(start, end);

    start = clock();
    for (int64_t i = 0; i < anzahl_hinten; i = i + 1) {
        ll_pop_back(&list, NULL);
    }
    end = clock();
    ll_zeit_pop_back = sekunden(start, end);

    start = clock();
    for (int64_t i = 0; i < anzahl_hinten; i = i + 1) {
        dll_pop_back(&dlist, NULL);
    }
    end = clock();
    dll_zeit_pop_back = sekunden(start, end);

    for (int64_t i = 0; i < anzahl_mitte; i = i + 1) {
        ll_push_front(&list, (double) i);
        dll_push_front(&dlist, (double) i);
    }

    start = clock();
    for (int64_t i = 0; i < anzahl_mitte; i = i + 1) {
        ll_find(&list, (double) (anzahl_mitte / 2), NULL);
    }
    end = clock();
    ll_zeit_find = sekunden(start, end);

    start = clock();
    for (int64_t i = 0; i < anzahl_mitte; i = i + 1) {
        dll_find(&dlist, (double) (anzahl_mitte / 2), NULL);
    }
    end = clock();
    dll_zeit_find = sekunden(start, end);

    ll_clear(&list);
    dll_clear(&dlist);

    for (int64_t i = 0; i < anzahl_vorne; i = i + 1) {
        ll_push_front(&list, (double) i);
        dll_push_front(&dlist, (double) i);
    }

    start = clock();
    for (int64_t i = 0; i < anzahl_vorne; i = i + 1) {
        ll_pop_front(&list, NULL);
    }
    end = clock();
    ll_zeit_pop_front = sekunden(start, end);

    start = clock();
    for (int64_t i = 0; i < anzahl_vorne; i = i + 1) {
        dll_pop_front(&dlist, NULL);
    }
    end = clock();
    dll_zeit_pop_front = sekunden(start, end);

    ll_clear(&list);
    dll_clear(&dlist);

    printf("\n%-40s %12s %10s %10s\n", "Szenario", "N", "LL (s)", "DLL (s)");
    printf("\n");
    printf("%-40s %5lldx%-6lld %10.3f %10.3f\n", "vorne einfuegen        LL O(1) DLL O(1)",
           (long long) wiederholungen, (long long) durchlaeufe, ll_zeit_front, dll_zeit_front);
    printf("%-40s %12lld %10.3f %10.3f\n", "hinten einfuegen       LL O(n) DLL O(1)",
           (long long) anzahl_hinten, ll_zeit_back, dll_zeit_back);
    printf("%-40s %12lld %10.3f %10.3f\n", "in der Mitte suchen    LL O(n) DLL O(n)",
           (long long) anzahl_mitte, ll_zeit_find, dll_zeit_find);
    printf("%-40s %12lld %10.3f %10.3f\n", "vorne entfernen        LL O(1) DLL O(1)",
           (long long) anzahl_vorne, ll_zeit_pop_front, dll_zeit_pop_front);
    printf("%-40s %12lld %10.3f %10.3f\n", "hinten entfernen       LL O(n) DLL O(1)",
           (long long) anzahl_hinten, ll_zeit_pop_back, dll_zeit_pop_back);
    printf("\n");



    return 0;
}