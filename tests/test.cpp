#include <LittleData.hpp>
#include<string>
#include <cstddef>
#include <gtest/gtest.h>

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

TEST(LinkedBinaryTreeTest, SizeTest)
{
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

TEST(ComparatorTest, CompareTest)
{
  using LittleData::Point2;
  using LittleData::LeftRight;
  using LittleData::BottomTop;

  
  Point2 a = {.x = 2, .y = 2};
  Point2 b = {.x = 5, .y = 1};

  LeftRight lr;
  BottomTop bt;

  ASSERT_TRUE(lr(a,b));
  ASSERT_TRUE(bt(b,a));
}

TEST(ListPriorityQueueTest, IndexTest)
{
  LittleData::ListPriorityQueue<LittleData::Pair, LittleData::IsLess>
    queue;

    ASSERT_TRUE(queue.empty());
    
    queue.insert(LittleData::Pair(2,5));
    queue.insert(LittleData::Pair(2,4));
    queue.insert(LittleData::Pair(3,7));
    queue.insert(LittleData::Pair(1,8));

    ASSERT_EQ(queue.size(), 4);
    ASSERT_EQ(queue.min().second, 8);

    queue.removeMin();
    ASSERT_EQ(queue.size(), 3);
    ASSERT_EQ(queue.min().second, 5);
}

TEST(VectorCompleteTreeTest, sizeTest)
{
  LittleData::VectorCompleteTree<int> tree;
  tree.addLast(4);
  tree.addLast(8);
  tree.addLast(7);
  ASSERT_EQ(tree.size(), 3);

  int last = *tree.last();
  ASSERT_EQ(last, 7);
}

TEST(HeapPriorityQueueTest, sizeTest)
{
  LittleData::HeapPriorityQueue<LittleData::Pair, LittleData::IsLess> queue;
  ASSERT_TRUE(queue.empty());

  queue.insert(LittleData::Pair(2,5));
    queue.insert(LittleData::Pair(2,4));
    queue.insert(LittleData::Pair(3,7));
    queue.insert(LittleData::Pair(1,8));

    ASSERT_EQ(queue.size(), 4);
    ASSERT_EQ(queue.min().second, 8);

    queue.removeMin();
    ASSERT_EQ(queue.size(), 3);
    ASSERT_TRUE(queue.min().second == 4 || queue.min().second == 5);
}

TEST(AdaptPriorityQueueTest, indexTest)
{
  LittleData::AdaptPriorityQueue<LittleData::Pair, LittleData::IsLess> queue;
  typename LittleData::AdaptPriorityQueue<LittleData::Pair, LittleData::IsLess>::Position Position;

  LittleData::Pair first(2,5);
  LittleData::Pair second(1,42);
  LittleData::Pair third(3, 7);
  LittleData::Pair extra(3,4);
  
  auto a = queue.insert(first);
  auto b = queue.insert(second);
  auto c = queue.insert(third);
  

  ASSERT_EQ(queue.size(), 3);
  //ASSERT_EQ((*a).second, 42) // doesn't work
  ASSERT_EQ(queue.min().second,42);

queue.replace(c, extra);

  queue.removeMin();
  ASSERT_EQ(queue.size(), 2);
  ASSERT_EQ(queue.min().second,5);

  queue.removeMin();
  ASSERT_EQ(queue.size(), 1);
  ASSERT_EQ(queue.min().second,4);
}
TEST(SearchTreeTest, MainTest)
{
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

TEST(AVLTree, MainTest)
{
  AVLTree<Entry<int, string>> T;

  /* T.insert(1, "one");
  T.insert(3, "three");
  T.insert(5, "five");
  T.insert(7, "seven");
  T.insert(9, "nine");
  T.insert(11, "eleven");

  ASSERT_EQ(T.size(), 6); */
  // AVLTree.rebalance(const TPos&) not fully implemented since LinkedBinaryTree.restructure is not implemented yet either
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}