#include "165.h"
// #include "behaviour.hpp"
// #include "class/SinglyLinkedList.hpp"
// #include "class/buku.hpp"
// #include "class/fort.hpp"
// #include "class/fortb.h"
// #include <fstream>
#include "157.h"
#include <iostream>
#include <vector>
// #include <vector>

void garis(int x) {
  if (x != 0) {
    std::cout << "=";
    garis(x - 1);
  } else {
    std::cout << std::endl;
  }
}

int main() {
  // bersihkan layar
  system("clear");

  // variabel yang dibutuhkan
  std::vector<bukuTemp> keranjang;
  bukuTemp buffer;
  std::fstream data;
  int pilih;
  // isMenuUser = true;

  // header
  garis(37);
  std::cout << "|>>      Menu Hapus Buku Saya      <<|";
  std::cout << std::endl;
  garis(37);
  std::cout << std::endl;

  // baca database user yang login
  keranjang.clear();
  data.open("user/32070_keranjang.txt", std::ios::in);
  while (std::getline(data, buffer.judul, ';') &&
         std::getline(data, buffer.penulis, ';') &&
         data >> buffer.tahunTerbit >> buffer.stok) {
    keranjang.push_back(buffer);
  }
  if (!data.is_open() || keranjang.size() == 0) {
    std::cout << "!!! Keranjang kosong !!!" << std::endl;
    exit(1);
  }
  data.close();

  while (true) {
    if(keranjang.size() == 0){
      std::cout<<"Abis"<<std::endl;
      break;
    }
    for (auto &x : keranjang) {
      std::cout << x.judul << std::endl;
    }
    std::cin >> pilih;
    std::cout << keranjang.at(pilih - 1).judul;
    std::cout << " Berhasil dihapus dari keranjang" << std::endl;
    keranjang.erase(keranjang.begin() + pilih - 1);

  }
}