#include "professor.h"

typedef struct element Element;

typedef struct listaprof ListaProf;

ListaProf *criaListaProf();

void ordenarListaProf(ListaProf *list);

void addProfLista(ListaProf *list,Prof *prof);

void imprimeListaProf(ListaProf *list);

void liberaListaProf(ListaProf *list);
