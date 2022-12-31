#ifndef __dimas
#define __dimas
#include "165.h"
#include "class/fort.h"
#include "class/fort.hpp"
#include "class/fortb.h"
#include "class/random.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using Random = effolkronium::random_static;

class Dimas {
public:
  void invoice(std::string nama, std::string alamat, std::string kota,
               std::string tanggal, int noOrder, std::vector<bukuTemp> &Buku) {
    ofstream myfile;
    myfile.open("Text.txt", ios::app);
    if (!myfile.fail()) {
      myfile << "INVOICE" << endl;
      myfile << "\t\t\t\t\t\t\t\t\t\t\t\tPERPUSTAKAAN" << endl;
      myfile << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                "\tTanggal   : "
             << tanggal << endl;
      myfile << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                "\tNo. Order : "
             << noOrder << endl;
      myfile << endl;
      myfile << endl;
      myfile << "Nama     : " << nama << endl;
      myfile << "Alamat   : " << alamat << endl;
      myfile << "Kota     : " << kota << endl;
      myfile << "=============================================================="
                "=============================================================="
             << endl;
      myfile << "|No"
             << "\t\t|  Deskripsi"
             << "\t\t|  Kuantitas"
             << "\t\t|  Tanggal Pinjam"
             << "\t\t|  Tanggal Harus Kembali" << endl;
      myfile << "=============================================================="
                "=============================================================="
             << endl;
      std::cout << Buku.size() << std::endl;
      for (int a = 0; a < Buku.size(); a++) {
        myfile << a + 1 << ". ";
        myfile << Buku.at(a).judul << " ";
        myfile << tanggal << " ";
        myfile << std::endl;
      }
      myfile << "*jika melewati batas/buku rusak, maka peminjam akan dikenakan "
                "denda!! "
             << endl;
      myfile.close();
    } else {
      cout << "file tidak ditemukan" << endl;
    }
  }
  void invoice2(int tgl, int bulan, int tahun, const std::string &nama,
                const std::string &alamat, const std::string &kota,
                std::vector<bukuTemp> &y) {
    std::string x = to_string(tgl) + to_string(bulan) + to_string(tahun);
    std::string kata[8];
    kata[0] = "Tanggal Order   : " + x;
    kata[1] = "No Invoice      : " + x + "/" + to_string(Random::get(1, 1000));
    kata[2] = "Nama   : " + nama;
    kata[3] = "Alamat : " + alamat;
    kata[4] = "Kota   : " + kota;
    kata[5] =
        to_string(tgl) + " - " + to_string(bulan) + " - " + to_string(tahun);
    kata[6] = to_string(tgl + 3) + " - " + to_string(bulan) + " - " +
              to_string(tahun);
    std::fstream data;
    fort::char_table table;
    fort::char_table table2;
    table.set_border_style(FT_NICE_STYLE);

    table << "Invoice" << fort::endr;
    table << "Perpustakaan Empud" << fort::endr;
    table << fort::separator;
    table << kata[0] << fort::endr;
    table << kata[1] << fort::endr;
    table << fort::separator;
    table << kata[2] << fort::endr;
    table << kata[3] << fort::endr;
    table << kata[4] << fort::endr;
    table << fort::separator;
    table << "No"
          << "Judul Buku"
          << "Tanggal Pinjam"
          << "Tanggal Kembali" << fort::endr;
    table << fort::separator;
    for (int a = 0; a < y.size(); a++) {
      table << a + 1 << y.at(a).judul << kata[5] << kata[6] << fort::endr;
    }
    table << fort::separator;
    table << "*jika melewati batas/buku rusak, maka peminjam akan dikenakan denda!!" << fort::endr;
    table[0][0].set_cell_min_width(50);
    table.row(0).set_cell_text_align(fort::text_align::center);
    table.row(1).set_cell_text_align(fort::text_align::center);
    table[2][0].set_cell_left_padding(43);
    table[3][0].set_cell_left_padding(43);
    table[0][0].set_cell_span(4);
    table[1][0].set_cell_span(4);
    table[2][0].set_cell_span(4);
    table[3][0].set_cell_span(4);
    table[4][0].set_cell_span(4);
    table[5][0].set_cell_span(4);
    table[6][0].set_cell_span(4);
    switch(y.size()){
      case 1:
        table[9][0].set_cell_span(4);
        break;
      case 2:
        table[10][0].set_cell_span(4);
        break;
      case 3:
        table[11][0].set_cell_span(4);
        break;
    }
    data.open("Invoice.txt", std::ios::out);
    data << table.to_string() << std::endl;
    data.close();
  }
};

#endif