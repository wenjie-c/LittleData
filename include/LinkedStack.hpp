#include <primitives.hpp>
#include<definitions.hpp>

using namespace std;

#ifndef LINKEDSTACK_HPP
#define LINKEDSTACK_HPP

namespace LittleData {

template <typename E> class LinkedStack : public IStack<E> {
public:
/**
 * @brief Construct a new Linked Stack< E> object
 * 
 */
  LinkedStack<E>();

  /**
   * @brief Number of items in stack.
   * 
   * @return int 
   */
  virtual int size() const;

  /**
   * @brief Is it empty?
   * 
   * @return true 
   * @return false 
   */
  virtual bool empty() const;

  /**
   * @brief Top element.
   * 
   * @return const E& 
   */
  virtual const E &top() /* const throw(DataException) */;

  /**
   * @brief Insert element in the stack.
   * 
   * @param data 
   */
  virtual void push(const E &data);

  /**
   * @brief Remove the element of the stack.
   * 
   */
  virtual void pop() /* throw(DataException) */ ;

private:
  SLinkedList<E> S;
  int n;
};

} // namespace LittleData
#endif LINKEDSTACK_HPP