#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/** getlength
    return: no of nodes present in the linked list
**/
int getlength(node *head)
{
    node *temp;
    temp = head;
    int cnt = 0;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

/** insert
    it will insert a node at given position
**/
node* insert(node *head, int data, int pos)
{
    node *temp, *p;
    int len = getlength(head);
    temp = (node *)malloc(sizeof(node));        // allocate memory to node and place data
    temp->data = data;
    temp->next = NULL;

    // add new node at starting, changes the head
    if(pos == 0)
    {
        temp->next = head;
        head = temp;
    }
    // add node elsewhere
    else if(pos > 0 && pos != len)
    {
        p = head;
        for(int i = 0; i<pos-1; i++)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    // append node at lasts
    else if(pos == len)
    {
        p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
    }
    return head;
}


/** remove_node
    delete node from linked list
**/
node* remove_node(node *head, int pos)
{
    node *temp, *p;
    int data;
    int len = getlength(head);

    if(pos <0 && pos > len)
    {
        printf("Wrong position entered\n");
        exit(0);
    }
    else if(pos == 0)
    {
        temp = head;
        head = head->next;
        data = temp->data;
        free(temp);
    }
    else
    {
        p = head;
        for(int i =0; i<pos-1; i++)
            p = p->next;
        temp = p->next;
        p->next = temp->next;
        data = temp->data;
        free(temp);
    }
    printf("%d is removed\n", data);
    return head;
}


/** display
    print linked list in the forward direction
**/
void display(node *head)
{
    node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
