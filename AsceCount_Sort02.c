#include <stdio.h>
#include <stdlib.h> // for using calloc

// Function to print the elements of an array
void printarray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the maximum element in an array
int maxelement(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort on an array
void countsort(int *arr, int n) {
    int max = maxelement(arr, n); // Find the maximum element in the array

    // Allocate memory for the count array and initialize all elements to 0
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Count the occurrences of each element in the input array
    for (int i = 0; i < n; i++) {
        count[arr[i]] = count[arr[i]] + 1;
    }

    // Update the count array to store the cumulative sum of counts
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Allocate memory for a temporary array to store the sorted elements
    int *arr2 = (int *)malloc(n * sizeof(int));

    // Build the sorted array using the count array
    for (int i = n - 1; i >= 0; i--) {
        arr2[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = arr2[i];
    }

    // Free the dynamically allocated memory
    free(arr2);
    free(count);
}

int main() {

    int arr[] = {1, 9, 6, 3, 2, 8, 5, 8};

    int n = 8;
    printarray(arr, n);
    countsort(arr, n);
    printarray(arr, n);

    return 0;
}
