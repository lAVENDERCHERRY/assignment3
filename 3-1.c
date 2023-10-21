#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct IntArray {
    int length;
    int *dataPtr;
};

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

void freeIntArray(struct IntArray *arrayPtr) {
    free(arrayPtr->dataPtr);
    free(arrayPtr);
}

void readIntArray(struct IntArray *array) {
    printf("Enter %d positive integers:\n", array->length);
    for (int i = 0; i < array->length; i++) {
        char input[20];
        bool validInput = false;
        while (!validInput) {
            printf("Enter int: ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                char *endptr;
                long num = strtol(input, &endptr, 10);
                if (*endptr == '\n' || *endptr == '\0' && endptr != input) {
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

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortIntArray(struct IntArray *array) {
    for (int i = 0; i < array->length - 1; i++) {
        for (int j = 0; j < array->length - i - 1; j++) {
            if (array->dataPtr[j] > array->dataPtr[j + 1]) {
                swap(&array->dataPtr[j], &array->dataPtr[j + 1]);
            }
        }
    }
}

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

int readPositiveInt() {
    int num;
    char input[20];
    bool validInput = false;

    while (!validInput) {
        printf("Enter an integer: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            char *endptr;
            long val = strtol(input, &endptr, 10);
            if ((*endptr == '\n' || *endptr == '\0') && endptr != input) {
                num = (int)val;
                if (num > 0) {
                    validInput = true;
                } else {
                    printf("Invalid input. Enter a positive int.\n");
                }
            } else {
                printf("Invalid input.\n");
            }
        } else {
            printf("Error reading input.\n");
            exit(1);
        }
    }
    return num;
}

int main() {
    int length = readPositiveInt();

    struct IntArray *array = mallocIntArray(length);
    readIntArray(array);
    sortIntArray(array);
    printIntArray(array);
    freeIntArray(array);

    return 0;
}