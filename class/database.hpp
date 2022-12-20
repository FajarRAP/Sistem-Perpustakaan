#ifndef __database
#define __database
#include <fstream>
#include <vector>
#include "buku.hpp"

struct BukuDatabase{
  std::string judul;
  std::string penulis;
  int tahunTerbit;
  short stok;
};

class Database
{
  public:
    void tambahBuku(const char *, const char *, int, short);
    void hapusBuku();
    void editBuku();
    void search();
    template <typename T>
    void bacaBuku(std::vector<T> &);
};

#endif