#ifndef __pqueue
#define __pqueue
#include "node.hpp"

//tipe data abstrak priority queue
template <typename T> 
class PriorityQueue {
public:
  //constructor
  PriorityQueue() { this->kepala = this->ekor = 0; }
  //enqueue elemen
  PriorityQueue<T> &enqueue(const T &data, int prioritas) {
    if (isEmpty()) {
      this->kepala = new Node<T>();
      this->kepala->data = data;
      this->kepala->prioritas = prioritas;
      this->kepala->berikut = 0;
      this->kepala->sebelum = 0;
      this->ekor = this->kepala;
      return *this;
    }
    Node<T> *tambah = new Node<T>();
    tambah->data = data;
    tambah->prioritas = prioritas;
    if (tambah->prioritas > this->kepala->prioritas) {
      tambah->berikut = this->kepala;
      tambah->sebelum = 0;
      this->kepala->sebelum = tambah;
      this->kepala = tambah;
      return *this;
    } else {
      Node<T> *jalan = this->kepala;
      Node<T> *jalan2;
      while (jalan->berikut != 0) {
        if (tambah->prioritas > jalan->berikut->prioritas) {
          break;
        }
        jalan = jalan->berikut;
      }
      if (jalan != this->ekor) {
        jalan2 = jalan->berikut;
        jalan->berikut = tambah;
        tambah->berikut = jalan2;
        tambah->sebelum = jalan;
        jalan2->sebelum = tambah;
        return *this;
      } else {
        jalan->berikut = tambah;
        tambah->berikut = 0;
        tambah->sebelum = jalan;
        this->ekor = tambah;
        return *this;
      }
    }
  }
  //dequeue elemen
  PriorityQueue<T> &dequeue() {
    if (!isEmpty()) {
      Node<T> *hapus = this->kepala;
      this->kepala = this->kepala->berikut;
      this->kepala->sebelum = 0;
      delete hapus;
      return *this;
    }
    return *this;
  }
  //cek priority queue kosong
  bool isEmpty() { return this->kepala == 0; }
  //cetak priority queue
  void display() {
    Node<T> *jalan = this->kepala;
    while (jalan != 0) {
      std::cout << jalan->data << std::endl;
      jalan = jalan->berikut;
    }
  }
  //ambil data depan
  T getFront() { return kepala->data; }
  //ambil data belakang
  T getRear() { return ekor->data; }

private:
  Node<T> *kepala;
  Node<T> *ekor;
};

#endif