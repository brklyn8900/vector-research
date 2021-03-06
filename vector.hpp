#include <iostream>
#include <cstddef>

template <class T>
class Vector
{
private:
  T *vector_array;
  size_t _capacity;
  size_t _size;

  void allocate(size_t _new_size)
  // check if allocating to smaller size
  {
    T *p = new T[_new_size];
    // memcopy instead of loop here, need to check if new size is smaller than array
    for (size_t i = 0; i < _new_size; i++)
    {
      p[i] = vector_array[i];
    }
    delete[] vector_array;
    vector_array = p;
    _capacity = _new_size;
  }

public:
  Vector();
  void push_back(const T x);
  size_t capacity();
  size_t size();
  void clear();
  void resize(T resize_value);
  size_t max_size();

  T &operator[](T index)
  {
    return vector_array[index];
  }

  // iterator
  class Iterator
  {
  public:
    Iterator(const T *x) noexcept : element(x) {}

    Iterator &operator=(T *x)
    {
      this->element = x;
      return *this;
    }

    // Prefix ++ overload
    Iterator &operator++()
    {
      element++;
      return *this;
    }

    // Postfix ++ overload
    Iterator operator++(int)
    {
      Iterator iterator = *this;
      ++*this;
      return iterator;
    }

    bool operator!=(const Iterator &iterator)
    {
      return element != iterator.element;
    }

    T operator*()
    {
      return *element;
    }

  private:
    const T *element;
  };

  Iterator begin()
  {
    return Iterator(&vector_array[0]);
  }

  Iterator end()
  {
    return Iterator(&vector_array[_size]);
  }

  Iterator rbegin()
  {
    return Iterator(&vector_array[_size]);
  }

  Iterator rend()
  {
    return Iterator(&vector_array[0]);
  }
};

template <class T>
Vector<T>::Vector()
{
  vector_array = new T[5];
  _capacity = 8;
  _size = 0;
};

template <class T>
void Vector<T>::push_back(const T x)
{
  if (_size == _capacity)
  {
    allocate(_capacity * 2);
  }
  vector_array[_size++] = x;
}

template <class T>
size_t Vector<T>::capacity()
{
  return _capacity;
}

template <class T>
size_t Vector<T>::size()
{
  return _size;
}

template <class T>
void Vector<T>::clear()
{
  _size = 0;
  _capacity = 0;
}

template <class T>
void Vector<T>::resize(T resize_value)
{
  _size = resize_value;
  _capacity = resize_value;
}

template <class T>
size_t Vector<T>::max_size()
{
  return 32 << 20;
}
