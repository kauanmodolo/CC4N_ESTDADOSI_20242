#include <stdio.h>

// Função principal do Shellsort
void shellsort(int array[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];
            array[j] = temp;
        }
    }
}

// Função para imprimir o array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função main para teste do Shellsort
int main() {
    int array[] = {29, 10, 14, 37, 13};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array original:\n");
    printArray(array, n);

    shellsort(array, n);

    printf("Array ordenado (Shellsort):\n");
    printArray(array, n);

    return 0;
}

// Complexidade:
// Melhor caso: O(n log n)
// Caso médio: depende da sequência de gaps, geralmente entre O(n^(3/2)) e O(n^2)
// Pior caso: O(n^2)
// Espaço: O(1)
