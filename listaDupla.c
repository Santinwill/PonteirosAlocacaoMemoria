#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _produto{
    int codigo;
    char nome[20];
    float preco;
}TpProduto;

typedef struct _nodo{
    TpProduto p;
    struct _nodo *proximo;
    struct _nodo *anterior;
}TpNodo;

typedef struct _lista{
    int tam;
    TpNodo *inicio;
    TpNodo *fim;
}TpLista;

TpProduto lerProduto();
void iniciaLista(TpLista *lista);
void inserirOrdenado(TpLista *lista);
TpNodo* excluirproduto(TpLista *lista, int codExcluir);
void imprimirLista(TpLista lista);
void imprimirListaContrario(TpLista lista);

int main(){

    int opcao, codExcluir;
    TpLista lista;
    TpNodo *excluido;

    iniciaLista(&lista);

        do{
            printf("------------- MENU --------------");
            printf("\n\n\tSelecione opcao\n\n\t   1-Inserir\n\t   2-Remover\n\t   3-Mostrar\n\t   4-Mostrar Contrario\n\t   0-Sair\n\n");
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
                    printf("\n\tCodigo %d removido com sucesso!\n\n", excluido->p.codigo);
                    free(excluido);
                }else{
                    printf("\n\tCodigo nao existe!\n\n");
                }
                break;
            case 3:
                imprimirLista(lista);
                break;
            case 4:
                imprimirListaContrario(lista);
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

TpProduto lerProduto() {
    TpProduto p;
    printf("\nDigite codigo: ");
    scanf("%d", &p.codigo);
    printf("Digite nome: ");
    scanf("%s", p.nome);
    printf("Digite preco: ");
    scanf("%f", &p.preco);
    printf("\n");
    return p;
}


void iniciaLista(TpLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void inserirOrdenado(TpLista *lista){
    TpNodo *ponteiroAuxiliar, *novo = (TpNodo*)malloc(sizeof(TpNodo));

    if(novo != NULL){
        novo->p = lerProduto();

        if(lista->inicio == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            lista->inicio = novo;
            lista->fim = novo;

        }else if(novo->p.codigo < lista->inicio->p.codigo){
            novo->proximo = lista->inicio;
            lista->inicio->anterior = novo;
            lista->inicio = novo;
            }
            else{
            ponteiroAuxiliar = lista->inicio;
            while(ponteiroAuxiliar->proximo != NULL && novo->p.codigo > ponteiroAuxiliar->proximo->p.codigo){
                ponteiroAuxiliar = ponteiroAuxiliar->proximo;
            }
            novo->proximo = ponteiroAuxiliar->proximo;

            if(ponteiroAuxiliar->proximo != NULL){
                ponteiroAuxiliar->proximo->anterior = novo;
            }
            novo->anterior = ponteiroAuxiliar;
            ponteiroAuxiliar->proximo = novo;
            while(ponteiroAuxiliar->proximo != NULL){
                ponteiroAuxiliar = ponteiroAuxiliar->proximo;
            }
            lista->fim = ponteiroAuxiliar;
        }
        lista->tam++;
    }
    else{
        printf("Erro ao alocar memória!");
    }
}

TpNodo* excluirproduto(TpLista *lista, int codExcluir){
    TpNodo *ponteiroAuxiliar, *remover = NULL;
    if(lista->inicio != NULL){
        if(lista->inicio->p.codigo == codExcluir) {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            if(lista->inicio != NULL) {
                remover->proximo->anterior = NULL;
            }
            lista->tam--;

        }else{
            ponteiroAuxiliar = lista->inicio;
            while(ponteiroAuxiliar->proximo != NULL && ponteiroAuxiliar->proximo->p.codigo != codExcluir){
                ponteiroAuxiliar = ponteiroAuxiliar->proximo;
            }

            if(ponteiroAuxiliar->proximo != NULL){
                remover = ponteiroAuxiliar->proximo;
                ponteiroAuxiliar->proximo = remover->proximo;
                if(ponteiroAuxiliar->proximo != NULL){
                    ponteiroAuxiliar->proximo->anterior = ponteiroAuxiliar;
                }
                lista->tam--;
                 while(ponteiroAuxiliar->proximo != NULL){
                     ponteiroAuxiliar = ponteiroAuxiliar->proximo;
                 }
                 lista->fim = ponteiroAuxiliar;
            }
        }
    }
    return remover;
}

void imprimirLista(TpLista lista){
    TpNodo *nodo = lista.inicio;
    printf("\n------- INICIO LISTA tam: %d ------\n", lista.tam);
    while(nodo != NULL){
        printf("\nCod: %d", nodo->p.codigo);
        printf("\nNome: %s", nodo->p.nome);
        printf("\nPreco: %.2f\n\n", nodo->p.preco);
        nodo = nodo->proximo;
    }
    printf("\n------------ FIM LISTA -----------\n\n\n\n");
}

void imprimirListaContrario(TpLista lista){
    TpNodo *nodo = lista.fim;
    printf("\n------------ FIM LISTA -----------\n");
    while(nodo != NULL){
        printf("\nCod: %d", nodo->p.codigo);
        printf("\nNome: %s", nodo->p.nome);
        printf("\nPreco: %.2f\n\n", nodo->p.preco);
        nodo = nodo->anterior;
    }
    printf("\n------- INICIO LISTA tam: %d ------\n\n\n\n", lista.tam);
}




