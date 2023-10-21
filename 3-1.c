#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        bool validInput = false;
        while (!validInput) {
            printf("Enter int: ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                char *endpoint;
                long num = strtol(input, &endpoint, 10);
                if (*endpoint == '\n' || (*endpoint == '\0' && endpoint != input)) {
                    if (num > 0) {
                        array->dataPtr[i] = (int)num;
                        validInput = true;
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
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
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
    printf("[");
    for (int i = 0; i < array->length; i++) {
        printf(" %d", array->dataPtr[i]);
        if (i < array->length - 1) {
            printf(",");
        }
    }
    printf(" ]\n");
}

int main() {
    int length;
    char input[20];
    bool validInput = false;

    while (!validInput) {
        printf("Enter length: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            char *endpoint;
            long num = strtol(input, &endpoint, 10);
            if (*endpoint == '\n' || (*endpoint == '\0' && endpoint != input)) {
                if (num > 0) {
                    length = (int)num;
                    validInput = true;
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
