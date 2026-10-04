#include <stdio.h>

int main() {
    int arr[5];
    int i, j;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 5; i++) {
        int smallest = i;
        for (j = i + 1; j < 5; j++) {
            if (arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }

    printf("Sorted array:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}