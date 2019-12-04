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
	printf("\n\nNOME DO ALUNO: %s\n",novoAl->nome);
	printf("\n\n");
	printf("MATRICULA DO ALUNO: %s\n\n",novoAl->matricula);
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
