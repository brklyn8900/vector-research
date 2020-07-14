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

// constructor

int main()
{
  Vector<int> vector;

  // add element
  for (int i = 0; i < 9; i++)
    vector.push_back(i);

  // console array elements
  std::cout << std::endl;
  std::cout << "array:" << std::endl;

  for (int i = 0; i < vector.capacity(); i++)
  {
    std::cout << "|  " << vector[i] << "  ";
  }
  std::cout << "|" << std::endl;
  std::cout << std::endl;

  // capacity and size
  std::cout << "capacity: " << vector.capacity() << std::endl;
  std::cout << "vector size: " << vector.size() << std::endl;
  std::cout << std::endl;

  // call function
  vector.resize(4);

  // console output after function
  std::cout << "array after function call:" << std::endl;
  for (int i = 0; i < vector.capacity(); i++)
  {
    std::cout << "|  " << vector[i] << "  ";
  }
  std::cout << "|" << std::endl;
  std::cout << std::endl;

  // final vector and array size
  std::cout << "capacity: " << vector.capacity() << std::endl;
  std::cout << "vector size: " << vector.size() << std::endl;
  // std::cout << "element size: " << element_size << std::endl;

  return 0;
}

// create an array
// how big the vector is and how big the underlying array is
// add the ability to add elements to the array
// have the ability to grow the array
// account for getting to the end of the array
// double the size of the array when getting to the end (create a bucket size)

// TODO:

// maxsize -- leave for later
// index operator -- overload operator - not sure how to do that

// DONE:

// size
// resize
// capacity
// push_back
// clear

// RAII
// resource aquisition is initialization design pattern in standard library

// iterators