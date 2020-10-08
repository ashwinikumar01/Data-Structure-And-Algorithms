#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
};

struct Node *Top=NULL;

void push(char x)
{
  struct Node *t;
  t=(struct Node *)malloc(sizeof(struct Node));

  if(t==NULL)
   printf("Stack Overflow");

   else
   {
       t->data=x;
       t->next=Top;
       Top=t;
   }
   
}

char pop()
{   
    struct Node *t;
    char x=-1;

    if(Top==NULL)
     printf("Stack Underflow");

    else
    {
        t=Top;
        Top=Top->next;
        x=t->data;
        free(t);
    }
    return x;
}

/*precedence +,-,*,\*/

int precedence(char x)
{
    if(x=='+' || x=='-')
      return 1;
    else if (x=='*' || x=='/')
      return 2;

    return 0;
}

/*checking operand = a,b,c*/

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/') 
      return 0;
    else
      return 1;
    
}

char *InfixToPostfix(char *infix)
{
   int i=0, j=0;
   char *postfix;
   double len=strlen(infix);
   postfix=(char *)malloc((len+1)*sizeof(char));
   
   while(infix[i]!='\0')
   {
       if(isOperand(infix[i]))
         postfix[j++]=infix[i++];
       else
       {
           if(precedence(infix[i])>precedence(Top->data))
               push(infix[i++]);
           else
           {
               postfix[j++]=pop();
           }
       }
   }
   while(Top!=NULL)
     postfix[j++]=pop();
   postfix[j]='\0';
   return postfix;
}

int main()
{
    char *infix="a+b*c";
    push('#');
    char *postfix=InfixToPostfix(infix);
    printf("%s",postfix);
    return 0;

}