#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H
struct node{
    int data;
    struct node *next;
};

void insert(struct node *head, int value);
void delete_node(struct node *head, int value);
void free_them_all(struct node*head);
void print_linked_list(struct node *head);



#endif