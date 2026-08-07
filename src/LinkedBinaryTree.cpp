#include<LinkedBinaryTree.hpp>

using namespace std;
namespace LittleData
{
    template<typename E>
    LinkedBinaryTree<E>::Position::Position(TreeNode<E> * _v) : v(_v) {} 
    template<typename E>
    E & LinkedBinaryTree<E>::Position::operator*()
    {
        return v->value;
    }

    template<typename E>
    E * LinkedBinaryTree<E>::Position::operator->() const{
        return &v->value;
    }
    template<typename E>
    typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::Position::left() const
    {
        return Position(v->left);
    }
    template<typename E>
    typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::Position::right() const
    {
        return Position(v->right);
    }
    template<typename E>
    typename LinkedBinaryTree<E>::Position  LinkedBinaryTree<E>::Position::parent() const
    {
        return Position(v->parent);
    }
    template<typename E>
    bool LinkedBinaryTree<E>::Position::isRoot() const
    {
        return v->parent == NULL;
    }
    template<typename E>
    typename LinkedBinaryTree<E>::PositionList LinkedBinaryTree<E>::positions() const
    {
        PositionList pl;
        preorder(_root,pl); // return the list of results
        return PositionList(pl); //return the list of results
    }
    template<typename E>
    bool LinkedBinaryTree<E>::Position::isExternal() const
    {
        return v->left == NULL && v->right == NULL;
    }
    template<typename E>
    LinkedBinaryTree<E>::LinkedBinaryTree() : _root(NULL), n(0) {}

    template<typename E>
    int LinkedBinaryTree<E>::size() const
    {
        return n;
    }
    template<typename E>
    bool LinkedBinaryTree<E>::empty() const
    {
        return size() == 0;
    }
    template<typename E>
    typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::root() const
    {
        if(empty()) throw DataException("The Linked Binary Tree is empty.");
        return Position(_root);
    }
    template<typename E>
    void LinkedBinaryTree<E>::addRoot()
    {
        if(!empty()) throw DataException("The Linked Binary Tree is not empty.");
        _root = new TreeNode<E>;
        n = 1;
    }
    template<typename E>
    void LinkedBinaryTree<E>::expandExternal(const Position & p)
    {
        if(!p.isExternal()) throw DataException("Node in position P is not an external Node.");
        TreeNode<E> * v = p.v; // p node
        v->left = new TreeNode<E>; // add a new left child
        v->left->parent = v; // v is its parent
        v->right = new TreeNode<E>; // add a new right child
        v->right->parent = v; // v is its parent
        n += 2;
    }
    template<typename E>
    typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::removeAboveExternal(const Position & p)
    {
        if(!p.isExternal() || p.isRoot()) throw DataException("Node in position P is not an external Node or it is the root.");
        TreeNode<E> * w = p.v; TreeNode<E> * v = w->parent; // get the node p amd its parent.
        TreeNode<E> * sib = (w == v->left ? v->right : v->left);
        if(v == _root) // is child of root?
        {
            _root = sib; // turn the root sibling
            sib->parent = NULL;
        }
        else
        {
            TreeNode<E> * gpar = v->parent;
            if(v == gpar->left) gpar->left = sib; // replace parent for sibling
            else gpar->right = sib;
            sib->parent = gpar;
        }
        delete w; delete v; // delete all nodes
        n -= 2; // 2 nodes less
        return Position(sib);
    }
    
    template<typename E>
    void LinkedBinaryTree<E>::preorder(TreeNode<E> * v, PositionList & pl) const
    {
        pl.addBack(Position(v)); // add this node
        if(v->left != NULL) // traverse the left subtree
        preorder(v->left, pl);
        if(v->right != NULL) // traverse the right subtree
        preorder(v->right, pl);
    }

    template<typename E>
    LinkedBinaryTree<E>::~LinkedBinaryTree()
    {
        Position leaf = leftEnd();
        while(size() != 1)
        {
            removeAboveExternal(leaf);
            leaf = leftEnd();
        }
        delete _root;
        n = 0;
    }

    template<typename E>
    typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::leftEnd()
    {
        Position node = root();
        while(!node.isExternal())
        {
            node = node.left();
        }
        return node;
    }

    template<typename E>
    void LinkedBinaryTree<E>::Position::swap(Position & b) {
        auto valueA = v->value;
        v->value = b.v->value;
        b.v->value = valueA;
    }

    
#pragma region EXPLICIT_INSTATIATION
template class LinkedBinaryTree<int>;
#pragma endregion EXPLICIT_INSTATIATION
}