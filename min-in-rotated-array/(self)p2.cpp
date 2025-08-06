#include <iostream>
using namespace std;
int min(int arr[], int n)
{
  int low = 0;
  int high = n - 1;
  while (low < high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] > arr[high])
    {
       low = mid + 1; 
    }
    else
    {
      high = mid;
    }
  }  
  return arr[low];
}
int main()
{
  int arr[] = {3, 4, 5, 0, 1,2};
  int n = sizeof(arr) / sizeof(arr[0]);
  int res = min(arr, n);
  cout << "min:" << res;
  return 0;
}
