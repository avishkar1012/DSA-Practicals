#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else 
    {
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;
        printf("%d enqueued to the queue\n", value);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty. No front element to dequeue.\n");
    }
    else
    {
        printf("%d dequeued from the queue\n", queue[front]);
    }
}

void peek() 
{
    if (front == -1)
    {
        printf("Queue is empty. No front element to peek.\n");
    }
    else
    {
        printf("Front element is: %d\n", queue[front]);
    }
}

void search() 
{
    int value, i, position = -1;
    
    if (front == -1)
    {
        printf("Queue is empty. No elements to search.\n");
    }
    else
    {
        printf("Enter the value to search: ");
        scanf("%d", &value);

        for (i = front; i <= rear; i++)
        {
            if (queue[i] == value)
            {
                position = i;
                break;
            }
        }

        if (position != -1)
        {
            printf("%d found at position %d in the queue\n", value, position - front + 1);
        }
        else
        {
            printf("%d not found in the queue\n", value);
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else 
    {
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\nQueue Operations:\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}