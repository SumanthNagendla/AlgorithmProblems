#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long) (numbers[first] * numbers[second]));
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    long maximum_first_value=0;
    long maximum_second_value=0;

    for (int first = 0; first < n; ++first) {
      if(numbers[first]>maximum_first_value)
      {
        maximum_second_value = maximum_first_value;
        maximum_first_value = numbers[first];
      }
      else if(numbers[first]>maximum_second_value)
      {
        maximum_second_value = numbers[first];
      }
    }
    //std::cout  << maximum_first_value << std::endl;
    //std::cout  << maximum_second_value << std::endl;
    max_product = (long long)(maximum_first_value*maximum_second_value);
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
