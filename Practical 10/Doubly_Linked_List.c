#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct node {
    int data;
    struct node *prev;
    struct node *next;
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

    printf("Doubly Linked List Operations....\n");

    printf("Size of data part = %d", sizeof(start->data));
    printf("\tSize of prev address=%d", sizeof(start->prev));
    printf("\tSize of next address=%d", sizeof(start->next));
    printf("\nSize of node = %d", sizeof(struct node));

    while (1) {
    printf("===Doubly Linked List operations menu===\n");
    printf("1.Insert at the beginning\n");
    printf("2.Insert at the last\n");
    printf("3.Insert at some position\n");
    printf("4.Delete from the beginning\n");
    printf("5.Delete from the last\n");
    printf("6.Delete from some position\n");
    printf("7.Display the List\n");
    printf("8.Exit\n");

    printf("Enter the operation you want to performed: ");
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
        p->prev = NULL;
        p->next = start;

        if (start != NULL)
        {
            start->prev = p;
        }

        start = p;
        printf("\nNode inserted into the list at the beginning: %d\n", p->data);
    }
}

void insert_last()
{
    struct node *p, *temp;
    int value;

    p = malloc(sizeof(struct node));

    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    p->data = value;
    p->next = NULL;

    if (start == NULL) {
        p->prev = NULL;
        start = p;
    } else {
        temp = start;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = p;
        p->prev = temp;
    }

    printf("Node inserted at the end: %d\n", p->data);
}

void insert_locc()
{
    struct node *p, *temp;
    int value, pos, i;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    p = malloc(sizeof(struct node));

    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    p->data = value;

    if (pos == 1) {
        p->prev = NULL;
        p->next = start;

        if (start != NULL) {
            start->prev = p;
        }

        start = p;
    } else {
        temp = start;

        for (i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Position out of bounds.\n");
            free(p);
            return;
        }

        p->next = temp->next;
        p->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = p;
        }

        temp->next = p;
    }

    printf("Node inserted successfully at position %d.\n", pos);
}

void delete_begin()
{
    struct node *p;
    int value;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    p = start;
    value = p->data;

    start = start->next;

    if (start != NULL) {
        start->prev = NULL;
    }

    free(p);

    printf("Node deleted from the beginning: %d\n", value);
}

void delete_last()
{
    struct node *p;
    int value;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    p = start;

    while (p->next != NULL) {
        p = p->next;
    }

    value = p->data;

    if (p->prev == NULL) {
        start = NULL;
    } else {
        p->prev->next = NULL;
    }

    free(p);

    printf("Last node deleted: %d\n", value);
}

void delete_locc()
{
    struct node *p;
    int pos, i, value;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    p = start;

    for (i = 1; i < pos && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    value = p->data;

    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        start = p->next;
    }

    if (p->next != NULL) {
        p->next->prev = p->prev;
    }

    free(p);

    printf("Node deleted from position %d: %d\n", pos, value);
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
            printf("%d : %p <--> ", p->data, (void*)p);
            p = p->next;
    }
    printf("NULL\n");
    }
}
