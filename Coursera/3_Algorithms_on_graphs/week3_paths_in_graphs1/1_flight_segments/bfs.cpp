#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector<int> layer(adj.size(), -1);
  vector<int> parent(adj.size(), -1);
  queue<int> q;
  q.push(s);
  layer[s] = 0;
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    for (auto vertex : adj[front]) {
      if (layer[vertex] == -1) {
        q.push(vertex);
	layer[vertex] = layer[front] + 1;
	parent[vertex] = front;
	if (vertex == t) return layer[vertex];
      }
    }
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
