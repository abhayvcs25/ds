#include<stdio.h>
#include<stdlib.h>

#define size 20

char queue[size];
int rear = -1 ,front = -1;

void display()
{
    int i;
    if (rear == -1 || front > rear)
        printf("The QUEUE is under flow");
    else
    {
        printf("The QUEUE is = ");
        for (i=front;i<=rear;i++)
            printf("\n%d",queue[i]);
    }
}

void insert()
{
    int n;

    if (rear == size-1)
        printf("The QUEUE is Over flow");
    else
    {
        if (front==-1)
            front = 0;
        printf("\nEnter the elem = ");
        scanf("%d",&n);
        queue[++rear]=n;
    }
}

void del()
{
    if (rear == -1 ||front > rear)
        printf("The QUEUE is underflow");
    else
        printf("The %d was deleted",queue[front++]);
}


void main()
{
    int choice;
    while (1)
    {
        printf("\n-----MENU-----");
        printf("\n1\tINSERT\n2\tDELETE\n3\tDISPLAY\n4\tEXIT");
        printf("\nEnter your choice = ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : insert();
                    break;
            case 2 : del();
                    break;
            case 3 : display();
                    break;
            case 4 : exit(0);
                    break;
            default :
                    printf("Invalid choice");
                    break;
        }
    }
}
