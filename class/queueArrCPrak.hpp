#ifndef __queueArrCPrak
#define __queueArrCPrak
#define maks 5

class QueueArrCPrak {
  friend std::ostream &operator<<(std::ostream &, const QueueArrCPrak &);
public :
  QueueArrCPrak();
  bool penuh(int);
  bool kosong(int);
  void cetak();
  void enqueue(char);
  char dequeue();
private :
  char A[maks];
  int banyak;
};

#endif