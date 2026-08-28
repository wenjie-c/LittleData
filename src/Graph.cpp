#include <Graph.hpp>
#include <algorithm>
#include <vector>

template <typename V>
const vector<Edge<V> *> &Vertex<V>::incidentEdges() const {
  return _incident;
}

template <typename V> bool Vertex<V>::isAdjacentTo(Vertex *vertex) {
  for (int i = 0; i < _incident.size(); i++) {
    auto edge = _incident[i];
    if (edge->isIncidentOn(this) && edge->isIncidentOn(vertex)) // the first part of statement is unnecessary
      return true;
  }
  return false;
}

template <typename V>
void Vertex<V>::eraseIncidentEdge(Edge<V> * incident) {
  if(!incident->isIncidentOn(this)) throw DataException("This edge is not incident on this vertex.");
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



template <typename V> bool Edge<V>::isAdjacentTo(const Edge<V> *edge) {
  return (_terminals[0] == edge->_terminals[0] &&
          _terminals[1] == edge->_terminals[1]) ||
         (_terminals[1] == edge->_terminals[0] &&
          _terminals[0] == edge->_terminals[1]);
}

template <typename V> bool Edge<V>::isIncidentOn(const Vertex<V> *v) {
  return (_terminals[0] == v || _terminals[1] == v);
}

template <typename V> void Graph<V>::insertVertex(V value) {
  _vertices.push_back(new Vertex<V>(value));
}

template <typename V> void Graph<V>::insertEdge(V a, V b, uint weight) {
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
}

template <typename V> void Graph<V>::insertEdge(uint a, uint b, uint weight) {
  if (a > _vertices.size() || b > _vertices.size())
    throw DataException("Vertex number a or b is out of range.");
  _edges.push_back(new Edge<V>(_vertices[a], _vertices[b], weight));
}

template <typename V> void Graph<V>::eraseVertex(Vertex<V> *vertex) {

  auto found = find_if(_vertices.begin(), _vertices.end(),
                       [&](Vertex<V> *vertex2) { return vertex2 == vertex; });
  if (found == _vertices.cend())
    throw DataException("This graph does not have the vertex.");

  /* remove_if(_edges.begin(), _edges.end(),
            [&](Edge<V> *edge) {
              delete edge;
              return edge->isIncidentOn(vertex); }); */

  /* auto found2 = find_if(_edges.begin(), _edges.end(), [&](Edge<int> *edge) {
    return edge->isIncidentOn(vertex);
  });
  (*found2)->opposite(*found)->eraseIncidentEdge(*found2); */
  auto incidents= (*found)->incidentEdges();
  delete (*found);
  _vertices.erase(found);
  for(Edge<V> * edge : incidents){
    eraseEdge(edge);
  }
  
  /* delete (*found2); */
  
  /* _edges.erase(found2); */
}

template <typename V> void Graph<V>::eraseEdge(Edge<V> *edge) {
  /* remove_if(_edges.begin(), _edges.end(),
            [&](Edge<V> *edge2) { return (edge2) == (edge); }); */
            auto found = find_if(_edges.begin(), _edges.end(),
          [&](Edge<V> * edge2){ return edge2 == edge ;});
          for(int i = 0; i < _vertices.size(); i++){
            if(edge->isIncidentOn(_vertices[i]))
              _vertices[i]->eraseIncidentEdge(edge);
          }
          delete(*found);
          _edges.erase(found);
}

#pragma region EXPLICIT_INSTATIATION
template class Vertex<int>;
template class Edge<int>;
template class Graph<int>;
#pragma endregion EXPLICIT_INSTATIATION