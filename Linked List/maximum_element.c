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

int Maximum(struct Node *p)
{
    int max = -1;
    while (p != NULL)
    {
        if (p->data > max)
        
            max = p->data;
            p = p->next;
        
    }
    return max;
}

int main()
{

    int A[] = {3, 5, 7,84, 9, 11, 13};
    create(A, 7);
    printf("%d", Maximum(first));
    return 0;
}