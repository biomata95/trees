#include <stdio.h>

#include <stdlib.h>


// RED BLACK Tree

typedef struct no * ApNo;
typedef struct no {
  ApNo esq, dir;
  ApNo pai;
  int chave;
  enum tipoCor {
    BLACK,
    RED
  }
  cor;
}
no;

int nodoNulo(no * p) {
  if (p == NULL) {
    return 0;
  } else {
    return 1;
  }
}

ApNo criaNo(int k, ApNo esq, ApNo dir) {
  ApNo p;

  p = (ApNo) malloc(sizeof(no));
  p -> chave = k;
  p -> esq = esq;
  p -> dir = dir;
  return p;
}

ApNo rotEsq(ApNo p) {
  ApNo dirP; // keep the original address of the right child
  dirP = p -> dir;
  p -> dir = dirP -> esq;
  dirP -> esq = p;
  return dirP;
}

ApNo rotDir(ApNo p) {
  ApNo esqP; // keep the original address of the left child
  esqP = p -> esq;
  p -> esq = esqP -> dir;
  return esqP;
}

void insereRN(ApNo p, int k) {
    p = criaNo(k, NULL, NULL);
    ApNo x = p;
    ApNo paiX = NULL;
    while (x != NULL)
      paiX = x;
    if (k < p -> chave) {
      x = p -> esq;
    } else {
      x = p -> dir;
    }
    /*paiX= ;*/
    if (paiX == NULL) {
      p = novoNodo;
    } else {
      if (k < paiX -> chave) {
        paiX -> esq = novoNodo;
      } else {
        paiX -> dir = novoNodo;
      }
      novoNodo -> cor = RED;
      arrumaArvRN(p, novoNodo);
    }

    void arrumaArvRN(ApNo raiz, ApNo p) {
        ApNo tio;
        while (p -> pai -> cor == RED)
          if (p -> pai == p -> pai -> pai -> esq) {
            /* insertion in subtree.left */
            tio = p -> pai -> pai -> dir;
            if (p -> tio -> cor == RED) {
              /* color to right. Grandfather's is red */
              p -> pai -> cor = BLACK; /* Case 1 */
              p -> tio -> cor = BLACK;
              p -> pai -> pai -> cor = RED;
              p = p -> pai -> pai -> cor;
            } else if {
              /* color to right. Grandfather's is black */
              if (p == p -> pai -> dir) {
                /* unbalancing. in the subtree.dir of the left child */
                p = p -> pai; /* Case 2: left-right */
                rotEsq(p);
              }
              p -> pai -> cor = BLACK; /* Case 3 left-left*/
              p -> pai -> pai -> cor = RED;
              rotDir(p -> pai -> pai);
            } else {
              if (p == p -> pai -> esq) {
                p = p -> pai;
                rotEsq(p);
              }
              p -> pai -> cor = BLACK;
              p -> pai -> pai -> cor = RED;
              rotEsq(p -> pai -> pai);
              /* insertion in subarv. right -- ditto changing dir <-> left */
            }
            raiz -> cor = BLACK;
          }

        int main() {
          int num;
          ApNo raiz;
          scanf("%d", & num);
          insereRN(raiz, num);
          return 0;
        }