#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  vector <double> fractions {};
  for (int i = 0; i < weights.size(); i++){
    fractions.push_back((values.at(i) * 1.0) / weights.at(i));
  }
 
  //sorting algorithm from maximum to minimum
  if (fractions.size() > 1) {
  int count {};
  while (count != fractions.size() - 1)  {
    count = 0;
    for (int i = 1; i < fractions.size(); i++){
      if (fractions.at(i) > fractions.at(i - 1)) {
       std::swap(fractions.at(i), fractions.at(i - 1));
       std::swap(weights.at(i), weights.at(i - 1));
       std::swap(values.at(i), values.at(i - 1));
      }
      else {
        count++;
      }
    }
  }
  }
   
  while (capacity != 0) {
    for (int i = 0; i < fractions.size(); i++) {
      if (capacity >= weights.at(i)) {
        value += values.at(i);
        capacity -= weights.at(i);
      }
      else {
        value += capacity * fractions.at(i);
        capacity = 0;
      }
      if (i == fractions.size() - 1 || capacity == 0) {
        capacity = 0;
        break;
      }
    }
  }
  return value; 
}
int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }


  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
