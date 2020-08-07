#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  
  vector <int> weight_table((w.size() + 1) * (W + 1));
  for (int i = 0; i <= W; i++) {
    weight_table[i] = 0;
  }
  for (int i = 0; i <= w.size(); i++) {
    weight_table[i * (W + 1)] = 0;
  }
  for (int i = 1; i <= w.size(); i++ ) {
    for (int j = 1; j <= W; j++) {
      weight_table[(W + 1) * i + j] = weight_table[(W + 1) * (i - 1) + j];
      int value {0};
      if (w.at(i - 1) <= j) {
        value = weight_table[(W + 1) * (i - 1) + (j - w.at(i - 1))] + w.at(i - 1);
      }
      weight_table[(W + 1) * i + j] = std::max(weight_table[(W + 1) * i + j], value);   
    }
  }
  return weight_table[(w.size() + 1) * (W + 1) - 1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
