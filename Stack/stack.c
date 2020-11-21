#include "linkedlist.c"

void stack_ll()
{
    node *first = NULL, *tempnode;
    int op, data, pos, temp;
    printf("Stack ADT.\n");

    while(1)
    {
        printf("0.Exit   1.Push   2.Pop   3.Display   4.Length   5.isEmpty   6.isFull   : ");
        scanf("%d", &op);
        switch(op)
        {
        case 0:
            exit(0);

        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            if(first == NULL)
            {
                first = (node *)malloc(sizeof(node));
                first->data = data;
                first->next = NULL;
            }
            else
                first = insert(first, data, 0);
            break;

        case 2:
            first = remove_node(first, 0);
            break;

        case 3:
            display(first);
            break;

        case 4:
            printf("Length of stack is : %d\n", getlength(first));
            break;

        case 5:
            temp = (getlength(first) > 0) ? 0 : 1;
            printf("isEmpty : %d\n", temp);
            break;

        case 6:
            tempnode = (node *)malloc(sizeof(node));
            temp = (tempnode == NULL) ? 1 : 0;
            printf("isEmpty : %d\n", temp);
            break;
        }
    }
}

int main()
{
    stack_ll();
    return 0;
}
