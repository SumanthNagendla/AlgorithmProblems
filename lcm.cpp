#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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

long long lcm_fast(int a, int b) {
  return ((long long) a * b)/gcd_fast(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
