#include<stdio.h>
#include<stdlib.h>
#include "arvbi.h"

nodo* create_nodo(void *chave){
	nodo *new;
	new = (nodo*) malloc (sizeof(nodo));
	if(new == NULL) return NULL;
	new->pai = NULL;
	new->esquerda = NULL;
	new->direita = NULL;
	new->chave = NULL;
	new->chave = chave;
	return new;
}

void procura_lugar(nodo *N,nodo *M, int (*comp_function)(void*,void*)){
	if((*comp_function)(N->chave,M->chave)>0){
		if(N->esquerda==NULL){
			N->esquerda=M;
			M->pai=N;
			return;
		}
		else{
			procura_lugar(N->esquerda,M,comp_function);
		}
	}
	else{
		if(N->direita==NULL){
			N->direita=M;
			M->pai=N;
			return;
		}
		else{
			procura_lugar(N->direita,M,comp_function);
		}
	}
}

int insert_arvbi(arvbi *S, void *chave, int (*comp_function)(void*,void*)){
	nodo *new = create_nodo(chave);
	if(new == NULL) return 1;
	if(S->raiz == NULL){
		S->raiz = new;
		S->nmemb ++;
		return 0;
	}
	procura_lugar(S->raiz,new,comp_function);
	S->nmemb ++;
	return 0;
}

void free_nodo(nodo *N, void (*free_function)(void*)){
    if(N->esquerda!=NULL){
    	free_nodo(N->esquerda,free_function);
    }
    if(N->direita!=NULL){
    	free_nodo(N->direita,free_function);
    }
    (*free_function)(N->chave);
    if(N->esquerda!=NULL) free(N->esquerda);
    if(N->direita!=NULL) free(N->direita);
}

void free_arvbi(arvbi *S, void (*free_function)(void*)){
    if(S->raiz == NULL){
        create_arvbi(S);
        return;
    }
    free_nodo(S->raiz,free_function);
    free(S->raiz);
    create_arvbi(S);
}

void print_nodo(nodo *N, void *chave, void (*print_function)(void*)){
	if(N->esquerda!=NULL){
    	print_nodo(N->esquerda,chave,print_function);
    }
    if(N->direita!=NULL){
    	print_nodo(N->direita,chave,print_function);
    }
    (*print_function)(N->chave);
}

void print_arvbi(arvbi *S, void (*print_function)(void*)){
	if(S->raiz == NULL){
		return;
    }
    print_nodo(S->raiz, S->raiz->chave, print_function); 
}

void* get_key_(nodo *S, void *chave, int (*comp_function)(void*,void*)){
	int flag;
	void *a;
	flag=(*comp_function)(S->chave,chave);
	if(flag==0) {
		return S->chave;
	}
	if(flag>0){
		if(S->esquerda!=NULL){
			a=get_key_(S->esquerda,chave,comp_function);
			return a;
		}
		else return NULL;
	}
	else{
		if(S->direita!=NULL){
			a=get_key_(S->direita,chave,comp_function);
			return a;
		}
		else return NULL;
	} 
}

void* get_key(arvbi *S, void *chave, int (*comp_function)(void*,void*)){
	if(S->raiz == NULL){
		return NULL;
    }
    void *a;
    a=get_key_(S->raiz,chave,comp_function);
    return a;
}
