#include <iostream>
using namespace std;
//! Program to find the square root of a number
//! if the number is not a perfect square number return the floor of the result.

int naive(int x)
{
  int i = 1;
  while (i * i <= x)
  {
    i++;
  }
  return i - 1;
  //* The time complexity of this solution is theta(sqrt(x))
  //* where x is the given number.
}

int efficient(int x)
{
  int low = 1;
  int high = x;
  int ans = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int mid_sq = mid * mid;
    if (mid_sq == x)
    {
      return mid;
    }
    if (mid_sq > x)
    {
      high = mid - 1;
    }
    if (mid_sq < x)
    {
      low = mid + 1;
      ans = mid;
    }
  }
  return ans;
  //* This method takes O(log(n)) time .
}
int main()
{
  int n;
  cout << "Enter the number to find the square root : ";
  cin >> n;
  cout << "The square root of " << n << " is " << naive(n) << endl;
  cout << "The square root of " << n << " is " << efficient(n);
  return 0;
}