#include<primitives.hpp>

using namespace std;

#ifndef LINKEDDEQUE_HPP
#define LINKEDDEQUE_HPP

namespace LittleData {

template <typename E>
class LinkedDeque
{
    public:
    /**
     * @brief Construct a new Linked Deque< E> object
     * 
     */
    LinkedDeque<E>();

    /**
     * @brief Number of elements in the deque.
     * 
     * @return int 
     */
    int size() const;

    /**
     * @brief Is the deque empty?
     * 
     * @return true 
     * @return false 
     */
    bool empty() const;

    /**
     * @brief The first element.
     * 
     * @return const E& 
     */
    const E & front() const /* throw (DataException) */;

    /**
     * @brief The last element.
     * 
     * @return const E& 
     */
    const E & back() const /* throw(DataException) */;

    /**
     * @brief Insert a new element at the beginning.
     * 
     * @param data 
     */
    void insertFront(const E & data);

    /**
     * @brief Insert a new element at the end.
     * 
     * @param data 
     */
    void insertBack(const E & data);

    /**
     * @brief Remove the first element.
     * 
     */
    void removeFront() /* throw(DataException) */;

    /**
     * @brief Remove the last element.
     * 
     */
    void removeBack() /* throw(DataException) */;
    private:
    DLinkedList<E> D;
    int n;
};
}

#endif LINKEDDEQUE_HPP