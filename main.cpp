#include "152.h"
#include "157.h"
#include "165.h"
#include "behaviour.hpp"
#include "class/DoublyLinkedList.hpp"
#include "class/SinglyLinkedList.hpp"
#include "class/admin.hpp"
#include "class/array1d.hpp"
#include "class/buku.hpp"
#include "class/database.hpp"
#include "class/ktp.hpp"
#include "class/random.hpp"
#include "class/sistem.hpp"
#include "class/StackArrayDinamis.hpp"
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

int main()
{
  // Pertemuan 3 : Array Dinamis
  Array1D<Buku> arrBuku(0);
  StackArrayDinamis<Buku> stackBuku(3);
  std::vector<Buku> tempBuku;
  char menuUtama;
  // Pertemuan 2 : Array Statis
  int angka[5];
  bool isMenuUtama;
  time_t now = time(0);
  tm *waktuSekarang = localtime(&now);

  // if(false){
  do 
  {
    // Menu Utama
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

    switch (menuUtama) 
    {
      // Login ke sistem
      case '1': 
      {
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
  
        switch (tipeUser) 
        {
          // Login sebagai admin
          case '1': 
          {    
            // variabel yang dibutuhkan
            std::fstream data;
            std::string bufferPassword;
            bool isLogin;
            char isPause;
    
            std::cout << "ID       : ";
            std::cin >> id;
            std::cout << "Password : ";
            std::cin >> password;
    
            // baca database admin
            data.open("admin/" + id + ".txt", std::ios::in);
            std::getline(data, bufferPassword);
            if (data.is_open())
            {
              isLogin = true;
            }
            data.close();
    
            // Cek apakah username (NIK) dan password (Register) sesuai
            if (isLogin == true && password == bufferPassword) 
            {
              // variabel yang dibutuhkan
              char menuAdmin;
              Database database;
              Buku data;
              std::string judul;
              std::string penulis;
              int tahunTerbit;
              short stok;
    
              while (menuAdmin != '6') 
              {
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
                std::cout << "|>>   6. Ke luar                  <<|" << std::endl;
                garis(37);
                std::cout << "Pilih : ";
    
                std::cin >> menuAdmin;
    
                switch (menuAdmin) 
                {
                  // Pilih tambah buku
                  case '1': 
                  {
                    system("clear");
                    // variabel yang dibutuhkan 165 no counter
                    short jumlahTambahBuku;

                    garis(37);
                    std::cout << "|>>       Menu Tambah Buku        <<|";
                    std::cout << std::endl;
                    garis(37); 
                    
                    std::cout << "Tambah berapa buku? ";
                    std::cin >> jumlahTambahBuku;
                    std::cout << std::endl;
                    
                    for (int a = 0; a < jumlahTambahBuku; a++) 
                    {
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
                    for (int a = 0; a < arrBuku.getUkuran(); a++)
                    {
                      arrBuku[a].setJudul(tempBuku[a].getJudul().c_str());
                      arrBuku[a].setPenulis(tempBuku[a].getPenulis().c_str());
                      arrBuku[a].setTahunTerbit(tempBuku[a].getTahunTerbit());
                      arrBuku[a].setStok(tempBuku[a].getStok());
                    }
      
                    // pesan
                    std::cout << "Buku Berhasil ditambah" << std::endl;
                    std::cout << std::endl;

                    //hold a second
                    std::cout << "Input apa saja untuk melanjutkan... ";
                    std::cin >> isPause;
                    break;
                  }
      
                  // Pilih hapus buku
                  case '2':
                  {
                    system("clear");
                    // variabel yang dibutuhkan
                    short posisi;
                    std::fstream data;
                    std::vector<bukuTemp> hapusBuku;
                    bukuTemp buffer;

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
                           data >> buffer.tahunTerbit >> buffer.stok)
                    {
                      hapusBuku.push_back(buffer);
                    }
                    data.close();
      
                    // cek kondisi jika user memasukkan nilai yang invalid
                    if (posisi - 1 < 0 || posisi - 1 > hapusBuku.size() - 1)
                    {
                      std::cout << "Gagal dihapus karena di luar kendali"
                                << std::endl;
                      exit(1);
                    }
      
                    // hapus buku
                    hapusBuku.erase(hapusBuku.begin() + posisi - 1);
      
                    // resize array, samakan dengan ukuran vector
                    arrBuku.resize(hapusBuku.size());
      
                    // isi nilai array dengan banyaknya vector
                    for (int a = 0; a < arrBuku.getUkuran(); a++)
                    {
                      arrBuku[a].setJudul(hapusBuku.at(a).judul.c_str());
                      arrBuku[a].setPenulis(hapusBuku.at(a).penulis.c_str());
                      arrBuku[a].setTahunTerbit(hapusBuku.at(a).tahunTerbit);
                      arrBuku[a].setStok(hapusBuku.at(a).stok);
                    }
      
                    // tulis hasil hapus
                    data.open("Buku.txt", std::ios::out);
                    for (int a = 0; a < hapusBuku.size(); a++)
                    {
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
                  case '3': 
                  {
                    // variabel yang dibutuhkan
                    std::vector<bukuTemp> updateBuku;
                    std::fstream data;
                    std::ofstream tulisUpdatean;
                    bukuTemp buffer;
                    short noBuku;
                    char pilihUpdate;
                    bool isMenuUpdate;

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
                           data >> buffer.tahunTerbit >> buffer.stok)
                    {
                      updateBuku.push_back(buffer);
                    }
                    data.close();
      
                    // cek kondisi jika user memasukkan nilai yang invalid
                    if (noBuku - 1 < 0 || noBuku - 1 > updateBuku.size() - 1)
                    {
                      std::cout << "Gagal mengupdate buku karena di luar kendali"
                                << std::endl;
                      exit(1);
                    }
      
                    do 
                    {
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
      
                      switch (pilihUpdate)
                      {
                      // pilih judul
                      case '1': 
                      {
                        isMenuUpdate = true;
                        std::cin.ignore();
                        std::cout << "Judul baru : ";
                        std::getline(std::cin, buffer.judul);
                        updateBuku.at(noBuku - 1).judul = buffer.judul;
                        std::cout << "Update Berhasil" << std::endl;
                        break;
                      }
      
                      // pilih penulis
                      case '2':
                      {
                        isMenuUpdate = true;
                        std::cin.ignore();
                        std::cout << "Penulis baru : ";
                        std::getline(std::cin, buffer.penulis);
                        updateBuku.at(noBuku - 1).penulis = buffer.penulis;
                        std::cout << "Update Berhasil" << std::endl;
                        break;
                      }
      
                      // pilih tahun terbit
                      case '3':
                      {
                        isMenuUpdate = true;
                        std::cout << "Tahun terbit baru : ";
                        std::cin >> buffer.tahunTerbit;
                        updateBuku.at(noBuku - 1).tahunTerbit = buffer.tahunTerbit;
                        std::cout << "Update Berhasil" << std::endl;
                        break;
                      }
      
                      // pilih stok
                      case '4':
                      {
                        isMenuUpdate = true;
                        std::cout << "Stok baru : ";
                        std::cin >> buffer.stok;
                        updateBuku.at(noBuku - 1).stok = buffer.stok;
                        std::cout << "Update Berhasil" << std::endl;
                        break;
                      }
      
                      default:
                        isMenuUpdate = false;
                        std::cout << "Pilihan tidak tersedia" << std::endl;
                      }
                    } while (isMenuUpdate == false);
      
                    // tulis hasil edit
                    tulisUpdatean.open("Buku.txt");
                    for (int a = 0; a < updateBuku.size(); a++)
                    {
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
                  case '4':
                  {
                    system("clear");
                    
                    // variabel yang dibutuhkan
                    char pilihSorting;
                    char pilihTampil;
                    int ukuran;

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
      
                    switch (pilihTampil)
                    {    
                      // Pilih cetak Array1D
                      case '1':
                      {
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
                               data >> buffer.tahunTerbit >> buffer.stok)
                        {
                          bacaBuku.push_back(buffer);
                        }
                        data.close();
        
                        // resize ukuran array
                        arrBuku.resize(bacaBuku.size());
        
                        // isi array dari vector
                        for (int a = 0; a < arrBuku.getUkuran(); a++)
                        {
                          arrBuku[a].setJudul(bacaBuku.at(a).judul.c_str());
                          arrBuku[a].setPenulis(bacaBuku.at(a).penulis.c_str());
                          arrBuku[a].setTahunTerbit(bacaBuku.at(a).tahunTerbit);
                          arrBuku[a].setStok(bacaBuku.at(a).stok);
                        }
        
                        // cetak value array
                        for (int a = 0; a < arrBuku.getUkuran(); a++)
                        {
                          if (a + 1 < 10) 
                          {
                            table << a + 1;
                          }
                          else if (a + 1 >= 10 && a + 1 < 100)
                          {
                            table << a + 1;
                          }
                          table<<arrBuku[a].getJudul();
                          table<<arrBuku[a].getPenulis();
                          table<<arrBuku[a].getTahunTerbit();
                          table<<arrBuku[a].getStok();
                          table << fort::endr;
                        }
                        table.column(3).set_cell_text_align(fort::text_align::center);
                        table.column(4).set_cell_text_align(fort::text_align::center);
                        std::cout<<table.to_string() << std::endl;
                        
                        ukuran = bacaBuku.size();
                        break;
                      }
        
                      // Pilih cetak single linked list
                      case '2': 
                      {
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
                               data >> buffer.tahunTerbit >> buffer.stok) 
                        {
                          bacaBuku.push_back(buffer);
                        }
                        data.close();
        
                        // isi node
                        for (int a = 0; a < bacaBuku.size(); a++)
                        {
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
                      case '3':
                      {    
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
                               data >> buffer.tahunTerbit >> buffer.stok)
                        {
                          bacaBuku.push_back(buffer);
                        }
                        data.close();
        
                        // isi node
                        for (int a = 0; a < bacaBuku.size(); a++)
                        {
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
  
                      default:
                      {
                        std::cout << "Pilihan tidak tersedia" << std::endl;                      
                      }
                      
                    }
      
                    // menu sortir (admin)
                    std::cout << std::endl;
                    garis2(37);
                    std::cout << "|>>           Sorting?            <<|";
                    std::cout << std::endl;
                    garis2(37);
                    std::cout << "|>>       1. Judul Asc            <<|";
                    std::cout << std::endl;
                    garis2(37);
                    std::cout << "|>>       2. Judul Desc           <<|";
                    std::cout << std::endl;
                    garis2(37);
                    std::cout << "|>>       3. Penulis Asc          <<|";
                    std::cout << std::endl;
                    garis2(37);
                    std::cout << "|>>       4. Penulis Desc         <<|";
                    std::cout << std::endl;
                    garis2(37);
                    std::cout << "|>>       5. Tahun Terbit Asc     <<|";
                    std::cout << std::endl;
                    garis2(37);
                    std::cout << "|>>       6. Tahun Terbit Desc    <<|";
                    std::cout << std::endl;
                    garis2(37);
                    std::cout << "|>>       7. Stok Asc             <<|";
                    std::cout << std::endl;
                    garis2(37);
                    std::cout << "|>>       8. Stok Desc            <<|";
                    std::cout << std::endl;
                    garis2(37);
                    
                    std::cout << "Pilih : ";
                    std::cin >> pilihSorting;
                    std::cout << std::endl;
                    
                    switch (pilihSorting) 
                    {
      
                      // sortir judul (naik)
                      case '1': 
                      {
                        // variabel yang dibutuhkan
                        std::fstream data;
                        std::vector<bukuTemp> hasilSort;
                        bukuTemp buffer;

                        //konversi ke tabel
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
                               data >> buffer.tahunTerbit >> buffer.stok)
                        {
                          hasilSort.push_back(buffer);
                        }
                        data.close();
        
                        // sortir berdasarkan judul (naik)
                        std::stable_sort(hasilSort.begin(), 
                                         hasilSort.end(), 
                                         judulAsc);
        
                        // cetak hasil sortir
                        for (int a = 0; a < hasilSort.size(); a++)
                        {
                          if (a + 1 < 10)
                          {
                            table << a + 1;
                          } 
                          else if (a + 1 >= 10 && a + 1 < 100)
                          {
                            table << a + 1;
                          }
                          table<<hasilSort.at(a).judul;
                          table<<hasilSort.at(a).penulis;
                          table<<hasilSort.at(a).tahunTerbit;
                          table<<hasilSort.at(a).stok;
                          table << fort::endr;
                        }
                        
                        //cetak tabel
                        table.column(3).set_cell_text_align(fort::text_align::center);
                        table.column(4).set_cell_text_align(fort::text_align::center);
                        std::cout<<table.to_string() << std::endl;
        
                        // pesan
                        std::cout << "Sorting Berhasil" << std::endl;
                        break;
                      }
        
                      // sortir judul (turun)
                      case '2': 
                      {    
                        // variabel yang dibutuhkan
                        std::fstream data;
                        std::vector<bukuTemp> hasilSort;
                        bukuTemp buffer;

                        //konversi ke tabel
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
                               data >> buffer.tahunTerbit >> buffer.stok)
                        {
                          hasilSort.push_back(buffer);
                        }
                        data.close();
        
                        // sortir berdasarkan judul (naik)
                        std::stable_sort(hasilSort.begin(),
                                         hasilSort.end(),
                                         judulDesc);
        
                        // cetak hasil sortir
                        for (int a = 0; a < hasilSort.size(); a++)
                        {
                          if (a + 1 < 10)
                          {
                            table << a + 1;
                          } 
                          else if (a + 1 >= 10 && a + 1 < 100)
                          {
                            table << a + 1;
                          }
                          table<<hasilSort.at(a).judul;
                          table<<hasilSort.at(a).penulis;
                          table<<hasilSort.at(a).tahunTerbit;
                          table<<hasilSort.at(a).stok;
                          table << fort::endr;
                        }

                        //cetak tabel
                        table.column(3).set_cell_text_align(fort::text_align::center);
                        table.column(4).set_cell_text_align(fort::text_align::center);
                        std::cout<<table.to_string() << std::endl;
                        
                        // pesan
                        std::cout << "Sorting Berhasil" << std::endl;
                        break;
                      }
        
                      // sortir penulis (naik)
                      case '3': 
                      {    
                        // variabel yang dibutuhkan
                        std::fstream data;
                        std::vector<bukuTemp> hasilSort;
                        bukuTemp buffer;
                        
                        //konversi ke tabel
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
                               data >> buffer.tahunTerbit >> buffer.stok)
                        {
                          hasilSort.push_back(buffer);
                        }
                        data.close();
        
                        // sortir berdasarkan judul (naik)
                        std::stable_sort(hasilSort.begin(), 
                                         hasilSort.end(),
                                         penulisAsc);
        
                        // cetak hasil sortir
                        for (int a = 0; a < hasilSort.size(); a++)
                        {
                          if (a + 1 < 10)
                          {
                            table << a + 1;
                          } 
                          else if (a + 1 >= 10 && a + 1 < 100)
                          {
                            table << a + 1;
                          }
                          table<<hasilSort.at(a).judul;
                          table<<hasilSort.at(a).penulis;
                          table<<hasilSort.at(a).tahunTerbit;
                          table<<hasilSort.at(a).stok;
                          table << fort::endr;
                        }

                        //cetak tabel
                        table.column(3).set_cell_text_align(fort::text_align::center);
                        table.column(4).set_cell_text_align(fort::text_align::center);
                        std::cout<<table.to_string() << std::endl;
        
                        // pesan
                        std::cout << "Sorting Berhasil" << std::endl;
                        break;
                      }
        
                      // sortir penulis (turun)
                      case '4':
                      {
        
                        // variabel yang dibutuhkan
                        std::fstream data;
                        std::vector<bukuTemp> hasilSort;
                        bukuTemp buffer;

                        //konversi ke tabel
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
                               data >> buffer.tahunTerbit >> buffer.stok)
                        {
                          hasilSort.push_back(buffer);
                        }
                        data.close();
        
                        // sortir berdasarkan judul (naik)
                        std::stable_sort(hasilSort.begin(),
                                         hasilSort.end(),
                                         penulisDesc);
        
                        // cetak hasil sortir
                        for (int a = 0; a < hasilSort.size(); a++)
                        {
                          if (a + 1 < 10)
                          {
                            table << a + 1;
                          } 
                          else if (a + 1 >= 10 && a + 1 < 100)
                          {
                            table << a + 1;
                          }
                          table<<hasilSort.at(a).judul;
                          table<<hasilSort.at(a).penulis;
                          table<<hasilSort.at(a).tahunTerbit;
                          table<<hasilSort.at(a).stok;
                          table << fort::endr;
                        }

                        //cetak tabel
                        table.column(3).set_cell_text_align(fort::text_align::center);
                        table.column(4).set_cell_text_align(fort::text_align::center);
                        std::cout<<table.to_string() << std::endl;
        
                        // pesan
                        std::cout << "Sorting Berhasil" << std::endl;
                        break;
                      }
        
                      // sort tahun terbit (naik)
                      case '5':
                      {    
                        // variabel yang dibutuhkan
                        std::fstream data;
                        std::vector<bukuTemp> hasilSort;
                        bukuTemp buffer;

                        //konversi ke tabel
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
                               data >> buffer.tahunTerbit >> buffer.stok)
                        {
                          hasilSort.push_back(buffer);
                        }
                        data.close();
        
                        // sortir berdasarkan judul (naik)
                        std::stable_sort(hasilSort.begin(), hasilSort.end(),
                                         tahunTerbitAsc);
        
                        // cetak hasil sortir
                        for (int a = 0; a < hasilSort.size(); a++)
                        {
                          if (a + 1 < 10)
                          {
                            table << a + 1;
                          } 
                          else if (a + 1 >= 10 && a + 1 < 100)
                          {
                            table << a + 1;
                          }
                          table<<hasilSort.at(a).judul;
                          table<<hasilSort.at(a).penulis;
                          table<<hasilSort.at(a).tahunTerbit;
                          table<<hasilSort.at(a).stok;
                          table << fort::endr;
                        }

                        //cetak tabel
                        table.column(3).set_cell_text_align(fort::text_align::center);
                        table.column(4).set_cell_text_align(fort::text_align::center);
                        std::cout<<table.to_string() << std::endl;
        
                        // pesan
                        std::cout << "Sorting Berhasil" << std::endl;
                        break;
                      }
        
                      // sortir tahun terbit (turun)
                      case '6':
                      {    
                        // variabel yang dibutuhkan
                        std::fstream data;
                        std::vector<bukuTemp> hasilSort;
                        bukuTemp buffer;

                        //konversi ke tabel
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
                               data >> buffer.tahunTerbit >> buffer.stok)
                        {
                          hasilSort.push_back(buffer);
                        }
                        data.close();
        
                        // sortir berdasarkan judul (naik)
                        std::stable_sort(hasilSort.begin(), 
                                         hasilSort.end(),
                                         tahunTerbitDesc);
        
                        // cetak hasil sortir
                        for (int a = 0; a < hasilSort.size(); a++)
                        {
                          if (a + 1 < 10)
                          {
                            table << a + 1;
                          } 
                          else if (a + 1 >= 10 && a + 1 < 100)
                          {
                            table << a + 1;
                          }
                          table<<hasilSort.at(a).judul;
                          table<<hasilSort.at(a).penulis;
                          table<<hasilSort.at(a).tahunTerbit;
                          table<<hasilSort.at(a).stok;
                          table << fort::endr;
                        }

                        //cetak tabel
                        table.column(3).set_cell_text_align(fort::text_align::center);
                        table.column(4).set_cell_text_align(fort::text_align::center);
                        std::cout<<table.to_string() << std::endl;
        
                        // pesan
                        std::cout << "Sorting Berhasil" << std::endl;
                        break;
                      }
        
                      // sortir stok (naik)
                      case '7':
                      {
        
                        // variabel yang dibutuhkan
                        std::fstream data;
                        std::vector<bukuTemp> hasilSort;
                        bukuTemp buffer;

                        //konversi ke tabel
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
                               data >> buffer.tahunTerbit >> buffer.stok) 
                        {
                          hasilSort.push_back(buffer);
                        }
                        data.close();
        
                        // sortir berdasarkan judul (naik)
                        std::stable_sort(hasilSort.begin(),
                                         hasilSort.end(), 
                                         stokAsc);
        
                        // cetak hasil sortir
                        for (int a = 0; a < hasilSort.size(); a++)
                        {
                          if (a + 1 < 10)
                          {
                            table << a + 1;
                          } 
                          else if (a + 1 >= 10 && a + 1 < 100)
                          {
                            table << a + 1;
                          }
                          table<<hasilSort.at(a).judul;
                          table<<hasilSort.at(a).penulis;
                          table<<hasilSort.at(a).tahunTerbit;
                          table<<hasilSort.at(a).stok;
                          table << fort::endr;
                        }

                        //cetak tabel
                        table.column(3).set_cell_text_align(fort::text_align::center);
                        table.column(4).set_cell_text_align(fort::text_align::center);
                        std::cout<<table.to_string() << std::endl;
        
                        // pesan
                        std::cout << "Sorting Berhasil" << std::endl;
                        break;
                      }
        
                      // sortir stok (turun)
                      case '8':
                      {
                        // variabel yang dibutuhkan
                        std::fstream data;
                        std::vector<bukuTemp> hasilSort;
                        bukuTemp buffer;

                        //konversi ke tabel
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
                               data >> buffer.tahunTerbit >> buffer.stok)
                        {
                          hasilSort.push_back(buffer);
                        }
                        data.close();
        
                        // sortir berdasarkan judul (naik)
                        std::stable_sort(hasilSort.begin(), hasilSort.end(), stokDesc);
        
                        // cetak hasil sortir
                        for (int a = 0; a < hasilSort.size(); a++)
                        {
                          if (a + 1 < 10)
                          {
                            table << a + 1;
                          } 
                          else if (a + 1 >= 10 && a + 1 < 100)
                          {
                            table << a + 1;
                          }
                          table<<hasilSort.at(a).judul;
                          table<<hasilSort.at(a).penulis;
                          table<<hasilSort.at(a).tahunTerbit;
                          table<<hasilSort.at(a).stok;
                          table << fort::endr;
                        }

                        //cetak tabel
                        table.column(3).set_cell_text_align(fort::text_align::center);
                        table.column(4).set_cell_text_align(fort::text_align::center);
                        std::cout<<table.to_string() << std::endl;
        
                        // pesan
                        std::cout << "Sorting Berhasil" << std::endl;
                        break;
                      }
                    
                      default:
                      {
                        std::cout << "Pilihan tidak tersedia" << std::endl;
                      }
                    }
                    
                    std::cout << "Input apa saja untuk melanjutkan... ";
                    std::cin >> isPause;
                    break;
                  }

                  //pilih cari buku
                  case '5':
                  {
                    system("clear");
                    std::string cari;
                    std::vector<bukuTemp> bacaBuku;
                    std::fstream data;
                    bukuTemp buffer;
                    bacaBuku.clear();
                    data.open("Buku.txt");
                    while (std::getline(data, buffer.judul, ';') &&
                           std::getline(data, buffer.penulis, ';') &&
                           data >> buffer.tahunTerbit >> buffer.stok)
                    {
                      bacaBuku.push_back(buffer);
                    }                    
                    data.close();

                    std::cout << "Cari Buku : ";
                    std::cin>>cari;

                    for(int a = 0; a < bacaBuku.size(); a++){
                      if(bacaBuku.at(a).judul.find(cari) != std::string::npos || bacaBuku.at(a).penulis.find(cari) != std::string::npos){
                        std::cout<<bacaBuku.at(a).judul<<" "<<bacaBuku.at(a).penulis<<std::endl;
                      }
                    }
                    
                    //hold a second
                    std::cout << "Input apa saja untuk melanjutkan... ";
                    std::cin >> isPause;
                    break;
                  }
                  // Ke luar dari menu admin
                  case '6':
                  {
                    break;
                  }
                  
                  default:
                  {
                    std::cout << "Pilihan tidak tersedia" << std::endl;                      
                  }
                  
                }
              }
            }
            break;
          }
    
          // Login sebagai user
          case '2': 
          {
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
            if (data.is_open()) 
            {
              isLogin = true;
            }
            data.close();
    
            // Cek NIK dan Password user hasil register
            if (isLogin == true && password == bufferPassword) 
            {
              // variabel yang dibutuhkan
              char menuUser;
    
              while (menuUser != '5') 
              {
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
                std::cout << "|>>    4. Transaksi               <<|";
                std::cout << std::endl;
                garis2(37);
                std::cout << "|>>    5. Ke luar                 <<|";
                std::cout << std::endl;
                garis(37);
                std::cout << "Pilih : ";
    
                std::cin >> menuUser;
    
                switch (menuUser) 
                {
                  // pilih tampil daftar buku
                  case '1':
                  {
                    system("clear");
                    
                    // variabel yang dibutuhkan untuk mencetak daftar buku
                    char pilihTampil;

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
      
                    switch (pilihTampil)
                    {
                      // pilih array1d dinamis
                      case '1': 
                      {
                        // variabel yang dibutuhkan ketika mencetak dengan array1d dinamis
                        std::fstream data;
                        std::vector<bukuTemp> bacaBuku;
                        bukuTemp buffer;

                        //bikin tabel
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
                               data >> buffer.tahunTerbit >> buffer.stok) 
                        {
                          bacaBuku.push_back(buffer);
                        }
                        data.close();
        
                        // resize ukuran array
                        arrBuku.resize(bacaBuku.size());
        
                        // isi array dari vector
                        for (int a = 0; a < arrBuku.getUkuran(); a++) 
                        {
                          arrBuku[a].setJudul(bacaBuku.at(a).judul.c_str());
                          arrBuku[a].setPenulis(bacaBuku.at(a).penulis.c_str());
                          arrBuku[a].setTahunTerbit(bacaBuku.at(a).tahunTerbit);
                          arrBuku[a].setStok(bacaBuku.at(a).stok);
                        }
        
                        // cetak value array
                        for (int a = 0; a < arrBuku.getUkuran(); a++)
                        {
                          if (a + 1 < 10) 
                          {
                            table << a + 1;
                          }
                          else if (a + 1 >= 10 && a + 1 < 100)
                          {
                            table << a + 1;
                          }
                          table<<arrBuku[a].getJudul();
                          table<<arrBuku[a].getPenulis();
                          table<<arrBuku[a].getTahunTerbit();
                          table<<arrBuku[a].getStok();
                          table << fort::endr;
                        }
                        table.column(3).set_cell_text_align(fort::text_align::center);
                        table.column(4).set_cell_text_align(fort::text_align::center);
                        std::cout<<table.to_string() << std::endl;
                        
                        //hold a second
                        std::cout << "Input apa saja untuk melanjutkan... ";
                        std::cin >> isPause;
                        break;
                      }
        
                      // pilih single linked list
                      case '2': 
                      {        
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
                               data >> buffer.tahunTerbit >> buffer.stok) 
                        {
                          bacaBuku.push_back(buffer);
                        }
                        data.close();
        
                        // isi node
                        for (int a = 0; a < bacaBuku.size(); a++) 
                        {
                          temp.setJudul(bacaBuku.at(a).judul.c_str());
                          temp.setPenulis(bacaBuku.at(a).penulis.c_str());
                          temp.setTahunTerbit(bacaBuku.at(a).tahunTerbit);
                          temp.setStok(bacaBuku.at(a).stok);
                          listBuku.tambahDepan(temp);
                        }
        
                        // cetak Single Linked List
                        listBuku.display();

                        //hold a second
                        std::cout << "Input apa saja untuk melanjutkan... ";
                        std::cin >> isPause;
                        break;
                      }
        
                      // pilih doubly linked list
                      case '3': 
                      {        
                        // variabel yang dibutuhkan untuk mencetak daftar buku dengan dll
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
                               data >> buffer.tahunTerbit >> buffer.stok) 
                        {
                          bacaBuku.push_back(buffer);
                        }
                        data.close();
        
                        // isi node
                        listBuku.clearList();
                        for (int a = 0; a < bacaBuku.size(); a++) 
                        {
                          temp.setJudul(bacaBuku.at(a).judul.c_str());
                          temp.setPenulis(bacaBuku.at(a).penulis.c_str());
                          temp.setTahunTerbit(bacaBuku.at(a).tahunTerbit);
                          temp.setStok(bacaBuku.at(a).stok);
                          listBuku.tambahBelakang(temp);
                        }
        
                        // cetak double linked list
                        listBuku.cetakMaju();

                        //hold a second
                        std::cout << "Input apa saja untuk melanjutkan... ";
                        std::cin >> isPause;
                        break;
                      }

                      default:
                      {
                        std::cout << "Pilihan tidak tersedia" << std::endl;
                      }
                    }
                    break;
                  }
    
                  // pilih pinjam buku
                  case '2': 
                  {
                    system("clear");
                    // variabel yang dibutuhkan untuk meminjam buku
                    std::vector<bukuTemp> bacaBuku;
                    std::vector<bukuTemp> maksBuku;
                    std::fstream data;
                    int pilihBuku;
                    bukuTemp buffer;
                    Buku keStack;
                    
                    garis(37);
                    std::cout << "|>>       Menu Pinjam Buku        <<|";
                    std::cout << std::endl;
                    garis(37);
      
                    // clear list sebelumnya (jika ada) kemudian baca
                    bacaBuku.clear();
                    data.open("Buku.txt");
                    while (std::getline(data, buffer.judul, ';') &&
                           std::getline(data, buffer.penulis, ';') &&
                           data >> buffer.tahunTerbit >> buffer.stok) 
                    {
                      bacaBuku.push_back(buffer);
                    }
                    data.close();
      
                    //pengecekan maksimal buku
                    maksBuku.clear();
                    data.open("user/" + id + "_keranjang.txt", std::ios::in);
                    while (std::getline(data, buffer.judul, ';') &&
                           std::getline(data, buffer.penulis, ';') &&
                           data >> buffer.tahunTerbit >> buffer.stok) 
                    {
                      maksBuku.push_back(buffer);
                    }
                    data.close();
                    
                    // input user memilih buku yang ingin dipinjam
                    std::cout << "Pilih Buku yang ingin dipinjam : ";
                    std::cin >> pilihBuku;

                    if(pilihBuku - 1 < 0 || pilihBuku - 1 > bacaBuku.size())
                    {
                      std::cout << "Buku tidak tersedia " << std::endl;
                      exit(1);
                    }
      
                    // simpan hasil pilih user sementara ke buffer
                    buffer.judul = bacaBuku.at(pilihBuku - 1).judul;
                    buffer.penulis = bacaBuku.at(pilihBuku - 1).penulis;
                    buffer.tahunTerbit = bacaBuku.at(pilihBuku - 1).tahunTerbit;
                    buffer.stok = bacaBuku.at(pilihBuku - 1).stok;
      
                    if (maksBuku.size() != 3) 
                    {
      
                      // masukkan ke buku untuk stack
                      keStack.setJudul(bacaBuku.at(pilihBuku - 1).judul.c_str());
                      keStack.setPenulis(bacaBuku.at(pilihBuku - 1).penulis.c_str());
                      keStack.setTahunTerbit(bacaBuku.at(pilihBuku - 1).tahunTerbit);
                      keStack.setStok(bacaBuku.at(pilihBuku - 1).stok);
      
                      // push ke stack
                      stackBuku.push(keStack);
      
                      // tulis ke database user yang login
                      data.open("user/" + id + "_keranjang.txt",
                                std::ios::out | std::ios::app);
                      data << buffer.judul;
                      data << ";" << buffer.penulis;
                      data << ";" << buffer.tahunTerbit;
                      data << " " << buffer.stok;
                      data.close();

                      //pesan
                      garis2(37);
                      std::cout << std::endl;
                      std::cout << "|>>   Buku Berhasil ditambahkan   <<|";
                      std::cout << std::endl;
                      std::cout << std::endl;
                      garis2(37);
                    }
                    else
                    {
                      std::cout << std::endl;
                      std::cout << "!!!Maksimal buku yang dipinjam adalah 3!!!";
                      std::cout << std::endl;
                      std::cout << std::endl;
                    }

                    //hold a second
                    std::cout << "Input apa saja untuk melanjutkan... ";
                    std::cin >> isPause;
                    break;
                  }
    
                  // pilih lihat list buku yang sudah dipilih
                  case '3': 
                  {
                    // variabel yang dibutuhkan untuk melihat list buku
                    bukuTemp buffer;
                    std::vector<Buku> listPinjam;

                    //bikin tabel
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
                    if (!data.is_open()) 
                    {
                      std::cout << "!!! Keranjang kosong !!!" << std::endl;
                      exit(1);
                    }
                    
                    while (std::getline(data, buffer.judul, ';') &&
                           std::getline(data, buffer.penulis, ';') &&
                           data >> buffer.tahunTerbit >> buffer.stok) 
                    {
                      keranjang.push_back(buffer);
                    }
                    data.close();
      
                    // cetak yang dipilih user
                    for (int a = 0; a < keranjang.size(); a++) 
                    {
                      if (a + 1 < 10) 
                      {
                        table << a + 1;
                      } 
                      else if (a + 1 >= 10 && a + 1 < 100) 
                      {
                        table << a + 1;
                      }
                      table << keranjang.at(a).judul;
                      table << fort::endr;
                    }
                    std::cout<<table.to_string() << std::endl;
                    //hold a second
                    std::cout << "Input apa saja untuk melanjutkan... ";
                    std::cin >> isPause;
                    break;
                  }
    
                  // pilih transaksi
                  case '4': 
                  {
                    system("clear");
                    
                    // variabel yang dibutuhkan untuk transaksi
                    bukuTemp bufferBuku;
                    std::vector<bukuTemp> invoice;
                    std::ifstream baca;
                    std::string buffer[20];
                    std::string isBenarUser, isBenarPassword;
                    fort::char_table table;
                    Dimas _157;

                    garis(37);
                    std::cout << "|>>        Menu Transaksi         <<|";
                    std::cout << std::endl;
                    garis(37);
                    std::cout << std::endl;

                    table << fort::header << "   !!! Konfirmasi Identitas !!!   ";
                    table << fort::endr;
                    std::cout << table.to_string() << std::endl;
      
                    // baca data ktp untuk identitas pada invoice
                    baca.open("dataKTP/" + id + ".txt");
                    while (std::getline(baca, buffer[0], ',') &&
                           std::getline(baca, buffer[1], ',') &&
                           std::getline(baca, buffer[2], ',') &&
                           std::getline(baca, buffer[3], ',') &&
                           std::getline(baca, buffer[4], ',') &&
                           std::getline(baca, buffer[5], ',') &&
                           std::getline(baca, buffer[6], ',') &&
                           std::getline(baca, buffer[7], ',') &&
                           std::getline(baca, buffer[8], ',') &&
                           std::getline(baca, buffer[9], ',') &&
                           std::getline(baca, buffer[10], ',') &&
                           std::getline(baca, buffer[11], ',') &&
                           std::getline(baca, buffer[12], ',') &&
                           std::getline(baca, buffer[13], ',') &&
                           std::getline(baca, buffer[14], ',') &&
                           std::getline(baca, buffer[15], ',') &&
                           std::getline(baca, buffer[16], ',') &&
                           std::getline(baca, buffer[17], ',') &&
                           std::getline(baca, buffer[18], ',') &&
                           std::getline(baca, buffer[19], ','));
                    baca.close();
      
                    // cek apakah keranjang kosong dan memasukkannya ke vector
                    baca.open("user/" + id + "_keranjang.txt", std::ios::in);
                    if (!baca.is_open()) 
                    {
                      std::cout << "Keranjang kosong" << std::endl;
                      exit(1);
                    }
                    while (std::getline(baca, bufferBuku.judul, ';') &&
                           std::getline(baca, bufferBuku.penulis, ';') &&
                           baca >> bufferBuku.tahunTerbit >> bufferBuku.stok) 
                    {
                      invoice.push_back(bufferBuku);
                    }
                    baca.close();
                    
                    std::cout << "Username : ";
                    std::cin >> isBenarUser;
                    std::cout << "Password : ";
                    std::cin >> isBenarPassword;
      
                    // cek apakah yang pinjam adalah yang login
                    if (isBenarUser == id && isBenarPassword == bufferPassword) 
                    {
                      fort::char_table table2;
                      table2 << fort::header << "    !!! Transaksi Berhasil !!!    ";
                      table2 << fort::endr;
                      std::cout << table2.to_string() << std::endl;
                      std::cout << "Kembalikan tanggal : " << __DATE__;
                      std::cout << std::endl;
                      // isi invoice
                      _157.invoice2(waktuSekarang->tm_mday, 
                                    1 + waktuSekarang->tm_mon, 
                                    1900 + waktuSekarang->tm_year, 
                                    buffer[3], 
                                    buffer[10], 
                                    buffer[1], 
                                    invoice);
                    }
      
                    
                    //hold a second
                    std::cout << "Input apa saja untuk melanjutkan... ";
                    std::cin >> isPause;
                    break;
                  }
    
                  // ke luar dari menu
                  case '5': 
                  {
                    break;
                  }
                  default:
                    std::cout << "Pilihan tidak tersedia" << std::endl;
                }
              }
            }
            break;
          }
          default:
            std::cout << "Pilihan tidak tersedia" << std::endl;
        }
        break;
      }
  
      // Daftar akun
      case '2': 
      {
        isMenuUtama = true;
        // variabel yang dibutuhkan memilih menu
        char pilihDaftar;
  
        // input user untuk memilih tipe akun
        std::cout << "Daftar sebagai : " << std::endl;
        std::cout << "1. Admin" << std::endl;
        std::cout << "2. Pengguna" << std::endl;
        std::cout << "Pilih : ";
  
        std::cin >> pilihDaftar;
  
        switch (pilihDaftar)
        {
  
          // Sebagai admin
          case '1': 
          {    
            // variabel yang dibutuhkan untuk daftar akun (admin)
            std::fstream data;
            std::string nik;
            std::string password;
    
            std::cout << "Masukkan NIK : ";
            std::cin >> nik;
    
            // cek apakah nik terdaftar di sistem
            data.open("dataKTP/" + nik + ".txt", std::ios::in);
            if (!data.is_open())
            {
              std::cout << "NIK Tidak terdaftar" << std::endl;
            }
            else
            {
              std::cout << "Masukkan password : ";
              std::cin >> password;
            }
            data.close();
    
            // tulis password yang telah diregister
            data.open("admin/" + nik + ".txt", std::ios::out | std::ios::trunc);
            data << password;
            data.close();
            break;
          }
    
          // Sebagai pengguna
          case '2':
          {    
            // variabel yang dibutuhkan untuk daftar akun (pengguna)
            std::fstream data;
            std::string nik;
            std::string password;
    
            std::cout << "Masukkan NIK : ";
            std::cin >> nik;
    
            // cek apakah nik terdaftar di sistem
            data.open("dataKTP/" + nik + ".txt", std::ios::in);
            if (!data.is_open())
            {
              std::cout << "NIK Tidak terdaftar" << std::endl;
            }
            else
            {
              std::cout << "Masukkan password : ";
              std::cin >> password;
            }
            data.close();
    
            // tulis password yang diregister
            data.open("user/" + nik + ".txt", std::ios::out | std::ios::trunc);
            data << password;
            data.close();
            break;
          }
        }
        break;
      }
  
      // pilih input ktp
      case '3': 
      {
        isMenuUtama = true;
        Sena _152;
        _152.inputKTP();
        break;
      }
  
      // pilih exit
      case '4': 
      {
        isMenuUtama = false;
        break;
      }
      default:
      {
        isMenuUtama = true;
        std::cout << "Pilihan tidak tersedia" << std::endl;        
      }
    }
  } while (isMenuUtama == true);
  // }
  
  return 0;
}

void garis(int x) 
{
  if (x > 0) 
  {
    std::cout << "=";
    garis(x - 1);
  } 
  else 
  {
    std::cout << std::endl;
    return;
  }
}

void garis2(int x)
{
  if (x > 0) 
  {
    std::cout << "-";
    garis2(x - 1);
  } 
  else 
  {
    std::cout << std::endl;
    return;
  }
}