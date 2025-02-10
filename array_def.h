#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

// data: A pointer to dynamically allocated memory (the array).
// length: The number of actual elements stored.
// capacity: The total allocated space.

#define DEFINE_ARRAY_TYPE(T) \
    typedef struct { \
        T *data; \
        size_t length; \
        size_t capacity; \
    } Array_##T; \
    \
    static inline void array_init_##T(Array_##T *arr, size_t capacity) { \
        arr->data = (T *)malloc(sizeof(T) * capacity); \
        arr->length = 0; \
        arr->capacity = capacity; \
    } \
    \
    static inline void array_add_##T(Array_##T *arr, T value) { \
        if (arr->length >= arr->capacity) { \
            arr->capacity *= 2; \
            arr->data = (T *)realloc(arr->data, sizeof(T) * arr->capacity); \
        } \
        arr->data[arr->length++] = value; \
    } \
    \
    static inline void array_remove_##T(Array_##T *arr, T value) { \
        if (arr->length >= arr->capacity) { \
            arr->capacity *= 2; \
            arr->data = (T *)realloc(arr->data, sizeof(T) * arr->capacity); \
        } \
        arr->data[arr->length++] = value; \
    } \
    \
    static inline void array_free_##T(Array_##T *arr) { \
        free(arr->data); \
    }

#endif // ARRAY_H
