
#include <cstddef>
#include<definitions.hpp>

#ifndef LINKEDBINARYTREE_HPP
#define LINKEDBINARYTREE_HPP

using namespace std;

namespace LittleData {
template<typename E>
class LinkedBinaryTree : public IBinaryTree<E>
{
    public:
    class Position{
        private:
        TreeNode<E> * v;
        public:
        /**
         * @brief Construct a new Position object
         * 
         * @param _v 
         */
        Position(TreeNode<E> * _v = NULL);
        /**
         * @brief Get the element.
         * 
         * @return E& 
         */
        E & operator*();

        E * operator->() const;

        bool operator==(Position  pos) const {return this->v == pos.v;}

        /**
         * @brief get the left child.
         * 
         * @return Position 
         */
        Position left() const;
        /**
         * @brief Get the right child.
         * 
         * @return Position 
         */
        Position right() const;
        /**
         * @brief Get the parent.
         * 
         * @return Position 
         */
        Position parent() const;
        /**
         * @brief Is the root of the tree.
         * 
         * @return true 
         * @return false 
         */
        bool isRoot() const;
        /**
         * @brief Is an external node?
         * 
         * @return true 
         * @return false 
         */
        bool isExternal() const;

        /**
         * @brief Swap both 
         * 
         * @param b 
         */
        void swap(Position & b);

        friend class LinkedBinaryTree<E>;
        friend class DLinkedList<LinkedBinaryTree<E>::Position>;

        friend class SearchTree;
    };
    typedef DLinkedList<LinkedBinaryTree<E>::Position> PositionList;
    public:
    /**
     * @brief Construct a new Linked Binary Tree< E> object
     * 
     */
    LinkedBinaryTree<E>();

    /**
     * @brief Number of nodes.
     * 
     * @return int 
     */
    int size() const;

    /**
     * @brief Is the tree empty?
     * 
     * @return true 
     * @return false 
     */
    bool empty() const;

    /**
     * @brief Get the root.
     * 
     * @return Position 
     */
    Position root() const;

    /**
     * @brief List of nodes.
     * 
     * @return PositionList 
     */
    PositionList positions() const;

    /**
     * @brief Add a root into an empty tree.
     * 
     */
    void addRoot();

    /**
     * @brief Expand external node.
     * 
     * @param p 
     */
    void expandExternal(const Position & p);

    /**
     * @brief Delete p and its parent.
     * 
     * @param p 
     * @return Position 
     */
    Position removeAboveExternal(const Position & p);

    // --- Housekeeping functions ---

    ~LinkedBinaryTree<E>();

    // --- End of housekeeping functions ---
    protected:
    /**
     * @brief Preorder utility.
     * 
     * @param v 
     * @param pl 
     */
    void preorder(TreeNode<E> * v, PositionList & pl) const;
    Position leftEnd();
    private:
    TreeNode<E> * _root;
    int n;
};

}

#endif LINKEDBINARYTREE_HPP