#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;
void insert(node **root, int data);
node *createNode(int data);
void inorder(node**root);
void postorder(node** root);
void preorder(node** root);
node* search(node* root, int data);
node* searchD(node** root , node* search);
void deleteNode(node** root, int data);

void main() {
    node* root= NULL;
    insert(&root, 30);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 22);
    insert(&root, 35);
    insert(&root, 8);
    insert(&root, 18);
    insert(&root, 32);
    insert(&root, 40);


    printf("%d", root->right->data);
    printf("\ninorder:\n");
    inorder(&root);
    printf("\n\n");
    postorder(&root);
    printf("\n\n");
    preorder(&root);
    printf("\nsearching for element 8:\n");
    int key =15;
    // struct node* result = search(root, key);

    // if (result != NULL)
    //     printf("%d found in the binary tree.\n", key);
    // else
    //     printf("%d not found in the binary tree.\n", key);
    printf("%d",key);
    deleteNode(&root,key);
    printf("\ninorder:\n");
    inorder(&root);
    printf("\n\n");
    
}

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}
void insert(node **root, int data)
{
    if (*root == NULL)
    {
        node *temp = createNode(data);
        *root = temp;
        return;
    }
    if (data < (*root)->data)
        insert(&(*root)->left, data);
    else
        insert(&(*root)->right, data);
}

void inorder(node **root){
    if(*root == NULL){
        return;
    }
    inorder(&(*root)->left);
    printf("%d ",(*root)->data);
    inorder(&(*root)->right);
}
void postorder(node** root){

    if(*root == NULL){
        return;
    }
    postorder(&(*root)->left);
    postorder(&(*root)->right);
    printf("%d ",(*root)->data);

}
void preorder(node** root){

    if(*root == NULL){
        return;
    }
    printf("%d ",(*root)->data);
    preorder(&(*root)->left);
    preorder(&(*root)->right);

}

node* search(node* root, int data){
    if(root==NULL || root->left->data == data||root->right->data){
        return root;
    }


    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}
node* searchD(node** root, node* search){
    // printf("pp");
  if(search==NULL){
        return search;
    }
    if((*root)->left == search){
        node* temp = (*root)->left;
        (*root)->left = NULL;
        return temp;
    }    
    if((*root)->right == search){
        node* temp = (*root)->right;
        (*root)->right = NULL;
        return temp;
    }
}

void insertSubtree(node**root, node* subtree){
    if((subtree) == NULL){
        return;
    }
    insert(root,subtree->data);
    insertSubtree(&(*root), subtree->left);
    insertSubtree(&(*root), subtree->right);
}
void deleteNode(node** root,int data){
    // printf("dd");
    node* result = searchD(root,search(*root,data));
    insertSubtree(root, result->left);
    insertSubtree(root, result->right);
}