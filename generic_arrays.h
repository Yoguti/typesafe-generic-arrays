#ifndef GEN_ARR
#define GEN_ARR

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEFINE_ARRAY_TYPE(T) \
    typedef struct { \
        T *data; \
        size_t length; \
        size_t capacity; \
    } Array_##T; \
    \
    static Array_##T array_copy_##T(Array_##T *arr) { \
        Array_##T array_copy; \
        array_copy.data = (T *)malloc(sizeof(T) * arr->capacity); \
        if (!array_copy.data) { \
            array_copy.length = 0; \
            array_copy.capacity = 0; \
            return array_copy; \
        } \
        array_copy.length = arr->length; \
        array_copy.capacity = arr->capacity; \
        for (int i = 0; i < (int) arr->length; i++) { \
            array_copy.data[i] = arr->data[i]; \
        } \
        return array_copy; \
    } \    
    \
    static void array_init_##T(Array_##T *arr, size_t capacity) { \
        arr->data = (T *)malloc(sizeof(T) * capacity); \
        arr->length = 0; \
        arr->capacity = capacity; \
    } \
    \
    static void array_add_##T(Array_##T *arr, T value) { \
        if (arr->length >= arr->capacity) { \
            size_t new_capacity = arr->capacity ? arr->capacity * 2 : 1; \
            T *new_data = (T *)realloc(arr->data, sizeof(T) * new_capacity); \
            if (!new_data) return; \
            arr->data = new_data; \
            arr->capacity = new_capacity; \
        } \
        arr->data[arr->length++] = value; \
    } \
    \
    static void array_remove_##T(Array_##T *arr, T value) { \
        for (size_t i = 0; i < arr->length; i++) { \
            if (arr->data[i] == value) { \
                for (size_t j = i; j < arr->length - 1; j++) { \
                    arr->data[j] = arr->data[j + 1]; \
                } \
                arr->length--; \
                \
                /* Shrink array if under 25% usage */ \
                if (arr->length < arr->capacity / 4 && arr->capacity > 1) { \
                    size_t new_capacity = arr->capacity / 2; \
                    T *new_data = (T *)realloc(arr->data, sizeof(T) * new_capacity); \
                    if (new_data) { \
                        arr->data = new_data; \
                        arr->capacity = new_capacity; \
                    } \
                } \
                return; \
            } \
        } \
    } \
    static void array_free_##T(Array_##T *arr) { \
        free(arr->data); \
        arr->data = NULL; \
        arr->length = 0; \
        arr->capacity = 0; \
    } \
    \
    static T array_return_##T(Array_##T *arr, int index) { \
        if (index < arr->length && index >= 0) { \
            return  arr->data[index]; \
        } \
    } \
    \
    static void array_print_##T(const Array_##T *arr, const char* format, size_t upper_bound) { \
        if (upper_bound > arr->length) upper_bound = arr->length; \
        for (size_t i = 0; i < upper_bound; i++) { \
            printf(format, arr->data[i]); \
        } \
        printf("\n"); \
    } \
    \
    static void array_insertion_sort_##T(Array_##T *arr) { \
        for (int i = 1; i < (int) arr->length; i++) { \
            T current = arr->data[i]; \
            int j = i - 1; \
            while (j >= 0 && arr->data[j] > current) { \
                arr->data[j+1] = arr->data[j]; \
                j--; \
            } \
            arr->data[j+1] = current; \
        } \
    } \
    \
    static void array_swap_##T(Array_##T *arr, int first, int second) { \
        if (first < (int) arr->length && second < (int) arr->length) { \
            if (first >= 0  && second >= 0) { \
                T aux = arr->data[second]; \
                arr->data[second] = arr->data[first]; \
                arr->data[first] = aux; \
            } \
        } \
    } \
    \
    static int partition_##T(Array_##T *arr, int low, int high) { \
        if (low < 0 || high >= (int)arr->length || low > high) return -1; \
        T pivot = arr->data[high]; \
        int i = low - 1; \
        for (int j = low; j < high; j++) { \
            if (arr->data[j] <= pivot) { \
                i++; \
                array_swap_##T(arr, i, j); \
            } \
        } \
        array_swap_##T(arr, i + 1, high); \
        return i + 1; \
    } \
    \
    static void quicksort_##T(Array_##T *arr, int low, int high) { \
        if (low < 0 || high >= (int)arr->length || low >= high) return; \
        int pi = partition_##T(arr, low, high); \
        if (pi == -1) return; \
        quicksort_##T(arr, low, pi - 1); \
        quicksort_##T(arr, pi + 1, high); \
    } \
    \
    static void array_reverse_##T(Array_##T *arr) { \
        for (int i = 0; i < (int)arr->length / 2; i++) { \
            T temp = arr->data[i]; \
            arr->data[i] = arr->data[arr->length - 1 - i]; \
            arr->data[arr->length - 1 - i] = temp; \
        } \
    } \
    \
    static int array_indexof_##T(Array_##T *arr, T goal) { \
        int i = 0; \
        while (i < arr->length) { \
             if (arr->data[i] == goal) { \
                return i; \
             } \
             i++; \
        } \
        return -1; \
    } \
    \
    static bool array_contains_##T(Array_##T *arr, T goal) { \
        return array_indexof_##T != -1; \
    } \
    \
    static void array_clear_##T(Array_##T *arr) { \
        arr->length = 0; \
    } \

    /*
        array_copy_##T
        array_mismatch_##T

    */

#endif // GEN_ARR_H
