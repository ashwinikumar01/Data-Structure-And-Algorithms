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

    // i is started from 1 because already A[0] is created
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int RMaximum(struct Node *p)
{
    int x = 0;
    if (p == NULL)
        return 0;
    x = RMaximum(p->next);
    return x > p->data ? x : p->data;
}

int main()
{

    int A[] = {3, 5, 7, 84, 9, 11, 13};
    create(A, 7);
    printf("%d", RMaximum(first));
    return 0;
}