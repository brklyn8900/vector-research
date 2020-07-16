#include "vector.hpp"

int main()
{
  Vector<int> vector;

  Vector<char> char_vector;

  char_vector.push_back('a');
  char_vector.push_back('b');
  char_vector.push_back('c');

  // iterator
  for (auto x = char_vector.begin(); x != char_vector.end(); ++x)
  {
    std::cout << *x << std::endl;
  }

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

  for (auto ptr = vector.begin(); ptr != vector.end(); ++ptr)
  {
    std::cout << "pointer: " << *ptr << std::endl;
  }
  std::cout << std::endl;

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
