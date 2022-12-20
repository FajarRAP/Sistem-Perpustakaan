#ifndef __sena
#define __sena
#include "class/ktp.hpp"

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
};

#endif