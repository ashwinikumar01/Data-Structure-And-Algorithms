#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *Top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack Overflow....");
    else
    {
        t->next = Top;
        t->data = x;
        Top = t;
    }
}

char pop()
{
    struct Node *t;
    char x = -1;
    if (Top == NULL)
    {
        printf("Stack Underflow");
    }
    else
    {
        t = Top;
        Top = Top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int isBalanced(char *exp)
{
    int i;
    for (i=0;exp[i]!='\0';i++)
    {
        if (exp[i] == '(')
            push(exp[i]);

        else if (exp[i] == ')')
        {
            if (Top == NULL)
                return 0;
            pop();
        }
    }
    if (Top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "(a+b)*(c-d)";
    printf("%d", isBalanced(exp));
    return 0;
}