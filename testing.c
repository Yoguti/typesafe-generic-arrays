#include <stdio.h>
#include <stdlib.h>

void remove_at(int *, int *, int);

int main(void) {

    int n = 10;
    int *buff = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        buff[i] = rand() % 100;
    }
    printf("\n");

    for (int j = 0; j < n; j++) {
        printf("%d ", buff[j]);
    }
    printf("\n");

    remove_at(buff, &n, 3);

    for (int j = 0; j < n; j++) {
        printf("%d ", buff[j]);
    }


    free(buff);



    return 0;
}

void remove_at(int *arr, int *size, int at) {
    int i = at;
    for (; i < *size; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;  
    arr = realloc(arr, (*size) * sizeof(int));

}