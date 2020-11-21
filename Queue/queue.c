#include "linkedlist.c"

void que()
{
    printf(" Queue ADT using linked list\n");
    int op, data, pos;
    node *front = NULL, *last = NULL, *temp;

    while(1)
    {
        printf("0.Exit  1.Enqueue  2.Dequeue  3.Display  4.Length  5.isEmpty  6.isFull :  ");
        scanf("%d", &op);
        switch(op)
        {
        case 0:
            exit(0);

        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            last = enqueue(last, data);
            if(front == NULL)
            {
                front = (node *)malloc(sizeof(node));
                front = last;
            }
            break;

        case 2:
            front = remove_node(front, 0);
            break;

        case 3:
            printf("Display queue: ");
            display(front);
            printf("\n");
            break;

        case 4:
            printf("Length of queue: %d\n", getlength(front));
            break;

        case 5:
            pos = (front == last) ? 1 : 0;
            printf("isEmpty: %d", pos);
            break;

        case 6:
            temp = (node *)malloc(sizeof(node));
            pos = (temp == NULL) ? 1 : 0
            printf("isFull : %d", pos);
            free(temp);
            break;

        }
    }
}


int main()
{
    que();
    return 0;
}
