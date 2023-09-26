#include <stdio.h>

void enqueue(int element);
int dequeue();
void display();

void main()
{
    struct queue
    {
        int front, rear;
        int arr[5];
    };

    struct queue q;
    q.front = 0;
    q.rear = -1;

    void equeue(int element)
    {
        if (q.rear == 4)
        {
            printf("queue is full\n");
            return;
        }
        q.arr[++q.rear] = element;
    }
    int dequeue(){
        if(q.front>q.rear){
            printf("queue is empty\n");
            return -1;
        }
        return q.arr[q.front++];
    }
    void display(){
        for(int i=q.front;i<=q.rear;i++){
            printf("%d ",q.arr[i]);
        }
        printf("\n");
    }
    equeue(1);
    equeue(2);
    equeue(3);
    equeue(4);
    equeue(5);
    equeue(6);
    display();
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    display();
}