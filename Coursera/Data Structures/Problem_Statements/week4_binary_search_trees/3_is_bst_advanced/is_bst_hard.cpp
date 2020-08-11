#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif


using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool is_bst {true};
int count {0};
struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

struct Super_Node {
  Node node;
  int index;
};

Super_Node previous;

void inorder_traversal(int index, const vector<Node> &tree) {
  if (tree.size() == 0 || index == -1)
    return;
  inorder_traversal(tree[index].left, tree);
  if (count == 0) {
    previous.node = tree[index];
    previous.index = index;
    count++;
  }
  else if (tree[index].key < previous.node.key)
    is_bst = false;
  else if (tree[index].key == previous.node.key)
    if (index > previous.index)
      is_bst = false;
  inorder_traversal(tree[index].right, tree);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  inorder_traversal(0, tree);
  return is_bst;
}

int main() {
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
