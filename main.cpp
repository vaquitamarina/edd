#include <bits/stdc++.h>

using namespace std;

class CircularQueue {
private:
  int *items;
  int front;
  int rear;
  int size;

public:
  CircularQueue(int s) {
    items = new int[s];
    front = -1;
    rear = -1;
    size = s;
  }

  bool isFull() {
    if (front == 0 && rear == size - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
      return false;
  }

  bool isEmpty() {
    if (front == -1) return true;
      else return false;
  }

  void push(int element) {
    if (isFull()) {
      cout<<"Cola llena"<<endl;
    } else {
      if (front == -1) front = 0;
        rear = (rear + 1) % size;
        items[rear] = element;
      }
  }

  int pop() {
    int element;
    if (isEmpty()) {
      cout<<"Cola vacia"<<endl;
    } else {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      } 
      else {
        front = (front + 1) % size;
      }
      return (element);
    }
  }
};

class PriorityQueue {
private:
  CircularQueue **array;
  int size;
  int lvl;
public:
  PriorityQueue(int s, int l) {
    size = s;
    lvl = l;
    array = new CircularQueue*[lvl];
    for (int i = 0; i < lvl; i++) {
      array[i] = new CircularQueue(size);
    }
  }
  void push(int element, int lvl){
    array[lvl]->push(element);
  }
  int pop(){
    for (int i = 0; i < lvl; i++) {
      if (!array[i]->isEmpty()) {
      return array[i]->pop();
      }
    }
    return -1;
  }
};


int main (int argc, char *argv[]) {
  PriorityQueue pq(10,3);
  pq.push(1,2);
  pq.push(2,1);
  cout<<pq.pop()<<endl;
  return 0;
}
