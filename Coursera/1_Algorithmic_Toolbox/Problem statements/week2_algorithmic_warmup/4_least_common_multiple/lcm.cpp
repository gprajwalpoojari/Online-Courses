#include <iostream>

unsigned long long lcm_best(int a, int b) {
  unsigned long long a_tmp = a;
  unsigned long long b_tmp = b;
  while (a_tmp != 0 && b_tmp != 0){
    if (a_tmp < b_tmp) {
      b_tmp = b_tmp % a_tmp;
    }
    else {
      a_tmp = a_tmp % b_tmp;
    }
  }
  unsigned long long gcd = std::max(a_tmp, b_tmp);
  unsigned long long quotient_a = a / gcd;
  unsigned long long quotient_b = b / gcd;
  unsigned long long lcm = gcd * quotient_a * quotient_b;
  return lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_best(a, b) << std::endl;
  return 0;
}
