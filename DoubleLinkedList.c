// doubly linked list

#include<stdio.h>
#include<stdlib.h>
void main(){

struct node{
int data;
struct node *next;
struct node *previous;
}*head, *CurrentElement, *TempElement;

// creation

head = (struct node*)malloc(sizeof(struct node*));
head->data = 0;
head->next = NULL;
head->previous= NULL;

// insertion
int isFirst = 1;

void addElement(int element){
    if(isFirst){
        printf("adding the first element\n");
        head->data = element;
        CurrentElement = head;
        isFirst =0;
        return;
    }
    printf("adding element \n");
    TempElement = (struct node*)malloc(sizeof(struct node*));
    TempElement->data = element;
    TempElement->previous = CurrentElement;
    CurrentElement->next = TempElement;
    TempElement->next = NULL;
    CurrentElement = TempElement;
    return;
}

void traversing(){
printf("\n Traversing and displaying the linkedlist :) \n");
TempElement = head;
while(TempElement!= NULL){
        printf("The element is: %d\n", TempElement->data);
        TempElement = TempElement->next;
}
}

void deletion(int element){
printf("finding the element in the list\n");
TempElement = head;
int isFound =0;
while(TempElement != NULL){
    if(TempElement->data == element){
        printf("Element found!\n");
        isFound =1;
        printf("Deleting it now! \n");
        TempElement->previous->next = TempElement->next;
        break;
    }
    TempElement = TempElement->next;
}
if(!isFound){
    printf("Element not found :(\n");
}
}

addElement(10);
addElement(20);
addElement(500);
traversing();
deletion(20);
traversing();
}
