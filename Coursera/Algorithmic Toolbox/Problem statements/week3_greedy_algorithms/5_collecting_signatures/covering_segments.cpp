#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

void sort_by_right_end(vector <Segment> &unsorted) {
  if (unsorted.size() > 1) {
  int count {};
  while (count != unsorted.size() - 1)  {
    count = 0;
    for (int i = 1; i < unsorted.size(); i++){
      if (unsorted[i].end < unsorted[i - 1].end) {
        std::swap(unsorted[i].start, unsorted[i - 1].start);
        std::swap(unsorted[i].end, unsorted[i - 1].end);
      }
      else {
        count++;
      }
    }
  }
  }
}


vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort_by_right_end(segments);
  int j = 0;
  points.push_back(segments[j].end);
  for (int i = 0; i < segments.size(); i++){ 
    if (segments[i].start <= points.at(j) && segments[i].end >= points.at(j)) {
      continue;
    }
    else{
      points.push_back(segments[i].end);
      j++;
    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
