#ifndef __Fajar
#define __Fajar
#include <iostream>
#include "class/fort.hpp"

// Pertemuan 1 : struct
struct bukuTemp 
{
  std::string judul;
  std::string penulis;
  int tahunTerbit;
  short stok;
};

class Fajar{
  public:
    void searchBuku(std::vector<bukuTemp> &bacaBuku,
                    std::fstream &data,
                    bukuTemp &buffer,
                    std::string &cari) {
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
    }
    void filterBuku(std::vector<bukuTemp> &bacaBuku, 
                    std::fstream &data, 
                    bukuTemp &buffer, 
                    char &pilih) {
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
      fort::char_table table;
      table.set_border_style(FT_SOLID_ROUND_STYLE);
      table << fort::header << "Menu Filter Buku" << fort::endr;
      table.row(0).set_cell_min_width(30);
      table.row(0).set_cell_text_align(fort::text_align::center);
      table.row(0).set_cell_bg_color(fort::color::red);
      table.row(0).set_cell_content_fg_color(fort::color::cyan);
      std::cout << table.to_string() << std::endl;
      
      garis(37);
      std::cout << "|>>     Filter Buku dengan :      <<|" << std::endl;
      garis(37);
      std::cout << "|>>  1. Judul                     <<|" << std::endl;
      garis2(37);
      std::cout << "|>>  2. Penulis                   <<|" << std::endl;
      garis2(37);
      std::cout << "|>>  3. Tahun Terbit              <<|" << std::endl;
      garis2(37);
      std::cout << "|>>  4. Stok                      <<|" << std::endl;
      garis(37);
      std::cout << "Pilih : ";
      std::cin >> pilih;

      switch(pilih){
        //pilih filter judul
        case '1': {
          fort::char_table table2;
          table2 << "Filter berdasarkan Judul" << fort::endr;
          table2 << fort::separator;
          for(int a = 0; a < bacaBuku.size(); a++){
            table2 << a + 1 << bacaBuku.at(a).judul << fort::endr;
          }
          table2[0][0].set_cell_span(2);
          table2.row(0).set_cell_text_align(fort::text_align::center);
          table2.set_border_style(FT_NICE_STYLE);
          std::cout << table2.to_string() << std::endl;
          break;
        }

        //pilih filter penulis
        case '2': {
          fort::char_table table2;
          table2 << "Filter berdasarkan Penulis" << fort::endr;
          table2 << fort::separator;
          for(int a = 0; a < bacaBuku.size(); a++){
            table2 << a + 1 << bacaBuku.at(a).penulis << fort::endr;
          }
          table2[0][0].set_cell_span(2);
          table2.row(0).set_cell_text_align(fort::text_align::center);
          table2.set_border_style(FT_NICE_STYLE);
          std::cout << table2.to_string() << std::endl;
          break;
        }

        //pilih filter tahun terbit
        case '3': {
          fort::char_table table2;
          table2 << "Filter berdasarkan Tahun Terbit" << fort::endr;
          table2 << fort::separator;
          for(int a = 0; a < bacaBuku.size(); a++){
            table2 << a + 1 << bacaBuku.at(a).tahunTerbit << fort::endr;
          }
          table2[0][0].set_cell_span(2);
          table2.row(0).set_cell_text_align(fort::text_align::center);
          table2.set_border_style(FT_NICE_STYLE);
          std::cout << table2.to_string() << std::endl;
          break;
        }

        //pilih filter stok
        case '4': {
          fort::char_table table2;
          table2 << "Filter berdasarkan Stok" << fort::endr;
          table2 << fort::separator;
          for(int a = 0; a < bacaBuku.size(); a++){
            table2 << a + 1 << bacaBuku.at(a).stok << fort::endr;
          }
          table2[0][0].set_cell_span(2);
          table2.row(0).set_cell_text_align(fort::text_align::center);
          table2.set_border_style(FT_NICE_STYLE);
          std::cout << table2.to_string() << std::endl;
          break;
        }
      }
    }
    void ekstrakBuku(std::vector<bukuTemp> &bacaBuku, 
                     std::fstream &data, 
                     bukuTemp &buffer, 
                     int &pilih, 
                     std::string &id){
      // baca database buku
      data.open("Buku.txt", std::ios::in);
      while(std::getline(data, buffer.judul, ';') &&
                std::getline(data, buffer.penulis, ';') &&
                data >> buffer.tahunTerbit >> buffer.stok) {
        bacaBuku.push_back(buffer);
      }
      data.close();
      
      // bikin tabel
      fort::char_table table;
      table.set_border_style(FT_SOLID_ROUND_STYLE);
      table << fort::header << "Menu Ekstrak Informasi Buku";
      table << fort::endr;
      table.row(0).set_cell_min_width(30);
      table.row(0).set_cell_text_align(fort::text_align::center);
      table.row(0).set_cell_bg_color(fort::color::green);
      table.row(0).set_cell_content_fg_color(fort::color::yellow);
      std::cout << table.to_string() << std::endl;

      // pilih buku yang ingin di ekstrak
      std::cout << "Pilih buku yang ingin di ekstrak : ";
      std::cin >> pilih;

      if(pilih - 1 < 0 || pilih - 1 >= bacaBuku.size()){
        std::cout << "Di luar kendali" << std::endl;
        return;
      }

      // tulis informasi ke txt
      data.open("user/" + id + "_ekstrak.txt", std::ios::out);
      data << bacaBuku.at(pilih - 1).judul << ";";
      data << bacaBuku.at(pilih - 1).penulis << ";";
      data << bacaBuku.at(pilih - 1).tahunTerbit << " ";
      data << bacaBuku.at(pilih - 1).stok;
      data.close();

      // pesan
      std::cout << "!!! Berhasil di ekstrak !!!" << std::endl;
    }
};

class Antrian{
public:
  std::string noAntrian;
  std::string id;
};

//ketentuan judul naik
bool judulAsc(const bukuTemp &, const bukuTemp &);
//ketentuan judul turun
bool judulDesc(const bukuTemp &, const bukuTemp &);
//ketentuan penulis naik
bool penulisAsc(const bukuTemp &, const bukuTemp &);
//ketentuan penulis turun
bool penulisDesc(const bukuTemp &, const bukuTemp &);
//ketentuan tahun terbit naik
bool tahunTerbitAsc(const bukuTemp &, const bukuTemp &);
//ketentuan tahun terbit turun
bool tahunTerbitDesc(const bukuTemp &, const bukuTemp &);
//ketentuan stok naik
bool stokAsc(const bukuTemp &, const bukuTemp &);
//ketentuan stok turun
bool stokDesc(const bukuTemp &, const bukuTemp &);

//ketentuan judul naik
bool judulAsc(const bukuTemp &a, const bukuTemp &b)
{
  return a.judul < b.judul;
}

//ketentuan judul turun
bool judulDesc(const bukuTemp &a, const bukuTemp &b)
{
  return a.judul > b.judul;
}

//ketentuan penulis naik
bool penulisAsc(const bukuTemp &a, const bukuTemp &b)
{
  return a.penulis < b.penulis;
}

//ketentuan penulis turun
bool penulisDesc(const bukuTemp &a, const bukuTemp &b)
{
  return a.penulis > b.penulis;
}

//ketentuan tahun terbit naik
bool tahunTerbitAsc(const bukuTemp &a, const bukuTemp &b)
{
  return a.tahunTerbit < b.tahunTerbit;
}

//ketentuan tahun terbit turun
bool tahunTerbitDesc(const bukuTemp &a, const bukuTemp &b)
{
  return a.tahunTerbit > b.tahunTerbit;
}

//ketentuan stok naik
bool stokAsc(const bukuTemp &a, const bukuTemp &b)
{
  return a.stok < b.stok;
}

//ketentuan stok turun
bool stokDesc(const bukuTemp &a, const bukuTemp &b)
{
  return a.stok > b.stok;
}

#endif