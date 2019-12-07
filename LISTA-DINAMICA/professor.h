
//criando tad professor

typedef struct professor Prof;

//criando novo professor

Prof *criaProf();

//adicionando nome e matricula ao tad professor

void addProf(char nomeProf[50],char matriculaProf[10],float salarioProf,Prof *novoProf);

//imprimindo informacoes de aluno

void imprimeProf(Prof *novoProf);

int comparaProf(Prof *prof1,Prof *prof2);

void liberarProf(Prof *prof, char nome[50]);

int buscarProf(Prof *prof, char nome[50]);
