#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent an array of integers
struct IntArray {
    int length;    // Length of the array
    int *dataPtr;  // Pointer to the array data
};

// Allocate memory for the struct and the integer array, and initialize the struct
struct IntArray *mallocIntArray(int length) {
    // Allocate memory for the IntArray struct and store its address in 'array'
    struct IntArray *array = (struct IntArray *)malloc(sizeof(struct IntArray));
    
    // Check if the memory allocation for the struct was successful
    if (array == NULL) {
        // Print an error message
        perror("Memory allocation error");
        // Terminate the program with an error code (1)
        exit(1);
    }
    
    // Set the 'length' member of the 'array' struct to the specified 'length' argument
    array->length = length;
    
    // Allocate memory for the integer array and store its address in 'array->dataPtr'
    array->dataPtr = (int *)malloc(length * sizeof(int));
    
    // Check if the memory allocation for the array was successful
    if (array->dataPtr == NULL) {
        // Print an error message
        perror("Memory allocation error");
        // Terminate the program with an error code (1)
        exit(1);
    }
    
    // Return a pointer to the initialized 'array' struct
    return array;
}

// Free the memory allocated for the struct and the integer array
void freeIntArray(struct IntArray *array) {
    free(array->dataPtr);  // Free memory of the array data
    free(array);           // Free memory of the struct
}

// Read positive integers from the user into the integer array
void readIntArray(struct IntArray *array) {
    // Prompt the user to enter positive integers
    printf("Enter %d positive integers:\n", array->length);

    // Loop through the array's elements
    for (int i = 0; i < array->length; i++) {
        int value;

        // Enter a loop that ensures valid input
        while (1) {
            // Prompt the user to enter an integer
            printf("Enter int: ");
            
            // Check if a valid integer is entered, and it's greater than 0
            if (scanf("%d", &value) == 1 && value > 0) {
                // Store the valid positive integer in the array
                array->dataPtr[i] = value;
                break;  // Exit the loop
            } else {
                // Print an error message for invalid input
                printf("Invalid input. Enter a positive int.\n");
                
                // Consume and discard any remaining characters in the input buffer
                while (getchar() != '\n');
            }
        }
    }
}


// Swap the values of two integers
void swap(int *x, int *y) {
    int temp = *x; // in order to swap we need to store x into a temp variable 
    *x = *y; //swap x with y 
    *y = temp; // use x value stored in temp and overwrite y
}

// Sort the integer array in ascending order using the bubble sort algorithm
void sortIntArray(struct IntArray *array) {
    // Outer loop to iterate through each element in the array
    for (int i = 0; i < array->length - 1; i++) {
        // Inner loop to compare adjacent elements and swap if necessary
        for (int j = 0; j < array->length - i - 1; j++) {
            // Check if the current element is greater than the next element
            if (array->dataPtr[j] > array->dataPtr[j + 1]) {
                // Swap the elements if they are in the wrong order
                swap(&array->dataPtr[j], &array->dataPtr[j + 1]);
            }
        }
    }
}


// Print the elements of the integer array
void printIntArray(struct IntArray *array) {
    // Print the opening bracket for the array
    printf("[ ");

    // Loop through the elements of the array
    for (int i = 0; i < array->length; i++) {
        // Print the current element's value
        printf("%d", array->dataPtr[i]);

        // Print a comma and space if it's not the last element
        printf("%s", (i < array->length - 1) ? ", " : "");
    }

    // Print the closing bracket for the array and a newline character
    printf(" ]\n");
}


// Main function to interact with the user, allocate, populate, sort, and print the array
int main() {
    int length;
    
    // Prompt the user to enter the length of the array
    printf("Enter the length of the array: ");
    
    // Enter a loop that ensures valid input for the array's length
    while (1) {
        // Check if a valid integer (length) is entered, and it's greater than 0
        if (scanf("%d", &length) == 1 && length > 0) {
            break;  // Exit the loop
        } else {
            // Print an error message for invalid input
            printf("Invalid input. Enter a positive integer.\n");
            
            // Consume and discard any remaining characters in the input buffer
            while (getchar() != '\n');
        }
    }

    // Allocate memory for the integer array and initialize the array struct
    struct IntArray *array = mallocIntArray(length);
    
    // Read positive integers from the user and store them in the array
    readIntArray(array);
    
    // Sort the array in ascending order
    sortIntArray(array);
    
    // Print the sorted array
    printIntArray(array);
    
    // Free memory to prevent memory leaks
    freeIntArray(array);
    
    // Indicate successful program execution by returning 0
    return 0;
}

