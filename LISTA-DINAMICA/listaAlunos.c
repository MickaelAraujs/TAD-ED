#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "aluno.h"
#include "listaAlunos.h"

struct nodo {
	Aluno *novoAluno;
	struct nodo *proximo;
};

struct listaal {
	Nodo *inicio;
};

ListaAlunos *criaListaAlunos() {
	ListaAlunos *li = (ListaAlunos*) malloc(sizeof(ListaAlunos));
	
	li->inicio = NULL;
	
	return li;
}

void ordenarListaAlunos(ListaAlunos *li) {
	Nodo *aux = li->inicio;
	Nodo *menor = li->inicio;
	
	do {
		aux = aux->proximo;
		int comp = comparaAluno(aux->novoAluno,menor->novoAluno);
		
		if(comp == -1) {
			Nodo *aux2 = li->inicio;
			while(aux2->proximo!=aux) {
				aux2 = aux2->proximo;
			}
			aux2->proximo = aux->proximo;
			aux->proximo = li->inicio;
			li->inicio = aux;
			aux = aux->proximo;
			menor = li->inicio;
			aux2 = li->inicio;	
		}
		else if(comp == 1) {
			menor = menor->proximo;
		}
	} while(aux->proximo!=NULL);
}


void addAlunoLista(ListaAlunos *li,Aluno *al) {

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
	
		ordenarListaAlunos(li);
	}
}


void imprimeListaAlunos(ListaAlunos *li) {
	Nodo *aux = li->inicio;
	while(aux!=NULL) {
		imprimeAluno(aux->novoAluno);
		aux = aux->proximo;
	}
}

void liberaListaAlunos(ListaAlunos *li) {
	Nodo *aux = li->inicio;
	
	while(aux!=NULL) {
		Nodo *aux2 = li->inicio;
		li->inicio = aux->proximo;
		aux = aux->proximo;
		free(aux2);
	}
	
	if(li->inicio == NULL) {
		printf("\n Lista excluida com sucesso! \n");
	}
}

void buscarAlunoLista(ListaAlunos *li, char nome[50]) {
	Nodo *aux = li->inicio;
	
	while(aux!=NULL) {
		int resultado = buscar(aux->novoAluno, nome);
		
		if(resultado == 1) {
			imprimeAluno(aux->novoAluno);
			break;
		}
		else {
			aux = aux->proximo;
		}
	}
}
