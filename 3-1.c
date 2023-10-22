#include <stdio.h>
#include <stdlib.h>

// Define a structure called IntArray to hold an array's length and data pointer.
struct IntArray {
    int length;   // Length of the integer array
    int *dataPtr; // Pointer to the array's data
};

// Function to dynamically allocate memory for an IntArray and its data.
struct IntArray *mallocIntArray(int length) {
    // Allocate memory for the IntArray structure itself.
    struct IntArray *array = (struct IntArray *)malloc(sizeof(struct IntArray));
    if (array == NULL) {
        // If memory allocation fails, print an error message and exit the program.
        perror("Memory allocation error");
        exit(1);
    }
    // Set the length of the array.
    array->length = length;
    // Allocate memory for the integer data array.
    array->dataPtr = (int *)malloc(length * sizeof(int));
    if (array->dataPtr == NULL) {
        // If memory allocation fails, print an error message and exit the program.
        perror("Memory allocation error");
        exit(1);
    }
    return array;
}

// Function to free the memory used by an IntArray and its data.
void freeIntArray(struct IntArray *array) {
    free(array->dataPtr);
    free(array);
}

// Function to read positive integers from the user into the integer array.
void readIntArray(struct IntArray *array) {
    printf("Enter %d positive integers:\n", array->length);
    for (int i = 0; i < array->length; i++) {
        int value;
        while (1) {
            printf("Enter int: ");
            if (scanf("%d", &value) == 1 && value > 0) {
                // Store the valid positive integer in the array.
                array->dataPtr[i] = value;
                break;
            } else {
                printf("Invalid input. Enter a positive int.\n");
                while (getchar() != '\n');
            }
        }
    }
}

// Function to swap the values of two integers.
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to sort the integer array in ascending order using the bubble sort algorithm.
void sortIntArray(struct IntArray *array) {
    for (int i = 0; i < array->length - 1; i++) {
        for (int j = 0; j < array->length - i - 1; j++) {
            if (array->dataPtr[j] > array->dataPtr[j + 1]) {
                // Swap the elements if they are in the wrong order.
                swap(&array->dataPtr[j], &array->dataPtr[j + 1]);
            }
        }
    }
}

// Function to print the elements of the integer array.
void printIntArray(struct IntArray *array) {
    printf("[ ");
    for (int i = 0; i < array->length; i++) {
        printf("%d%s", array->dataPtr[i], (i < array->length - 1) ? ", " : "");
    }
    printf(" ]\n");
}

// Main function to interact with the user, allocate, populate, sort, and print the array.
int main() {
    int length;
    printf("Enter the length of the array: ");
    while (1) {
        if (scanf("%d", &length) == 1 && length > 0) {
            break;
        } else {
            printf("Invalid input. Enter a positive integer.\n");
            while (getchar() != '\n');
        }
    }

    // Allocate memory for an IntArray with the specified length.
    struct IntArray *array = mallocIntArray(length);
    // Read positive integers into the array.
    readIntArray(array);
    // Sort the array in ascending order.
    sortIntArray(array);
    // Print the sorted array.
    printIntArray(array);
    // Free the memory to prevent memory leaks.
    freeIntArray(array);

    return 0;
}
