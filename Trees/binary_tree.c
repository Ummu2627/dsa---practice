#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(char value)
{
    struct Node *newNode =malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void inorder(struct Node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}
void preorder(struct Node *root)
{
    if(root==NULL)
    return;
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}
int main()
{
    struct Node*root= createNode('A');
    root->left=createNode('B');
    root->right=createNode('C');
    root->left->left=createNode('D');
    root->left->right=createNode('E');
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    return 0;
}
