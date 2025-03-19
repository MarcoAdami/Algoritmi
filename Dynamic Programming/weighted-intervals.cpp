/*
Input:
  Let n distinct intervals [a1, b1[, . . . , [an, bn[ of the real line be given, 
  open to the right, where interval i is associated with a profit wi, 1 ≤ i ≤ n.

Disjoint intervals:
  Two intervals i and j are called disjoint if: bj ≤ ai or bi ≤ aj

Problem:
  Find a maximum-weight independent set, that is, a subset of mutually disjoint intervals 
  such that the sum of their profits is as large as possible.

Version-0:
  We could try every possible set combination, 
  but the number of possibility grows exponentialy. O(2^n)

Version-1:
  If we want to use DP a preprocessing step is required: 
  sorting the intervals by non-decreasing right endpoints. 
  But it would take O(n^2), because you should check all 
  the intervals that came before. 

Version-2:
  To make better another preprocessing step is required:
  prepocessing the precedent intervals for each starting point, 
  a precise order isn't required if there are multiple precedessor for 
  a starting point. 
  But if we do this on a normal array it will take O(n^2) to compute,
  so before we need to sort the intervals.

  Steps:
  - sort intervals O(n*log(n))
  - preprocessing precedent interval O(n*log(n)) -> using a dicotomic algorithm for each element 
  - use DP to find the result by maxing each result between
    the one before and the prec + the current interval
  - Reconstruct the set of intervals
  
  Example input:
  11
  1 4 4
  3 5 12
  0 6 3
  5 8 7
  3 8 8
  5 9 12
  6 10 8
  8 11 10
  8 12 3
  2 13 15
  12 14 7
*/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool comp(vector<int> a, vector<int> b){
  return a[1] < b[1];
}

int binarySearch(vector<int>& arr, int low, int high, int x)
{
  int validIndex=-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x){
          low = mid + 1;
          validIndex = mid;
        }
            

        // If x greater, ignore left half
        if (arr[mid] < x){
          low = mid + 1;
          validIndex = mid;
        }
        // If x is smaller, ignore right half
        else{
          high = mid - 1;   
        }
            
    }

    // If we reach here, then element was not present
    return validIndex;
}
int main()
{
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int n; cin>>n;
    vector<vector<int> > intervals(n, vector<int> (3));

    // get the input O(n)
    for(int i=0; i<n; ++i){
      cin>>intervals[i][0];
      cin>>intervals[i][1];
      cin>>intervals[i][2];
    }

    // sort intervals O(n*log(n))
    sort(intervals.begin(), intervals.end(), comp); 

    // remember intervals orederd
    vector<int> endPoints(n);
    for(int i=0; i<n; ++i){
      endPoints[i]=intervals[i][1];
    }

    // preprocessing precedent interval O(n*log(n))
    vector<int> prec (n);
    for(int i=0; i<n; ++i){
      int index = binarySearch(endPoints, 0, n, intervals[i][0]);
      if(index)
      prec[i] = index;
      // cout<< intervals[i][0]<<" "<<prec[i]<<endl;
    }

    // DP solution the step before and the precedent are optimal,
    // so we can do the max of both and find the optimal solution in the last one.
    vector<int> DP(n);
    for(int i=0; i<n; ++i){
      DP[i] = max(DP[i-1], DP[prec[i]] + intervals[i][2]);
    }

    cout<<"MaxIntervals: "<<DP[n-1]<<endl;

    // Reconstruct the set of intervals
    vector<int> setSol;
    int j=n-1;
    while(j>0){
      if(DP[j-1] > intervals[j][2] + DP[prec[j]]){
        j--;
      }else{
        setSol.push_back(j);
        j = prec[j];
      }
    }


    for(int i=0; i<setSol.size(); ++i){
      cout<<"index: "<<setSol[i]<<", weight: "<< intervals[setSol[i]][2]<<endl;
    }

    return 0;
}