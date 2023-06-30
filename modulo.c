#include <string.h>
#include "lib.h"

void menu(){
    int op, op2;

    //--------- iniciando a estrutura --------------------//
    heap *h = NULL;
    cliente c;
    caixa *caixas = (caixa*)malloc(TAM * sizeof(caixa));
    caixas[0].pedidoNoCaixa=NULL;
    caixas[0].prioridade=false;
    caixas[0].quantidadeDeClientes=0;
    caixas[1].pedidoNoCaixa=NULL;
    caixas[1].prioridade=true;
    caixas[1].quantidadeDeClientes=0;
    pedido p;
    int quantidade;
    int atendimento;
    struct tm *timeInfo;
    time_t horaAtual;
    for(int i=0;i<50;i++){
        c.pedido[i].preco=0;
        c.pedido[i].quantidade=0;
        strcpy(c.pedido[i].comida,"");
    }
    c.valorTotal=0;
    c.hora;
    c.segundo;
    c.minuto;
    do {
        system("cls");
        puts("BEM VINDO A NOSSA LANCHONETE!\nDefina seu tipo de atendimento, digite 1 para prioritaria ou 2 para nao prioritario ou 0 para encerrar o atendimento\n");
        scanf("%d", &atendimento);
        time(&horaAtual);
        timeInfo = localtime(&horaAtual);
        c.hora = timeInfo->tm_hour;
        c.minuto = timeInfo->tm_min;
        c.segundo = timeInfo->tm_sec;
        do {
            int cont = 0;
            //--------------- Exibir menu ---------------------//
            system("cls");
            puts("\n\t\t\t\tLANCHONETE ---\n");
            if (atendimento == 1) {
                c.prioridade = true;
            }
            if (atendimento == 2) {
                c.prioridade = false;
            }
            if (atendimento > 2 || atendimento < 1) {
                puts("OPCAO INCORRETA!");
            }
            puts("-------------------------CARDAPIO------------------------------");
            puts("\t1 - Coxinha de frango - R$2,50\n \t2 - Pastel de frango - R$3,00\n\t3 - Pastel de queijo - R$3,00\n\t"
                 "4 - Pastel de carne - R$3,00\n\t5 - Calzone - R$6,00\n\t6 - Pizza - R$30,00\n\t0 - Sair");
            printf("\nINFORME SUA OPCAO:\n");
            scanf("%d", &op);//Escolha da Opção

            switch (op) {
                case 1:
                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade);
                    while (c.pedido[cont].preco != 0) {
                        cont++;
                    }
                    c.pedido[cont].quantidade = quantidade;
                    strcpy(c.pedido[cont].comida, "Coxinha de Frango");
                    c.pedido[cont].preco = 2.50;
                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                    break;
                case 2:
                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade);
                    while (c.pedido[cont].preco != 0) {
                        cont++;
                    }
                    c.pedido[cont].quantidade = quantidade;
                    strcpy(c.pedido[cont].comida, "Pastel de Frango");
                    c.pedido[cont].preco = 3;
                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                    break;
                case 3:
                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade);
                    while (c.pedido[cont].preco != 0) {
                        cont++;
                    }
                    c.pedido[cont].quantidade = quantidade;
                    strcpy(c.pedido[cont].comida, "Pastel de Queijo");
                    c.pedido[cont].preco = 3;
                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                    break;
                case 4:
                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade);
                    while (c.pedido[cont].preco != 0) {
                        cont++;
                    }
                    c.pedido[cont].quantidade = quantidade;
                    strcpy(c.pedido[cont].comida, "Pastel de Carne");
                    c.pedido[cont].preco = 3;
                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                    break;
                case 5:
                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade);
                    while (c.pedido[cont].preco != 0) {
                        cont++;
                    }
                    c.pedido[cont].quantidade = quantidade;
                    strcpy(c.pedido[cont].comida, "Calzone");
                    c.pedido[cont].preco = 6;
                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                    break;
                case 6:
                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade);
                    while (c.pedido[cont].preco != 0) {
                        cont++;
                    }
                    c.pedido[cont].quantidade = quantidade;
                    strcpy(c.pedido[cont].comida, "Pizza");
                    c.pedido[cont].preco = 30;
                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                    break;
                default:
                    puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
                    break;
            }
            printf("\nFINALIZAR PEDIDO? DIGITE 1 PARA SIM E 2 PARA NAO:\n");
            scanf("%d", &op2);
            if (op2 == 1) {
                puts("Pedido cadastrado! Realize o pagamento no caixa");
                if(atendimento==1) {
                    heap *novo = cria_heap(c);
                    caixas[0].pedidoNoCaixa = uniao(caixas[0].pedidoNoCaixa, novo);
                    for (int i = 0; i < 50; i++) {
                        c.pedido[i].preco = 0;
                        c.pedido[i].quantidade = 0;
                        strcpy(c.pedido[i].comida, "");
                    }
                    c.valorTotal = 0;
                    op = 0;
                    printf("CAIXA 1: PRIORITARIO");
                    imprime(caixas[0].pedidoNoCaixa);
                    caixas[0].quantidadeDeClientes = caixas[0].quantidadeDeClientes + 1;
                }
                if(atendimento==2){
                    heap *novo = cria_heap(c);
                    caixas[1].pedidoNoCaixa = uniao(caixas[1].pedidoNoCaixa, novo);
                    for (int i = 0; i < 50; i++) {
                        c.pedido[i].preco = 0;
                        c.pedido[i].quantidade = 0;
                        strcpy(c.pedido[i].comida, "");
                    }
                    c.valorTotal = 0;
                    op = 0;

                    printf("CAIXA 2: NAO PRIORITARIO");
                    imprime(caixas[1].pedidoNoCaixa);
                    caixas[1].quantidadeDeClientes = caixas[1].quantidadeDeClientes + 1;
                }
            }
            if(caixas[0].quantidadeDeClientes==3){
                int opcao,x;
                printf("\n3 clientes para 1 caixa. Deseja criar mais algum caixas? 1 para sim e 2 para nao\n");
                scanf("%d",&opcao);
                if(opcao==1){
                    printf("Quantos?");
                    scanf("%d",&x);
                    *caixas=aumentarCaixas(caixas,x);
                }
            }
            if (op2 > 2 || op2 < 1) {
                puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
            }
            getch();
        } while (op != 0);
        getch();
    } while (atendimento!=0);
}
heap* cria_heap(cliente c){
    heap *h = (heap *)malloc(sizeof (heap));
    h->esq=NULL;
    h->dir=NULL;
    h->clientes.valorTotal=0;
    h->clientes.prioridade=false;
    h->clientes.senha=0;
    for(int i=0;i<50;i++){
        strcpy(h->clientes.pedido[i].comida,c.pedido[i].comida);
        h->clientes.pedido[i].preco=c.pedido[i].preco;
        h->clientes.pedido[i].quantidade=c.pedido[i].quantidade;
    }
    h->clientes.valorTotal=c.valorTotal;
    h->clientes.prioridade=c.prioridade;
    srand(time(NULL));
    int numeroSorteado = rand() %(100000) + 1;
    h->clientes.senha= numeroSorteado;
    h->clientes.hora=c.hora;
    h->clientes.minuto=c.minuto;
    h->clientes.segundo=c.segundo;
    h->s=1;
    return h;
}

caixa aumentarCaixas(caixa *c,int tamanho){
    caixa *temp = (caixa *)realloc(c, tamanho * sizeof(caixa));
    if (temp == NULL) {
        perror("Falha ao realocar memória");
        free(c);
        return *temp;
    }
    return *temp;
}

void troca_filhos (heap* a){
    heap *aux=a->esq;
    a->esq=a->dir;
    a->dir=aux;
}

heap* uniao(heap * h1, heap* h2) {
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    if(h1->clientes.senha > h2->clientes.senha)
        return uniao_heaps(h1, h2);
    else
        return uniao_heaps(h2, h1);
}

heap * uniao_heaps(heap* h1, heap * h2)
{
    if(h1->esq == NULL){
        h1->esq = h2;
    }
    else{
        h1->dir = uniao(h1->dir,h2);
        if(h1->esq->s <h1->dir->s){
            troca_filhos(h1);
        }
        h1->s=h1->dir->s+1;
    }
    return h1;
}

void imprime(heap *h) {
    if (h != NULL) {
        printf("\nCLIENTE SENHA: \n");
        printf("HORARIO: %02d:%02d:%02d\n", h->clientes.hora, h->clientes.minuto, h->clientes.segundo);
        for (int i = 0; h->clientes.pedido[i].preco != 0; i++) {
            printf("PEDIDO: %s %dx", h->clientes.pedido[i].comida, h->clientes.pedido[i].quantidade);
            if (h->esq != NULL)
                printf("(E:%s)", h->esq->clientes.pedido[i].comida);
            if (h->dir != NULL)
                printf("(D:%s)", h->dir->clientes.pedido[i].comida);
            printf("\n");
        }
        printf("TOTAL A PAGAR: R$ %.2f\n", h->clientes.valorTotal);
        imprime(h->esq);
        imprime(h->dir);
    }
}
