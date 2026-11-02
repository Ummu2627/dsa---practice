#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
struct Node *createNode(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;
    return newNode;
}
int height(struct Node *n)
{
    if(n==NULL)
    return 0;
return n->height;
}
int max(int a, int b)
{
    if(a>b)
    return a;
    else
    return b;
}
void updateHeight(struct Node *n)
{
    n->height=1+max(height(n->left),height(n->right));
}
int getBalance(struct Node *n)
{
    if (n==NULL)
    return 0;
    return height(n->left)-height(n->right);
}
struct Node *rightRotate(struct Node *y)
{
    struct Node *x=y->left;
    struct Node *T2=x->right;
    x->right=y;
    y->left=T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}
struct Node* leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}
struct Node *insert(struct Node *root,int key)
{
    if(root==NULL)
    return createNode(key);
    if(key<root->data)
    root->left=insert(root->left,key);
    else if(key>root->data)
    root->right=insert(root->right,key);
    else 
    return root;
    updateHeight(root);
    int balance=getBalance(root);
 /*LL CASE*/
    if(balance>1&& key<root->left->data)
    return rightRotate(root);
 /*RR CASE*/
    if(balance <-1 && key>root->right->data)
    return leftRotate(root);
 /*LR CASE*/
    if(balance >1 && key >root->left->data)
    {
     root->left=leftRotate(root->left);
     return rightRotate(root);
    }
 /*RL CASE*/
    if(balance<-1 && key<root->right->data)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inorder(struct Node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct Node*root=NULL;
    int value,n,i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter the value: ");
        scanf("%d", &value);
        root=insert(root,value);
    }
    printf("Inorder Traversal: ");
    inorder (root);
    return 0;
}
