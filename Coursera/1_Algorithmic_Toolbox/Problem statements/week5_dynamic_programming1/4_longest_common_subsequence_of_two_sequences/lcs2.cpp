#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int row = a.size() + 1;
  int column = b.size() + 1;
  int optimal_path[row][column] = {};
  for (int i = row - 1; i >= 0; i--) {
    for (int j = column - 1; j >= 0; j--) {
      if (i == row - 1 || j == column - 1) {
        optimal_path[i][j] = 0;
      }
      else if (a.at(i) == b.at(j)) {
        optimal_path[i][j] = optimal_path[i + 1][j + 1] + 1;
      }
      else {
        int maximum = std::max({optimal_path[i][j + 1], optimal_path[i + 1][j]});
        optimal_path[i][j] = maximum;
      }
    }
  }
  return optimal_path[0][0];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
