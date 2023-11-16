#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

node* createNode(int data){
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insertNode(node** head, int data){
    node* t2 = createNode(data);
    if(*head == NULL){
        *head = (node*)malloc(sizeof(node));
        *head =t2;
        return;
    }
    node* temp = *head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next = t2;
    t2->prev = temp;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        printf("%d \n",temp->data);
        temp=  temp->next;
    }
}

void deleteElement(node** head,int element){
    node* temp = *head; 
    if(temp->data == element){
        *head = temp->next;
        (*head)->prev = NULL;
        return;
    }
    while(temp->next->data!=element){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    
    if(temp->next != NULL)
    temp->next->prev = temp;
}

void main(){
    node *head = NULL;
    insertNode(&head,10);
    insertNode(&head,20);
    insertNode(&head,30);
    display(head);
    deleteElement(&head, 20);
    printf("\n\n\n");
    display(head);

}
