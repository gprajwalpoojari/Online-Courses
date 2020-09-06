#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

vector<int> preorder{0};
vector<int> postorder{0};
int clock_{1};

int explore(vector<vector <int> > &adj, int vertex, vector<int> &order) {
  preorder[vertex] = clock_;
  clock_++;
  for (auto vert : adj[vertex]) {
    if (preorder[vert] == 0) {
      int result = explore(adj, vert, order);
      if (result == 1) return 1;
    }
    else if (preorder[vert] != 0 && postorder[vert] == 0) return 1;
  }
  postorder[vertex] = clock_;
  clock_++;
//  std::cout << clock_<<std::endl;
  order.push_back(vertex);
  return 0;
}

void dfs(vector<vector<int> > &adj,vector<int> &order) {
  //write your code here
  for (int i = 0; i < adj.size(); i++) {
    if (preorder[i] == 0) {
      int result = explore(adj, i, order);
      if (result == 1) return;
    }
  }
  for (int i = 0; i < order.size() - i - 1; i++) {
    std::swap(order[i], order[order.size() - i - 1]);
  }
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  //write your code here
  dfs(adj, order);
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  preorder.resize(n);
  postorder.resize(n);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
