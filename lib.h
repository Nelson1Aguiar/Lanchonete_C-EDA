#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include <string.h>
#define TAM 2
#define pai(i) ((i-1)/2)
#define esq(i) (2*i+1)
#define dir(i) (2*i+2)

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
    int horaConclusao;
    int minutoConclusao;
    int segundoConclusao;
}cliente;

typedef struct no{
    cliente clientes;
    int s;

    struct no *esq;
    struct no *dir;
}heap;

typedef struct caixa{
    int num;
    bool prioridade;
    int senha;
    heap *pedidoNoCaixa;
    int quantidadeDeClientes;
}caixa;

typedef struct No{
    caixa caixas;
    struct No* proximo;
}No;

typedef struct{
    cliente *v;
    int tam;
    int n;
}heapMin;

void menu(void);
heap* cria_heap(cliente c);
void troca_filhos (heap* a);

heap* uniao(heap * h1, heap* h2);
heap* remover(heap *h);
heap* uniao_heaps(heap* h1, heap* h2);


void imprime(heap *h,caixa *c);



void inserirNoComeco(No** cabeca, caixa *c);

void listaCaixas(No* no);
int buscarCaixaMenosCliente(No* cabeca,bool p);
caixa* buscarUmCaixa(No* cabeca,int c);
void removerCaixa(No** cabeca, int num);
void menu();

heapMin* criarHeapSimples(int maximo);
void heap_insere(heapMin *h,cliente c);
void sobe(heapMin *h,int pos);
void trocar(heapMin *h,int posicaoPai,int pos);
void imprimir(heapMin h);
cliente* removerSimples(heapMin *h);
void descer(heapMin *h,int i);
void letreiro(heap *h,caixa *c);
bool temCliente(No *no,int num);
void notaFiscal(No *no,int caixa,int pagamento);
