/*Using Linear Search*/

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

struct Node *LSearch(struct Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
            return (p); //if key= p->data we are returning address of that point
        p = p->next;
    }
    return NULL;
}

int main()
{
    struct Node *temp;
    int A[] = {12, 15, 17, 19, 10};
    create(A, 5);
    temp = LSearch(first, 15);
    if (temp)
    {
        printf("Key is Found = %d\n", temp->data);
    }
    else
    {
        printf("Key Not Found");
    }

    return 0;
}