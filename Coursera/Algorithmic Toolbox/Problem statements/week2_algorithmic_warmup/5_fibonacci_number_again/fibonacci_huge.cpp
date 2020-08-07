#include <iostream>
#include <vector>
long long get_fibonacci_huge_naive(long long n, long long m) {
    long long count {1};
    if (n <= 1) {
        return n;
    }
    else {
	long long previous {0}, current {1};
        while (true) {
            long long tmp_previous = previous;
            previous = current;
            current += tmp_previous;
	    current = current % m;
	    previous = previous % m;
	    if (previous % m == 0 && current % m == 1) {
	        break;
	    }
	    else {
		count++;
            }
        }
	n = n % count;
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
	    current = current % m;
	    previous = previous % m;
        }
        return current % m;
	}
    }
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
