#ifndef __array1d
#define __array1d

template <typename T>
class Array1D
{
  public:
    Array1D();
    Array1D(int);    
    ~Array1D();
    int getUkuran();
    T &operator[](int);
    Array1D<T> &resize(int);
    Array1D<T> operator+(const Array1D<T> &);
    Array1D<T> operator-(const Array1D<T> &);
    Array1D<T> operator*(const Array1D<T> &);
    Array1D<T> operator/(const Array1D<T> &);
    Array1D<T> operator%(const Array1D<T> &);
    Array1D<T> operator=(const Array1D<T> &);
    Array1D<T> operator==(const Array1D<T> &);
    Array1D<T> operator!=(const Array1D<T> &);
    Array1D<T> operator>(const Array1D<T> &);
    Array1D<T> operator>=(const Array1D<T> &);
    Array1D<T> operator<(const Array1D<T> &);
    Array1D<T> operator<=(const Array1D<T> &);
    Array1D<T> operator&&(const Array1D<T> &);
    Array1D<T> operator||(const Array1D<T> &);
    Array1D<T> operator+=(const Array1D<T> &);
    Array1D<T> operator-=(const Array1D<T> &);
    Array1D<T> operator*=(const Array1D<T> &);
    Array1D<T> operator/=(const Array1D<T> &);
    Array1D<T> operator%=(const Array1D<T> &);
  
  private:
    int ukuran;
    T *array;
};

#endif