#include <ArrayQueue.hpp>

using namespace std;

namespace LittleData {

template <typename E>
ArrayQueue<E>::ArrayQueue(int capacity)
    : _array(new E[capacity]), _capacity(capacity), n(0), f(0), r(0) {}

template <typename E> int ArrayQueue<E>::size() const { return n; }

template <typename E> bool ArrayQueue<E>::empty() const { return n == 0; }

template <typename E> const E &ArrayQueue<E>::front() const {
  if (empty())
    throw DataException("Queue is empty.");
  return _array[f];
}

template <typename E> void ArrayQueue<E>::enqueue(const E &data) {
  if (size() == _capacity)
    throw DataException("Queue is full.");
  _array[r] = data;
  r = (r + 1) % _capacity;
  n++;
}

template <typename E> void ArrayQueue<E>::dequeue() {
  if (empty())
    throw DataException("Queue is empty");
  f = (f + 1) % _capacity;
  n--;
}

template <typename E> ArrayQueue<E>::~ArrayQueue() { delete[] _array; }

#pragma region EXPLICIT_INSTATIATION
template class ArrayQueue<int>;
#pragma endregion EXPLICIT_INSTATIATION
} // namespace LittleData