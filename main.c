#include <stdio.h>
#include "generic_arrays.h"

// Use DEFINE_ARRAY_TYPE macro to create typed array implementations
// This creates all the necessary functions for the specified type
// Example: DEFINE_ARRAY_TYPE(int) creates Array_int and all related functions
DEFINE_ARRAY_TYPE(int)
DEFINE_ARRAY_TYPE(double)

int main() {
    Array_int numbers;
    Array_double decimals;
    
    printf("=== Array Initialization and Adding Elements ===\n");
    // Initialize with capacity 4, then add 10 elements to show auto-resizing
    array_init_int(&numbers, 4);
    printf("Initial state - Length: %zu, Capacity: %zu\n", numbers.length, numbers.capacity);
    
    printf("\nAdding numbers 1-10...\n");
    for(int i = 1; i <= 10; i++) {
        array_add_int(&numbers, i);
        printf("After adding %d - Array: ", i);
        array_print_int(&numbers, "%d ", numbers.length);
        printf("Length: %zu, Capacity: %zu\n", numbers.length, numbers.capacity);
    }
    
    // Deep copy demonstration
    printf("\n=== Array Copy ===\n");
    printf("Original array: ");
    array_print_int(&numbers, "%d ", numbers.length);
    Array_int numbers_copy = array_copy_int(&numbers);
    printf("Copied array:   ");
    array_print_int(&numbers_copy, "%d ", numbers_copy.length);
    
    // Remove element demonstration
    printf("\n=== Remove Element ===\n");
    printf("Before removing 5: ");
    array_print_int(&numbers, "%d ", numbers.length);
    array_remove_int(&numbers, 5);
    printf("After removing 5:  ");
    array_print_int(&numbers, "%d ", numbers.length);
    printf("New length: %zu, New capacity: %zu\n", numbers.length, numbers.capacity);
    
    // Array return (get element) demonstration
    printf("\n=== Get Element ===\n");
    printf("Current array: ");
    array_print_int(&numbers, "%d ", numbers.length);
    int value = array_return_int(&numbers, 6);
    printf("Value at index 6: %d\n", value);
    
    // Swap elements demonstration
    printf("\n=== Swap Elements ===\n");
    printf("Before swap: ");
    array_print_int(&numbers, "%d ", numbers.length);
    array_swap_int(&numbers, 0, 8);
    printf("After swapping positions 0 and 8: ");
    array_print_int(&numbers, "%d ", numbers.length);
    
    // Sorting demonstrations
    printf("\n=== Sorting ===\n");
    Array_int to_sort;
    array_init_int(&to_sort, 10);
    int unsorted_values[] = {64, 34, 25, 12, 22, 11, 90, 45, 33, 21};
    for(int i = 0; i < 10; i++) {
        array_add_int(&to_sort, unsorted_values[i]);
    }
    
    printf("Original unsorted array: ");
    array_print_int(&to_sort, "%d ", to_sort.length);
    
    // Insertion sort
    Array_int insertion_sort_array = array_copy_int(&to_sort);
    printf("\nInsertion Sort:\n");
    printf("Before: ");
    array_print_int(&insertion_sort_array, "%d ", insertion_sort_array.length);
    array_insertion_sort_int(&insertion_sort_array);
    printf("After:  ");
    array_print_int(&insertion_sort_array, "%d ", insertion_sort_array.length);
    
    // Quicksort
    Array_int quicksort_array = array_copy_int(&to_sort);
    printf("\nQuicksort:\n");
    printf("Before: ");
    array_print_int(&quicksort_array, "%d ", quicksort_array.length);
    quicksort_int(&quicksort_array, 0, quicksort_array.length - 1);
    printf("After:  ");
    array_print_int(&quicksort_array, "%d ", quicksort_array.length);
    
    // Array reverse demonstration
    printf("\n=== Array Reverse ===\n");
    printf("Before reverse: ");
    array_print_int(&quicksort_array, "%d ", quicksort_array.length);
    array_reverse_int(&quicksort_array);
    printf("After reverse:  ");
    array_print_int(&quicksort_array, "%d ", quicksort_array.length);
    
    // Search operation demonstration
    printf("\n=== Search Operations ===\n");
    printf("Searching in array: ");
    array_print_int(&to_sort, "%d ", to_sort.length);
    int search_value = 45;
    int index = array_indexof_int(&to_sort, search_value);
    printf("Index of %d: %d\n", search_value, index);
    
    // Array mismatch demonstration
    printf("\n=== Array Mismatch ===\n");
    Array_int arr1, arr2;
    array_init_int(&arr1, 10);
    array_init_int(&arr2, 10);
    
    for(int i = 1; i <= 10; i++) {
        array_add_int(&arr1, i);
        array_add_int(&arr2, i);
    }
    printf("Initial arrays (identical):\n");
    printf("Array 1: ");
    array_print_int(&arr1, "%d ", arr1.length);
    printf("Array 2: ");
    array_print_int(&arr2, "%d ", arr2.length);
    
    printf("\nModifying Array 2 at index 7...\n");
    arr2.data[7] = 99;
    printf("After modification:\n");
    printf("Array 1: ");
    array_print_int(&arr1, "%d ", arr1.length);
    printf("Array 2: ");
    array_print_int(&arr2, "%d ", arr2.length);
    
    int mismatch = array_mismatch_int(&arr1, &arr2);
    printf("First mismatch at index: %d\n", mismatch);
    
    // Array clear demonstration
    printf("\n=== Array Clear ===\n");
    printf("Before clear: ");
    array_print_int(&arr1, "%d ", arr1.length);
    array_clear_int(&arr1);
    printf("After clear - Length: %zu (array is now empty)\n", arr1.length);
    
    // Always free arrays when done to prevent memory leaks
    array_free_int(&numbers);
    array_free_int(&numbers_copy);
    array_free_int(&to_sort);
    array_free_int(&insertion_sort_array);
    array_free_int(&quicksort_array);
    array_free_int(&arr1);
    array_free_int(&arr2);
    array_free_double(&decimals);
    
    return 0;
}