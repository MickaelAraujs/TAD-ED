#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "professor.h"


struct professor {
	char nome[50];
	char matricula[10];
	float salario;
};

Prof *criaProf() {
	Prof *prof = (Prof*) malloc(sizeof(Prof));
	
	return prof;
}

void addProf(char nomeProf[50],char matriculaProf[10],float salarioProf,Prof *novoProf) {
	strcpy(novoProf->nome,nomeProf);
	strcpy(novoProf->matricula,matriculaProf);
	
	novoProf->salario = salarioProf;
	
	printf("\n professor adicionado com sucesso!\n");
}

void imprimeProf(Prof *novoProf) {
	printf("=========================================");
	printf("NOME DO PROFESSOR: %s",novoProf->nome);
	printf("\n\n");
	printf("MATRICULA DO PROFESSOR: %s",novoProf->matricula);
	printf("\n\n");
	printf("SALARIO DO PROFESSOR: %.2f",novoProf->salario);
	printf("\n\n");
	printf("=========================================");
}

int comparaProf(Prof *prof1,Prof *prof2) {
	int cmp = strcmp(prof1->nome,prof2->nome);
	
	if(cmp == 0) {
		return 0;
	}
	else if(cmp > 0) {
		return 1;
	}
	
	return -1;
}

void liberarProf(Prof *prof, char nome[50]) {
	int cmp = strcmp(prof->nome,nome);
	
	if(cmp == 0) {
		free(prof);
	}
	else {
		printf("\n professor nao encontrado! \n");
	}
}
