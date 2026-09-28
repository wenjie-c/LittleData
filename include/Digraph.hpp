#ifndef DiGraph_HPP
#define DiGraph_HPP

#include <Graph.hpp>

/**
 * @brief Directed Edge
 *
 * @tparam V
 */
template <typename V> class DiEdge : public IEdge<V> {
public:
  DiEdge<V>(Vertex<V> *origin, Vertex<V> *destination, const uint weight = 0)
      : _origin(origin), _destination(destination), _weight(weight) {}

  const vector<Vertex<V> *> endVertices() override {
    return {_origin, _destination};
  }
  Vertex<V> *opposite(Vertex<V> *v) override;
  bool isAdjacentTo(const IEdge<V> *edge) const override;
  bool isIncidentOn(const Vertex<V> *v) const override;
  const uint &getWeight() override {return _weight;}
  void setWeight(uint value) override {_weight = value;}
  Vertex<V> *origin() { return _origin; }
  Vertex<V> *destination()  { return _destination; }

protected:
  uint _weight;
  Vertex<V> *_origin;
  Vertex<V> *_destination;
};

template <typename V> class DiGraph : public Graph<V> {
public:
  DiGraph() {}
  virtual void insertEdge(uint a, uint b, uint weight = 0) override;

private:
#pragma region DiGraph_VARIABLES

#pragma endregion DiGraph_VARIABLES
};
#endif // DiGraph_HPP