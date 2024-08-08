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
int altura(nodo *, int);
int contar(nodo *);

int main(int argc, char *argv[]) {
  nodo *raiz = NULL;
  insert(raiz, 10);
  insert(raiz, 5);
  insert(raiz, 20);
  insert(raiz, 10);
  view(raiz, 0);
  cout << altura(raiz, 0) << endl;
  cout << contar(raiz) << endl;
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
      if(x > raiz->inf) {
        insert(raiz->der, x);
      } else {
        cout << "El dato ya existe" << endl;
      }
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
        nodo *aux = p->izq;
        nodo *aux1;
        int cen = 0;
        while(aux->der != NULL){
          aux1 = aux;
          aux = aux->der;
          cen = 1;
        }
        raiz->inf = aux->inf;
        p = aux;
        if (cen == 0) {
          raiz->izq = aux->izq;
        } else {
          aux1->der = aux->izq;
        }
      }
      delete p;
    }
  }
}

int altura(nodo *raiz, int cont){
  if(raiz != NULL){
    int a = altura(raiz->izq, cont + 1);
    int b = altura(raiz->der, cont + 1);
    if(a > b){
      return a;
    } else{
      return b;
    }
  }
  return cont;
}


int contar(nodo *raiz){
  if(raiz != NULL){
    return 1 + contar(raiz->izq) + contar(raiz->der);
  } else{
    return 0;
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
