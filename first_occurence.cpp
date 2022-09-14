#include <iostream>
using namespace std;

int f_recursive(int arr[], int n, int key, int low, int high)
{
  if (low > high)
  {
    return -1;
  }
  int mid = (low + high) / 2;
  if (arr[mid] > key)
  {
    return f_recursive(arr, n, key, low, mid - 1);
  }
  if (arr[mid] < key)
  {
    return f_recursive(arr, n, key, mid + 1, high);
  }
  else
  {
    if (mid == 0 || arr[mid - 1] != arr[mid])
    {
      return mid;
    }
    else
    {
      return f_recursive(arr, n, key, low, mid - 1);
    }
  }
}
int f_iterative(int arr[], int n, int key)
{
  int low = 0;
  int high = n - 1;
  int mid;
  while (low <= high)
  {
    mid = (high + low) / 2;
    if (arr[mid] > key)
    {
      high = mid - 1;
    }
    else if (arr[mid] < key)
    {
      low = mid + 1;
    }
    else
    {
      if (mid != 0 || (arr[mid - 1] != arr[mid]))
      {
        return mid;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return -1;
}
int main()
{
  int arr[] = {1, 2, 3, 3, 4, 4, 4, 4, 5, 5};
  int n = sizeof(arr) / sizeof(int);
  int key;
  cout << "Enter the element to be searched : ";
  cin >> key;
  cout << f_recursive(arr, n, key, 0, sizeof(arr) - 1) << endl;
  cout << f_iterative(arr, n, key);
  return 0;
}