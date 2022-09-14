#include <iostream>
using namespace std;
string equilibrium(int *arr, int n)
{
  // code here
  string str;
  for (int i = 0; i < n; i++)
  {
    int lsum = 0;
    int rsum = 0;
    for (int j = 0; j < i; j++)
    {
      lsum += arr[j];
    }
    for (int k = i + 1; k <= n - 1; k++)
    {
      rsum += arr[k];
    }
    if (lsum == rsum)
    {
      str = "YES";
    }
    else
    {
      str = "NO";
    }
  }
  return str;
}

int main()
{
  int arr[] = {1, 2, 3, 3};
  int n = sizeof(arr) / sizeof(int);
  cout << equilibrium(arr, n);
  return 0;
}