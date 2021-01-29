#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long fibonacci_fast(long long n) {
  n = n%60;
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current  = 1;
    long long tmp_previous = -1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }
    return current;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
  if(from==to)
    return fibonacci_fast(from);
  if (to <= 1)
      return to;
  long long previous = 0;
  long long current  = 1;
  long long tmp_previous = -1;
  long long sum = 0;
  for (long long i = 0; i <= from - 1; ++i) {
      tmp_previous = previous;
      previous = current;
      current = (tmp_previous + current)%10;
  }
  //std::cout << "Previous: " << previous << '\n';
  //std::cout << "Current: " << current << '\n';
  sum = previous+current;
  long long border = (to-from)%60;
  for (long long i = 0; i < border-1; ++i) {
      tmp_previous = previous;
      previous = current;
      current = (tmp_previous + current)%10;
      //std::cout << current << '\n';
      sum += current;
  }
  return sum%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
