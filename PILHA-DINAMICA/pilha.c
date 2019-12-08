#include<stdio.h>
#include<stdlib.h>

#include "pilha.h"

struct no {
	int info;
	struct no* prox;
};

typedef struct no No;

struct pilha {
	No* prim;
};

Pilha* cria(void) {
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

int vazia(Pilha* p) {
	return (p->prim==NULL);
}

/* função auxiliar: insere no início */
No* ins_ini(No* l, int v) {
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;
	return p;
}

/* função auxiliar: retira do início */
No* ret_ini(No* l) {
	No* p = l->prox;
	free(l);
	return p;
}

void push(Pilha* p, int v) {
	p->prim = ins_ini(p->prim,v);
}

int pop(Pilha* p) {
	int v;
	if(vazia(p)) {
	printf("Pilha vazia.\n");
	exit(1); /* aborta programa */
	}
	v = p->prim->info;
	p->prim = ret_ini(p->prim);
	return v;
}

void libera (Pilha* p) {
	No* q = p->prim;
	while(q!=NULL) {
		No* t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}
