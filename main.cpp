#include "behaviour.hpp"
#include "class/DoublyLinkedList.hpp"
#include "class/SinglyLinkedList.hpp"
#include "class/StackArrayDinamis.hpp"
#include "class/QueueDLL.h"
#include "class/admin.hpp"
#include "class/array1d.hpp"
#include "class/buku.hpp"
#include "class/database.hpp"
#include "class/ktp.hpp"
#include "class/random.hpp"
#include "class/sistem.hpp"
#include "class/user.hpp"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using Random = effolkronium::random_static;

// Pertemuan 1 : Rekursi
void garis(int);
void garis2(int);
#include "165.h"
#include "157.h"
#include "152.h"

int main() {
  // Pertemuan 3 : Array Dinamis
  std::vector<Buku> tempBuku;
  Array1D<Buku> arrBuku(0);
  StackArrayDinamis<Buku> stackBuku(3);
  Sena _152;
  Dimas _157;
  Fajar _165;
  char menuUtama;
  // Pertemuan 2 : Array Statis
  int angka[5];
  bool isMenuUtama;
  bool isMenuAdmin = true;
  bool isMenuUser = true;
  char isPause;
  time_t now = time(0);
  tm *waktuSekarang = localtime(&now);

  // if(false){
  do {
    // Menu Utama
    isMenuAdmin = true;
    isMenuUser = true;
    system("clear");
    garis(37);
    std::cout << "|>> Perpustakaan Empud Solehudin  <<|" << std::endl;
    garis(37);
    std::cout << "|>> 1. Masuk                      <<|" << std::endl;
    garis2(37);
    std::cout << "|>> 2. Daftar                     <<|" << std::endl;
    garis2(37);
    std::cout << "|>> 3. Input KTP                  <<|" << std::endl;
    garis2(37);
    std::cout << "|>> 4. Ke luar                    <<|" << std::endl;
    garis(37);
    std::cout << "Pilih : ";

    std::cin >> menuUtama;
    system("clear");

    switch (menuUtama) {
    // Login ke sistem
    case '1': {
      // variabel yang dibutuhkan
      isMenuUtama = true;
      char tipeUser;
      std::string id;
      std::string password;

      garis(37);
      std::cout << "|>> \t\tTipe Pengguna :       <<|" << std::endl;
      garis(37);
      std::cout << "|>>   1. Admin                    <<|" << std::endl;
      garis2(37);
      std::cout << "|>>   2. Pengguna                 <<|" << std::endl;
      garis(37);
      std::cout << "Pilih : ";

      std::cin >> tipeUser;

      switch (tipeUser) {
      // Login sebagai admin
      case '1': {
        // variabel yang dibutuhkan
        std::fstream data;
        std::string bufferPassword;
        bool isLogin;

        std::cout << "ID       : ";
        std::cin >> id;
        std::cout << "Password : ";
        std::cin >> password;

        // baca database admin
        data.open("admin/" + id + ".txt", std::ios::in);
        std::getline(data, bufferPassword);
        if (data.is_open()) {
          isLogin = true;
        }
        data.close();

        // Cek apakah username (NIK) dan password (Register) sesuai
        if (isLogin == true && password == bufferPassword) {
          // variabel yang dibutuhkan
          short menuAdmin;
          Database database;
          Buku data;
          std::string judul;
          std::string penulis;
          int tahunTerbit;
          short stok;

          while (isMenuAdmin) {
            // Menu Admin
            system("clear");
            garis(37);
            std::cout << "|>>\t\t Masuk sebagai Admin      <<|" << std::endl;
            garis(37);
            std::cout << "|>>   1. Tambah Buku              <<|" << std::endl;
            garis2(37);
            std::cout << "|>>   2. Hapus Buku               <<|" << std::endl;
            garis2(37);
            std::cout << "|>>   3. Perbarui Buku            <<|" << std::endl;
            garis2(37);
            std::cout << "|>>   4. Lihat list buku          <<|" << std::endl;
            garis2(37);
            std::cout << "|>>   5. Cari Buku                <<|" << std::endl;
            garis2(37);
            std::cout << "|>>   6. Sortir Buku              <<|" << std::endl;
            garis2(37);
            std::cout << "|>>   7. Lihat Daftar Admin       <<|" << std::endl;
            garis2(37);
            std::cout << "|>>   8. Lihat Daftar User        <<|" << std::endl;
            garis2(37);
            std::cout << "|>>   9. Konfirmasi Transaksi     <<|" << std::endl;
            garis2(37);
            std::cout << "|>>  10. Ke luar                  <<|" << std::endl;
            garis(37);
            std::cout << "Pilih : ";

            std::cin >> menuAdmin;

            switch (menuAdmin) {
              // Pilih tambah buku
              case 1: {
                //bersihkan layar
                system("clear");
                
                // variabel yang dibutuhkan
                short jumlahTambahBuku;
                isMenuAdmin = true;
  
                garis(37);
                std::cout << "|>>       Menu Tambah Buku        <<|";
                std::cout << std::endl;
                garis(37);
  
                std::cout << "Tambah berapa buku? ";
                std::cin >> jumlahTambahBuku;
                std::cout << std::endl;
  
                for (int a = 0; a < jumlahTambahBuku; a++) {
                  // input user buku baru
                  std::cin.ignore();
                  std::cout << "Judul        : ";
                  std::getline(std::cin, judul);
                  std::cout << "Penulis      : ";
                  std::getline(std::cin, penulis);
                  std::cout << "Tahun Terbit : ";
                  std::cin >> tahunTerbit;
                  std::cout << "Stok         : ";
                  std::cin >> stok;
  
                  // isi data buku ke class buku
                  data.setJudul(judul.c_str());
                  data.setPenulis(penulis.c_str());
                  data.setTahunTerbit(tahunTerbit);
                  data.setStok(stok);
  
                  // tulis ke database buku.txt
                  database.tambahBuku(data.getJudul().c_str(),
                                      data.getPenulis().c_str(),
                                      data.getTahunTerbit(), data.getStok());
  
                  // temporary ke vector
                  tempBuku.push_back(data);
                }
  
                // resize array, samakan dengan ukuran vector
                arrBuku.resize(tempBuku.size());
  
                // isi nilai array dengan banyaknya vector
                for (int a = 0; a < arrBuku.getUkuran(); a++) {
                  arrBuku[a].setJudul(tempBuku[a].getJudul().c_str());
                  arrBuku[a].setPenulis(tempBuku[a].getPenulis().c_str());
                  arrBuku[a].setTahunTerbit(tempBuku[a].getTahunTerbit());
                  arrBuku[a].setStok(tempBuku[a].getStok());
                }
  
                // pesan
                std::cout << "Buku Berhasil ditambah" << std::endl;
                std::cout << std::endl;
  
                // hold a second
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }
  
              // Pilih hapus buku
              case 2: {
                //bersihkan layar
                system("clear");
                
                // variabel yang dibutuhkan
                short posisi;
                std::fstream data;
                std::vector<bukuTemp> hapusBuku;
                bukuTemp buffer;
                isMenuAdmin = true;
  
                garis(37);
                std::cout << "|>>       Menu Hapus Buku         <<|";
                std::cout << std::endl;
                garis(37);
  
                // input user posisi
                std::cout << "Posisi ke : ";
                std::cin >> posisi;
                std::cout << std::endl;
  
                // baca database dari buku.txt
                data.open("Buku.txt");
                while (std::getline(data, buffer.judul, ';') &&
                       std::getline(data, buffer.penulis, ';') &&
                       data >> buffer.tahunTerbit >> buffer.stok) {
                  hapusBuku.push_back(buffer);
                }
                data.close();
  
                // cek kondisi jika user memasukkan nilai yang invalid
                if (posisi - 1 < 0 || posisi - 1 > hapusBuku.size() - 1) {
                  std::cout << "Gagal dihapus karena di luar kendali"
                            << std::endl;
                  exit(1);
                }
  
                // hapus buku
                hapusBuku.erase(hapusBuku.begin() + posisi - 1);
  
                // resize array, samakan dengan ukuran vector
                arrBuku.resize(hapusBuku.size());
  
                // isi nilai array dengan banyaknya vector
                for (int a = 0; a < arrBuku.getUkuran(); a++) {
                  arrBuku[a].setJudul(hapusBuku.at(a).judul.c_str());
                  arrBuku[a].setPenulis(hapusBuku.at(a).penulis.c_str());
                  arrBuku[a].setTahunTerbit(hapusBuku.at(a).tahunTerbit);
                  arrBuku[a].setStok(hapusBuku.at(a).stok);
                }
  
                // tulis hasil hapus
                data.open("Buku.txt", std::ios::out);
                for (int a = 0; a < hapusBuku.size(); a++) {
                  data << hapusBuku.at(a).judul;
                  data << ";" << hapusBuku.at(a).penulis;
                  data << ";" << hapusBuku.at(a).tahunTerbit;
                  data << " " << hapusBuku.at(a).stok;
                }
                data.close();
  
                // pesan
                std::cout << "Buku Berhasil Dihapus" << std::endl;
                std::cout << std::endl;
  
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }
  
              // pilih update buku
              case 3: {
                //bersihkan layar
                system("clear");
                
                // variabel yang dibutuhkan
                std::vector<bukuTemp> updateBuku;
                std::fstream data;
                std::ofstream tulisUpdatean;
                bukuTemp buffer;
                short noBuku;
                char pilihUpdate;
                bool isMenuUpdate;
                isMenuAdmin = true;
  
                garis(37);
                std::cout << "|>>       Menu Update Buku        <<|";
                std::cout << std::endl;
                garis(37);
  
                // Pilih buku yang akan diedit
                std::cout << "Update Buku No? ";
                std::cin >> noBuku;
                std::cout << std::endl;
  
                // baca database dari buku.txt
                data.open("Buku.txt");
                while (std::getline(data, buffer.judul, ';') &&
                       std::getline(data, buffer.penulis, ';') &&
                       data >> buffer.tahunTerbit >> buffer.stok) {
                  updateBuku.push_back(buffer);
                }
                data.close();
  
                // cek kondisi jika user memasukkan nilai yang invalid
                if (noBuku - 1 < 0 || noBuku - 1 > updateBuku.size() - 1) {
                  std::cout << "Gagal mengupdate buku karena di luar kendali"
                            << std::endl;
                  exit(1);
                }
  
                do {
                  // pilih atribut buku apa yang ingin diedit
                  garis2(37);
                  std::cout << "|>>         Update apa?           <<|";
                  std::cout << std::endl;
                  garis2(37);
                  std::cout << "|>>      1. Judul                 <<|";
                  std::cout << std::endl;
                  garis2(37);
                  std::cout << "|>>      2. Penulis               <<|";
                  std::cout << std::endl;
                  garis2(37);
                  std::cout << "|>>      3. Tahun Terbit          <<|";
                  std::cout << std::endl;
                  garis2(37);
                  std::cout << "|>>      4. Stok                  <<|";
                  std::cout << std::endl;
                  garis2(37);
  
                  std::cout << "Pilih : ";
                  std::cin >> pilihUpdate;
  
                  switch (pilihUpdate) {
                  // pilih judul
                  case '1': {
                    isMenuUpdate = true;
                    std::cin.ignore();
                    std::cout << "Judul baru : ";
                    std::getline(std::cin, buffer.judul);
                    updateBuku.at(noBuku - 1).judul = buffer.judul;
                    std::cout << "Update Berhasil" << std::endl;
                    break;
                  }
  
                  // pilih penulis
                  case '2': {
                    isMenuUpdate = true;
                    std::cin.ignore();
                    std::cout << "Penulis baru : ";
                    std::getline(std::cin, buffer.penulis);
                    updateBuku.at(noBuku - 1).penulis = buffer.penulis;
                    std::cout << "Update Berhasil" << std::endl;
                    break;
                  }
  
                  // pilih tahun terbit
                  case '3': {
                    isMenuUpdate = true;
                    std::cout << "Tahun terbit baru : ";
                    std::cin >> buffer.tahunTerbit;
                    updateBuku.at(noBuku - 1).tahunTerbit = buffer.tahunTerbit;
                    std::cout << "Update Berhasil" << std::endl;
                    break;
                  }
  
                  // pilih stok
                  case '4': {
                    isMenuUpdate = true;
                    std::cout << "Stok baru : ";
                    std::cin >> buffer.stok;
                    updateBuku.at(noBuku - 1).stok = buffer.stok;
                    std::cout << "Update Berhasil" << std::endl;
                    break;
                  }
  
                  default: {
                    isMenuUpdate = false;
                    std::cout << "Pilihan tidak tersedia" << std::endl;
                  }
                  }
                } while (isMenuUpdate == false);
  
                // tulis hasil edit
                tulisUpdatean.open("Buku.txt");
                for (int a = 0; a < updateBuku.size(); a++) {
                  tulisUpdatean << updateBuku.at(a).judul;
                  tulisUpdatean << ";" << updateBuku.at(a).penulis;
                  tulisUpdatean << ";" << updateBuku.at(a).tahunTerbit;
                  tulisUpdatean << " " << updateBuku.at(a).stok;
                }
                tulisUpdatean.close();
  
                std::cout << std::endl;
  
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }
  
              // pilih tampilkan buku
              case 4: {
                //bersihkan layar
                system("clear");
  
                // variabel yang dibutuhkan
                char pilihTampil;
                int ukuran;
                isMenuAdmin = true;
  
                garis(37);
                std::cout << "|>>        Menu Print Buku        <<|";
                std::cout << std::endl;
                garis(37);
  
                // input user pilih tampil data
                garis2(37);
                std::cout << "|>>    Ingin menampilkan dengan?  <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>> 1. Array1D Dinamis            <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>> 2. Single Linked List         <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>> 3. Double Linked List         <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "Pilih : ";
                std::cin >> pilihTampil;
                std::cout << std::endl;
  
                switch (pilihTampil) {
                // Pilih cetak Array1D
                case '1': {
                  std::fstream data;
                  std::vector<bukuTemp> bacaBuku;
                  bukuTemp buffer;
  
                  fort::char_table table;
                  table.set_border_style(FT_NICE_STYLE);
                  table << fort::header << "No";
                  table << "Judul Buku";
                  table << "Penulis Buku";
                  table << "Tahun Terbit";
                  table << "Stok Tersedia";
                  table << fort::endr;
  
                  // baca database buku
                  bacaBuku.clear();
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    bacaBuku.push_back(buffer);
                  }
                  data.close();
  
                  // resize ukuran array
                  arrBuku.resize(bacaBuku.size());
  
                  // isi array dari vector
                  for (int a = 0; a < arrBuku.getUkuran(); a++) {
                    arrBuku[a].setJudul(bacaBuku.at(a).judul.c_str());
                    arrBuku[a].setPenulis(bacaBuku.at(a).penulis.c_str());
                    arrBuku[a].setTahunTerbit(bacaBuku.at(a).tahunTerbit);
                    arrBuku[a].setStok(bacaBuku.at(a).stok);
                  }
  
                  // cetak value array
                  for (int a = 0; a < arrBuku.getUkuran(); a++) {
                    if (a + 1 < 10) {
                      table << a + 1;
                    } else if (a + 1 >= 10 && a + 1 < 100) {
                      table << a + 1;
                    }
                    table << arrBuku[a].getJudul();
                    table << arrBuku[a].getPenulis();
                    table << arrBuku[a].getTahunTerbit();
                    table << arrBuku[a].getStok();
                    table << fort::endr;
                  }
                  table.column(3).set_cell_text_align(fort::text_align::center);
                  table.column(4).set_cell_text_align(fort::text_align::center);
                  std::cout << table.to_string() << std::endl;
  
                  ukuran = bacaBuku.size();
                  break;
                }
  
                // Pilih cetak single linked list
                case '2': {
                  // variabel yang dibutuhkan
                  SinglyLinkedList<Buku> listBuku;
                  std::vector<bukuTemp> bacaBuku;
                  std::fstream data;
                  bukuTemp buffer;
                  Buku temp;
  
                  // hapus list jika ada
                  listBuku.clearList();
  
                  // baca database buku
                  bacaBuku.clear();
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    bacaBuku.push_back(buffer);
                  }
                  data.close();
  
                  // isi node
                  for (int a = 0; a < bacaBuku.size(); a++) {
                    temp.setJudul(bacaBuku.at(a).judul.c_str());
                    temp.setPenulis(bacaBuku.at(a).penulis.c_str());
                    temp.setTahunTerbit(bacaBuku.at(a).tahunTerbit);
                    temp.setStok(bacaBuku.at(a).stok);
                    listBuku.tambahDepan(temp);
                  }
  
                  // cetak Single Linked List
                  listBuku.display();
                  ukuran = bacaBuku.size();
                  break;
                }
  
                // pilih doubly linked list
                case '3': {
                  // variabel yang dibutuhkan
                  DoublyLinkedList<Buku> listBuku;
                  std::vector<bukuTemp> bacaBuku;
                  std::fstream data;
                  bukuTemp buffer;
                  Buku temp;
  
                  // hapus list jika ada
                  listBuku.clearList();
  
                  // baca database buku
                  bacaBuku.clear();
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    bacaBuku.push_back(buffer);
                  }
                  data.close();
  
                  // isi node
                  for (int a = 0; a < bacaBuku.size(); a++) {
                    temp.setJudul(bacaBuku.at(a).judul.c_str());
                    temp.setPenulis(bacaBuku.at(a).penulis.c_str());
                    temp.setTahunTerbit(bacaBuku.at(a).tahunTerbit);
                    temp.setStok(bacaBuku.at(a).stok);
                    listBuku.tambahBelakang(temp);
                  }
  
                  // cetak
                  listBuku.cetakMaju();
                  ukuran = bacaBuku.size();
                  break;
                }
  
                default: {
                  std::cout << "Pilihan tidak tersedia" << std::endl;
                }
                }
  
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }
  
              // pilih cari buku
              case 5: {
                //bersihkan layar
                system("clear");
  
                //variabel yang dibutuhkan
                std::string cari;
                std::vector<bukuTemp> bacaBuku;
                std::fstream data;
                bukuTemp buffer;
                isMenuAdmin = true;

                //baca database buku
                bacaBuku.clear();
                data.open("Buku.txt");
                while (std::getline(data, buffer.judul, ';') &&
                       std::getline(data, buffer.penulis, ';') &&
                       data >> buffer.tahunTerbit >> buffer.stok) {
                  bacaBuku.push_back(buffer);
                }
                data.close();
  
                // bikin tabel
                fort::char_table tableSearch;
                fort::char_table tableSearch2;
                tableSearch.set_border_style(FT_SOLID_ROUND_STYLE);
                tableSearch << fort::header << "Menu Cari Buku" << fort::endr;
                tableSearch.row(0).set_cell_min_width(30);
                tableSearch.row(0).set_cell_text_align(fort::text_align::center);
                tableSearch.row(0).set_cell_bg_color(fort::color::light_red);
                tableSearch.row(0).set_cell_content_fg_color(fort::color::green);
                std::cout << tableSearch.to_string() << std::endl;
                std::cout << "Cari Buku : ";
                std::cin >> cari;
  
                // desain tabel
                tableSearch2 << fort::header << "No"
                             << "Judul Buku"
                             << "Penulis Buku "
                             << "Tahun Terbit"
                             << "Stok Tersedia" << fort::endr;
  
                for (int a = 0, b = 0; a < bacaBuku.size(); a++) {
                  if (bacaBuku.at(a).judul.find(cari) != std::string::npos ||
                      bacaBuku.at(a).penulis.find(cari) != std::string::npos) {
                    tableSearch2
                        << b + 1 << bacaBuku.at(a).judul << bacaBuku.at(a).penulis
                        << bacaBuku.at(a).tahunTerbit << bacaBuku.at(a).stok
                        << fort::endr;
                    b++;
                  }
                }
  
                tableSearch2.set_border_style(FT_DOUBLE_STYLE);
                tableSearch2.set_cell_content_fg_color(fort::color::magenta);
                tableSearch2.column(3).set_cell_text_align(fort::text_align::center);
                tableSearch2.column(4).set_cell_text_align(fort::text_align::center);
  
                // cetak tabel
                std::cout << tableSearch2.to_string() << std::endl;
  
                // hold a second
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }
  
              // pilih sortir buku
              case 6: {
                //bersihkan layar
                system("clear");

                //variabel yang dibutuhkan
                char pilihSorting;
                isMenuAdmin = true;
  
                garis(37);
                std::cout << "|>>       Menu Sortir Buku        <<|";
                std::cout << std::endl;
                garis(37);
                std::cout << "|>>    1. Judul Asc               <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>>    2. Judul Desc              <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>>    3. Penulis Asc             <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>>    4. Penulis Desc            <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>>    5. Tahun Terbit Asc        <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>>    6. Tahun Terbit Desc       <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>>    7. Stok Asc                <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>>    8. Stok Desc               <<|";
                std::cout << std::endl;
                garis2(37);
  
                std::cout << "Pilih : ";
                std::cin >> pilihSorting;
                std::cout << std::endl;
  
                switch (pilihSorting) {
  
                // sortir judul (naik)
                case '1': {
                  // variabel yang dibutuhkan
                  std::fstream data;
                  std::vector<bukuTemp> hasilSort;
                  bukuTemp buffer;
  
                  // konversi ke tabel
                  fort::char_table table;
                  table.set_border_style(FT_NICE_STYLE);
                  table << fort::header << "No";
                  table << "Judul Buku";
                  table << "Penulis Buku";
                  table << "Tahun Terbit";
                  table << "Stok Tersedia";
                  table << fort::endr;
  
                  // clear daftar jika masih tersedia
                  hasilSort.clear();
  
                  // baca database buku
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    hasilSort.push_back(buffer);
                  }
                  data.close();
  
                  // sortir berdasarkan judul (naik)
                  std::stable_sort(hasilSort.begin(), hasilSort.end(), judulAsc);
  
                  // cetak hasil sortir
                  for (int a = 0; a < hasilSort.size(); a++) {
                    if (a + 1 < 10) {
                      table << a + 1;
                    } else if (a + 1 >= 10 && a + 1 < 100) {
                      table << a + 1;
                    }
                    table << hasilSort.at(a).judul;
                    table << hasilSort.at(a).penulis;
                    table << hasilSort.at(a).tahunTerbit;
                    table << hasilSort.at(a).stok;
                    table << fort::endr;
                  }
  
                  // cetak tabel
                  table.column(3).set_cell_text_align(fort::text_align::center);
                  table.column(4).set_cell_text_align(fort::text_align::center);
                  std::cout << table.to_string() << std::endl;
  
                  // pesan
                  std::cout << "Sorting Berhasil" << std::endl;
                  break;
                }
  
                // sortir judul (turun)
                case '2': {
                  // variabel yang dibutuhkan
                  std::fstream data;
                  std::vector<bukuTemp> hasilSort;
                  bukuTemp buffer;
  
                  // konversi ke tabel
                  fort::char_table table;
                  table.set_border_style(FT_NICE_STYLE);
                  table << fort::header << "No";
                  table << "Judul Buku";
                  table << "Penulis Buku";
                  table << "Tahun Terbit";
                  table << "Stok Tersedia";
                  table << fort::endr;
  
                  // clear daftar jika masih tersedia
                  hasilSort.clear();
  
                  // baca database buku
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    hasilSort.push_back(buffer);
                  }
                  data.close();
  
                  // sortir berdasarkan judul (naik)
                  std::stable_sort(hasilSort.begin(), hasilSort.end(), judulDesc);
  
                  // cetak hasil sortir
                  for (int a = 0; a < hasilSort.size(); a++) {
                    if (a + 1 < 10) {
                      table << a + 1;
                    } else if (a + 1 >= 10 && a + 1 < 100) {
                      table << a + 1;
                    }
                    table << hasilSort.at(a).judul;
                    table << hasilSort.at(a).penulis;
                    table << hasilSort.at(a).tahunTerbit;
                    table << hasilSort.at(a).stok;
                    table << fort::endr;
                  }
  
                  // cetak tabel
                  table.column(3).set_cell_text_align(fort::text_align::center);
                  table.column(4).set_cell_text_align(fort::text_align::center);
                  std::cout << table.to_string() << std::endl;
  
                  // pesan
                  std::cout << "Sorting Berhasil" << std::endl;
                  break;
                }
  
                // sortir penulis (naik)
                case '3': {
                  // variabel yang dibutuhkan
                  std::fstream data;
                  std::vector<bukuTemp> hasilSort;
                  bukuTemp buffer;
  
                  // konversi ke tabel
                  fort::char_table table;
                  table.set_border_style(FT_NICE_STYLE);
                  table << fort::header << "No";
                  table << "Judul Buku";
                  table << "Penulis Buku";
                  table << "Tahun Terbit";
                  table << "Stok Tersedia";
                  table << fort::endr;
  
                  // clear daftar jika masih tersedia
                  hasilSort.clear();
  
                  // baca database buku
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    hasilSort.push_back(buffer);
                  }
                  data.close();
  
                  // sortir berdasarkan judul (naik)
                  std::stable_sort(hasilSort.begin(), hasilSort.end(),
                                   penulisAsc);
  
                  // cetak hasil sortir
                  for (int a = 0; a < hasilSort.size(); a++) {
                    if (a + 1 < 10) {
                      table << a + 1;
                    } else if (a + 1 >= 10 && a + 1 < 100) {
                      table << a + 1;
                    }
                    table << hasilSort.at(a).judul;
                    table << hasilSort.at(a).penulis;
                    table << hasilSort.at(a).tahunTerbit;
                    table << hasilSort.at(a).stok;
                    table << fort::endr;
                  }
  
                  // cetak tabel
                  table.column(3).set_cell_text_align(fort::text_align::center);
                  table.column(4).set_cell_text_align(fort::text_align::center);
                  std::cout << table.to_string() << std::endl;
  
                  // pesan
                  std::cout << "Sorting Berhasil" << std::endl;
                  break;
                }
  
                // sortir penulis (turun)
                case '4': {
  
                  // variabel yang dibutuhkan
                  std::fstream data;
                  std::vector<bukuTemp> hasilSort;
                  bukuTemp buffer;
  
                  // konversi ke tabel
                  fort::char_table table;
                  table.set_border_style(FT_NICE_STYLE);
                  table << fort::header << "No";
                  table << "Judul Buku";
                  table << "Penulis Buku";
                  table << "Tahun Terbit";
                  table << "Stok Tersedia";
                  table << fort::endr;
  
                  // clear daftar jika masih tersedia
                  hasilSort.clear();
  
                  // baca database buku
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    hasilSort.push_back(buffer);
                  }
                  data.close();
  
                  // sortir berdasarkan judul (naik)
                  std::stable_sort(hasilSort.begin(), hasilSort.end(),
                                   penulisDesc);
  
                  // cetak hasil sortir
                  for (int a = 0; a < hasilSort.size(); a++) {
                    if (a + 1 < 10) {
                      table << a + 1;
                    } else if (a + 1 >= 10 && a + 1 < 100) {
                      table << a + 1;
                    }
                    table << hasilSort.at(a).judul;
                    table << hasilSort.at(a).penulis;
                    table << hasilSort.at(a).tahunTerbit;
                    table << hasilSort.at(a).stok;
                    table << fort::endr;
                  }
  
                  // cetak tabel
                  table.column(3).set_cell_text_align(fort::text_align::center);
                  table.column(4).set_cell_text_align(fort::text_align::center);
                  std::cout << table.to_string() << std::endl;
  
                  // pesan
                  std::cout << "Sorting Berhasil" << std::endl;
                  break;
                }
  
                // sort tahun terbit (naik)
                case '5': {
                  // variabel yang dibutuhkan
                  std::fstream data;
                  std::vector<bukuTemp> hasilSort;
                  bukuTemp buffer;
  
                  // konversi ke tabel
                  fort::char_table table;
                  table.set_border_style(FT_NICE_STYLE);
                  table << fort::header << "No";
                  table << "Judul Buku";
                  table << "Penulis Buku";
                  table << "Tahun Terbit";
                  table << "Stok Tersedia";
                  table << fort::endr;
  
                  // clear daftar jika masih tersedia
                  hasilSort.clear();
  
                  // baca database buku
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    hasilSort.push_back(buffer);
                  }
                  data.close();
  
                  // sortir berdasarkan judul (naik)
                  std::stable_sort(hasilSort.begin(), hasilSort.end(),
                                   tahunTerbitAsc);
  
                  // cetak hasil sortir
                  for (int a = 0; a < hasilSort.size(); a++) {
                    if (a + 1 < 10) {
                      table << a + 1;
                    } else if (a + 1 >= 10 && a + 1 < 100) {
                      table << a + 1;
                    }
                    table << hasilSort.at(a).judul;
                    table << hasilSort.at(a).penulis;
                    table << hasilSort.at(a).tahunTerbit;
                    table << hasilSort.at(a).stok;
                    table << fort::endr;
                  }
  
                  // cetak tabel
                  table.column(3).set_cell_text_align(fort::text_align::center);
                  table.column(4).set_cell_text_align(fort::text_align::center);
                  std::cout << table.to_string() << std::endl;
  
                  // pesan
                  std::cout << "Sorting Berhasil" << std::endl;
                  break;
                }
  
                // sortir tahun terbit (turun)
                case '6': {
                  // variabel yang dibutuhkan
                  std::fstream data;
                  std::vector<bukuTemp> hasilSort;
                  bukuTemp buffer;
  
                  // konversi ke tabel
                  fort::char_table table;
                  table.set_border_style(FT_NICE_STYLE);
                  table << fort::header << "No";
                  table << "Judul Buku";
                  table << "Penulis Buku";
                  table << "Tahun Terbit";
                  table << "Stok Tersedia";
                  table << fort::endr;
  
                  // clear daftar jika masih tersedia
                  hasilSort.clear();
  
                  // baca database buku
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    hasilSort.push_back(buffer);
                  }
                  data.close();
  
                  // sortir berdasarkan judul (naik)
                  std::stable_sort(hasilSort.begin(), hasilSort.end(),
                                   tahunTerbitDesc);
  
                  // cetak hasil sortir
                  for (int a = 0; a < hasilSort.size(); a++) {
                    if (a + 1 < 10) {
                      table << a + 1;
                    } else if (a + 1 >= 10 && a + 1 < 100) {
                      table << a + 1;
                    }
                    table << hasilSort.at(a).judul;
                    table << hasilSort.at(a).penulis;
                    table << hasilSort.at(a).tahunTerbit;
                    table << hasilSort.at(a).stok;
                    table << fort::endr;
                  }
  
                  // cetak tabel
                  table.column(3).set_cell_text_align(fort::text_align::center);
                  table.column(4).set_cell_text_align(fort::text_align::center);
                  std::cout << table.to_string() << std::endl;
  
                  // pesan
                  std::cout << "Sorting Berhasil" << std::endl;
                  break;
                }
  
                // sortir stok (naik)
                case '7': {
  
                  // variabel yang dibutuhkan
                  std::fstream data;
                  std::vector<bukuTemp> hasilSort;
                  bukuTemp buffer;
  
                  // konversi ke tabel
                  fort::char_table table;
                  table.set_border_style(FT_NICE_STYLE);
                  table << fort::header << "No";
                  table << "Judul Buku";
                  table << "Penulis Buku";
                  table << "Tahun Terbit";
                  table << "Stok Tersedia";
                  table << fort::endr;
  
                  // clear daftar jika masih tersedia
                  hasilSort.clear();
  
                  // baca database buku
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    hasilSort.push_back(buffer);
                  }
                  data.close();
  
                  // sortir berdasarkan judul (naik)
                  std::stable_sort(hasilSort.begin(), hasilSort.end(), stokAsc);
  
                  // cetak hasil sortir
                  for (int a = 0; a < hasilSort.size(); a++) {
                    if (a + 1 < 10) {
                      table << a + 1;
                    } else if (a + 1 >= 10 && a + 1 < 100) {
                      table << a + 1;
                    }
                    table << hasilSort.at(a).judul;
                    table << hasilSort.at(a).penulis;
                    table << hasilSort.at(a).tahunTerbit;
                    table << hasilSort.at(a).stok;
                    table << fort::endr;
                  }
  
                  // cetak tabel
                  table.column(3).set_cell_text_align(fort::text_align::center);
                  table.column(4).set_cell_text_align(fort::text_align::center);
                  std::cout << table.to_string() << std::endl;
  
                  // pesan
                  std::cout << "Sorting Berhasil" << std::endl;
                  break;
                }
  
                // sortir stok (turun)
                case '8': {
                  // variabel yang dibutuhkan
                  std::fstream data;
                  std::vector<bukuTemp> hasilSort;
                  bukuTemp buffer;
  
                  // konversi ke tabel
                  fort::char_table table;
                  table.set_border_style(FT_NICE_STYLE);
                  table << fort::header << "No";
                  table << "Judul Buku";
                  table << "Penulis Buku";
                  table << "Tahun Terbit";
                  table << "Stok Tersedia";
                  table << fort::endr;
  
                  // clear daftar jika masih tersedia
                  hasilSort.clear();
  
                  // baca database buku
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    hasilSort.push_back(buffer);
                  }
                  data.close();
  
                  // sortir berdasarkan judul (naik)
                  std::stable_sort(hasilSort.begin(), hasilSort.end(), stokDesc);
  
                  // cetak hasil sortir
                  for (int a = 0; a < hasilSort.size(); a++) {
                    if (a + 1 < 10) {
                      table << a + 1;
                    } else if (a + 1 >= 10 && a + 1 < 100) {
                      table << a + 1;
                    }
                    table << hasilSort.at(a).judul;
                    table << hasilSort.at(a).penulis;
                    table << hasilSort.at(a).tahunTerbit;
                    table << hasilSort.at(a).stok;
                    table << fort::endr;
                  }
  
                  // cetak tabel
                  table.column(3).set_cell_text_align(fort::text_align::center);
                  table.column(4).set_cell_text_align(fort::text_align::center);
                  std::cout << table.to_string() << std::endl;
  
                  // pesan
                  std::cout << "Sorting Berhasil" << std::endl;
                  break;
                }
  
                default: {
                  std::cout << "Pilihan tidak tersedia" << std::endl;
                }
                }
  
                // hold a second
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }
  
              //pilih lihat semua admin
              case 7: {
                //bersihkan layar
                system("clear");

                //variabel yang dibutuhkan
                std::vector<std::string> semuaNya;
                std::fstream data;
                std::string temp;
                isMenuAdmin = true;

                _152.dataAdmin(semuaNya, data, temp);
                
                // hold a second
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }
              
              //pilih lihat semua user
              case 8: {
                //bersihkan tampilan
                system("clear");

                //variabel yang dibutuhkan
                std::vector<std::string> semuaNya;
                std::fstream data;
                std::string temp;
                isMenuAdmin = true;
                
                _157.dataPengguna(semuaNya, data, temp);
                
                // hold a second
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }

              //pilih konfirmasi transaksi
              case 9: {
                //bersihkan layar
                system("clear");

                //variabel yang dibutuhkan
                std::vector<Antrian> konfirmasiAntrian;
                std::fstream data;
                Antrian temp;
                QueueDLL<Antrian> queue;
                short no;

                //pepe
                _152.antrianPeminjam(konfirmasiAntrian, data, temp, queue, no);

                // hold a second
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }
              
              // Ke luar dari menu admin
              case 10: {
                isMenuAdmin = false;
                break;
              }
  
              default: {
                isMenuAdmin = true;
                std::cout << "Pilihan tidak tersedia" << std::endl;
              }
            }
          }
        }
        else {
          std::cout << "Username/Password salah" << std::endl;

          // hold a second
          std::cout << "Input apa saja untuk melanjutkan... ";
          std::cin >> isPause;
        }
        break;
      }

      // Login sebagai user
      case '2': {
        // variabel yang dibutuhkan
        std::fstream data;
        std::string bufferPassword;
        bool isLogin;
        char isPause;

        std::cout << "ID       : ";
        std::cin >> id;
        std::cout << "Password : ";
        std::cin >> password;

        // baca database user
        data.open("user/" + id + ".txt", std::ios::in);
        std::getline(data, bufferPassword);
        if (data.is_open()) {
          isLogin = true;
        }
        data.close();

        // Cek NIK dan Password user hasil register
        if (isLogin == true && password == bufferPassword) {
          // variabel yang dibutuhkan
          short menuUser;

          while (isMenuUser) {
            system("clear");

            // variabel yang dibutuhkan
            std::vector<bukuTemp> keranjang;
            
            // input user memilih menu User
            garis(37);
            std::cout << "|>>       Masuk sebagai User      <<|";
            std::cout << std::endl;
            garis(37);
            std::cout << "|>>    1. Lihat List Buku         <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>    2. Pinjam Buku             <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>    3. Lihat Buku              <<|";
            std::cout << std::endl;
            std::cout << "|>>       yang akan Dipinjam      <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>    4. Hapus Buku              <<|";
            std::cout << std::endl;
            std::cout << "|>>       yang akan Dipinjam      <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>    5. Transaksi               <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>    6. Cek Status              <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>    7. Cetak Invoice           <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>    8. Cari Buku               <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>    9. Filter Buku             <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>   10. Bookmark Buku           <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>   11. Ekstrak Informasi Buku  <<|";
            std::cout << std::endl;
            garis2(37);
            std::cout << "|>>   12. Ke luar                 <<|";
            std::cout << std::endl;
            garis(37);
            std::cout << "Pilih : ";

            std::cin >> menuUser;

            switch (menuUser) {
            // pilih tampil daftar buku
            case 1: {
              //bersihkan layar
              system("clear");

              // variabel yang dibutuhkan untuk mencetak daftar buku
              char pilihTampil;
              isMenuUser = true;

              garis(37);
              std::cout << "|>>        Menu Print Buku        <<|";
              std::cout << std::endl;
              garis(37);

              // input user pilih tampil data
              garis2(37);
              std::cout << "|>>    Ingin menampilkan dengan?  <<|";
              std::cout << std::endl;
              garis2(37);
              std::cout << "|>> 1. Array1D Dinamis            <<|";
              std::cout << std::endl;
              garis2(37);
              std::cout << "|>> 2. Single Linked List         <<|";
              std::cout << std::endl;
              garis2(37);
              std::cout << "|>> 3. Double Linked List         <<|";
              std::cout << std::endl;
              garis2(37);

              std::cout << "Pilih : ";
              std::cin >> pilihTampil;
              std::cout << std::endl;

              switch (pilihTampil) {
                // pilih array1d dinamis
                case '1': {
                  // variabel yang dibutuhkan ketika mencetak dengan array1d
                  // dinamis
                  std::fstream data;
                  std::vector<bukuTemp> bacaBuku;
                  bukuTemp buffer;
                  
                  // bikin tabel
                  fort::char_table table;
                  table.set_border_style(FT_NICE_STYLE);
                  table << fort::header << "No";
                  table << "Judul Buku";
                  table << "Penulis Buku";
                  table << "Tahun Terbit";
                  table << "Stok Tersedia";
                  table << fort::endr;
                  
                  // baca database buku
                  bacaBuku.clear();
                  data.open("Buku.txt");
                  while (std::getline(data, buffer.judul, ';') &&
                         std::getline(data, buffer.penulis, ';') &&
                         data >> buffer.tahunTerbit >> buffer.stok) {
                    bacaBuku.push_back(buffer);
                  }
                  data.close();
  
                  // resize ukuran array
                  arrBuku.resize(bacaBuku.size());
  
                  // isi array dari vector
                  for (int a = 0; a < arrBuku.getUkuran(); a++) {
                    arrBuku[a].setJudul(bacaBuku.at(a).judul.c_str());
                    arrBuku[a].setPenulis(bacaBuku.at(a).penulis.c_str());
                    arrBuku[a].setTahunTerbit(bacaBuku.at(a).tahunTerbit);
                    arrBuku[a].setStok(bacaBuku.at(a).stok);
                  }
                  
                  // cetak value array
                  for (int a = 0; a < arrBuku.getUkuran(); a++) {
                    if (a + 1 < 10) {
                      table << a + 1;
                    } else if (a + 1 >= 10 && a + 1 < 100) {
                      table << a + 1;
                    }
                    table << arrBuku[a].getJudul();
                    table << arrBuku[a].getPenulis();
                    table << arrBuku[a].getTahunTerbit();
                    table << arrBuku[a].getStok();
                    table << fort::endr;
                  }
                  table.column(3).set_cell_text_align(fort::text_align::center);
                  table.column(4).set_cell_text_align(fort::text_align::center);
                  std::cout << table.to_string() << std::endl;
                  
                  // hold a second
                  std::cout << "Input apa saja untuk melanjutkan... ";
                  std::cin >> isPause;
                  break;
                }
  
                // pilih single linked list
                case '2': {
                // variabel yang dibutuhkan untuk cetak daftar buku dengan sll
                SinglyLinkedList<Buku> listBuku;
                std::vector<bukuTemp> bacaBuku;
                std::fstream data;
                bukuTemp buffer;
                Buku temp;
  
                // clear list
                listBuku.clearList();
                bacaBuku.clear();
                // baca database buku
                data.open("Buku.txt");
                while (std::getline(data, buffer.judul, ';') &&
                       std::getline(data, buffer.penulis, ';') &&
                       data >> buffer.tahunTerbit >> buffer.stok) {
                  bacaBuku.push_back(buffer);
                }
                data.close();
  
                // isi node
                for (int a = 0; a < bacaBuku.size(); a++) {
                  temp.setJudul(bacaBuku.at(a).judul.c_str());
                  temp.setPenulis(bacaBuku.at(a).penulis.c_str());
                  temp.setTahunTerbit(bacaBuku.at(a).tahunTerbit);
                  temp.setStok(bacaBuku.at(a).stok);
                  listBuku.tambahDepan(temp);
                }
  
                // cetak Single Linked List
                listBuku.display();
  
                // hold a second
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }
  
                // pilih doubly linked list
                case '3': {
                // variabel yang dibutuhkan untuk mencetak daftar buku dengan
                // dll
                DoublyLinkedList<Buku> listBuku;
                std::vector<bukuTemp> bacaBuku;
                std::fstream data;
                bukuTemp buffer;
                Buku temp;
  
                // clear list
                listBuku.clearList();
                bacaBuku.clear();
  
                // baca database buku
                data.open("Buku.txt");
                while (std::getline(data, buffer.judul, ';') &&
                       std::getline(data, buffer.penulis, ';') &&
                       data >> buffer.tahunTerbit >> buffer.stok) {
                  bacaBuku.push_back(buffer);
                }
                data.close();
  
                // isi node
                listBuku.clearList();
                for (int a = 0; a < bacaBuku.size(); a++) {
                  temp.setJudul(bacaBuku.at(a).judul.c_str());
                  temp.setPenulis(bacaBuku.at(a).penulis.c_str());
                  temp.setTahunTerbit(bacaBuku.at(a).tahunTerbit);
                  temp.setStok(bacaBuku.at(a).stok);
                  listBuku.tambahBelakang(temp);
                }
  
                // cetak double linked list
                listBuku.cetakMaju();
  
                // hold a second
                std::cout << "Input apa saja untuk melanjutkan... ";
                std::cin >> isPause;
                break;
              }
  
                default: {
                std::cout << "Pilihan tidak tersedia" << std::endl;
                }
              }
              break;
            }
      
            // pilih pinjam buku
            case 2: {
              //bersihkan layar
              system("clear");
                
              // variabel yang dibutuhkan untuk meminjam buku
              std::vector<bukuTemp> bacaBuku;
              std::vector<bukuTemp> maksBuku;
              std::fstream data;
              int pilihBuku;
              bukuTemp buffer;
              Buku keStack;
              isMenuUser = true;
              
              garis(37);
              std::cout << "|>>       Menu Pinjam Buku        <<|";
              std::cout << std::endl;
              garis(37);

              _152.keranjang(bacaBuku, 
                             maksBuku, 
                             data, 
                             buffer, 
                             keStack, 
                             stackBuku, 
                             id, 
                             pilihBuku);
              
              // hold a second
              std::cout << "Input apa saja untuk melanjutkan... ";
              std::cin >> isPause;
              break;
            }

            // pilih lihat list buku yang sudah dipilih
            case 3: {
              //bersihkan layar
              system("clear");
              
              // variabel yang dibutuhkan untuk melihat list buku
              bukuTemp buffer;
              std::vector<Buku> listPinjam;
              isMenuUser = true;

              // bikin tabel
              fort::char_table table;
              table.set_border_style(FT_NICE_STYLE);
              table << fort::header << "No";
              table << "Judul Buku";
              table << fort::endr;

              garis(37);
              std::cout << "|>>        Menu Buku Saya         <<|";
              std::cout << std::endl;
              garis(37);
              std::cout << std::endl;

              // baca database user yang login
              data.open("user/" + id + "_keranjang.txt", std::ios::in);
              if (!data.is_open()) {
                std::cout << "!!! Keranjang kosong !!!" << std::endl;
                exit(1);
              }

              keranjang.clear();
              while (std::getline(data, buffer.judul, ';') &&
                     std::getline(data, buffer.penulis, ';') &&
                     data >> buffer.tahunTerbit >> buffer.stok) {
                keranjang.push_back(buffer);
              }
              data.close();

              // cetak yang dipilih user
              for (int a = 0; a < keranjang.size(); a++) {
                if (a + 1 < 10) {
                  table << a + 1;
                } else if (a + 1 >= 10 && a + 1 < 100) {
                  table << a + 1;
                }
                table << keranjang.at(a).judul;
                table << fort::endr;
              }
              std::cout << table.to_string() << std::endl;
              
              // hold a second
              std::cout << "Input apa saja untuk melanjutkan... ";
              std::cin >> isPause;
              break;
            }

            // pilih hapus buku yang sudah dipilih
            case 4: {
              //bersihkan layar
              system("clear");

              //variabel yang dibutuhkan
              std::vector<bukuTemp> listHapus;
              bukuTemp buffer;
              int pilih;
              isMenuUser = true;

              _152.hapusBukuKeranjang(keranjang, data, buffer, pilih, id);
              
              // hold a second
              std::cout << "Input apa saja untuk melanjutkan... ";
              std::cin >> isPause;
              break;
            }
              
            // pilih transaksi
            case 5: {
              //bersihkan layar
              system("clear");

              // variabel yang dibutuhkan untuk transaksi
              std::string temp;
              std::fstream data;
              std::string isBenarUser, isBenarPassword;
              fort::char_table table;
              int noAntrian = 0;
              bool status = true;
              isMenuUser = true;

              garis(37);
              std::cout << "|>>        Menu Transaksi         <<|";
              std::cout << std::endl;
              garis(37);
              std::cout << std::endl;

              table << fort::header << "   !!! Konfirmasi Identitas !!!   ";
              table << fort::endr;
              std::cout << table.to_string() << std::endl;              

              std::cout << "Username : ";
              std::cin >> isBenarUser;
              std::cout << "Password : ";
              std::cin >> isBenarPassword;

              // cek jika belum diacc tapi ingin pinjam lagi
              data.open("Transaksi/" + id + "_status.txt", std::ios::in);
              data >> status;
              data.close();

              if(status == true){
                // cek apakah yang pinjam adalah yang login
                if (isBenarUser == id && isBenarPassword == bufferPassword) {
                  fort::char_table table2;
                  table2 << fort::header << "    !!! Transaksi Berhasil !!!    " << fort::endr;
                  table2 << "Mohon Tunggu di Acc" << fort::endr;
                  table2 << fort::endr;
                  table2.row(1).set_cell_text_align(fort::text_align::center);
                  std::cout << table2.to_string() << std::endl;
                  std::cout << std::endl;
  
                  data.open("Transaksi/noAntrian.txt", std::ios::in);
                  while(data >> noAntrian &&
                        std::getline(data, temp, ';'));
                  data.close();
                  
                  data.open("Transaksi/noAntrian.txt", std::ios::app);
                  data << ++noAntrian << ";" << id <<";";
                  data.close();
                  
                  data.open("Transaksi/" + id + "_status.txt", std::ios::out);
                  data << "0";
                  data.close();
                } 
                
              } else {
                  std::cout << "!!! Silakan tunggu di Acc !!!" << std::endl;
              }

              // hold a second
              std::cout << "Input apa saja untuk melanjutkan... ";
              std::cin >> isPause;
              break;
            }

            // pilih cek status peminjaman
            case 6: {
              //bersihkan layar
              system("clear");

              //variabel yang dibutuhkan
              std::fstream data;
              bool status;
              isMenuUser = true;

              //header
              garis(37);
              std::cout << "|>>        Menu Cek Status       <<|";
              std::cout << std::endl;
              garis(37);
              
              //baca status
              data.open("Transaksi/" + id + "_status.txt", std::ios::in);
              data >> status;
              data.close();

              //cek kondisi jika sudah di acc ato belum
              if(status == true){
                std::cout << "Sudah di Acc" << std::endl;
                std::cout << "Cetaklah invoice sebagai bukti" << std::endl;
              } else {
                std::cout << "Belum di Acc" << std::endl;
              }
              
              // hold a second
              std::cout << "Input apa saja untuk melanjutkan... ";
              std::cin >> isPause;
              break;
            }

            // pilih cetak invoice
            case 7: {
              //bersihkan layar
              system("clear");
              
              //variabel yang dibutuhkan
              std::vector<bukuTemp> invoice;
              std::fstream data;
              std::string buffer[20];
              bukuTemp bufferBuku;
              bool isAcc = false;
              isMenuUser = true;

              //header
              garis(37);
              std::cout << "|>>       Menu Cetak Invoice      <<|";
              std::cout << std::endl;
              garis(37);
              
              //cek sudah di acc ato belum
              data.open("Transaksi/" + id + "_status.txt", std::ios::in);
              data >> isAcc;
              data.close();
              
              if(isAcc == true){
                // cek apakah keranjang kosong dan memasukkannya ke vector
                data.open("user/" + id + "_keranjang.txt", std::ios::in);
                if (!data.is_open()) {
                  std::cout << "Keranjang kosong" << std::endl;
                  exit(1);
                }
                while (std::getline(data, bufferBuku.judul, ';') &&
                       std::getline(data, bufferBuku.penulis, ';') &&
                       data >> bufferBuku.tahunTerbit >> bufferBuku.stok) {
                  invoice.push_back(bufferBuku);
                }
                data.close();
                
                // baca data ktp untuk identitas pada invoice
                data.open("dataKTP/" + id + ".txt", std::ios::in);
                while (std::getline(data, buffer[0], ',') &&
                       std::getline(data, buffer[1], ',') &&
                       std::getline(data, buffer[2], ',') &&
                       std::getline(data, buffer[3], ',') &&
                       std::getline(data, buffer[4], ',') &&
                       std::getline(data, buffer[5], ',') &&
                       std::getline(data, buffer[6], ',') &&
                       std::getline(data, buffer[7], ',') &&
                       std::getline(data, buffer[8], ',') &&
                       std::getline(data, buffer[9], ',') &&
                       std::getline(data, buffer[10], ',') &&
                       std::getline(data, buffer[11], ',') &&
                       std::getline(data, buffer[12], ',') &&
                       std::getline(data, buffer[13], ',') &&
                       std::getline(data, buffer[14], ',') &&
                       std::getline(data, buffer[15], ',') &&
                       std::getline(data, buffer[16], ',') &&
                       std::getline(data, buffer[17], ',') &&
                       std::getline(data, buffer[18], ',') &&
                       std::getline(data, buffer[19], ','))
                  ;
                data.close();
                
                // isi invoice
                _157.invoice2(waktuSekarang->tm_mday, 1 + waktuSekarang->tm_mon,
                              1900 + waktuSekarang->tm_year, buffer[3],
                              buffer[10], buffer[1], invoice, id);
                // pesan
                std::cout << "Invoice berhasil dicetak" << std::endl;
              } else {
                std::cout << "Transaksi belum di Acc" << std::endl;
              }

              // hold a second
              std::cout << "Input apa saja untuk melanjutkan... ";
              std::cin >> isPause;
              break;
            }

            // pilih cari buku
            case 8: {
              // bersihkan layar
              system("clear");

              //variabel yang dibutuhkan
              std::string cari;
              std::vector<bukuTemp> bacaBuku;
              std::fstream data;
              bukuTemp buffer;
              isMenuUser = true;
              
              _165.searchBuku(bacaBuku, data, buffer, cari);
              
              // hold a second
              std::cout << "Input apa saja untuk melanjutkan... ";
              std::cin >> isPause;
              break;
            }
              
            // pilih filter buku
            case 9: {
              // bersihkan layar
              system("clear");

              //variabel yang dibutuhkan
              std::vector<bukuTemp> bacaBuku;
              std::fstream data;
              bukuTemp buffer;
              char pilih;
              isMenuAdmin = true;

//pepe
              _165.filterBuku(bacaBuku, data, buffer, pilih);
              
              // hold a second
              std::cout << "Input apa saja untuk melanjutkan... ";
              std::cin >> isPause;
              break;
            }

            // pilih bookmark buku
            case 10: {
              // bersihkan layar
              system("clear");

              //variable yang dibutuhkan
              std::vector<bukuTemp> bacaBuku;
              std::fstream data;
              bukuTemp buffer;
              char pilih;
              isMenuUser = true;

              _157.bookmark(bacaBuku, data, buffer, pilih, id);

              // hold a second
              std::cout << "Input apa saja untuk melanjutkan... ";
              std::cin >> isPause;
              break;
            }
              
            // pilih ekstrak info buku
            case 11: {
              // bersihkan layar
              system("clear");

              // variabel yang dibutuhkan
              std::vector<bukuTemp> bacaBuku;
              std::fstream data;
              bukuTemp buffer;
              int pilih;
              isMenuUser = true;

              _165.ekstrakBuku(bacaBuku, data, buffer, pilih, id);
              
              // hold a second
              std::cout << "Input apa saja untuk melanjutkan... ";
              std::cin >> isPause;
              break;
            }
              
            // ke luar dari menu
            case 12: {
              isMenuUser = false;
              break;
            }
            default:
              std::cout << "Pilihan tidak tersedia" << std::endl;
            }
          }
        }
        else {
          std::cout << "Username/Password salah" << std::endl;

          // hold a second
          std::cout << "Input apa saja untuk melanjutkan... ";
          std::cin >> isPause;
        }
        break;
      }
      default:
        std::cout << "Pilihan tidak tersedia" << std::endl;
      }
      break;
    }

    // Daftar akun
    case '2': {
      isMenuUtama = true;
      // variabel yang dibutuhkan memilih menu
      char pilihDaftar;

      // input user untuk memilih tipe akun
      std::cout << "Daftar sebagai : " << std::endl;
      std::cout << "1. Admin" << std::endl;
      std::cout << "2. Pengguna" << std::endl;
      std::cout << "Pilih : ";

      std::cin >> pilihDaftar;

      switch (pilihDaftar) {

      // Sebagai admin
      case '1': {
        // variabel yang dibutuhkan untuk daftar akun (admin)
        std::vector<std::string> bacaKTP;
        std::fstream data;
        std::string nik;
        std::string password;
        std::string temp;

        std::cout << "Masukkan NIK : ";
        std::cin >> nik;

        // cek apakah nik terdaftar di sistem
        data.open("dataKTP/" + nik + ".txt", std::ios::in);
        if (!data.is_open()) {
          std::cout << "NIK Tidak terdaftar" << std::endl;
        } else {
          std::cout << "Masukkan password : ";
          std::cin >> password;
        }
        data.close();

        //baca KTP
        data.open("dataKTP/" + nik + ".txt", std::ios::in);
        while(std::getline(data, temp, ',')){
          bacaKTP.push_back(temp);
        }
        data.close();

        //tulis ke database akun
        data.open("admin/dataSemuaAdmin.txt", std::ios::app);
        for(int a = 0; a < bacaKTP.size(); a++){
          data << bacaKTP.at(a)<<";";
        }
        data.close();
        
        // tulis password yang telah diregister
        data.open("admin/" + nik + ".txt", std::ios::out | std::ios::trunc);
        data << password;
        data.close();


        //pesan
        std::cout << "Berhasil daftar sebagai Admin" << std::endl;
        
        // hold a second
        std::cout << "Input apa saja untuk melanjutkan... ";
        std::cin >> isPause;
        break;
      }

      // Sebagai pengguna
      case '2': {
        // variabel yang dibutuhkan untuk daftar akun (pengguna)
        std::fstream data;
        std::string nik;
        std::string password;

        std::cout << "Masukkan NIK : ";
        std::cin >> nik;

        // cek apakah nik terdaftar di sistem
        data.open("dataKTP/" + nik + ".txt", std::ios::in);
        if (!data.is_open()) {
          std::cout << "NIK Tidak terdaftar" << std::endl;
        } else {
          std::cout << "Masukkan password : ";
          std::cin >> password;
        }
        data.close();

        // tulis password yang diregister
        data.open("user/" + nik + ".txt", std::ios::out | std::ios::trunc);
        data << password;
        data.close();

        //pesan
        std::cout << "Berhasil daftar sebagai User" << std::endl;
        
        // hold a second
        std::cout << "Input apa saja untuk melanjutkan... ";
        std::cin >> isPause;
        break;
      }
      }
      break;
    }

    // pilih input ktp
    case '3': {
      isMenuUtama = true;
      _152.inputKTP();

      //pesan
      std::cout << "Berhasil input KTP" << std::endl;
      
      // hold a second
      std::cout << "Input apa saja untuk melanjutkan... ";
      std::cin >> isPause;
      break;
    }

    // pilih exit
    case '4': {
      isMenuUtama = false;
      std::cout << "Semoga Senantiasa" << std::endl;
      break;
    }
    default: {
      isMenuUtama = true;
      std::cout << "Pilihan tidak tersedia" << std::endl;
    }
    }
  } while (isMenuUtama == true);
  // }

  return 0;
}

void garis(int x) {
  if (x > 0) {
    std::cout << "=";
    garis(x - 1);
  } else {
    std::cout << std::endl;
    return;
  }
}

void garis2(int x) {
  if (x > 0) {
    std::cout << "-";
    garis2(x - 1);
  } else {
    std::cout << std::endl;
    return;
  }
}