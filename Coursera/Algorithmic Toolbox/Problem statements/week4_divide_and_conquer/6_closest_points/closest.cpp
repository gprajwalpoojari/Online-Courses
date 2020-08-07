#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <time.h>
#define INT_MAX 1000000000
using std::vector;
using std::string;

void merge(vector <int> &y, vector <int> &x, int l, int r, int partition) {
  if (l >= r) return;
  vector <int> temp_y{};
  vector <int> temp_x{};
  int j {l};
  int k {partition + 1};
  
  for (int i = l; i < r + 1; i++) {
    if (j == partition + 1 || k == r + 1) { 
      if (j == partition + 1) {
        temp_y.push_back(y.at(k));
        temp_x.push_back(x.at(k));
        k++;
      }
      else {
        temp_y.push_back(y.at(j));
        temp_x.push_back(x.at(j));
        j++;
      }
    }
    else {
      if (y.at(j) <= y.at(k)) {
        temp_y.push_back(y.at(j));
        temp_x.push_back(x.at(j));
        j++;
      }
      else {
        temp_y.push_back(y.at(k));
        temp_x.push_back(x.at(k));
        k++;
      }
    }
  }
  for (int i = l; i <= r; i++) {
    y.at(i) = temp_y.at(i - l);
    x.at(i) = temp_x.at(i - l);
  }
}

double divide_and_conquer(vector<int> &a, vector <int> &b, int l, int r) {
  if (l >= r) {
    return INT_MAX;
  }
  int random = l + rand() % (r - l + 1);
  std::swap(a.at(random), a.at(l));
  std::swap(b.at(random), b.at(l));
  int x = a[l];
  int j = l;
  int k = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      std::swap(a[i], a[j + 1]);
      std::swap(b[i], b[j + 1]);
      j++;
      if (k < j) k = j;
    }
    if (a[i] == x) {
      std::swap(a[i], a[k + 1]);
      std::swap(b[i], b[k + 1]);
      k++;
    }
  }
  std::swap(a[l], a[j]);
  std::swap(b[l], b[j]);
  double dist1 = divide_and_conquer(a, b, l, k - 1);
  double dist2 = divide_and_conquer(a, b, k + 1, r);
  int center = k;
  int cent_val = a.at(center);
  merge(b, a, l, k, k - 1);
  merge(b, a, l, r, k);
  if (l + 1 == r) {
    double dist = sqrt(pow((a[l] - a[r]), 2) + pow((b[l] - b[r]), 2));
    return dist;
  }
  double minimum = std::min(dist1, dist2);
  if (minimum == 0) {
    return minimum;
  }
  double lower = cent_val - minimum;
  double upper = cent_val + minimum;
  vector <int> y_range {};
  vector <int> x_range {};
  for (int i = l; i <= r; i++) {
    if (a.at(i) >= lower && a.at(i) <= upper) {
      y_range.push_back(b.at(i));
      x_range.push_back(a.at(i));
    }
  }
 int size = y_range.size();
  for (int i = 0; i < size - 1; i++) {
    for(int j = i + 1; j < std::min(size, i + 8) ; j++) {
      double d_selective = sqrt(pow(x_range[i] - x_range[j], 2) + pow(y_range[i] - y_range[j], 2));
      minimum = std::min(minimum, d_selective);
    }
  }
  return minimum;
}

double minimal_distance(vector<int> x, vector<int> y) {
  //write your code here
  int l = 0;
  int r = x.size() - 1;
  double minimum = divide_and_conquer(x, y, l, r);
  return minimum;
}

double naive_minimal_distance(vector<int> x, vector<int> y) {
  double d = INT_MAX;
  for(int i = 0; i < x.size() - 1; i++) {
    for (int j = i + 1; j < x.size(); j++) {
      double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
      d = std::min(dist, d);
    }
  }
  return d;
}

bool test() {
  int n_const = 10000;
  int point_const = 10000000;
  size_t n = rand() % (n_const -1) + 2;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    x[i] = pow(-1, (rand() % 10)) * (rand() % (point_const + 1) - point_const);
    y[i] = pow(-1, (rand() % 10)) * (rand() % (point_const + 1) - point_const);
  }
//  double d1 = naive_minimal_distance(x, y);
  double d2 = minimal_distance(x, y);
/*  if (d1 != d2) {
  std::cout << "Size " << x.size() << std::endl;
  for (int i = 0; i < x.size(); i++) {
    std::cout  << x[i] << " " << y[i] << std::endl;
  }
  std::cout << "Naive : " << d1 << std::endl;
  std::cout << "Efficient : " << d2 << std::endl;
  return false;
  }
*/ 
//  else {
    std::cout << "Success" << std::endl;
    return true;
//  }
}

int main() {
/*
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
*/
 int count = 0;
 bool val = true;
 srand(time(0));  
 while (val) {
  val = test();
  count++;
  std::cout << count<<std::endl;
 }
}
