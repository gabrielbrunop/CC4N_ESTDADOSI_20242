#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int left, int middle, int right) {
    int i, j, k;
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int *leftArray = malloc(leftSize * sizeof(int));
    int *rightArray = malloc(rightSize * sizeof(int));

    for (i = 0; i < leftSize; i++)
        leftArray[i] = array[left + i];
    for (j = 0; j < rightSize; j++)
        rightArray[j] = array[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

void printArray(int array[], int size) {
    printf("Array ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    mergeSort(numeros, 0, tamanho - 1);
    printArray(numeros, tamanho);

    return 0;
}