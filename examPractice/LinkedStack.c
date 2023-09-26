#include <stdio.h>
#include <stdlib.h>

void push(int element);
void display();
void delete(int element);
void pop();
int peek();
int main()
{
    int top = -1;
    struct node
    {
        int data;
        struct node *next;
    } *head, *currentElement, *tempElement;

    int isFirst = 1;
    void push(int data)
    {
        if (top == -1)
        {
            tempElement = (struct node *)malloc(sizeof(struct node));
            head = tempElement;
            head->data = data;
            head->next = NULL;
            printf("\nfirst element added\n");
            currentElement = head;
            top++;
        }
        else
        {
            tempElement = (struct node *)malloc(sizeof(struct node));
            tempElement->data = data;
            tempElement->next = NULL;
            currentElement->next = tempElement;
            currentElement = currentElement->next;
            top++;
            printf("\n added value :) \n");
        }
    }

    void display()
    {
        int i = 0;
        tempElement = head;
        while (tempElement != NULL)
        {
            printf(" %d \n", tempElement->data);
            tempElement = tempElement->next;
        }
    }

    void delete (int element)
    {
        if (head->data == element)
        {
            printf("deleting first element");
            head = head->next;
            return;
        }
        printf("this is not first element");
        struct node *previousNode = head;
        tempElement = head->next;
        while (tempElement != NULL)
        {

            if (tempElement->data == element)
            {
                previousNode->next = tempElement->next;
                return;
            }
            tempElement = tempElement->next;
            previousNode = previousNode->next;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            printf("\nUNDERFLOWWWWWWWWWWWWWWWWW\n");
            return;
        }
        tempElement = head;
        while (tempElement->next->next != NULL)
        {
            tempElement = tempElement->next;
        }
        tempElement->next = NULL;
        return;
    }

    int peek()
    {
        tempElement = head;
        while (tempElement->next != NULL)
        {
            tempElement = tempElement->next;
        }
        return tempElement->data;
    }
    push(20);
    push(35);
    push(40);
    push(45);
    push(50);
    display();
    printf("peek value: %d\n", peek());
    pop();
    display();
}
