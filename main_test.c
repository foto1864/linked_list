#include <stdio.h>
#include "linked_list.h"

int main(void) {
    list* new_list = list_create();

    list_insert(new_list, 10);
    list_insert(new_list, 20);
    list_insert(new_list, 30);
    list_print(new_list);

    printf("The size of the list is: %d\n", list_size(new_list));

    list_remove(new_list, 10);
    list_remove(new_list, 40);
    list_print(new_list);

    list_destroy(new_list);
    
    return 0;
}