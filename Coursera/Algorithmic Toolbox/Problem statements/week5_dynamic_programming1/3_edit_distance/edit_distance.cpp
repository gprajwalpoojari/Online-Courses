#include <iostream>
#include <string>
#include <algorithm>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int row = str1.length() + 1;
  int column = str2.length() + 1;
  int distance_array[row][column] = {{0}};
  for (int i = 0; i < row; i++) {
    distance_array[i][0] = i;
  }
  for (int j = 0; j < column; j++) {
    distance_array[0][j] = j;
  }
  for (int i = 1; i < row; i++){
    for (int j = 1; j < column; j++) {
      int insertion = distance_array[i][j - 1] + 1;
      int deletion = distance_array[i - 1][j] + 1;
      int match = distance_array[i - 1][j - 1];
      int mismatch = distance_array[i - 1][j - 1] + 1;
      if (str1.at(i - 1) == str2.at(j - 1)) {
        distance_array[i][j] = match;
      }
      else {
        int minimum =std::min({insertion, deletion, mismatch});
        distance_array[i][j] = minimum;
      }
    }
  }
  return distance_array[row - 1][column - 1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
