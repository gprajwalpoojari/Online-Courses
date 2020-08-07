#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000000

using std::vector;

vector<int> optimal_sequence(int n);

int calculate_min_path(int n, vector<int> &minimum_path) {
  vector<int> path (3, MAX);
  vector <int> parameter {n / 2, n / 3, n - 1};
    if (n >= 2 && n % 2 == 0) {
      path[0] = minimum_path[parameter[0]] + 1;
    }
    if (n >= 3 && n % 3 == 0) {
      path[1] = minimum_path[parameter[1]] + 1;
    }
    if (n > 1) {
      path[2] = minimum_path[parameter[2]] + 1;
    }
    int minimum = std::min({path[0], path[1], path[2]});
    minimum_path[n] = minimum;

    int index = std::find(path.begin(), path.end(), minimum) - path.begin();
    return parameter[index];
}
vector<int> optimal_sequence(int n) {
  vector <int> minimum_path(n + 1);
  vector <int> sequence_previous {-1, 0};
  vector <int> sequence {};
  for (int i = 2; i <= n; i++) {
    int previous = calculate_min_path(i, minimum_path);
    sequence_previous.push_back(previous);
    } 
  while (n != 1) {
    sequence.push_back(n);
    n = sequence_previous.at(n);
  }
  sequence.push_back(n);
  
  std::reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
