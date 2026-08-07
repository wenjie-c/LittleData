
#include <SearchTree.hpp>
#ifndef AVLEntry_HPP
#define AVLEntry_HPP

template <typename E> class AVLTree;

template <typename E> class AVLEntry : public E {
private:
  int ht;

protected:
  typedef typename E::Key K;
  typedef typename E::Value V;

  int height() const { return ht; }
  void setHeight(int h) { ht = h; }

public:
  AVLEntry(const K &k = K(), const V &v = V()) : E(k, v), ht(0) {}
  friend class AVLTree<E>;
};

#endif // AVLEntry_HPP

#ifndef AVLTree_HPP
#define AVLTree_HPP

template <typename E> class AVLTree : public SearchTree<AVLEntry<E>> {
public:
  typedef AVLEntry<E> _AVLEntry;
  typedef typename SearchTree<_AVLEntry>::Iterator Iterator;
  typedef SearchTree<_AVLEntry> ST;
  typedef typename ST::TPos TPos;
protected:
#pragma region AVLTree_VARIABLES
  typedef typename _AVLEntry::Key K;
  typedef typename _AVLEntry::Value V;
  
#pragma endregion AVLTree_VARIABLES
public:
  AVLTree();
  Iterator insert(const K &k, const V &x); // insert (k,x)
  void erase(const K &k);
  void erase(const Iterator &p);

protected:
  int height(const TPos &v) const;
  void setHeight(TPos v);
  bool isBalanced(const TPos &v) const;
  TPos tallGrandchild(const TPos &z) const;
  void rebalance(const TPos &v);
};
#endif // AVLTree_HPP