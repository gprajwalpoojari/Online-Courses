#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int *partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int k = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      if (i > j + 1)
        swap(a[i], a[j + 1]);
    j++;
    if (k < j) k = j;
    }
    if (a[i] == a[l]) {
      if (i > k + 1)
        swap(a[i], a[k + 1]);
        k++;
    }
  }
  swap(a[l], a[j]);
  int *m = new int [2] {j, k};
  return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int *m = partition2(a, l, r);

  randomized_quick_sort(a, l, (*m) - 1);
  randomized_quick_sort(a, *(m + 1) + 1, r);
  delete m;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
