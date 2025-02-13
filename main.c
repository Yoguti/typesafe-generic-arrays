#include <stdio.h>
#include "generic_arrays.h"

// Define an array type for `int`
DEFINE_ARRAY_TYPE(int)

int main() {
    Array_int arr;
    array_init_int(&arr, 4);
    array_add_int(&arr, 10);
    array_add_int(&arr, 20);
    printf("Array length: %zu\n", arr.length);
    array_free_int(&arr);
    return 0;
}
