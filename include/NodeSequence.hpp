
#include <NodeList.hpp>
using namespace std;

#ifndef NODESEQUENCE_HPP
#define NODESEQUENCE_HPP

namespace LittleData{
template <typename E> class NodeSequence : public LittleData::NodeList<E> {
public:
/**
 * @brief Get the position from the index.
 * 
 * @param i 
 * @return LittleData::NodeList<E>::Iterator 
 */
  typename LittleData::NodeList<E>::Iterator atIndex(int i) const;

  /**
   * @brief Get the index from the position.
   * 
   * @param p 
   * @return int 
   */
  int indexOf(const typename LittleData::NodeList<E>::Iterator p) const;
};
}
#endif NODESEQUENCE_HPP