#include <primitives.hpp>
using namespace std;

#ifndef NODE_HPP
#define NODE_HPP
namespace LittleData {

template <typename E> class NodeList;

template <typename E> class Node {
private:
  E data;
  Node *prev;
  Node *next;
  friend class NodeList<E>;
};

template<typename E>
class IStack{
  public:
  virtual int size() {};
  virtual bool empty() {};
  virtual const E & top() {};
  virtual void push(const E & data) {};
  virtual void pop() {};
};

template<typename E>
class IQueue{
  public:
  virtual int size() const {}
  virtual bool empty() const {}
  virtual const E & front() const {}
  virtual void enqueue(const E & data) {}
  virtual void dequeue() {}
};

template<typename E>
struct TreeNode {
  E value;
  TreeNode<E> * parent;
  TreeNode<E> * left;
  TreeNode<E> * right;
  TreeNode() : value(), parent(NULL), left(NULL), right(NULL) {}
};

template<typename E>
class IBinaryTree{
  public:
  class Position;
  virtual int size() const {}
  virtual bool empty() const {}
  //virtual Position root() const {}
  //virtual void addRoot() {}
  //virtual void expandExternal(const Position & p) {}
  //virtual Position removeAboveExternal(const Position & p) {}
};

template<typename E, typename C>
class IPriorityQueue
{
  public:
  virtual int size() const {}
  virtual bool empty() const {}
  virtual void insert(const E & e) {}
  virtual const E & min() const {}
  virtual void removeMin() {}
};

} // namespace LittleData

#endif NODE_HPP