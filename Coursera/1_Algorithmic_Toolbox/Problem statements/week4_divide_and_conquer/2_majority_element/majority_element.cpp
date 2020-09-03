#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void sort(vector <int> &a,int left, int right) {
  if (right - left <= 1) return;
  else {
    int j = left;
    int k = left;
    for (int i = left + 1; i < right; i++) {
      if (a.at(i) < a.at(left)) {
        if (i > j + 1) {
          std::swap(a.at(i),a.at(j + 1));
        }
        j++;
        if (k < j) k = j;
      }
      else if (a.at(i) == a.at(left)) {
        if (i > k + 1) {
          std::swap(a.at(i), a.at(k + 1));
        }
        k++;
      }
    }
    if (j != left) {
      std::swap(a.at(j), a.at(left));
    }
    sort(a, left, j);
    sort(a, k + 1, right);
  }
}
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  sort(a, left, right);
  int count {1};
  for (int i = 1; i < right; i++) {
    if (a.at(i) == a.at(i - 1)) {
      count++;
      if (count > (right * 1.0) / 2.0) return 1;
    }
    else count = 1;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
/*  sort(a, 0, a.size());
  for (int i = 0; i < a.size(); i++){
    std::cout << a[i] << " ";
  }
*/
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
