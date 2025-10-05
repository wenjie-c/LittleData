#include <definitions.hpp>

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

using namespace std;

namespace LittleData {
  
  /**
   * @brief Implementation of a List with doubly ended list and iterators
   * 
   * @tparam E 
   */
template <typename E> class NodeList {
private:


public:
  class Iterator {
  public:
    /**
     * @brief References the element.
     *
     * @return E*
     */
    E &operator*();

    /**
     * @brief Compares positions.
     *
     * @param p
     * @return true
     * @return false
     */
    bool operator==(const Iterator &p) const;

    bool operator!=(const Iterator &p) const;

    /**
     * @brief Move to the next position.
     *
     * @return Iterator<E>&
     */
    Iterator &operator++();

    /**
     * @brief Move to the previous position.
     *
     * @return Iterator<E>&
     */
    Iterator &operator--();
    ~Iterator();

    /**
     * @brief Gives access to NodeList
     *
     */
     
     friend class NodeList<E>;
     private:
    Node<E> *v;
    /**
     * @brief Construct a new Iterator object
     *
     * @param u
     */
    Iterator(Node<E> * u);
  };

  public:
  /**
   * @brief Construct a new Node List< E> object
   * 
   */
  NodeList<E>();
  /**
   * @brief Size of the list.
   * 
   * @return int 
   */
  int size() const;

  /**
   * @brief Is the list empty?
   * 
   * @return true 
   * @return false 
   */
  bool empty() const;

  /**
   * @brief Initial position.
   * 
   * @return Iterator 
   */
  Iterator begin() const;

  /**
   * @brief Final position (just after it).
   * 
   * @return Iterator 
   */
  Iterator end() const;

  /**
   * @brief Insert to frontal.
   * 
   * @param data 
   */
  void insertFront(const E & data);

  /**
   * @brief Insert to end.
   * 
   * @param data 
   */
  void insertBack(const E & data);

  /**
   * @brief Insert data before p.
   * 
   * @param p 
   * @param data 
   */
  void insert(const Iterator & p, const E & data);

  /**
   * @brief Erase the frontal element.
   * 
   */
  void eraseFront();

  /**
   * @brief Erase the last element.
   * 
   */
  void eraseBack();
  /**
   * @brief Erase p element.
   * 
   * @param p 
   */
  void erase(const Iterator &p);
  
  NodeList<E>(NodeList<E> & tobeCopied);

  // --- Housekeeping functions ---

  ~NodeList<E>();

  // --- End of housekeeping functions ---
  private:
  int n;
  Node<E> * header;
  Node<E> * trailer;
};

} // namespace LittleData

#endif ITERATOR_HPP