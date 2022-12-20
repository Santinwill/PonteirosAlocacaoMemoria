#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 50

typedef struct _produto{
	int cod;
	char nome[TAM];
	float preco;
}tp_produto;

typedef struct _pilha{
	tp_produto *info;
	int topo;
}tp_pilha;

void cria(tp_pilha *p,int tamanho){
 tp_produto *var=(tp_produto*)malloc(tamanho*sizeof(tp_produto));
	p->info=var;
}

int cheia(tp_pilha *b, int e){
    if(b->topo == (e-1)){
        return 1;
    }else{
        return 0;
    }
}
        

void push(tp_pilha *a,int e){
    if(cheia(a,e)==0){
        a->topo++;    
        printf("\nDigite nome: ");
        fflush(stdin);
        fgets((a->info+a->topo)->nome, TAM, stdin);
        printf("Digite codigo: ");
        scanf("%d", &(a->info+a->topo)->cod);
        printf("Digite preco: ");
        scanf("%f", &(a->info+a->topo)->preco);
        printf("\n");
    }else{
        printf("\n\nPilha Cheia!\n\n");
    }
}


void pop(tp_pilha *p){
    if(p->topo != -1){
        p->topo--;
        printf("excluido com sucesso!\n\n");
    }else{
        printf("\n\nPilha Vazia!\n\n");
    }
} 

 void display(tp_pilha *d){ 
 	int i;
 	if(d->topo != -1){
    	for(i = 0; i<=d->topo; i++){
    	printf("Cod: %d\n", (d->info+i)->cod);
     	printf("Nome: %s", (d->info+i)->nome);
     	printf("Preço: %.2f\n\n", (d->info+i)->preco);
   		}
	}else{
		printf("\n\nSem produtos na pilha!\n\n");
	}
   printf("\n");
 }

int main(){
	tp_pilha *p;
	int y,e;
	p=(tp_pilha*)malloc(sizeof(tp_pilha));
	p->topo=-1;
	
	printf("Quantos produtos voce quer inserir\n");
	scanf("%d",&e);
	
	cria(p,e);

    do{

        printf("\nO que vc quer fazer com a pilha: Digite:\n\n 1=Inserir(push)\n 2=Retirar(pop)\n 3=Mostrar(display)\n 0=Sair\n\n");
        scanf("%d",&y);
        if(y==1){
            push(p,e);
        }else if(y==2){
            pop(p);
        }else if(y==3){
            display(p);
        }else if(y==0){
            break;
        }else{
            printf("Esta opcao e invalida!\n");
        }
    }while(y!=0);
     printf("\nVoce optou por sair do programa, as operacoes na pilha foram finalizadas\n");

	free(p);
}
