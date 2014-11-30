#ifndef _ARVBI_H
#define _ARVBI_H

/*-------------------------------------------------------------------------------------------------------------
---------------------------------ARVORE BINARIA DE PESQUISA GENÉRICA-------------------------------------------
-----------------------------------------------------------Por: Myke Wyllian Dal'Agnol-------------------------
-------------------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------------------
----Estrutura de dados que representa um nodo na árvore, com ponteiros para o pai, filho a esquerda,-----------
---------filho a direita e um ponteiro void para a chave-------------------------------------------------------
-------------------------------------------------------------------------------------------------------------*/
typedef struct nodo {
	void *chave; 
	struct nodo *pai; 
	struct nodo *esquerda; 
	struct nodo *direita; 
} nodo;

/*-------------------------------------------------------------------------------------------------------------
----Estrutura de dados que reprenta uma árvore binária, possui um ponteiro pro nodo raiz e um contador de nodos
-------------------------------------------------------------------------------------------------------------*/
typedef struct arvbi {
	nodo *raiz;
	size_t nmemb;
} arvbi;

/*-------------------------------------------------------------------------------------------------------------
----Macro que inicializa uma árvore binaria, recebe uma árvore de parâmetro------------------------------------
-------------------------------------------------------------------------------------------------------------*/
#define create_arvbi(S)  S->nmemb=0;S->raiz=NULL

/*-------------------------------------------------------------------------------------------------------------
----Macro que retorna o numero de nodos que a raiz possui, recebe uma árvore de parâmetro----------------------
-------------------------------------------------------------------------------------------------------------*/
#define get_size_arvbi(S) S->nmemb

/*-------------------------------------------------------------------------------------------------------------
----Macro que testa se a árvore está vazia, recebe uma árvore de parâmetro-------------------------------------
-------------------------------------------------------------------------------------------------------------*/
#define test_emptiness_arvbi(S) (S->nmemb==0 ? 1:0) 

/*-------------------------------------------------------------------------------------------------------------
----Função que libera todos os nodos da árvore, que é passada de parâmetro junto com a função que libera a chave
-------------------------------------------------------------------------------------------------------------*/
void free_arvbi(arvbi *S, void (*free_function)(void*));

/*-------------------------------------------------------------------------------------------------------------
----Função que cria um nodo e insere uma chave na árvore, recebe de parâmetros a árvore, a chave a ser---------
-----------inserida e uma função que compara as chaves, que deve retornar valores menores que 0 se a ----------
-----------primeira chave for menor, 0 se ambas as chaves forem iguais e maiores que 0 se a segunda -----------
-----------chave for maior-------------------------------------------------------------------------------------
--------------a função retorna 0 quando inserido corretamente e 1 quando houver erro de malloc----------------
-------------------------------------------------------------------------------------------------------------*/
int insert_arvbi(arvbi *S, void *chave, int (*comp_function)(void*,void*));

/*------------------------------------------------------------------------------------------------------------
----Função que imprime todas as chaves da árvore, recebe de parâmetros a árvore e a função que imprime a chave
-------------------------------------------------------------------------------------------------------------*/
void print_arvbi(arvbi *S, void (*print_function)(void*));

/*-------------------------------------------------------------------------------------------------------------
----Função que retorna a chave que esta sendo buscada, recebe uma árvore, um elemento a ser buscado------------
-----------e uma função de comparação que deve retornar valores menores que 0 se a primeira chave for----------
-----------menor, 0 se ambas as chaves forem iguais e maiores que 0 se a segunda chave for maior---------------
--------------a função retorna um ponteiro para a chave encontrada, quando não encontrada o retorno é NULL-----
-------------------------------------------------------------------------------------------------------------*/
void* get_key(arvbi *S, void *chave, int (*comp_function)(void*,void*));

#endif
