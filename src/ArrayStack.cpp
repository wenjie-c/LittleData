#include <ArrayStack.hpp>

using namespace std;

namespace LittleData {

template<typename E>
ArrayStack<E>::ArrayStack(int capacity) : _array(new E[capacity]),_capacity(capacity),t(-1) {}

template<typename E>
int ArrayStack<E>::size() const {return t + 1;}

template<typename E>
bool ArrayStack<E>::empty() const {return t < 0;}

template<typename E>
const E &ArrayStack<E>::top() const 
{
    if(empty()) throw DataException("The array is empty.");
    return _array[t];
}

template<typename E>
void ArrayStack<E>::push(const E &data)
{
    if(size() == _capacity) throw DataException("The array is full.");
    t++;
    _array[t] = data;
}

template<typename E>
void ArrayStack<E>::pop()
{
    if(empty()) throw DataException("The array is empty.");
    t--;
}

template<typename E>
ArrayStack<E>::~ArrayStack()
{
    delete [] _array;
}

#pragma region EXPLICIT_INSTATIATION
template class ArrayStack<int>;
#pragma endregion EXPLICIT_INSTATIATION

}