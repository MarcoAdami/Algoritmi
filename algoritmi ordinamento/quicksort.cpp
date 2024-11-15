#include<iostream>
#include<vector> //#include <bits/stdc++.h> // use in terminal std=c++11
#include <fstream>
#include<vector>
#include<deque>
#include "random-array.cpp"
#include <cstdlib>
using namespace std;



void quickSort(vector<int>& arr, int start, int end){
  if(end-start<=1){
    return;
  }

  int pivot = start;
  for(int i=pivot+1; i<end; ++i){
    if(arr[pivot]>arr[i]){
      swap(arr[pivot], arr[i]);
      pivot++;
    }
  }

  quickSort(arr, start, pivot);
  quickSort(arr, pivot+1, end);
}
 
int main()
{
    // ifstream cin("input.txt");
    // ofstream cout("output.txt", ios::out);
    int size=10;
    vector<int> arr(size);

    
    initRandomArray(arr, size);

    quickSort(arr, 0, size);

    cout<<endl;
    for(int i=0; i<size; ++i){
      cout<<arr[i]<<" ";
    }

    
    return 0;
}