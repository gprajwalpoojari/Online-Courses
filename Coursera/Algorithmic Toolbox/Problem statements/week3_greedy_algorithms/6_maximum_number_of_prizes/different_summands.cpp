#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  while (n != 0) {
    for (int i = 1; i <= n; i++){
      if (n - i > i) {
        summands.push_back(i);
        n -= i;
      }
      else {
        summands.push_back(n);
        n = 0;
        break;
      }
    } 
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
