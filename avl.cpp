#include <bits/stdc++.h>
using namespace std;

struct nodo {
  int inf;
  nodo *izq;
  nodo *der;
  int fe;
};

void insert(nodo *&, int, bool &);
void reestructizq(nodo *&, bool &);

int main(int argc, char *argv[]) { return 0; }

void insert(nodo *&raiz, bool &cen, int dato) {
  nodo *raiz1, *raiz2, *x;
  if (raiz != NULL) {
    if (dato < raiz->inf) {
      insert(raiz->izq, cen, dato);
      if (cen == 1) {
        switch (raiz->fe) {
        case 1:
          raiz->fe = 0;
          cen = 0;
          break;
        case 0:
          raiz->fe = -1;
          break;
        case -1:
          raiz1 = raiz->izq;
          if (raiz1->fe <= 0) {
            // Izquierda Izquierda
            raiz->izq = raiz1->der;
            raiz1->der = raiz;
            raiz->fe = 0;
            raiz = raiz1;
          } else {
            raiz2 = raiz1->der;
            raiz->izq = raiz2->der;
            raiz2->der = raiz;
            raiz1->der = raiz2->izq;
            raiz2->izq = raiz1;
            if (raiz2->fe == -1) {
              raiz->fe = 1;
            } else {
              raiz->fe = 0;
            }
            if (raiz2->fe == 1) {
              raiz1->fe = -1;
            } else {
              raiz2->fe = 0;
            }
            raiz = raiz2;
          }
          raiz->fe = 0;
          cen = 0;
          break;
        }
      }
    } else if (dato > raiz->inf) {
      insert(raiz->der, cen, dato);
      if (cen == 1) {
        switch (raiz->fe) {
        case -1:
          raiz->fe = 0;
          cen = 0;
          break;
        case 0:
          raiz->fe = 1;
          break;
        case 1:
          raiz1 = raiz->der;
          if (raiz1->fe >= 0) {
            // Derecha Derecha
            raiz->der = raiz1->izq;
            raiz1->izq = raiz;
            raiz->fe = 0;
            raiz = raiz1;
          } else {
            // Derecha Izquierda
            raiz2 = raiz1->izq;
            raiz->der = raiz2->izq;
            raiz2->izq = raiz;
            raiz1->izq = raiz2->der;
            raiz2->der = raiz1;
            if (raiz2->fe == 1)
              raiz->fe = -1;
            else
              raiz->fe = 0;
            if (raiz2->fe == -1)
              raiz1->fe = 1;
            else
              raiz1->fe = 0;
            raiz = raiz2;
          }
          raiz->fe = 0;
          cen = 0;
          break;
        }
      }
    } else {
      cout << "\nEL DATO YA EXISTE EN EL ARBOL...\n\n";
    }
  } else {
    x = new (nodo);
    x->inf = dato;
    x->der = NULL;
    x->izq = NULL;
    x->fe = 0;
    raiz = x;
    cen = 1;
  }
}
