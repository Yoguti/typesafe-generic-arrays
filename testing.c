#include <stdio.h>
#include <stdlib.h>

void remove_at(int *, int *, int);
void invert(int *, int);
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

    invert(buff, n);

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

void invert(int *arr, int size) {
	int tail = size - 1;
	for (int i = 0; i < size / 2; i++) {
		int aux = arr[i];
		arr[i] = arr[tail];
		arr[tail] = aux;
		tail--;
	}

}
