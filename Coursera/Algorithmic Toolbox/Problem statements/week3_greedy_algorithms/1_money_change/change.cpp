
#include <iostream>

int get_change(int m) {
  //write your code here
  int n {};
  int denominations [] {10, 5, 1};
  for (int i = 0; i < 3; i++) {
    if (m == 0) {
      break;
    }
    n += m / (denominations[i]);
    m = m % denominations[i];
  } 
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
