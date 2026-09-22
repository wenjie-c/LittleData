#include <NodeSequence.hpp>
#include <algorithm>
#include <definitions.hpp>
#include <functional>
#include <sstream>
#include <string>
#ifndef TREE_HPP
#define TREE_HPP

template <typename E> struct TreeNode {
  E value;
  TreeNode<E> *parent;
  LittleData::NodeSequence<TreeNode<E> *> children;
  TreeNode() : parent(NULL), value() {}
  TreeNode(E v) : parent(NULL), value(v) {}
  TreeNode(TreeNode<E> *p) : parent(p) {}
  void addChild(E v) {
    TreeNode<E> *child = new TreeNode<E>(v);
    children.insertBack(child);
  }

  size_t size() {
    /* if (children.empty()) {
      return 1; // Reached a leaf
    } */

    size_t size = children.size();
    for (auto iter = children.begin(); iter != children.end(); ++iter) {
      size += (*iter)->size();
    }
    return size;
  }

  /**
   * @brief Find a node among its childs such it matches the predicate.
   *
   * @param predicate
   * @return TreeNode<E>&
   */
  TreeNode<E> *find(function<bool(const E)> predicate) {
    typename LittleData::NodeList<TreeNode<E> *>::Iterator iter;
    for (iter = children.begin(); iter != children.end(); ++iter) {
      if (predicate((*iter)->value))
        return (*iter);
    }
    return nullptr;
  }

  void eraseChild(TreeNode<E> *node) {
    typename LittleData::NodeList<TreeNode<E> *>::Iterator iter;
    for (iter = children.begin(); iter != children.end(); ++iter) {
      if ((*iter) == node) {
        delete (*iter);
        children.erase(iter);
        return;
      }
    }
  }

  const string print() {
    stringstream ss;
    ss << "- " << value;
    return ss.str();
  }

  void clearChildren() {
    for (auto iter = children.begin(); iter != children.end(); ++iter) {
      (*iter)->clearChildren();
      delete (*iter);
    }
    while (!children.empty()) {
      children.eraseBack();
    }
  }
};

template <typename E> class Tree {
public:
  Tree(E root) : _root(new TreeNode<E>(root)) {}

  TreeNode<E> *getRoot() { return _root; }

  const string drawTree();

  size_t size() { return _root->size() + 1; }

  ~Tree<E>() {
    _root->clearChildren();
    delete _root;
  }

protected:
  TreeNode<E> *_root;
  void setRoot(TreeNode<E> *value) { _root = value; }
  const string drawNode(TreeNode<E> *node, unsigned int level = 0);
};

#endif // TREE_HPP