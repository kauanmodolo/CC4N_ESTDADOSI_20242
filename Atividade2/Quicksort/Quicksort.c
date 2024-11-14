#include <stdio.h>

// Função auxiliar para trocar elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de particionamento do Quicksort
int partition(int array[], int low, int high) {
    int pivot = array[high]; // Escolhe o último elemento como pivô
    int i = (low - 1); // Índice do menor elemento
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// Função principal do Quicksort
void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

// Função para imprimir o array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função main para teste do Quicksort
int main() {
    int array[] = {29, 10, 14, 37, 13};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array original:\n");
    printArray(array, n);

    quicksort(array, 0, n - 1);

    printf("Array ordenado (Quicksort):\n");
    printArray(array, n);

    return 0;
}

// Complexidade:
// Melhor caso: O(n log n)
// Caso médio: O(n log n)
// Pior caso: O(n^2)
// Espaço: O(log n) devido à recursão
