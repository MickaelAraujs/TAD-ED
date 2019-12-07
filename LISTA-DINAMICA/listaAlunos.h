#include "aluno.h"



typedef struct nodo Nodo;

typedef struct listaal ListaAlunos;

ListaAlunos *criaListaAlunos();

void ordenarListaAlunos(ListaAlunos *li);

void addAlunoLista(ListaAlunos *li,Aluno *al);

void imprimeListaAlunos(ListaAlunos *li);

void liberaListaAlunos(ListaAlunos *li);
