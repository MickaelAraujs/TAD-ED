#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "aluno.h"
#include "lista.h"

main() {
	Lista *newLista = criaLista();
	
	printf("TESTANDO IMPLEMENTACAO ...\n\n\n\n");
	
	char nomeAl[50], matriculaAl[10];
	int k;
	for(k=1;k<=5;k++) {
		printf("informe o nome do aluno\n");
		fflush(stdin);
		gets(nomeAl);
		printf("\ninforme a matricula do aluno %s\n",nomeAl);
		fflush(stdin);
		gets(matriculaAl);
		
		Aluno *newAluno = criaAluno();
		addAluno(nomeAl,matriculaAl,newAluno);
		addAlunoLista(newLista,newAluno);
	}
	
	printf("\n\n\n ALUNOS MATRICULADOS: \n\n");
	imprimeLista(newLista);
}
