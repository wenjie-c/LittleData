#include <primitives.hpp>

#ifndef LINKEDQUEUE_HPP
#define LINKEDQUEUE_HPP

using namespace std;

namespace LittleData {

/**
 * @brief A Queue structure based on Linked List
 *
 * @tparam E
 */
template <typename E> class LinkedQueue {
public:
  /**
   * @brief Construct a new Linked Queue< E> object
   *
   */
  LinkedQueue<E>();

  int size() const;

  /**
   * @brief Is the queue empty?
   *
   * @return true
   * @return false
   */
  bool empty() const;

  /**
   * @brief Frontal element
   *
   * @return const E&
   */
  const E &front() const /* throw(DataException) */;

  /**
   * @brief Enqueue an element in the queue.
   *
   * @param data
   */
  void enqueue(const E &data);

  /**
   * @brief Dequeue an element from the queue.
   *
   */
  void dequeue() /* throw (DataException) */;

private:
  CircleList<E> C;
  int n;
};

} // namespace LittleData

#endif //LINKEDQUEUE_HPP