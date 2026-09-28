#include <Graph.hpp>

/**
 * @brief Same as Edge but with custom flag
 * 
 * @tparam V 
 * @tparam F Custom flag
 */
template <typename V, typename F> class CustomEdge : public Edge<V> {
public:
  CustomEdge(Vertex<V> *a, Vertex<V> *b, F customFlag, const uint weight = 0)
      : Edge<V>(a, b, weight), _flag(customFlag) {}


  F getFlag() { return _flag; }

  void setFlag(F value) { _flag = value; }

protected:
  F _flag;
};

/**
 * @brief Graph with custom edges
 * 
 * @tparam V 
 * @tparam F Custom Flag for each edge
 */
template <typename V, typename F>
class CustomGraph : public Graph<V> {
    public:
    CustomGraph<V, F>() {}
  /**
   * @brief Add a new edge between Vertices with key a and key b. It initialized the provided edge flags.
   * 
   * @param a 
   * @param b 
   * @param weight 
   */
    virtual void insertEdge(uint a, uint b, F flag ,uint weight = 0);
};