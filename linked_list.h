#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct list list;

list* list_create(void);
void list_insert(list* list, int value);
void list_print(list* list);
void list_destroy(list* list);
int list_size(list* list);
void list_remove(list* list, int value);

#endif