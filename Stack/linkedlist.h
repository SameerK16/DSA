#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct node
{
    int data;
    struct node *next;
}node;

int getlength(node *head);
node* insert(node *head, int data, int pos);
node* remove_node(node *head, int pos);
void display(node *head);


#endif // LINKEDLIST_H_INCLUDED
