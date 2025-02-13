# Generic Array Implementation in C

A header-only library providing type-safe dynamic arrays in C through macro-based generic programming. This implementation offers common array operations with automatic memory management and includes sorting algorithms.

## Features

- Type-safe generic arrays through C preprocessor macros
- Dynamic resizing with efficient memory management
- Automatic shrinking when array is under-utilized
- Comprehensive array operations including:
  - Insertion and removal
  - Sorting (QuickSort and Insertion Sort)
  - Searching and containment checks
  - Array reversal
  - Printing with custom format strings
  - Deep copying
  - Clear operations

## Usage

1. Include the header file in your project:
#include "gen_arr.h"

2. Define an array type for your desired data type:
DEFINE_ARRAY_TYPE(int)  // Creates Array_int type

3. Use the generated functions:
// Initialize array
Array_int numbers;
array_init_int(&numbers, 10);  // Initial capacity of 10

// Add elements
array_add_int(&numbers, 42);
array_add_int(&numbers, 17);

// Sort array
array_quicksort_int(&numbers, 0, numbers.length - 1);

// Print array
array_print_int(&numbers, "%d ", numbers.length);

// Free memory
array_free_int(&numbers);

## Available Functions

For any type `T`, the following functions are generated:

| Function | Description |
|----------|-------------|
| `array_init_T(Array_T *arr, size_t capacity)` | Initialize array with given capacity. Returns nothing. |
| `array_add_T(Array_T *arr, T value)` | Add an element to the array. Returns nothing. |
| `array_remove_T(Array_T *arr, T value)` | Remove the first occurrence of `value` from the array. Returns nothing. |
| `array_free_T(Array_T *arr)` | Free memory allocated for the array. Returns nothing. |
| `array_return_T(Array_T *arr, int index)` | Get the element at the specified index. Returns the element at the given index, or undefined behavior if index is out of range. |
| `array_print_T(Array_T *arr, const char* format, size_t upper_bound)` | Print array elements up to `upper_bound` using the provided format. Returns nothing. |
| `array_insertion_sort_T(Array_T *arr)` | Sort the array using the insertion sort algorithm. Returns nothing. |
| `array_quicksort_T(Array_T *arr, int low, int high)` | Sort the array using the quicksort algorithm within the given range (`low` to `high`). Returns nothing. |
| `array_reverse_T(Array_T *arr)` | Reverse the array elements. Returns nothing. |
| `array_indexof_T(Array_T *arr, T goal)` | Find the index of the element `goal`. Returns the index of the first occurrence, or -1 if the element is not found. |
| `array_contains_T(Array_T *arr, T goal)` | Check if the element `goal` exists in the array. Returns `true` if found, otherwise `false`. |
| `array_clear_T(Array_T *arr)` | Remove all elements from the array. Returns nothing. |
| `array_copy_T(Array_T *arr)` | Create a deep copy of the array. Returns a new `Array_T` with a copied content. |
| `array_mismatch_T(Array_T *arr, Array_T *second_arr)` | Find the first index where the two arrays mismatch. Returns -1 if arrays are identical, or the index of the mismatch. If arrays have different lengths, returns -2. |

## Memory Management

The array automatically grows when elements are added and the capacity is reached. When the array is less than 25% full, it will automatically shrink to save memory. The growth factor is 2x and the shrink factor is 0.5x.

## Notes

- All operations are type-safe
- Memory is automatically managed
- Error checking is included for all operations
- The library is header-only for easy integration
