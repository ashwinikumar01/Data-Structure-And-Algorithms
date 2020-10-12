/*Next place of Rear if it is Front it's Full */

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{

    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d", q.Q[i]);
        printf("\n");
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size); /*till one end of circle doesn't touch the other end*/
}

void enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x;
    if (q->front == q->rear)
    {
        printf("Queue is Empty");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
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
    printf("Deleted elment = %d\n", dequeue(&q));
    printf("Deleted elment = %d\n", dequeue(&q));
}
