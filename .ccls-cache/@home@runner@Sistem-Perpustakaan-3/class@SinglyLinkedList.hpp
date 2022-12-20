#ifndef __sllNew
#define __sllNew

#include "node.hpp"

//Tipe Data Abstrak Singly Linked List
template <typename T>
class SinglyLinkedList
{
public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  SinglyLinkedList<T> &tambahDepan(T data);
  SinglyLinkedList<T> &tambahBelakang(T data);
  SinglyLinkedList<T> &hapusDepan();
  SinglyLinkedList<T> &hapusBelakang();
  SinglyLinkedList<T> &clearList();
  void display();
  bool isKosong();
  
private:
  Node<T> *kepala;
  Node<T> *ekor;
};

#endif