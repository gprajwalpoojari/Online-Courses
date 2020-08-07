#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  vector<long long> next_free_time;
  vector<int> worker_priority;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    next_free_time.resize(num_workers_);
    worker_priority.resize(num_workers_);
    for (int i = 0; i < num_workers_; i++) {
      worker_priority.at(i) = i;
      next_free_time.at(i) = 0;
    }
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = worker_priority.at(0);
/*      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }*/

      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time.at(0);
      next_free_time.at(0) += duration;
      SiftDown(0);
    }
  }

  void SiftDown(int index) {
    int left_child{-1}, right_child{-1}, parent{-1};
    if (index * 2 + 2 < next_free_time.size())
      right_child = 2 * index + 2;
    if (index * 2 + 1 < next_free_time.size())
      left_child = 2 * index + 1;
    else return;
    parent = index;
    int min_index {parent};
    if (right_child != -1) {
      if (next_free_time.at(right_child) < next_free_time.at(min_index))
        min_index = right_child;
      if (next_free_time.at(right_child) == next_free_time.at(min_index)) {
        if (worker_priority.at(right_child) < worker_priority.at(min_index)) {
          min_index = right_child;
        }
      }
    }
    if (left_child != -1) {
      if (next_free_time.at(left_child) < next_free_time.at(min_index))
        min_index = left_child;
      if (next_free_time.at(left_child) == next_free_time.at(min_index)) {
        if (worker_priority.at(left_child) < worker_priority.at(min_index)) {
          min_index = left_child;
        }
      }
    }
    if (min_index == parent)
      return;
    else {
      swap(next_free_time.at(min_index), next_free_time.at(parent));
      swap(worker_priority.at(min_index), worker_priority.at(parent));
    }
    index = min_index;
    SiftDown(index);
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
