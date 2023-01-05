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
    if (!isEmpty()) {
      fort::char_table table;
      table << "Antrian Prioritas" << fort::endr;
      table << fort::separator;
      table << "No Antrian" << "ID User" << fort::endr;
      table << fort::separator;
      Node<T> *jalan = this->kepala;
      while (jalan) {
        table << jalan->data.noAntrian << jalan->data.id << fort::endr;
        jalan = jalan->berikut;
      }
      table.set_border_style(FT_NICE_STYLE);
      table.column(0).set_cell_text_align(fort::text_align::center);
      table[0][0].set_cell_span(2);
      table.row(0).set_cell_text_align(fort::text_align::center);
      std::cout << table.to_string() << std::endl;
      return;
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