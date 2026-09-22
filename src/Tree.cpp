#include <Tree.hpp>

template <typename E> const string Tree<E>::drawTree() {
  stringstream ss;

  ss << _root->value << " [ROOT]" << endl;
  for (auto iter = _root->children.begin(); iter != _root->children.end();
       ++iter) {
    ss << drawNode(*iter, 1);
  }
  return ss.str();
}

template <typename E>
const string Tree<E>::drawNode(TreeNode<E> *node, unsigned int level) {
  stringstream ss;

  ss << node->print();
  if (node->children.empty()) {
    ss << endl;
    return ss.str();
  }
  ss << ":" << endl;
  for (auto iter = node->children.begin(); iter != node->children.end();
       ++iter) {
    for (int i = 0; i < level; i++) {
      ss << " ";
    }
    ss << drawNode(*iter, level + 1);
  }
  return ss.str();
}

#pragma region EXPLICIT_INSTATIATION
template class Tree<int>;
template class TreeNode<int>;
#pragma endregion EXPLICIT_INSTATIATION