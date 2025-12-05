#include <HeapPriorityQueue.hpp>

using namespace std;

namespace LittleData {

template <typename E, typename C>
int HeapPriorityQueue<E,C>::size() const 
{
    return T.size();
}

template <typename E, typename C>
bool HeapPriorityQueue<E,C>::empty() const
{
    return T.empty();
}

template <typename E, typename C>
void HeapPriorityQueue<E,C>::insert(const E &e)
{
    T.addLast(e); // add e to heap
    Position v = T.last();
    while(!T.isRoot(v)) //up-heap bubbling
    {
        Position u = T.parent(v);
        if(!isLess(*v,*u)) break; // if v is already in order, then we are done
        T.swap(v,u); // otherwise, swap with its parent
        v = u;
    }
}

template <typename E, typename C>
const E &HeapPriorityQueue<E,C>::min()
{
    return *(T.root());
}

template <typename E, typename C>
void HeapPriorityQueue<E,C>::removeMin()
{
    if(size() == 1) // only one node?
        T.removeLast(); // ... delete the last one
    else
    {
        Position u = T.root(); // root position
        T.swap(u, T.last()); // swap between root and last node
        T.removeLast();
        while(T.hasLeft(u)) // down-heap bubbling
        {
            Position v = T.left(u);
            if(T.hasRight(u) && isLess(*(T.right(u)),*v))
                v = T.right(u); // is u's smallest children
            if(isLess(*v,*u)) // check if it's out of order
            {
             T.swap(u,v);
             u = v;
            }
            else break; // otherwise, we are done
        }
    }
}

#pragma region EXPLICIT_INSTATIATION
template class HeapPriorityQueue<Pair, IsLess>;
#pragma endregion EXPLICIT_INSTATIATION

} // namespace LittleData