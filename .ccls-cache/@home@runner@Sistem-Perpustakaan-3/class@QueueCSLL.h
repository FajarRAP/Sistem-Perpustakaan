#ifndef __QueueCSLL
#define __QueueCSLL
#include "node.hpp"

template <typename T>
class QueueCSLL 
{
public:
  // constructor
  QueueCSLL();
  // destructor
  ~QueueCSLL();
  // enqueue elemen
  QueueCSLL<T> &enqueue(const T &);
  // dequeue elemen
  QueueCSLL<T> &dequeue();
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
QueueCSLL<T>::QueueCSLL() 
{
  this->kepala = 0;
  this->ekor = 0;
}

template <typename T>
QueueCSLL<T>::~QueueCSLL() 
{
  Node<T> *jalan = this->kepala;
  Node<T> *hapus;
  while (jalan != this->kepala) 
  {
    hapus = jalan;
    jalan = jalan->berikut;
    delete hapus;
  }
  this->kepala = 0;
  this->ekor = 0;
}

template <typename T>
QueueCSLL<T> &QueueCSLL<T>::enqueue(const T &data) 
{
  if (isEmpty()) 
  {
    this->kepala = new Node<T>();
    this->kepala->data = data;
    this->kepala->berikut = this->kepala;
    this->ekor = this->kepala;
    return *this;
  }
  Node<T> *tambah = new Node<T>();
  tambah->data = data;
  tambah->berikut = this->kepala;
  this->ekor->berikut = tambah;
  this->ekor = tambah;
  return *this;
}

template <typename T>
QueueCSLL<T> &QueueCSLL<T>::dequeue() 
{
  if (!isEmpty()) 
  {
    Node<T> *hapus = this->kepala;
    if (hapus->berikut == this->kepala) 
    {
      this->kepala = 0;
      this->ekor = 0;
      return *this;
    }
    this->kepala = this->kepala->berikut;
    delete hapus;
    this->ekor->berikut = this->kepala;
    return *this;
  }
  return *this;
}

template <typename T>
T QueueCSLL<T>::getFront() 
{ 
  return this->kepala->data; }

template <typename T>
T QueueCSLL<T>::getRear() 
{ 
  return this->ekor->data; }

template <typename T>
bool QueueCSLL<T>::isEmpty() 
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
void QueueCSLL<T>::display() 
{
  if (!isEmpty()) 
  {
    Node<T> *jalan = this->kepala;
    do 
    {
      std::cout << jalan->data << " ";
      jalan = jalan->berikut;
    } while (jalan != this->kepala);
    return;
  }
  std::cout << "Antrian Kosong" << std::endl;
}

#endif