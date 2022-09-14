#include <iostream>
using namespace std;
//! Program to find a given element in an infinite (million) sized arrays.
int binary(int arr[], int key, int low, int high);
int naive(int arr[], int x)
{
  //* The array is an infinite sized array
  int i = 0;
  while (true)
  {
    if (arr[i] == x)
    {
      return i;
    }
    if (arr[i] > x)
    {
      return -1;
    }
    else
    {
      i++;
    }
  }
  //* This method takes O(index of element);
}

int efficient(int arr[], int x)
{
  if (arr[0] == x)
  {
    return 0;
  }
  int i = 1;
  while (arr[i] < x)
  {
    i = i * 2;
    if (arr[i] == x)
    {
      return i;
    }
  }
  return binary(arr, x, (i / 2) + 1, i - 1); // high  = i-1,low = (i/2)+1
  //* This algorithm is called as unbounded binary search
  //* This method takes O(log(pos)) time.
}
int main()
{
  int arr[] = {1, 10, 15, 20, 40, 60, 80, 100, 200, 1000};
  int key = 100;
  cout << "The naive method results in " << naive(arr, key) << endl;
  cout << "The efficient method results in " << efficient(arr, key);
  return 0;
}
int binary(int arr[], int key, int low, int high)
{
  while (low <= high)
  {
    int mid = (high + low) / 2;
    if (arr[mid] == key)
    {
      return mid;
    }
    if (arr[mid] < key)
    {
      low = mid + 1;
    }
    if (arr[mid] > key)
    {
      high = mid - 1;
    }
  }
  return -1;
}