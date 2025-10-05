#include <LinkedQueue.hpp>

using namespace std;

namespace LittleData {
template <typename E> LinkedQueue<E>::LinkedQueue() : C(), n(0) {}

template <typename E> int LinkedQueue<E>::size() const { return n; }

template <typename E> bool LinkedQueue<E>::empty() const { return n == 0; }

template <typename E>
const E &LinkedQueue<E>::front() const /* throw(DataException) */ {
  if (empty())
    throw DataException("Stack is empty.");

  return C.front();
}

template <typename E> void LinkedQueue<E>::enqueue(const E &data) {
  C.add(data);
  C.advance();
  n++;
}

template <typename E> void LinkedQueue<E>::dequeue() /* throw(DataException) */ {
  if (empty())
    throw DataException("Stack is empty.");

  C.remove();
  n--;
}

#pragma region EXPLICIT_INSTATIATION
template class LinkedQueue<int>;
#pragma endregion EXPLICIT_INSTATIATION

} // namespace LittleData