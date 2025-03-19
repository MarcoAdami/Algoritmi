/*
  Implementazione con vector
*/
#include <iostream>
#include <vector> //#include <bits/stdc++.h> // use in terminal std=c++11
#include <fstream>

using namespace std;

void mergeSort(vector<int>& arr, int start, int middle, int end)
{
  // Check that the remaining array is more than 2 elements
  if (end - start >= 2)
  {
    // Recursive call - Divide the array in left and right
    
    mergeSort(arr, start, (middle + start) / 2, middle); // Call mergesort on the left array
    mergeSort(arr, middle, (middle + end) / 2, end); //Call mergesort on right array

    int la = middle - start;
    int lb = end - middle;

    //Create temp vector
    vector<int> A, B;
    for (int i = start; i < middle; ++i)
    {
      A.push_back(arr[i]);
    }
    for (int i = middle; i < end; ++i)
    {
      B.push_back(arr[i]);
    }
    
    int i = start;
    int j = 0;
    int k = 0;

    // Merge
    while(j<la || k<lb){
      if ((A[j] <= B[k] && j<la) || k>=lb)
      {
        arr[i] = A[j];
        j++;
      }
      else
      {
        arr[i] = B[k];
        k++;
      }
      i++;
    }
  }
}

void startMergeSort(vector<int>& arr, int n){
  mergeSort(arr, 0, n/2, n);
}

// int main()
// {
//     ifstream in("input.txt");
//     ofstream out("output.txt");
//     int size=10;

//     vector<int> arr(size);
//     initRandomArray(arr, size);

//     startMergeSort(arr, size);

//     for (int i = 0; i < size; ++i)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }