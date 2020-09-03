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
        for (long long i = 0; i < n - 1; ++i){
            long long tmp_previous = previous;
            previous = current;
            current += tmp_previous;
            current = current % 10;
            previous = previous % 10;
        }
        return current;
    }
}

long long fibonacci_sum_squares_naive(long long n) {
   
    if (n <= 1)
        return n;
    
    long long fib_n = fibonacci_sum_naive(n);
    long long fib_n1 = fibonacci_sum_naive(n + 1);
    long long sum = fib_n * fib_n1;
    sum = sum % 10;
    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
