/*Simultaneously we can use program if there are no elements
by using Insert(first,-2,19); Display(first); */

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

int count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void Insert(struct Node *p, int index, int x)
{
    int i;
    struct Node *t;
    if (index < 0 || index > count(p))
    {
        printf("Element can\'t be inserted at this location ");
    }

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)

            p = p->next;
        t->next = p->next;
        p->next = t;

        printf("Element Inserted\n");
    }
}

int main()
{
    int A[] = {13, 33, 10, 78, 45};
    create(A, 5);
    Insert(first, 5, 2);
    Display(first);
    printf("\n");
    printf("Count = %d ", count(first));

    return 0;
}
