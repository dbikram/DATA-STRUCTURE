//program to evaluate the postfix expression
#include<stdio.h>
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
                char pofx[50],*e;
                int op1,op2,res,num;
                printf("Enter the postfix expression:");
                gets(pofx);
                e=pofx;
                while(*e!='\0') //till the end of the postfix expression
                {
                                if(isalnum(*e)) //if it is alphabet or number
                                {
                                                num=*e-48;
                                                push(num);
                                }
                                else //if it is character
                                {
                                                op2=pop();
                                                op1=pop();
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
                printf("The result of evaluation of postfix expression:%d\n",pop());
}
