#include <stdio.h>

int main() {
    int arr[5], mid, target, found = 0;
    int low = 0, high = 4;
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            found = 1;
            printf("Element found at index %d\n", mid);
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found) {
        printf("Element not found\n");
    }
    return 0;
}