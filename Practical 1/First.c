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