#include <exception>
#include <iostream>

using namespace std;

#ifndef PRIMITIVES
#define PRIMITIVES

//#define throw(...) //deprecated

/**
 * @brief Data structures expection
 * 
 */
class DataException : std::exception {
public:
  const char *message;
  DataException(const char *message) : message(message) {}
  const char *what() const noexcept  { return message; }
};

template <typename E> class SLinkedList;
template <typename E> class DLinkedList;
template <typename E> class CircleList;

/**
 * @brief Singly linked list and Circulary Linked list node.
 *
 * @tparam E Data type which it stores.
 */
template <typename E> class SNode {
private:
  E data;
  SNode<E> *next;
  friend class SLinkedList<E>;
  friend class CircleList<E>;
};

/**
 * @brief Singly Linked List.
 *
 * @tparam E Data type which it stores.
 */
template <typename E> class SLinkedList {
public:
  SLinkedList();
  ~SLinkedList();

  bool empty() const;
  const E &front() const;
  void addFront(const E &data);
  void removeFront();

private:
  SNode<E> *head;
};

/**
 * @brief Doubly linked list node.
 *
 * @tparam E Data type which it stores.
 */
template <typename E> class DNode {
private:
  E data;
  DNode<E> *prev;
  DNode<E> *next;
  friend class DLinkedList<E>;
};

/**
 * @brief Doubly linked list.
 *
 * @tparam E Data type which it stores.
 */
template <typename E> class DLinkedList {
public:
  DLinkedList();
  ~DLinkedList();

  bool empty() const;
  const E &front() const;
  const E &back() const;
  void addFront(const E &data);
  void addBack(const E &data);
  void removeFront();
  void removeBack();

private:
  DNode<E> *header;
  DNode<E> *trailer;

protected:
  void add(DNode<E> *v, const E &data);
  void remove(DNode<E> *v);
};

/**
 * @brief Circularly Linked List.
 *
 * @tparam E Data type which it stores.
 */
template <typename E> class CircleList {
public:
  CircleList();
  ~CircleList();
  bool empty() const;
  const E &front() const;
  const E &back() const;
  void advance();
  void add(const E & data);
  void remove();

private:
  SNode<E> *cursor;
};


#endif //PRIMITIVES
