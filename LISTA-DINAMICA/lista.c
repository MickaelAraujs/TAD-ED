#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "aluno.h"
#include "lista.h"

struct nodo {
	Aluno *novoAluno;
	struct nodo *proximo;
};

struct lista {
	Nodo *inicio;
};

Lista *criaLista() {
	Lista *li = (Lista*) malloc(sizeof(Lista));
	
	li->inicio = NULL;
	
	return li;
}

void ordenarLista(Lista *li) {
	Nodo *aux = li->inicio;
	Nodo *menor = li->inicio;
	
	do {
		aux = aux->proximo;
		int comp = comparaAluno(aux->novoAluno,menor->novoAluno);
		
		if(comp == -1) {
			menor = aux;
		// aqui ta dando problema, corrigir...	
			Nodo *aux2 = menor->proximo;
			menor->proximo = li->inicio;
			li->inicio->proximo = aux2;
			li->inicio = menor;
			menor = menor->proximo;
		}
	} while(aux->proximo!=NULL);
}


void addAlunoLista(Lista *li,Aluno *al) {

	Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
	
	novo->novoAluno = al;
	novo->proximo = NULL;
	
	if(li->inicio==NULL) {
		li->inicio = novo;
	}
	else {
		Nodo *aux = li->inicio;
		
		while(aux->proximo!=NULL) {
			aux = aux->proximo;
		}
		aux->proximo = novo;
	
		ordenarLista(li);
	}
}


void imprimeLista(Lista *li) {
	Nodo *aux = li->inicio;
	while(aux!=NULL) {
		imprimeAluno(aux->novoAluno);
		aux = aux->proximo;
	}
}
