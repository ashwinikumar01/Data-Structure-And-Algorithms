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

struct Node *RSearch(struct Node *p, int key)
{
    if (p == NULL)
        return 0;
    if (key == p->data)
        return (p);
    return RSearch(p->next, key);
}

int main()
{
    struct Node *temp;
    int A[] = {10, 12, 14, 45, 29};
    create(A, 5);
    temp = RSearch(first, 12);
    if (temp)
        printf("Key is Found %d\n", temp->data);
    else
        printf("Key Not Found");

    return 0;
}