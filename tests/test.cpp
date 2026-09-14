#include "Digraph.hpp"
#include <LittleData.hpp>
#include <cstddef>
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(SLinkedListTest, SizeTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  SLinkedList<int> unit = SLinkedList<int>();
  unit.addFront(input1);
  unit.addFront(input2);
  unit.addFront(input3);
  unit.addFront(input4);

  ASSERT_EQ(input4, unit.front());
  unit.removeFront();
  ASSERT_EQ(input3, unit.front());
  unit.removeFront();
  ASSERT_EQ(input2, unit.front());
  unit.removeFront();
  ASSERT_EQ(input1, unit.front());
  unit.removeFront();

  ASSERT_TRUE(unit.empty());
}

TEST(DLinkedListTest, SizeTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  DLinkedList<int> unit = DLinkedList<int>();
  unit.addFront(input1);
  unit.addFront(input2);
  unit.addFront(input3);
  unit.addFront(input4);

  ASSERT_EQ(input4, unit.front());
  unit.removeFront();
  ASSERT_EQ(input3, unit.front());
  unit.removeFront();
  ASSERT_EQ(input2, unit.front());
  unit.removeFront();
  ASSERT_EQ(input1, unit.front());
  unit.removeFront();

  ASSERT_TRUE(unit.empty());
}

TEST(CircleListTest, SizeTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  CircleList<int> unit = CircleList<int>();
  unit.add(input1);
  unit.add(input2);
  unit.add(input3);
  unit.add(input4);

  ASSERT_EQ(input4, unit.front());
  unit.remove();
  ASSERT_EQ(input3, unit.front());
  unit.remove();
  ASSERT_EQ(input2, unit.front());
  unit.remove();
  ASSERT_EQ(input1, unit.front());
  unit.remove();

  ASSERT_TRUE(unit.empty());
}

TEST(CircleListTest, AdvanceTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  CircleList<int> unit = CircleList<int>();
  unit.add(input1);
  unit.add(input2);
  unit.add(input3);
  unit.add(input4);

  ASSERT_EQ(input4, unit.front());
  unit.advance();
  ASSERT_EQ(input3, unit.front());
  unit.advance();
  ASSERT_EQ(input2, unit.front());
  unit.advance();
  ASSERT_EQ(input1, unit.front());
  unit.advance();
  ASSERT_EQ(input4, unit.front());
}

TEST(LinkedStackTest, SizeTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  LittleData::LinkedStack<int> unit = LittleData::LinkedStack<int>();
  unit.push(input1);
  unit.push(input2);
  unit.push(input3);
  unit.push(input4);

  ASSERT_EQ(input4, unit.top());
  unit.pop();
  ASSERT_EQ(input3, unit.top());
  unit.pop();
  ASSERT_EQ(input2, unit.top());
  unit.pop();
  ASSERT_EQ(input1, unit.top());
  unit.pop();

  ASSERT_TRUE(unit.empty());
}

TEST(ArrayStackTest, SizeTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  LittleData::ArrayStack<int> unit = LittleData::ArrayStack<int>(4);
  unit.push(input1);
  unit.push(input2);
  unit.push(input3);
  unit.push(input4);

  ASSERT_EQ(input4, unit.top());
  unit.pop();
  ASSERT_EQ(input3, unit.top());
  unit.pop();
  ASSERT_EQ(input2, unit.top());
  unit.pop();
  ASSERT_EQ(input1, unit.top());
  unit.pop();

  ASSERT_TRUE(unit.empty());
}

TEST(LinkedQueueTest, SizeTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  LittleData::LinkedQueue<int> unit = LittleData::LinkedQueue<int>();
  unit.enqueue(input1);
  unit.enqueue(input2);
  unit.enqueue(input3);
  unit.enqueue(input4);

  ASSERT_EQ(input1, unit.front());
  unit.dequeue();
  ASSERT_EQ(input2, unit.front());
  unit.dequeue();
  ASSERT_EQ(input3, unit.front());
  unit.dequeue();
  ASSERT_EQ(input4, unit.front());
  unit.dequeue();

  ASSERT_TRUE(unit.empty());
}

TEST(ArrayQueueTest, SizeTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  LittleData::ArrayQueue<int> unit = LittleData::ArrayQueue<int>(4);
  unit.enqueue(input1);
  unit.enqueue(input2);
  unit.enqueue(input3);
  unit.enqueue(input4);

  ASSERT_EQ(input1, unit.front());
  unit.dequeue();
  ASSERT_EQ(input2, unit.front());
  unit.dequeue();
  ASSERT_EQ(input3, unit.front());
  unit.dequeue();
  ASSERT_EQ(input4, unit.front());
  unit.dequeue();

  ASSERT_TRUE(unit.empty());
}

TEST(LinkedDeQueTest, SizeTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  LittleData::LinkedDeque<int> unit = LittleData::LinkedDeque<int>();
  // as a queue
  unit.insertFront(input1);
  unit.insertFront(input2);
  unit.insertFront(input3);
  unit.insertFront(input4);

  ASSERT_EQ(input1, unit.back());
  unit.removeBack();
  ASSERT_EQ(input2, unit.back());
  unit.removeBack();
  ASSERT_EQ(input3, unit.back());
  unit.removeBack();
  ASSERT_EQ(input4, unit.back());
  unit.removeBack();

  ASSERT_TRUE(unit.empty());

  // as a stack
  unit.insertFront(input1);
  unit.insertFront(input2);
  unit.insertFront(input3);
  unit.insertFront(input4);

  ASSERT_EQ(input4, unit.front());
  unit.removeFront();
  ASSERT_EQ(input3, unit.front());
  unit.removeFront();
  ASSERT_EQ(input2, unit.front());
  unit.removeFront();
  ASSERT_EQ(input1, unit.front());
  unit.removeFront();

  ASSERT_TRUE(unit.empty());
}

TEST(NodeListTest, SizeTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  LittleData::NodeList<int> unit = LittleData::NodeList<int>();
  unit.insertFront(input1);
  unit.insertFront(input2);
  unit.insertBack(input3);
  unit.insertBack(input4);

  ASSERT_EQ(input2, *unit.begin());
  unit.eraseFront();
  ASSERT_EQ(input1, *unit.begin());
  unit.eraseFront();
  ASSERT_EQ(input4, *--unit.end());
  unit.eraseBack();
  ASSERT_EQ(input3, *--unit.end());
  unit.eraseBack();

  ASSERT_TRUE(unit.empty());
}

TEST(NodeSequenceTest, IndexTest) {
  const int input1 = 1;
  const int input2 = 2;
  const int input3 = 4;
  const int input4 = 3;
  LittleData::NodeSequence<int> unit = LittleData::NodeSequence<int>();
  unit.insertFront(input1);
  unit.insertFront(input2);
  unit.insertBack(input3);
  unit.insertBack(input4);

  auto position = unit.atIndex(0);
  int index = unit.indexOf(position);
  ASSERT_EQ(index, 0);
  ASSERT_EQ(*position, input2);

  auto position2 = unit.atIndex(2);
  int index2 = unit.indexOf(position2);
  ASSERT_EQ(index2, 2);
  ASSERT_EQ(*position2, input3);
}

TEST(LinkedBinaryTreeTest, SizeTest) {
  LittleData::LinkedBinaryTree<int> arbol;
  ASSERT_EQ(0, arbol.size());
  arbol.addRoot();
  ASSERT_EQ(1, arbol.size());

  LittleData::LinkedBinaryTree<int>::Position root = arbol.root();
  *root = 1;
  ASSERT_TRUE(root.isRoot());
  ASSERT_TRUE(root.isExternal());

  arbol.expandExternal(root);
  *root.left() = 2;
  *root.right() = 3;
  ASSERT_FALSE(root.isExternal());
  ASSERT_EQ(3, arbol.size());

  arbol.expandExternal(root.left());
  *root.left().left() = 4;
  *root.left().right() = 5;
  ASSERT_EQ(5, arbol.size());

  arbol.expandExternal(root.right());
  *root.right().left() = 6;
  *root.right().right() = 7;
  ASSERT_EQ(7, arbol.size());

  arbol.expandExternal(root.right().right());
  *root.right().right().left() = 8;
  *root.right().right().right() = 9;
  ASSERT_EQ(9, arbol.size());
}

TEST(ComparatorTest, CompareTest) {
  using LittleData::BottomTop;
  using LittleData::LeftRight;
  using LittleData::Point2;

  Point2 a = {.x = 2, .y = 2};
  Point2 b = {.x = 5, .y = 1};

  LeftRight lr;
  BottomTop bt;

  ASSERT_TRUE(lr(a, b));
  ASSERT_TRUE(bt(b, a));
}

TEST(ListPriorityQueueTest, IndexTest) {
  LittleData::ListPriorityQueue<LittleData::Pair, LittleData::IsLess> queue;

  ASSERT_TRUE(queue.empty());

  queue.insert(LittleData::Pair(2, 5));
  queue.insert(LittleData::Pair(2, 4));
  queue.insert(LittleData::Pair(3, 7));
  queue.insert(LittleData::Pair(1, 8));

  ASSERT_EQ(queue.size(), 4);
  ASSERT_EQ(queue.min().second, 8);

  queue.removeMin();
  ASSERT_EQ(queue.size(), 3);
  ASSERT_EQ(queue.min().second, 5);
}

TEST(VectorCompleteTreeTest, sizeTest) {
  LittleData::VectorCompleteTree<int> tree;
  tree.addLast(4);
  tree.addLast(8);
  tree.addLast(7);
  ASSERT_EQ(tree.size(), 3);

  int last = *tree.last();
  ASSERT_EQ(last, 7);
}

TEST(HeapPriorityQueueTest, sizeTest) {
  LittleData::HeapPriorityQueue<LittleData::Pair, LittleData::IsLess> queue;
  ASSERT_TRUE(queue.empty());

  queue.insert(LittleData::Pair(2, 5));
  queue.insert(LittleData::Pair(2, 4));
  queue.insert(LittleData::Pair(3, 7));
  queue.insert(LittleData::Pair(1, 8));

  ASSERT_EQ(queue.size(), 4);
  ASSERT_EQ(queue.min().second, 8);

  queue.removeMin();
  ASSERT_EQ(queue.size(), 3);
  ASSERT_TRUE(queue.min().second == 4 || queue.min().second == 5);
}

TEST(AdaptPriorityQueueTest, indexTest) {
  LittleData::AdaptPriorityQueue<LittleData::Pair, LittleData::IsLess> queue;
  typename LittleData::AdaptPriorityQueue<
      LittleData::Pair, LittleData::IsLess>::Position Position;

  LittleData::Pair first(2, 5);
  LittleData::Pair second(1, 42);
  LittleData::Pair third(3, 7);
  LittleData::Pair extra(3, 4);

  auto a = queue.insert(first);
  auto b = queue.insert(second);
  auto c = queue.insert(third);

  ASSERT_EQ(queue.size(), 3);
  // ASSERT_EQ((*a).second, 42) // doesn't work
  ASSERT_EQ(queue.min().second, 42);

  queue.replace(c, extra);

  queue.removeMin();
  ASSERT_EQ(queue.size(), 2);
  ASSERT_EQ(queue.min().second, 5);

  queue.removeMin();
  ASSERT_EQ(queue.size(), 1);
  ASSERT_EQ(queue.min().second, 4);
}
TEST(SearchTreeTest, MainTest) {
  SearchTree<Entry<int, string>> S;
  S.insert(1, "one");
  S.insert(3, "three");
  S.insert(5, "five");
  S.insert(7, "seven");
  S.insert(9, "nine");
  S.insert(11, "eleven");

  ASSERT_EQ(S.size(), 6);
  bool areSame = (*S.find(1)).value() == "one";
  ASSERT_TRUE(areSame);
  areSame = (*S.find(3)).value() == "three";
  ASSERT_TRUE(areSame);
  areSame = (*S.find(2)).value() == "two";
  ASSERT_FALSE(areSame);

  S.insert(6, "six");
  ASSERT_EQ(S.size(), 7);
  areSame = (*S.find(6)).value() == "six";
  ASSERT_TRUE(areSame);

  ASSERT_NO_THROW(S.erase(7));
  ASSERT_EQ(S.size(), 6);

  areSame = (*S.find(6)).value() == "six";
  ASSERT_TRUE(areSame);
}

TEST(AVLTree, MainTest) {
  AVLTree<int, string> avl;
  avl.insert(10, "ten");
  avl.insert(20, "twenty");
  avl.insert(30, "thirty");
  avl.insert(40, "fourty");
  avl.insert(50, "fifty");
  avl.insert(25, "twenty-five");

  cout << "Inorder traversal of the AVL tree: ";
  ASSERT_NO_FATAL_FAILURE(avl.printInorder());

  // Remove a node from the AVL tree
  ASSERT_NO_FATAL_FAILURE(avl.remove(30));
  cout << "Inorder traversal after removing 30: ";
  ASSERT_NO_FATAL_FAILURE(avl.printInorder());

  ASSERT_TRUE(avl.search(25));
  ASSERT_FALSE(avl.search(30));
}

TEST(Graph, IncidentTest) {
  Graph<int> g;

  g.insertVertex(1, 11);
  g.insertVertex(2, 12);
  g.insertVertex(3, 13);
  g.insertEdge(1, 2);
  g.insertEdge(2, 3);

  Vertex<int> *firstVertex = g[1];
  Vertex<int> *secondVertex = g[2];
  IEdge<int> *firstEdge = g.edges()[0];
  IEdge<int> *secondEdge = g.edges()[1];
  ASSERT_TRUE(firstEdge->isIncidentOn(firstVertex));
  ASSERT_TRUE(firstEdge->isIncidentOn(secondVertex));
  ASSERT_FALSE(secondEdge->isIncidentOn(firstVertex));
}

TEST(Graph, MainTest) {
  Graph<int> g;

  g.insertVertex(1, 11); // 1
  g.insertVertex(2, 12); // 2
  g.insertVertex(3, 13); // 3
  g.insertVertex(4, 14); // 4
  g.insertVertex(5, 15); // 5

  ASSERT_EQ(g.vertices().size(), 5);

  g.insertEdge(1, 2);
  g.insertEdge(2, 3);
  g.insertEdge(3, 4);
  g.insertEdge(4, 5);

  ASSERT_EQ(g.edges().size(), 4);

  Vertex<int> *firstVertex = g[1];
  IEdge<int> *firstEdge = g.edges()[0];
  cout << "First vertex has value " << firstVertex->getValue() << endl;
  cout << "First edge links vertex with value "
       << firstEdge->endVertices()[0]->getValue() << " and "
       << firstEdge->endVertices()[1]->getValue() << endl;
  // bool condition = g.edges()[0].isIncidentOn(firstVertex);
  ASSERT_TRUE(firstEdge->isIncidentOn(firstVertex));

  Vertex<int> *secondVertex = g[2];
  IEdge<int> *secondEdge = g.edges()[1];
  Vertex<int> *fourthVertex = g[4];
  ASSERT_EQ(secondVertex->incidentEdges().size(), 2);

  cout << "Second edge links vertex with value "
       << secondEdge->endVertices()[0]->getValue() << " and "
       << secondEdge->endVertices()[1]->getValue() << endl;

  g.insertEdge(5, 1);
  g.eraseEdge(secondEdge);

  ASSERT_EQ(secondVertex->incidentEdges().size(), 1);

  g.eraseVertex(secondVertex);
  ASSERT_EQ(g.vertices().size(), 4);
  ASSERT_EQ(g.edges().size(), 3);
  ASSERT_EQ(firstVertex->incidentEdges().size(), 1);
}

TEST(DiGraph, WalkTest) {
  DiGraph<int> g;

  g.insertVertex(1, 11); // 1
  g.insertVertex(2, 12); // 2
  g.insertVertex(3, 13); // 3
  g.insertVertex(4, 14); // 4
  g.insertVertex(5, 15); // 5

  ASSERT_EQ(g.vertices().size(), 5);

  g.insertEdge(1, 2);
  g.insertEdge(2, 3);
  g.insertEdge(3, 4);
  g.insertEdge(4, 5);
  g.insertEdge(5, 1);

  auto current = g.find(2);
  while (current->getValue() != 11) {
    cout << "Vertex is in key: " << current->getValue() << endl;
    DiEdge<int> *outEdge = NULL;
    int i = 0;
    auto incidentEdges = current->incidentEdges();
    do {

      outEdge = static_cast<DiEdge<int> *>(incidentEdges[i]);
      i++;
      if (incidentEdges.size() == i)
        break;
    } while (outEdge->origin() != current);
    current = outEdge->destination();
  }

  ASSERT_EQ(current->getKey(), 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}