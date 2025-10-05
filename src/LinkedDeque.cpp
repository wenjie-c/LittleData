#include<LinkedDeque.hpp>

using namespace std;

namespace LittleData
{

template <typename E>
LittleData::LinkedDeque<E>::LinkedDeque() : D(), n(0) {}

template <typename E>
int LinkedDeque<E>::size() const
{
    return n;
}

template <typename E>
bool LittleData::LinkedDeque<E>::empty() const
{
    return n == 0;
}

template <typename E>
const E & LittleData::LinkedDeque<E>::front() const /* throw (DataException) */
{
    if(empty()) throw DataException("Deque is empty");
    return D.front();
}

template <typename E>
const E & LittleData::LinkedDeque<E>::back() const /* throw(DataException) */
{
    if(empty()) throw DataException("Deque is empty");
    return D.back();
}

template <typename E>
void LittleData::LinkedDeque<E>::insertFront(const E & data)
{
    D.addFront(data);
    n++;
}

template <typename E>
void LittleData::LinkedDeque<E>::insertBack(const E & data)
{
    D.addBack(data);
    n++;
}

template <typename E>
void LittleData::LinkedDeque<E>::removeFront() /* throw(DataException) */
{
    if(empty()) throw DataException("Removing front of empty deque");
    D.removeFront();
    n--;
}

template <typename E>
void LittleData::LinkedDeque<E>::removeBack() /* throw(DataException) */
{
    if(empty()) throw DataException("Removing back of empty deque");
    D.removeBack();
    n--;
}

#pragma region EXPLICIT_INSTATIATION
template class LinkedDeque<int>;
#pragma endregion EXPLICIT_INSTATIATION

}
