
#include <SearchTree.hpp>
#include <algorithm>
#ifndef AVLEntry_HPP
#define AVLEntry_HPP

// This source code is based on
// https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/

/**
 * @brief An AVLTree node
 *
 * @tparam K Key
 * @tparam V Value
 */
template <typename K, typename V> class AVLTree;

/**
 * @brief An AVLNode, it works as an Entry for an AVLTree
 *
 * @tparam K
 * @tparam V
 */
template <typename K, typename V> class AVLNode {

protected:
  /* typedef typename E::Key K;
  typedef typename E::Value V; */
  int ht;
  K _key;
  V _value;

  AVLNode<K, V> *_left;
  AVLNode<K, V> *_right;

public:
  AVLNode(const K key, const V value)
      : ht(1), _key(key), _value(value), _left(nullptr), _right(nullptr) {}
  int height() const { return ht; }
  void setHeight(int h) { ht = h; }
  friend class AVLTree<K, V>;
};

#endif // AVLEntry_HPP

#ifndef AVLTree_HPP
#define AVLTree_HPP

/**
 * @brief An AVLTree.
 *
 * @tparam K Key type of each node
 * @tparam V Value type of each node
 */
template <typename K, typename V> class AVLTree {
private:
  AVLNode<K, V> *root;

  int height(AVLNode<K, V> *node);
  int balanceFactor(AVLNode<K, V> *node);
  AVLNode<K, V> *rightRotate(AVLNode<K, V> *y);
  AVLNode<K, V> *leftRotate(AVLNode<K, V> *x);
  AVLNode<K, V> *insert(AVLNode<K, V> *node, const K key, const V value);
  AVLNode<K, V> *minValueNode(AVLNode<K, V> *node);
  AVLNode<K, V> *deleteNode(AVLNode<K, V> *root, K key);
  void inorder(AVLNode<K, V> *root);
  bool search(AVLNode<K, V> *root, K key);

public:
  AVLTree<K, V>() : root(NULL) {}

  /**
   * @brief Insert a new entry providing key and value pair.
   *
   * @param key
   * @param value
   */
  void insert(const K key, const V value);

  /**
   * @brief Remove the entry with such key.
   *
   * @param key
   */
  void remove(const K key);

  /**
   * @brief Check wheter the key exists in the AVLTree.
   *
   * @param key
   * @return true
   * @return false
   */
  bool search(K key);

  /**
   * @brief Print the tree using inorder method.
   *
   */
  void printInorder();
};
#endif // AVLTree_HPP