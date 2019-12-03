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
	
	printf("\nAluno inserido com sucesso!");
}

void imprimeAluno(Aluno *novoAl) {
	printf("NOME DO ALUNO: %s",novoAl->nome);
	printf("\n\n");
	printf("MATRICULA DO ALUNO: %s",novoAl->matricula);
} 
