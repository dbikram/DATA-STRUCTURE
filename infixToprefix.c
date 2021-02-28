#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
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
                                case ')':return 1;
                                case '+':
                                case '-':return 2;
                                case '*':
                                case '/':return 3;

                }
}
void main()
{
                char prfx[max],infx[max],ch,discard;
                int i=0,k=0;
                printf("Enter the infix string:");
                scanf("%s",infx);
                push('#');
                strrev(infx); //reversing the infix string
                while((ch=infx[i++])!='\0') //till the end of the infix string
                {
                                if(ch==')') //if ch is right parenthesis
                                                push(ch);
                                else if(isalnum(ch)) //if ch is alphabet or number
                                                prfx[k++]=ch;
                                else if(ch=='(') //if ch is left parenthesis
                                {
                                                while(stack[top]!=')') //till the right parenthesis encountered
                                                                prfx[k++]=pop();
                                                discard=pop();
                                }
                                else
                                {
                                                while(priority(stack[top])>priority(ch))
                                                                prfx[k++]=pop();
                                                push(ch);
                                }
                }
                while(stack[top]!='#') //when the end of the string reached
                                prfx[k++]=pop(); //pop out all the elements
                prfx[k]='\0'; //make it string
                strrev(prfx); //reversing the prefix string
                strrev(infx); //reversing the infix string
                printf("\nPrefix string:%s\n",prfx);

}
