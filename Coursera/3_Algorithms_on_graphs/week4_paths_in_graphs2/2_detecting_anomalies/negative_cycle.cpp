#include <iostream>
#include <vector>
#include <cmath>
#define MAX 2147483646
using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  vector<int> currency_min(adj.size(), MAX);
  currency_min[0] = 0;
  for (int count = 0; count < adj.size(); count++) {
    for (int i = 0; i < adj.size(); i++) {
      for (int j = 0; j < adj[i].size(); j++) {
        if (currency_min[i] - MAX / 2 + cost[i][j] > MAX / 2) {
          continue;
        }
        else {
          if (currency_min[adj[i][j]] > currency_min[i] + cost[i][j]) {
	    if (count == adj.size() - 1) return 1;
            currency_min[adj[i][j]] = currency_min[i] + cost[i][j];
//            std::cout<<i<< " "<<j<<" "<<currency_min[adj[i][j]]<<std::endl;
            }
        }
      }
    }
  }
  return 0;
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
  std::cout << negative_cycle(adj, cost);
}
