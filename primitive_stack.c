//primitive operations of stack
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct stack
{
                int item[max];
                int top;
}s;
void push(struct stack*,int);
int pop(struct stack*);
void display(struct stack*);
int fullStack(struct stack*);
int emptyStack(struct stack*);
int main()
{
                s.top=-1;
                int x,y,ch;
                while(1)
                {
                                printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:");
                                scanf("%d",&ch);
                                switch(ch)
                                {
                                case 1:
                                                if(!fullStack(&s))
                                                {
                                                                printf("Enter a number to insert into stack:");
                                                                scanf("%d",&x);
                                                                push(&s,x);
                                                }
                                                else
                                                                printf("The stack is full\n");
                                                break;
                                case 2:
                                                if(!emptyStack(&s))
                                                {
                                                                y=pop(&s);
                                                                printf("the popped element is:%d\n",y);
                                                }
                                                else
                                                                printf("The stack is empty\n");
                                                break;
                                case 3:
                                                if(!emptyStack(&s))
                                                {
                                                                printf("The following stack element is:\n");
                                                                display(&s);
                                                }
                                                else
                                                                printf("The stack is empty\n");
                                                break;
                                case 4:
                                                exit(0);
                                default:
                                                printf("Wrong key\n");
                                }
                }
}
int fullStack(struct stack*s)
{
                if(s->top==max-1)
                                return 1;
                else
                                return 0;
}
int emptyStack(struct stack*s)
{
                if(s->top==-1)
                                return 1;
                else
                                return 0;
}
void push(struct stack*s,int x)
{
                s->top++;
                s->item[s->top]=x;
}
int pop(struct stack*s)
{
                int y;
                y=s->item[s->top];
                s->top--;
                return y;
}
void display(struct stack*s)
{
                int i;
                for(i=s->top;i>=0;i--)
                                printf("%d\n",s->item[i]);
}
