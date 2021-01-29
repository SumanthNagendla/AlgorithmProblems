#include <iostream>

int get_change(int m) {
  //write your code here
  int sum =0;
  if(m>=10)
  {
    sum = sum + m/10;
    m=m%10;
  }
  if(m>=5)
  {
    sum = sum + m/5;
    m=m%5;
  }
  sum=sum+m;
  return sum;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
