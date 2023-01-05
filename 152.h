#ifndef __sena
#define __sena
#include "class/ktp.hpp"
#include "class/fort.hpp"

class Sena{
  public:
    void inputKTP(){
      KTP data;
      while(!data.setProvinsi());
      while(!data.setKabKota());
      while(!data.setNIK());
      data.setNama();
      while(!data.setKelahiran());
      while(!data.setKelamin());
      while(!data.setGolonganDarah());
      while(!data.setAlamat());
      while(!data.setAgama());
      while(!data.setKawin());
      while(!data.setGawe());
      while(!data.setWargaNegara());
      data.setDurasi("SEUMUR HIDUP");
      data.tulisFile();
    }
    void keranjang(std::vector<bukuTemp> &bacaBuku, 
                   std::vector<bukuTemp> &maksBuku, 
                   std::fstream &data, 
                   bukuTemp &buffer, 
                   Buku &keStack, 
                   StackArrayDinamis<Buku> &stackBuku, 
                   std::string &id, 
                   int &pilihBuku) {
      fort::char_table table;
      
      // clear list sebelumnya (jika ada) kemudian baca
      bacaBuku.clear();
      data.open("Buku.txt");
      while (std::getline(data, buffer.judul, ';') &&
             std::getline(data, buffer.penulis, ';') &&
             data >> buffer.tahunTerbit >> buffer.stok) {
        bacaBuku.push_back(buffer);
      }
      data.close();
      
      table << "List Buku" << fort::endr;
      table << fort::separator;
      table << "No";
      table << "Judul";
      table << "Penulis";
      table << "Tahun Terbit";
      table << "Stok" << fort::endr;
      table << fort::separator;

      for(int a = 0; a < bacaBuku.size(); a++){
        table << a + 1;
        table << bacaBuku.at(a).judul;
        table << bacaBuku.at(a).penulis;
        table << bacaBuku.at(a).tahunTerbit;
        table << bacaBuku.at(a).stok << fort::endr;
      }
      
      table[0][0].set_cell_span(5);
      table.row(0).set_cell_text_align(fort::text_align::center);
      table.row(1).set_cell_text_align(fort::text_align::center);
      table.set_border_style(FT_NICE_STYLE);
      
      std::cout << table.to_string() << std::endl;
      
      // pengecekan maksimal buku
      maksBuku.clear();
      data.open("user/" + id + "_keranjang.txt", std::ios::in);
      while (std::getline(data, buffer.judul, ';') &&
             std::getline(data, buffer.penulis, ';') &&
             data >> buffer.tahunTerbit >> buffer.stok) {
        maksBuku.push_back(buffer);
      }
      data.close();

      // input user memilih buku yang ingin dipinjam
      std::cout << "Pilih Buku yang ingin dipinjam : ";
      std::cin >> pilihBuku;

      if (pilihBuku - 1 < 0 || pilihBuku - 1 > bacaBuku.size()) {
        std::cout << "Buku tidak tersedia " << std::endl;
        exit(1);
      }

      // simpan hasil pilih user sementara ke buffer
      buffer.judul = bacaBuku.at(pilihBuku - 1).judul;
      buffer.penulis = bacaBuku.at(pilihBuku - 1).penulis;
      buffer.tahunTerbit = bacaBuku.at(pilihBuku - 1).tahunTerbit;
      buffer.stok = bacaBuku.at(pilihBuku - 1).stok;

      if (maksBuku.size() != 3) {

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

        // pesan
        garis2(37);
        std::cout << "|>>   Buku Berhasil ditambahkan   <<|";
        std::cout << std::endl;
        garis2(37);
      } 
      else {
        std::cout << std::endl;
        std::cout << "!!!Maksimal buku yang dipinjam adalah 3!!!";
        std::cout << std::endl;
        std::cout << std::endl;
      }
    }
    void antrianPeminjam(std::vector<Antrian> &antrianBiasa, 
                         std::vector<Antrian> &antrianPrioritas,
                         std::fstream &data, 
                         Antrian &temp, 
                         QueueDLL<Antrian> &queue,
                         PriorityQueue<Antrian> &pqueue,
                         short &no,
                         short &pilih) {
      bool ketemu = false;
      
      //header
      garis(37);
      std::cout << "|>>   Menu Konfirmasi Transaksi   <<|";
      std::cout << std::endl;
      garis(37);
  
      //baca antrian
      data.open("Transaksi/noAntrian.txt", std::ios::in);
      while(std::getline(data, temp.noAntrian, ';') &&
            std::getline(data, temp.id, ';')){
        queue.enqueue(temp);
        antrianBiasa.push_back(temp);
      }
      data.close();
      
      //baca antrian prioritas
      data.open("Transaksi/noAntrianPrioritas.txt", std::ios::in);
      while(std::getline(data, temp.noAntrian, ';') &&
            std::getline(data, temp.id, ';')){
        pqueue.enqueue(temp, 1);
        antrianPrioritas.push_back(temp);
      }
      data.close();

      pqueue.display();
      queue.display();

      if(!queue.isEmpty() || !pqueue.isEmpty()){
        std::cout << "1. Antrian Prioritas" << std::endl;
        std::cout << "2. Antrian Reguler" << std::endl;
        std::cout << "Pilih : ";
        std::cin >> pilih;
        switch(pilih){
          case 1:
            if(!pqueue.isEmpty()){
              std::cout << "Acc antrian no : ";
              std::cin >> no;
          
              for(int a = 0; a < antrianPrioritas.size(); a++){
                if(no == stoi(antrianPrioritas.at(a).noAntrian)){
                  data.open("Transaksi/" + antrianPrioritas.at(a).id + "_status.txt",
                            std::ios::out);
                  data << "1";
                  data.close();
                  
                  std::cout << "Antrian berhasil diterima" << std::endl;
                  antrianPrioritas.erase(antrianPrioritas.begin() + a);
                  ketemu = true;
      
                  if(antrianPrioritas.size() != 0) {
                  data.open("Transaksi/noAntrianPrioritas.txt", std::ios::out);
                  for(int a = 0; a < antrianPrioritas.size(); a++){
                    data << antrianPrioritas.at(a).noAntrian << ";";
                    data << antrianPrioritas.at(a).id<<";";
                  }
                  data.close();
                  }else{
                    data.open("Transaksi/noAntrianPrioritas.txt", std::ios::out);
                    data << "";
                    data.close();
                  }
                  
                }
              }
      
              if(ketemu == false){
                std::cout << "No Antrian tidak ada" << std::endl;
                return;
              }
            }else{
              std::cout << "Antrian Prioritas Kosong" << std::endl;
            }
            break;
          case 2:
            if(!queue.isEmpty()){
              std::cout << "Acc antrian no : ";
              std::cin >> no;
          
              for(int a = 0; a < antrianBiasa.size(); a++){
                if(no == stoi(antrianBiasa.at(a).noAntrian)){
                  data.open("Transaksi/" + antrianBiasa.at(a).id + "_status.txt",
                            std::ios::out);
                  data << "1";
                  data.close();
                  
                  std::cout << "Antrian berhasil diterima" << std::endl;
                  antrianBiasa.erase(antrianBiasa.begin() + a);
                  ketemu = true;
      
                  if(antrianBiasa.size() != 0){
                  data.open("Transaksi/noAntrian.txt", std::ios::out);
                  for(int a = 0; a < antrianBiasa.size(); a++){
                    data << antrianBiasa.at(a).noAntrian << ";";
                    data << antrianBiasa.at(a).id<<";";
                  }
                  data.close();
                  }else{
                    data.open("Transaksi/noAntrian.txt", std::ios::out);
                    data << "";
                    data.close();
                  }
                }
              }
      
              if(ketemu == false){
                std::cout << "No Antrian tidak ada" << std::endl;
                return;
              }
            }else{
              std::cout << "Antrian Reguler Kosong" << std::endl;
            }
            break;
        }
      }
    }
    void dataAdmin(std::vector<std::string> &semuaNya, 
                   std::fstream &data, 
                   std::string &temp) {
      fort::char_table tabel;
      
      //header
      garis(37);
      std::cout << "|>>       Menu Daftar Admin       <<|";
      std::cout << std::endl;
      garis(37);
      
      //baca database admin
      data.open("admin/dataSemuaAdmin.txt", std::ios::in);
      while(!data.eof()){
        std::getline(data, temp,';');
        semuaNya.push_back(temp);
      }
      data.close();

      //cetak semua nama admin
      tabel << "No" 
            << "Nama User" 
            << fort::endr;
      tabel << fort::separator;
      for(int a = 0; a < semuaNya.size()/20; a++){
        tabel << a + 1 
              << semuaNya.at(3 + (20 * a)) 
              << fort::endr;
      }
      tabel[0][1].set_cell_min_width(30);
      tabel[0][1].set_cell_text_align(fort::text_align::center);
      tabel.set_border_style(FT_DOUBLE_STYLE);
      std::cout << tabel.to_string() << std::endl;
    }
    void hapusBukuKeranjang(std::vector<bukuTemp> &keranjang, std::fstream &data, bukuTemp &buffer, int & pilih, std::string &id){
      // bikin tabel
      fort::char_table table;
      fort::char_table table2;
      table.set_border_style(FT_NICE_STYLE);
      table << fort::header << "No";
      table << "Judul Buku";
      table << fort::endr;
      
      //header
      garis(37);
      std::cout << "|>>      Menu Hapus Buku Saya     <<|";
      std::cout << std::endl;
      garis(37);
      std::cout << std::endl;

      // baca database user yang login
      keranjang.clear();
      data.open("user/" + id + "_keranjang.txt", std::ios::in);
      while (std::getline(data, buffer.judul, ';') &&
             std::getline(data, buffer.penulis, ';') &&
             data >> buffer.tahunTerbit >> buffer.stok) {
        keranjang.push_back(buffer);
      }

      //cek keranjang kosong
      if (!data.is_open() || keranjang.size() == 0) {
        std::cout << "!!! Keranjang kosong !!!" << std::endl;
        return;
      }
      data.close();

      for(int a = 0; a < keranjang.size(); a++){
        table << a + 1 << keranjang.at(a).judul;
        table << fort::endr;
      }

      std::cout << table.to_string() << std::endl;
      
      //pilih buku yang mau dihapus
      std::cout << "Buku yang mau dihapus : ";
      std::cin >> pilih;
      if(pilih - 1 < 0 || pilih - 1 >= keranjang.size()){
        std::cout << "Di luar kendali" << std::endl;
        exit(1);
      }
      table2 << keranjang.at(pilih - 1).judul;

      std::cout << table2.to_string();
      std::cout << "!!! Berhasil dihapus !!!" << std::endl << std::endl;
      keranjang.erase(keranjang.begin() + pilih - 1);

      data.open("user/" + id + "_keranjang.txt", std::ios::out);
      for(int a = 0; a < keranjang.size(); a++){
        data << keranjang.at(a).judul << ";";
        data << keranjang.at(a).penulis <<";";
        data << keranjang.at(a).tahunTerbit << " ";
        data << keranjang.at(a).stok;
      }
      data.close();
    }
};

#endif