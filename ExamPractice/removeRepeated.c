#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;
node* createNode(int data);
void insert(node** head, int element);
void display(node* head);
void removeRepeated(node** head);

void main(){
node* head =  NULL;
insert(&head, 10);
insert(&head, 50);
insert(&head, 50);
insert(&head, 50);
insert(&head, 50);
insert(&head, 50);
insert(&head, 50);
insert(&head, 50);
insert(&head, 50);
insert(&head, 50);
insert(&head, 10);
insert(&head, 30);
insert(&head, 10);
insert(&head, 30);
insert(&head, 10);
insert(&head, 40);
insert(&head, 10);
insert(&head, 40);
insert(&head, 20);

display(head);

removeRepeated(&head);
printf("\n\n\n \n\n");
display(head);



}

void removeRepeated(node **head){
    node *i = *head;
    while(i!=NULL){
        node* j = i;
        while(j->next!= NULL){
            if(i->data == j->next->data){
                j->next = j->next->next;
            }
            else{
            j = j->next;}
        }
        i = i->next;
    }
}

node* createNode(int data){
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
}


void insert(node** head, int element){
    node* temp = *head;
    node* newNode = createNode(element);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void display(node* head){
    node* temp = head;
    while(temp!= NULL){
        printf("%d\n", temp->data);
        temp= temp->next;
    }
}