#include <stdio.h>
#include <stdlib.h>

// Struct definition
struct IntArray {
    int length;
    int *dataPtr;
};

// Function to allocate and initialize the IntArray
struct IntArray* mallocIntArray(int length) {
    struct IntArray *array = (struct IntArray*)malloc(sizeof(struct IntArray));
    if (array == NULL) {
        perror("mallocIntArray");
        exit(1);
    }
    array->length = length;
    array->dataPtr = (int*)malloc(length * sizeof(int));
    if (array->dataPtr == NULL) {
        perror("malloc");
        exit(1);
    }
    return array;
}

// Function to free the IntArray
void freeIntArray(struct IntArray *arrayPtr) {
    free(arrayPtr->dataPtr);
    free(arrayPtr);
}

// Function to read positive ints from the user to fill the array
void readIntArray(struct IntArray *array) {
    printf("Enter %d positive integers:\n", array->length);
    for (int i = 0; i < array->length; i++) {
        char input[20];
        int num;
        while (1) {
            printf("Enter int: ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                char *endptr;
                long num = strtol(input, &endptr, 10);
                if (*endptr == '\n' || (*endptr == '\0' && endptr != input)) {
                    if (num > 0) {
                        array->dataPtr[i] = (int)num;
                        break;
                    } else {
                        printf("Invalid input. Enter a positive int.\n");
                    }
                } else {
                    printf("Invalid input. Enter a valid int.\n");
                }
            } else {
                printf("Error reading input.\n");
                exit(1);
            }
        }
    }
}

// Function to swap two integers
void swap(int *xp, int *yp) {
    int swapint = *xp; // Store the value of the first element in 'swapint'
    *xp = *yp; // Assign the value of the second element to the first element
    *yp = swapint; // Assign the value stored in 'swapint' to the second element
}

// Function to sort the IntArray using Bubble Sort
void sortIntArray(struct IntArray *array) {
    for (int i = 0; i < array->length - 1; i++) {
        for (int j = 0; j < array->length - i - 1; j++) {
            if (array->dataPtr[j] > array->dataPtr[j + 1]) {
                swap(&array->dataPtr[j], &array->dataPtr[j + 1]);
            }
        }
    }
}

// Function to print the IntArray
void printIntArray(struct IntArray *array) {
    printf("[ ");
    for (int i = 0; i < array->length; i++) {
        printf("%d", array->dataPtr[i]);
        if (i < array->length - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

int main() {
    int length;
    char input[20];

    while (1) {
        printf("Enter the length of the array ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            char *endptr;
            long num = strtol(input, &endptr, 10);
            if (*endptr == '\n' || (*endptr == '\0' && endptr != input)) {
                if (num > 0) {
                    length = (int)num;
                    break;
                } else {
                    printf("Invalid input. Enter a positive int.\n");
                }
            } else {
                printf("Invalid input. Enter a valid int.\n");
            }
        } else {
            printf("Error reading input.\n");
            exit(1);
        }
    }

    struct IntArray *array = mallocIntArray(length);
    readIntArray(array);
    sortIntArray(array);
    printIntArray(array);
    freeIntArray(array);

    return 0;
}