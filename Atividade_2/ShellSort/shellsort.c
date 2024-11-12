#include <stdio.h>

void shellSort(int array[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = array[i];
            int j;

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
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

    shellSort(numeros, tamanho);
    printArray(numeros, tamanho);

    return 0;
}