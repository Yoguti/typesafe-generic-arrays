#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

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
    static inline void array_add_##T(Array_##T *arr, T value, bool reallocate) { \
        if (arr->length >= arr->capacity) { \
            if (reallocate) { \
                size_t new_capacity = arr->capacity ? arr->capacity * 2 : 1; \
                T *new_data = (T *)realloc(arr->data, sizeof(T) * new_capacity); \
                if (new_data) { \
                    arr->data = new_data; \
                    arr->capacity = new_capacity; \
                } \
            } \
        } \
        arr->data[arr->length++] = value; \
    } \
    \
    static inline void array_remove_##T(Array_##T *arr, T value, bool reallocate) { \
        for (size_t i = 0; i < arr->length; i++) { \
            if (arr->data[i] == value) { \
                for (size_t j = i; j < arr->length - 1; j++) { \
                    arr->data[j] = arr->data[j + 1]; \
                } \
                arr->length--; \
                \
                /* Shrink array if under 25% usage */ \
                if (reallocate && arr->length < arr->capacity / 4 && arr->capacity > 1) { \
                    size_t new_capacity = arr->capacity / 2; \
                    T *new_data = (T *)realloc(arr->data, sizeof(T) * new_capacity); \
                    if (new_data) { \
                        arr->data = new_data; \
                        arr->capacity = new_capacity; \
                    } \
                } \
                return; /* Stop after removing first match */ \
            } \
        } \
    } \
    \
    static inline void array_free_##T(Array_##T *arr) { \
        free(arr->data); \
        arr->data = NULL; \
        arr->length = 0; \
        arr->capacity = 0; \
    } \
    \
    static inline T array_return_##T(Array_##T *arr, int index) { \
        if (index < arr->length) { \
            return  arr->data[index]; \     
        } \
    } \
    \
    static inline void array_print_##T(const Array_##T *arr, void (*func)(T)) { \
        for (size_t i = 0; i < arr->length; i++) { \
            func(arr->data[i]); \
        } \
    } \

    void print_int(int value) {
        printf("%d ", value);
    }

    void print_float(float value) {
        printf("%.2f ", value);
    }

    void print_double(double value) {
        printf("%.2f ", value);
    }

    void print_char(char value) {
        printf("%c ", value);
    }

    void print_long(long value) {
        printf("%ld ", value);
    }

    void print_short(short value) {
        printf("%hd ", value);
    }

    void print_unsigned_int(unsigned int value) {
        printf("%u ", value);
    }

    void print_unsigned_long(unsigned long value) {
        printf("%lu ", value);
    }

    void print_unsigned_short(unsigned short value) {
        printf("%hu ", value);
    }

    void print_unsigned_char(unsigned char value) {
        printf("%c ", value);
    }



#endif // ARRAY_H
