/*
 * Datei:   doublelinkedlist.c
 * Aufgabe: Doppelt verkettete Liste (DLL) fuer double-Werte.
 *          Mit tail und prev braucht keine Operation am Ende eine Schleife.
 * Version: 1.0 (07.10.2026)
 * Lizenz:  GPL
 */

#include <stdlib.h>
#include "doublelinkedlist.h"


/* setzt die Liste auf leer (nur fuer eine neue Liste verwenden) */
void dll_init(DLLIST_t *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}


/* Anzahl der Elemente (mitgezaehlt, darum O(1)) */
uint32_t dll_size(const DLLIST_t *list)
{
  uint32_t ret = list->size;

  return ret;
}


/* fuegt vorne ein - O(1). 0, wenn malloc fehlschlaegt */
int dll_push_front(DLLIST_t *list, double value)
{
  int ret = 0;
  DLLNODE_t *node = malloc(sizeof(DLLNODE_t));

  if (node != NULL)
  {
    node->value = value;
    node->prev = NULL;            /* vorne gibt es keinen Vorgaenger */
    node->next = list->head;

    if (list->head == NULL)
      list->tail = node;          /* Liste war leer: neuer Knoten ist auch das Ende */
    else
      list->head->prev = node;    /* alter erster bekommt einen Vorgaenger */

    list->head = node;
    list->size = list->size + 1;
    ret = 1;
  }
  return ret;
}


/* haengt hinten an - O(1), weil tail direkt auf das Ende zeigt */
int dll_push_back(DLLIST_t *list, double value)
{
  int ret = 0;
  DLLNODE_t *node = malloc(sizeof(DLLNODE_t));

  if (node != NULL)
  {
    node->value = value;
    node->next = NULL;            /* hinten gibt es keinen Nachfolger */
    node->prev = list->tail;

    if (list->tail == NULL)
      list->head = node;          /* Liste war leer: neuer Knoten ist auch der Anfang */
    else
      list->tail->next = node;    /* alter letzter bekommt einen Nachfolger */

    list->tail = node;
    list->size = list->size + 1;
    ret = 1;
  }
  return ret;
}
