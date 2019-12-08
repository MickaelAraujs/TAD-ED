#include<stdio.h>
#include<stdlib.h>

#include "pilha.h"

#define MAX 50

struct pilha {
	int n;
	float vet[MAX];
};

Pilha* cria(void) {
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->n = 0; /* inicializa com zero elementos */
	return p;
}

int vazia(Pilha* p) {
	if(p->n==0) {
		return 1;
	}
	
	return 0;
}

void push(Pilha* p, int v) {
	if(p->n == MAX) { /* capacidade esgotada */
	printf("Capacidade da pilha estourou.\n");
	exit(1); /* aborta programa */
	}
	/* insere elemento na próxima posição livre */
	p->vet[p->n] = v;
	p->n++;
}

int pop(Pilha* p) {
	int v;
	if(vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1); /* aborta programa */
	}
	/* retira elemento do topo */
	v = p->vet[p->n-1];
	p->n--;
	return v;
}

void libera(Pilha* p) {
	free(p);
}
