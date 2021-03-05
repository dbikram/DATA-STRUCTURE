//program to write operations of doubly ended Queue
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct dequeue
{
                int item[max];
                int left,right;
}q;
void leftInsert(struct dequeue*,int);
int leftDelete(struct dequeue*);
void rightInsert(struct dequeue*,int);
int rightDelete(struct dequeue*);
void display(struct dequeue*);
int fullQueue(struct dequeue*);
int emptyQueue(struct dequeue*);
void main()
{
                q.left=q.right=-1;
                int a,b,x,y,ch;
                while(1)
                {
                                printf("\n1.Insertion at left\n2.Insertion at right\n3.Deletion from left\n4.Deletion from right\n5.Display\n6.Exit\nEnter your choice:");
                                scanf("%d",&ch);
                                switch(ch)
                                {
                                case 1:
                                                if(!fullQueue(&q))
                                                {
                                                                printf("Enter the number for insertion from left side:");
                                                                scanf("%d",&a);
                                                                leftInsert(&q,a);
                                                }
                                                else
                                                                printf("The Dequeue is full\n");
                                                break;
                                case 2:
                                                if(!fullQueue(&q))
                                                {
                                                                printf("Enter the number for insertion from right side:");
                                                                scanf("%d",&b);
                                                                rightInsert(&q,b);
                                                }
                                                else
                                                                printf("The Dequeue is full\n");
                                                break;
                                case 3:
                                                if(!emptyQueue(&q))
                                                {
                                                                x=leftDelete(&q);
                                                                printf("The deleted element from left side is:%d\n",x);
                                                }
                                                else
                                                                printf("The Dequeue is empty\n");
                                                break;
                                case 4:
                                                if(!emptyQueue(&q))
                                                {
                                                                y=rightDelete(&q);
                                                                printf("The deleted element from right side is:%d\n",y);
                                                }
                                                else
                                                                printf("The Dequeue is empty\n");
                                                break;
                                case 5:
                                                if(!emptyQueue(&q))
                                                {
                                                                printf("The following elements are:\n");
                                                                display(&q);
                                                }
                                                else
                                                                printf("The Dequeue is empty\n");
                                                break;
                                case 6:
                                                exit(0);
                                default:
                                                printf("Wrong key\n");
                                }
                }
}
void leftInsert(struct dequeue*q,int a)
{
                if(q->left==-1)
                {
                                q->left=0;
                                q->right=0;
                }
                else if(q->left==0)
                                q->left=max-1;
                else
                                q->left--;
                q->item[q->left]=a;
}
void rightInsert(struct dequeue*q,int b)
{
                if(q->right==-1)
                {
                                q->left=0;
                                q->right=0;
                }
                else if(q->right==max-1)
                                q->right=0;
                else
                                q->right++;
                q->item[q->right]=b;
}
int leftDelete(struct dequeue*q)
{
                int x;
                x=q->item[q->left];
                if(q->left==q->right)
                                q->left=q->right=-1;
                else if(q->left==max-1)
                                q->left=0;
                else
                                q->left++;
                return x;
}
int rightDelete(struct dequeue*q)
{
                int y;
                y=q->item[q->right];
                if(q->right==q->left)
                                q->right=q->left=-1;
                else if(q->right==0)
                                q->right=max-1;
                else
                                q->right--;
                return y;
}
void display(struct dequeue*q)
{
                int i,j;
                if(q->left<=q->right)
                {
                                for(i=q->left;i<=q->right;i++)
                                                printf("%d\t",q->item[i]);
                }
                else
                {
                                for(i=0;i<=q->right;i++)
                                                printf("%d\t",q->item[i]);
                                for(j=q->left;j<=max-1;j++)
                                                printf("%d\t",q->item[j]);
                }
}
int fullQueue(struct dequeue*q)
{
                if(((q->left-q->right)==1)&&(q->left==0)||(q->right==max-1))
                                return 1;
                else
                                return 0;
}
int emptyQueue(struct dequeue*q)
{
                if(q->left==-1&&q->right==-1)
                                return 1;
                else
                                return 0;
}
