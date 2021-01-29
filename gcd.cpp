#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  int current_gcd = 1;
  int remainder = -1;
  int temp = 0;
  if(b<a)
  {
    temp=a;
    a=b;
    b=temp;
  }
  while(remainder !=0)
  {
    remainder = a%b;
    current_gcd = b;
    a=b;
    b=remainder;
  }
  return current_gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
