/*
Name: tree.h
Author: Sameer Koleshwar
Description: tree implementation using queue, queue is created using linked list
*/


#include <stdio.h>
#include <stdlib.h>

// node structure for element of tree.
typedef struct node
{
    struct node *lchild, *rchild;
    int data;
}node;
node *root;

// node structure for queue
typedef struct queue_node
{
    node* data;
    struct queue_node *next;
}qnode;
qnode *first = NULL, *last = NULL;

// allocate space for new queue node
qnode* new_qnode(node *t)
{
    qnode *temp = (qnode *)malloc(sizeof(qnode));
    temp->data = t;
    temp->next = NULL;
    return temp;
}

// enqueue the element in the queue
void enqueue(node *t)
{
    // if there are no elements in the queue
    if(first == 0)
    {
        first = (qnode *)malloc(sizeof(qnode));
        first->data = t;
        first->next = NULL;
        last = first;
    }
    else
    {
        qnode* k=(qnode*)malloc(sizeof(qnode)) ;
        k->data=t;
        k->next=0;
        last->next=k;
        last=k;
    }
}

// count no of elements in the queue
int count()
{
    int cnt = 0;
    qnode *temp = first;
    while(temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

// dequeue funtion, will return the tree node address
node* dequeue()
{
    qnode *temp = first;
    first = first->next;
    return temp->data;
}

// allocate space to new element of tree.
node* newNode(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

// take the lchild and rchild of temp element of tree
void getchildren(node *temp)
{
    int x;

    // read the lchild, if user enters -1 then it is NULL
    // and enqueue the node in the queue
    printf("enter the lchild of %d: ", temp->data);
    scanf("%d", &x);
    if(x != -1)
    {
        temp->lchild = newNode(x);
        enqueue(temp->lchild);
    }

    // similarly read the rchild
    printf("enter the rchild of %d: ", temp->data);
    scanf("%d", &x);
    if(x != -1)
    {
        temp->rchild = newNode(x);
        enqueue(temp->rchild);
    }

}

// create a tree
void create()
{
    int x;
    node *temp;

    // take data input from the user, for root node
    printf("enter the root value: ");
    scanf("%d", &x);
    root = newNode(x);

    // enqueue root in the queue
    enqueue(root);

    // while loop will run till, queue is not empty
    while(count()>0)
    {
        // dequeue tree node from the queue
        temp = dequeue();
        // take the children for the tree node extracted
        getchildren(temp);

    }
}

// display data in preorder tree travsal
void preorder(node *temp)
{
    if(temp == NULL)
        return;
    printf("%d ", temp->data);
    preorder(temp->lchild);
    preorder(temp->rchild);
}

// display data in postorder tree travsal
void postorder(node *temp)
{
    if(temp == NULL)
        return;
    postorder(temp->lchild);
    postorder(temp->rchild);
    printf("%d ", temp->data);
}

// display data in inorder tree travsal
void inorder(node *temp)
{
    if(temp == NULL)
        return;
    inorder(temp->lchild);
    printf("%d ", temp->data);
    inorder(temp->rchild);
}

