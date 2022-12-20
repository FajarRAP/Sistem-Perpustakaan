#ifndef __dllNew
#define __dllNew

#include "node.hpp"

//Tipe Data Abstrak Doubly Linked List
template <typename T>
class DoublyLinkedList
{
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  DoublyLinkedList &tambahDepan(const T &);
  DoublyLinkedList &tambahBelakang(const T &);
  DoublyLinkedList &hapusDepan();
  DoublyLinkedList &hapusBelakang();
  DoublyLinkedList &clearList();
  void cetakMaju();
  void cetakMundur();
  bool isKosong();

private:
  Node<T> *kepala;
  Node<T> *ekor;
};

#endif