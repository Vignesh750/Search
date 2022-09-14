#include <iostream>
using namespace std;

int f_iterative(int arr[], int n, int key)
{
  int low = 0;
  int high = n - 1;
  int mid;
  while (low <= high)
  {
    mid = (low + high) / 2;
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

int l_iterative(int arr[], int n, int key)
{
  int low = 0;
  int high = n - 1;
  int mid;
  while (low <= high)
  {
    mid = (low + high) / 2;
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
      if (mid == n - 1 || arr[mid + 1] != arr[mid])
      {
        return mid;
      }
      else
      {
        low = mid + 1;
      }
    }
  }
  return -1;
}

int count(int arr[], int n, int key)
{
  int first = f_iterative(arr, n, key);
  if (first == -1)
  {
    return 0;
  }
  return (l_iterative(arr, n, key) - first + 1);
}
int main()
{
  int arr[] = {1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5};
  int n = sizeof(arr) / sizeof(int);
  int key;
  cout << "Enter the element to be searched : ";
  cin >> key;
  cout << count(arr, n, key);
  return 0;
}