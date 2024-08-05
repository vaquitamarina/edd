#include <iostream>
using namespace std;

struct nodo {
  int inf;
  nodo *izq;
  nodo *der;
};

void insert(nodo *&, int);
void remove(nodo *&, int);
void preOrder(nodo *);
void inOrder(nodo *);
void postOrder(nodo *);
void view(nodo *, int);

int main(int argc, char *argv[]) {
  nodo *raiz = NULL;
  insert(raiz, 10);
  insert(raiz, 5);
  insert(raiz, 20);
  remove(raiz, 10);
  view(raiz, 0);
  return 0;
}

void insert(nodo *&raiz, int x) {
  if (raiz == NULL) {
    raiz = new nodo;
    raiz->inf = x;
    raiz->izq = NULL;
    raiz->der = NULL;
  } else {
    if (x < raiz->inf) {
      insert(raiz->izq, x);
    } else {
      insert(raiz->der, x);
    }
  }
}

void remove(nodo *&raiz, int x) {
  if (raiz != NULL) {
    if (x < raiz->inf) {
      remove(raiz->izq, x);
    } else if (x > raiz->inf) {
      remove(raiz->der, x);
    } else {
      nodo *p = raiz;
      if (p->der == NULL) {
        raiz = p->izq;
      } else if (p->izq == NULL) {
        raiz = p->der;
      } else {
        p = p->izq;
        while (p->der != NULL) {
          p = p->der;
        }
        p->der = raiz->der;
        p = raiz;
        raiz = raiz->izq;
      }
      delete p;
    }
  }
}

void preOrder(nodo *raiz) {
  if (raiz != NULL) {
    cout << raiz->inf << " ";
    preOrder(raiz->izq);
    preOrder(raiz->der);
  }
}

void inOrder(nodo *raiz) {
  if (raiz != NULL) {
    inOrder(raiz->izq);
    cout << raiz->inf << " ";
    inOrder(raiz->der);
  }
}

void postOrder(nodo *raiz) {
  if (raiz != NULL) {
    postOrder(raiz->izq);
    postOrder(raiz->der);
    cout << raiz->inf << " ";
  }
}

void view(nodo *raiz, int n) {
  if (raiz != NULL) {
    view(raiz->der, n + 1);
    for (int i = 0; i < n; i++) {
      cout << "   ";
    }
    cout << raiz->inf << endl;
    view(raiz->izq, n + 1);
  }
}
