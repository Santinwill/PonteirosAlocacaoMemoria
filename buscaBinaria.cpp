#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int *vet, int valor, int inicio, int fim){
    int meio;
    if(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(valor == vet[meio]){
            return meio;
        }else{ //se o num procurado nao for o do meio
            if(valor < vet[meio]){
                return buscaBinaria(vet, valor, inicio, meio-1);
            }else{
                return buscaBinaria(vet, valor, meio+1, fim);
            }
        }
    }
    return -1; //elemento nao encontrado
}

int main() {
    int vet[10];
    int valor, op, i, j, copia, res;

    printf("Informe 10 Valores: \n");

    for(i = 0; i < 10; i++){
        printf("valor Vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    printf("\nAntes de ordenar:\n");
    for(i = 0; i < 10; i++){
        printf("%3d", vet[i]);
    }

    for(j = 1; j <= 10; j++){
        for(i = 0; i < 9; i++){
            if(vet[i] > vet[i+1]){
                copia = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = copia;
            }
        }
    }

    printf("\nApos de ordenar:\n");
    for(i = 0; i < 10; i++){
        printf("%3d", vet[i]);
    }

    do{
        printf("\nQual valor a ser encontrado? ");
        scanf("%d", &valor);
        
        res = buscaBinaria(vet, valor, 0, 10);
        
        if(res > -1){
        	printf("\nPosicao: %d\n", res);
		}else{
			printf("\nElemento nao encontrado!!!\n\n");
		}
        printf("\n0- Sair\n1- Nova Busca\n");
        scanf("%d", &op);
    }while(op != 0);

    return 0;
}
