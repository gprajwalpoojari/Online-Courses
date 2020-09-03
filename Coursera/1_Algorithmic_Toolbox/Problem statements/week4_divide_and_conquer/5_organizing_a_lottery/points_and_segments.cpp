#include <iostream>
#include <vector>

using std::vector;
using std::swap;

void check_count(const vector <int> &a,const vector <int> &b,const vector <int> &points, vector <int> &cnt,const int *const index) {
  for(int i = 0; i < points.size(); i++){
    for (int j = *index; j <= *(index + 1); j++) {
      if (a.at(j) <= points.at(i) && points.at(i) <= b.at(j))
        cnt[i]++;
    }
  }
}

int *partition2(vector<int> &a, vector <int> &b, int l, int r) {
  int x = a[l];
  int j = l;
  int k = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      swap(a[i], a[j + 1]);
      swap(b[i], b[j + 1]);
      j++;
      if (k < j) k = j;
    }
    if (a[i] == x) {
      swap(a[i], a[k + 1]);
      swap(b[i], b[k + 1]);
      k++;
    }
  }
  swap(a[l], a[j]);
  swap(b[l], b[j]);
  int *m = new int [2] {j, k};
  return m;
}

void randomized_quick_sort(vector<int> &a, vector <int> &b, vector <int> &cnt,const vector <int> &points, int l, int r) {
  if (l >= r) {
    if (l== r) {
      for (int i = 0; i < points.size(); i++) {
        if (a.at(r) <= points.at(i) && points.at(i) <= b.at(r))
        cnt[i]++;
      }
    }
  return;
  }
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  swap(b[l], b[k]);
  int *m = partition2(a, b, l, r);
  check_count(a, b, points, cnt, m);

  randomized_quick_sort(a, b, cnt, points, l, (*m) - 1);
  randomized_quick_sort(a, b, cnt, points, *(m + 1) + 1, r);
  delete m;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {   
   std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt(points.size());
  randomized_quick_sort(starts, ends, cnt, points, 0, (starts.size() - 1));
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}

