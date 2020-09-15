#include <iostream>
#include <vector>
#include <queue>
#define MAX 2147483647

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
typedef std::pair<long long, int> type;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
  vector <long long> cost_min(adj.size(), MAX);
  vector <bool> min_visited(adj.size(), false);
  cost_min[s] = 0;
  priority_queue<type, vector<type>, std::greater<type>> pq;
  for (int i = 0; i < adj.size(); i++) {
    pq.push(std::make_pair(cost_min[i], i));
  }
  while (!pq.empty()) {
    pair <int, int> cp = pq.top();
    pq.pop();
    if (!min_visited[cp.second]) {
      min_visited[cp.second] = true;
      for (auto v = 0; v < adj[cp.second].size(); v++) {
        if (cost_min[adj[cp.second][v]] > cost_min[cp.second] + cost[cp.second][v]) {
          cost_min[adj[cp.second][v]] = cost_min[cp.second] + cost[cp.second][v];
          pq.push(std::make_pair(cost_min[adj[cp.second][v]], adj[cp.second][v]));
        }
      }
    }
  }
  if (cost_min[t] == MAX) return -1;
  return cost_min[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
