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

ApNo criaNodo(int k, ApNo esq, ApNo dir) {
  ApNo p;
  p = (ApNo) malloc(sizeof(TipoNo));
  p -> chave = k;
  p -> esq = esq;
  p -> dir = dir;
  p -> bal = 0;
  return p;
}

/*-------------------------LeftRotation----------------------------*/
ApNo rotEsq(ApNo p) {
  ApNo f;
  f = p -> dir;
  p -> dir = f -> esq;
  f -> esq = p;
  return f;
}

/*--------------------------------------------------------------------*/

/*-------------------------RightRotation-----------------------------*/
ApNo rotDir(ApNo p) {
  ApNo f;
  f = p -> esq;
  p -> esq = f -> dir;
  f -> dir = p;
  return f;
}

/*--------------------------------------------------------------------*/

ApNo insere(ApNo p, int n, int * mudouH) {
  if (p == NULL) {
    * mudouH = TRUE;
    return criaNodo(n, NULL, NULL);
  }
  if (p -> chave > n) {
    p -> esq = insere(p -> esq, n, mudouH);
    if ( * mudouH) {
      p -> bal++;
    }
  } else {
    p -> dir = insere(p -> dir, n, mudouH);
    if ( * mudouH) {
      p -> bal--;
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

int verificaAVL(ApNo p, int k) {
  if (p == NULL) {
    return k;
  } else {
    if ((p -> bal < -1) || (p -> bal > 1)) {
      k++;
    }
    return verificaAVL(p -> esq, k);
    return verificaAVL(p -> dir, k);
  }
}

int main() {
  ApNo raiz;
  int num, mudouH, aux;
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
  aux = 0;
  aux = verificaAVL(raiz, 0);
  printf("%d\n\n", aux);
  if (aux == 0) {
    printf("The tree is AVL\n");
  } else {
    printf("The tree is not AVL \n");
  }
  imprimeArv(raiz);
  return 0;
}