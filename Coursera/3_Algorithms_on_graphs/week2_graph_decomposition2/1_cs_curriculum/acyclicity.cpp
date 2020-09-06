#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<int> pre_order{0};
vector<int> post_order{0};
int number = 1;

int explore(vector<vector<int>> &adj, int vertex) {
  pre_order[vertex] = number;
  number++;
  for (auto vert : adj[vertex]) {
    if (pre_order[vert] == 0) {
      int result = explore(adj, vert);
      if (result == 1) return 1;
    }
    else if (pre_order[vert] != 0 && post_order[vert] == 0)
      return 1;
  }
  post_order[vertex] = number;
  number++;
  return 0;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  for (int i = 0; i < adj.size(); i++) {
    if (pre_order[i] == 0) {
      int result = explore(adj, i);
      if (result == 1) return 1;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  pre_order.resize(n);
  post_order.resize(n);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
