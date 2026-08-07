#include <SearchTree.hpp>
#include "LinkedBinaryTree.cpp"
#include "primitives.cpp"
#include <string>
/* 
#pragma region InternalBinaryTree

template<typename E>
    SearchTree<E>::LinkedBinaryTree::Position::Position(Entry<int,E> * _v) : v(_v) {} 
    template<typename E>
    E & SearchTree<E>::LinkedBinaryTree::Position::operator*()
    {
        return v->value();
    }

    
    template<typename E>
    typename SearchTree<E>::LinkedBinaryTree::Position SearchTree<E>::LinkedBinaryTree::Position::left() const
    {
        return Position(v->left());
    }
    template<typename E>
    typename SearchTree<E>::LinkedBinaryTree::Position SearchTree<E>::LinkedBinaryTree::Position::right() const
    {
        return Position(v->right());
    }
    template<typename E>
    typename SearchTree<E>::LinkedBinaryTree::Position  SearchTree<E>::LinkedBinaryTree::Position::parent() const
    {
        return Position(v->parent);
    }
    template<typename E>
    bool SearchTree<E>::LinkedBinaryTree::Position::isRoot() const
    {
        return v->parent == NULL;
    }
    template<typename E>
    typename SearchTree<E>::LinkedBinaryTree::PositionList SearchTree<E>::LinkedBinaryTree::positions() const
    {
        PositionList pl;
        preorder(_root,pl); // return the list of results
        return PositionList(pl); //return the list of results
    }
    template<typename E>
    bool SearchTree<E>::LinkedBinaryTree::Position::isExternal() const
    {
        return v->left == NULL && v->right == NULL;
    }
    template<typename E>
    SearchTree<E>::LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) {}

    template<typename E>
    int SearchTree<E>::LinkedBinaryTree::size() const
    {
        return n;
    }
    template<typename E>
    bool LinkedBinaryTree<E>::empty() const
    {
        return size() == 0;
    }
    template<typename E>
    typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::root() const
    {
        if(empty()) throw DataException("The Linked Binary Tree is empty.");
        return Position(_root);
    }
    template<typename E>
    void LinkedBinaryTree<E>::addRoot()
    {
        if(!empty()) throw DataException("The Linked Binary Tree is not empty.");
        _root = new TreeNode<E>;
        n = 1;
    }
    template<typename E>
    void LinkedBinaryTree<E>::expandExternal(const Position & p)
    {
        if(!p.isExternal()) throw DataException("Node in position P is not an external Node.");
        TreeNode<E> * v = p.v; // p node
        v->left = new TreeNode<E>; // add a new left child
        v->left->parent = v; // v is its parent
        v->right = new TreeNode<E>; // add a new right child
        v->right->parent = v; // v is its parent
        n += 2;
    }
    template<typename E>
    typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::removeAboveExternal(const Position & p)
    {
        if(!p.isExternal() || p.isRoot()) throw DataException("Node in position P is not an external Node or it is the root.");
        TreeNode<E> * w = p.v; TreeNode<E> * v = w->parent; // get the node p amd its parent.
        TreeNode<E> * sib = (w == v->left ? v->right : v->left);
        if(v == _root) // is child of root?
        {
            _root = sib; // turn the root sibling
            sib->parent = NULL;
        }
        else
        {
            TreeNode<E> * gpar = v->parent;
            if(v == gpar->left) gpar->left = sib; // replace parent for sibling
            else gpar->right = sib;
            sib->parent = gpar;
        }
        delete w; delete v; // delete all nodes
        n -= 2; // 2 nodes less
        return Position(sib);
    }
    
    template<typename E>
    void LinkedBinaryTree<E>::preorder(TreeNode<E> * v, PositionList & pl) const
    {
        pl.addBack(Position(v)); // add this node
        if(v->left != NULL) // traverse the left subtree
        preorder(v->left, pl);
        if(v->right != NULL) // traverse the right subtree
        preorder(v->right, pl);
    }

    template<typename E>
    LinkedBinaryTree<E>::~LinkedBinaryTree()
    {
        Position leaf = leftEnd();
        while(size() != 1)
        {
            removeAboveExternal(leaf);
            leaf = leftEnd();
        }
        delete _root;
        n = 0;
    }

    template<typename E>
    typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::leftEnd()
    {
        Position node = root();
        while(!node.isExternal())
        {
            node = node.left();
        }
        return node;
    }

#pragma endregion InternalBinaryTree

 */
template <typename E>
typename SearchTree<E>::Iterator &SearchTree<E>::Iterator::operator++() {
  TPos w = _v.right();
  if (!w.isExternal()) { // has right subtree
    do {
      _v = w;
      w = w.left();
    } // moves down of the chain
    while (!_v.isExternal());
  } else {
    w = _v.parent();        // get parent
    while (*_v == (*w.right())) // moves up right chain
    {
      _v = w;
      w = w.parent();
    }
    _v = w; // first link left
  }
  return *this;
}

template <typename E>
typename LittleData::LinkedBinaryTree<E>::Position SearchTree<E>::root() const {
  return T.root().left();
}

template <typename E> typename SearchTree<E>::Iterator SearchTree<E>::begin() {
  typedef typename LittleData::LinkedBinaryTree<E>::Position TPos;
  TPos _v = root(); // start a virtual root
  while (!_v.isExternal())
    _v = _v.left(); // search the left-most node
  return Iterator(_v.parent());
}

template <typename E> typename SearchTree<E>::Iterator SearchTree<E>::end() {
  typedef typename LittleData::LinkedBinaryTree<E>::Position TPos;
  return Iterator(T.root());
}

template <typename E>
typename LittleData::LinkedBinaryTree<E>::Position SearchTree<E>::finder(
    const K &k, const typename LittleData::LinkedBinaryTree<E>::Position &v) {
  if (v.isExternal())
    return v; // key not found
  if (k < v->key())
    return finder(k, v.left()); // search in the left subtree
  else if (v->key() < k)
    return finder(k, v.right()); // search in the right subtree
  else
    return v;
}

template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::find(const K &k) {
  typedef typename LittleData::LinkedBinaryTree<E>::Position TPos;
  TPos v = finder(k, root()); // search in the virtual root
  if (!v.isExternal())
    return Iterator(v); // found
  return end();         // not found
}

template <typename E>
typename LittleData::LinkedBinaryTree<E>::Position
SearchTree<E>::inserter(const K &k, const V &x) {
  typedef typename LittleData::LinkedBinaryTree<E>::Position TPos;
  TPos v = finder(k, root()); // find from teh virtual root
  while (!v.isExternal())
    v = finder(k, v.right()); // the key already exists
  T.expandExternal(v);
  v->setKey(k);
  v->setValue(x); // set the entry
  n++;
  return v;
}

template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::insert(const K &k, const V &x) {
  typedef typename LittleData::LinkedBinaryTree<E>::Position TPos;
  TPos v = inserter(k, x);
  return Iterator(v);
}

template <typename E>
typename LittleData::LinkedBinaryTree<E>::Position
SearchTree<E>::eraser(typename LittleData::LinkedBinaryTree<E>::Position &v) {
  typedef typename LittleData::LinkedBinaryTree<E>::Position TPos;
  TPos w;
  if (v.left().isExternal())
    w = v.left(); // delete from the left
  else if (v.right().isExternal())
    w = v.right(); // delete from the right

  else {           // are both internal?
    w = v.right(); // move to right subtree
    do {
      w = w.left();
    } while (!w.isExternal()); // get the left-most node
    TPos u = w.parent();
    v->setKey(u->key());
    v->setValue(u->value()); // copy the parent of w to v
  }
  n--;
  return T.removeAboveExternal(w);
}

template <typename E> void SearchTree<E>::erase(const K &k) {
  TPos v = finder(k, root()); // search from the virtual root
  if (v.isExternal())         // not found?
    throw DataException("Erase if nonexistent");
  eraser(v);
}

template <typename E> void SearchTree<E>::erase(const Iterator &p) {
  erase(p._v);
}

template <typename E>
typename LittleData::LinkedBinaryTree<E>::Position SearchTree<E>::restructure(const TPos &v) {
  auto y = v.parent();
  auto z = y.parent();
  // TODO finish restructure function

}


#pragma region EXPLICIT_INSTATIATION
template class Entry<int,string>;
template class LittleData::LinkedBinaryTree<Entry<int,string>>;
template class DLinkedList<LittleData::LinkedBinaryTree<Entry<int, string>>::Position>;
template class SearchTree<Entry<int,string>>;
#pragma endregion EXPLICIT_INSTATIATION