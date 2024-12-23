#include <stdio.h>

#define MAX 100

// Function to display the array
void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
void insert(int arr[], int *size, int element, int position) {
    if (*size >= MAX) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }

    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element; // Insert element
    (*size)++;
    printf("Element %d inserted at position %d.\n", element, position);
}

// Function to delete an element at a specific position
void delete(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }

    printf("Element %d deleted from position %d.\n", arr[position], position);

    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

int main() {
    int arr[MAX], size = 0;
    int choice, element, position;

    printf("Enter initial size of array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            printf("Enter position to insert (0-based index): ");
            scanf("%d", &position);
            insert(arr, &size, element, position);
            break;
        case 2:
            printf("Enter position to delete (0-based index): ");
            scanf("%d", &position);
            delete(arr, &size, position);
            break;
        case 3:
            display(arr, size);
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
