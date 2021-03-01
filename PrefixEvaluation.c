//program to find the evaluation of prefix expression
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int stack[50];
int top=-1;
void push(int x)
{
                stack[++top]=x;
}
int pop()
{
                return(stack[top--]);
}
void main()
{
                char prfx[50],*e;
                int op1,op2,res,num;
                printf("Enter the prefix expression:");
                gets(prfx);
                strrev(prfx); //reversing the prefix string
                e=prfx;
                while(*e!='\0') //till the end of the prefix string
                {
                                if(isalnum(*e)) //if it is alphabet or number
                                {
                                                num=*e-48;
                                                push(num);
                                }
                                else //if it is character
                                {
                                                op1=pop();
                                                op2=pop();
                                                switch(*e)
                                                {
                                                case '+':
                                                                res=op1+op2;
                                                                push(res);
                                                                break;
                                                case '-':
                                                                res=op1-op2;
                                                                push(res);
                                                                break;
                                                case '*':
                                                                res=op1*op2;
                                                                push(res);
                                                                break;
                                                case '/':
                                                                res=op1/op2;
                                                                push(res);
                                                                break;
                                                case '^':
                                                                res=pow(op1,op2);
                                                                push(res);
                                                                break;
                                                }
                                }
                                *e++;
                }
                printf("The result of evaluation of prefix expression:%d\n",pop());
}
