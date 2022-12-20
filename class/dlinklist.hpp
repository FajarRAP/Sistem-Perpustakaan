#ifndef __dll
#define __dll
#include <iostream>
#include "node.hpp"
#include "buku.hpp"

Node<Buku> *head;
Node<Buku> *tail;
Node<Buku> *jalan;
Node<Buku> *temp;
Node<Buku> *hapus;

template <typename T>
class OldDoublyLinkedList
{
  public:
    void add(T data)
    {
      Node<T> *temp = new Node<T>();
        if(head == 0)
        {
            head = new Node<T>();
            head = calo(data);
            tail = head;
            return;
        }
        temp = calo(data);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    void remove()
    {
      hapus = tail;
      tail = tail->prev;
      tail->next = 0;
      hapus->prev = 0;
      delete hapus;
    }

    void clearList()
    {
      for(jalan = head; jalan != 0;)
      {
        hapus = jalan;
        jalan = jalan->next;
        delete hapus;
      }
      head = 0;
      tail = 0;
    }

    void cetakMaju()
    {
      int a = 0;
      for(jalan = head; jalan != 0; jalan = jalan->next)
      {
        if(a+1 < 10)
        {
          std::cout<<std::left<<a + 1<<std::setw(4)<<".";
        }else if(a+1 >= 10 && a+1 < 100)
        {      
          std::cout<<std::left<<a + 1<<std::setw(3)<<".";
        }
        std::cout<<jalan->data<<std::endl;
        a++;
      }
    }

    void cetakMundur()
    {
      int a = 1;
      for(jalan = tail; jalan != 0; jalan = jalan->prev)
      {
        std::cout<<a<<"."<<jalan->data<<std::endl;
        a++;
      }
    }

    int getLen()
    {
        int n = 0;
        for(jalan = head; jalan != 0; jalan = jalan->next)
        {
            n++;
        }
        return n;
    }
  private:
  
  Node<T> *calo(T &data)
  {
    Node<T> *temp = new Node<T>();
    temp->data = data;
    temp->next = 0;
    temp->prev = 0;
    return temp;
  }

};
#endif