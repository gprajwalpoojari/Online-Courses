#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  vector <int> result_pre_order;
  vector <int> result_in_order;
  vector <int> result_post_order;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in_order_traversal(int i) {
    if (i == -1)
      return;
    in_order_traversal(left.at(i));
    result_in_order.push_back(key.at(i));
    in_order_traversal(right.at(i));
  }

  vector <int> in_order() {
    // Finish the implementation
    // You may need to add a new recursive method to do that
    int i {0};
    in_order_traversal(i);    
    return result_in_order;
  }

  void pre_order_traversal(int i) {
    if (i == -1)
      return;
    result_pre_order.push_back(key.at(i));
    pre_order_traversal(left.at(i));
    pre_order_traversal(right.at(i));
  }

  vector <int> pre_order() {
    // Finish the implementation
    // You may need to add a new recursive method to do that
    int i {0};
    pre_order_traversal(i);
    return result_pre_order;
  }
  void post_order_traversal(int i) {
    if (i == -1)
      return;
    post_order_traversal(left.at(i));
    post_order_traversal(right.at(i));
    result_post_order.push_back(key.at(i));
  }

  vector <int> post_order() {
    // Finish the implementation
    // You may need to add a new recursive method to do that
    int i {0};
    post_order_traversal(i);
    return result_post_order;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
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

  return main_with_large_stack_space();
}

