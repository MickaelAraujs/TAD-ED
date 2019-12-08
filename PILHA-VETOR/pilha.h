
typedef struct pilha Pilha;

Pilha* cria(void);

int vazia(Pilha* p);

void push(Pilha* p, int v);

int pop(Pilha* p);

void libera(Pilha* p);
