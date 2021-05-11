/*
Name: test_tree.c;
Author: Sameer Koleshwar
Description: Test tree header file.
*/

#include "tree.h"



int main()
{
    create();
    
    printf("\n\npreorder tree traversal\n");
    preorder(root);

    printf("\n\ninorder tree traversal\n");
    inorder(root);

    printf("\n\npostorder tree traversal\n");
    postorder(root);

    return 0;
}