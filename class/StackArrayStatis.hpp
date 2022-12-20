#ifndef __stackArrS
#define __stackArrS
#define maks 5

//Tipe Data Abstrak Stack Array Statis
class StackArrayStatis
{
friend std::ostream& operator<<(std::ostream&, const StackArrayStatis&);
public:
  StackArrayStatis();
  bool penuh(int);
  bool kosong(int);
  void cetak();
  void push(char);
  char pop();

private:
  char element[maks];
  int banyak;
};

#endif