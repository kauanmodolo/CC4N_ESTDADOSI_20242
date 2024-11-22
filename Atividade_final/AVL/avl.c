#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da árvore AVL
typedef struct NoAVL {
    int valor;
    struct NoAVL *esq;
    struct NoAVL *dir;
    int altura;
} NoAVL;

// Função para calcular a altura de um nó
int alturaNo(NoAVL *nodo) {
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}

// Função para obter o maior entre dois valores
int maior(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó
NoAVL* criarNo(int valor) {
    NoAVL* novo = (NoAVL*)malloc(sizeof(NoAVL));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura = 1;
    return novo;
}

// Função para realizar rotação à direita
NoAVL *rotacaoParaDireita(NoAVL *y) {
    NoAVL *x = y->esq;
    NoAVL *T2 = x->dir;

    // Rotação
    x->dir = y;
    y->esq = T2;

    // Atualizar alturas
    y->altura = maior(alturaNo(y->esq), alturaNo(y->dir)) + 1;
    x->altura = maior(alturaNo(x->esq), alturaNo(x->dir)) + 1;

    return x;
}

// Função para realizar rotação à esquerda
NoAVL *rotacaoParaEsquerda(NoAVL *x) {
    NoAVL *y = x->dir;
    NoAVL *T2 = y->esq;

    // Rotação
    y->esq = x;
    x->dir = T2;

    // Atualizar alturas
    x->altura = maior(alturaNo(x->esq), alturaNo(x->dir)) + 1;
    y->altura = maior(alturaNo(y->esq), alturaNo(y->dir)) + 1;

    return y;
}

// Função para calcular o fator de balanceamento
int fatorDeBalanceamento(NoAVL *nodo) {
    if (nodo == NULL)
        return 0;
    return alturaNo(nodo->esq) - alturaNo(nodo->dir);
}

// Função para inserir um valor na árvore AVL
NoAVL* adicionarNo(NoAVL* nodo, int valor) {
    // Inserção padrão na árvore binária de busca
    if (nodo == NULL)
        return criarNo(valor);

    if (valor < nodo->valor)
        nodo->esq = adicionarNo(nodo->esq, valor);
    else if (valor > nodo->valor)
        nodo->dir = adicionarNo(nodo->dir, valor);
    else // Não permite valores duplicados
        return nodo;

    // Atualizar altura do nó atual
    nodo->altura = 1 + maior(alturaNo(nodo->esq), alturaNo(nodo->dir));

    // Verificar o fator de balanceamento
    int balanceamento = fatorDeBalanceamento(nodo);

    // Resolver os casos de desbalanceamento

    // Caso Esquerda-Esquerda
    if (balanceamento > 1 && valor < nodo->esq->valor)
        return rotacaoParaDireita(nodo);

    // Caso Direita-Direita
    if (balanceamento < -1 && valor > nodo->dir->valor)
        return rotacaoParaEsquerda(nodo);

    // Caso Esquerda-Direita
    if (balanceamento > 1 && valor > nodo->esq->valor) {
        nodo->esq = rotacaoParaEsquerda(nodo->esq);
        return rotacaoParaDireita(nodo);
    }

    // Caso Direita-Esquerda
    if (balanceamento < -1 && valor < nodo->dir->valor) {
        nodo->dir = rotacaoParaDireita(nodo->dir);
        return rotacaoParaEsquerda(nodo);
    }

    return nodo;
}

// Função para imprimir a árvore AVL em pré-ordem
void imprimirPreOrdem(NoAVL *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);
    }
}

// Função para imprimir a árvore AVL em ordem (crescente)
void imprimirEmOrdem(NoAVL *raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->dir);
    }
}

// Função principal
int main() {
    NoAVL *raiz = NULL;

    // Inserir elementos na árvore AVL
    raiz = adicionarNo(raiz, 10);
    raiz = adicionarNo(raiz, 20);
    raiz = adicionarNo(raiz, 30);
    raiz = adicionarNo(raiz, 40);
    raiz = adicionarNo(raiz, 50);
    raiz = adicionarNo(raiz, 25);

    // Exibir a árvore AVL
    printf("Percurso pre-ordem da arvore AVL:\n");
    imprimirPreOrdem(raiz);

    printf("\n\nPercurso em ordem (crescente) da arvore AVL:\n");
    imprimirEmOrdem(raiz);

    return 0;
}
