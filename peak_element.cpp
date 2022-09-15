#include <iostream>
using namespace std;
int naive(int arr[], int n)
{
  if (n == 1)
  {
    return arr[0];
  }
  if (arr[0] >= arr[1])
  {
    return arr[0];
  }
  if (arr[n - 1] >= arr[n - 2])
  {
    return arr[n - 1];
  }
  for (int i = 1; i < n - 1; i++)
  {
    if ((arr[i - 1] <= arr[i]) && (arr[i + 1] <= arr[i]))
    {
      return arr[i];
    }
  }
  return -1;
}
int efficient(int arr[], int n)
{
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid != n || arr[mid] >= arr[mid + 1]))
    {
      return arr[mid];
    }
    else if (arr[mid - 1] > arr[mid] && mid > 0)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return -1;
  //* The time complexity of this solution is O(log(n))
  //* The auxiliary space for this solution is O(1)
}
int main()
{
  int arr[] = {5, 20, 40, 30, 20, 50, 60};
  int n = sizeof(arr) / sizeof(int);
  cout << "The naive method gives " << naive(arr, n) << endl;
  cout << "The efficient method gives " << efficient(arr, n);
  cout << endl
       << "if the elements are different then both of them are peak elements";
  return 0;
}