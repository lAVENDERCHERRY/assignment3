#include <stdio.h>
#include <stdlib.h>

struct IntArray {
    int length;
    int *dataPtr;
};

struct IntArray *mallocIntArray(int length) {
    struct IntArray *array = (struct IntArray *)malloc(sizeof(struct IntArray));
    if (array == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    array->length = length;
    array->dataPtr = (int *)malloc(length * sizeof(int));
    if (array->dataPtr == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    return array;
}

void freeIntArray(struct IntArray *array) {
    free(array->dataPtr);
    free(array);
}

void readIntArray(struct IntArray *array) {
    printf("Enter %d positive integers:\n", array->length);
    for (int i = 0; i < array->length; i++) {
        int value;
        while (1) {
            printf("Enter int: ");
            if (scanf("%d", &value) == 1 && value > 0) {
                array->dataPtr[i] = value;
                break;
            } else {
                printf("Invalid input. Enter a positive int.\n");
                while (getchar() != '\n');
            }
        }
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
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
    printf("[ ");
    for (int i = 0; i < array->length; i++) {
        printf("%d%s", array->dataPtr[i], (i < array->length - 1) ? ", " : "");
    }
    printf(" ]\n");
}

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

    struct IntArray *array = mallocIntArray(length);
    readIntArray(array);
    sortIntArray(array);
    printIntArray(array);
    freeIntArray(array);

    return 0;
}
