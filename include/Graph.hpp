#include <definitions.hpp>
#include <sys/types.h>
#include <vector>

#ifndef Graph_HPP
#define Graph_HPP

// template <typename V> class Graph;
template <typename V> class IGraph;
template <typename V> class IEdge;

template <typename V> class Vertex {
public:
  Vertex(const uint key, const V value) : _key(key), _value(value) {}

  const vector<IEdge<V> *> &incidentEdges() const;

  bool isAdjacentTo(Vertex *vertex);

  /* const V &operator*() { return getValue(); } */

  const V &getValue() { return _value; }

  void setValue(V value) { _value = value; }

  const uint &getKey() { return _key; }

  /* protected: */ // Can't use protected due to I can't add Graph as friend
                   // class
  V _value;
  uint _key;
  vector<IEdge<V> *> _incident;
  void eraseIncidentEdge(IEdge<V> *incident);
  friend class IGraph<V>;
};

template <typename V> class IEdge {
public:
  virtual const vector<Vertex<V> *> endVertices() = 0;
  virtual Vertex<V> *opposite(Vertex<V> *v) = 0;
  virtual bool isAdjacentTo(const IEdge<V> *edge) = 0;
  virtual bool isIncidentOn(const Vertex<V> *v) = 0;
  virtual const uint &getWeight() = 0;
  virtual void setWeight(uint value) = 0;

  virtual ~IEdge<V>() = default;
};

template <typename V> class Edge : public IEdge<V> {
public:
  Edge(Vertex<V> *a, Vertex<V> *b, const uint weight = 0)
      : _weight(weight), _terminals{a, b} {}
  const vector<Vertex<V> *> endVertices() override {
    return vector<Vertex<V> *>({_terminals[0], _terminals[1]});
  }
  Vertex<V> *opposite(Vertex<V> *v) override;

  /**
   * @brief Check if the edge has the same end vertices.
   *
   * @param edge
   * @return true
   * @return false
   */
  bool isAdjacentTo(const IEdge<V> *edge) override;

  /**
   * @brief Check if this edge is incident on vertex v.
   *
   * @param v
   * @return true
   * @return false
   */
  bool isIncidentOn(const Vertex<V> *v) override;

  const uint &getWeight() override { return _weight; }

  void setWeight(uint value) override { _weight = value; }

  /* protected: */ // Can't use protected due to I can't add Graph as friend
                   // class
  uint _weight;
  Vertex<V> *_terminals[2];
  friend class IGraph<V>;
};

template <typename V> class IGraph {
public:
  IGraph() {}
  virtual const vector<Vertex<V> *> &vertices() = 0;
  virtual const vector<IEdge<V> *> &edges() = 0;

  /**
   * @brief Insert a vertex with a value
   *
   * @param value The value
   */
  virtual void insertVertex(const uint key, V value) = 0;

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
  virtual void insertEdge(uint a, uint b, uint weight = 0) = 0;

  virtual Vertex<V> *find(const uint key) const = 0;
  virtual Vertex<V> *operator[](const uint key) const = 0;

  virtual void eraseVertex(Vertex<V> *vertex) = 0;
  virtual void eraseEdge(IEdge<V> *edge) = 0;

  /* ~IGraph<V>() {
    for (int i = 0; i < _vertices.size(); i++) {
      delete _vertices[i];
    }
    for (int i = 0; i < _edges.size(); i++) {
      delete _edges[i];
    }

    _vertices.clear();
    _edges.clear();
  } */
  virtual ~IGraph<V>() = default;

protected:
  /* vector<Vertex<V> *> _vertices;
  vector<Edge<V> *> _edges; */
};

/**
 * @brief Undirected Graph
 *
 * @tparam V
 */
template <typename V> class Graph : public IGraph<V> {
public:
  Graph() {}

  virtual const vector<Vertex<V> *> &vertices() override {
    return this->_vertices;
  }
  virtual const vector<IEdge<V> *> &edges() override { return this->_edges; }

  /**
   * @brief Insert a vertex with a value
   *
   * @param value The value
   */
  virtual void insertVertex(const uint key, V value) override;

  /**
   * @brief Insert an edge between vertex with value a and vertex with value b
   * with a given weight.
   *
   * @param a
   * @param b
   * @param weight
   */
  /* void insertEdge(V a, V b, uint weight = 0) ; */

  /**
   * @brief Insert an edge between vertex number a and vertex number b with a
   * given weight. The number corresponds to the node's key.
   *
   * @param a
   * @param b
   * @param weight
   */
  virtual void insertEdge(uint a, uint b, uint weight = 0) override;

  virtual Vertex<V> *find(const uint key) const override;
  virtual Vertex<V> *operator[](const uint key) const;

  virtual void eraseVertex(Vertex<V> *vertex) override;
  virtual void eraseEdge(IEdge<V> *edge) override;

  virtual ~Graph<V>() {
    for (int i = 0; i < this->_vertices.size(); i++) {
      delete this->_vertices[i];
    }
    for (int i = 0; i < this->_edges.size(); i++) {
      delete this->_edges[i];
    }

    this->_vertices.clear();
    this->_edges.clear();
  }

protected:
  vector<Vertex<V> *> _vertices;
  vector<IEdge<V> *> _edges;
};
#endif // Graph_HPP