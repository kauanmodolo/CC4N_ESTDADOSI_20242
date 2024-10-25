#include <stdio.h>

#define TAMANHO 50

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função Selection Sort para ordenar o vetor
void selectionSort(int vetor[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i; // Assume o elemento atual como o menor
        for (j = i+1; j < n; j++) {
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j; // Atualiza o índice do menor elemento
            }
        }
        trocar(&vetor[min_idx], &vetor[i]);
    }
}

// Função para imprimir o vetor
void printArray(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    // Definindo o vetor com 50 elementos não ordenados
    int vetor[TAMANHO] = {23, 45, 12, 78, 67, 89, 45, 23, 12, 9, 
                          34, 56, 90, 33, 12, 6, 88, 76, 55, 43, 
                          11, 29, 39, 59, 69, 79, 3, 25, 14, 65,
                          74, 91, 82, 64, 53, 18, 7, 21, 16, 35, 
                          13, 42, 50, 31, 26, 8, 19, 61, 30, 41};

    printf("Vetor original:\n");
    printArray(vetor, TAMANHO);

    // Ordenar o vetor utilizando Selection Sort
    selectionSort(vetor, TAMANHO);

    printf("Vetor ordenado:\n");
    printArray(vetor, TAMANHO);

    return 0;
}
