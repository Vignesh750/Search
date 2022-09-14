#include <iostream>
using namespace std;

int recursive(int arr[], int n, int low, int high, int key)
{
  if (low > high)
  {
    return -1;
  }
  int mid = (low + high) / 2;

  if (arr[mid] == key)
  {
    return mid;
  }
  else if (arr[mid] > key)
  {
    return recursive(arr, n, low, mid - 1, key);
  }
  else
  {
    return recursive(arr, n, mid + 1, high, key);
  }
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr) / sizeof(int);
  int key;
  cout << "Enter the value to be searched : ";
  cin >> key;
  cout << recursive(arr, n, 0, n - 1, key);

  return 0;
}