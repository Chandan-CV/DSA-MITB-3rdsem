#include <stdio.h>

#define MAX 5

int main()
{
    int queue[MAX];
    int front = -1, rear = -1, count =0;

    while (1)
    {
        
        printf("\n rear: %d, front %d count: %d \n", rear, front,count);
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
            if(rear==-1 && front ==-1){
                rear = (rear+1)%MAX;
                front = (front+1)%MAX;
                queue[rear] = item;
                count++;
                break;
            }
            if(count!=MAX){
                rear = (rear+1)%MAX;
                queue[rear] = item;
                count++;
            }
            else{
                printf("\n lollll queue is full!! \n");
            }
            break;
        case 2:
            if (count ==0)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Deleted item is %d\n", queue[front]);
                front = (front+1)%MAX;
                count--;
            }
        case 3:
            if (count==0)
            {
                printf("Queue is empty\n");
            }
            else
            {
                int x = front;
                printf("Queue elements are:\n");
                for (int i = 0; i <count; i++)
                {
                    printf("%d\n", queue[x]);
                    x = (x+1)%MAX;
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