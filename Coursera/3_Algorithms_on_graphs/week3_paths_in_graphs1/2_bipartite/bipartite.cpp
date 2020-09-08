#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> colour(adj.size(), -1);
  queue<int> q;
  int col = 0;
  for (int i = 0; i < adj.size(); i++) {
    if (colour[i] == -1) {
      q.push(i);
      colour[i] = col;
      while (!q.empty()) {
        int front = q.front();
        q.pop();
        col = (colour[front] + 1) % 2;
        for (auto vertex : adj[front]) {
          if (colour[vertex] != colour[front]) {
            if (colour[vertex] == -1) {
              q.push(vertex);
	      colour[vertex] = col;
            }
          }
          else return 0;
        }
      }
    }
  }
  return 1;
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
  std::cout << bipartite(adj);
}
