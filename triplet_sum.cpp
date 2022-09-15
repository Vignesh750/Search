#include <iostream>
using namespace std;
//! Program to find if an sorted array contains a triplet whose sum is equal to a given sum.
// Even if the array is unsorted then the efficient solution will still take O(n*n) time.
// because sorting will take O(n* log(n)) + O(n*n) results in O(n*n)
bool naive(int arr[], int n, int sum)
{
  //* In the naive method we simply use three for loops
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        if (arr[i] + arr[j] + arr[k] == sum)
        {
          return true;
        }
      }
    }
  }
  return false;
  //* This method takes O(n*n*n) time and O(1) auxiliary space.
}

bool efficient(int arr[], int n, int sum)
{
  for (int i = 0; i < n - 2; i++)
  {
    int j = i + 1;
    int k = n - 1;
    while (j < k)
    {
      if (arr[i] + arr[j] + arr[k] == sum)
      {
        return true;
      }
      else if (arr[j] + arr[k] + arr[i] < sum)
      {
        k--;
      }
      else
      {
        j++;
      }
    }
  }
  return false;
  //* This method takes O(n*n) time and O(1) space
  //* This method mainly uses two pointer method as a sub routine the while loop does
  //* the two sum and adds it to the current index counted by the for loop.
  //* This method can also be solved using recursion
  //* this one takes O(1) auxiliary space
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