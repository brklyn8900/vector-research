
template <class T>
class vector
{
private:
  int vector_size;
  int vector_capacity;
  T *arr;

public:
  vector(int size = 10);
  void add(const T &obj);
};

template <typename T>
vector<T>::vector(int size)
{
  this->vector_size = size;
  this->vector_capacity = 0;
  this->arr = new T[this->vector_capacity];
}
// create an array
// how big the vector is and how big the underlying array is
// add the ability to add elements to the array
// have the ability to grow the array
// account for getting to the end of the array
// double the size of the array when getting to the end (create a bucket size)

// size
// maxsize
// resize
// capacity
// index operator
// push_back
// clear

int main()
{
  vector<int> templated_array;

  templated_array.add(4);

  return 0;
}