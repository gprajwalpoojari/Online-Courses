#include <iostream>
#include <vector>

using std::vector;

int get_change(int m, vector <int> shortest_path) {
  //write your code here
  vector <int> denominations {1, 3, 4};
  if (m == 0) {
    return 0;
  }
  if (shortest_path[m] != 0) {
    return shortest_path[m];
  }
  for (int i = 1; i <= m; i++) {
    for (auto j : denominations) {
      if (i >= j) {
        int num_coins = get_change(i - j, shortest_path) + 1;
        if (shortest_path[i] == 0 || num_coins < shortest_path[i]) {
          shortest_path[i] = num_coins;
        }
      }
    }
  }
  return shortest_path[m];
}

int main() {
  int m;
  std::cin >> m;
  vector <int> shortest_path(m + 1);
  std::cout << get_change(m, shortest_path) << '\n';
}
