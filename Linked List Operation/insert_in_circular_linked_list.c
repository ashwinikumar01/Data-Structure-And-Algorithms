#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// using do while for moving circularly
void Display(struct Node *h)
{
    do
    {

        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
}

int Length(struct Node *p)
{
    int l = 0;
    do
    {
        l++;
        p = p->next;
    } while (p != Head);
    return l;
}

void Insert(struct Node *h, int index, int x)
{
    int i;
    struct Node *t;

    if (index < 0 || index > Length())
        return;

    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        //if it is the first node
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while (h->next != Head)
                h = h->next;

            h->next = t;
            Head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            h = h->next;
            t->next = h->next;
            h->next = t;
        }
    }
}

int main()
{
    int A[] = {3, 5, 7, 9, 13};
    create(A, 5);
    Insert(Head, 2, 56);
    Display(Head);
    return 0;
}
