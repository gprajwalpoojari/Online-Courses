#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  int j = left;
  int k = ave;
  for (int i = left; i < ave; i++) {
    for (int j = ave; j < right; j++) {
      if (a[i] > a[j]) {
//        cout << a[i] << " " << b[j] << endl;
        number_of_inversions++;
      }
    }
  }
/*  for (int i = left; i < right; i++) {
    if (k != right && j != ave) {
      if (a[j] > a[k]) {
        b[i] = a[k];
        k++;
      }
      else {
        b[i] = a[j];
        j++;
      }
    }
    else {
      if (j == ave) {
        k++;
      }
      else if (k == right) {
        j++;
      }
    }
  }
  for (int i = left; i < right; i++) {
    a[i] = b [i];
  }*/
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
