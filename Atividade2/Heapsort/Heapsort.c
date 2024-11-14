#include <stdio.h>

// Função auxiliar para trocar elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para criar um heap máximo
void heapify(int array[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

// Função principal do Heapsort
void heapsort(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

// Função para imprimir o array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função main para teste do Heapsort
int main() {
    int array[] = {29, 10, 14, 37, 13};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array original:\n");
    printArray(array, n);

    heapsort(array, n);

    printf("Array ordenado (Heapsort):\n");
    printArray(array, n);

    return 0;
}

// Complexidade:
// Melhor caso: O(n log n)
// Caso médio: O(n log n)
// Pior caso: O(n log n)
// Espaço: O(1), pois é um algoritmo em local
