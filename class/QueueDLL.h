#ifndef __QueueDLL
#define __QueueDLL
#include "node.hpp"
#include "fort.hpp"

template <typename T>
class QueueDLL 
{
public:
  // constructor
  QueueDLL();
  // destructor
  ~QueueDLL();
  // enqueue elemen
  QueueDLL<T> &enqueue(const T &);
  // dequeue elemen
  QueueDLL<T> &dequeue();
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
QueueDLL<T>::QueueDLL() 
{
  this->kepala = 0;
  this->ekor = 0;
}

template <typename T>
QueueDLL<T>::~QueueDLL() 
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
QueueDLL<T> &QueueDLL<T>::enqueue(const T &data) 
{
  if (isEmpty()) 
  {
    this->kepala = new Node<T>();
    this->kepala->data = data;
    this->kepala->berikut = 0;
    this->kepala->sebelum = 0;
    this->ekor = this->kepala;
    return *this;
  }
  Node<T> *tambah = new Node<T>();
  tambah->data = data;
  tambah->berikut = 0;
  tambah->sebelum = this->ekor;
  this->ekor->berikut = tambah;
  this->ekor = tambah;
  return *this;
}

template <typename T>
QueueDLL<T> &QueueDLL<T>::dequeue() 
{
  if(!isEmpty())
  {
    Node<T> *hapus = this->kepala;
    this->kepala = this->kepala->berikut;
    delete hapus;
    return *this;
  }
  return *this;
}

template <typename T>
T QueueDLL<T>::getFront() 
{ 
  return this->kepala->data; 
}

template <typename T>
T QueueDLL<T>::getRear() 
{ 
  return this->ekor->data; 
}

template <typename T>
bool QueueDLL<T>::isEmpty() 
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
void QueueDLL<T>::display() 
{
  if (!isEmpty()) 
  {
    fort::char_table table;
    table << "No Antrian" << "ID User" << fort::endr;
    table << fort::separator;
    Node<T> *jalan = this->kepala;
    while (jalan) 
    {
      table << jalan->data.noAntrian << jalan->data.id << fort::endr;
      jalan = jalan->berikut;
    }
    table.set_border_style(FT_NICE_STYLE);
    table.column(0).set_cell_text_align(fort::text_align::center);
    std::cout << table.to_string() << std::endl;
    return;
  }
  std::cout << "Antrian Kosong" << std::endl;
}

#endif