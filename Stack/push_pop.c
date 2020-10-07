//using array//
#include<stdio.h>
#include<stdlib.h>

struct Stack
{
  int size;
  int top;
  int *S;                           /*array for storing elements*/
};

void create(struct Stack *st)
{
    printf("Enter size = ");
    scanf("%d",&st->size);       
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));      /*creating array dynamically in heap for storing elements*/
}

void Display(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        printf("%d ",st.S[i]);                   /*since value are in array*/
    }
}

void push(struct Stack *st, int x)
{
   if(st->top == st->size-1)
   {
       printf("Stack Overflow\n");
   }
   else
   {
       st->top++;
       st->S[st->top]=x;
   }
   
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1) 
    {
       printf("Stack Underflow\n ");
    }
    else  
    {
      x=st->S[st->top];
      st->top--;
    }
    return x;   
}

int main() 
{
    struct Stack st;                     // creating object of stack
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    printf("Pop = %d\n",pop(&st));
    printf("Pop = %d\n",pop(&st));
    printf("Pop = %d\n",pop(&st));
    Display(st);
    
    return 0;
}