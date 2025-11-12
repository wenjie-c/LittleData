#include <ListPriorityQueue.hpp>
#include <utility>

using namespace std;
using namespace LittleData;

template <typename E, typename C> int ListPriorityQueue<E, C>::size() const {
  return L.size();
}

template <typename E, typename C> bool ListPriorityQueue<E, C>::empty() const {
  return L.empty();
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::insert(const E &e) {
  typename NodeList<E>::Iterator p;
  p = L.begin();

  while (p != L.end() && !isLess(e, *p))
    ++p; // find the largest element
  L.insert(p, e);
}

template <typename E, typename C>
const E &ListPriorityQueue<E, C>::min() const {
  if (L.empty())
    throw new DataException("ListPriorityQueue is empty.");
  return *L.begin();
}

template <typename E, typename C> void ListPriorityQueue<E, C>::removeMin() {
  if (L.empty())
    throw new DataException("ListPriorityQueue is empty.");
  L.eraseFront();
}

#pragma region EXPLICIT_INSTATIATION
  //template class NodeList<Pair>::Iterator;
template class LittleData::ListPriorityQueue<Pair, IsLess>;
template class LittleData::NodeList<Pair>;
#pragma endregion EXPLICIT_INSTATIATION