#ifndef __buku
#define __buku
#include<iostream>
#include<iomanip>

struct dataBuku{
  std::string judul, penulis;
  int tahunTerbit;
  short stok;
};

class Buku{
  friend std::ostream &operator<<(std::ostream &, Buku &);
  public:
    Buku();
    Buku(const char *, const char *, int, short);
    void setJudul(const char *);
    void setPenulis(const char *);
    void setTahunTerbit(int);
    void setStok(short);
    void setNewValue(const char *, const char *, int, short);
    std::string getJudul();
    std::string getPenulis();
    int getTahunTerbit();
    short getStok();
    Buku operator+(const Buku &);
    Buku operator-(const Buku &);
    Buku operator*(const Buku &);
    Buku operator/(const Buku &);
    Buku operator%(const Buku &);
    Buku operator==(const Buku &);
    Buku operator!=(const Buku &);
    Buku operator>(const Buku &);
    Buku operator>=(const Buku &);
    Buku operator<(const Buku &);
    Buku operator<=(const Buku &);
    Buku operator&&(const Buku &);
    Buku operator||(const Buku &);
    Buku operator=(const Buku &);
    Buku operator+=(const Buku &);
    Buku operator-=(const Buku &);
    Buku operator*=(const Buku &);
    Buku operator/=(const Buku &);
    Buku operator%=(const Buku &);    
  
  private:
    std::string judul;
    std::string penulis;
    int tahunTerbit;
    short stok;
};

#endif