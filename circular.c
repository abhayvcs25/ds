#include<stdio.h>
#include<stdlib.h>

#define size 3

char queue[size];
int rear = -1 ,front = -1;


int isfull()
{
    if (front == rear+1 || (front == 0 && rear== size -1)) return 1;
    return 0;
}

int isempty()
{
    if (front==-1) return 1;
    return 0;
}


void display()
{
    int i;
    if (isempty())
        printf("The QUEUE is under flow");
    else
    {
        printf("The QUEUE is = ");
        for (i=front;i!=rear;i=(i+1)%size)
            printf("\n%d",queue[i]);
        printf("\n%d",queue[i]);
    }
}

void insert()
{
    int n;

    if (isfull())
        printf("The QUEUE is Over flow");
    else
    {
        if (front==-1)
            front = 0;
        printf("\nEnter the elem = ");
        scanf("%d",&n);
        rear = (rear+1)%size;
        queue[rear] = n;
        printf("%d was inserted",n);
    }
}

void del()
{
    int e;
    if (isempty())
        printf("The QUEUE is underflow");
    else
    {
        e=queue[front];
        if (front == rear)
        {
            front = -1;
            rear =- 1;
        }
        else
            front = (front + 1) % size;
        printf("\n deleted element %d",e);

    }
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
