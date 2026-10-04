#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int top = -1;
int stack[SIZE];

void push();
void pop();
void peek();
void display();

int main() {
    int choice;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;       
}

void push() {
    int x;
    if (top == SIZE - 1) {
        printf("\nStack Overflow! Stack is full.\n");
    } else {
        printf("Enter the element to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("Element pushed successfully.\n");
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack Underflow! Stack is empty.\n");
    } else {
        printf("Element popped: %d\n", stack[top]);
        top--;
    }
}

void peek() {
    printf("Top element: %d\n", stack[top]);
}

void display() {
    printf("\nThe elements in the stack are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}