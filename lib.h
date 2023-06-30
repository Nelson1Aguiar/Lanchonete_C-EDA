#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>

typedef struct pedido{
    char comida[30];
    float preco;
    int quantidade;
}pedido;

typedef struct cliente{
    bool prioridade;
    int senha;
    pedido pedido[50];
    float valorTotal;
    int hora;
    int minuto;
    int segundo;
}cliente;

typedef struct no{
    cliente clientes;
    int s;

    struct no *esq;
    struct no *dir;
}heap;

typedef struct caixa{
    bool prioridade;
    int senha;
    heap *pedidoNoCaixa;
}caixa;

void menu(void);
heap* cria_heap(cliente c);
void troca_filhos (heap* a);

heap* uniao(heap * h1, heap* h2);

heap* uniao_heaps(heap* h1, heap* h2);

void imprime(heap *h);

