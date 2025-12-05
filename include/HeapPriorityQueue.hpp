#include <VectorCompleteTree.hpp>
#include <definitions.hpp>
#include <Comparator.hpp>
#include <iostream>

using namespace std;

#ifndef HEAP_PRIORITY_QUEUE_HPP
#define HEAP_PRIORITY_QUEUE_HPP

namespace LittleData {

  /**
 * @brief PriorityQueue implemented using Heap or vectorCompleteTree.
 *
 * @tparam E Element Type
 * @tparam C Comparator Type
 */
template <typename E, typename C>
class HeapPriorityQueue { // it cannot inherit from IPriorityQueue<E,C>
public:
  typedef VectorCompleteTree<E> Heap;
  HeapPriorityQueue() {}

  /**
   * @brief Size of the priority queue.
   *
   * @return int
   */
  int size() const ;

  /**
   * @brief Is the priority queue empty?
   *
   * @return true
   * @return false
   */
  bool empty() const ;

  /**
   * @brief Insert and sort the element.
   *
   * @param e The element.
   */
  void insert(const E &e) ;

  /**
   * @brief Get the smallest key element.
   *
   * @return const E&
   */
  const E &min() ;

  /**
   * @brief Remove the smallest key element.
   *
   */
  void removeMin() ;

private:
#pragma region HEAPPRIORITYQUEUE_VARIABLES
  Heap T;
  C isLess;
  typedef typename Heap::Position Position; // a shortcut

#pragma endregion HEAPPRIORITYQUEUE_VARIABLES
};

} // namespace LittleData
#endif HEAP_PRIORITY_QUEUE_HPP