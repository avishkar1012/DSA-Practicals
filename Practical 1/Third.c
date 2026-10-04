#include <stdio.h>

int main() {
    int A, B, C, D, E, F, G, H;

    printf("Enter the first number: ");
    scanf("%d", &A);
    printf("Enter the second number: ");
    scanf("%d", &B);
    printf("Enter the third number: ");
    scanf("%d", &C);
    printf("Enter the fourth number: ");
    scanf("%d", &D);
    printf("Enter the fifth number: ");
    scanf("%d", &E);
    printf("Enter the sixth number: ");
    scanf("%d", &F);
    printf("Enter the seventh number: ");
    scanf("%d", &G);
    printf("Enter the eighth number: ");
    scanf("%d", &H);

    int myNumbers[8] = {A, B, C, D, E, F, G, H};
    printf("The Even numbers are: ");
    for (int i = 0; i < 8; i++) {
        if (myNumbers[i] % 2 == 0) {
            printf("%d ", myNumbers[i]);
        }
    }
    printf("\n");

}