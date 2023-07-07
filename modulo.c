#include "lib.h"

void menu() {
    int op, op2;

    //--------- iniciando a estrutura --------------------//
    cliente c;
    caixa *caixas= (caixa*)malloc(sizeof(caixa));
    No *cabeca=NULL;
    caixas->num=1;
    caixas->pedidoNoCaixa = NULL;
    caixas->prioridade = true;
    caixas->quantidadeDeClientes = 0;
    inserirNoComeco(&cabeca, caixas);

    caixas = (caixa*)malloc(sizeof(caixa));
    caixas->num=2;
    caixas->pedidoNoCaixa = NULL;
    caixas->prioridade = false;
    caixas->quantidadeDeClientes = 0;
    inserirNoComeco(&cabeca,caixas);
    pedido p;
    int quantidade,atvLanchonete=0,qtdCaixas=TAM;
    int atendimento;
    int senhaPrioritaria = 0;
    int senhaNaoPrioritaria = 1;
    struct tm *timeInfo;
    time_t horaAtual;
    for (int i = 0; i < 50; i++) {
        c.pedido[i].preco = 0;
        c.pedido[i].quantidade = 0;
        strcpy(c.pedido[i].comida, "");
    }
    c.valorTotal = 0;
    c.hora=0;
    c.segundo=0;
    c.minuto=0;
        printf("-----------ABRINDO AS ATIVIDADE DA LANCHONETE-----------\n ");
        printf("DOIS CAIXAS FORAM ABERTOS, UM PRIORITARIO E UM NAO PRIORITARIO\n");
            do {
                listaCaixas(cabeca);
                printf("1 - RECEBER CLIENTE\n2 - ABRIR MAIS UM CAIXA\n3 - FECHAR CAIXA\n4- PAGAMENTO DE UM CLIENTE\n0 - ENCERRAR AS ATIVIDADES DA LANCHONETE\n");
                scanf("%d", &atvLanchonete);
                if (atvLanchonete == 1) {
                    LOOP: do {
                        system("cls");
                        puts("BEM VINDO A NOSSA LANCHONETE!\n1 - PRIORITARIO\n2 - NAO PRIORITARIO\n0 - VOLTAR\n");
                        scanf("%d", &atendimento);
                        time(&horaAtual);
                        timeInfo = localtime(&horaAtual);
                        c.hora = timeInfo->tm_hour;
                        c.minuto = timeInfo->tm_min;
                        c.segundo = timeInfo->tm_sec;
                        if(atendimento==1 || atendimento==2) {
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
                                    case 0:
                                        goto LOOP;
                                        break;
                                    default:
                                        puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
                                        break;
                                }
                                printf("\nFINALIZAR PEDIDO? DIGITE 1 PARA SIM E 2 PARA NAO:\n");
                                scanf("%d", &op2);
                                if (op2 == 1) {
                                    bool p= c.prioridade;
                                    int caixaMenosGente= buscarCaixaMenosCliente(cabeca,p);
//                                    listaCaixas(cabeca);
                                    printf("---------%d",caixaMenosGente);
                                    time(&horaAtual);
                                    timeInfo = localtime(&horaAtual);
                                    c.horaConclusao = timeInfo->tm_hour;
                                    c.minutoConclusao = timeInfo->tm_min;
                                    c.segundoConclusao = timeInfo->tm_sec;
                                    puts("Pedido cadastrado! Realize o pagamento no caixa\n");
                                    c.senha = senhaNaoPrioritaria;
                                    heap *novo = cria_heap(c);
                                    buscarUmCaixa(cabeca,caixaMenosGente)->pedidoNoCaixa=uniao(buscarUmCaixa(cabeca,caixaMenosGente)->pedidoNoCaixa, novo);
                                    buscarUmCaixa(cabeca,caixaMenosGente)->quantidadeDeClientes= buscarUmCaixa(cabeca,caixaMenosGente)->quantidadeDeClientes + 1;
                                    imprime(buscarUmCaixa(cabeca,caixaMenosGente)->pedidoNoCaixa,buscarUmCaixa(cabeca,caixaMenosGente));
                                    senhaNaoPrioritaria = senhaNaoPrioritaria + 1;
                                    for (int i = 0; i < 50; i++) {
                                        c.pedido[i].preco = 0;
                                        c.pedido[i].quantidade = 0;
                                        strcpy(c.pedido[i].comida, "");
                                    }
                                    c.valorTotal = 0;
                                    op = 0;
                                }
                                if (op2 > 2 || op2 < 1) {
                                    puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
                                }
                                getch();
                            } while (op != 0);
                        }else system("cls");
                        getch();
                    } while (atendimento != 0);
                }
                if (atvLanchonete == 2) {
                    int abrirCaixa;
                    qtdCaixas = qtdCaixas + 1;
                    printf("\n1 - PRIORITARIO\n2 - NAO PRIORITARIO\n");
                    scanf("%d",&abrirCaixa);
                    if(abrirCaixa==1) {
                        caixas =(caixa*)malloc(sizeof(caixa));
                        caixas->pedidoNoCaixa = NULL;
                        caixas->quantidadeDeClientes = 0;
                        caixas->prioridade=true;
                        caixas->num=qtdCaixas;
                        inserirNoComeco(&cabeca,caixas);
                        printf("UM NOVO CAIXA PRIORITARIO FOI ABERTO\n");
                    }
                    if(abrirCaixa==2){
                        caixas =(caixa*)malloc(sizeof(caixa));
                        caixas->pedidoNoCaixa = NULL;
                        caixas->quantidadeDeClientes = 0;
                        caixas->prioridade=false;
                        caixas->num=qtdCaixas;
                        inserirNoComeco(&cabeca,caixas);
                        printf("UM NOVO CAIXA NAO PRIORITARIO FOI ABERTO\n");
                    }
                    if(abrirCaixa>2||abrirCaixa<1){
                        printf("OPCAO INVALIDA!\n");
                    }
                    system("pause");
                    system("cls");
                }
                if(atvLanchonete==3){
                    int caixaVaiFechar,caixaMenosCliente;
                    printf("Qual caixa deseja fechar?\n");
                    scanf("%d",&caixaVaiFechar);
                    bool p= buscarUmCaixa(cabeca,caixaVaiFechar)->prioridade;
                    caixaMenosCliente= buscarCaixaMenosCliente(cabeca,p);
                    while(buscarUmCaixa(cabeca,caixaVaiFechar)->num==buscarUmCaixa(cabeca,caixaMenosCliente)->num){
                        buscarUmCaixa(cabeca,caixaVaiFechar)->quantidadeDeClientes=buscarUmCaixa(cabeca,caixaVaiFechar)->quantidadeDeClientes+1;
                    }
                    cabeca->caixas.pedidoNoCaixa=uniao(buscarUmCaixa(cabeca,caixaMenosCliente)->pedidoNoCaixa, buscarUmCaixa(cabeca,caixaVaiFechar)->pedidoNoCaixa);
                    printf("O CAIXA %d foi o unido com o caixa %d\n",buscarUmCaixa(cabeca,caixaMenosCliente)->num, buscarUmCaixa(cabeca,caixaVaiFechar)->num);
                    removerCaixa(&cabeca,caixaVaiFechar);
                }
                if(atvLanchonete==4){
                    int caixaPaga=0;
                    printf("Qual caixa deseja realizar o pagamento?");
                    scanf("%d",&caixaPaga);
                }
                if(atvLanchonete==0){
                    for(int i=0;i<qtdCaixas;i++){
                        free(caixas[i].pedidoNoCaixa);
                    }
                    printf("LANCHONETE FECHADA!");
                }
            }while (atvLanchonete != 0);
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
    h->clientes.senha= c.senha;
    h->clientes.hora=c.hora;
    h->clientes.minuto=c.minuto;
    h->clientes.segundo=c.segundo;
    h->clientes.horaConclusao=c.horaConclusao;
    h->clientes.minutoConclusao=c.minutoConclusao;
    h->clientes.segundoConclusao=c.segundoConclusao;
    h->s=1;
    return h;
}

void troca_filhos (heap* a){
    heap *aux=a->esq;
    a->esq=a->dir;
    a->dir=aux;
}

heap* uniao(heap * h1, heap* h2) {
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    if(h1->clientes.senha < h2->clientes.senha)
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
heap* remover(heap *h){
    if (h == NULL)
        return NULL;

    heap* esquerdo = h->esq;
    heap* direito = h->dir;
    free(h);
    return uniao(esquerdo, direito);
}
caixa* buscarUmCaixa(No* cabeca,int c){
    No* corrente = cabeca;
    while (corrente != NULL) {
        if (corrente->caixas.num == c) {
            return &(corrente->caixas);  // Elemento encontrado
        }
        corrente = corrente->proximo;
    }// Elemento não encontrado
    return NULL;
}

// Função para criar um novo nó com o dado especificado
No* criarNo(caixa* c) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->caixas.quantidadeDeClientes = c->quantidadeDeClientes;
    novoNo->caixas.pedidoNoCaixa = c->pedidoNoCaixa;
    novoNo->caixas.prioridade = c->prioridade;
    novoNo->caixas.num = c->num;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNoComeco(No** cabeca, caixa* c) {
    No* novoNo = criarNo(c);
    novoNo->caixas = *c;
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
}
int buscarCaixaMenosCliente(No* cabeca,bool p){
    int min=100,caixaNum=0;
    if (cabeca == NULL) {
        printf("A lista está vazia.\n");
        return 0;
    }

    No* menorElemento = cabeca;

    while (menorElemento != NULL) {
            if (min > menorElemento->caixas.quantidadeDeClientes) {
                if(menorElemento->caixas.prioridade==p){
                    min=menorElemento->caixas.quantidadeDeClientes;
                    caixaNum=menorElemento->caixas.num;
                }
            }
        menorElemento = menorElemento->proximo;
    }
    return caixaNum;
}

// Função para imprimir os elementos da lista
void listaCaixas(No* no) {
    while (no != NULL) {
        letreiro(no->caixas.pedidoNoCaixa,&no->caixas);
        no = no->proximo;
        printf("\n");
    }
    printf("\n\n");
}
void removerCaixa(No** cabeca, int num) {
    No* temp = *cabeca;
    No* prev = NULL;

    // Caso especial: remover o elemento do início da lista
    if (temp != NULL && temp->caixas.num == num) {
        *cabeca = temp->proximo;
        free(temp);
        return;
    }

    // Procurar o elemento a ser removido
    while (temp != NULL && temp->caixas.num!= num) {
        prev = temp;
        temp = temp->proximo;
    }

    // Se o elemento não foi encontrado na lista
    if (temp == NULL) {
        return;
    }

    // Remover o elemento da lista
    prev->proximo = temp->proximo;
    free(temp);
}


heapMin* criarHeapSimples(int maximo){
    heapMin *h=(heapMin *)malloc(sizeof(heapMin));
    h->n;
    h->tam=maximo;
    h->v= malloc(sizeof(cliente)*maximo);
    return h;
}

void heap_inserir(heapMin *h,cliente c){
h->v[h->n]=c;
h->n++;
sobe(h,h->n-1);
}

void sobe(heapMin *h,int pos){
    int posicaoPai;
    while(pos>0){
        posicaoPai=pai(pos);
        if(h->v[posicaoPai].senha < h->v[pos].senha){
            break;
        }
        trocar(h,posicaoPai,pos);
        pos=posicaoPai;
    }

}

void trocar(heapMin *h,int posicaoPai,int pos){
    cliente aux=h->v[pos];
    h->v[pos]=h->v[posicaoPai];
    h->v[posicaoPai]=aux;
}
void imprimir(heapMin h){
    puts("------------Elementos---------------");
    for(int i=0;i<h.n;i++){
        printf(" %d -",h.v[i]);
    }
}
cliente* removerSimples(heapMin *h){
    cliente *topo;
    *topo= h->v[0];
    h->v[0]=h->v[h->n-1];
    h->n--;
    descer(h,0);
    return topo;
}

void descer(heapMin *h,int i){
    int aux=esq(i);
    int filho_direita;
    while(aux<h->n){
        filho_direita=dir(i);
        if(filho_direita<h->n){
            if(h->v[filho_direita].senha<h->v[aux].senha){
                aux=filho_direita;
            }
        }
        if(h->v[i].senha<h->v[filho_direita].senha){
            break;
        }
        trocar(h,i,aux);
        i=aux;
        aux=esq(i);
    }
}

void letreiro(heap *h,caixa *c) {
    if (h != NULL) {
        if(c->prioridade==true){
            printf("\nCAIXA PRIORITARIO: %d",c->num);
        }else printf("\nCAIXA NAO PRIORITARIO: %d",c->num);
        printf("\nSENHA: %d",h->clientes.senha);
        printf("\nREALIZE SEU PAGAMENTO");
    }else{
        if(c->prioridade==true){
            printf("\nCAIXA PRIORITARIO: %d",c->num);
        }else printf("\nCAIXA NAO PRIORITARIO: %d",c->num);
        printf("\nCAIXA LIVRE");
    }
}



void imprime(heap *h,caixa *c) {
    if (h != NULL) {
        if(c->prioridade==true){
            printf("\nCAIXA PRIORITARIO: %d",c->num);
        }else printf("\nCAIXA NAO PRIORITARIO: %d",c->num);
        printf("\nSENHA: %d",h->clientes.senha);
        if(h->clientes.prioridade==1){
            printf("\nTIPO ATENDIMENTO: PRIORITARIO\n");
        }else printf("\nTIPO ATENDIMENTO: NAO PRIORITARIO\n");
        printf("HORARIO DE ENTRADA NO SISTEMA: %02d:%02d:%02d\n", h->clientes.hora, h->clientes.minuto, h->clientes.segundo);
        printf("HORARIO DE CONCLUSAO DO PEDIDO: %02d:%02d:%02d\n", h->clientes.horaConclusao, h->clientes.minutoConclusao, h->clientes.segundoConclusao);
        for (int i = 0; h->clientes.pedido[i].preco != 0; i++) {
            printf("PEDIDO: %s %dx", h->clientes.pedido[i].comida, h->clientes.pedido[i].quantidade);
            if (h->esq != NULL)
                printf("(E:%s)", h->esq->clientes.pedido[i].comida);
            if (h->dir != NULL)
                printf("(D:%s)", h->dir->clientes.pedido[i].comida);
            printf("\n");
        }
        printf("TOTAL A PAGAR: R$ %.2f\n", h->clientes.valorTotal);
        imprime(h->esq,c);
        imprime(h->dir,c);
    }
}
