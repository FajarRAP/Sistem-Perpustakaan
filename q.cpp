// #include <iostream>
// #include <fstream>
// #include "157.h"
// #include "165.h"

// void garis(int x) {
//   if (x != 0) {
//     std::cout << "=";
//     garis(x - 1);
//   } else {
//     std::cout << std::endl;
//   }
// }

// int main() {
//   system("clear");
//   std::vector<bukuTemp> invoice;
//   std::fstream data;
//   bukuTemp bufferBuku;
//   Dimas _157;
//   data.open("user/32070_keranjang.txt", std::ios::in);
//   while (std::getline(data, bufferBuku.judul, ';') &&
//          std::getline(data, bufferBuku.penulis, ';') &&
//          data >> bufferBuku.tahunTerbit >> bufferBuku.stok) {
//     invoice.push_back(bufferBuku);
//   }
//   data.close();
//   _157.invoice2(12, 12, 2022, "Fajar Riansyah", "Dusun Singandaru", "Ciamis",
//                 invoice);
// }