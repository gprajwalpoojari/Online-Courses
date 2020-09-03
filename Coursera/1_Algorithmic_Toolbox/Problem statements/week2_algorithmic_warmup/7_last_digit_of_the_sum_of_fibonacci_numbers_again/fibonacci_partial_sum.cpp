#include <iostream>

long long fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;
    long long count {1};
    long long previous {0}, current {1};
    while (true) {
        long long tmp_previous = previous;
        previous = current;
        current += tmp_previous;
        current = current % 10;
        previous = previous % 10;
        if (previous % 10 == 0 && current % 10 == 1) {
            break;
        }
        else {
            count++;
        }
    }
    n = (n) % count;
    previous = 0;
    current = 1;
    if (n <= 1) {
        return n;
    }
    else {
        for (long long i = 0; i < n + 1; ++i){
            long long tmp_previous = previous;
            previous = current;
            current += tmp_previous;
            current = current % 10;
            previous = previous % 10;
        }
        if (current == 0){
            current = 10;
        }
        current = current - 1;
        return current;
    }
}




long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (from >= 1) {
        from -= 1 ;
    } 
    long long from_sum = fibonacci_sum_naive(from);
    long long to_sum = fibonacci_sum_naive(to);    
    if (to_sum < from_sum) {
        to_sum += 10;
    }	
    return to_sum - from_sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
