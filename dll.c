#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* createnode(int data)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void insertend(struct node ** head,int data)
{
    struct node *nn = createnode(data);
    if(*head == NULL)
    {
        *head = nn;
        return;
    }
    struct node * temp = *head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next=nn;
    nn->prev=temp;
}

void insertleft(struct node **head ,int target ,int data)
{
    struct node * temp = *head;
    while(temp!= NULL && temp->data!= target)
        temp=temp->next;

    if (temp==NULL)
    {
        printf("The value was not found");
        return;
    }

    struct node * nn=createnode(data);
    nn->next=temp;
    nn->prev=temp->prev;

    if(temp->prev!=NULL)
        temp->prev->next = nn;
    else
        *head = nn;

    temp->prev=nn;
    printf("The %d was inserted on left of %d",data,target);
}

void deletenode(struct node **head,int target)
{
    struct node * temp = *head;
    while(temp->data!=target)
        temp=temp->next;
    if (temp == NULL)
    {
        printf("The values was not found");
        return;
    }
    if(temp->prev !=NULL)
        temp->prev->next=temp->next;
    else
        *head=temp->next;

    if(temp->next != NULL)
        temp->next->prev=temp->prev;
    free(temp);
    printf("Node with value %d was deleted",target);
}

void display(struct node **head)
{
    struct node * temp = *head;
    printf("\n===Doubly Linked LIst ===");
    while(temp!=NULL)
      {
          printf("\n%d",temp->data);
          temp=temp->next;
      }
    printf("\nNULL");
}

void main()
{
    struct node * head = NULL;
    int choice,data,target;

    while(1){
        printf("\n=====MENU=====");
        printf("\n1\tinsert at end\n2\tinsert left to value\n3\tdelete value\n4\tdisplay\n5\texit");
        printf("\nEnter your choice = ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("\nEnter the value= ");
                    scanf("%d",&data);
                    insertend(&head,data);
                    break;
            case 2 : printf("\nEnter the value = ");
                    scanf("%d",&data);
                    printf("\nEnter the target = ");
                    scanf("%d",&target);
                    insertleft(&head,target,data);
                    break;
            case 3 : printf("\nEnter the value = ");
                    scanf("%d",&target);
                    deletenode(&head,target);
                    break;
            case 4 : display(&head);
                    break;
            case 5 : exit(0);
                    break;
            default:printf("Invalid choice");
                    break;
        }
    }
}
