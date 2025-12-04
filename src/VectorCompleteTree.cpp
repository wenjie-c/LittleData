#include <VectorCompleteTree.hpp>

using namespace std;

namespace LittleData {

template <typename E> int VectorCompleteTree<E>::size() const {
  return V.size() - 1;
}

template <typename E> bool VectorCompleteTree<E>::empty() const {
  return size() == 0;
}

template <typename E>
typename VectorCompleteTree<E>::Position
VectorCompleteTree<E>::left(const Position &p) {
  return pos(2 * idx(p));
}

template <typename E>
typename VectorCompleteTree<E>::Position
VectorCompleteTree<E>::right(const Position &p) {
  return pos(2 * idx(p) + 1);
}

template <typename E>
typename VectorCompleteTree<E>::Position
VectorCompleteTree<E>::parent(const Position &p) {
  return pos(idx(p) / 2);
}

template <typename E>
bool VectorCompleteTree<E>::hasLeft(const Position &p) const {
  return 2 * idx(p) <= size();
}

template <typename E>
bool VectorCompleteTree<E>::hasRight(const Position &p) const {
  return 2 * idx(p) + 1 <= size();
}

template <typename E>
bool VectorCompleteTree<E>::isRoot(const Position &p) const {
  return idx(p) == 1;
}

template <typename E>
typename VectorCompleteTree<E>::Position VectorCompleteTree<E>::root() {
  return pos(1);
}

template <typename E>
typename VectorCompleteTree<E>::Position VectorCompleteTree<E>::last() {
  return pos(size());
}

template <typename E> void VectorCompleteTree<E>::addLast(const E &e) {
  V.push_back(e);
}

template <typename E> void VectorCompleteTree<E>::removeLast() { V.pop_back(); }

template <typename E>
void VectorCompleteTree<E>::swap(const Position &p, const Position &q) {
  E e = *q;
  *q = *p;
  *p = e;
}

#pragma region EXPLICIT_INSTATIATION
template class LittleData::VectorCompleteTree<int>;
#pragma endregion EXPLICIT_INSTATIATION

} // namespace LittleData