#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

bool partition_possible(const vector<int> &A) {
  int sum {0};
  for (auto i : A) {
    sum += i; 
  }
  if (A.size() >= 3 && sum % 3 == 0) return true;
  else return false;
}

bool modified_knapsack(const vector<int> &A, const int &W) {
  int a {W + 1};
  int b {W + 1};
  int item = A.size() + 1;
  int optimal_array[a][b][item];
  for (int k = 0; k < item; k++) {
    optimal_array[0][0][k] = 0;
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      optimal_array[i][j][0] = 0;
    }
  }
  for (int k = 1; k < item; k++) {
    for (int j = 0; j < b; j++) {
      for (int i = 0; i < a; i++) {
        optimal_array[i][j][k] = optimal_array[i][j][k - 1];
        int value[2] {0, 0};
        if (A.at(k - 1) <= i) {
          value[0] = optimal_array[i - A.at(k - 1)][j][k - 1] + A.at(k - 1);
        }
        if (A.at(k - 1) <= j) {
          value[1] = optimal_array[i][j - A.at(k - 1)][k - 1] + A.at(k - 1);
        }
        optimal_array[i][j][k] = std::max({optimal_array[i][j][k], value[0], value[1]});
      }
    }
  }
//  std::cout << optimal_array[a - 1][b - 1][item - 1]<<std::endl;
  if (optimal_array[a - 1][b - 1][item - 1] == 2 * W) return true;
  else return false;
} 

int partition3(const vector<int> &A) {
  if (partition_possible(A)) {
    int sum {0};
    for (auto i : A) {
      sum += i;
    }
    int souvenir_per_person = sum / 3;
    bool optimal = modified_knapsack(A, souvenir_per_person);
    if (optimal) return 1;
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (int i = 0; i < A.size(); i++) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << std::endl;
}
