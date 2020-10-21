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

void Display(struct Node *p)
{

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int RCount(struct Node *p)
{
    int c = 0;
    if (p != NULL)
        return RCount(p->next) + 1;
    else
        return 0;
}

int main()
{
    int A[] = {3, 5, 7, 9, 11, 13};
    create(A, 6);
    Display(first);
    printf("\n");
    printf("Count = %d", RCount(first));
    return 0;
}