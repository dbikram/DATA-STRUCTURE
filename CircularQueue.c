// primitive operation of circular queue
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct Queue
{
                int item[max];
                int front,rear;
}q;
void enQueue(struct Queue*,int);
int deQueue(struct Queue*);
void display(struct Queue*);
int fullQueue(struct Queue*);
int emptyQueue(struct Queue*);
void main()
{
                q.front=-1,q.rear=-1;
                int ch,x,y;
                while(1)
                {
                                printf("\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\nEnter your choice:");
                                scanf("%d",&ch);
                                switch(ch)
                                {
                                case 1:
                                                if(!fullQueue(&q))
                                                {
                                                                printf("Enter the number for insertion:");
                                                                scanf("%d",&x);
                                                                enQueue(&q,x);
                                                }
                                                else
                                                                printf("The Queue is full\n");
                                                break;
                                case 2:
                                                if(!emptyQueue(&q))
                                                {
                                                                y=deQueue(&q);
                                                                printf("The dequeued element is:%d\n",y);
                                                }
                                                else
                                                                printf("The Queue is empty\n");
                                                break;
                                case 3:
                                                if(!emptyQueue(&q))
                                                {
                                                                printf("The following elements are:\n");
                                                                display(&q);
                                                }
                                                else
                                                                printf("The Queue is empty\n");
                                                break;
                                case 4:
                                                exit(0);
                                default:
                                                printf("Wrong key\n");
                                }
                }
}
int fullQueue(struct Queue*q)
{
                if((q->rear+1)%max==q->front)
                                return 1;
                else
                                return 0;
}
int emptyQueue(struct Queue*q)
{
                if(q->front==-1)
                                return 1;
                else
                                return 0;
}
void enQueue(struct Queue*q,int x)
{
                q->rear=(q->rear+1)%max;
                q->item[q->rear]=x;
                if(q->front==-1)
                                q->front=0;
}
int deQueue(struct Queue*q)
{
                int y;
                y=q->item[q->front];
                if(q->front==q->rear)
                                q->rear=q->front=-1;
                else
                                q->front=(q->front+1)%max;
                return y;
}
void display(struct Queue*q)
{
                int i,j;
                if(q->front<=q->rear)
                {
                                for(i=q->front;i<=q->rear;i++)
                                                printf("%d ",q->item[i]);
                }
                else //reinsertion
                {
                                for(i=0;i<=q->rear;i++)
                                                printf("%d ",q->item[i]);
                                for(j=q->front;j<=max-1;j++)
                                                printf("%d ",q->item[j]);
                }
}
