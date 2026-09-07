#include <definitions.hpp>
#include <sys/types.h>
#include <vector>

#ifndef Graph_HPP
#define Graph_HPP

template <typename V> class Graph;
template <typename V> class Edge;

template <typename V> class Vertex {
public:
  Vertex(const uint key, const V value) : _key(key), _value(value) {}

  const vector<Edge<V> *> &incidentEdges() const;

  bool isAdjacentTo(Vertex *vertex);

  /* const V &operator*() { return getValue(); } */

  const V &getValue() { return _value; }

  void setValue(V value) { _value = value; }

  const uint &getKey() { return _key; }

protected:
  V _value;
  uint _key;
  vector<Edge<V> *> _incident;
  void eraseIncidentEdge(Edge<V> *incident);
  friend class Graph<V>;
};

template <typename V> class Edge {
public:
  Edge(Vertex<V> *a, Vertex<V> *b, const uint weight = 0)
      : _weight(weight), _terminals({a, b}) {}
  const vector<Vertex<V> *> endVertices() const {
    return vector<Vertex<V> *>({_terminals[0], _terminals[1]});
  }
  Vertex<V> *opposite(Vertex<V> *v);

  /**
   * @brief Check if the edge has the same end vertices.
   *
   * @param edge
   * @return true
   * @return false
   */
  bool isAdjacentTo(const Edge<V> *edge);

  /**
   * @brief Check if this edge is incident on vertex v.
   *
   * @param v
   * @return true
   * @return false
   */
  bool isIncidentOn(const Vertex<V> *v);

  const uint &getWeight() { return _weight; }

  void setWeight(uint value) { _weight = value; }

protected:
  uint _weight;
  Vertex<V> *_terminals[2];
  friend class Graph<V>;
};

/**
 * @brief Undirected Graph
 *
 * @tparam V
 */
template <typename V> class Graph {
public:
  Graph() {}

  const vector<Vertex<V> *> &vertices() { return _vertices; }
  const vector<Edge<V> *> &edges() { return _edges; }

  /**
   * @brief Insert a vertex with a value
   *
   * @param value The value
   */
  void insertVertex(const uint key, V value);

  /**
   * @brief Insert an edge between vertex with value a and vertex with value b
   * with a given weight.
   *
   * @param a
   * @param b
   * @param weight
   */
  /* void insertEdge(V a, V b, uint weight = 0); */

  /**
   * @brief Insert an edge between vertex number a and vertex number b with a
   * given weight. The number corresponds to the node's key.
   *
   * @param a
   * @param b
   * @param weight
   */
  void insertEdge(uint a, uint b, uint weight = 0);

  Vertex<V> *find(const uint key) const;
  Vertex<V> *operator[](const uint key) const;

  void eraseVertex(Vertex<V> *vertex);
  void eraseEdge(Edge<V> *edge);

  ~Graph<V>() {
    for (int i = 0; i < _vertices.size(); i++) {
      delete _vertices[i];
    }
    for (int i = 0; i < _edges.size(); i++) {
      delete _edges[i];
    }

    _vertices.clear();
    _edges.clear();
  }

protected:
  vector<Vertex<V> *> _vertices;
  vector<Edge<V> *> _edges;
};
#endif // Graph_HPP