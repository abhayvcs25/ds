#include<stdio.h>

#define SIZE 5

int stack[SIZE],top=-1;

void push(int);
void pop();
void display();

void main()
{
    int value,choice=1;

    while(choice != 4){
        printf("\n******MENU******\n");
        printf("1.\tpush\n2.\tpop\n3.\tdisplay\n4.\texit\n");
        printf("Enter your choice = ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("Enter value to enter = ");
                     scanf("%d",&value);
                     push(value);

                    break;
            case 2 : pop();
                    break;
            case 3 : display();
                    break;
            case 4 :
                    break;
            default : printf("Invalid choice");
                    break;
        }

    }
}

void push(int n)
{
    if (top==SIZE-1)
        printf("\nThe Stack is full\n");
    else
    {
        top++;
        stack[top]=n;
        printf("\n%d Inserted\n",n);
    }
}

void pop()
{
    if (top==-1)
        printf("\nThe Stack is Empty\n");

    else
    {
        printf("%d was Deleted",stack[top]);
        top--;
    }
}

void display()
{
    if (top==-1)
        printf("The stack is Empty");
    else
    {
        int i;
        printf("\nThe Stack Elements are\n");
        for (i=top ; i>=0 ; i--)
            printf("%d\n",stack[i]);
    }
}
