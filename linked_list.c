#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct list_node {
    int value;
    struct list_node* next;
} list_node;

struct list {
    list_node* head;
    int size;
};

list* list_create(void) {
    list* list = malloc(sizeof(*list));
    list->head = NULL;
    list->size = 0;
    return list;
}

list_node* node_create(int value) {
    list_node* node = malloc(sizeof(*node));
    node->value = value;
    node->next = NULL;
    return node;
}

void list_insert(list* list, int value) {
    list_node* new_node = node_create(value);
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    return;
}

void list_print(list* list) {
    list_node* current = list->head;
    while (current != NULL) {
        printf("Node has value: %d\n", current->value);
        current = current->next;
    }
    return;
}

void list_destroy(list* list) {
    list_node* current = list->head;
    list_node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(list);
    return;
}

int list_size(list* list) {
    return list->size;
}

void list_remove(list* list, int value) {
    list_node* remove = list->head;
    list_node* previous = NULL;
    while (remove != NULL) {
        if (remove->value == value) {
            if (previous == NULL) {
                list->head = remove->next;
            } 
            else {
                previous->next = remove->next;
            }
            free(remove);
            list->size--;
            printf("Removal was successful: %d\n", value);
            return;
        }
        previous = remove;
        remove = remove->next;
    }
    printf("The number suggested was not inside the list: %d\n", value);
    return;
}