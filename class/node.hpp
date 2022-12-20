#ifndef __node
#define __node

template<typename T>
class Node
{
  public:
    T data;
    Node<T> *berikut;
    Node<T> *sebelum;
};

#endif
