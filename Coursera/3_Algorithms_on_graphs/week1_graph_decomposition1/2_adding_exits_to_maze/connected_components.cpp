#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visited_tracker{false};

void explore(vector<vector<int>> &adj, int vertex) {
  visited_tracker[vertex] = true;
  for (auto i : adj[vertex]) {
    if (!visited_tracker[i]) {
      explore(adj, i);
    }
  }
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  for (int i = 0; i < adj.size(); i++) {
    if (visited_tracker[i] == false) {
      explore(adj, i);
      res++;
    }
  }
  return res;
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
  std::cout << number_of_components(adj);
}
