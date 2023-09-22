#include <stdio.h>

#define MAX 5

int main()
{
    int queue[MAX];
    int front = 0, rear = 0;

    while (1)
    {
        int choice;
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int item;
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            if ((rear + 1) % MAX == front)
                printf("Queue is full\n");
            else
            {
                queue[rear % MAX] = item;
                rear++;
            }

            break;
        case 2:
            if (front == rear)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Deleted item is %d\n", queue[front % MAX]);
                front++;
            }
        case 3:
            if (front == rear)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue elements are:\n");
                for (int i = front; i < rear; i++)
                {
                    printf("%d\n", queue[i % MAX]);
                }
            }
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }

    return 0;
}