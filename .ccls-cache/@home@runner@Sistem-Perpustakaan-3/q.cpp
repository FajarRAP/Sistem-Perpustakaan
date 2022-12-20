#include "165.h"
#include "behaviour.hpp"
#include "class/SinglyLinkedList.hpp"
#include "class/buku.hpp"
#include "fort.hpp"
#include "fortb.h"
#include <fstream>
#include <iostream>
#include <vector>

void garis(int x) {
  if (x != 0) {
    std::cout << "=";
    garis(x - 1);
  } else {
    std::cout << std::endl;
  }
}

int main() {
  system("clear");
  garis(37);
  std::cout << "|>>        Menu Transaksi         <<|";
  std::cout << std::endl;
  garis(37);
  std::cout << std::endl;
  fort::char_table table;
  // table << fort::header << "   !!! Konfirmasi Identitas !!!   ";
  // table << fort::endr;
  table << fort::header << "    !!! Transaksi Berhasil !!!    " << fort::endr;
  std::cout << table.to_string() << std::endl;
}