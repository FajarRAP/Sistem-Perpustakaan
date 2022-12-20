#ifndef __sll
#define __sll
#include<iostream>

template <class T>
class Node2;

template <class T>
class List;

template <class T>
std::ostream& operator<< (std::ostream &, const List<T> &);

template<class T>
class Node2
{
	friend class List<T>;
	
	public:
		Node2(T &data, Node2<T> *nodeBerikut)
    {
      this->data = data;
      this->berikut = nodeBerikut;
    }

		T data;
		Node2 *berikut;
};

template<class T>
class List
{
	public:
		List();
		~List();
		void sisip(T data);
		bool hapus(T &data);
    void clearList();
		bool kosong();
		void cetak();
	
		Node2<T> *kepala;
		Node2<T> *nodeBaru(T &data, Node2<T> *nodeBerikut)
		{
      Node2<T>* temp = new Node2<T>(data, nodeBerikut); 
      return temp;
    }
};

template<class T>
std::ostream& operator<<(std::ostream& out, const List<T>& k)
{
	for(Node2<T> *p = k.kepala; p; p = p->berikut)
  {
		out<<p->data<<std::endl;
  }
	out<<std::endl;
	return out;
}

template <typename T>
List<T>::List()
{
  kepala = 0;
}

template<class T>
List<T>::~List()
{
	Node2<T>* temp;
  
	for(Node2<T>* p = kepala; p;)
	{
		temp=p;
		p=p->berikut;
		delete temp;
	}
}

template <class T>
void List<T>::sisip(T data)
{
	// std::cout<<nodeBaru<<" Masuk List : "<<std::endl;
	Node2<T> *p = nodeBaru(data, kepala);
	kepala = p;
}

template<class T>
bool List<T>::hapus(T &data)
{
	if(kosong())
  {
	  return 0;
  }
  
	data = kepala->data;
	Node2<T> *hapus = kepala;
	kepala = kepala->berikut;
	delete hapus;
	return 1;
}

template<typename T>
void List<T>::clearList()
{
	Node2<T>* temp;
  
	for(Node2<T>* p = kepala; p;)
	{
		temp=p;
		p=p->berikut;
		delete temp;
	}
}

template <typename T>
bool List<T>::kosong()
{
  return (kepala==0);
}

template<class T>
void List<T>::cetak()
{
  int a = 0;
	for(Node2<T> *p = kepala; p; p=p->berikut)
  {
    if(a+1 < 10)
    {
      std::cout<<std::left<<a + 1<<std::setw(4)<<".";
    }else if(a+1 >= 10 && a+1 < 100)
    {      
      std::cout<<std::left<<a + 1<<std::setw(3)<<".";
    }
		std::cout<<p->data<<std::endl;
    a++;
  }
	std::cout<<std::endl;
}

#endif