#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void sort_vector(vector <int> &unsorted) {
  if (unsorted.size() > 1) {
  int count {};
  while (count != unsorted.size() - 1)  {
    count = 0;
    for (int i = 1; i < unsorted.size(); i++){
      if (unsorted.at(i) > unsorted.at(i - 1)) {
        std::swap(unsorted.at(i), unsorted.at(i - 1));
      }
      else {
        count++;
      }
    }
  }
  }
}

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  sort_vector(a);
  sort_vector(b);
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
