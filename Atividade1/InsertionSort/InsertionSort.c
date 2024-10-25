#include <stdio.h>

#define TAMANHO 50

// Função Insertion Sort para ordenar o vetor
void insertionSort(int vetor[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;

        // Move os elementos do vetor[0..i-1] que são maiores que a chave
        // uma posição para frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
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

    // Ordenar o vetor utilizando Insertion Sort
    insertionSort(vetor, TAMANHO);

    printf("Vetor ordenado:\n");
    printArray(vetor, TAMANHO);

    return 0;
}
