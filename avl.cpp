#include <bits/stdc++.h>
using namespace std;

struct nodo {
  int inf;
  nodo *izq;
  nodo *der;
  int fe;
};

void insert(nodo *&raiz, int dato, int &cent);
void remove(nodo *&raiz, int dato, int &cent);
void rstruct1(nodo *&raiz, int &cent);
void rstruct2(nodo *&raiz, int &cent);
void borra(nodo *&aux, nodo *&q, int &cent);
void view(nodo *raiz, int grado);
void preorden(nodo *raiz);
void postorden(nodo *raiz);
void buscar(nodo *raiz, int dato);

int main(int argc, char *argv[]) {
  // test
  nodo *raiz = NULL;
  int cen = 1;
  insert(raiz, 65, cen);
  insert(raiz, 39, cen);
  insert(raiz, 70, cen);
  insert(raiz, 23, cen);
  insert(raiz, 50, cen);
  insert(raiz, 82, cen);
  insert(raiz, 68, cen);
  insert(raiz, 10, cen);
  insert(raiz, 66, cen);
  insert(raiz, 43, cen);
  insert(raiz, 59, cen);
  // insert(raiz, 4, cen);
  // insert(raiz, 2, cen);
  // insert(raiz, 10, cen);
  remove(raiz, 23, cen);
  view(raiz, 0);
  return 0;
}

void insert(nodo *&raiz, int dato, int &cent) {
  nodo *raiz1, *raiz2, *x;
  if (raiz != NULL) {
    if (dato < raiz->inf) {
      insert(raiz->izq, dato, cent);
      if (cent) {
        switch (raiz->fe) {
        case 1:
          raiz->fe = 0;
          cent = 0;
          break;
        case 0:
          raiz->fe = -1;
          break;
        case -1:
          raiz1 = raiz->izq;
          if (raiz1->fe <= 0) {
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
              raiz1->fe = 0;
            }
            raiz = raiz2;
          }
          raiz->fe = 0;
          cent = 0;
          break;
        }
      }
    } else {
      if (dato > raiz->inf) {
        insert(raiz->der, dato, cent);
        if (cent) {
          switch (raiz->fe) {
          case -1:
            raiz->fe = 0;
            cent = 0;
            break;
          case 0:
            raiz->fe = 1;
            break;
          case 1:
            raiz1 = raiz->der;
            if (raiz1->fe >= 0) {
              raiz->der = raiz1->izq;
              raiz1->izq = raiz;
              raiz->fe = 0;
              raiz = raiz1;
            } else {
              raiz2 = raiz1->izq;
              raiz->der = raiz2->izq;
              raiz2->izq = raiz;
              raiz1->izq = raiz2->der;
              raiz2->der = raiz1;
              if (raiz2->fe == 1) {
                raiz->fe = -1;
              } else {
                raiz->fe = 0;
              }
              if (raiz2->fe == -1) {
                raiz1->fe = 1;
              } else {
                raiz1->fe = 0;
              }
              raiz = raiz2;
            }
            raiz->fe = 0;
            cent = 0;
            break;
          }
        }
      } else {
        cout << "El dato ya existe en el arbol" << endl;
      }
    }
  } else {
    x = new (nodo);
    x->inf = dato;
    x->fe = 0;
    x->izq = x->der = NULL;
    raiz = x;
    cent = 1;
  }
}

void view(nodo *raiz, int grado) {
  if (raiz != NULL) {
    view(raiz->der, grado + 1);
    for (int i = 0; i < grado; i++) {
      cout << "    ";
    }
    cout << raiz->inf << endl;
    view(raiz->izq, grado + 1);
  }
}

void preorden(nodo *raiz) {
  if (raiz != NULL) {
    cout << raiz->inf << " ";
    preorden(raiz->izq);
    preorden(raiz->der);
  }
}
void postorden(nodo *raiz) {
  if (raiz != NULL) {
    preorden(raiz->izq);
    preorden(raiz->der);
    cout << raiz->inf << " ";
  }
}

void buscar(nodo *raiz, int dato) {
  if (dato < raiz->inf) {
    if (raiz->izq == NULL) {
      cout << "EL DATO BUSCADO NO EXISTE\n";
    } else {
      buscar(raiz->izq, dato);
    }
  } else {
    if (dato > raiz->inf) {
      if (raiz->der == NULL) {
        cout << "EL DATO BUSCADO NO EXISTE\n";
      } else {
        buscar(raiz->der, dato);
      }
    } else {
      cout << "EL DATO BUSCADO SI EXISTE\n";
    }
  }
}

void rstruct1(nodo *&raiz, int &cent) {
  if (cent == 1) {
    switch (raiz->fe) {
    case -1:
      raiz->fe = 0;
      break;
    case 0:
      raiz->fe = -1;
      cent = 0;
      break;
    case 1: {
      nodo *raiz1 = raiz->der;
      if (raiz1->fe >= 0) {
        raiz->der = raiz1->izq;
        raiz1->izq = raiz;
        switch (raiz1->fe) {
        case 0:
          raiz->fe = 1;
          raiz1->fe = -1;
          cent = 0;
          break;
        case 1:
          raiz->fe = 0;
          raiz1->fe = 0;
          break;
        }
        raiz = raiz1;
      } else {
        nodo *raiz2 = raiz1->izq;
        raiz->der = raiz2->izq;
        raiz2->izq = raiz;
        raiz1->izq = raiz2->der;
        raiz2->der = raiz1;
        if (raiz2->fe == 1) {
          raiz->fe = -1;
        } else {
          raiz->fe = 0;
        }
        if (raiz2->fe == -1) {
          raiz1->fe = 1;
        } else {
          raiz1->fe = 0;
        }
        raiz = raiz2;
        raiz2->fe = 0;
      }
      break;
    }
    }
  }
}

void rstruct2(nodo *&raiz, int &cent) {
  if (cent == 1) {
    switch (raiz->fe) {
    case 1:
      raiz->fe = 0;
      break;
    case 0:
      raiz->fe = 1;
      cent = 0;
      break;
    case -1: {
      nodo *raiz1 = raiz->izq;
      if (raiz1->fe <= 0) {
        raiz->izq = raiz1->der;
        raiz1->der = raiz;
        switch (raiz1->fe) {
        case 0:
          raiz->fe = -1;
          raiz1->fe = 1;
          cent = 0;
          break;
        case -1:
          raiz->fe = 0;
          raiz1->fe = 0;
          break;
        }
        raiz = raiz1;
      } else {
        nodo *raiz2 = raiz1->der;
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
          raiz1->fe = 0;
        }
        raiz = raiz2;
        raiz2->fe = 0;
      }
    }
    }
  }
}

void borra(nodo *&aux, nodo *&q, int &cent) {
  if (aux->der != NULL) {
    borra(aux->der, q, cent);
    rstruct2(aux, cent);
  } else {
    q->inf = aux->inf;
    aux = aux->izq;
    q = aux;
    cent = 1;
  }
}

void remove(nodo *&raiz, int dato, int &cent) {
  if (raiz != NULL) {
    if (dato < raiz->inf) {
      remove(raiz->izq, dato, cent);
      rstruct1(raiz, cent);
    } else {
      if (dato > raiz->inf) {
        remove(raiz->der, dato, cent);
        rstruct2(raiz, cent);
      } else {
        nodo *q = raiz;
        if (q->der == NULL) {
          raiz = q->izq;
          cent = 1;
        } else if (q->izq == NULL) {
          raiz = q->der;
          cent = 1;
        } else {
          borra(raiz->izq, q, cent);
          rstruct2(raiz, cent);
        }
        delete q;
      }
    }
  } else {
    cout << "El dato no existe" << endl;
  }
}
