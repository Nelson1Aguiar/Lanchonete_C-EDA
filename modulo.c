#include "lib.h"

void menu() {
    int op, op2;

    //--------- iniciando a estrutura --------------------//
    heap *h = NULL;
    cliente c;
    caixa *caixas = (caixa *) malloc(TAM * sizeof(caixa));
    caixas[0].pedidoNoCaixa = NULL;
    caixas[0].prioridade = true;
    caixas[0].quantidadeDeClientes = 0;
    caixas[1].pedidoNoCaixa = NULL;
    caixas[1].prioridade = false;
    caixas[1].quantidadeDeClientes = 0;
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
    c.hora;
    c.segundo;
    c.minuto;
        printf("-----------DESEJA ABRINDO AS ATIVIDADE DA LANCHONETE-----------\n ");
        printf("DOIS CAIXAS FORAM ABERTOS, UM PRIORITARIO E UM NAO PRIORITARIO\n");
            do {
                printf("1 - RECEBER CLIENTE\n2 - ABRIR MAIS UM CAIXA\n3 - FECHAR CAIXA\n0 - ENCERRAR AS ATIVIDADES DA LANCHONETE\n");
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
                                    time(&horaAtual);
                                    timeInfo = localtime(&horaAtual);
                                    c.horaConclusao = timeInfo->tm_hour;
                                    c.minutoConclusao = timeInfo->tm_min;
                                    c.segundoConclusao = timeInfo->tm_sec;
                                    puts("Pedido cadastrado! Realize o pagamento no caixa\n");
                                    if (atendimento == 1) {
//                                        for(int i=0;i<qtdCaixas;i++){
//                                            if(caixas[i].prioridade==c.prioridade){
//                                                for(int j=0;j<qtdCaixas;j++){
//                                                    if(caixas[j].prioridade=c.prioridade){
//                                                        if(caixas[i].quantidadeDeClientes>caixas[j].quantidadeDeClientes){
//                                                            caixaMenosGente=j;
//                                                        }
//                                                        else{
//                                                            caixaMenosGente=i;
//                                                        }
//                                                    }
//                                                }
//                                            }
//                                        }
                                        c.senha = 2 * senhaPrioritaria;
                                        heap *novo = cria_heap(c);
                                        caixas[0].pedidoNoCaixa = uniao(caixas[0].pedidoNoCaixa, novo);
                                        senhaPrioritaria = senhaPrioritaria + 1;;
                                        for (int i = 0; i < 50; i++) {
                                            c.pedido[i].preco = 0;
                                            c.pedido[i].quantidade = 0;
                                            strcpy(c.pedido[i].comida, "");
                                        }
                                        c.valorTotal = 0;
                                        op = 0;
                                        imprime(caixas[0].pedidoNoCaixa);
                                        caixas[0].quantidadeDeClientes = caixas[0].quantidadeDeClientes + 1;
                                    }
                                    if (atendimento == 2) {
//                                        for(int i=0;i<qtdCaixas;i++){
//                                            if(caixas[i].prioridade==c.prioridade){
//                                                for(int j=0;j<qtdCaixas;j++){
//                                                    if(caixas[j].prioridade=c.prioridade){
//                                                        if(caixas[i].quantidadeDeClientes>caixas[j].quantidadeDeClientes){
//                                                            caixaMenosGente=j;
//                                                        }
//                                                        else{
//                                                            caixaMenosGente=i;
//                                                        }
//                                                    }
//                                                }
//                                            }
//                                        }
                                        c.senha = 2 * senhaNaoPrioritaria - 1;
                                        heap *novo = cria_heap(c);
                                        caixas[1].pedidoNoCaixa = uniao(caixas[1].pedidoNoCaixa, novo);
                                        senhaNaoPrioritaria = senhaNaoPrioritaria + 1;
                                        for (int i = 0; i < 50; i++) {
                                            c.pedido[i].preco = 0;
                                            c.pedido[i].quantidade = 0;
                                            strcpy(c.pedido[i].comida, "");
                                        }
                                        c.valorTotal = 0;
                                        op = 0;

                                        imprime(caixas[1].pedidoNoCaixa);
                                        caixas[1].quantidadeDeClientes = caixas[1].quantidadeDeClientes + 1;
                                    }
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
                        *caixas = aumentarCaixas(caixas, qtdCaixas,true);
                        printf("UM NOVO CAIXA PRIORITARIO FOI ABERTO\n");
                    }
                    if(abrirCaixa==2){
                        *caixas = aumentarCaixas(caixas, qtdCaixas,false);
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
                    for(int i=0;i<qtdCaixas;i++){
                        if(caixas[i].prioridade==caixas[caixaVaiFechar-1].prioridade) {
                            for (int j = 0; j < qtdCaixas; j++) {
                                if(caixas[j].prioridade==caixas[caixaVaiFechar-1].prioridade) {
                                    if (caixas[i].quantidadeDeClientes > caixas[j].quantidadeDeClientes) {
                                        caixaMenosCliente = j;
                                    } else {
                                        caixaMenosCliente = 1;
                                    }
                                }
                            }
                        }
                    }
                    uniao(caixas[caixaMenosCliente].pedidoNoCaixa,caixas[caixaVaiFechar].pedidoNoCaixa);
                    free(caixas[caixaVaiFechar].pedidoNoCaixa);
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

caixa aumentarCaixas(caixa *c,int tamanho,bool prioridade){
    caixa *temp = (caixa *)realloc(c, tamanho * sizeof(caixa));
    temp[tamanho-1].prioridade=prioridade;
    temp[tamanho-1].pedidoNoCaixa=NULL;
    temp[tamanho-1].quantidadeDeClientes=0;
    temp[tamanho-1].senha=0;
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
heap* remover(heap *h){
    if (h == NULL)
        return NULL;

    heap* esquerdo = h->esq;
    heap* direito = h->dir;
    free(h);
    return uniao(esquerdo, direito);
}

void imprime(heap *h) {
    if (h != NULL) {
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
        imprime(h->esq);
        imprime(h->dir);
    }
}
