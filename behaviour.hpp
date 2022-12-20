#include <iostream>
#include "class/queueArrCPrak.hpp"
#include "class/admin.hpp"
#include "class/array1d.hpp"
#include "class/buku.hpp"
#include "class/database.hpp"
#include "class/sistem.hpp"
#include "class/user.hpp"
#include "class/DoublyLinkedList.hpp"
#include "class/SinglyLinkedList.hpp"
#include "class/StackArrayStatis.hpp"
#include "class/StackArrayDinamis.hpp"

//awal dari behaviour queueArrCPrak
//operator overloading <<
std::ostream &operator<<(std::ostream &out, const QueueArrCPrak &obj) 
{
  std::cout << "Isi Antrian : ";
  for (int i = 0; i < obj.banyak; i++)
  {
    out << obj.A[i] << " ";
  }
  return out;
}

//constructor
QueueArrCPrak::QueueArrCPrak() 
{
  banyak = 0;
  for (int i = 0; i < maks; i++)
  {
    A[i] = '0';
  }
}

//cek antrian penuh atau tidak
bool QueueArrCPrak::penuh(int banyak) 
{ 
  if(banyak == maks)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//cek antrian kosong atau tidak
bool QueueArrCPrak::kosong(int banyak) 
{ 
  if(banyak == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//cetak queue
void QueueArrCPrak::cetak() 
{
  std::cout << "Isi Antrian : ";
  for (int i = 0; i < banyak; i++)
  {
    std::cout << A[i] << " ";  
  }
}

//masuk antrian
void QueueArrCPrak::enqueue(char x) 
{
  std::cout << "Elemen : " << x << " masuk antrian" << std::endl;
  if (penuh(banyak) == true)
  {
    std::cout << "Antrian penuh" << std::endl;
  }
  else if (A[0] == '0') 
  {
    A[0] = x;
    banyak++;
  } 
  else 
  {
    for(int i = banyak; i >= 0; i--)
    {
      A[i + 1] = A[i]; 
    }
    A[0] = x;
    banyak++;
  }
}

//ke luar antrian
char QueueArrCPrak::dequeue() 
{
  char temp = A[--banyak];
  std::cout << "Elemen : " << temp << "ke luar antrian" << std::endl;
  A[banyak] = '0';
  return temp;
}

//mulai behaviour admin->
//constructor
Admin::Admin()
{
  //kosong
}

//constructor berparameter
Admin::Admin(const char *id, const char *password)
{
  this->id = id;
  this->password = password;
}

//constructor berparameter
Admin::Admin(const char *nama, const char *id, const char *password)
{
  this->nama = nama;
  this->id = id;
  this->password = password;
}

//set nama
void Admin::setNama(const char *nama)
{
  this->nama = nama;
}

//set id
void Admin::setId(const char *id)
{ 
  this->id = id; 
}

//set password
void Admin::setPassword(const char *password)
{ 
  this->password = password;
}

//get nama
std::string Admin::getNama()
{
  return this->nama; 
}

//get id
std::string Admin::getId()
{ 
  return this->id; 
}

//get password
std::string Admin::getPassword()
{
  return this->password; 
}

//cek apakah admin atau bukan
bool Admin::isAdmin(std::string id, std::string password)
{
  if(id == "admin" && password == "admin")
  {
    return true;
  }
  return false;
}

//overloading +
Admin Admin::operator+(const Admin &obj)
{
  Admin temp;
  temp.nama = this->nama + obj.nama;
  temp.id = this->id + obj.id;
  temp.password = this->password + obj.password;
  return temp;
}

//overloading =
Admin &Admin::operator=(const Admin &obj)
{
  this->nama = obj.nama;
  this->id = obj.id;
  this->password = obj.password;
  return *this;
}

//overloading +=
Admin &Admin::operator+=(const char *kata)
{
  this->nama += kata;
  this->id += kata;
  this->password += kata;
  return *this;
}

//overloading ==
Admin Admin::operator==(const Admin &obj)
{
  Admin temp;
  temp.nama = this->nama == obj.nama;
  temp.id = this->id == obj.id;
  temp.password = this->password == obj.password;
  return temp;
}

//overloading !=
Admin Admin::operator!=(const Admin &obj)
{
  Admin temp;
  temp.nama = this->nama != obj.nama;
  temp.id = this->id != obj.id;
  temp.password = this->password != obj.password;
  return temp;
}

//overloading >
Admin Admin::operator>(const Admin &obj)
{
  Admin temp;
  temp.nama = this->nama > obj.nama;
  temp.id = this->id > obj.id;
  temp.password = this->password > obj.password;
  return temp;
}

//overloading >=
Admin Admin::operator>=(const Admin &obj)
{
  Admin temp;
  temp.nama = this->nama >= obj.nama;
  temp.id = this->id >= obj.id;
  temp.password = this->password >= obj.password;
  return temp;
}

//overloading <
Admin Admin::operator<(const Admin &obj)
{
  Admin temp;
  temp.nama = this->nama < obj.nama;
  temp.id = this->id < obj.id;
  temp.password = this->password < obj.password;
  return temp;
}

//overloading <=
Admin Admin::operator<=(const Admin &obj)
{
  Admin temp;
  temp.nama = this->nama <= obj.nama;
  temp.id = this->id <= obj.id;
  temp.password = this->password <= obj.password;
  return temp;
}

//overloading &&
Admin Admin::operator&&(const Admin &obj)
{
  Admin temp;
  temp.nama = this->nama == obj.nama && this->nama != obj.nama;
  temp.id = this->id > obj.id && this->id >= obj.id;
  temp.password = this->password < obj.password && this->password > obj.password;
  return temp;
}

//overloading ||
//<--akhir dari behaviour Admin
Admin Admin::operator||(const Admin &obj) 
{
  Admin temp;
  temp.nama = this->nama == obj.nama || this->nama != obj.nama;
  temp.id = this->id > obj.id || this->id >= obj.id;
  temp.password = this->password < obj.password || this->password > obj.password;
  return temp;
}

//awal dari behaviour user -->
//constructor
User::User()
{
  //Kosong  
}

//constructor berparameter
User::User(const char *id, const char *password)
{
  this->id = id;
  this->password = password;
}

//set id
void User::setId(const char *id) 
{ 
  this->id = id; 
} 

//set password
void User::setPassword(const char *password) 
{ 
  this->password = password; 
} 

//get id
std::string User::getId() 
{ 
  return this->id; 
}

//get password
std::string User::getPassword() 
{ 
  return this->password; 
}

//cek apakah user atau bukan
bool User::isUser(std::string id, std::string password)
{
  if(id == "user" && password == "user"){
    return 1;
  }  
  return 0;
}

//overloading +
User User::operator+(const User &obj)
{
  User temp;
  temp.id = this->id + obj.id;
  temp.password = this->password + obj.password;
  return temp;
}

//overloading ==
User User::operator==(const User &obj)
{
  User temp;
  temp.id = this->id == obj.id;
  temp.password = this->password == obj.password;
  return temp;
}

//overloading !=
User User::operator!=(const User &obj)
{
  User temp;
  temp.id = this->id != obj.id;
  temp.password = this->password != obj.password;
  return temp;
}

//overloading >
User User::operator>(const User &obj)
{
  User temp;
  temp.id = this->id > obj.id;
  temp.password = this->password > obj.password;
  return temp;
}

//overloading >=
User User::operator>=(const User &obj)
{
  User temp;
  temp.id = this->id >= obj.id;
  temp.password = this->password >= obj.password;
  return temp;
}

//overloading <
User User::operator<(const User &obj)
{
  User temp;
  temp.id = this->id < obj.id;
  temp.password = this->password < obj.password;
  return temp;
}

//overloading <=
User User::operator<=(const User &obj)
{
  User temp;
  temp.id = this->id <= obj.id;
  temp.password = this->password <= obj.password;
  return temp;
}

//overloading =
User User::operator=(const User &obj)
{
  this->id = obj.id;
  this->password = obj.password;
  return *this;
}

//overloading +=
User User::operator+=(const User &obj)
{
  this->id += obj.id;
  this->password += obj.password;
  return *this;
}

//overloading &&
User User::operator&&(const User &obj)
{
  User temp;
  temp.id = this->id == obj.id && this->id != obj.id;
  temp.password = this->password >= obj.password && this->password <= obj.password;
  return temp;
}

//overloading ||
//<-- akhir dari behaviour User
User User::operator||(const User &obj)
{
  User temp;
  temp.id = this->id == obj.id || this->id != obj.id;
  temp.password = this->password >= obj.password || this->password <= obj.password;
  return temp;
}

//awal dari behaviour array1d-->
//constructor
template <typename T>
Array1D<T>::Array1D()
{
  //kosong
}

//constructor berparameter
template <typename T>
Array1D<T>::Array1D(int ukuran)
{
  this->ukuran = ukuran;
  this->array = new T[this->ukuran];
}

//destructor
template <typename T>
Array1D<T>::~Array1D()
{
  delete []array;  
}

//overloading []
template <typename T>
T &Array1D<T>::operator[](int indeks)
{
  return array[indeks];
}

//get ukuran
template <typename T>
int Array1D<T>::getUkuran()
{
  return this->ukuran;
}

//resize array
template <typename T>
Array1D<T> &Array1D<T>::resize(int ukuran)
{
  delete []array;
  this->ukuran = ukuran;
  this->array = new T[this->ukuran];
  return *this;
}

//overloading +
template<typename T>
Array1D<T> Array1D<T>::operator+(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran + obj.ukuran;
  temp.array = this->array + obj.array;
  return temp;
}

//overloading -
template<typename T>
Array1D<T> Array1D<T>::operator-(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran - obj.ukuran;
  temp.array = this->array - obj.array;
  return temp;
}

//overloading *
template<typename T>
Array1D<T> Array1D<T>::operator*(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran * obj.ukuran;
  temp.array = this->array * obj.array;
  return temp;
}

//overloading /
template<typename T>
Array1D<T> Array1D<T>::operator/(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran / obj.ukuran;
  temp.array = this->array / obj.array;
  return temp;
}

//overloading %
template<typename T>
Array1D<T> Array1D<T>::operator%(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran % obj.ukuran;
  temp.array = this->array % obj.array;
  return temp;
}

//overloading =
template<typename T>
Array1D<T> Array1D<T>::operator=(const Array1D<T> &obj)
{      
  this->ukuran = obj.ukuran;
  this->array = obj.array;
  return *this;
}

//overloading ==
template<typename T>
Array1D<T> Array1D<T>::operator==(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran == obj.ukuran;
  temp.array = this->array == obj.array;
  return temp;
}

//overloading !=
template<typename T>
Array1D<T> Array1D<T>::operator!=(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran != obj.ukuran;
  temp.array = this->array != obj.array;
  return temp;
}

//overloading >
template<typename T>
Array1D<T>Array1D<T>::operator>(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran > obj.ukuran;
  temp.array = this->array > obj.array;
  return temp;
}

//overloading >=
template<typename T>
Array1D<T> Array1D<T>::operator>=(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran >= obj.ukuran;
  temp.array = this->array >= obj.array;
  return temp;
}

//overloading <
template<typename T>
Array1D<T>Array1D<T>:: operator<(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran < obj.ukuran;
  temp.array = this->array < obj.array;
  return temp;
}

//overloading <=
template<typename T>
Array1D<T> Array1D<T>::operator<=(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran <= obj.ukuran;
  temp.array = this->array <= obj.array;
  return temp;
}

//overloading &&
template<typename T>
Array1D<T> Array1D<T>::operator&&(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran && obj.ukuran;
  temp.array = this->array && obj.array;
  return temp;
}

//overloading ||
template<typename T>
Array1D<T> Array1D<T>::operator||(const Array1D<T> &obj)
{
  Array1D<T> temp;
  temp.ukuran = this->ukuran || obj.ukuran;
  temp.array = this->array || obj.array;
  return temp;
}

//overloading +=
template<typename T>
Array1D<T> Array1D<T>::operator+=(const Array1D<T> &obj)
{
  this->ukuran += obj.ukuran;
  this->array += obj.array;
  return *this;
}

//overloading -=
template<typename T>
Array1D<T> Array1D<T>::operator-=(const Array1D<T> &obj)
{
  this->ukuran -= obj.ukuran;
  this->array -= obj.array;
  return *this;
}

//overloading *=
template<typename T>
Array1D<T> Array1D<T>::operator*=(const Array1D<T> &obj)
{
  this->ukuran *= obj.ukuran;
  this->array *= obj.array;
  return *this;
}

//overloading /=
template<typename T>
Array1D<T> Array1D<T>::operator/=(const Array1D<T> &obj)
{
  this->ukuran /= obj.ukuran;
  this->array /= obj.array;
  return *this;
}

//overloading %=
//<-- akhir dari behaviour Array1D
template<typename T>
Array1D<T> Array1D<T>::operator%=(const Array1D<T> &obj)
{
  this->ukuran %= obj.ukuran;
  this->array %= obj.array;
  return *this;
}

//awal dari behaviour Buku -->
//overloading <<
std::ostream &operator<<(std::ostream &out, Buku &obj)
{
  out<<std::left<<std::setw(50)<<obj.getJudul();
  out<<std::setw(33)<<obj.getPenulis();
  out<<std::setw(6)<<obj.getTahunTerbit();
  out<<obj.getStok();
  return out;
}

//constructor
Buku::Buku()
{
  //Kosong  
}

//constructor berparameter
Buku::Buku(const char *judul, const char *penulis, int tahunTerbit, short stok)
{
  this->judul = judul;
  this->penulis = penulis;
  this->tahunTerbit = tahunTerbit;
  this->stok = stok;
}

//set judul
void Buku::setJudul(const char *judul)
{
  this->judul = judul;
}

//set penulis
void Buku::setPenulis(const char *penulis)
{
  this->penulis = penulis;
}

//set tahun terbit
void Buku::setTahunTerbit(int tahunTerbit)
{
  this->tahunTerbit = tahunTerbit;
}

//set stok
void Buku::setStok(short stok)
{
  this->stok = stok;
}

//set semuanya
void Buku::setNewValue(const char *judul, const char *penulis, int tahunTerbit, short stok)
{
  this->judul = judul;
  this->penulis = penulis;
  this->tahunTerbit = tahunTerbit;
  this->stok = stok;
}

//get judul
std::string Buku::getJudul()
{
  return judul;
}

//get penulis
std::string Buku::getPenulis()
{
  return penulis;
}

//get tahun terbit
int Buku::getTahunTerbit()
{
  return tahunTerbit;
}

//get stok
short Buku::getStok()
{
  return stok;
}

//overloading +
Buku Buku::operator+(const Buku &obj)
{
  Buku temp;
  temp.judul = this->judul + obj.judul;
  temp.penulis = this->penulis + obj.penulis;
  temp.tahunTerbit = this->tahunTerbit + obj.tahunTerbit;
  temp.stok = this->stok + obj.stok;
  return temp;
}

//overloading -
Buku Buku::operator-(const Buku &obj)
{
  Buku temp;
  temp.tahunTerbit = this->tahunTerbit - obj.tahunTerbit;
  temp.stok = this->stok - obj.stok;
  return temp;
}

//overloading *
Buku Buku::operator*(const Buku &obj)
{
  Buku temp;
  temp.tahunTerbit = this->tahunTerbit * obj.tahunTerbit;
  temp.stok = this->stok * obj.stok;
  return temp;
}

//overloading /
Buku Buku::operator/(const Buku &obj)
{
  Buku temp;
  temp.tahunTerbit = this->tahunTerbit / obj.tahunTerbit;
  temp.stok = this->stok / obj.stok;
  return temp;
}

//overloading %
Buku Buku::operator%(const Buku &obj)
{
  Buku temp;
  // temp.judul = this->judul % obj.judul;
  // temp.penulis = this->penulis % obj.penulis;
  temp.tahunTerbit = this->tahunTerbit % obj.tahunTerbit;
  temp.stok = this->stok % obj.stok;
  return temp;
}

//overloading ==
Buku Buku::operator==(const Buku &obj)
{
  Buku temp;
  temp.judul = this->judul == obj.judul;
  temp.penulis = this->penulis == obj.penulis;
  temp.tahunTerbit = this->tahunTerbit == obj.tahunTerbit;
  temp.stok = this->stok == obj.stok;
  return temp;
}

//overloading !=
Buku Buku::operator!=(const Buku &obj)
{
  Buku temp;
  temp.judul = this->judul != obj.judul;
  temp.penulis = this->penulis != obj.penulis;
  temp.tahunTerbit = this->tahunTerbit != obj.tahunTerbit;
  temp.stok = this->stok != obj.stok;
  return temp;
}

//overloading >
Buku Buku::operator>(const Buku &obj)
{
  Buku temp;
  temp.judul = this->judul > obj.judul;
  temp.penulis = this->penulis > obj.penulis;
  temp.tahunTerbit = this->tahunTerbit > obj.tahunTerbit;
  temp.stok = this->stok > obj.stok;
  return temp;
}

//overloading >=
Buku Buku::operator>=(const Buku &obj)
{
  Buku temp;
  temp.judul = this->judul >= obj.judul;
  temp.penulis = this->penulis >= obj.penulis;
  temp.tahunTerbit = this->tahunTerbit >= obj.tahunTerbit;
  temp.stok = this->stok >= obj.stok;
  return temp;
}

//overloading <
Buku Buku::operator<(const Buku &obj)
{
  Buku temp;
  temp.judul = this->judul < obj.judul;
  temp.penulis = this->penulis < obj.penulis;
  temp.tahunTerbit = this->tahunTerbit < obj.tahunTerbit;
  temp.stok = this->stok < obj.stok;
  return temp;
}

//overloading <=
Buku Buku::operator<=(const Buku &obj)
{
  Buku temp;
  temp.judul = this->judul <= obj.judul;
  temp.penulis = this->penulis <= obj.penulis;
  temp.tahunTerbit = this->tahunTerbit <= obj.tahunTerbit;
  temp.stok = this->stok <= obj.stok;
  return temp;
}

//overloading &&
Buku Buku::operator&&(const Buku &obj)
{
  Buku temp;
  temp.judul = (this->judul == obj.judul) && (this->judul != obj.judul);
  temp.penulis = (this->penulis <= obj.penulis) && (this->penulis >= obj.penulis);
  temp.tahunTerbit = (this->tahunTerbit < obj.tahunTerbit) && (this->tahunTerbit >obj.tahunTerbit);
  temp.stok = (this->stok == obj.stok) && (this->stok != obj.stok);
  return temp;
}

//overloading ||
Buku Buku::operator||(const Buku &obj)
{
  Buku temp;
  temp.judul = (this->judul == obj.judul) || (this->judul != obj.judul);
  temp.penulis = (this->penulis <= obj.penulis) || (this->penulis >= obj.penulis);
  temp.tahunTerbit = (this->tahunTerbit < obj.tahunTerbit) || (this->tahunTerbit >obj.tahunTerbit);
  temp.stok = (this->stok == obj.stok) || (this->stok != obj.stok);
  return temp;
}

//overloading =
Buku Buku::operator=(const Buku &obj)
{
  this->judul = obj.judul;
  this->penulis = obj.penulis;
  this->tahunTerbit = obj.tahunTerbit;
  this->stok = obj.stok;
  return *this;
}

//overloading +=
Buku Buku::operator+=(const Buku &obj)
{
  this->judul += obj.judul;
  this->penulis += obj.penulis;
  this->tahunTerbit += obj.tahunTerbit;
  this->stok += obj.stok;
  return *this;
}

//overloading -=
Buku Buku::operator-=(const Buku &obj)
{            
  this->tahunTerbit -= obj.tahunTerbit;
  this->stok -= obj.stok;
  return *this;
}

//overloading *=
Buku Buku::operator*=(const Buku &obj)
{
  this->tahunTerbit *= obj.tahunTerbit;
  this->stok *= obj.stok;
  return *this;
}

//overloading /=
Buku Buku::operator/=(const Buku &obj)
{
  this->tahunTerbit /= obj.tahunTerbit;
  this->stok /= obj.stok;
  return *this;
}

//overloading %=
//<-- akhir dari behaviour Buku
Buku Buku::operator%=(const Buku &obj)
{
  this->tahunTerbit %= obj.tahunTerbit;
  this->stok %= obj.stok;
  return *this;
}

//awal dari behaviour Database -->
//tambah buku
void Database::tambahBuku(const char *judul, const char *penulis, int tahunTerbit, short stok)
{
  Buku buffer;
  std::fstream file;

  buffer.setJudul(judul);
  buffer.setPenulis(penulis);
  buffer.setTahunTerbit(tahunTerbit);
  buffer.setStok(stok);
  file.open("Buku.txt", std::ios::out|std::ios::app);
  file<<buffer.getJudul();
  file<<";"<<buffer.getPenulis();
  file<<";"<<buffer.getTahunTerbit();
  file<<" "<<buffer.getStok();
  file.close();
}

//hapus buku
void Database::hapusBuku()
{
  return;
}

//edit buku
void Database::editBuku()
{
  return;
}

//baca buku
template <typename T>
void Database::bacaBuku(std::vector<T> &bacaBuku)
{
  BukuDatabase buffer;
  std::fstream file;
  file.open("Buku.txt", std::ios::in);
  while(std::getline(file, buffer.judul, ',') && 
        std::getline(file, buffer.penulis, ',') && file >> buffer.tahunTerbit >> buffer.stok){
    bacaBuku.push_back(buffer);
        }
  file.close();
  // for(auto &x : bacaBuku)
}

//search buku
//<-- akhir dari behaviour Database
void Database::search()
{
  return;
}

//awal dari behaviour Sistem -->
//constructor
Sistem::Sistem()
{
  //kosong
}

//constructor berparameter
Sistem::Sistem(char tipeUser, const char *username, const char *password)
{
  this->tipeUser = tipeUser;
  this->username = username;
  this->password = password;
}

//set tipe user
void Sistem::setTipeUser(char tipeUser)
{
  this->tipeUser = tipeUser;  
}

//set username
void Sistem::setUsername(const char *username)
{
  this->username = username;  
}

//set password
void Sistem::setPassword(const char *password)
{
  this->password = password;  
}

//get tipe user
char Sistem::getTipeUser()
{
  return tipeUser;  
}

//get username
std::string Sistem::getUsername()
{
  return username;  
}

//get password
std::string Sistem::getPassword()
{
  return password;  
}

//cek apakah berhasil login atau tidak
bool Sistem::Login(bool isAdmin, bool isUser)
{
  if(isAdmin == true)
  {
    std::cout<<"Admin di Login"<<std::endl;
    return true;
  }

  if(isUser == true)
  {
    std::cout<<"User di Login"<<std::endl;
    return true;
  }
  return false;
}

//overloading +
Sistem Sistem::operator+(const Sistem &obj)
{
  Sistem temp;
  temp.tipeUser = this->tipeUser + obj.tipeUser;
  temp.username = this->username + obj.username;
  temp.password = this->password + obj.password;
  return temp;
}

//overloading ==
Sistem Sistem::operator==(const Sistem &obj)
{
  Sistem temp;
  temp.tipeUser = this->tipeUser == obj.tipeUser;
  temp.username = this->username == obj.username;
  temp.password = this->password == obj.password;
  return temp;
}

//overloading !=
Sistem Sistem::operator!=(const Sistem &obj)
{
  Sistem temp;
  temp.tipeUser = this->tipeUser != obj.tipeUser;
  temp.username = this->username != obj.username;
  temp.password = this->password != obj.password;
  return temp;
}

//overloading >
Sistem Sistem::operator>(const Sistem &obj)
{
  Sistem temp;
  temp.tipeUser = this->tipeUser > obj.tipeUser;
  temp.username = this->username > obj.username;
  temp.password = this->password > obj.password;
  return temp;
}

//overloading >=
Sistem Sistem::operator>=(const Sistem &obj)
{
  Sistem temp;
  temp.tipeUser = this->tipeUser >= obj.tipeUser;
  temp.username = this->username >= obj.username;
  temp.password = this->password >= obj.password;
  return temp;
}

//overloading <
Sistem Sistem::operator<(const Sistem &obj)
{
  Sistem temp;
  temp.tipeUser = this->tipeUser < obj.tipeUser;
  temp.username = this->username < obj.username;
  temp.password = this->password < obj.password;
  return temp;
}

//overloading <=
Sistem Sistem::operator<=(const Sistem &obj)
{
  Sistem temp;
  temp.tipeUser = this->tipeUser <= obj.tipeUser;
  temp.username = this->username <= obj.username;
  temp.password = this->password <= obj.password;
  return temp;
}

//overloading &&
Sistem Sistem::operator&&(const Sistem &obj)
{
  Sistem temp;
  temp.tipeUser = this->tipeUser == obj.tipeUser && this->tipeUser != obj.tipeUser;
  temp.username = this->username < obj.username && this->username < obj.username;
  temp.password = this->password <= obj.password && this->password >= obj.password;
  return temp;
}

//overloading ||
Sistem Sistem::operator||(const Sistem &obj)
{
  Sistem temp;
  temp.tipeUser = this->tipeUser == obj.tipeUser || this->tipeUser != obj.tipeUser;
  temp.username = this->username < obj.username || this->username < obj.username;
  temp.password = this->password <= obj.password || this->password >= obj.password;
  return temp;
}

//overloading =
Sistem Sistem::operator=(const Sistem &obj)
{
  this->tipeUser = obj.tipeUser;
  this->username = obj.username;
  this->password = obj.password;
  return *this;
}

//overloading +=
//<-- akhir dari behaviour Sistem
Sistem Sistem::operator+=(const Sistem &obj)
{
  this->tipeUser += obj.tipeUser;
  this->username += obj.username;
  this->password += obj.password;
  return *this;
}

//awal dari behaviour DoublyLinkedList -->
//constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  this->kepala = 0;
  this->ekor = 0;
}

//destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  Node<T> *jalan = this->kepala;
  Node<T> *hapus;
  while(jalan != 0)
  {
    hapus = jalan;
    jalan = jalan->berikut;
    delete hapus;
  }
}

//tambah node di depan
template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::tambahDepan(const T &data)
{
  if(this->kepala == 0)
  {
    this->kepala = new Node<T>();
    this->kepala->data = data;
    this->kepala->berikut = 0;
    this->kepala->sebelum = 0;
    this->ekor = this->kepala;
    return *this;
  }
  Node<T> *newNode = new Node<T>();
  newNode->data = data;
  this->kepala->sebelum = newNode;
  newNode->berikut = this->kepala;
  newNode->sebelum = 0;
  this->kepala = newNode;
  return *this;
}

//tambah node di belakang
template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::tambahBelakang(const T &data)
{
  if(this->kepala == 0)
  {
    this->kepala = new Node<T>();
    this->kepala->data = data;
    this->kepala->berikut = 0;
    this->kepala->sebelum = 0;
    this->ekor = this->kepala;
    return *this;
  }
  Node<T> *nodeBaru = new Node<T>();
  nodeBaru->data = data;
  nodeBaru->sebelum = this->ekor;
  nodeBaru->berikut = 0;
  this->ekor->berikut = nodeBaru;
  this->ekor = nodeBaru;
  return *this;
}

//hapus node paling depan
template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::hapusDepan()
{
  Node<T> *hapus = this->kepala;
  this->kepala = this->kepala->berikut;
  this->kepala->sebelum = 0;
  delete hapus;
  return *this;
}

//hapus node paling belakang
template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::hapusBelakang()
{
  Node<T> *hapus = this->ekor;
  this->ekor = this->ekor->sebelum;
  this->ekor->berikut = 0;
  delete hapus;
  return *this;
}

//bersihkan list (hapus semua)
template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::clearList()
{
  Node<T> *jalan = this->kepala;
  Node<T> *hapus;
  while(jalan != 0)
  {
    hapus = jalan;
    jalan = jalan->berikut;
    delete hapus;
  }
  this->kepala = 0;
  this->ekor = 0;
  return *this;
}

//cetak maju isi list
template <typename T>
void DoublyLinkedList<T>::cetakMaju()
{
  if(!isKosong())
  {
    int a = 0;
    Node<T> *jalan = this->kepala;
    while(jalan != 0)
    {
      if(a+1 < 10)
      {
        std::cout<<std::left<<a + 1<<std::setw(4)<<".";
      }
      else if(a+1 >= 10 && a+1 < 100)
      {      
        std::cout<<std::left<<a + 1<<std::setw(3)<<".";
      }
      std::cout<<jalan->data<<std::endl;
      a++;
      jalan = jalan->berikut;
    }
    return;
  }
  std::cout<<"List Kosong"<<std::endl;
}

//cetak mundur isi list
template <typename T>
void DoublyLinkedList<T>::cetakMundur()
{
  if(!isKosong()){
    int a = 0;
    Node<T> *jalan = this->ekor;
    while(jalan != 0)
    {
      if(a+1 < 10)
      {
        std::cout<<std::left<<a + 1<<std::setw(4)<<".";
      }
      else if(a+1 >= 10 && a+1 < 100)
      {      
        std::cout<<std::left<<a + 1<<std::setw(3)<<".";
      }
      std::cout<<jalan->data<<std::endl;
      a++;
      jalan = jalan->sebelum;
    }
    return;
  }
  std::cout<<"List Kosong"<<std::endl;
}

//cek apakah list kosong atau tidak
//akhir dari behaviour DoublyLinkedList
template <typename T>
bool DoublyLinkedList<T>::isKosong()
{
  if(this->kepala == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//awal dari behaviour SinglyLinkedList -->
//constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
  this->kepala = 0;
  this->ekor = 0;
}

//destructor
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
  Node<T> *hapus;
  Node<T> *jalan = this->kepala;
  while(jalan != 0)
  {
    hapus = jalan;
    jalan = jalan->berikut;
    delete hapus;
  }
}

//tambah node di depan
template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::tambahDepan(T data)
{
  if(isKosong())
  {
    this->kepala = new Node<T>();
    this->kepala->data = data;
    this->kepala->berikut = 0;
    this->ekor = this->kepala;
    return *this;
  }
  Node<T> *nodeBaru = new Node<T>();
  nodeBaru->data = data;
  nodeBaru->berikut = this->kepala;
  this->kepala = nodeBaru;
  return *this;
}

//tambah node di belakang
template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::tambahBelakang(T data)
{
  if(isKosong())
  {
    this->kepala = new Node<T>();
    this->kepala->data = data;
    this->kepala->berikut = 0;
    this->ekor = this->kepala;
    return *this;
  }
  Node<T> *nodeBaru = new Node<T>();
  nodeBaru->data = data;
  nodeBaru->berikut = 0;
  this->ekor->berikut = nodeBaru;
  this->ekor = nodeBaru;
  return *this;
}

//hapus node paling depan
template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::hapusDepan()
{
  Node<T> *hapus = this->kepala;
  this->kepala = this->kepala->berikut;
  delete hapus;
  return *this;
}

//hapus node paling belakang
template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::hapusBelakang()
{
  Node<T> *hapus = this->ekor;
  Node<T> *jalan = this->kepala;
  while(jalan->berikut != ekor)
  {
    jalan = jalan->berikut;
  }
  this->ekor = jalan;
  this->ekor->berikut = 0;
  delete hapus;
  return *this;
}

//clear list (hapus semua)
template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::clearList()
{
  Node<T> *jalan = this->kepala;
  Node<T> *hapus;
  while(jalan != 0)
  {
    hapus = jalan;
    jalan = jalan->berikut;
    delete hapus;
  }
  this->kepala = 0;
  this->ekor = 0;
  return *this;
}

//cetak list
template <typename T>
void SinglyLinkedList<T>::display()
{
  if(!isKosong())
  {
    Node<T> *jalan = this->kepala;
    int a = 0;
    while(jalan != 0)
    {
      if(a+1 < 10)
      {
        std::cout<<std::left<<a + 1<<std::setw(4)<<".";
      }else if(a+1 >= 10 && a+1 < 100)
      {      
        std::cout<<std::left<<a + 1<<std::setw(3)<<".";
      }
      std::cout<<jalan->data<<std::endl;
      jalan = jalan->berikut;
      a++;
    }
    return;
  }
  std::cout<<"List kosong"<<std::endl;
}

//cek apakah list kosong atau tidak
//<-- akhir dari behaviour SinglyLinkedList
template <typename T>
bool SinglyLinkedList<T>::isKosong()
{
  if(this->kepala == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//awal dari behaviour Stack Array Statis -->
//overloading <<
std::ostream &operator<<(std::ostream &out, const StackArrayStatis &obj)
{ 
  std::cout<<"Isi stack : ";
  for (int i = 0; i < maks; i++)
  {
    out<<obj.element[i]<<" ";
  }
  out<<std::endl;
  return out;
}

//constructor
StackArrayStatis::StackArrayStatis() 
{
  this->banyak = 0;
  for (int i = 0; i < maks; i++)
  {
    element[i] = '0';
  }
}

//cek apakah stack penuh atau tidak
bool StackArrayStatis::penuh(int banyak)
{
  if(banyak == maks)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//cek apakah stack kosong atau tidak
bool StackArrayStatis::kosong(int banyak)
{ 
  if(banyak == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//cetak stack
void StackArrayStatis::cetak()
{
  std::cout<<"Isi stack : ";
  for (int i = 0; i < maks; i++)
  {
    std::cout<<element[i]<<" "; 
  }
  std::cout<<std::endl;
}

//push ke stack
void StackArrayStatis::push(char x)
{
  if (penuh(banyak))
  {
    std::cout<<"Stack penuh"<<std::endl;
    return;
  }
  std::cout<<"Elemen masuk : "<<x<<std::endl;
  if (element[0] == '0') 
  {
    element[0] = x;
    banyak++; 
  }
  else
  {
    for (int i = banyak; i >= 0; i--)
    {
      element[i+1] = element[i];    
    }
    element[0] = x;
    banyak++; 
  }
}

//pop stack
//<-- akhir dari behaviour Stack Array Statis
char StackArrayStatis::pop()
{
  if(!kosong(banyak))
  {
    std::cout<<"Pop stack, elemen yang di-pop : "<<element[0]<<std::endl;
    char temp = element[0];
    for(int i = 0; i < banyak; i++)
    {
      element[i] = element[i+1];
    }
    element[banyak] = '0';
    banyak--;
    return temp;
  }
  std::cout<<"Stack Underflow"<<std::endl;
  std::cout<<banyak<<std::endl;
  return '0';
}

//awal dari behaviour Stack Array Dinamis -->
//constructor
template <typename T>
StackArrayDinamis<T>::StackArrayDinamis(int maxStack)
{
    this->maxStack = maxStack;
    this->top = 0;
    this->array = new T[this->maxStack];
}

//cek apakah stack kosong atau tidak
template <typename T>
bool StackArrayDinamis<T>::isEmpty()
{
  if(this->top == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//cek apakah stack penuh atau tidak
template <typename T>
bool StackArrayDinamis<T>::isFull()
{
  if(this->top == this->maxStack)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//get data stack paling atas
template <typename T>
T StackArrayDinamis<T>::getTop()
{
    return this->array[top - 1];
}

//push data ke stack
template <typename T>
StackArrayDinamis<T> &StackArrayDinamis<T>::push(const T &data)
{
    if (!isFull())
    {
        this->array[top++] = data;
        return *this;
    }
    std::cout << "Maksimal buku yang dipinjam adalah " << this->maxStack << std::endl;
    return *this;
}

//pop data dari stack
template <typename T>
StackArrayDinamis<T> &StackArrayDinamis<T>::pop(T &temp)
{
    if (!isEmpty())
    {
        temp = this->array[--top];
        return *this;
    }
    std::cout << "Tidak bisa menghapus lagi! Buku Kosong" << std::endl;
    return *this;
}

//cetak stack
//<-- akhir dari behaviour Stack Array Dinamis
template <typename T>
void StackArrayDinamis<T>::display()
{
    if (!isEmpty())
    {
        for (int a = this->top - 1; a >= 0; a--)
        {
            std::cout << array[a] << std::endl;
        }
        return;
    }
    std::cout << "Buku Kosong" << std::endl;
}