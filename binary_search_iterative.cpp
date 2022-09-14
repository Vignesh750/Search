#include <iostream>
using namespace std;
//! Program to return the index of a key element if it is present in a given array.
//! Here we use the Binary search method

int binary_search_iterative(int arr[], int n, int key)
{
  int low = 0;      // starting index
  int high = n - 1; // ending index
  while (low <= high)
  {
    int mid = (high + low) / 2;
    if (arr[mid] == key)
    {
      return mid;
      ;
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

int binary_search_recursive(int arr[],int n,int key){
  int mid = n / 2;
  if(arr[mid]==key){
    return mid;
  }
  if(arr[mid]>key){
    return binary_search_recursive(arr[], n / 2, key);
  }
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(int);
  int key = 5;
  cout << binary_search_iterative(arr, n, key);
  return 0;
}