//Author: Katy Bohanan
//Program 3
//CS303
//April 2023

#include <iostream>
#include "queue.h"
#include "infixtopostfix.h"

int main() {

  std::string infix;
  std::cout << "Enter an infix expression: ";
  getline(std::cin, infix);

  std::string postfix = infixToPostfix(infix);

  std::cout << "\nPostfix expression: " << postfix << std::endl;
  

Queue<int>* Q = new Queue<int>;
Q->enqueue(1);
Q->enqueue(2);
Q->enqueue(3);
Q->enqueue(4);
Q->enqueue(5);

std::cout << "\nFront element: " << Q->peek() << std::endl;

std::cout << "Dequeue: " << Q->dequeue() << std::endl;
std::cout << "Dequeue: " << Q->dequeue() << std::endl;

std::cout << "\nIs queue empty? " << std::endl;
if (Q->is_empty() == false)
  std::cout << "No\n";
else
  std::cout << "Yes\n";

std::cout << "Total elements in queue: " << Q->get_size() << std::endl;
  
}