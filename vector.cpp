#include <iostream>


template <typename T>
class static_array
{
  private:
    int cap;
    int elements;
    T *arr;
  
  public:
    static_array(int size = 10);
    ~static_array();
    int size() const;
    void add(const T &obj);
    T &get(int index);
};
template <typename T>
static_array<T>::static_array(int size)
{
  this->cap = size;
  this->elements = 0;
  this->arr = new T[this->cap];
}

template <typename T>
static_array<T>::~static_array()
{
  delete[] this->arr;
}

template <typename T>
int static_array<T>::size()const
{
  return this->elements;
}

template <typename T>
void static_array<T>::add(const T &obj)
{
  if (this->elements <= this->cap)
    this->arr[this->elements++] = obj;
  else
    std::cout << "array is full" << std::endl;
}

template <typename T>
T& static_array<T>::get(int index)
{
  if (index < 0 || index >= this->elements)
    throw "Bad index";

  return this->arr[index];
}

// need random access, overload index operator

int main()
{
  static_array<int> ia;
  static_array<std::string> sa;

  for (size_t i = 0; i < 10; i++)
  {
    ia.add(100);
    sa.add("Koinos to the moon!");
  }

  for (size_t i = 0; i < 10; i++)
  {
    std::cout << i << " ";
    std::cout << ia.get(i) << " ";
    std::cout << sa.get(i) << " ";
    std::cout << std::endl;
  }

  return 0;
 }