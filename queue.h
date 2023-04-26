#pragma once
#include <list>
#include <iostream>

template <typename item_type>
struct Node {
  item_type data;
  Node* next;
};

template <typename item_type>
class Queue {
private:
  Node<item_type>* front;
  Node<item_type>* rear;
  int size;
public:
  Queue(); //creates empty queue
  void enqueue (item_type item); //inserts new element at end of queue
  item_type dequeue(); //removes item from front of queue and returns it
  item_type peek(); //returns the item at the front of the queue
  bool is_empty(); //checks is queue is empty
  int get_size();
};

template <typename item_type>
Queue<item_type>::Queue(){
  front = nullptr;
  rear = nullptr;
  size = 0;
}

template <typename item_type>
void Queue<item_type>::enqueue(item_type item){
  Node<item_type>* temp = new Node<item_type>;
  temp->data = item;
  temp->next = nullptr;
  if (is_empty()) {
    front = rear = temp;
  } 
  else {
    rear->next = temp;
    rear = temp;
  }
  size++;
} 

template <typename item_type>
item_type Queue<item_type>::dequeue(){
  if (is_empty()) {
    std::cout << "Queue is empty\n";
    return -1;
  }
  else {
    Node<item_type>* temp = front;
    item_type item = temp->data;
    front = front->next;
    delete temp;
    size--;
    return item;
  }
}

template <typename item_type>
item_type Queue<item_type>::peek(){
  if (is_empty()) {
    std::cout << "Queue is empty\n";
    return -1;
  }
  else
    return front->data;
}


template <typename item_type>
bool Queue<item_type>::is_empty(){
    return (front == nullptr);
}

template <typename item_type>
int Queue<item_type>::get_size(){
  return size;
}