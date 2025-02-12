#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define 

int main (int argc, char *argv[]) {
	int size = 0;
	printf("Instert array size: ");
	scanf("%d", &size);

	int matrix[size][size] = {0};

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				matrix[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", matrix[i][j]);
		}
	}


	return 0;
}