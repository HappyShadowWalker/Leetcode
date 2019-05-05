#include <vector>
#include <iostream>

using namespace std;


int partition(int l, int r, vector<int>& arr)
{
  int pivot = arr[l];
  int i =l ;
  int j = r;
  while (i< j)
  {
    while(i<j && arr[j] >=pivot)
    {
      j--;
    }
    if (i <j)
    {
      arr[i] = arr[j];
      i++;
    }
    while(i< j && arr[i] <pivot)
    {
      i ++;
    }
    if (i < j){
      arr[j] = arr[i];
      j--;
    }
  }
  arr[i] = pivot;
  return i;
}

void quick_sort(vector<int>& arr, int l, int r)
{
  if (l >=r)
    return ;
  int p_i = partition(l, r, arr);
  quick_sort(arr, l, p_i -1);
  quick_sort(arr, p_i+1, r);
}

int main()
{
  vector<int> v = {5,3,3,2};
  quick_sort(v, 0, v.size()-1);
  for(auto c:v)
    cout << c << " ";
  return 0;

}
