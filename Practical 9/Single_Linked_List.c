#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert_begin();
void insert_last();
void insert_position();
void delete_begin();
void delete_last();
void delete_position();
void display();

int main()
{
    int choice = 0;

    printf("Size of data = %d\tSize of Link=%d", sizeof(start->data), sizeof(start->next));
    printf("\nSize of node = %d", sizeof(struct node));

    while (1) {
    printf("===Linked list operations menu===\n");
    printf("1.Insert at the beginning\n");
    printf("2.Insert at the last\n");
    printf("3.Insert at some position\n");
    printf("4.Delete from the beginning\n");
    printf("5.Delete from the last\n");
    printf("6.Delete from some position\n");
    printf("7.Display the nodes\n");
    printf("8.Exit\n");

    printf("Enter your choice: ");
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
        insert_position();
        break;

    case 4:
        delete_begin();
        break;

    case 5:
        delete_last();
        break;

    case 6:
        delete_position();
        break;

    case 7:
        display();
        break;

    case 8:
        printf("Exiting...");
        return 0;

    default:
        printf("Invalid choice. Choose from 1 to 8\n");
        break;
    }
    }
    return 0;
}

void insert_begin()
{
    struct node *p;
    int value;
    p = (struct node *)malloc(sizeof(struct node));
    printf("Address of Node = %p", (void*)p);

    if (p == NULL) {
        printf("\nOverflow\n");
    } else {
        printf("\nEnter the value: ");
        scanf("%d", &value);
        p->data = value;
        p->next = start;
        start = p;
        printf("\nNode inserted into the list\n");
    }
}

void insert_last()
{
    struct node *p, *temp;
    int value;
    p = (struct node *)malloc(sizeof(struct node));
    printf("Address of Node = %p", (void*)p);

    if (p == NULL) {
        printf("\nOverflow\n");
    } else {
        printf("\nEnter the value: ");
        scanf("%d", &value);
        p->data = value;
        p->next = NULL;
    }

    if (start == NULL) {
        start = p;
    } else {
        temp = start;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = p;

        printf("Node inserted at the last of list\n");
    }
}

void insert_position()
{
    struct node *p, *temp;
    int value, pos, i = 1;
    p = (struct node *)malloc(sizeof(struct node));
    printf("Address of Node = %p", (void*)p);

    if (p == NULL) {
        printf("\nOverflow\n");
    } else {
        printf("\nEnter the position: ");
        scanf("%d", &pos);
        printf("\nEnter the value: ");
        scanf("%d", &value);
        p->data = value;

        if (pos == 1) {
            p->next = start;
            start = p;

            printf("Node inserted at the position 1\n");
        } else {
            temp = start;
            while (i < pos - 1 && temp != NULL) {
                temp = temp->next;
                i++;
            }
            if (temp == NULL) {
                printf("\nPosition out of bounds\n");
                free(p);
            } else {
                p->next = temp->next;
                temp->next = p;

                printf("Node inserted at the position %d\n", pos);
            }
        }
    }
}

void delete_begin()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("Underflow..!! List is empty.\n");
    } else {
        temp = start;
        start = start->next;
        free(temp);

        printf("Node deleted from beginning\n");
    }
}

void delete_last()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("Underflow..!! List is empty.\n");
    } else if (start->next == NULL)
    {
        free(start);
        start = NULL;
    }
    else {
        temp = start;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;

        printf("Node deleted from last\n");
    }
}

void delete_position()
{
    struct node *temp, *del;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (start == NULL) {
        printf("Underflow..!! List is empty.\n");
        return;
    } else if (pos == 1) {
        temp = start;
        start = start->next;
        free(temp);

        printf("Node deleted from position 1\n");
        return;
    }
    else {
        temp = start;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            printf("Position out of bounds\n");
        } else {
            del = temp->next;
            temp->next = del->next;
            free(del);

            printf("Node deleted from position %d\n", pos);
        }
    }
}

void display()
{
    struct node *p;
    p = start;

    if (p == NULL)
    {
        printf("\nList is empty.\n");
    } else {
        printf("\nPrinting Values: \n");
        while (p != NULL)  {
            printf("%d : %p -> ", p->data, p);
            p = p->next;
    }
    printf("\n");
    }
}