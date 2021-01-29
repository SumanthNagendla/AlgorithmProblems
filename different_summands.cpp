#include <iostream>
#include <vector>
#include <math.h>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  if(n==0)
  {
   return summands;
  }
  if(n==1)
  {
    summands.push_back(1);
   return summands;
  }
  int temp = n;
  int i=1;
  while((i<n)&&(temp>i))
  {
    summands.push_back(i);
    temp=temp-i;
    i++;
  }
  if(i-1>=temp)
  {
    int last_value = i+temp-1;
    summands.pop_back();
    summands.push_back(last_value);
  }
  else
  {
    summands.push_back(temp);
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
