#include <stdio.h>
#include <stdlib.h>

// linked list adt
typedef struct node
{
    int data;
    struct node *next;
}node;

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

node* insert(node *head, int data, int pos)
{
    node *temp, *p;
    int len = getlength(head);
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if(pos == 0)
    {
        temp->next = head;
        head = temp;
    }
    else if(pos > 0 && pos != len)
    {
        p = head;
        for(int i = 0; i<pos-1; i++)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    else if(pos == len)
    {
        p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
    }
    return head;
}

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


void ll()
{
    node *head = NULL;
    int op, data, pos;

    printf("linked list adt \n");
    while(1)
    {
        printf("0.exit   1.insert   2.delete   3.display   4.length: ");
        scanf("%d", &op);

        switch(op)
        {
        case 0:
            exit(0);

        case 1:
            printf("Enter data and position : ");
            scanf("%d %d", &data, &pos);
            if(head == NULL)
            {
                head = (node *)malloc(sizeof(node));
                head->data = data;
                head->next = NULL;
            }
            else
                head = insert(head, data, pos);

            break;

        case 3:
            display(head);
            printf("\n");
            break;

        case 4:
            printf("length of linked list: %d\n", getlength(head));
            break;

        case 2:
            printf("Enter position to delete start from 0 : ");
            scanf("%d", &pos);
            head = remove_node(head, pos);
            break;
        }
    }
}

int main()
{
    ll();
    return 0;
}
