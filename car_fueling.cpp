#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, int n, vector<int> & stops) {
  int num_refill = 0;
  int curr_refill = 0;
  int limit = tank;
  while (limit < dist)
  {
  //cout<< "Entered the While Loop" << std::endl;
      //While the destination cannot be reached with current fuel
      if (curr_refill >= n || stops[curr_refill] > limit)
      {
          //Cannot reach the destination nor the next gas station
          //cout<< "Cannot reach destimationn point" << std::endl;
          return -1;
      }

      //Find the furthest gas station we can reach
      while ((curr_refill < n-1)&&(stops[curr_refill+1]<=limit))
      {
        curr_refill = curr_refill + 1;
        //cout<< "The furthest gas station to reach is : " << stops[curr_refill+1] << std::endl;
      }

      num_refill = num_refill+1;  //Stop to tank
      limit = stops[curr_refill] + tank;  //Fill up the tank
      curr_refill = curr_refill+1;
  }

  return num_refill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
    {
        cin >> stops.at(i);
        //cout << stops.at(i) << std::endl;
    }

    cout << compute_min_refills(d, m, n, stops) << "\n";

    return 0;
}
