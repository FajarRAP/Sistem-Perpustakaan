#ifndef __stackArrD
#define __stackArrD

template <typename T>
class StackArrayDinamis
{
public:    
  StackArrayDinamis(int maxStack);
  bool isEmpty();
  bool isFull();
  T getTop();
  StackArrayDinamis<T> &push(const T &data);
  StackArrayDinamis<T> &pop(T &temp);
  void display();

private:
  T *array;
  int maxStack;
  int top;
};

#endif