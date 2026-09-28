#include <Digraph.hpp>

template <typename V> Vertex<V> *DiEdge<V>::opposite(Vertex<V> *v) {
  if (v == _origin)
    return _destination;
  if (v == _destination)
    return _origin;
  throw DataException("This edge is not incident on this vertex.");
}

template <typename V> bool DiEdge<V>::isAdjacentTo(const IEdge<V> *edge) const {
  const DiEdge<V>* diedge = dynamic_cast<const DiEdge<V>*>(edge);
  if(diedge == NULL) return false;
  return (diedge->_origin == this->_origin &&
          diedge->_destination == this->_destination);
}

template <typename V> bool DiEdge<V>::isIncidentOn(const Vertex<V> *v) const {
    return _origin == v || _destination == v;
}

template <typename V> 
void DiGraph<V>::insertEdge(uint a, uint b, uint weight) {
    auto first = this->find(a);
    auto second = this->find(b);
    this->_edges.push_back(new DiEdge<V>(first,second, weight));
  first->_incident.push_back(this->_edges.back());
  second->_incident.push_back(this->_edges.back());
}

#pragma region EXPLICIT_INSTATIATION

template class DiGraph<int>;
#pragma endregion EXPLICIT_INSTATIATION