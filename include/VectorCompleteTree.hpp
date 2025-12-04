#include <definitions.hpp>
#include <primitives.hpp>
#include <vector>

using namespace std;

#ifndef COMPLETE_TREE_HPP
#define COMPLETE_TREE_HPP

namespace LittleData {

/**
 * @brief Complete Binary Tree or Heap based on a std::vector.
 * 
 * @tparam E 
 */
template <typename E> class VectorCompleteTree : public IBinaryTree<E> {
private:
  //NodeList<E> V;
  vector<E> V;

public:

  VectorCompleteTree() : V(1) {}
  // class Position;
  typedef typename vector<E>::iterator Position;
  int size() const override;
  bool empty() const override;

  /**
   * @brief Get the left child of the node.
   *
   * @param p The node.
   * @return Position
   */
  Position left(const Position &p);

  /**
   * @brief Get the right child of the node.
   *
   * @param p The node.
   * @return Position
   */
  Position right(const Position &p);

  /**
   * @brief Get the parent child of the node.
   *
   * @param p The node.
   * @return Position
   */
  Position parent(const Position &p);

  /**
   * @brief Check if has left child.
   *
   * @param p
   * @return true
   * @return false
   */
  bool hasLeft(const Position &p) const;

  /**
   * @brief Check if has right child.
   *
   * @param p
   * @return true
   * @return false
   */
  bool hasRight(const Position &p) const;

  /**
   * @brief Check if it is root.
   *
   * @param p
   * @return true
   * @return false
   */
  bool isRoot(const Position &p) const;

  /**
   * @brief Get the position of the root.
   * 
   * @return Position 
   */
  Position root();

  /**
   * @brief Get the last position of teh tree.
   * 
   * @return Position 
   */
  Position last();

  /**
   * @brief Add a new last node.
   * 
   * @param e 
   */
  void addLast(const E & e);

  /**
   * @brief Remove the last node.
   * 
   */
  void removeLast();

  /**
   * @brief Swaps the content between node p and node q.
   * 
   * @param p 
   * @param q 
   */
  void swap(const Position & p, const Position & q);

protected:
  /**
   * @brief Map an index to a position.
   *
   * @param i
   * @return Position
   */
  Position pos(int i)
  {
    return V.begin() + i;
  }

  /**
   * @brief Map a position to an index.
   *
   * @param p
   * @return int
   */
  int idx(const Position &p) const
  {
    return p - V.begin();
  }
};

} // namespace LittleData

#endif COMPLETE_TREE_HPP