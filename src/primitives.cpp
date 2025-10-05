#include <cstddef>
#include <primitives.hpp>
#include <LinkedBinaryTree.hpp> // I need to access to LinkedBinaryTree just for splicit instantiation

using namespace std;

template <typename E> SLinkedList<E>::SLinkedList() : head(NULL) {}
template <typename E> SLinkedList<E>::~SLinkedList() {
  while (!empty())
    removeFront();
}
template <typename E> bool SLinkedList<E>::empty() const {
  return head == NULL;
}
template <typename E> const E &SLinkedList<E>::front() const {
  return head->data;
}
template <typename E> void SLinkedList<E>::addFront(const E &data) {
  SNode<E> *v = new SNode<E>;
  v->data = data;
  v->next = head;
  head = v;
}
template <typename E> void SLinkedList<E>::removeFront() {
  if (empty())
    throw DataException("Linked list is empty");
  SNode<E> *old = head;
  head = old->next;
  delete old;
}

template <typename E> DLinkedList<E>::DLinkedList() {
  header = new DNode<E>;
  trailer = new DNode<E>;
  header->next = trailer;
  trailer->prev = header;
}
template <typename E> DLinkedList<E>::~DLinkedList() {
  while (!empty())
    removeFront();
  delete header;
  delete trailer;
}
template <typename E> void DLinkedList<E>::add(DNode<E> *v, const E &data) {
  DNode<E> *u = new DNode<E>;
  u->data = data;
  u->next = v;
  u->prev = v->prev;
  v->prev->next = u;
  v->prev = u;
}
template <typename E> void DLinkedList<E>::remove(DNode<E> *v) {
  DNode<E> *u = v->prev;
  DNode<E> *w = v->next;
  u->next = w;
  w->prev = u;
  delete v;
}
template <typename E> bool DLinkedList<E>::empty() const {
  return header->next == trailer;
}
template <typename E> const E &DLinkedList<E>::front() const {
  return header->next->data;
}
template <typename E> const E &DLinkedList<E>::back() const {
  return trailer->prev->data;
}
template <typename E> void DLinkedList<E>::addFront(const E &data) {
  add(header->next, data);
}
template <typename E> void DLinkedList<E>::addBack(const E &data) {
  add(trailer, data);
}
template <typename E> void DLinkedList<E>::removeFront() {
  remove(header->next);
}
template <typename E> void DLinkedList<E>::removeBack() {
  remove(trailer->prev);
}

template <typename E> CircleList<E>::CircleList() : cursor(NULL) {}
template <typename E> CircleList<E>::~CircleList() {
  while (!empty())
    remove();
}
template <typename E> bool CircleList<E>::empty() const {
  return cursor == NULL;
}
template <typename E> const E &CircleList<E>::front() const {
  return cursor->next->data;
}
template <typename E> const E &CircleList<E>::back() const {
  return cursor->data;
}
template <typename E> void CircleList<E>::advance() { cursor = cursor->next; }
template <typename E> void CircleList<E>::add(const E &data) {
  SNode<E> *v = new SNode<E>;
  v->data = data;
  if (empty()) {
    v->next = v;
    cursor = v;
  } else {
    v->next = cursor->next;
    cursor->next = v;
  }
}
template <typename E> void CircleList<E>::remove() {
  SNode<E> *old = cursor->next;
  if (old == cursor)
    cursor = NULL;
  else
    cursor->next = old->next;
  delete old;
}

#pragma region EXPLICIT_INSTATIATION
template class SLinkedList<int>;
template class DLinkedList<int>;
template class CircleList<int>;
template class DLinkedList<LittleData::LinkedBinaryTree<int>::Position>;
#pragma endregion EXPLICIT_INSTATIATION