#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;

void insert_begin();
void insert_last();
void insert_locc();
void delete_begin();
void delete_last();
void delete_locc();
void display();

int main()
{
    int choice = 0;

    printf("Doubly Linked List Operations:\n");

    printf("\nSize of data part = %d", sizeof(start->data));
    printf("\nSize of previous address part = %d", sizeof(start->prev));
    printf("\nSize of next address part = %d", sizeof(start->next));
    printf("\nSize of node = %d", sizeof(struct node));

    while (1)
    {
        printf("\n\n1. Insert at beginning");
        printf("\n2. Insert at last");
        printf("\n3. Insert at specific location");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from last");
        printf("\n6. Delete from specific location");
        printf("\n7. Display");
        printf("\n8. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_begin();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_locc();
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            delete_locc();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!");
        }
    }
}

