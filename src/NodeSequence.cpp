#include <NodeSequence.hpp>
#include <Tree.hpp>
#include <iterator>
using namespace std;

template <typename E>
typename LittleData::NodeList<E>::Iterator LittleData::NodeSequence<E>::atIndex(int i) const
{
    auto p = this->begin();
    for(int j = 0; j < i; j++) ++p;
    return p;
}

template <typename E>
int LittleData::NodeSequence<E>::indexOf(const typename LittleData::NodeList<E>::Iterator p) const
{
    auto q = this->begin();
    int j = 0;
    while(q != p)
    {
        ++q; ++j;
    }
    return j;
}

#pragma region EXPLICIT_INSTATIATION
template class LittleData::NodeSequence<int>;
template class LittleData::NodeSequence<TreeNode<int>*>;
#pragma endregion EXPLICIT_INSTATIATION