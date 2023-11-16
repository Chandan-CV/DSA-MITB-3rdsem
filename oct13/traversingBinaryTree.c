#include<stdio.h>
// traversing a binary tree
struct node{
        int data;
        struct node *left;
        struct node *right;
    };
struct node* addLeft(int data, struct node *root){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    root->left = temp;
    return temp;
}
struct node* addRight(int data, struct node *root){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    root->right = temp;
    return temp;
}
void main(){
    struct node *root, *currentRoot;
    // create a binary tree
    root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;
    currentRoot = root;
    currentRoot = addLeft(2, currentRoot);
    

}