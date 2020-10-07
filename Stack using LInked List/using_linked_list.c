#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *Top = NULL;

void push(int x)
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

int pop()
{
  struct Node *t; 
  int x = -1;
  if (Top == NULL)
    printf("Stack Underflow....");
  else
  {
    t = Top;
    Top = Top->next;
    x = t->data;
    free(t);
  }
  return x;
}

void Display()
{
  struct Node *p = Top;
  if (p == NULL)
    printf("Nothing to Display....");
  else
  {
    while (p != NULL)
    {
      printf("%d\n", p->data);
      p = p->next;
    }
  }
}

int main()
{
  push(22);
  push(20);
  push(30);
  Display();
  pop();

  printf("After Popping out\n");
  Display();

  return 0;
}
