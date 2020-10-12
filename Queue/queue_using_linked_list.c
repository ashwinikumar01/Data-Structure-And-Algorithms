#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Queue Full\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;

        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *p;
    if (front == NULL)
    {
        printf("Queue Empty");
    }
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void Display()
{
    struct Node *p=front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();
   printf("%d ",dequeue()) ;
   printf("%d",dequeue()) ;
    return 0;
}
