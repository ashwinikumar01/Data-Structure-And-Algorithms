#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q; /*space for storing elements*/
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int)); /*creating array dynamically in heap*/
}

void display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d", q.Q[i]);
        printf("\n");
    }
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is Full");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Stack is Empty");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int main()
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 4);
    enqueue(&q, 7);
    enqueue(&q, 9);
    enqueue(&q, 11);
    display(q);
    printf("deleted elment = %d\n", dequeue(&q));
    printf("deleted elment = %d\n", dequeue(&q));
    return 0;
}