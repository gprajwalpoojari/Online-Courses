#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>

using std::priority_queue;
using std::vector;
using std::pair;
typedef pair<double, int> type;

double calc_dist(vector<int> &x, vector<int> &y, int index_a, int index_b) {
  return sqrt(pow(x[index_b] - x[index_a], 2) + pow(y[index_b] - y[index_a], 2));
}
double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  vector<double> cost(x.size(), std::numeric_limits<double>::max());
  vector<bool>road_built(x.size(), 0);
  cost[0] = 0;
  priority_queue<type, vector<type>, std::greater<type>> q;
  q.push(std::make_pair(cost[0],0));
  while(!q.empty()) {
    type tp = q.top();
    q.pop();
    if (!road_built[tp.second]) {
      road_built[tp.second] = 1;
      result += tp.first;
      for (int v = 0; v < road_built.size(); v++) {
        if (!road_built[v] && cost[v] > calc_dist(x, y, tp.second, v)) {
          cost[v] = calc_dist(x, y, tp.second, v);
          q.push(std::make_pair(cost[v], v));
        }
      }
    }
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
