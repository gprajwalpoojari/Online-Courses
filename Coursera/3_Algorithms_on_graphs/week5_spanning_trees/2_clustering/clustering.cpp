#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>

using std::priority_queue;
using std::vector;
using std::pair;
typedef pair<double, pair<int, int>> type;

void make_set(vector<int> &parent, vector<int> &rank, int index) {
  parent[index] = index;
  rank[index] = 0;
}

int Find(vector<int> &parent, int v) {
  if (parent[v] != v) {
    parent[v] = Find(parent, parent[v]);
  }
  return parent[v];
}

void Union(vector<int> &parent, vector<int> &rank, int x, int y) {
  int x_id = Find(parent, x);
  int y_id = Find(parent, y);
  if (x_id == y_id) return;
  if (x_id < y_id) {
    parent[x_id] = y_id;
  }
  else {
    parent[y_id] = x_id;
    if (x_id == y_id) {
      rank[x_id] += 1;
    }
  }
}

double calc_dist(vector<int> &x, vector<int> &y, int a, int b) {
  return sqrt(pow(x[b] - x[a], 2) + pow(y[b] - y[a], 2));
}
double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here
  vector<int> parent(x.size());
  vector<int> rank(x.size());
  for (int i = 0; i < x.size(); i++) {
    make_set(parent, rank, i);
  }
  priority_queue<type, vector<type>, std::greater<type>> q;
  for (int i = 0; i < x.size(); i++) {
    for (int j = i + 1; j < y.size(); j++) {
      q.push(std::make_pair(calc_dist(x, y, i, j), std::make_pair(i, j)));
    }
  }
  int sets = x.size();
  while (!q.empty()) {
    type lightest = q.top();
    q.pop();
    int index1 = lightest.second.first;
    int index2 = lightest.second.second;
    if (Find(parent, index1) != Find(parent, index2)) {
      if (sets != k) {
        Union(parent, rank, index1, index2);
        sets--;
      }
      else {
        return lightest.first;
      }
    }
  }
  return 0;
}

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
