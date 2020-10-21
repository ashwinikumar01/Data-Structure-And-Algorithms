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

void RDisplay(struct Node *p)
{
    if (p)
    {

        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int main()
{
    int A[] = {3, 5, 7, 9, 11, 13};
    create(A, 6);
    RDisplay(first);
    return 0;
}