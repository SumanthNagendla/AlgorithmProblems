#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<long long int> &a, int x, int left, int right) {
  int midPoint = -1;
  if(left<=right)
  {
    midPoint = (left+right)/2;

    if(x==a[midPoint])
      return midPoint;

    if(x>a[midPoint])
      return binary_search(a,x,midPoint+1,right);

    if(x<a[midPoint])
      return binary_search(a,x,left,midPoint-1);

  }
  return -1;
}

int linear_search(const vector<long long int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i],0,a.size()) << " ";
  }
}
