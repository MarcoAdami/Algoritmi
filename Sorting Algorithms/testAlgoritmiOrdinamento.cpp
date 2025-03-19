#include<iostream>
#include <fstream>
#include<vector>
#include <ctime>
#include "random-array.cpp"
#include "merge-sort.cpp"

using namespace std;


 
int main()
{
  ofstream out("output.txt", ios::out);

  // init array
  int size=1000000;
  vector<int> arr(size);
  initRandomArray(arr, size); // in random-array.cpp

  //test
  clock_t start;
  clock_t end;

  start = clock();
  startMergeSort(arr, size);
  end = clock();
  clock_t time = end - start;
  cout<<"mergesort: "<<(double)time/CLOCKS_PER_SEC<<endl;

  

  return 0;
}