#include <stdio.h>

#include <stdlib.h>

// Build a recursive function that averages the elements of a tree

typedef struct no * Apontador;
struct no {
  int chave;
  Apontador esq, dir;
  int contaNodo;
}
No;

static Apontador nodoNULL;

void criaArv(Apontador * p) {
  * p = NULL;
  return;
}

Apontador criaNo(int chave) {
  Apontador novo;
  novo = malloc(sizeof(No));
  if (!novo) {
    return NULL;
  }
  novo -> esq = nodoNULL;
  novo -> dir = nodoNULL;
  novo -> chave = chave;
  return novo;
}

Apontador inicializaDic() {
  nodoNULL = criaNo(0);
  return nodoNULL;
}

Apontador insere(Apontador p, int valor) {
  if (p == nodoNULL) {
    return criaNo(valor);
  }
  if (valor < p -> chave) {
    p -> esq = insere(p -> esq, valor);
  } else {
    p -> dir = insere(p -> dir, valor);
  }
  return p;
}

void emOrdem(Apontador p) {
  if (p == nodoNULL) {
    return;
  }
  emOrdem(p -> esq);
  printf("%d ", p -> chave);
  emOrdem(p -> dir);
}

int media(Apontador p, int k) {
  if (p == nodoNULL) {
    return k;
  } else {
    return p -> chave + media(p -> esq, k) + media(p -> dir, k);
  }
}

int main() {
  int valor, k;
  Apontador raiz;
  raiz = inicializaDic();
  criaArv( & raiz);
  valor = 0;
  k = 0;
  while (valor != -1) {
    scanf("%d", & valor);
    if (valor != -1) {
      raiz = insere(raiz, valor);
      k++;
    }
  }
  printf("The average is: %.1f \n", media(raiz, 0));
  printf("Printing:\n");
  emOrdem(raiz);
  return 0;
}