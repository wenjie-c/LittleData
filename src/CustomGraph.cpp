#include <CustomGraph.hpp>

template <typename V, typename F>
void CustomGraph<V, F>::insertEdge(uint a, uint b, F flag, const uint weight) {
  auto first = this->find(a);
  auto second = this->find(b);
  this->_edges.push_back(new CustomEdge<V, F>(first, second, flag, weight));
  first->_incident.push_back(this->_edges.back());
  second->_incident.push_back(this->_edges.back());
}