 #include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visited_tracker {false};

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  visited_tracker[x] = true;
  if (x == y) return 1;
  for (auto visited : adj[x]) {
    if (!visited_tracker[visited]) {
      int path = reach(adj, visited, y);
        if (path == 1) return path;
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  visited_tracker.resize(n);
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
