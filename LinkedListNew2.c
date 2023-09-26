#include <stdio.h>
#include <stdlib.h>
void main()
{
    struct node
    {
        int data;
        struct node *next;
    } *head, *currentElement, *newElement, *previousElement;

    int isFirst = 1;
    void addElement(int element)
    {
        printf("adding the element\n");
        newElement = (struct node *)malloc(sizeof(struct node));
        newElement->data = element;
        newElement->next = NULL;
        if (isFirst)
        {
            printf("adding the first element\n");
            head = newElement;
            currentElement = head;
            isFirst = 0;
            return;
        }
        currentElement->next = newElement;
        currentElement = currentElement->next;
    }

    void display()
    {
        currentElement = head;
        while (currentElement != NULL)
        {
            printf("%p ", currentElement);
            printf("%d \n", currentElement->data);
            currentElement = currentElement->next;
        }
    }

    void deleteElement(int element)
    {
        if (head->data == element)
        {
            head = head->next;
            return;
        }
        currentElement = head->next;
        previousElement = head;
        int isFound = 0;
        while (currentElement != NULL)
        {
            if (currentElement->data == element)
            {
                printf("element found \n");
                currentElement = currentElement->next;
                previousElement->next = currentElement;
                isFound = 1;
                break;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
        if (!isFound)
        {
            printf("element does not exist in the linked list\n");
        }
    }
    addElement(1);
    addElement(2);
    addElement(3);
    display();
    deleteElement(2);
    display();
}
