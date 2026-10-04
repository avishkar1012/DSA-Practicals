#include <stdio.h>
#include <string.h>

void LenofString(char str[]);
void ReverseString(char str[]);
void LowertoUpper(char str[]);

int main() {
    char str[100];
    int ch;

    printf("Enter a string: ");
    scanf("%s" ,str);

    do {
        printf("==== Menu =====\n");
        printf("1. Length of String\n");
        printf("2. Reverse String\n");
        printf("3. Convert Lowercase to Uppercase\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch); 

        switch (ch) {
            case 1:
                LenofString(str);
                break;

            case 2:
                ReverseString(str);
                break;

            case 3:
                LowertoUpper(str);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (ch != 4);

    return 0;
}

void LenofString(char str[]) {
    int length = strlen(str);
    printf("Length of the string is: %d\n", length);
}

void ReverseString(char str[]) {
    int length = strlen(str);
    char reversed[100];

    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';

    printf("Reversed string is: %s\n", reversed);
}

void LowertoUpper(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    printf("String in uppercase is: %s\n", str);
}