#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int>>&, int, vector<int>&);
void explore(vector<vector<int>>&, int);

vector<int> preorder{0};
vector<int> postorder{0};
vector<bool> visited_tracker{false};
int clock_{1};

void explore(vector<vector<int> > &adj, int vertex, vector<int> &order) {
  preorder[vertex] = clock_;
  clock_++;
  for (auto vert : adj[vertex]) {
    if (preorder[vert] == 0)
      explore(adj, vert, order);
  }
  postorder[vertex] = clock_;
  clock_++;
  order.push_back(vertex);
}

void dfs(vector<vector<int> > &adj, vector<int> &order) {
  for (int i = 0; i < adj.size(); i++) {
    if (preorder[i] == 0)
      explore(adj, i, order);
  }
}

void explore(vector<vector<int>> &adj, int vertex) {
  visited_tracker[vertex] = true;
  for (auto vert : adj[vertex]) {
    if (!visited_tracker[vert])
      explore(adj, vert);
  }
}
int number_of_strongly_connected_components(vector<vector<int> > &rev_adj, vector<vector<int> > &adj) {
  int result = 0;
  //write your code here
  vector<int> order;
  dfs(rev_adj, order);
  for (int i = 0; i < order.size() - i - 1; i++) {
    std::swap(order[i], order[order.size() - i - 1]);
  }
  for (int i = 0; i < order.size(); i++) {
    if (!visited_tracker[order[i]]) {
     explore(adj, order[i]);
     result++;
    }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  preorder.resize(n);
  postorder.resize(n);
  visited_tracker.resize(n);
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > rev_adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    rev_adj[y - 1].push_back(x - 1);
  }

  std::cout << number_of_strongly_connected_components(rev_adj, adj);
}
