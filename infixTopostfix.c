#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 50
char stack[max];
int top=-1;
void push(char elem)
{
                stack[++top]=elem;
}
char pop()
{
                return(stack[top--]);
}
int priority(char elem)
{
                switch(elem)
                {
                                case '#':return 0;
                                case '(':return 1;
                                case '+':
                                case '-':return 2;
                                case '*':
                                case '/':return 3;
                }
}
void main()
{
                char pofx[50],infx[50],ch,discard;
                int i=0,k=0;
                printf("Enter the infix string:");
                scanf("%s",infx);
                push('#');
                while((ch=infx[i++])!='\0')//till the end of the infix string
                {
                                if(ch=='(') //if ch is left parenthesis
                                                push(ch); //then, push it into stack
                                else if(isalnum(ch)) //if ch is alphabet or number
                                                pofx[k++]=ch;
                                else if(ch==')') //if ch is right parenthesis
                                {
                                                while(stack[top]!='(') //till the left parenthesis encountered
                                                                pofx[k++]=pop();
                                                discard=pop(); //discard the left parenthesis
                                }
                                else
                                {
                                                while(priority(stack[top])>=priority(ch))
                                                                pofx[k++]=pop();
                                                push(ch);
                                }
                }
                while(stack[top]!='#') //when the string reached at the end
                                pofx[k++]=pop(); //pop out all the elements
                pofx[k]='\0'; //make it string
                printf("\npostfix expression:%s\n",pofx);
}
