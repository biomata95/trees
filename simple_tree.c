#include <stdio.h>

#include <stdlib.h>

typedef struct no * ApNo; /* nodo */
typedef struct no {
  /* tree struct */
  int chave;
  ApNo esq, dir;
}
TipoNo;

/*-----------------------------------------------------------------*/
/* tree generation                                                 */

void criaArv(ApNo * raiz) {
  * raiz = NULL;
  return;
}

ApNo criaNo(int k, ApNo esq, ApNo dir) {
  ApNo p;

  p = (ApNo) malloc(sizeof(TipoNo));
  p -> chave = k;
  p -> esq = esq;
  p -> dir = dir;
  return p;
}

ApNo insere(int k, ApNo p) {
  if (p == NULL) {
    return criaNo(k, NULL, NULL);
  }
  if (k <= p -> chave)
    p -> esq = insere(k, p -> esq);
  else
    p -> dir = insere(k, p -> dir);
  return p;
}

/*-----------------------------------------------------------------*/
/* tree print                                                      */

void imprimeArv(ApNo p) {

  if (p == NULL)
    printf("()");
  else {
    printf("(%d ", p -> chave);
    imprimeArv(p -> esq);
    imprimeArv(p -> dir);
    printf(")");
  }
  return;
}

/*-----------------------------------------------------------------*/

int main(int argc, char * argv[]) {
  ApNo raiz;
  int chave;

  criaArv( & raiz);

  printf("Enter a key sequence. End the sequence with -1: \n");
  scanf("%d", & chave);
  while (chave != -1) {
    raiz = insere(chave, raiz);
    scanf("%d", & chave);
  }
  printf("Tree \n");
  imprimeArv(raiz);
  printf("\n");
  return 0;
}