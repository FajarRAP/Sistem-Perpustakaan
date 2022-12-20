#ifndef __dimas
#define __dimas
#include <iostream>
#include <fstream>
#include <vector>
#include "165.h"

using namespace std;

class Dimas{
public:
  void invoice(std::string nama, std::string alamat, std::string kota, std::string tanggal, int noOrder, std::vector<bukuTemp> &Buku)
  {
    ofstream myfile;
    myfile.open("Text.txt", ios::app);
    if(!myfile.fail())
    {        
    myfile<<"INVOICE"<<endl;
    myfile<<"\t\t\t\t\t\t\t\t\t\t\t\tPERPUSTAKAAN"<<endl;
    myfile<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTanggal   : "<<tanggal<<endl;
    myfile<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tNo. Order : "<<noOrder<<endl;
    myfile<<endl;
    myfile<<endl;
    myfile<<"Nama     : "<<nama<<endl;
    myfile<<"Alamat   : "<<alamat<<endl;
    myfile<<"Kota     : "<<kota<<endl;        
    myfile<<"============================================================================================================================"<<endl;
    myfile<<"|No"<<"\t\t|  Deskripsi"<<"\t\t|  Kuantitas"<<"\t\t|  Tanggal Pinjam"<<"\t\t|  Tanggal Harus Kembali"<<endl;
    myfile<<"============================================================================================================================"<<endl;      
    std::cout<<Buku.size()<<std::endl;
    for(int a = 0; a < Buku.size(); a++){
      myfile<<a+1<<". ";
      myfile<<Buku.at(a).judul<<" ";
      myfile<<tanggal<<" ";
      myfile<<std::endl;
    }
    myfile<<"*jika melewati batas/buku rusak, maka peminjam akan dikenakan denda!! "<<endl;
    myfile.close();
    }
    else
    {
      cout<<"file tidak ditemukan"<<endl;
    }
  }
};
  
  


#endif