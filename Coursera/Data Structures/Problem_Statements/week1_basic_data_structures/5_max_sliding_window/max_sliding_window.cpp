#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::stack;
/*
class StackWithMax {
private:
    stack<int> main_stack;
    stack<int> auxiliary_stack;

public:
    void Push(int value) {
      main_stack.push(value);
      if (auxiliary_stack.empty()) {
        auxiliary_stack.push(value);
      }
      else if (main_stack.top() >= auxiliary_stack.top()) {
        auxiliary_stack.push(value);
      }
    }
    
    int Pop() {
      assert(!main_stack.empty());
      if (auxiliary_stack.top() == main_stack.top()) {
        auxiliary_stack.pop();
      }
      main_stack.pop();
    }
    
    int Top() {
      assert(!main_stack.empty());
      return main_stack.top();
    }

    bool Empty() {
      return main_stack.empty();
    }

    int Max() {
      assert(!main_stack.empty());
      return auxiliary_stack.top();
    }
};
*/
class QueueUsingStacks{
private:
    stack<int> stack1;
    stack<int> stack2;
    stack<int> auxiliary_stack;
    int first;

public:
    QueueUsingStacks(std::vector<int> const &A, int w) {
      for (int i = 0; i < w; i++) {
        Enqueue(A.at(i));
      }
      cout << Get_Max() << " ";
    }

    void Dequeue() {
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        if (stack1.top() == auxiliary_stack.top()) {
          auxiliary_stack.pop();
        }
        stack1.pop();
      }
      assert(!stack2.empty());
      stack2.pop();
      while (!stack2.empty()) {
        Enqueue(stack2.top());
        stack2.pop();
      }
    }

    void Enqueue(int value) {
      stack1.push(value);
      if (auxiliary_stack.empty()) {
        first = value;
        auxiliary_stack.push(value);
      }
      else if (stack1.top() >= auxiliary_stack.top()) {
        auxiliary_stack.push(value);  
      }
    }
    
    int Get_Max() {
      assert(!auxiliary_stack.empty());
      return auxiliary_stack.top();
    }
    
    bool equal_elements(){
      if (stack1.size() == auxiliary_stack.size() && first == stack1.top()) {
        return true;
      }
      else return false;
    }
    
    int Get_First() {return first;}
    
};

void max_sliding_window_naive(vector<int> const & A, int w) {
    QueueUsingStacks my_queue(A, w);
    for (size_t i = w; i < A.size(); ++i) {
        if (my_queue.equal_elements() && A.at(i) == my_queue.Get_First()) {
          int window_max = my_queue.Get_Max();
          cout << window_max << " ";
        }
        else {
          my_queue.Dequeue();
          my_queue.Enqueue(A.at(i));
          int window_max = my_queue.Get_Max();
          cout << window_max << " ";
        }
    }
    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
