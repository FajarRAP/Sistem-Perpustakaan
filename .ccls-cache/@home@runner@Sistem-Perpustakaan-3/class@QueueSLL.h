#ifndef __QueueSLL
#define __QueueSLL
#include "node.hpp"

template <typename T> 
class QueueSLL 
{
public:
  // constructor
  QueueSLL();
  // destructor
  ~QueueSLL();
  // enqueue elemen
  QueueSLL<T> &enqueue(const T &);
  // dequeue elemen
  QueueSLL<T> &dequeue();
  // ambil kepala
  T getFront();
  // ambil belakang
  T getRear();
  // cek antrian kosong
  bool isEmpty();
  // cetak antrian
  void display();

private:
  Node<T> *kepala;
  Node<T> *ekor;
};

template <typename T> 
QueueSLL<T>::QueueSLL() 
{
  this->kepala = 0;
  this->ekor = 0;
}

template <typename T> 
QueueSLL<T>::~QueueSLL() 
{
  Node<T> *jalan = this->kepala;
  Node<T> *hapus;
  while (jalan) 
  {
    hapus = jalan;
    jalan = jalan->berikut;
    delete hapus;
  }
}

template <typename T> 
QueueSLL<T> &QueueSLL<T>::enqueue(const T &data) 
{
  if (isEmpty()) 
  {
    this->kepala = new Node<T>();
    this->kepala->data = data;
    this->kepala->berikut = 0;
    this->ekor = this->kepala;
    return *this;
  }
  Node<T> *tambah = new Node<T>();
  tambah->data = data;
  tambah->berikut = 0;
  this->ekor->berikut = tambah;
  this->ekor = tambah;
  return *this;
}

template <typename T> 
QueueSLL<T> &QueueSLL<T>::dequeue() 
{
  if(!isEmpty())
  {
    Node<T> *hapus = this->kepala;
    this->kepala = this->kepala->berikut;
    delete hapus;
    return *this;
  }
}

template <typename T> 
T QueueSLL<T>::getFront() 
{ 
  return this->kepala->data; 
}

template <typename T> 
T QueueSLL<T>::getRear() 
{ 
  return this->ekor->data; 
}

template <typename T> 
bool QueueSLL<T>::isEmpty() 
{
  if (this->kepala == 0) 
  {
    return true;
  } 
  else 
  {
    return false;
  }
}

template <typename T> 
void QueueSLL<T>::display() 
{
  if (!isEmpty()) 
  {
    Node<T> *jalan = this->kepala;
    while (jalan) 
    {
      std::cout << jalan->data << " ";
      jalan = jalan->berikut;
    }
    return;
  }
  std::cout << "Antrian Kosong" << std::endl;
}

#endif