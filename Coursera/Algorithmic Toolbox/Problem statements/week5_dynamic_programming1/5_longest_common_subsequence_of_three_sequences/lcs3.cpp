#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int x = a.size() + 1;
  int y = b.size() + 1;
  int z = c.size() + 1;
  int optimal_path[x][y][z] = {};
  for (int i = x - 1; i >= 0; i--) {
    for (int j = y - 1; j >= 0; j--) {
      for (int k = z - 1; k >= 0; k--) {
        if (i == x - 1 || j == y - 1 || k == z - 1) {
          optimal_path[i][j][k] = 0;
        }
        else if (a.at(i) == b.at(j) && a.at(i) == c.at(k)) {
          optimal_path[i][j][k] = optimal_path[i + 1][j + 1][k + 1] + 1;
        }
        else {
          int maximum = std::max({optimal_path[i][j + 1][k], optimal_path[i + 1][j][k], optimal_path[i][j][k + 1]});
          optimal_path[i][j][k] = maximum;
        }
      }
    }
  }

  return optimal_path[0][0][0];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
