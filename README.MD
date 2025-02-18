# Typesafe Generic Arrays in C

A header-only library providing type-safe dynamic arrays in C through macro-based generic programming. This implementation offers common array operations with automatic memory management and includes sorting algorithms.

## Features

- Type-safe generic arrays through C preprocessor macros
- Dynamic resizing with efficient memory management
- Comprehensive array operations including:
  - Insertion and removal
  - Sorting (QuickSort and Insertion Sort)
  - Deep copying
  - Array reversal
  - Element swapping
  - Searching and indexing
  - Mismatch detection between arrays
  - Array clearing
  - Custom format printing

## Usage

1. Include the header file in your project:
```c
#include "generic_arrays.h"
```

2. Define array types for your desired data types using the DEFINE_ARRAY_TYPE macro:
```c
DEFINE_ARRAY_TYPE(int, int)      // Creates Array_int type
DEFINE_ARRAY_TYPE(double, double) // Creates Array_double type
```

3. Use the generated functions:
```c
// Initialize array
Array_int numbers;
array_init_int(&numbers, 4);  // Initial capacity of 4

// Add elements (array will automatically resize)
for(int i = 1; i <= 10; i++) {
    array_add_int(&numbers, i);
}

// Deep copy
Array_int numbers_copy = array_copy_int(&numbers);

// Remove elements
array_remove_int(&numbers, 5);  // Removes first occurrence of 5

// Get element at index
int value = array_return_int(&numbers, 6);

// Swap elements
array_swap_int(&numbers, 0, 8);

// Sort array (using either method)
array_insertion_sort_int(&numbers);
// OR
quicksort_int(&numbers, 0, numbers.length - 1);

// Reverse array
array_reverse_int(&numbers);

// Search operations
int index = array_indexof_int(&numbers, 45);

// Compare arrays
int mismatch = array_mismatch_int(&numbers, &numbers_copy);

// Clear array
array_clear_int(&numbers);

// Free memory when done
array_free_int(&numbers);
array_free_int(&numbers_copy);
```

## Available Functions

For any type `T`, the following functions are generated:

| Function | Description |
|----------|-------------|
| `array_init_T(Array_T *arr, size_t capacity)` | Initialize array with given capacity |
| `array_add_T(Array_T *arr, T value)` | Add element to end of array |
| `array_remove_T(Array_T *arr, T value)` | Remove first occurrence of value |
| `array_return_T(Array_T *arr, int index)` | Get element at index |
| `array_print_T(Array_T *arr, const char* format, size_t length)` | Print array elements with format string |
| `array_copy_T(Array_T *arr)` | Create deep copy of array |
| `array_swap_T(Array_T *arr, int i, int j)` | Swap elements at indices i and j |
| `array_insertion_sort_T(Array_T *arr)` | Sort using insertion sort |
| `quicksort_T(Array_T *arr, int low, int high)` | Sort using quicksort |
| `array_reverse_T(Array_T *arr)` | Reverse array elements |
| `array_indexof_T(Array_T *arr, T value)` | Find index of first occurrence |
| `array_mismatch_T(Array_T *arr1, Array_T *arr2)` | Find first index where arrays differ |
| `array_clear_T(Array_T *arr)` | Remove all elements |
| `array_free_T(Array_T *arr)` | Free array memory |

## Array Structure

Each array type creates a structure with the following members:
```c
typedef struct {
    T* data;           // Pointer to array data
    size_t length;     // Current number of elements
    size_t capacity;   // Total allocated capacity
} Array_T;
```

## Memory Management

- Arrays automatically resize when capacity is reached
- Memory is automatically managed
- Always call `array_free_T()` when done to prevent memory leaks

## Example Program

See `main.c` for a complete example demonstrating all array operations.

## Notes

- All operations are type-safe through macro generation
- Functions include error checking
- The library is header-only for easy integration
- Arrays can be used with any data type
- Format strings for printing must match the data type
