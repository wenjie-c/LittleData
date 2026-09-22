#include <NodeList.hpp>
#include <Tree.hpp>
#include <cstdio>

using namespace std;

namespace LittleData {
template <typename E>NodeList<E>::Iterator::Iterator() {}
template <typename E> E &NodeList<E>::Iterator::operator*() { return v->data; }

template <typename E>
bool NodeList<E>::Iterator::operator==(const Iterator &p) const {
  return v == p.v;
}

template <typename E>
bool NodeList<E>::Iterator::operator!=(const Iterator &p) const {
  return v != p.v;
}

template <typename E>
typename NodeList<E>::Iterator &NodeList<E>::Iterator::operator++() {
  v = v->next;
  return *this;
}

template <typename E>
typename NodeList<E>::Iterator &NodeList<E>::Iterator::operator--() {
  v = v->prev;
  return *this;
}

template <typename E> NodeList<E>::Iterator::Iterator(Node<E> *u) { v = u; }
template <typename E> NodeList<E>::Iterator::~Iterator() {  }

template <typename E> NodeList<E>::NodeList() {
  n = 0; // initially empty
  // Create centinels
  header = new Node<E>;
  trailer = new Node<E>;
  // referencies
  header->next = trailer;
  trailer->prev = header;
}

template <typename E> int NodeList<E>::size() const { return n; }
template <typename E> bool NodeList<E>::empty() const { return n == 0; }
template <typename E>
typename NodeList<E>::Iterator NodeList<E>::begin() const {
  return Iterator(header->next);
}
template <typename E> typename NodeList<E>::Iterator NodeList<E>::end() const {
  return Iterator(trailer);
}
template <typename E> void NodeList<E>::insertFront(const E &data) {
  insert(begin(), data);
}
template <typename E> void NodeList<E>::insertBack(const E &data) {
  insert(end(), data);
}
template <typename E>
void NodeList<E>::insert(const Iterator &p, const E &data) {
  Node<E> *w = p.v;
  Node<E> *u = w->prev;
  Node<E> *v = new Node<E>;

  v->data = data;
  v->next = w;
  w->prev = v;
  v->prev = u;
  u->next = v;
  n++;
}
template <typename E> void NodeList<E>::eraseFront() { erase(begin()); }
template <typename E> void NodeList<E>::eraseBack() {
  erase(--end()); // delete the node in front of the trailer
}
template <typename E> void NodeList<E>::erase(const Iterator &p) {
  if(empty()) throw DataException("NodeList is empty.");
  Node<E> *v = p.v;     // node to be deleted
  Node<E> *w = v->next; // successor
  Node<E> *u = v->prev; // predessor
  u->next = w;
  w->prev = u; // unlinking p
  delete v;
  n--;
}

template <typename E> NodeList<E>::~NodeList() {
  while (!empty())
    eraseFront();
  delete header;
  delete trailer;
}

template <typename E>
NodeList<E>::NodeList(NodeList<E> & tobeCopied)
{
  n = 0; // initially empty
  // Create centinels
  header = new Node<E>;
  trailer = new Node<E>;
  // referencies
  header->next = trailer;
  trailer->prev = header;

  for(NodeList<E>::Iterator i = tobeCopied.begin(); i != tobeCopied.end(); ++i)
  {
    insertBack(*i);
  }
}

#pragma region EXPLICIT_INSTATIATION
template class NodeList<int>;
template class LittleData::NodeList<pair<int,int>>;
template class NodeList<TreeNode<int>*>;
#pragma endregion EXPLICIT_INSTATIATION

} // namespace LittleData