#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void Insert_first()
{
    int n;
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL) printf("\nOVERFLOW");
    else
    {
        printf("\nEnter value = ");
        scanf("%d",&n);
        ptr->data = n;
        ptr->next=head;
        head=ptr;
        printf("\n%d was inserted\n",n);
    }
}

void Insert_end()
{
    struct node *ptr,*temp;
    int n;

    ptr = (struct node *)malloc(sizeof(struct node *));

    if (ptr == NULL) printf("\nOVERFLOW");
    else
    {
        printf("\nEnter value = ");
        scanf("%d",&n);
        ptr->data = n;
        if (head == NULL)
        {
            ptr->next= NULL;
            head = ptr;
            printf("\n%d was inserted\n",n);
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp=temp->next;
            temp->next=ptr;
            ptr->next=NULL;
            printf("\n%d was inserted\n",n);
        }
    }
}

void Insert_any()
{
    struct node *ptr,*temp;
    int i,loc,n;
    ptr= (struct node *)malloc(sizeof(struct node *));

    if (ptr == NULL) printf("\nOVERFLOW");
    else
    {
        printf("\nEnter value = ");
        scanf("%d",&n);
        printf("\nEnter Location = ");
        scanf("%d",&loc);
        ptr->data = n;
        temp = head;
        for(i=1 ; i<loc-1 ;i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
            ptr->next=temp->next;
            temp->next=ptr;
            printf("\n%d was inserted\n",n);
        }
    }
}

void Display()
{
    struct node *ptr;
    ptr=head;
    if(ptr==NULL) printf("\nOVERFLOW");
    else
    {
        printf("\nLINKED LIST =");
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->data);
            ptr=ptr->next;
        }
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n-----MENU-----");
        printf("\n1\tInsert at the first\n2\tInsert any where\n3\tInsert at the end\n4\tDisplay\n5\tExit");;
        printf("\nEnter your choice = ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : Insert_first();
                    break;
            case 2 : Insert_any();
                    break;
            case 3 : Insert_end();
                    break;
            case 4 : Display();
                    break;
            case 5 : exit(0);
                    break;
            default : printf("\nInvalid choice\n");
                    break;
        }
    }
}
