#include <iostream>

int gcd_fast(int a, int b) {
  while (a != 0 && b != 0){
    if (a < b) {
      b = b % a;
    }
    else {
      a = a % b;
    }
  }
  return std::max(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
