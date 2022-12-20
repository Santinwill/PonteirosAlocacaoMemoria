#include <stdio.h>
#include <stdlib.h>
#define TAM 8

typedef struct no{
    int chave;
    struct no *proximo;
}No;

typedef struct{
    No * inicio;
}Lista;

void inicializarLista(Lista *l){
    l->inicio = NULL;
}

void inserirLista(Lista *l, int valor){
    No *novo = (No*)malloc(sizeof(No));
    
    if(novo){
        novo->chave = valor;
        novo->proximo = l->inicio;
        l->inicio = novo;
    }else{
        printf("\n\nErro ao alocar memoria\n\n");
    }
}

int buscaLista(Lista *l, int valor){
    No *aux = l->inicio;
    while(aux != NULL && aux->chave != valor){
        aux = aux->proximo;
    }if(aux != NULL){
        return aux->chave;
    }else{
        return 0;
    }
}

void imprimirLista(Lista *l){
    No *aux = l->inicio;
    
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

void inicializarTabela(Lista t[]){
    int i;
    for(i = 0; i < TAM; i++){
        inicializarLista(&t[i]);
    }    
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Lista t[], int valor){
    int id = funcaoHash(valor);  
    inserirLista(&t[id], valor);
    printf("\nIndice %d = ", id);
    imprimirLista(&t[id]);
    printf("\n\n\n");
}

int busca(Lista t[], int chave){
    int id = funcaoHash(chave);
    return buscaLista(&t[id], chave);
}

void imprimir(Lista t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("\nIndice %d = ", i);
        imprimirLista(&t[i]);
    }
    printf("\n\n\n");
}

int main() {
    
    int opcao, aux, valor, retorno;
    Lista tabela[TAM];
    
    inicializarTabela(tabela);
    
    do{
        printf("----------- Menu -----------");
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar \n\t3 - Imprimir\n\n");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 0:
                printf("\n\nSaiu!\n\n");
                break;
            case 1:
                printf("Qual valor deseja inserir? ");
                scanf("%d", &valor);
                inserir(tabela, valor);
                
                break;
            case 2:
                printf("Qual valor deseja encontrar? ");
                scanf("%d", &valor);
                retorno = busca(tabela, valor);
                if(retorno != 0){
                    int aux = funcaoHash(valor);
                    printf("\nIndice: %d\n", aux);
                    printf("Valor encontrado: %d\n\n", retorno);
                }else{
                    printf("\nValor nao encontrado!\n\n");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            default:
                printf("\nOpcao invalida!\n\n");
                break;
        }
    }while(opcao != 0);
    
    return 0;
}




