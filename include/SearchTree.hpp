#ifndef SEARCHTREE_HPP
#define SEARCHTREE_HPP

#include <LinkedBinaryTree.hpp>
#include <string>

/**
 * @brief A binary search tree
 * 
 * @tparam K Key
 * @tparam V Value
 */
template <typename K, typename V> class Entry {

  public:
    typedef K Key;
    typedef V Value;

  private:
    K _key;
    V _value;

  public:
    /**
     * @brief Construct a new Entry object
     *
     * @param k
     * @param v
     */
    Entry(const K &k = K(), const V &v = V()) : _key(k), _value(v) {}
    /**
     * @brief Key getter
     *
     * @return const K&
     */
    const K &key() const { return _key; }

    /**
     * @brief Value getter
     *
     * @return const V&
     */
    const V &value() const { return _value; }

    /**
     * @brief Set the Key object
     *
     * @param k
     */
    void setKey(const K &k) { _key = k; }

    /**
     * @brief Set the Value object
     *
     * @param v
     */
    void setValue(const V &v) { _value = v; }

    bool operator==(const Entry<K,V> & entry ) const {return _key == entry.key();}
  };

/**
 * @brief A binary search tree implemented with a linked binary tree.
 *
 * @tparam E A templated Entry
 */
template <typename E> class SearchTree : public LittleData::IBinaryTree<E> {
public:
  typedef typename E::Key K;
  typedef typename E::Value V;
  class Iterator;

// #pragma region InternalBinaryTree
//   /**
//    * @brief A binary search tree entry as a key-value pair
//    *
//    * @tparam K Key type
//    * @tparam V Value type
//    */
//   template <typename K, typename V> class Entry {

//   public:
//     typedef K Key;
//     typedef V Value;

//   private:
//     K _key;
//     V _value;

//   public:
//     /**
//      * @brief Construct a new Entry object
//      *
//      * @param k
//      * @param v
//      */
//     Entry(const K &k = K(), const V &v = V()) : _key(k), _value(v) {}
//     /**
//      * @brief Key getter
//      *
//      * @return const K&
//      */
//     const K &key() const { return _key; }

//     /**
//      * @brief Value getter
//      *
//      * @return const V&
//      */
//     const V &value() const { return _value; }

//     /**
//      * @brief Set the Key object
//      *
//      * @param k
//      */
//     void setKey(const K &k) { _key = k; }

//     /**
//      * @brief Set the Value object
//      *
//      * @param v
//      */
//     void setValue(const V &v) { _value = v; }
//   };


//   class LinkedBinaryTree : public LittleData::IBinaryTree<E>
// {
//     public:
//     class Position{
//         private:
//         Entry<int,E> * v;
//         public:
//         /**
//          * @brief Construct a new Position object
//          * 
//          * @param _v 
//          */
//         Position(Entry<int,E> * _v = NULL);
//         /**
//          * @brief Get the element.
//          * 
//          * @return E& 
//          */
//         E & operator*();


//         /**
//          * @brief get the left child.
//          * 
//          * @return Position 
//          */
//         Position left() const;
//         /**
//          * @brief Get the right child.
//          * 
//          * @return Position 
//          */
//         Position right() const;
//         /**
//          * @brief Get the parent.
//          * 
//          * @return Position 
//          */
//         Position parent() const;
//         /**
//          * @brief Is the root of the tree.
//          * 
//          * @return true 
//          * @return false 
//          */
//         bool isRoot() const;
//         /**
//          * @brief Is an external node?
//          * 
//          * @return true 
//          * @return false 
//          */
//         bool isExternal() const;
//         friend class SearchTree<E>::LinkedBinaryTree;
//         friend class DLinkedList<LinkedBinaryTree::Position>;

//         friend class SearchTree;
//     };
//     typedef DLinkedList<LinkedBinaryTree::Position> PositionList;
//     public:
//     /**
//      * @brief Construct a new Linked Binary Tree< E> object
//      * 
//      */
//     LinkedBinaryTree();

//     /**
//      * @brief Number of nodes.
//      * 
//      * @return int 
//      */
//     int size() const;

//     /**
//      * @brief Is the tree empty?
//      * 
//      * @return true 
//      * @return false 
//      */
//     bool empty() const;

//     /**
//      * @brief Get the root.
//      * 
//      * @return Position 
//      */
//     Position root() const;

//     /**
//      * @brief List of nodes.
//      * 
//      * @return PositionList 
//      */
//     PositionList positions() const;

//     /**
//      * @brief Add a root into an empty tree.
//      * 
//      */
//     void addRoot();

//     /**
//      * @brief Expand external node.
//      * 
//      * @param p 
//      */
//     void expandExternal(const Position & p);

//     /**
//      * @brief Delete p and its parent.
//      * 
//      * @param p 
//      * @return Position 
//      */
//     Position removeAboveExternal(const Position & p);

//     // --- Housekeeping functions ---

//     ~LinkedBinaryTree();

//     // --- End of housekeeping functions ---
//     protected:
//     /**
//      * @brief Preorder utility.
//      * 
//      * @param v 
//      * @param pl 
//      */
//     void preorder(Entry<int,E> * v, PositionList & pl) const;
//     Position leftEnd();
//     private:
//     Entry<int,E> * _root;
//     int n;
// };

// #pragma endregion InternalBinaryTree

 
public:
  SearchTree() : T(), n(0) {
    T.addRoot();
    T.expandExternal(T.root());
  } // creates the super root
  int size() const override { return n; };
  bool empty() const override { return n == 0; };

  /**
   * @brief Find an entry with key k
   *
   * @param k Key
   * @return Iterator
   */
  Iterator find(const K &k);

  /**
   * @brief Insert a key-value pair
   *
   * @param k Key
   * @param x Value
   * @return Iterator
   */
  Iterator insert(const K &k, const V &x);

  /**
   * @brief Delete an entry with key k
   *
   * @param k Key
   */
  void erase(const K &k);

  /**
   * @brief Delete an entry in p
   *
   * @param p Iterator
   */
  void erase(const Iterator &p);

  /**
   * @brief Get the first Entry
   *
   * @return Iterator
   */
  Iterator begin();

  /**
   * @brief Get the last Entry
   *
   * @return Iterator
   */
  Iterator end();
  typedef LittleData::LinkedBinaryTree<E> BinaryTree;
  typedef typename BinaryTree::Position TPos;
protected:
  

  /**
   * @brief Get a virtual root.
   *
   * @return TPos
   */
  TPos root() const;

  /**
   * @brief Search utility
   *
   * @param k
   * @param v
   * @return TPos
   */
  TPos finder(const K &k, const TPos &v);

  /**
   * @brief Inserter utility
   *
   * @param k
   * @param x
   * @return TPos
   */
  TPos inserter(const K &k, const V &x);

  /**
   * @brief Eraser utility
   *
   * @param v
   * @return TPos
   */
  TPos eraser(TPos &v);

  TPos restructure(const TPos &v);

private:
  BinaryTree T;
  int n; // the number of entries

public:
  class Iterator {
  private:
    TPos _v;

  public:
    /**
     * @brief Construct a new Iterator object
     *
     * @param v
     */
    Iterator(const TPos &v) : _v(v) {}
    /**
     * @brief Read only entry.
     *
     * @return const E&
     */
    /* const E &operator*() const { return *_v; } */ // passing ‘const SearchTree<Entry<int, std::__cxx11::basic_string<char> > >::TPos’ {aka ‘const LittleData::LinkedBinaryTree<Entry<int, std::__cxx11::basic_string<char> > >::Position’} as ‘this’ argument discards qualifiers [-fpermissive]

    /**
     * @brief Read and write entry.
     *
     * @return E&
     */
    E &operator*() { return *_v; }

    bool operator==(const Iterator &p) const { return _v->key() == p._v->key(); }

    /**
     * @brief Inorder successor
     *
     * @return Iterator&
     */
    Iterator &operator++();

    friend class SearchTree;
  };
};

#endif // SEARCHTREE_HPP