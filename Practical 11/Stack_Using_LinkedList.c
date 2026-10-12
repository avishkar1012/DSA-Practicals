#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct stack {
    int data;
    struct stack *next;
};

struct stack *top = NULL;

void push();
void pop();
void peek();
void display();

int main()
{
        int choice = 0;
        printf("===Dynamic Implementation of Stack (using Linked list)===\n");
        printf("\nSize of data = %zu \t Size of Link = %zu", sizeof(top->data), sizeof(top->next));
        printf("\nSize of node = %zu", sizeof(struct stack));

        while (choice != 5) {
            printf("\n--Stack Menu--\n");
            printf("\n1. Push");
            printf("\n2. Pop");
            printf("\n3. Peek");
            printf("\n4. Display the stack");
            printf("\n5. Exit");
            printf("\nEnter the operation to be performed: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting the program....\n");
                exit(0);

            default:
                printf("Enter valid option\n");
            }
        }
        return 0;
}

void push() {
    struct stack *p;
    int value;

    p = (struct stack *)malloc(sizeof(struct stack));
    printf("Address of Node = %p", (void*)p);

    if (p == NULL) {
        printf("STACK OVERFLOW\n");
    } else {
        printf("\nEnter value: ");
        scanf("%d", &value);

        p->data = value;
        p->next = top;
        top = p;
        printf("Node of %d inserted at the top of the stack.\n", value);
    }
}

void pop()
{
    struct stack *temp;

    if (top == NULL)
    {
        printf("Underflow!! List is empty\n");
    }
    else
    {
        temp = top;
        top = top->next;

        printf("%d node popped from the top of stack\n", temp->data);
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n", top->data);
}

void display()
{
    struct stack *temp;

    if (top ==  NULL)
    {
        printf("The list is empty currently\n");
    }
    else
    {
        temp = top;

        printf("Linked List: \n");
        while (temp != NULL)
        {
            printf("%d -> %p ", temp->data,(void*)temp->next);
            temp = temp->next;
        }
    }
}
