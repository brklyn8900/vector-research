#include <iostream>
#include <cstddef>

template<class T>
class Vector
{
public:
  // create array
  T* vector_array;
  // underlying array size
  size_t _capacity;
  // vector size
  size_t _size;

  // add the ability to add elements to the array
  void push_back(const T x)
  {
    if (_size == _capacity) 
      {
        allocate(_capacity * 2);
      }
    vector_array[_size++] = x;
  }
  
  // create vector
  Vector() 
  {
    vector_array = new T [5];
    _capacity = 8;
    _size = 0;
  };

  // get capacity
  size_t capacity() 
  {
    return _capacity;
  }

  // get size
  size_t size()
  {
    return _size;
  }

  // clear vector
  void clear()
  {
    _size = 0;
    _capacity = 0;
  }

  // resize vector 
  void resize(T resize_value)
  {
    _size = resize_value;
    _capacity = resize_value;
  }

  // maxsize
  void max_size() {

  }

  private:
    void allocate(size_t _new_size)
    {
      T* p = new T[_new_size];
      for (T i = 0; i < _capacity; i++)
      {
        p[i] = vector_array[i];
      }
      delete[] vector_array;
      vector_array = p;
      _capacity = _new_size;
    }
};


// constructor


int main()
{
  Vector<int> vector;

  // add element
  for (int i = 0; i < 17; i++) vector.push_back(i + 20);


  // console array elements
  std::cout << std::endl;
  std::cout << "array:" << std::endl;

  
    for (int i = 0; i < vector.capacity(); i++)
    {
      std::cout << "|  " << vector.vector_array[i] << "  ";
    }
    std::cout << "|" << std::endl;
    std::cout << std::endl;

  // capacity and size
  std::cout << "capacity: " << vector.capacity() << std::endl;
  std::cout << "vector size: " << vector.size() << std::endl;
  std::cout << std::endl;

  // 
  vector.resize(3);

  // console output after function
    std::cout << "array after function call:" << std::endl;
    for (int i = 0; i < vector.capacity(); i++)
    {
      std::cout << "|  " << vector.vector_array[i] << "  ";
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