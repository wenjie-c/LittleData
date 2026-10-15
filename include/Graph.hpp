#include <definitions.hpp>
#include <sys/types.h>
#include <vector>

#ifndef Graph_HPP
#define Graph_HPP

// template <typename V> class Graph;
template <typename V> class IGraph;
template <typename V> class IEdge;

/**
 * @brief A graph vertex with a value
 *
 * @tparam V
 */
template <typename V> class Vertex {
public:
  Vertex(const uint key, const V value) : _key(key), _value(value) {}

  /**
   * @brief Return the incident edges on this vertex.
   *
   * @return const vector<IEdge<V> *>&
   */
  const vector<IEdge<V> *> &incidentEdges() const;

  /**
   * @brief Check if the vertex is adjacent to this vertex.
   *
   * @param vertex
   * @return true
   * @return false
   */
  bool isAdjacentTo(Vertex *vertex) const;

  /* const V &operator*() { return getValue(); } */

  /**
   * @brief Get the Value object
   *
   * @return const V&
   */
  const V &getValue() { return _value; }

  /**
   * @brief Set the Value object
   *
   * @param value
   */
  void setValue(V value) { _value = value; }

  /**
   * @brief Get the Key object
   *
   * @return const uint&
   */
  const uint &getKey() { return _key; }

  /* protected: */ // Can't use protected due to I can't add Graph as friend
                   // class
  V _value;
  uint _key;
  vector<IEdge<V> *> _incident;
  /**
   * @brief Erase an incident edge, as an internal utility fucntion. Called when
   * an edge is deleted.
   *
   * @param incident
   */
  void eraseIncidentEdge(IEdge<V> *incident);
  friend class IGraph<V>;
};

/**
 * @brief The Edge Interface
 *
 * @tparam V
 */
template <typename V> class IEdge {
public:
  /**
   * @brief Get both endVertices.
   *
   * @return const vector<Vertex<V> *>
   */
  virtual const vector<Vertex<V> *> endVertices() = 0;

  /**
   * @brief Get the opposite vertex of the given vertex. Exception occurs when
   * the given vertex is not an end vertex of this edge.
   *
   * @param v
   * @return Vertex<V>*
   */
  virtual Vertex<V> *opposite(Vertex<V> *v) = 0;

  /**
   * @brief Check whether the given edge is parallel to this edge.
   *
   * @param edge
   * @return true
   * @return false
   */
  virtual bool isAdjacentTo(const IEdge<V> *edge) const = 0;

  /**
   * @brief Check whether this edge is incident on the given vertex is incident
   *
   * @param v
   * @return true
   * @return false
   */
  virtual bool isIncidentOn(const Vertex<V> *v) const = 0;

  /**
   * @brief Get the Weight object
   *
   * @return const uint&
   */
  virtual const uint &getWeight() = 0;

  /**
   * @brief Set the Weight object
   *
   * @param value
   */
  virtual void setWeight(uint value) = 0;

  virtual ~IEdge<V>() = default;
};

/**
 * @brief The undirected edge implementation
 *
 * @tparam V
 */
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
  bool isAdjacentTo(const IEdge<V> *edge) const override;

  /**
   * @brief Check if this edge is incident on vertex v.
   *
   * @param v
   * @return true
   * @return false
   */
  bool isIncidentOn(const Vertex<V> *v) const override;

  const uint &getWeight() override { return _weight; }

  void setWeight(uint value) override { _weight = value; }

  /* protected: */ // Can't use protected due to I can't add Graph as friend
                   // class
  uint _weight;
  Vertex<V> *_terminals[2];
  friend class IGraph<V>;
};

/**
 * @brief The Graph Interface
 *
 * @tparam V
 */
template <typename V> class IGraph {
public:
  IGraph() {}
  /**
   * @brief Get all the vertices of this graph.
   *
   * @return const vector<Vertex<V> *>&
   */
  virtual const vector<Vertex<V> *> &vertices() = 0;

  /**
   * @brief Get all the edges of this graph.
   *
   * @return const vector<IEdge<V> *>&
   */
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

  /**
   * @brief Find the vertex with the given key.
   *
   * @param key
   * @return Vertex<V>*
   */
  virtual Vertex<V> *find(const uint key) const = 0;

  /**
   * @brief Find the vertex with the given key.
   *
   * @param key
   * @return Vertex<V>*
   */
  virtual Vertex<V> *operator[](const uint key) const = 0;

  /**
   * @brief Erase the given vertex. Exception occurs if the given vertex doesn't
   * exist.
   *
   * @param vertex
   */
  virtual void eraseVertex(Vertex<V> *vertex) = 0;

  /**
   * @brief Erase the given edge. Exception occurs if the given edge doesn't
   * exist.
   *
   * @param edge
   */
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
 * @brief Undirected Graph implementation.
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