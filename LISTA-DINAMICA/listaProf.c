#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "professor.h"
#include "listaProf.h"

struct element {
	Prof *novoProf;
	struct element *prox;
};

struct listaprof {
	Element *inicio;
};

ListaProf *criaListaProf() {
	ListaProf *list = (ListaProf*) malloc(sizeof(ListaProf));
	
	list->inicio = NULL;
	
	return list;
}

void ordenarListaProf(ListaProf *list) {
	Element *aux = list->inicio;
	Element *menor = list->inicio;
	
	do {
		aux = aux->prox;
		int comp = comparaProf(aux->novoProf,menor->novoProf);
		
		if(comp == -1) {
			Element *aux2 = list->inicio;
			while(aux2->prox!=aux) {
				aux2 = aux2->prox;
			}
			aux2->prox = aux->prox;
			aux->prox = list->inicio;
			list->inicio = aux;
			aux = aux->prox;
			menor = list->inicio;
			aux2 = list->inicio;
		}
		else if(comp == 1) {
			menor = menor->prox;
		}
	} while(aux->prox!=NULL);
}

void addProfLista(ListaProf *list,Prof *prof) {
	Element *novoprof = (Element*) malloc(sizeof(Element));
	
	novoprof->novoProf = prof;
	novoprof->prox = NULL;
	
	if(list->inicio==NULL) {
		list->inicio = novoprof;
	}
	else {
		Element *aux = list->inicio;
		
		while(aux->prox!=NULL) {
			aux = aux->prox;
		}
		aux->prox = novoprof;
	
		ordenarListaProf(list);	
	}
}

void imprimeListaProf(ListaProf *list) {
	Element *aux = list->inicio;
	while(aux!=NULL) {
		imprimeProf(aux->novoProf);
		aux = aux->prox;
	}
}

void liberaListaProf(ListaProf *list) {
	Element *aux = list->inicio;
	
	while(aux!=NULL) {
		Element *aux2 = list->inicio;
		list->inicio = aux->prox;
		aux = aux->prox;
		free(aux2);
	}
	
	if(list->inicio == NULL) {
		printf("\n Lista excluida com sucesso! \n");
	}
}

void buscarProfLista(ListaProf *list, char nome[50]) {
	Element *aux = list->inicio;
	
	while(aux!=NULL) {
		int resultado = buscarProf(aux->novoProf,nome);
		
		if(resultado == 1) {
			imprimeProf(aux->novoProf);
			break;
		}
		else {
			aux = aux->prox;
		}
	}
}
