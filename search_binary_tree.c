#include <stdio.h>

#include <stdlib.h>

typedef struct no * ApNo;
typedef struct no {
  int chave;
  ApNo esq, dir;
}
TipoNo;

void criaArv(ApNo * p) {
  * p = NULL;
  return;
}

ApNo criaNo(int num, ApNo esq, ApNo dir) {
  ApNo p;
  p = (ApNo) malloc(sizeof(TipoNo));
  p -> chave = num;
  p -> esq = esq;
  p -> dir = dir;
  return p;
}

ApNo insere(int num, ApNo p) {
  if (p == NULL) {
    return criaNo(num, NULL, NULL);
  }
  if (num < p -> chave) {
    p -> esq = insere(num, p -> esq);
  } else {
    p -> dir = insere(num, p -> dir);
  }
  return p;
}

void imprimeArv(ApNo p) {
  if (p == NULL) {
    printf("()");
  } else {
    printf("(%d", p -> chave);
    imprimeArv(p -> esq);
    imprimeArv(p -> dir);
    printf(")");
  }
  return;
}

ApNo busca(int k, ApNo p) {
  if (p == NULL) {
    return NULL;
  }
  if (p -> chave == k) {
    return p;
  }
  if (k < p -> chave) {
    return busca(k, p -> esq);
  } else {
    return busca(k, p -> dir);
  }
}

int main() {
  ApNo raiz;
  int num;
  criaArv( & raiz);
  printf("Enter values ​​up to -1 \n");
  while (num != -1) {
    scanf("%d", & num);
    raiz = insere(num, raiz);
  }
  printf("Do you want to search for some value \n");
  scanf("%d", & num);
  if (busca(num, raiz) != NULL) {
    printf("This value has been found \n");
  } else {
    printf("This value was not found \n");
  }
  printf("Printing \n");
  imprimeArv(raiz);
  printf("\n");
  return 0;
}