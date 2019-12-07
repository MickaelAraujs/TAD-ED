#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "aluno.h"


struct aluno {
	char nome[50];
	char matricula[10];
};


Aluno *criaAluno() {
	Aluno *al = (Aluno*) malloc(sizeof(Aluno));
	
	return al;
}

void addAluno(char nomeAl[50],char matriculaAl[10],Aluno *novoAl) {
	strcpy(novoAl->nome,nomeAl);
	strcpy(novoAl->matricula,matriculaAl);
	
	printf("\nAluno inserido com sucesso!\n\n");
}

void imprimeAluno(Aluno *novoAl) {
	printf("========================================\n\n");
	printf("NOME DO ALUNO: %s",novoAl->nome);
	printf("\n\n");
	printf("MATRICULA DO ALUNO: %s",novoAl->matricula);
	printf("\n\n");
	printf("========================================\n\n");
} 

int comparaAluno(Aluno *al1,Aluno *al2) {
	int cmp = strcmp(al1->nome,al2->nome);
	
	if(cmp == 0) {
		return 0;
	}
	else if(cmp > 0) {
		return 1;
	}
	
	return -1;
}

void liberarAluno(Aluno *al, char nome[50]) {
	int cmp = strcmp(al->nome,nome);
	
	if(cmp == 0) {
		free(al);
	}
	else {
		printf("\nAluno nao encontrado!\n");
	}
}

int buscar(Aluno *al, char nome[50]) {
	int cmp = strcmp(al->nome,nome);
	
	if(cmp == 0) {
		return 1;
	}
	
	return -1;
}
