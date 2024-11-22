#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
typedef struct Nodo {
    int chave;
    struct Nodo *esq, *dir;
} Nodo;

// Função para criar um novo nó
Nodo* criarNodo(int chave) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->chave = chave;
    novo->esq = novo->dir = NULL;
    return novo;
}

// Função para adicionar um elemento na árvore
Nodo* adicionar(Nodo* raiz, int chave) {
    if (raiz == NULL) return criarNodo(chave);

    if (chave < raiz->chave)
        raiz->esq = adicionar(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = adicionar(raiz->dir, chave);

    return raiz;
}

// Função para exibir os elementos em ordem crescente
void exibirEmOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        exibirEmOrdem(raiz->dir);
    }
}

// Função principal
int main() {
    Nodo* raiz = NULL;

    // Inserindo valores na árvore
    raiz = adicionar(raiz, 50);
    adicionar(raiz, 30);
    adicionar(raiz, 20);
    adicionar(raiz, 40);
    adicionar(raiz, 70);
    adicionar(raiz, 60);
    adicionar(raiz, 80);

    // Exibindo os valores em ordem
    printf("Elementos da árvore em ordem crescente: ");
    exibirEmOrdem(raiz);

    return 0;
}
