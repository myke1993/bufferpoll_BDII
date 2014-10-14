#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "buffend.h"
#include "erros.h"
void cria_tabelas(){
	char nome[40][40], tipo;
	int campos,tamanho,erro,i,j,tuplas;
	printf("  QUAL SERA O NOME DA SUA TABELA?\n\n  ==> ");
	scanf(" %s",nome[0]);
	table *t = NULL;
	column *c = NULL;
	t = iniciaTabela(nome[0]);
	if(t == ERRO_NOME_TABELA_INVALIDO){
		printf("\n\nErro: Nome da tabela já existente.\n\n");
		return;
	}
	printf("  QUANTOS CAMPOS TERA SUA TABELA?\n\n  ==> ");
	scanf(" %d",&campos);
	for(i=1;i<=campos;i++){
		printf("\n  NOME DO CAMPO  ==>  ");
		scanf(" %s",nome[i]);
		printf("\n  TIPO DO CAMPO, S = STRING, I = INTEIRO, D = DOUBLE C = CHAR  ==>  ");
		scanf(" %c",&tipo);
		while(tipo!='S'&&tipo!='I'&&tipo!='D'&&tipo!='C'){
			printf("\n  TIPO INVALIDO \n\nTIPO DO CAMPO, S = STRING, I = INTEIRO, D = DOUBLE C = CHAR  ==>  ");
			scanf(" %c",&tipo);
		}
		switch(tipo){
			case 'I':{tamanho = sizeof(int);break;}
			case 'D':{tamanho = sizeof(double);break;}
			case 'C':{tamanho = sizeof(char);break;}
			case 'S':{ printf("\n  QUANTIDADE DE CARACTERES  ==>  ");
						scanf(" %d ",&tamanho);
						tamanho*=sizeof(char); break;}
		}
		t = adicionaCampo(t, nome[i],tipo,tamanho);
	}
	erro = finalizaTabela(t);

	if(erro != SUCCESS){
		printf("Erro %d: na função finalizaTabela().\n", erro);
		return;
	}
	printf("\n\n  QUANTAS TUPLAS(LINHAS) TERA SUA TABELA?\n\n  ==> ");
	scanf("%d",&tuplas);
	printf("\n  INSIRA OS VALORES NA TABELA:\n");
	for(j=0;j<tuplas;j++){
		for(i=1;i<=campos;i++){
			printf("\n %s :   ==> ",nome[i]);
			scanf(" %s",nome[39]);
			c = insereValor(c, nome[i], nome[39]);
		}
	}
	erro = finalizaInsert(nome[0], c);

	if(erro != SUCCESS){
		printf("Erro: na Insersão\n");
		return;
	}
	
}
void insere_valores(){
	//descobrir como fazer pra inserir no depois de pronto!!
}
void mostra_valores(){
}

int main(){ 

	int op = 0, menu_inicial = 1;

	while(menu_inicial){
		printf("\n----MENU PARA CRIAÇÃO E MODIFICAÇÃO DE TABELAS----\n\n");
		printf("  TECLE 1 CRIAR TABELAS \n");
		//printf("  TECLE 2 PARA INSERIR VALORES NAS TABELAS \n");
		printf("  TECLE 3 PARA MOSTRAR AS TUPLAS DAS TABELAS \n");
		printf("  TECLE 4 PARA SAIR DO PROGRAMA \n\n  ==> ");
		scanf("%d", &op);
		if(op<1 || op>4){
            printf("  \n\n NUMERO INVALIDO \n");
		}
		else{
			switch(op){
			case 1: {cria_tabelas();break;}
			//case 2: {insere_valores();break;}
			case 3: {mostra_valores();break;}
			case 4: {printf("\n\n    >>PROGRAMA FINALIZADO<<\n\n\n");return 0;}
			}
		}
	}
	return 1;
}
