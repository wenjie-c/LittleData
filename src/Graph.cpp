#include <Graph.hpp>
#include <PVector.hpp>
#include <algorithm>
#include <vector>

template <typename V>
const vector<IEdge<V> *> &Vertex<V>::incidentEdges() const {
  return _incident;
}

template <typename V> bool Vertex<V>::isAdjacentTo(Vertex *vertex) const {
  for (int i = 0; i < _incident.size(); i++) {
    auto edge = _incident[i];
    if (edge->isIncidentOn(this) &&
        edge->isIncidentOn(
            vertex)) // the first part of statement is unnecessary
      return true;
  }
  return false;
}

template <typename V> void Vertex<V>::eraseIncidentEdge(IEdge<V> *incident) {
  if (!incident->isIncidentOn(this))
    throw DataException("This edge is not incident on this vertex.");
  auto found = find(_incident.begin(), _incident.end(), incident);
  _incident.erase(found);
}

template <typename V> Vertex<V> *Edge<V>::opposite(Vertex<V> *v) {
  if (_terminals[0] == v)
    return _terminals[1];
  else if (_terminals[1] == v)
    return _terminals[0];
  else
    throw DataException("This edge is not incident to vertex v.");
}

template <typename V> bool Edge<V>::isAdjacentTo(const IEdge<V> *edge) const {
  auto secondEdge = dynamic_cast<const Edge *>(edge);
  if (secondEdge == NULL)
    throw DataException(
        "You can't mix a no directed edge with a directed edge."); // or return
                                                                   // false
  return (_terminals[0] == secondEdge->_terminals[0] &&
          _terminals[1] == secondEdge->_terminals[1]) ||
         (_terminals[1] == secondEdge->_terminals[0] &&
          _terminals[0] == secondEdge->_terminals[1]);
}

template <typename V> bool Edge<V>::isIncidentOn(const Vertex<V> *v) const {
  return (_terminals[0] == v || _terminals[1] == v);
}

template <typename V> void Graph<V>::insertVertex(const uint key, V value) {
  this->_vertices.push_back(new Vertex<V>(key, value));
}

/* template <typename V> void Graph<V>::insertEdge(V a, V b, uint weight) {
  auto found =
      find_if(_vertices.begin(), _vertices.end(),
              [&](Vertex<V> *vertex) { return vertex->getValue() == a; });

  if (found == _vertices.cend())
    throw DataException("This graph does not have a vertex with value a.");

  auto found2 =
      find_if(_vertices.begin(), _vertices.end(),
              [&](Vertex<V> *vertex) { return vertex->getValue() == b; });

  if (found2 == _vertices.cend())
    throw DataException("This graph does not have a vertex with value b.");

  _edges.push_back(new Edge<V>((*found), (*found2), weight));
  (*found)->_incident.push_back(_edges.back());
  (*found2)->_incident.push_back(_edges.back());
} */

template <typename V> void Graph<V>::insertEdge(uint a, uint b, uint weight) {
  /* if (a > _vertices.size() || b > _vertices.size())
    throw DataException("Vertex number a or b is out of range."); */
  auto first = find(a);
  auto second = find(b);
  this->_edges.push_back(new Edge<V>(first, second, weight));
  first->_incident.push_back(this->_edges.back());
  second->_incident.push_back(this->_edges.back());
}

template <typename V> Vertex<V> *Graph<V>::find(const uint key) const {
  auto found =
      find_if(this->_vertices.cbegin(), this->_vertices.cend(),
              [key](Vertex<V> *node) { return node->getKey() == key; });
  if (found == this->_vertices.cend())
    throw DataException("Vertex with this key wasn't found");
  return (*found);
}

template <typename V> Vertex<V> *Graph<V>::operator[](const uint key) const {
  return find(key);
}

template <typename V> void Graph<V>::eraseVertex(Vertex<V> *vertex) {

  auto found = find_if(this->_vertices.begin(), this->_vertices.end(),
                       [&](Vertex<V> *vertex2) { return vertex2 == vertex; });
  if (found == this->_vertices.cend())
    throw DataException("This graph does not have the vertex.");

  /* remove_if(_edges.begin(), _edges.end(),
            [&](Edge<V> *edge) {
              delete edge;
              return edge->isIncidentOn(vertex); }); */

  /* auto found2 = find_if(_edges.begin(), _edges.end(), [&](Edge<int> *edge) {
    return edge->isIncidentOn(vertex);
  });
  (*found2)->opposite(*found)->eraseIncidentEdge(*found2); */
  auto incidents = (*found)->incidentEdges();
  delete (*found);
  this->_vertices.erase(found);
  for (IEdge<V> *edge : incidents) {
    eraseEdge(edge);
  }

  /* delete (*found2); */

  /* _edges.erase(found2); */
}

template <typename V> void Graph<V>::eraseEdge(IEdge<V> *edge) {
  /* remove_if(_edges.begin(), _edges.end(),
            [&](Edge<V> *edge2) { return (edge2) == (edge); }); */
  auto found = find_if(this->_edges.begin(), this->_edges.end(),
                       [&](IEdge<V> *edge2) { return edge2 == edge; });
  for (int i = 0; i < this->_vertices.size(); i++) {
    if (edge->isIncidentOn(this->_vertices[i]))
      this->_vertices[i]->eraseIncidentEdge(edge);
  }
  delete (*found);
  this->_edges.erase(found);
}

#pragma region EXPLICIT_INSTATIATION
template class Vertex<int>;
template class IEdge<int>;
template class Edge<int>;
template class IGraph<int>;
template class Graph<int>;
#pragma endregion EXPLICIT_INSTATIATION