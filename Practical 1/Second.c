#include <stdio.h>

int EvenorOdd(int);
int IsPrime(int);
int Factorial(int);
int Reverse(int);

int main() {
    int ch, num;
    printf("Enter the number: ");
    scanf("%d", &num);

    do {
        printf("==== Menu =====\n");
        printf("1. Check Even or Odd\n");
        printf("2. Check Prime\n");
        printf("3. Calculate Factorial\n");
        printf("4. Reverse a Number\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                EvenorOdd(num);
                break;
                
            case 2:
                IsPrime(num);
                break;

            case 3:
                int fact = Factorial(num);
                printf("Factorial of %d is %d\n", num, fact);
                break;

            case 4:
                int rev = Reverse(num);
                printf("Reverse of %d is %d\n", num, rev);
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

int EvenorOdd(int n) {
    if (n % 2 == 0)
        printf("%d is Even\n", n);
    else
        printf("%d is Odd\n", n);
    return 0;
}

int IsPrime(int n) {
    int i;
    if (n <= 1) {
        printf("%d is not a prime number\n", n);
        return 0;
    }

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d is not a prime number\n", n);
            return 0;
        }
    }
    printf("%d is a prime number\n", n);
    return 1;
}

int Factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * Factorial(n - 1);
}

int Reverse(int n) {
    int rev = 0;
    while (n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

