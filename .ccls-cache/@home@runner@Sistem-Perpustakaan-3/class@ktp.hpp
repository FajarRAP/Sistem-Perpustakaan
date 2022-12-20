#ifndef __ktp
#define __ktp
#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>

struct dataLahir
{
  std::string tempat;
  std::string tanggal;
  std::string bulan;
  std::string tahun;
};

struct dataAlamat
{
  std::string alamat;
  std::string rt;
  std::string rw;
  std::string desa;
  std::string kec;
};

struct dataKTP
{
  std::string provinsi;
  std::string kabupatenKota;
  std::string nik;
  std::string nama;
  dataLahir ktpLahir;
  const char *jenisKelamin;
  const char *golDarah;
  dataAlamat ktpAlamat;
  const char *agama;
  const char *statusKawin;
  const char *gawe;
  const char *wargaNegara;
  const char *berlakuHingga;
};


class KTP{
  friend std::istream &operator>>(std::istream &, KTP &);

  friend std::ostream &operator<<(std::ostream &, KTP &);

  public:

    KTP()
    {
      //Constructor Kosong  
    }

    bool setProvinsi();

    bool setKabKota();

    bool setNIK();

    void setNama();

    bool setKelahiran();

    bool setKelamin();

    bool setGolonganDarah();

    bool setAlamat();

    bool setAgama();

    bool setKawin();

    bool setGawe();

    bool setWargaNegara();

    void setDurasi(const char *);

    void tulisFile();

    void bacaFile();

    bool cekAngka(std::string);
    
    template <typename T>
    void bacaDatabase(std::vector<T> &, T, const char *);

    void garis(int);

    template <typename T>
    void cetak(std::ostream &, int, int, const char *, T &);

    KTP operator+(const KTP &obj)
    {
      KTP temp;
      temp.pengguna.provinsi = this->pengguna.provinsi + obj.pengguna.provinsi;
      temp.pengguna.kabupatenKota = this->pengguna.kabupatenKota + obj.pengguna.kabupatenKota;
      temp.pengguna.nik = this->pengguna.nik + obj.pengguna.nik;
      temp.pengguna.nama = this->pengguna.nama + obj.pengguna.nama;
      temp.pengguna.ktpLahir.tempat = this->pengguna.ktpLahir.tempat + obj.pengguna.ktpLahir.tempat;
      temp.pengguna.ktpLahir.tanggal = this->pengguna.ktpLahir.tanggal + obj.pengguna.ktpLahir.tanggal;
      temp.pengguna.ktpLahir.bulan = this->pengguna.ktpLahir.bulan + obj.pengguna.ktpLahir.bulan;
      temp.pengguna.ktpLahir.tahun = this->pengguna.ktpLahir.tahun + obj.pengguna.ktpLahir.tahun;  
      temp.pengguna.ktpAlamat.rt = this->pengguna.ktpAlamat.rt + obj.pengguna.ktpAlamat.rt;
      temp.pengguna.ktpAlamat.rw = this->pengguna.ktpAlamat.rw + obj.pengguna.ktpAlamat.rw;
      temp.pengguna.ktpAlamat.desa = this->pengguna.ktpAlamat.desa + obj.pengguna.ktpAlamat.desa;
      temp.pengguna.ktpAlamat.kec = this->pengguna.ktpAlamat.kec + obj.pengguna.ktpAlamat.kec;    
      return temp;
    }
  
    KTP operator==(const KTP &obj)
    {
      KTP temp;
      temp.pengguna.provinsi = this->pengguna.provinsi == obj.pengguna.provinsi;
      temp.pengguna.kabupatenKota = this->pengguna.kabupatenKota == obj.pengguna.kabupatenKota;
      temp.pengguna.nik = this->pengguna.nik == obj.pengguna.nik;
      temp.pengguna.nama = this->pengguna.nama == obj.pengguna.nama;
      temp.pengguna.ktpLahir.tempat = this->pengguna.ktpLahir.tempat == obj.pengguna.ktpLahir.tempat;
      temp.pengguna.ktpLahir.tanggal = this->pengguna.ktpLahir.tanggal == obj.pengguna.ktpLahir.tanggal;
      temp.pengguna.ktpLahir.bulan = this->pengguna.ktpLahir.bulan == obj.pengguna.ktpLahir.bulan;
      temp.pengguna.ktpLahir.tahun = this->pengguna.ktpLahir.tahun == obj.pengguna.ktpLahir.tahun;
      temp.pengguna.ktpAlamat.alamat = this->pengguna.ktpAlamat.alamat == obj.pengguna.ktpAlamat.alamat;
      temp.pengguna.ktpAlamat.rt = this->pengguna.ktpAlamat.rt == obj.pengguna.ktpAlamat.rt;
      temp.pengguna.ktpAlamat.rw = this->pengguna.ktpAlamat.rw == obj.pengguna.ktpAlamat.rw;
      temp.pengguna.ktpAlamat.desa = this->pengguna.ktpAlamat.desa == obj.pengguna.ktpAlamat.desa;
      temp.pengguna.ktpAlamat.kec = this->pengguna.ktpAlamat.kec == obj.pengguna.ktpAlamat.kec;  
      return temp;
    }
  
    KTP operator!=(const KTP &obj)
    {
      KTP temp;
      temp.pengguna.provinsi = this->pengguna.provinsi != obj.pengguna.provinsi;
      temp.pengguna.kabupatenKota = this->pengguna.kabupatenKota != obj.pengguna.kabupatenKota;
      temp.pengguna.nik = this->pengguna.nik != obj.pengguna.nik;
      temp.pengguna.nama = this->pengguna.nama != obj.pengguna.nama;
      temp.pengguna.ktpLahir.tempat = this->pengguna.ktpLahir.tempat != obj.pengguna.ktpLahir.tempat;
      temp.pengguna.ktpLahir.tanggal = this->pengguna.ktpLahir.tanggal != obj.pengguna.ktpLahir.tanggal;
      temp.pengguna.ktpLahir.bulan = this->pengguna.ktpLahir.bulan != obj.pengguna.ktpLahir.bulan;
      temp.pengguna.ktpLahir.tahun = this->pengguna.ktpLahir.tahun != obj.pengguna.ktpLahir.tahun;
      temp.pengguna.ktpAlamat.alamat = this->pengguna.ktpAlamat.alamat != obj.pengguna.ktpAlamat.alamat;
      temp.pengguna.ktpAlamat.rt = this->pengguna.ktpAlamat.rt != obj.pengguna.ktpAlamat.rt;
      temp.pengguna.ktpAlamat.rw = this->pengguna.ktpAlamat.rw != obj.pengguna.ktpAlamat.rw;
      temp.pengguna.ktpAlamat.desa = this->pengguna.ktpAlamat.desa != obj.pengguna.ktpAlamat.desa;
      temp.pengguna.ktpAlamat.kec = this->pengguna.ktpAlamat.kec != obj.pengguna.ktpAlamat.kec;
      return temp;
    }
  
    KTP operator>(const KTP &obj)
    {
      KTP temp;
      temp.pengguna.provinsi = this->pengguna.provinsi > obj.pengguna.provinsi;
      temp.pengguna.kabupatenKota = this->pengguna.kabupatenKota > obj.pengguna.kabupatenKota;
      temp.pengguna.nik = this->pengguna.nik > obj.pengguna.nik;
      temp.pengguna.nama = this->pengguna.nama > obj.pengguna.nama;
      temp.pengguna.ktpLahir.tempat = this->pengguna.ktpLahir.tempat > obj.pengguna.ktpLahir.tempat;
      temp.pengguna.ktpLahir.tanggal = this->pengguna.ktpLahir.tanggal > obj.pengguna.ktpLahir.tanggal;
      temp.pengguna.ktpLahir.bulan = this->pengguna.ktpLahir.bulan > obj.pengguna.ktpLahir.bulan;
      temp.pengguna.ktpLahir.tahun = this->pengguna.ktpLahir.tahun > obj.pengguna.ktpLahir.tahun;
      temp.pengguna.ktpAlamat.alamat = this->pengguna.ktpAlamat.alamat > obj.pengguna.ktpAlamat.alamat;
      temp.pengguna.ktpAlamat.rt = this->pengguna.ktpAlamat.rt > obj.pengguna.ktpAlamat.rt;
      temp.pengguna.ktpAlamat.rw = this->pengguna.ktpAlamat.rw > obj.pengguna.ktpAlamat.rw;
      temp.pengguna.ktpAlamat.desa = this->pengguna.ktpAlamat.desa > obj.pengguna.ktpAlamat.desa;
      temp.pengguna.ktpAlamat.kec = this->pengguna.ktpAlamat.kec > obj.pengguna.ktpAlamat.kec;
      return temp;
    }
  
    KTP operator>=(const KTP &obj)
    {
      KTP temp;
      temp.pengguna.provinsi = this->pengguna.provinsi >= obj.pengguna.provinsi;
      temp.pengguna.kabupatenKota = this->pengguna.kabupatenKota >= obj.pengguna.kabupatenKota;
      temp.pengguna.nik = this->pengguna.nik >= obj.pengguna.nik;
      temp.pengguna.nama = this->pengguna.nama >= obj.pengguna.nama;
      temp.pengguna.ktpLahir.tempat = this->pengguna.ktpLahir.tempat >= obj.pengguna.ktpLahir.tempat;
      temp.pengguna.ktpLahir.tanggal = this->pengguna.ktpLahir.tanggal >= obj.pengguna.ktpLahir.tanggal;
      temp.pengguna.ktpLahir.bulan = this->pengguna.ktpLahir.bulan >= obj.pengguna.ktpLahir.bulan;
      temp.pengguna.ktpLahir.tahun = this->pengguna.ktpLahir.tahun >= obj.pengguna.ktpLahir.tahun;
      temp.pengguna.ktpAlamat.alamat = this->pengguna.ktpAlamat.alamat >= obj.pengguna.ktpAlamat.alamat;
      temp.pengguna.ktpAlamat.rt = this->pengguna.ktpAlamat.rt >= obj.pengguna.ktpAlamat.rt;
      temp.pengguna.ktpAlamat.rw = this->pengguna.ktpAlamat.rw >= obj.pengguna.ktpAlamat.rw;
      temp.pengguna.ktpAlamat.desa = this->pengguna.ktpAlamat.desa >= obj.pengguna.ktpAlamat.desa;
      temp.pengguna.ktpAlamat.kec = this->pengguna.ktpAlamat.kec >= obj.pengguna.ktpAlamat.kec;
      return temp;
    }
  
    KTP operator<(const KTP &obj)
    {
      KTP temp;
      temp.pengguna.provinsi = this->pengguna.provinsi < obj.pengguna.provinsi;
      temp.pengguna.kabupatenKota = this->pengguna.kabupatenKota < obj.pengguna.kabupatenKota;
      temp.pengguna.nik = this->pengguna.nik < obj.pengguna.nik;
      temp.pengguna.nama = this->pengguna.nama < obj.pengguna.nama;
      temp.pengguna.ktpLahir.tempat = this->pengguna.ktpLahir.tempat < obj.pengguna.ktpLahir.tempat;
      temp.pengguna.ktpLahir.tanggal = this->pengguna.ktpLahir.tanggal < obj.pengguna.ktpLahir.tanggal;
      temp.pengguna.ktpLahir.bulan = this->pengguna.ktpLahir.bulan < obj.pengguna.ktpLahir.bulan;
      temp.pengguna.ktpLahir.tahun = this->pengguna.ktpLahir.tahun < obj.pengguna.ktpLahir.tahun;
      temp.pengguna.ktpAlamat.alamat = this->pengguna.ktpAlamat.alamat < obj.pengguna.ktpAlamat.alamat;
      temp.pengguna.ktpAlamat.rt = this->pengguna.ktpAlamat.rt < obj.pengguna.ktpAlamat.rt;
      temp.pengguna.ktpAlamat.rw = this->pengguna.ktpAlamat.rw < obj.pengguna.ktpAlamat.rw;
      temp.pengguna.ktpAlamat.desa = this->pengguna.ktpAlamat.desa < obj.pengguna.ktpAlamat.desa;
      temp.pengguna.ktpAlamat.kec = this->pengguna.ktpAlamat.kec < obj.pengguna.ktpAlamat.kec;
      return temp;
    }
  
    KTP operator<=(const KTP &obj)
    {
      KTP temp;
      temp.pengguna.provinsi = this->pengguna.provinsi <= obj.pengguna.provinsi;
      temp.pengguna.kabupatenKota = this->pengguna.kabupatenKota <= obj.pengguna.kabupatenKota;
      temp.pengguna.nik = this->pengguna.nik <= obj.pengguna.nik;
      temp.pengguna.nama = this->pengguna.nama <= obj.pengguna.nama;
      temp.pengguna.ktpLahir.tempat = this->pengguna.ktpLahir.tempat <= obj.pengguna.ktpLahir.tempat;
      temp.pengguna.ktpLahir.tanggal = this->pengguna.ktpLahir.tanggal <= obj.pengguna.ktpLahir.tanggal;
      temp.pengguna.ktpLahir.bulan = this->pengguna.ktpLahir.bulan <= obj.pengguna.ktpLahir.bulan;
      temp.pengguna.ktpLahir.tahun = this->pengguna.ktpLahir.tahun <= obj.pengguna.ktpLahir.tahun;
      temp.pengguna.ktpAlamat.alamat = this->pengguna.ktpAlamat.alamat <= obj.pengguna.ktpAlamat.alamat;
      temp.pengguna.ktpAlamat.rt = this->pengguna.ktpAlamat.rt <= obj.pengguna.ktpAlamat.rt;
      temp.pengguna.ktpAlamat.rw = this->pengguna.ktpAlamat.rw <= obj.pengguna.ktpAlamat.rw;
      temp.pengguna.ktpAlamat.desa = this->pengguna.ktpAlamat.desa <= obj.pengguna.ktpAlamat.desa;
      temp.pengguna.ktpAlamat.kec = this->pengguna.ktpAlamat.kec <= obj.pengguna.ktpAlamat.kec;
      return temp;
    }
  
    KTP operator=(const KTP &obj)
    {
      this->pengguna.provinsi = obj.pengguna.provinsi;
      this->pengguna.kabupatenKota = obj.pengguna.kabupatenKota;
      this->pengguna.nik = obj.pengguna.nik;
      this->pengguna.nama = obj.pengguna.nama;
      this->pengguna.ktpLahir.tempat = obj.pengguna.ktpLahir.tempat;
      this->pengguna.ktpLahir.tanggal = obj.pengguna.ktpLahir.tanggal;
      this->pengguna.ktpLahir.bulan = obj.pengguna.ktpLahir.bulan;
      this->pengguna.ktpLahir.tahun = obj.pengguna.ktpLahir.tahun;
      this->pengguna.jenisKelamin = obj.pengguna.jenisKelamin;
      this->pengguna.golDarah = obj.pengguna.golDarah;
      this->pengguna.ktpAlamat.alamat = obj.pengguna.ktpAlamat.alamat;
      this->pengguna.ktpAlamat.rt = obj.pengguna.ktpAlamat.rt;
      this->pengguna.ktpAlamat.rw = obj.pengguna.ktpAlamat.rw;
      this->pengguna.ktpAlamat.desa = obj.pengguna.ktpAlamat.desa;
      this->pengguna.ktpAlamat.kec = obj.pengguna.ktpAlamat.kec;
      this->pengguna.agama = obj.pengguna.agama;
      this->pengguna.statusKawin = obj.pengguna.statusKawin;
      this->pengguna.gawe = obj.pengguna.gawe;
      this->pengguna.wargaNegara = obj.pengguna.wargaNegara;
      this->pengguna.berlakuHingga = obj.pengguna.berlakuHingga;
      return *this;
    }
  
    KTP operator+=(const KTP &obj)
    {
      this->pengguna.provinsi += obj.pengguna.provinsi;
      this->pengguna.kabupatenKota += obj.pengguna.kabupatenKota;
      this->pengguna.nik += obj.pengguna.nik;
      this->pengguna.nama += obj.pengguna.nama;
      this->pengguna.ktpLahir.tempat += obj.pengguna.ktpLahir.tempat;
      this->pengguna.ktpLahir.tanggal += obj.pengguna.ktpLahir.tanggal;
      this->pengguna.ktpLahir.bulan += obj.pengguna.ktpLahir.bulan;
      this->pengguna.ktpLahir.tahun += obj.pengguna.ktpLahir.tahun;
      this->pengguna.ktpAlamat.alamat += obj.pengguna.ktpAlamat.alamat;
      this->pengguna.ktpAlamat.rt += obj.pengguna.ktpAlamat.rt;
      this->pengguna.ktpAlamat.rw += obj.pengguna.ktpAlamat.rw;
      this->pengguna.ktpAlamat.desa += obj.pengguna.ktpAlamat.desa;
      this->pengguna.ktpAlamat.kec += obj.pengguna.ktpAlamat.kec;
      return *this;
    }
  
  private:
    dataKTP pengguna;
    const char *bantuBulan = "";
    char pilihMenu;
    std::string buffer[21];
};

std::istream &operator>>(std::istream &masukan, KTP &data){
  switch(data.pilihMenu){
    case '1':
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
      break;
    case '2':
      data.bacaFile();
      std::cout<<data.buffer[5];
      break;
  }
  return masukan;
}

std::ostream &operator<<(std::ostream &keluaran, KTP &data){
  switch(data.pilihMenu){
    case '1':
      data.garis(60);
  
      data.cetak(keluaran, 20, 30, "PROVINSI ",
                 data.pengguna.provinsi);
      data.cetak(keluaran, 21, 28, "KABUPATEN ",
                 data.pengguna.kabupatenKota);
  
      keluaran << std::left << std::setw(59) << "|"
             << "|" << std::endl;
  
      data.cetak(keluaran, 2, 41, "NIK\t\t\t: ", data.pengguna.nik);
      data.cetak(keluaran, 2, 37, "Nama\t\t\t\t: ", data.pengguna.nama);
  
      keluaran << std::left << std::setw(2) << "|"
             << "Tempat/Tgl Lahir\t: " << data.pengguna.ktpLahir.tempat
             << ", ";
      keluaran << data.pengguna.ktpLahir.tanggal << "-" << data.bantuBulan
             << data.pengguna.ktpLahir.bulan << "-" << std::setw(24);
      keluaran << data.pengguna.ktpLahir.tahun << "|" << std::endl;
      keluaran << std::left << std::setw(2) << "|"
             << "Jenis Kelamin\t\t: " << data.pengguna.jenisKelamin << "\t\t\t";
      keluaran << "Gol. Darah : " << std::setw(6) << data.pengguna.golDarah << "|"
             << std::endl;
  
      data.cetak(keluaran, 2, 37,
                 "Alamat\t\t\t: ", data.pengguna.ktpAlamat.alamat);
  
      keluaran << std::left << std::setw(2) << "|"
             << "\t\tRT/RW\t\t: " << data.pengguna.ktpAlamat.rt << "/" << std::setw(33)
             << data.pengguna.ktpAlamat.rw << "|";
      keluaran << std::endl;
  
      data.cetak(keluaran, 2, 37,
                 "\t\tKel/Desa\t: ", data.pengguna.ktpAlamat.desa);
      data.cetak(keluaran, 2, 37,
                 "\t\tKecamatan\t: ", data.pengguna.ktpAlamat.kec);
      data.cetak(keluaran, 2, 37, "Agama\t\t\t\t: ", data.pengguna.agama);
      data.cetak(keluaran, 2, 37,
                 "Status Perkawinan\t: ", data.pengguna.statusKawin);
      data.cetak(keluaran, 2, 37, "Pekerjaan\t\t\t: ", data.pengguna.gawe);
      data.cetak(keluaran, 2, 37,
                 "Kewarganegaraan\t: ", data.pengguna.wargaNegara);
      data.cetak(keluaran, 2, 37, "Berlaku hingga\t: ", data.pengguna.berlakuHingga);
      data.garis(60);
      break;
    case '2':
      std::cout<<"Baca"<<std::endl;
      data.garis(60);
  
      data.cetak(keluaran, 20, 30, "PROVINSI ",
                 data.buffer[0]);
      data.cetak(keluaran, 21, 28, "KABUPATEN ",
                 data.buffer[1]);
  
      keluaran << std::left << std::setw(59) << "|"
             << "|" << std::endl;
  
      data.cetak(keluaran, 2, 41, "NIK\t\t\t: ", data.buffer[2]);
      data.cetak(keluaran, 2, 37, "Nama\t\t\t\t: ", data.buffer[3]);
      keluaran << std::left << std::setw(2) << "|" << "Tempat/Tgl Lahir\t: " << data.buffer[4] << ", ";
      keluaran << data.buffer[5] << "-" << data.bantuBulan << data.buffer[6] << "-" << std::setw(24);
      keluaran << data.buffer[7] << "|" << std::endl;
      keluaran << std::left << std::setw(2) << "|" << "Jenis Kelamin\t\t: " << data.buffer[8] << "\t\t\t";
      keluaran << "Gol. Darah : " << std::setw(6) << data.buffer[9] << "|" << std::endl;
      data.cetak(keluaran, 2, 37, "Alamat\t\t\t: ", data.buffer[10]);
      keluaran << std::left << std::setw(2) << "|" << "\t\tRT/RW\t\t: " << data.buffer[11] << "/" << std::setw(33) << data.buffer[12] << "|";
      keluaran << std::endl;
  
      data.cetak(keluaran, 2, 37, "\t\tKel/Desa\t: ", data.buffer[13]);
      data.cetak(keluaran, 2, 37, "\t\tKecamatan\t: ", data.buffer[14]);
      data.cetak(keluaran, 2, 37, "Agama\t\t\t\t: ", data.buffer[15]);
      data.cetak(keluaran, 2, 37, "Status Perkawinan\t: ", data.buffer[16]);
      data.cetak(keluaran, 2, 37, "Pekerjaan\t\t\t: ", data.buffer[17]);
      data.cetak(keluaran, 2, 37, "Kewarganegaraan\t: ", data.buffer[18]);
      data.cetak(keluaran, 2, 37, "Berlaku hingga\t: ", data.buffer[19]);
      data.garis(60);
      break;
  }
  return keluaran;
}

bool KTP::setProvinsi()
{
  std::vector<std::string> namaProvinsi;
  std::string buffer;
  bacaDatabase(namaProvinsi, buffer, "Database/dataProvinsi.txt");
  std::cin.ignore();
  std::cout<<"Provinsi : ";
  std::getline(std::cin, pengguna.provinsi);
  for(int a = 0; a < namaProvinsi.size(); a++)
  {
    if(pengguna.provinsi == namaProvinsi.at(a))
    {
      return 1;
    }
  }
  std::cout<<"Provinsi tidak valid"<<std::endl;
  return 0;
}

bool KTP::setKabKota()
{
  bool isKetemu = false;
  std::vector<std::string> kabupatenKota;
  std::string buffer;
  char pilih;
  std::cout<<"1. Kabupaten\n2. Kota\nPilih : ";
  std::cin>>pilih;
  switch(pilih){
    case '1':
      bacaDatabase(kabupatenKota, buffer, "Database/dataKab.txt");
      while(!isKetemu){
        std::cout<<"Nama Kabupaten : ";
        std::cin>>pengguna.kabupatenKota;
        for(int a = 0; a < kabupatenKota.size(); a++){
          if(pengguna.kabupatenKota == kabupatenKota.at(a)){
            return 1;
          }
        }            
        std::cout<<"Kabupaten tidak valid"<<std::endl;
        return 0;
      }
      break;
    case '2':
      bacaDatabase(kabupatenKota, buffer, "Database/dataKota.txt");
      while(!isKetemu){
        std::cout<<"Nama Kota : ";
        std::cin>>pengguna.kabupatenKota;
        for(int a = 0; a < kabupatenKota.size(); a++){
          if(pengguna.kabupatenKota == kabupatenKota.at(a)){
            return 1;
          }
        }            
        std::cout<<"Kota tidak valid"<<std::endl;
        return 0;
      }
      break;
    default:
      std::cout<<"Pilihan tidak tersedia"<<std::endl;
    return 0;
  }
  return 0;
}

bool KTP::setNIK()
{
  std::cout<<"NIK : ";
  std::cin>>pengguna.nik;
  
  if(cekAngka(pengguna.nik) && pengguna.nik.length() == 16)
  {
    return 1;
  }
  std::cout<<"NIK tidak valid"<<std::endl;
  return 0;
}

void KTP::setNama()
{
  std::cin.ignore();
  std::cout<<"Nama : ";
  std::getline(std::cin, pengguna.nama);
}

bool KTP::setKelahiran()
{
  short tanggal, bulan, tahun;
  
  std::cout<<"Kelahiran"<<std::endl;
  std::cout<<"Tempat : ";
  std::cin>>pengguna.ktpLahir.tempat;
  std::cout<<"Tanggal : ";
  std::cin>>pengguna.ktpLahir.tanggal;
  std::cout<<"Bulan   : ";
  std::cin>>pengguna.ktpLahir.bulan;
  std::cout<<"Tahun   : ";
  std::cin>>pengguna.ktpLahir.tahun;
  
  if(cekAngka(pengguna.ktpLahir.tanggal) && cekAngka(pengguna.ktpLahir.bulan) && cekAngka(pengguna.ktpLahir.tahun)){
    tanggal = std::stoi(pengguna.ktpLahir.tanggal);
    bulan = std::stoi(pengguna.ktpLahir.bulan);
    tahun = std::stoi(pengguna.ktpLahir.tahun);
    if(bulan < 10){
      bantuBulan = "0";
    }
    if(tanggal <= 0 || tanggal > 31){
      std::cout<<"Tanggal tidak valid"<<std::endl;
      return 0;
    }else if(bulan <= 0 || bulan > 12){
      std::cout<<"Bulan tidak valid"<<std::endl;
      return 0;
    }else if(tahun <= 0){
      std::cout<<"Tahun tidak valid"<<std::endl;
      return 0;
    }
  return 1;
  }
  std::cout<<"Mengandung karakter ilegal"<<std::endl;
  return 0;
}

bool KTP::setKelamin()
{
  char pilihKelamin;
  
  std::cout<<"Jenis Kelamin : "<<std::endl;
  std::cout<<"1. Laki-laki"<<std::endl;
  std::cout<<"2. Perempuan"<<std::endl;
  std::cout<<"Pilih : ";
  std::cin>>pilihKelamin;
  
  switch(pilihKelamin)
  {
    case '1':
      pengguna.jenisKelamin = "LAKI-LAKI";
      return 1;
      break;
    case '2':
      pengguna.jenisKelamin = "PEREMPUAN";
      return 1;
      break;
    default:
      std::cout<<"Pilihan tidak tersedia"<<std::endl;
  }
  return 0;
}

bool KTP::setGolonganDarah()
{
  char pilihGolDar;
  
  std::cout<<"Golongan darah : "<<std::endl;
  std::cout<<"1. O"<<std::endl;
  std::cout<<"2. AB"<<std::endl;
  std::cout<<"3. B"<<std::endl;
  std::cout<<"4. A"<<std::endl;
  std::cout<<"Pilih : ";
  std::cin>>pilihGolDar;
  
  switch(pilihGolDar)
  {
    case '1':
      pengguna.golDarah = "O";
      return 1;
      break;
    case '2':
      pengguna.golDarah = "AB";
      return 1;
      break;
    case '3':
      pengguna.golDarah = "B";
      return 1;
      break;
    case '4':
      pengguna.golDarah = "A";
      return 1;
      break;
    default:
      std::cout<<"Pilihan tidak tersedia"<<std::endl;
  }
  return 0;
}

bool KTP::setAlamat()
{
  std::cin.ignore();
  std::cout<<"Alamat    : ";
  std::getline(std::cin, pengguna.ktpAlamat.alamat);
  std::cout<<"RT        : ";
  std::cin>>pengguna.ktpAlamat.rt;
  
  if(!cekAngka(pengguna.ktpAlamat.rt))
  {
    std::cout<<"RT tidak valid"<<std::endl;
    return 0;
  }
  
  std::cout<<"RW        : ";
  std::cin>>pengguna.ktpAlamat.rw;
  
  if(!cekAngka(pengguna.ktpAlamat.rw))
  {
    std::cout<<"RW tidak valid"<<std::endl;
    return 0;
  }
  
  std::cout<<"Kel/Desa  : ";
  std::cin>>pengguna.ktpAlamat.desa;
  std::cout<<"Kecamatan : ";
  std::cin>>pengguna.ktpAlamat.kec;
  return 1;
}

bool KTP::setAgama()
{
  char pilihAgama;
  
  std::cout<<"Agama : "<<std::endl;
  std::cout<<"1. Buddha"<<std::endl;
  std::cout<<"2. Islam"<<std::endl;
  std::cout<<"3. Hindu"<<std::endl;
  std::cout<<"4. Katolik"<<std::endl;
  std::cout<<"5. Konghucu"<<std::endl;
  std::cout<<"6. Protestan"<<std::endl;
  std::cout<<"Pilih : ";
  std::cin>>pilihAgama;
  
  switch(pilihAgama)
  {
    case '1':
      pengguna.agama = "BUDDHA";
      return 1;
      break;
    case '2':
      pengguna.agama = "ISLAM";
      return 1;
      break;
    case '3':
      pengguna.agama = "HINDU";
      return 1;
      break;
    case '4':
      pengguna.agama = "KATOLIK";
      return 1;
      break;
    case '5':
      pengguna.agama = "KONGHUCU";
      return 1;
      break;
    case '6':
      pengguna.agama = "PROTESTAN";
      return 1;
      break;
    default:
      std::cout<<"Pilihan tidak tersedia"<<std::endl;
  }
  return 0;
}

bool KTP::setKawin()
{
  char pilihKawin;
  
  std::cout<<"Status Perkawinan : "<<std::endl;
  std::cout<<"1. KAWIN"<<std::endl;
  std::cout<<"2. BELUM KAWIN"<<std::endl;
  std::cout<<"3. CERAI MATI"<<std::endl;
  std::cout<<"4. CERAI HIDUP"<<std::endl;
  std::cout<<"Pilih : ";
  std::cin>>pilihKawin;
  
  switch(pilihKawin)
  {
    case '1':
      pengguna.statusKawin = "KAWIN";
      return 1;
      break;
    case '2':
      pengguna.statusKawin = "BELUM KAWIN";
      return 1;
      break;
    case '3':
      pengguna.statusKawin = "CERAI MATI";
      return 1;
      break;
    case '4':
      pengguna.statusKawin = "CERAI HIDUP";
      return 1;
      break;
    default:  
      std::cout<<"Pilihan tidak tersedia"<<std::endl;
  }
  return 0;
}

bool KTP::setGawe()
{
  char pilihGawe;
  
  std::cout<<"Pekerjaan : "<<std::endl;
  std::cout<<"1. BEKERJA"<<std::endl;
  std::cout<<"2. BELUM/TIDAK BEKERJA"<<std::endl;
  std::cout<<"Pilih : ";
  std::cin>>pilihGawe;
  
  switch(pilihGawe)
  {
    case '1':
      pengguna.gawe = "BEKERJA";
      return 1;
      break;
    case '2':
      pengguna.gawe = "NGANGGUR";
      return 1;
      break;
    default:
      std::cout<<"Pilihan tidak tersedia"<<std::endl;
  }
  return 0;
}

bool KTP::setWargaNegara()
{
  char pilihWN;
  
  std::cout<<"Kewarganegaraan : "<<std::endl;
  std::cout<<"1. WNI"<<std::endl;
  std::cout<<"2. WNA"<<std::endl;
  std::cout<<"Pilih : ";
  std::cin>>pilihWN;
  
  switch(pilihWN)
  {
    case '1':
      pengguna.wargaNegara = "WNI";
      return 1;
      break;
    case '2':
      pengguna.wargaNegara = "WNA";
      return 1;
      break;
    default:
      std::cout<<"Pilihan tidak tersedia"<<std::endl;
  }
  return 0;
}

void KTP::setDurasi(const char *kata)
{
  pengguna.berlakuHingga = kata;
}

void KTP::tulisFile()
{
  std::fstream tulis;
  tulis.open("dataKTP/" + pengguna.nik + ".txt", std::ios::out|std::ios::trunc);
  tulis<<pengguna.provinsi<<",";
  tulis<<pengguna.kabupatenKota<<",";
  tulis<<pengguna.nik<<",";
  tulis<<pengguna.nama<<",";
  tulis<<pengguna.ktpLahir.tempat<<",";
  tulis<<pengguna.ktpLahir.tanggal<<",";
  tulis<<pengguna.ktpLahir.bulan<<",";
  tulis<<pengguna.ktpLahir.tahun<<",";
  tulis<<pengguna.jenisKelamin<<",";
  tulis<<pengguna.golDarah<<",";
  tulis<<pengguna.ktpAlamat.alamat<<",";
  tulis<<pengguna.ktpAlamat.rt<<",";
  tulis<<pengguna.ktpAlamat.rw<<",";
  tulis<<pengguna.ktpAlamat.desa<<",";
  tulis<<pengguna.ktpAlamat.kec<<",";
  tulis<<pengguna.agama<<",";
  tulis<<pengguna.statusKawin<<",";
  tulis<<pengguna.gawe<<",";
  tulis<<pengguna.wargaNegara<<",";
  tulis<<pengguna.berlakuHingga;
  tulis.close();
}

void KTP::bacaFile()
{
  std::fstream baca;
  baca.open("Database/hasilInput.txt", std::ios::in);
  while(
    std::getline(baca, buffer[0], ',') &&
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
    std::getline(baca, buffer[19], ',') &&
    std::getline(baca, buffer[20])
  );
  baca.close();
}

bool KTP::cekAngka(std::string nik)
{
  for(int a = 0; a < nik.length(); a++)
  {
    if(isdigit(nik[a]) == 0)
    {
      return 0;
    }
  }
  return 1;
}

template <typename T>
void KTP::bacaDatabase(std::vector<T> &vector, T buffer, const char *namaFile)
{
  std::ifstream bacaDatabase;
  bacaDatabase.open(namaFile);
  for(int a = 0; std::getline(bacaDatabase, buffer); a++)
  {
    vector.push_back(buffer);
  }
  bacaDatabase.close();
}

template <typename T>
void KTP::cetak(std::ostream &x, int batasKiri, int batasKanan, const char *kata, T &dataNya)
{
  x << std::left << std::setw(batasKiri) << "|" << kata << std::setw(batasKanan) << dataNya << "|" << std::endl;
}

void KTP::garis(int x)
{
  for(int a = 0; a < x; a++){
    std::cout<<"=";
  }
  std::cout<<std::endl;
}

#endif