class KTP{
  public:
    KTP(std::string provinsi, 
        std::string kab_kota, 
        std::string nik, 
        std::string nama, 
        std::string tempat, 
        short tanggal, 
        short bulan, 
        short tahun, 
        std::string jenisKelamin, 
        char golDarah, 
        std::string alamat, 
        short rt, 
        short rw, 
        std::string kecamatan, 
        std::string kel_desa, 
        std::string agama, 
        std::string statusKawin, 
        std::string pekerjaan, 
        std::string kewarganegaraan, 
        const char *berlaku = "SEUMUR HIDUP")
    {
      this->provinsi = provinsi;
      this->kab_kota = kab_kota;
      this->nik = nik;
      this->nama = nama;
      this->tempat = tempat;
      this->tanggal = tanggal;
      this->bulan = bulan;
      this->tahun = tahun;
      this->jenisKelamin = jenisKelamin;
      this->golDarah = golDarah;
      this->alamat = alamat;
      this->rt = rt;
      this->rw = rw;
      this->kecamatan = kecamatan;
      this->kel_desa = kel_desa;
      this->agama = agama;
      this->statusKawin = statusKawin;
      this->pekerjaan = pekerjaan;
      this->kewarganegaraan = kewarganegaraan;
      this->berlaku = "SEUMUR HIDUP";
    }

  void setProvinsi(const char *provinsi)
  {
    this->provinsi = provinsi;
  }

  void setKab_kota(const char *kab_kota)
  {
    this->kab_kota = kab_kota;
  }

  void setNik(const char *nik)
  {
    this->nik = nik;
  }

  void setNama(const char *nama)
  {
    this->nama = nama;
  }

  void setTempat(const char *tempat)
  {
    this->tempat = tempat;
  }

  void setTanggal(short tanggal)
  {
    this->tanggal = tanggal;
  }

  void setBulan(short bulan)
  {
    this->bulan = bulan;
  }

  void setTahun(short tahun)
  {
    this->tahun = tahun;
  }

  void setJenisKelamin(const char *jenisKelamin)
  {
    this->jenisKelamin = jenisKelamin;
  }

  void setGolDarah(char golDarah)
  {
    this->golDarah = golDarah;
  }

  void setAlamat(const char *alamat)
  {
    this->alamat = alamat;
  }

  void setRt(short rt)
  {
    this->rt = rt;
  }

  void setRw(short rw)
  {
    this->rw = rw;
  }

  void setKel_desa(const char *kel_desa)
  {
    this->kel_desa = kel_desa;
  }

  void setKecamatan(const char *kecamatan)
  {
    this->kecamatan = kecamatan;
  }

  void setAgama(const char *agama)
  {
    this->agama = agama;
  }

  void setStatusKawin(const char *statusKawin)
  {
    this->statusKawin = statusKawin;
  }

  void setPekerjaan(const char *pekerjaan)
  {
    this->pekerjaan = pekerjaan;
  }

  void setKewarganegaraan(const char *kewarganegaraan)
  {
    this->kewarganegaraan = kewarganegaraan;
  }

  void setBerlaku(const char *berlaku)
  {
    this->berlaku = berlaku;
  }

  auto getProvinsi(const char *provinsi)
  {
    return this->provinsi;
  }

  auto getKab_kota(const char *kab_kota)
  {
    return this->kab_kota;
  }

  auto getNik(const char *nik)
  {
    return this->nik;
  }

  auto getNama(const char *nama)
  {
    return this->nama;
  }

  auto getTempat(const char *tempat)
  {
    return this->tempat;
  }

  auto getTanggal(short tanggal)
  {
    return this->tanggal;
  }

  auto getBulan(short bulan)
  {
    return this->bulan;
  }

  auto getTahun(short tahun)
  {
    return this->tahun;
  }

  auto getJenisKelamin(const char *jenisKelamin)
  {
    return this->jenisKelamin;
  }

  auto getGolDarah(char golDarah)
  {
    return this->golDarah;
  }

  auto getAlamat(const char *alamat)
  {
    return this->alamat;
  }

  auto getRt(short rt)
  {
    return this->rt;
  }

  auto getRw(short rw)
  {
    return this->rw;
  }

  auto getKel_desa(const char *kel_desa)
  {
    return this->kel_desa;
  }

  auto getKecamatan(const char *kecamatan)
  {
    return this->kecamatan;
  }

  auto getAgama(const char *agama)
  {
    return this->agama;
  }

  auto getStatusKawin(const char *statusKawin)
  {
    return this->statusKawin;
  }

  auto getPekerjaan(const char *pekerjaan)
  {
    return this->pekerjaan;
  }

  auto getKewarganegaraan(const char *kewarganegaraan)
  {
    return this->kewarganegaraan;
  }

  auto getBerlaku(const char *berlaku)
  {
    return this->berlaku;
  }

  private:
    std::string provinsi;
    std::string kab_kota;
    std::string nik;
    std::string nama;
    std::string tempat;
    short tanggal;
    short bulan;
    short tahun;
    std::string jenisKelamin;
    char golDarah;
    std::string alamat;
    short rt;
    short rw;
    std::string kel_desa;
    std::string kecamatan;
    std::string agama;
    std::string statusKawin;
    std::string pekerjaan;
    std::string kewarganegaraan;
    const char *berlaku = "SEUMUR HIDUP";
};