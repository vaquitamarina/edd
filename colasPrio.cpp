#include <bits/stdc++.h>
using namespace std;

#define MAX 10
#define LVL 5

class ColaPrioritaria{
  private:
    string matriz[LVL][MAX];
    int frente[LVL];
    int final[LVL];
  public:
    ColaPrioritaria();
    void insertar(string dato, int prio){
      if(frente[prio] == (final[prio] + 1) % MAX){
        cout<<"Cola llena"<<endl;
      } else{
        if(frente[prio] == -1){
          frente[prio] = 0;
          final[prio] = 0;
        } else{
          final[prio] = (final[prio] + 1) % MAX;
        }
        matriz[prio][final[prio]] = dato;
      }
    }
    string pop(){
      for(int i = 0; i < LVL; i++){
        if(frente[i] != -1){
          string aux = matriz[i][frente[i]];
          if(frente[i] == final[i]){
            frente[i] = -1;
            final[i] = -1;
          } else{
            frente[i] = (frente[i] + 1) % MAX;
          }
          return aux;
        }    
      }
      cout<<"Cola vacia"<<endl;
      return "";
    }
}

int main (int argc, char *argv[]) {
  Colaprioritaria cola;
  cola.insertar("A", 0);
  cola.insertar("B", 1);
  return 0;
}
