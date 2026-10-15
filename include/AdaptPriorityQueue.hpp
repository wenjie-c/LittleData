#include <NodeList.hpp>
#include <definitions.hpp>
#include <Comparator.hpp>

#ifndef ADAPT_PRIORITY_QUEUE_HPP
#define ADAPT_PRIORITY_QUEUE_HPP

namespace LittleData {
  /**
   * @brief An extended Priority Queue based on NodeList.
   * 
   * @tparam E Value type
   * @tparam C Comparator type Comparator class derived
   */
template <typename E, typename C>
class AdaptPriorityQueue //: public IPriorityQueue<E, C> 
{

protected:
  typedef NodeList<E> ElementList;

public:
  class Position {
  private:
    typename ElementList::Iterator q;

  public:
    const E &operator*() { return *q; }
    friend class AdaptPriorityQueue<E, C>;
  };

public:

/**
   * @brief Size of the priority queue.
   *
   * @return int
   */
  int size() const;

  /**
   * @brief Is the priority queue empty?
   *
   * @return true
   * @return false
   */
  bool empty() const;

   /**
   * @brief Insert and sort the element.
   *
   * @param e The element.
   */
  Position insert(const E &e);

  /**
   * @brief Get the smallest key element.
   *
   * @return const E&
   */
  const E &min() const;

   /**
   * @brief Remove the smallest key element.
   *
   */
  void removeMin();

  /**
   * @brief Remove a value by position.
   * 
   * @param p The position
   */
  void remove(const Position & p);

  /**
   * @brief Replace a specific value by another one.
   * 
   * @param p Specific position.
   * @param e New value.
   * @return Position 
   */
  Position replace(const Position &p, const E &e);

private:
  ElementList L;
  C isLess;
};
} // namespace LittleData

#endif // ADAPT_PRIORITY_QUEUE_HPP