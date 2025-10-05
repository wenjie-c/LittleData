#include <LinkedStack.hpp>

using namespace std;

namespace LittleData {

template <typename E> LinkedStack<E>::LinkedStack() : S(), n(0) {}

template <typename E> int LinkedStack<E>::size() const { return n; } 

template <typename E> bool LinkedStack<E>::empty() const { return n == 0; }

template <typename E>
const E &LinkedStack<E>::top() /* throw(DataException) */ {
  if (empty())
    throw DataException("Stack is empty.");
  return S.front();
}

template <typename E> void LinkedStack<E>::push(const E &data) {
  ++n;
  S.addFront(data);
}

template <typename E> void LinkedStack<E>::pop() /* throw(DataException) */ {
  if (empty())
    throw DataException("Stack is empty.");
  --n;
  S.removeFront();
}

#pragma region EXPLICIT_INSTATIATION
template class LinkedStack<int>;
#pragma endregion EXPLICIT_INSTATIATION

} // namespace LittleData