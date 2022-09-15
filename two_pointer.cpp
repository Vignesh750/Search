#include <iostream>
using namespace std;
//! Program to find if there is a pair with sum x in a sorted array.
//! https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Searching/video/NzAyMQ%3D%3D

bool naive(int arr[], int n, int sum)
{
  //* returns true if the sum exists in the array else false
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] + arr[j] == sum)
      {
        return true;
      }
    }
  }
  return false;
  //* The time complexity of the method is O(n*n).
  // This method takes O(1) auxiliary space
}
bool efficient(int arr[], int n, int sum)
{
  int i = 0;
  int j = n - 1;
  while (i < j)
  {
    if (arr[i] + arr[j] == sum)
    {
      return true;
    }
    else if (arr[i] + arr[j] > sum)
    {
      j = j - 1;
    }
    else
    {
      i = i + 1;
    }
  }
  return false;
  //* The time complexity of this method is O(n)
  //* This method takes O(1) auxiliary space
}
int main()
{
  int arr[] = {2, 3, 8, 117};
  int n = sizeof(arr) / sizeof(int);
  int sum;
  cout << "Enter the sum to find : ";
  cin >> sum;
  string res = naive(arr, n, sum) ? "Sum Exists\n" : "Sum does not exist\n";
  cout << "The result by naive method is : " << res;
  res = efficient(arr, n, sum) ? "Sum Exists\n" : "Sum does not exist\n";
  cout << "The result by efficient method is : " << res;
  return 0;
}