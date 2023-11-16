#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;

};

typedef struct node node;

node* createNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp-> next = NULL;
    return temp;
}

void addNode(node** head, int data){
    node* newElement = createNode(data);
    if(*head == NULL){
        newElement->next = newElement;
        *head = (node*)malloc(sizeof(node));
        *head = newElement;
        return;
    }
    node *temp = *head;
    while(temp->next!= *head){
        temp = temp->next;
    }
    temp->next = newElement;
    newElement->next = *head;

}

void display(node* head){
    node* temp = head;
    while(temp->next!=head){
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

void deleteNode(node** head, int data){
        node* temp = *head;
        while(temp-> next ->data !=data){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        printf("removed the element\n");
}
void main(){
    printf("hello world");
    node* head = NULL;
    addNode(&head, 10);
    display(head);
    printf("\n\n\n\n");
     addNode(&head, 20);
    display(head);
    printf("\n\n\n\n");
     addNode(&head, 30);
    display(head);
    printf("\n\n\n\n");
     addNode(&head, 40);
    display(head);
    printf("\n\n\n\n");     
    deleteNode(&head, 20);
    display(head);
    printf("\n\n\n\n");
    
}
