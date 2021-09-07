#include <stdio.h>

#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct no * ApNo;
typedef struct no {
  int chave, bal;
  ApNo esq, dir;
}
TipoNo;

void criaArv(ApNo * p) {
  * p = NULL;
  return;
}

ApNo createNodo(int k, ApNo esq, ApNo dir) {
  ApNo p;
  p = (ApNo) malloc(sizeof(TipoNo));
  p -> chave = k;
  p -> esq = esq;
  p -> dir = dir;
  p -> bal = 0;
  return p;
}

/*-------------------------RotationLeft----------------------------*/
ApNo rotEsq(ApNo p) {
  ApNo f;
  f = p -> dir;
  p -> dir = f -> esq;
  f -> esq = p;
  return f;
}

/*--------------------------------------------------------------------*/

/*-------------------------RotationRight-----------------------------*/
ApNo rotDir(ApNo p) {
  ApNo f;
  f = p -> esq;
  p -> esq = f -> dir;
  f -> dir = p;
  return f;
}

/*--------------------------------------------------------------------*/

ApNo balanceia(ApNo p) {
  ApNo f, n;
  if (p -> bal == 2) { // left unbalanced //
    f = p -> esq;
    if (f -> bal == 1) { //left-left//
      p -> bal = 0;
      f -> bal = 0;
      return rotDir(p);
    } else { //left-right//
      n = f -> dir;
      if (n -> bal == 0) {
        f -> bal = 0;
        p -> bal = 0;
      } else if (n -> bal == 1) {
        f -> bal = 0;
        p -> bal = -1;
      } else {
        f -> bal = 1;
        p -> bal = 0;
      }
      n -> bal = 0;
      p -> esq = rotEsq(f);
      return rotDir(p);
    }
  } else if (p -> bal == -2) { // unbalanced to the right //
    f = p -> dir;
    if (f -> bal == -1) { //right-right//
      p = rotEsq(p);
      p -> bal = 0;
      f -> bal = 0;
      return rotEsq(p);
    } else { //dir-esq//
      n = f -> esq;
      rotDir(f);
      p = rotEsq(p);
      if (n -> bal == 0) {
        f -> bal = 0;
        p -> bal = 0;
      } else if (n -> bal == 0) {
        f -> bal = 0;
        p -> bal = -1;
      } else {
        f -> bal = 1;
        p -> bal = 0;
      }
    }
  }
}

ApNo insere(ApNo p, int n, int * mudouH) {
  if (p == NULL) {
    * mudouH = TRUE;
    return criaNodo(n, NULL, NULL);
  }
  if (p -> chave > n) {
    p -> esq = insere(p -> esq, n, mudouH);
    if ( * mudouH) {
      p -> bal++;
      if (p -> bal == 2) {
        p = balanceia(p);
      }
    }
  } else {
    p -> dir = insere(p -> dir, n, mudouH);
    if ( * mudouH) {
      p -> bal--;
      if (p -> bal == -2) {
        p = balanceia(p);
      }
    }
  }
  if (p -> bal == 0) {
    * mudouH = FALSE;
  }
  return p;
}

void imprimeArv(ApNo p) {
  if (p == NULL) {
    printf("()");
  } else {
    printf("(%d:%d", p -> chave, p -> bal);
    imprimeArv(p -> esq);
    imprimeArv(p -> dir);
    printf(")");
  }
  return;
}

int main() {
  ApNo raiz;
  int num, mudouH;
  criaArv( & raiz);
  num = 0;
  mudouH = FALSE;
  while (num != -1) {
    scanf("%d", & num);
    if (num != -1) {
      raiz = insere(raiz, num, & mudouH);
      printf(":%d", raiz -> bal);
    }
  }
  balanceia(raiz);
  imprimeArv(raiz);
  return 0;
}