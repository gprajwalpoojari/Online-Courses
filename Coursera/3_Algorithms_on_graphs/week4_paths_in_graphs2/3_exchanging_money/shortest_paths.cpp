#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  vector<int> prev(adj.size());
  distance[s] = 0;
  queue<int> q;
  q.push(s);
  reachable[s] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int vertex : adj[v]) {
      if(!reachable[vertex])
        q.push(vertex);
        reachable[vertex] = 1;
    }
  }
  int tmp = 1;
  queue<int> no_shortest_path;
  for (int count = 0; count < adj.size(); count++) {
    for (int i = 0; i < adj.size(); i++) {
      for (int j = 0; j < adj[i].size(); j++) {
        if (reachable[adj[i][j]] && distance[i] != std::numeric_limits<long long>::max() && distance[adj[i][j]] > distance[i] + cost[i][j]) {
          if (count == adj.size() - 1) {
            no_shortest_path.push(adj[i][j]);
	    shortest[adj[i][j]] = 0;
            while (!no_shortest_path.empty()) {
	      int top = no_shortest_path.front();
	      no_shortest_path.pop();
	      for (int vertex : adj[top]) {
                if (shortest[vertex]) {
                  no_shortest_path.push(vertex);
                  shortest[vertex] = 0;
	        }
              }
            }
          }
          else {
            distance[adj[i][j]] = distance[i] + cost[i][j];
            prev[adj[i][j]] = i;
          }
        }
      }
    }
  }
}
int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
