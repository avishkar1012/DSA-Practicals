#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue();
void dequeue();
void peek();
void search();
void display();

int main()
{
    int choice;
    struct node *p;

    printf("\n====Linear Queue(Linked List)====\n");

    printf("Size of data = %zu\t Size of Link = %zu", sizeof(front->data), sizeof(front->next));
    printf("\n Size of node = %zu\n", sizeof(struct node));

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("===============\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            search();
            break;

        case 5:
            display();
            break;

        case 6:
            while (front != NULL)
            {
                p = front;
                front = front->next;
                free(p);
            }
            rear = NULL;
            printf("\nProgram terminated.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void enqueue() {
    struct node *p;
    int value;

    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("\nQueue Overflow!\n");
    }
    else {
        printf("\nEnter element to insert: ");
        scanf("%d", &value);

        p->data = value;
        p->next = NULL;

        if (front == NULL)
        {
            front = rear = p;
        }
        else {
            rear->next = p;
            rear = p;
        }

        printf("%d inserted into the queue.\n", value);
    }
}

void dequeue()
{
    struct node *p;

    if (front == NULL)
    {
        printf("\nQueue Underflow!\n");
    }
    else {
        p = front;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        printf("\n%d deleted from the queue.\n", p->data);
        free(p);
    }
}

void peek()
{
    if (front == NULL)
    {
        printf("\nQueue is empty. No front element.\n");
    }
    else
    {
        printf("\nFront element is %d\n", front->data);
    }
}

void search()
{
    struct node *p = front;
    int value, position = 1;

    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &value);

    while (p != NULL)
    {
        if (p->data == value)
        {
            printf("%d found at position %d.\n", value, position);
            return;
        }

        p = p->next;
        position++;
    }

    printf("%d not found in the queue.\n", value);

}

void display()
{
    struct node *p;

    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue elements are (Front -> Rear): \n");
        p = front;

        while (p != NULL)
        {
            printf("%d -> ", p->data);
            p = p->next;
        }

        printf("NULL\n");
    }
}
