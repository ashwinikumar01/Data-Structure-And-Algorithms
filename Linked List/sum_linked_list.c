#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Add(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + (p->data);
        p = p->next;
    }
    return (sum);
}

int main()
{
    int A[] = {4, 8, 12, 16, 20, 24};
    create(A, 6);
    printf("Sum = %d", Add(first));
    return 0;
}