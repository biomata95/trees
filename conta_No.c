#include <stdio.h>

#include <stdlib.h>

// Build a recursive function that counts the number of nodes inside a tree

typedef struct no * Apontador;
struct no {
  int chave;
  Apontador esq, dir;
}
No;

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
  novo -> esq = NULL;
  novo -> dir = NULL;
  novo -> chave = chave;
  return novo;
}

Apontador insere(Apontador p, int valor) {
  if (p == NULL) {
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
  if (p == NULL) {
    return;
  }
  emOrdem(p -> esq);
  printf("%d ", p -> chave);
  emOrdem(p -> dir);
}

int main() {
  int valor;
  Apontador raiz;
  criaArv( & raiz);
  valor = 0;
  while (valor != -1) {
    scanf("%d", & valor);
    if (valor != -1) {
      raiz = insere(raiz, valor);
    }
  }
  printf("Number of nodes is: %d \n", conta(raiz));
  printf("Printing:\n");
  emOrdem(raiz);
  return 0;
}