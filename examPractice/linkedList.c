#include <stdio.h>
#include <stdlib.h>

void addElement();
void display();
void delete(int element);
int main()
{
    struct node
    {
        int data;
        struct node *next;
    } *head, *currentElement, *tempElement;

    int isFirst = 1;
    void addElement(int data)
    {
        if (isFirst)
        {
            tempElement = (struct node *)malloc(sizeof(struct node));
            head = tempElement;
            head->data = data;
            head->next = NULL;
            isFirst = 0;
            printf("\nfirst element added\n");
            currentElement = head;
        }
        else
        {
            tempElement = (struct node *)malloc(sizeof(struct node));
            tempElement->data = data;
            tempElement->next = NULL;
            currentElement->next = tempElement;
            currentElement = currentElement->next;
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
                free(tempElement);
                return;
            }
            tempElement = tempElement->next;
            previousNode = previousNode->next;
        }
    }
    addElement(20);
    addElement(35);
    addElement(89);
    addElement(90);
    display();
    delete (35);
    printf("\n/////////////////\n");
    display();
    return 0;
}
