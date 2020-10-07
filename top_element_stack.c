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

int isFull(struct Stack st)
{
  if (st.top==st.size-1)
   return 1;
  return 0;
}

int isEmpty(struct Stack st)
{
   return st.top==-1;   // if condition is true return 1 ,if not return 0
}

int StackTop(struct Stack st)
{
   if(!isEmpty(st))
     return st.S[st.top];
   return -1;  
}

int main() 
{
    struct Stack st;                     // creating object of stack
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    printf("Stack Top = %d\n",StackTop(st));
    Display(st);
    
    return 0;
}