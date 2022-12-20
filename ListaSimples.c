#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
    int cod;
    char nome[MAX];
    float preco;
}tp_produto;

typedef struct nodo{
    tp_produto p;
    struct nodo *proximo;
}Nodo;

typedef struct{
    Nodo *inicio;
    int tam;
}Comeco;

tp_produto lerProduto();
void iniciaLista(Comeco *lista);
void inserirOrdenado(Comeco *lista);
Nodo* excluirproduto(Comeco *lista, int codExcluir);
void imprimirLista(Comeco lista);

int main(){

    int opcao, codExcluir;
    Comeco lista;
    Nodo *excluido;

    iniciaLista(&lista);

        do{
            printf("------------- MENU --------------");
            printf("\n\n\tSelecione opcao\n\n\t   1-Inserir\n\t   2-Remover\n\t   3-Mostrar\n\t   0-Sair\n\n");
            scanf("%d",&opcao);
            printf("\n\n");
            switch(opcao){
            case 1:
                inserirOrdenado(&lista);
                break;
            case 2:
                printf("Informe codigo do produto a ser removido: ");
                scanf("%d", &codExcluir);
                excluido = excluirproduto(&lista, codExcluir);
                if(excluido != NULL){
                    printf("\n\tCodigo %d removido com sucesso!\n\n", excluido->p.cod);
                    free(excluido);
                }else{
                    printf("\n\tCodigo nao existe!\n\n");
                }
                break;
            case 3:
                imprimirLista(lista);
                break;
            case 0:
                break;
            default:
                printf("Esta opcao e invalida!\n");
                break;
            }
        }while(opcao != 0);

        printf("\nSaiu do programa!\n");
}
void iniciaLista(Comeco *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

tp_produto lerProduto() {
    tp_produto p;
    printf("\nDigite codigo: ");
    scanf("%d", &p.cod);
    printf("Digite nome: ");
    scanf("%s", p.nome);
    printf("Digite preco: ");
    scanf("%f", &p.preco);
    printf("\n");
    return p;
}
void inserirOrdenado(Comeco *lista){
    Nodo *ponteiroAuxiliar, *novo = (Nodo*)malloc(sizeof(Nodo));
    if(novo != NULL){
        novo->p = lerProduto();
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }else if(novo->p.cod < lista->inicio->p.cod){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }else{
            ponteiroAuxiliar = lista->inicio;
            while(ponteiroAuxiliar->proximo != NULL && novo->p.cod > ponteiroAuxiliar->proximo->p.cod){
                ponteiroAuxiliar = ponteiroAuxiliar->proximo;
            }
            novo->proximo = ponteiroAuxiliar->proximo;
            ponteiroAuxiliar->proximo = novo;
        }
        lista->tam++;
    }else{
        printf("Erro ao alocar memória!");
    }
}

Nodo* excluirproduto(Comeco *lista, int codExcluir){
    Nodo *ponteiroAuxiliar, *remover = NULL;
    if(lista->inicio != NULL){
        if(lista->inicio->p.cod == codExcluir) {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }else{
            ponteiroAuxiliar = lista->inicio;
            while(ponteiroAuxiliar->proximo != NULL && ponteiroAuxiliar->proximo->p.cod != codExcluir){
                ponteiroAuxiliar = ponteiroAuxiliar->proximo;
            }
            if(ponteiroAuxiliar->proximo != NULL){
                remover = ponteiroAuxiliar->proximo;
                ponteiroAuxiliar->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }
    return remover;
}

void imprimirLista(Comeco lista){
    Nodo *nodo = lista.inicio;
    printf("\n------- INICIO LISTA tam: %d ------\n", lista.tam);
    while(nodo != NULL){
        printf("\nCod: %d", nodo->p.cod);
        printf("\nNome: %s", nodo->p.nome);
        printf("\nPreco: %.2f\n\n", nodo->p.preco);
        nodo = nodo->proximo;
    }
    printf("\n------------ FIM LISTA -----------\n\n\n\n");
}
