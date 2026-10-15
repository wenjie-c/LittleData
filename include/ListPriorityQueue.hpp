#include <Comparator.hpp>
#include <NodeList.hpp>
#include <definitions.hpp>
#include <iostream>

using namespace std;

#ifndef LISTPRIORITYQUEUE_HPP
#define LISTPRIORITYQUEUE_HPP

namespace LittleData {

/**
 * @brief A Priority Queue based on NodeList.
 *
 * @tparam E Element Type
 * @tparam C Comparator Type
 */
template <typename E, typename C>
class ListPriorityQueue : IPriorityQueue<E, C> {
public:
  /**
   * @brief Size of the priority queue.
   *
   * @return int
   */
  int size() const override;

  /**
   * @brief Is the priority queue empty?
   *
   * @return true
   * @return false
   */
  bool empty() const override;

  /**
   * @brief Insert and sort the element.
   *
   * @param e The element.
   */
  void insert(const E &e) override;
  /**
   * @brief Get the smallest key element.
   *
   * @return const E&
   */
  const E &min() const override;
  /**
   * @brief Remove the smallest key element.
   *
   */
  void removeMin() override;

private:
  NodeList<E> L;
  C isLess;
};

typedef pair<int, int> Pair; // Key-Value pair.

} // namespace LittleData

#endif // LISTPRIORITYQUEUE_HPP