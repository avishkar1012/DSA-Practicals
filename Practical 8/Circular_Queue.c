#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    printf("Enter the value to enqueue: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("Enqueued %d to the queue.\n", value);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    int value = queue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("Dequeued %d from the queue.\n", value);
}

void peek()
{
    if (front == -1)
    {
        printf("Queue is empty. Cannot peek.\n");
        return;
    }

    printf("Front element is: %d\n", queue[front]);
}

void search()
{
    int value;
    int i;
    int position = -1;

    if (front == -1)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nEnter the value to search: ");
    scanf("%d", &value);

    i = front;

    while (1)
    {
        if (queue[i] == value)
        {
            position = i;
            break;
        }

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % MAX;
    }

    if (position == -1)
    {
        printf("\nValue not found in the queue.\n");
    }
    else
    {
        printf("\nValue found at position: %d\n", position);
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (i = front; i != rear; i = (i + 1) % MAX)
    {
        printf("%d ", queue[i]);
    }

    printf("%d\n", queue[rear]);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");

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
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}