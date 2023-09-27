#include <stdio.h>

struct queue
{
    int front, rear;
    int arr[5];
};
struct stack
{
    int top;
    struct queue q1, q2;
};

void enqueue(struct queue q, int element);
int dequeue(struct queue q);
void push(struct stack s, int element);
void pop(struct stack s);
void main()
{
    struct stack s;
    s.q1.front = -1;
    s.q2.front = -1;
    s.q1.rear = -1;
    s.q2.rear = -1;

    push(s, 10);
    push(s, 20);
    push(s, 40);
    push(s, 50);
    push(s, 30);
}

void enqueue(struct queue *q, int element)
{
    if ((*q->front == -1) && (*q->rear == -1))
    {
        q.front = 0;
        q.rear = 0;
        q.arr[q.rear] = element;
        printf("\n added the first element \n");
        printf("rear value of the element: %d", q.rear);

        return;
    }
    if (q.rear >= 5)
    {
        printf("\nOVERFLOWWWWWW\n");
        return;
    }
    printf("rear: %d", q.rear);
    q.arr[q.rear++] = element;
}

int dequeue(struct queue q)
{
    if (q.front > q.rear)
    {
        printf("\n UNDERFLOWWWWW \n");
        return -1;
    }
    q.front++;
    return q.arr[q.front - 1];
}

void push(struct stack s, int element)
{
    if (s.top == 4)
    {
        printf("\nOVERFLOWWWW\n");
        return;
    }
    enqueue(s.q1, element);
    s.top++;
}
void pop(struct stack s)
{
    while (s.q1.front != s.q1.rear)
    {
        enqueue(s.q2, dequeue(s.q1));
    }
    printf("\n pop value is: %d\n", s.q1.arr[s.q1.front]);
    dequeue(s.q1);
    s.top--;
}

void peek(struct stack s)
{
    printf("\n\n\n peek value is: %d\n", s.q1.arr[s.q1.rear]);
}