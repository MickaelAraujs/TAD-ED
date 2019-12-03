#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	}
}

void imprimeLista(Lista *li) {
	Nodo *aux = li->inicio;
	while(aux!=NULL) {
		imprimeAluno(aux->novoAluno);
		aux = aux->proximo;
	}
}
