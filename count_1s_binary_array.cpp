#include <iostream>
using namespace std;
//! Program to find the number of 1's in a given binary array.

int binary_search(int arr[], int n)
{ //* this method finds the first occurence of the number 1 and returns the index of the first index.
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == 0)
    {
      low = mid + 1;
    }
    else
    {
      if (mid == 0 || arr[mid] != arr[mid - 1])
      {
        return mid;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return 0;
}
int main()
{
  int arr[] = {0, 1, 1, 1, 1, 1};
  int n = sizeof(arr) / sizeof(int);
  int res = n - binary_search(arr, n);
  cout << "The number of 1's in the given binary array is " << res;
  return 0;
}