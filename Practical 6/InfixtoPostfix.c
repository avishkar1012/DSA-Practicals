#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int precedence(char c) {
    switch (c) {
        case '^':
            return 3;

        case '*':
        case '/':
        case '%':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '%' || c == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {

        c = infix[i];

        if (c == ' ')
            continue;

        if (isalnum(c)) {
            postfix[j++] = c;
        }

        else if (c == '(') {
            push(c);
        }

        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();   // Remove '('
        }

        else if (isOperator(c)) {

            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(c)) {

                postfix[j++] = pop();
            }

            push(c);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {

    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}