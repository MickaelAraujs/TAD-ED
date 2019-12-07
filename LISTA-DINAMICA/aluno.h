
//criando tad aluno
typedef struct aluno Aluno;

//criando novo aluno
Aluno *criaAluno();

//adicionando nome e matricula ao tad aluno
void addAluno(char nomeAl[50],char matriculaAl[10],Aluno *novoAl);

//imprimindo informacoes de aluno
void imprimeAluno(Aluno *novoAl);

int comparaAluno(Aluno *al1,Aluno *al2);

void liberarAluno(Aluno *al, char nome[50]);

int buscar(Aluno *al, char nome[50]);
