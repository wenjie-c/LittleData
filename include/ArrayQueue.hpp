#include <definitions.hpp>

using namespace std;

namespace LittleData {

enum {ARRAYQUEUE_CAPACITY = 64} ;

/**
 * @brief A Queue structure based on array.
 * 
 * @tparam E 
 */
template <typename E>
class ArrayQueue : public IQueue<E> {
public:
/**
 * @brief Construct a new Array Queue< E> object
 * 
 * @param capacity 
 */
ArrayQueue<E>(int capacity = ARRAYQUEUE_CAPACITY);

/**
 * @brief Size of the queue.
 * 
 * @return int 
 */
  int size() const;

  /**
   * @brief Is the queue empty?
   * 
   * @return true 
   * @return false 
   */
  bool empty() const;

  /**
   * @brief Frontal element.
   * 
   * @return const E& 
   */
  const E &front() const;

  /**
   * @brief Enqueue an element.
   * 
   * @param data 
   */
  void enqueue(const E &data);

  /**
   * @brief Dequeue an element.
   * 
   */
  void dequeue();
  ~ArrayQueue();

private:
  E *_array;
  int _capacity; // total capacity
  int n; // actual size
  int f; // frontal position
  int r; // end position
};
} // namespace LittleData