#include <definitions.hpp>

using namespace std;

#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

namespace LittleData
{

enum {ARRAYSTACK_CAPACITY = 64};

template<typename E>
class ArrayStack : public IStack<E>
{
    public:
    /**
     * @brief Construct a new Array Stack< E> object
     * 
     * @param capacity Maximum size of the internal array.
     */
    ArrayStack<E>(int capacity = ARRAYSTACK_CAPACITY);
    ~ArrayStack();

    /**
     * @brief Number of items in the stack.
     * 
     * @return int 
     */
    int size() const;

    /**
     * @brief Is the stack empty?
     * 
     * @return true 
     * @return false 
     */
    bool empty() const;

    /**
     * @brief The frontal element
     * 
     * @return const E& 
     */
    const E & top() const;

    /**
     * @brief Insert data in the stack.
     * 
     * @param data 
     */
    void push(const E & data);

    /**
     * @brief Delete the frontal element.
     * 
     */
    void pop();
    private:
    E * _array;
    int _capacity;
    int t; // Index of frontal element
    
};


}

#endif ARRAYSTACK_HPP