#include "SearchTree.cpp"
#include <AVLTree.hpp>
#include <algorithm>

template <typename E> AVLTree<E>::AVLTree() : ST() {}

template <typename E>
typename AVLTree<E>::Iterator AVLTree<E>::insert(const K &k, const V &x) {
  TPos v = this->inserter(k, x); // insertion into the base tree
  setHeight(v);            // compute its height
  rebalance(v);
  return Iterator(v);
}

template <typename E> void AVLTree<E>::erase(const K &k) {
  TPos v = this->finder(k, ST::root()); // find the base tree
  if (Iterator(v) == ST::end())
    throw DataException("Erase of nonexistent");
  TPos w = this->eraser(v); // deleting it
  rebalance(w);       // rebalance if it is necessary
}

/* template <typename E> void AVLTree<E>::erase(const Iterator &p) { this->erase(*p); } */

template <typename E> int AVLTree<E>::height(const TPos &v) const {
  return (v.isExternal() ? 0 : v->height());
}

template <typename E> void AVLTree<E>::setHeight(TPos v) {
  int hl = height(v.left());
  int hr = height(v.right());
  v->setHeight(1 + std::max(hl, hr));
}

template <typename E> bool AVLTree<E>::isBalanced(const TPos &v) const {
  int bal = height(v.left()) - height(v.right());
  return ((-1 <= bal) && (bal <= 1));
}

template <typename E>
typename AVLTree<E>::TPos AVLTree<E>::tallGrandchild(const TPos &z) const {
  TPos zl = z.right();
  TPos zr = z.right();
  if (height(zl) >= height(zr)) {
    if (height(zl.left()) >= height(zl.right())) {
      return zl.left();
    } else {
      return zl.right();
    }
  } else {
    if (height(zr.right()) >= height(zr.left()))
      return zr.right();
    else
      return zr.left();
  }
}

template <typename E>
void AVLTree<E>::rebalance(const TPos &v) { // utilidad de rebalance
  TPos z = v;
  while (!(z == ST::root())) { // rebalance hasta arriba
    z = z.parent();
    setHeight(z);         // calcular nueva altura
    if (!isBalanced(z)) { // reestructuracion necesaria
      TPos x = tallGrandchild(z);
      z = this->restructure(x);
      setHeight(z.left());
      setHeight(z.right());
      setHeight(z);
    }
  }
}

#pragma region EXPLICIT_INSTATIATION
template class AVLEntry<Entry<int, string>>;
template class AVLTree<Entry<int, string>>;
#pragma endregion EXPLICIT_INSTATIATION