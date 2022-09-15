#include <iostream>
using namespace std;
//! Program to find an element in a sorted and rotated array and return its index.
//! The degree of rotation is unknown

// The naive approach is to use linear search
// The efficient approach takes O(log(n)) time to find the element.

int binary_efficient_recursive(int arr[], int n, int key, int low, int high)
{
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == key)
    {
      return mid;
    }
    if (arr[mid] >= arr[low] and key >= arr[low] && key < arr[mid])
    {
      return binary_efficient_recursive(arr, n, key, low, mid - 1);
    }
    else
    {
      return binary_efficient_recursive(arr, n, key, mid + 1, high);
    }
  }
  return -1;
}

int binary_efficient_iterative(int arr[], int n, int key, int low, int high)
{
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == key)
    {
      return mid;
    }
    if (arr[mid] >= arr[low])
    {
      if (key >= arr[low] && key < arr[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (key >= arr[mid] && key <= arr[high])
      {
        low = mid + 1;
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
  int arr[] = {3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
  int n = sizeof(arr) / sizeof(int);
  int key;
  cout << "Enter the key to be searched in the array : ";
  cin >> key;
  cout << "The index is given by recursive method is " << binary_efficient_recursive(arr, n, key, 0, n - 1);
  cout << "\nThe index given by iterative method is " << binary_efficient_iterative(arr, n, key, 0, n - 1);
  return 0;
}