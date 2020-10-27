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

//Linear Display
void Display(struct Node *h)
{
    int i;
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
}

//Recursive Display
void RDisplay(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    create(A, 5);
    Display(Head);
    printf("\n");
    RDisplay(Head);
    return 0;
}