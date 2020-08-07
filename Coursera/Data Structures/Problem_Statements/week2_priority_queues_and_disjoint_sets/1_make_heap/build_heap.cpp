#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void SiftDown(int index) {
    int left_child{-1}, right_child{-1}, parent{-1};
    if (index * 2 + 2 < data_.size())
      right_child = 2 * index + 2;
    if (index * 2 + 1 < data_.size())
      left_child = 2 * index + 1;
    else return;
    parent = index;
    int min_index {parent};
    if (right_child != -1 && data_.at(right_child) < data_.at(min_index))
      min_index = right_child;
    if (left_child != -1 && data_.at(left_child) < data_.at(min_index))
      min_index = left_child;
    if (min_index == parent)
      return;
    else {
      swap(data_.at(min_index), data_.at(parent));
      swaps_.push_back(make_pair(parent, min_index));
    }
    index = min_index;
    SiftDown(index);
  }

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
/*    if (swaps_.size() > 4 * data_.size())
      return false;
    else 
      return true;
*/  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
//      data_[i] = rand() % 100;
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }

  void build_heap() {
    ReadData();
    swaps_.clear();
    for (int i = data_.size() / 2; i >= 0; i--) {
      SiftDown(i);
    }
    WriteResponse();
    //return value;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
//  heap_builder.Solve();
//  bool value {true};
//  while (value == true){
    heap_builder.build_heap();
//    cout << std::endl;
//  }
  return 0;
}
