#include <bits/stdc++.h>
#define MAX 10
#define LVL 5

using namespace std;

class ColaPrioritaria{
  private:
    string matriz[LVL][MAX];
    int frente[LVL];
    int final[LVL];
  public:    
    ColaPrioritaria(){
      for(int i = 0; i < LVL; i++){
        frente[i] = -1;
        final[i] = -1;
      }
    }
    void push(string dato, int prio){
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
};

int main (int argc, char *argv[]) {
  ColaPrioritaria cola;
  cola.push("A", 3);
  cola.push("b", 0);
  cout<<cola.pop()<<endl;
  cout<<cola.pop()<<endl;
  return 0;
}


