#ifndef __QueueCDLL
#define __QueueCDLL
#include "node.hpp"

template <typename T>
class QueueCDLL 
{
public:
  // constructor
  QueueCDLL();
  // destructor
  ~QueueCDLL();
  // enqueue elemen
  QueueCDLL<T> &enqueue(const T &);
  // dequeue elemen
  QueueCDLL<T> &dequeue();
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
QueueCDLL<T>::QueueCDLL() 
{
  this->kepala = 0;
  this->ekor = 0;
}

template <typename T>
QueueCDLL<T>::~QueueCDLL() 
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
QueueCDLL<T> &QueueCDLL<T>::enqueue(const T &data) 
{
  if (isEmpty()) 
  {
    this->kepala = new Node<T>();
    this->kepala->data = data;
    this->kepala->berikut = this->kepala;
    this->kepala->sebelum = this->kepala;
    this->ekor = this->kepala;
    return *this;
  }
  Node<T> *tambah = new Node<T>();
  tambah->data = data;
  tambah->berikut = this->kepala;
  tambah->sebelum = this->ekor;
  this->ekor->berikut = tambah;
  this->ekor = tambah;
  return *this;
}

template <typename T>
QueueCDLL<T> &QueueCDLL<T>::dequeue() 
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
    this->kepala->sebelum = this->ekor;
    this->ekor->berikut = this->kepala;
    return *this;
  }
  return *this;
}

template <typename T>
T QueueCDLL<T>::getFront() 
{ 
  return this->kepala->data; 
}

template <typename T>
T QueueCDLL<T>::getRear() 
{ 
  return this->ekor->data; 
}

template <typename T>
bool QueueCDLL<T>::isEmpty() 
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
void QueueCDLL<T>::display() 
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