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
| `array_init_T(Array_T *arr, size_t capacity)` | Initialize array with given capacity |
| `array_add_T(Array_T *arr, T value)` | Add element to array |
| `array_remove_T(Array_T *arr, T value)` | Remove first occurrence of value |
| `array_free_T(Array_T *arr)` | Free array memory |
| `array_return_T(Array_T *arr, int index)` | Get element at index |
| `array_print_T(Array_T *arr, const char* format, size_t upper_bound)` | Print array elements |
| `array_insertion_sort_T(Array_T *arr)` | Sort using insertion sort |
| `array_quicksort_T(Array_T *arr, int low, int high)` | Sort using quicksort |
| `array_reverse_T(Array_T *arr)` | Reverse array elements |
| `array_indexof_T(Array_T *arr, T goal)` | Find index of element |
| `array_contains_T(Array_T *arr, T goal)` | Check if element exists |
| `array_clear_T(Array_T *arr)` | Remove all elements |
| `array_copy_T(Array_T *arr)` | Create deep copy of array |

## Memory Management

The array automatically grows when elements are added and the capacity is reached. When the array is less than 25% full, it will automatically shrink to save memory. The growth factor is 2x and the shrink factor is 0.5x.

## Notes

- All operations are type-safe
- Memory is automatically managed
- Error checking is included for all operations
- The library is header-only for easy integration

## License
This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). 
