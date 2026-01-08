#include <AdaptPriorityQueue.hpp>
namespace LittleData {

template <typename E, typename C> int AdaptPriorityQueue<E, C>::size() const {
  return L.size();
}

template <typename E, typename C> bool AdaptPriorityQueue<E, C>::empty() const {
  return L.empty();
}

template <typename E, typename C>
typename AdaptPriorityQueue<E, C>::Position
AdaptPriorityQueue<E, C>::insert(const E &e) {
  typename ElementList::Iterator p = L.begin();
  while (p != L.end() && !isLess(e, *p))
    ++p;
  L.insert(p, e);
  Position pos;

  pos.q = --p;
  return pos;
}

template <typename E, typename C>
const E &AdaptPriorityQueue<E, C>::min() const {
  if (L.empty())
    throw new DataException("AdaptPriorityQueue is empty.");
  return *L.begin();
}

template <typename E, typename C> void AdaptPriorityQueue<E, C>::removeMin() {
  if (L.empty())
    throw new DataException("AdaptPriorityQueue is empty.");
  L.eraseFront();
}

template <typename E, typename C>
void AdaptPriorityQueue<E, C>::remove(const Position &p) {
  L.erase(p.q);
}

template <typename E, typename C>
typename AdaptPriorityQueue<E, C>::Position
AdaptPriorityQueue<E, C>::replace(const Position &p, const E &e) {
  L.erase(p.q);
  return insert(e);
}

#pragma region EXPLICIT_INSTATIATION
  //template class NodeList<Pair>::Iterator;
template class LittleData::AdaptPriorityQueue<Pair, IsLess>;
template class LittleData::NodeList<Pair>;
#pragma endregion EXPLICIT_INSTATIATION

} // namespace LittleData