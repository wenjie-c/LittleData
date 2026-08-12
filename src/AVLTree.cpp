#include "SearchTree.cpp"
#include <AVLTree.hpp>
#include <algorithm>
#include <cstddef>
#include <exception>

template <typename K, typename V>
int AVLTree<K, V>::height(AVLNode<K, V> *node) {
  if (node == nullptr)
    return 0;
  return node->height();
}
template <typename K, typename V>
int AVLTree<K, V>::balanceFactor(AVLNode<K, V> *node) {
  if (node == nullptr)
    return 0;
  return height(node->_left) - height(node->_right);
}
template <typename K, typename V>
AVLNode<K, V> *AVLTree<K, V>::rightRotate(AVLNode<K, V> *y) {
  AVLNode<K, V> *x = y->_left;
  AVLNode<K, V> *t2 = x->_right;

  // rotation
  x->_right = y;
  y->_left = t2;

  // update heights
  y->setHeight(max(height(y->_left), height(y->_right)) + 1);
  x->setHeight(max(height(x->_left), height(x->_right)) + 1);
  return x; // return the new root
}
template <typename K, typename V>
AVLNode<K, V> *AVLTree<K, V>::leftRotate(AVLNode<K, V> *x) {
  AVLNode<K, V> *y = x->_right;
  AVLNode<K, V> *t2 = y->_left;

  // rotation
  y->_left = x;
  x->_right = t2;

  // update heights
  x->setHeight(max(height(x->_left), height(x->_right)) + 1);
  y->setHeight(max(height(y->_left), height(y->_right)) + 1);
  return y; // return the new root
}
template <typename K, typename V>
AVLNode<K, V> *AVLTree<K, V>::insert(AVLNode<K, V> *node, const K key,
                                     const V value) {
  if (node == NULL)
    return new AVLNode<K, V>(key, value);
  if (key < node->_key)
    node->_left = this->insert(node->_left, key, value);
  else if (key > node->_key)
    node->_right = this->insert(node->_right, key, value);
  else
    return node;
  // update height of this ancestor node
  node->setHeight(1 + max(height(node->_left), height(node->_right)));
  int balance = balanceFactor(node);

  // left heavy
  if (balance > 1) {
    if (balanceFactor(node->_left) >= 0)
      return rightRotate(node);
    else {
      node->_left = leftRotate(node->_left);
      return rightRotate(node);
    }
  }

  // right heavy
  if (balance < -1) {
    if (balanceFactor(node->_right) <= 0)
      return leftRotate(node);
    else {
      node->_right = rightRotate(node->_right);
      return leftRotate(node);
    }
  }

  return node;
}
template <typename K, typename V>
AVLNode<K, V> *AVLTree<K, V>::minValueNode(AVLNode<K, V> *node) {
  AVLNode<K, V> *current = node;
  while (current->_left != nullptr)
    current = current->_left;
  return current;
}
template <typename K, typename V>
AVLNode<K, V> *AVLTree<K, V>::deleteNode(AVLNode<K, V> *root, K key) {
  if (root == nullptr)
    return root;

  if (key < root->_key)
    root->_left = deleteNode(root->_left, key);
  else if (key > root->_key)
    root->_right = deleteNode(root->_right, key);
  else {
    // node with only one child or none
    if ((root->_left == nullptr) || (root->_right == nullptr)) {
      AVLNode<K, V> *temp = root->_left ? root->_left : root->_right;

      if (temp == nullptr) {
        delete root;
        return nullptr;
      } else {
        AVLNode<K, V> *old = root;
        root = temp;
        delete old;
      }
    } else {
      AVLNode<K, V> *temp = minValueNode(root->_right);
      root->_key = temp->_key;
      root->_right = deleteNode(root->_right, temp->_key);
    }
  }

  if (root == nullptr)
    return root;
  root->setHeight(1 + max(height(root->_left), height(root->_right)));
  int balance = balanceFactor(root);

  // if the tree becomes unbalanced
  if (balance > 1 && balanceFactor(root->_left) >= 0)
    return rightRotate(root);
  if (balance > 1 && balanceFactor(root->_left) < 0) {
    root->_left = leftRotate(root->_left);
    return rightRotate(root);
  }

  if (balance < -1 && balanceFactor(root->_right) <= 0)
    return leftRotate(root);
  if (balance < -1 && balanceFactor(root->_right) > 0) {
    root->_right = rightRotate(root->_right);
    return leftRotate(root);
  }
  return root;
}
template <typename K, typename V>
void AVLTree<K, V>::inorder(AVLNode<K, V> *root) {
  if (root != nullptr) {
    inorder(root->_left);
    cout << root->_key << " ";
    inorder(root->_right);
  }
}
template <typename K, typename V>
bool AVLTree<K, V>::search(AVLNode<K, V> *root, K key) {
  if (root == nullptr)
    return false;
  if (root->_key == key)
    return true;
  if (key < root->_key)
    return search(root->_left, key);
  return search(root->_right, key);
}

template <typename K, typename V>
void AVLTree<K, V>::insert(const K key, const V value) {
  root = insert(root, key, value);
}
template <typename K, typename V> void AVLTree<K, V>::remove(const K key) {
  root = deleteNode(root, key);
}
template <typename K, typename V> bool AVLTree<K, V>::search(K key) {
  return search(root, key);
}
template <typename K, typename V> void AVLTree<K, V>::printInorder() {
  inorder(root);
  cout << endl;
}

#pragma region EXPLICIT_INSTATIATION
template class AVLNode<int, string>;
template class AVLTree<int, string>;
#pragma endregion EXPLICIT_INSTATIATION