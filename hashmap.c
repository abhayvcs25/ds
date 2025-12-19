#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define Empty -1

typedef struct
{
    int key;
    char name[30];
    int age;
}employee;

void insert(employee ht[],int m , employee emp)
{
    int index = emp.key%m;
    int start = index;

    while(ht[index].key != Empty)
    {
        index=(index+1)%m;
        if(index==start){
            printf("Hash table is full");
            return;
        }
    }

    ht[index]=emp;
    printf("Inserted %d key  at %d index \n",emp.key,index);
}

int search(employee ht[],int m ,int key){
    int index = key%m;
    int start = index;

    while(ht[index].key != Empty)
    {
        if(ht[index].key == key)
            return index;
        index = (index+1)%m;
        if(index == start)
            break;
    }
    return -1;
}

void display(employee ht[] ,int m)
{
    printf("\nHash table = \n");
    for (int i=0;i<m;i++)
    {
        if(ht[i].key == Empty) printf("index %2d :Empty \n",i);
        else printf("index %2d : key = %d : name = %s : age=%d\n",i,ht[i].key,ht[i].name,ht[i].age);
    }
}
int main()
{
    int m, choice, key;
    printf("\nEnter the size of the hash table = ");
    scanf("%d", &m);

    employee *ht = (employee *)malloc(m * sizeof(employee));
    for (int i = 0; i < m; i++)
        ht[i].key = Empty;

    while (1) {
        printf("\n=====MENU=====");
        printf("\n1\tinsert\n2\tsearch\n3\tdisplay\n4\texit\n");
        printf("\nEnter your choice = ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                employee emp;
                printf("Enter key, name, age: ");
                scanf("%d %s %d", &emp.key, emp.name, &emp.age);
                insert(ht, m, emp);
                break;
            }
            case 2: {
                printf("Enter the key to search = ");
                scanf("%d", &key);
                int pos = search(ht, m, key);
                if (pos != -1)
                    printf("Key %d found at index %d (name = %s , age = %d)\n",
                           key, pos, ht[pos].name, ht[pos].age);
                else
                    printf("Key %d was not found\n", key);
                break;
            }
            case 3:
                display(ht, m);
                break;
            case 4:
                free(ht);
                printf("EXITING\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
