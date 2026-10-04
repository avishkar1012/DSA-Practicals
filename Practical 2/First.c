#include <stdio.h>

int main() {
    int a[5], i, n, found = 0;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &n);
    for (i = 0; i < 5; i++) {
        if (a[i] == n) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Element found at index %d\n", i);
    } else {
        printf("Element not found\n");
    }
    return 0;
}