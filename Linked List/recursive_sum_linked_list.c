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

int RAdd(struct Node *p)
{
    int sum = 0;
    if (p != NULL)
        return RAdd(p->next) + p->data;
    else
        return 0;
}

int main()
{
    int A[] = {4, 8, 12, 16, 20, 24};
    create(A, 6);
    printf("Sum = %d", RAdd(first));
    return 0;
}