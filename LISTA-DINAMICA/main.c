#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "aluno.h"
#include "listaAlunos.h"

#include "professor.h"
#include "listaProf.h"

void interface(int opcao,ListaAlunos *listaDeAlunos,ListaProf *listaProfessores) {
	system("cls");
	
	char nomeAl[50], matriculaAl[10];
	
	char nomeProf[50], matriculaProf[10];
	float salarioProf;
	
	switch(opcao) {
		case 1 : {
			Aluno *newAluno = criaAluno();
			
			printf("informe o nome do aluno:\n");
			fflush(stdin);
			gets(nomeAl);
			
			printf("informe a matricula de %s:\n",nomeAl);
			fflush(stdin);
			gets(matriculaAl);
			
			addAluno(nomeAl,matriculaAl,newAluno);
			addAlunoLista(listaDeAlunos,newAluno);
			break;
		}
		
		case 2: {
			Prof *newProf = criaProf();
					
			printf("informe o nome do professor:\n");
			fflush(stdin);
			gets(nomeProf);
			
			printf("informe a matricula de %s:\n",nomeProf);
			fflush(stdin);
			gets(matriculaProf);
			
			printf("informe o salario de %s:\n",nomeProf);
			scanf("%f",&salarioProf);
			
			addProf(nomeProf,matriculaProf,salarioProf,newProf);
			addProfLista(listaProfessores,newProf);
			break;
		}
		case 3 : {
			printf("informe o nome do aluno:\n");
			fflush(stdin);
			gets(nomeAl);
			
			buscarAlunoLista(listaDeAlunos,nomeAl);
			break;
		}
		case 4 : {
			printf("informe o nome do professor:\n");
			fflush(stdin);
			gets(nomeProf);
			
			buscarProfLista(listaProfessores,nomeProf);
			break;
		}
		case 5 :  {
			imprimeListaAlunos(listaDeAlunos);
			break;
		}
		case 6 : {
			imprimeListaProf(listaProfessores);
			break;
		}
		case 7 : {
			char c;
			printf("Tem certeza que deseja excluir toda a lista?\n\n Digite S para confirmar\n");
			fflush(stdin);
			scanf("%c",&c);
			
			if(c == 's' || c == 'S') {
				liberaListaAlunos(listaDeAlunos);
			}
			else {
				printf("\nOperacao cancelada!");
			}
			break;
		}
		case 8 : {
			char c;
			printf("Tem certeza que deseja excluir toda a lista?\n\n Digite S para confirmar\n");
			fflush(stdin);
			scanf("%c",&c);
			
			if(c == 's' || c == 'S') {
				liberaListaProf(listaProfessores);
			}
			else {
				printf("\nOperacao cancelada!");
			}
			break;
		}
		case 0: break;
		default: printf("\nOperacao invalida!!!\n");
	}

	system("pause");	
}

void main(void) {
	ListaAlunos *listaDeAlunos = criaListaAlunos();
	ListaProf *listaProfessores = criaListaProf();
	
	int opcao;
	
	do {
		printf("================================ MENU DE OPCOES =============================");
		printf("\n\n DIGITE O NUMERO QUE CORRESPONDE A OPCAO DESEJADA: \n\n");
		printf("1. INSERIR ALUNO\n\n");
		printf("2. INSERIR PROFESSOR\n\n");
		printf("3. BUSCAR ALUNO\n\n");
		printf("4. BUSCAR PROFESSOR\n\n");
		printf("5. IMPRIMIR LISTA DE ALUNOS\n\n");
		printf("6. IMPRIMIR LISTA DE PROFESSORES\n\n");
		printf("7. EXCLUIR TODOS OS ALUNOS DA LISTA\n\n");
		printf("8. EXCLUIR TODOS OS PROFESSORES DA LISTA\n\n");
		printf("\n\n0. SAIR DO SISTEMA\n");
		printf("=============================================================================\n\n");
		
		scanf("%d",&opcao);
		interface(opcao,listaDeAlunos,listaProfessores);
		system("cls");
	} while(opcao!=0);
}
