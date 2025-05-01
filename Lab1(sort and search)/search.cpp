#include <cstdio>
#include <cstdlib>
#include "sort.h"

int main() {
    int size;
    int choice;
    int key;
    int arr[] = {4, 7, 8, 2};
    size = sizeof(arr) / sizeof(arr[0]);

    printf("enter the element to be found");
    scanf("%d", &key);

    printf("\n");
    printf("\n");
    printf("1. Linear search\n");
    printf("2. Binary search\n");
    printf("3. Exit\n");
    printf("Enter the choice\n");
    scanf("%d", &choice);

    if (choice == 1) {
        bubblesort(arr, size);
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                printf("Found the element using Linear search");
            }
        }
    } else if (choice == 2) {
        bubblesort(arr, size);
        int low = 0, high = size - 1, mid;
        int found = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                printf("Element found using binary search\n");
                found = 1;
                break;
            } else if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (!found) {
            printf("Element not found using binary search\n");
        }
    } else {
        printf("Exited from program");
    }
}
