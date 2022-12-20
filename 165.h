#ifndef __Fajar
#define __Fajar
#include<iostream>

// Pertemuan 1 : struct
struct bukuTemp 
{
  std::string judul;
  std::string penulis;
  int tahunTerbit;
  short stok;
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