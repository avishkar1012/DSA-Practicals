#include <stdio.h>

void add1();
void add2(int, int);
int add3();
int add4(int, int);

int main() {
    int ch, x, y, result;

    do {
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                add1();
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &x, &y);
                add2(x, y);
                break;

            case 3:
                result = add3();
                printf("Sum = %d\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%d %d", &x, &y);
                int sum = add4(x, y);
                printf("Sum: %d\n", sum);
                break;
                
            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (ch != 5);
    return 0;
}

void add1() {
    int x, y, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    sum = x + y;
    printf("Sum = %d\n", sum);
}

void add2(int x, int y) {
    int sum = x + y;
    printf("Sum = %d\n", sum);
}

int add3() {
    int x, y, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    return x + y;
}

int add4(int x, int y) {
    return x + y;
}