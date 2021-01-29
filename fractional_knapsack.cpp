#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using std::vector;

struct Item
{
  int weight;
  int value;
};

bool sortFunc(struct Item a, struct Item b)
{
  if(a.weight==0 || b.weight==0)
  {
    if(a.weight==0 && b.weight==0)
    {
      return a.value>b.value;
    }
    else if(a.weight==0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  double r1 = ((double)a.value)/a.weight;
  double r2 = ((double)b.value)/b.weight;
  if(r1>r2)
  {
    return true;
  }
  else if (r1==r2)
  {
    if(a.weight >= b.weight)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

double get_optimal_value(int capacity, int n,vector<Item> Items) {
  double value = 0.0;
  std::sort(Items.begin(),Items.begin()+n,sortFunc);
  /*
  for (int i = 0; i < n; i++) {
    std::cout << "After sorting" <<std::endl;
    std::cout << "Value: " << Items[i].value << "Weight: " << Items[i].weight << std::endl;
  }*/
  int total_weight = 0;
  for(int i=0; i<n; i++)
  {
    if(total_weight<=capacity)
    {
      if(total_weight+Items[i].weight <= capacity)
      {
        total_weight = total_weight+Items[i].weight;
        value = value+(double)Items[i].value;
      }
      else
      {
        value = value + ((double)((capacity - total_weight)*Items[i].value)/(double)(Items[i].weight));
        break;
      }
    }
    else
    {
      break;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<Item> Items(n);
  for (int i = 0; i < n; i++) {
    std::cin >> Items[i].value >> Items[i].weight;
  }
  double optimal_value = get_optimal_value(capacity, n, Items);

  std::cout<< std::fixed << std::setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}
