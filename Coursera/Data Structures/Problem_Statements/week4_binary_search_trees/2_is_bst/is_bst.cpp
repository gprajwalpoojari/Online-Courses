#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

int LeftDescendent(int index, vector<Node>& tree) {
  Node node = tree[index];
  if (node.left != -1) {
    while (tree[node.left].left != -1) {
      node = tree[node.left];
    }
  return node.left;
  }
  return index;
}

int Next(int index, vecctor<Node> &tree) {
  if (tree[index].right != -1) {
    LeftDescendent(tree[index].right, &tree)
  }
  else {
    RightAncestor(index, &tree);
  }
}


bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  int smallest = LeftDescendent(0, tree);
  Node next = Next(smallest);
  while (next.key != -1) {
    if (next.key < smallest.key) {
      return false;
    }
    smallest = Next(smallest);
    next = Next(smallest);
  }
  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
