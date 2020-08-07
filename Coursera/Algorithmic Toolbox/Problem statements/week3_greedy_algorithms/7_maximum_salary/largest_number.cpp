#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
bool isgreaterorequal(string digit, string max_digit) {
  int a_i {0}, b_i {0};
  std::stringstream ss;
  string a = digit + max_digit;
  ss.str(a);
  ss >> a_i;
  ss.clear();
  string b = max_digit + digit;
  ss.str(b);
  ss >> b_i;
  ss.clear();
  if (a_i > b_i) {
    return true;
  }
  else {
    return false;
  }
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  string result {};
  for (int i = 0; i < a.size(); i++) {
    string max_digit {a.at(i)};
    for (int j = i; j < a.size(); j++) {
      if (isgreaterorequal(a.at(j), max_digit)) {
        max_digit = a.at(j);
      }
    }
    std::swap(a.at(std::find(a.begin() + i, a.end(), max_digit) - a.begin()), a.at(i));
    result += a.at(i);
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
