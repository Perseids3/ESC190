#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c" // How can I use linked_list.h

int main() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->next = NULL;
    print_linked_list(head);
    insert(head, 9);
    insert(head, 1);
    insert(head, 3);
    insert(head, 20);
    print_linked_list(head);
    delete_node(head, 1);
    print_linked_list(head);
    delete_node(head, 0);
    print_linked_list(head);
    free_them_all(head);
    return 0;
}