#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    int index_1 {-1}, index_2 {-1};
    long long max {};
    for (int i = 0; i < n; i++) {
	if (index_1 == -1 || max < numbers.at(i)) {
	    max = numbers.at(i);
	    index_1 = i;
	}
    }
    max = 0;
    for (int i = 0; i < n; i++) {
        if (i != index_1 && (index_2 == -1 || max < numbers.at(i))) {
	    max = numbers.at(i);
	    index_2 = i;
	}
    }

    max_product = numbers[index_1] * numbers[index_2];
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << std::endl;
    return 0;
}
